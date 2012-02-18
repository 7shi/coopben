#include <stdio.h>

class A { public: int a; };
class B : virtual public A { public: void setA(int); };
class C : virtual public A { public: void setA(int); };
class D : public B, public C {};

int main() {
    D d;
    B *b = static_cast<B *>(&d);
    C *c = static_cast<C *>(&d);
    b->setA(1);
    printf("%d\n", d.a);
    c->setA(2);
    printf("%d\n", d.a);
}
