#include <stdio.h>

class Test1 { public: virtual void test1() {} } t1;
class Test2 { public: virtual void test2() {} } t2;
class Test3 : public Test1, public Test2 {} t3;
class Test4 : public Test1, public Test2 {
public:
    virtual void test1() { printf("Test4::test1\n"); }
    virtual void test2() { printf("Test4::test2\n"); }
} t4;

void show_vtable(const char *name, void *p, int n) {
    printf("%s: %p\n", name, p);
    void **vtbl = *reinterpret_cast<void ***>(p);
    printf("%p: %p (vtable)\n", p, vtbl);
    for (int i = 0; i < n; i++)
        printf("%p: %p\n", &vtbl[i], vtbl[i]);
}

int main() {
    show_vtable("&t1", &t1, 1);
    show_vtable("&t2", &t2, 1);
    show_vtable("&t3", &t3, 2);
    show_vtable("static_cast<Test2 *>(&t3)",
        static_cast<Test2 *>(&t3), 1);
    show_vtable("&t4", &t4, 2);
    show_vtable("static_cast<Test2 *>(&t4)",
        static_cast<Test2 *>(&t4), 1);
}
