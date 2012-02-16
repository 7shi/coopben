#include <stdio.h>

class Pair {
public:
    int a, b;
    Pair(int a, int b) : a(a), b(b) {}
    ~Pair() { printf("%d, %d\n", a, b); }
    int add() { return a + b; }
};

int main() {
    Pair pair(1, 2);
    printf("%d\n", pair.add());
}
