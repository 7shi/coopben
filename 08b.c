#include <stdio.h>
#include <stdlib.h>

typedef struct tagNumber Number;
struct tagNumber {
    void (*show)(Number *);
    int n;
};

void Number_show(Number *this) {
    printf("%p: n = %d\n", &this->n, this->n);
}

void Number_init(Number *this, int n) {
    this->show = Number_show;
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

typedef struct tagPair Pair;
struct tagPair {
    union {
        void (*show)(Pair *);
        Number base;
    };
    int n2;
};

void Pair_show(Pair *this) {
    Number_show((Number *)this);
    printf("%p: n2 = %d\n", &this->n2, this->n2);
}

void Pair_init(Pair *this, int n, int n2) {
    Number_init((Number *)this, n);
    this->show = Pair_show;
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

int main() {
    Number *n;

    n = Number_new(1);
    printf("%p: Number\n", n);
    n->show(n);
    Number_delete(n);

    n = (Number *)Pair_new(2, 3);
    printf("\n%p: Pair\n", n);
    n->show(n);
    Pair_delete((Pair *)n);
}
