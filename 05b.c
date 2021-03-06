#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b;
} Pair;

Pair *Pair_new() {
    return (Pair *)malloc(sizeof(Pair));
}

void Pair_delete(Pair *this) {
    free(this);
}

void Pair_init(Pair *this, int a, int b) {
    this->a = a;
    this->b = b;
}

void Pair_fini(Pair *this) {
    printf("%d, %d\n", this->a, this->b);
}

int Pair_add(Pair *this) {
    return this->a + this->b;
}

int main(void) {
    Pair *pair = Pair_new();
    Pair_init(pair, 1, 2);
    printf("%d\n", Pair_add(pair));
    Pair_fini(pair);
    Pair_delete(pair);
    return 0;
}
