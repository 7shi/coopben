#include <stdio.h>

class Pair {
public:
    int a, b;
    int add() { return a + b; }
    int add(int c) { return a + b + c; }
    int add(int c, int d) { return a + b + c + d; }
};


int main() {
    Pair pair = { 1, 2 };
    printf("%d\n", pair.add());
    printf("%d\n", pair.add(3));
    printf("%d\n", pair.add(3, 4));
}
