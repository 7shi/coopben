#include <stdio.h>

class Pair {
public:
    int a, b;
    int add() { return a + b; }
    int add(int);
};

extern "C" int _ZN4Pair3addEv(Pair *);
extern "C" int _ZN4Pair3addEi(Pair *p, int c) {
    return _ZN4Pair3addEv(p) + c;
}

int main() {
    Pair pair = { 1, 2 };
    printf("%d, %d\n", pair.add(), _ZN4Pair3addEv(&pair));
    printf("%d, %d\n", pair.add(3), _ZN4Pair3addEi(&pair, 3));
}
