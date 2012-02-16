#include <stdio.h>
#include <stdlib.h>

typedef struct { int v; } Counter;

int Counter_count;

Counter *Counter_new(int v) {
    Counter *this = (Counter *)malloc(sizeof(Counter));
    this->v = v;
    Counter_count += v;
    return this;
}

void Counter_delete(Counter *this) {
    Counter_count -= this->v;
    free(this);
}

int main() {
    Counter *c1 = Counter_new(1);
    Counter *c2 = Counter_new(2);
    Counter *c3 = Counter_new(3);
    printf("%d\n", Counter_count);
    Counter_delete(c1);
    printf("%d\n", Counter_count);
    Counter_delete(c2);
    printf("%d\n", Counter_count);
    Counter_delete(c3);
    printf("%d\n", Counter_count);
}
