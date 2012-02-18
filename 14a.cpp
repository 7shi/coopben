#include <stdio.h>

class Test {
    int n;
public:
    Test(int n) : n(n) {}
    virtual void show() {
        printf("%d\n", n);
    }
};

extern "C" void call_Test_show(void *);

int main() {
    Test t = 12345;
    call_Test_show(&t);
}
