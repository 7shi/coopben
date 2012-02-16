#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void create_thunk(unsigned char *thunk, void *this, void *func) {
    // push this
    thunk[0] = 0x68;
    *(void **)&thunk[1] = this;
    // mov eax, show
    thunk[5] = 0xb8;
    *(void **)&thunk[6] = func;
    // call eax
    thunk[10] = 0xff;
    thunk[11] = 0xd0;
    // add esp, 4
    thunk[12] = 0x83;
    thunk[13] = 0xc4;
    thunk[14] = 4;
    // ret
    thunk[15] = 0xc3;
}

typedef struct {
    void (*show)(void);
    int n;
} Number;

void Number_show(Number *this) {
    printf("%p: n = %d\n", &this->n, this->n);
}

void Number_init(Number *this, void (*show)(), int n) {
    unsigned char *thunk;
    this->n = n;

    thunk = (unsigned char *)
        VirtualAlloc(NULL, 16, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    this->show = (void (*)(void))thunk;
    create_thunk(thunk, this, show);
}

Number *Number_new(int n) {
    Number *this = (Number *)malloc(sizeof(Number));
    Number_init(this, Number_show, n);
    return this;
}

void Number_delete(Number *this) {
    VirtualFree(this->show, 0, MEM_RELEASE);
    free(this);
}

typedef struct {
    union {
        void (*show)(void);
        Number base;
    };
    int n2;
} Pair;

void Pair_show(Pair *this) {
    Number_show((Number *)this);
    printf("%p: n2 = %d\n", &this->n2, this->n2);
}

void Pair_init(Pair *this, int n, int n2) {
    Number_init((Number *)this, Pair_show, n);
    this->n2 = n2;
}

Pair *Pair_new(int n, int n2) {
    Pair *this = (Pair *)malloc(sizeof(Pair));
    Pair_init(this, n, n2);
    return this;
}

void Pair_delete(Pair *this) {
    free(this);
}

int main(void) {
    Number *n;

    n = Number_new(1);
    printf("%p: Number\n", n);
    n->show();
    Number_delete(n);

    n = (Number *)Pair_new(2, 3);
    printf("\n%p: Pair\n", n);
    n->show();
    Pair_delete((Pair *)n);

    return 0;
}
