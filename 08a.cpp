#include <stdio.h>

class Number {
public:
    int n;
    Number(int n) : n(n) {}
    virtual void show() {
        printf("%p: n = %d\n", &n, n);
    }
};

class Pair : public Number {
public:
    int n2;
    Pair(int n, int n2) : Number(n), n2(n2) {}
    virtual void show() {
        Number::show();
        printf("%p: n2 = %d\n", &n2, n2);
    }
};

int main() {
    Number *n;

    n = new Number(1);
    printf("%p: Number\n", n);
    n->show();
    delete n;

    n = new Pair(2, 3);
    printf("\n%p: Pair\n", n);
    n->show();
    delete n;
}
