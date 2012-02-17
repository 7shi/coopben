#include <stdio.h>

class Number {
public:
    int n;
    Number(int n) : n(n) {}
    virtual void show() {
        printf("%p: n = %d\n", &n, n);
    }
};

class Pair1 : public Number {
public:
    int n2;
    Pair1(int n, int n2) : Number(n), n2(n2) {}
    virtual void show() {
        Number::show();
        printf("%p: n2 = %d\n", &n2, n2);
    }
};

class Pair2 : public Number {
public:
    int n3;
    Pair2(int n, int n3) : Number(n), n3(n3) {}
    virtual void show() {
        Number::show();
        printf("%p: n3 = %d\n", &n3, n3);
    }
};

class Pair3 : public Pair1, public Pair2 {
public:
    int n4;
    Pair3(int n, int n2, int nn, int n3, int n4)
        : Pair1(n, n2), Pair2(nn, n3), n4(n4) {}
    virtual void show() {
        Pair1::show();
        Pair2::show();
        printf("%p: n4 = %d\n", &n4, n4);
    }
};

int main() {
    Pair3 *p3 = new Pair3(1, 2, 3, 4, 5);
    Pair1 *p1 = static_cast<Pair1 *>(p3);
    Pair2 *p2 = static_cast<Pair2 *>(p3);
    Pair2 *p2_2 = reinterpret_cast<Pair2 *>(p3);
    Number *n1 = static_cast<Number *>(p1);
    Number *n2 = static_cast<Number *>(p2);
    printf("%p: Pair3\n", p3);
    printf("%p:   Pair1\n", p1);
    printf("%p:    Number\n", n1);
    printf("%p:   Pair2\n", p2);
    printf("%p:    Number\n", n2);
    printf("%p:   Pair2 (reinterpret_cast)\n", p2_2);
    p3->show();
    delete p3;
}
