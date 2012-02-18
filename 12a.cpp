#include <stdio.h>

namespace mult {
    class A { public: int a; };
    class B : public A { public: int b; };
    class C : public A { public: int c; };
    class D : public B, public C { public: int d; };
}

namespace virt {
    class A { public: int a; };
    class B : virtual public A { public: int b; };
    class C : virtual public A { public: int c; };
    class D : public B, public C { public: int d; };
}

int main() {
    mult::D d1;
    virt::D d2;

    printf("%p: &d1\n", &d1);
    mult::B *d1b = static_cast<mult::B *>(&d1);
    printf("%p: &d1b->a\n", &d1b->a);
    printf("%p: &d1.b\n", &d1.b);
    mult::C *d1c = static_cast<mult::C *>(&d1);
    printf("%p: &d1c->a\n", &d1c->a);
    printf("%p: &d1.c\n", &d1.c);
    printf("%p: &d1.d\n", &d1.d);

    printf("\n%p: &d2\n", &d2);
    virt::B *d2b = static_cast<virt::B *>(&d2);
    void **d2bvt = *reinterpret_cast<void ***>(d2b);
    printf("%p: %p (vtable)\n", d2b, d2bvt);
    printf("%p: %p\n", &d2bvt[-3], d2bvt[-3]);
    printf("%p: &d2.b\n", &d2.b);
    virt::C *d2c = static_cast<virt::C *>(&d2);
    void **d2cvt = *reinterpret_cast<void ***>(d2c);
    printf("%p: %p (vtable)\n", d2c, d2cvt);
    printf("%p: %p\n", &d2cvt[-3], d2cvt[-3]);
    printf("%p: &d2.c\n", &d2.c);
    printf("%p: &d2.d\n", &d2.d);
    printf("%p: &d2.a\n", &d2.a);
}
