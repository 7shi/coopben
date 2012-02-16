#include <stdio.h>

struct Pair { int a, b; };

int Pair_add(struct Pair *this) {
    return this->a + this->b;
}

int main() {
    struct Pair pair = { 1, 2 };
    printf("%d\n", Pair_add(&pair));
    return 0;
}
