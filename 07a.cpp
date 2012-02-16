#include <stdio.h>

class A {
public:
    int a;
    void showA() { printf("%p: a = %d\n", &a, a); }
};

class B : public A {
public:
    int b;
    void showB() { printf("%p: b = %d\n", &b, b); }
};

int main() {
    A a;
    printf("%p: A\n", &a);
    a.a = 1;
    a.showA();

    B b;
    printf("\n%p: B\n", &b);
    b.a = 2;
    b.b = 3;
    b.showA();
    b.showB();
}
