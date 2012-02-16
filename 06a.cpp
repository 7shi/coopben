#include <stdio.h>

class Counter {
public:
    static int count;
    int v;
    Counter(int v) : v(v) { count += v; }
    ~Counter() { count -= v; }
};

int Counter::count;

int main() {
    Counter *c1 = new Counter(1);
    Counter *c2 = new Counter(2);
    Counter *c3 = new Counter(3);
    printf("%d\n", Counter::count);
    delete c1;
    printf("%d\n", Counter::count);
    delete c2;
    printf("%d\n", Counter::count);
    delete c3;
    printf("%d\n", Counter::count);
}
