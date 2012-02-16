#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int a, b;
} Pair;

Pair *Pair_new(int a, int b) {
    Pair *this = (Pair *)malloc(sizeof(Pair));
    this->a = a;
    this->b = b;
    return this;
}

void Pair_delete(Pair *this) {
    printf("%d, %d\n", this->a, this->b);
    free(this);
}

int Pair_add(Pair *this) {
    return this->a + this->b;
}

int main(void) {
    Pair *pair = Pair_new(1, 2);
    printf("%d\n", Pair_add(pair));
    Pair_delete(pair);
    return 0;
}
