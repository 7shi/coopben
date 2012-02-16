#include <stdio.h>

typedef struct {
    int a, b;
} Pair;

void Pair_init(Pair *this, int a, int b) {
    this->a = a;
    this->b = b;
}

int Pair_add(Pair *this) {
    return this->a + this->b;
}

int main() {
    Pair pair;
    Pair_init(&pair, 1, 2);
    printf("%d\n", Pair_add(&pair));
    return 0;
}
