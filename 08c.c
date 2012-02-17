#include <stdio.h>
#include <stdlib.h>

typedef struct tagNumber Number;
typedef struct tagPair Pair;

void Number_show(Number *);
void Pair_show(Pair *);

struct vtbl_Number {
    void (*show)(Number *);
} vtable_Number = {
    Number_show
};

struct vtbl_Pair {
    void (*show)(Pair *);
} vtable_Pair = {
    Pair_show
};

struct tagNumber {
    struct vtbl_Number *vtable;
    int n;
};

void Number_init(Number *this, int n) {
    this->vtable = &vtable_Number;
    this->n = n;
}

Number *Number_new(int n) {
    Number *this = (Number *)malloc(sizeof(Number));
    Number_init(this, n);
    return this;
}

void Number_delete(Number *this) {
    free(this);
}

void Number_show(Number *this) {
    printf("%p: n = %d\n", &this->n, this->n);
}

struct tagPair {
    union {
        struct vtbl_Pair *vtable;
        Number base;
    };
    int n2;
};

void Pair_init(Pair *this, int n, int n2) {
    Number_init(&this->base, n);
    this->vtable = &vtable_Pair;
    this->n2 = n2;
}

Pair *Pair_new(int n, int n2) {
    Pair *this = (Pair *)malloc(sizeof(Pair));
    Pair_init(this, n, n2);
    return this;
}

void Pair_delete(Pair *this) {
    Number_delete(&this->base);
}

void Pair_show(Pair *this) {
    Number_show(&this->base);
    printf("%p: n2 = %d\n", &this->n2, this->n2);
}

int main(void) {
    Number *n;

    n = Number_new(1);
    printf("%p: Number\n", n);
    n->vtable->show(n);
    Number_delete(n);

    n = (Number *)Pair_new(2, 3);
    printf("\n%p: Pair\n", n);
    n->vtable->show(n);
    Pair_delete((Pair *)n);

    return 0;
}
