#include <stdio.h>

class Pair {
public:
    int a, b;
    int add();
};

int Pair::add() {
    return a + b;
}

int main() {
    Pair pair = { 1, 2 };
    printf("%d\n", pair.add());
}
