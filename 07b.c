#include <stdio.h>

typedef struct { int a; } A;

void A_showA(A *this) {
    printf("%p: a = %d\n", &this->a, this->a);
}

typedef struct { A base; int b; } B;

void B_showB(B *this) {
    printf("%p: b = %d\n", &this->b, this->b);
}

int main() {
    A a;
    B b;

    printf("%p: A\n", &a);
    a.a = 1;
    A_showA(&a);

    printf("\n%p: B\n", &b);

    b.base.a = 2;
    A_showA(&b.base);

    ((A *)&b)->a = 2;
    A_showA((A *)&b);
    
    b.b = 3;
    B_showB(&b);

    return 0;
}
