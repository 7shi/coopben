#include <stdio.h>
#include <stdlib.h>

typedef struct tagNumber Number;
typedef struct tagPair1 Pair1;
typedef struct tagPair2 Pair2;
typedef struct tagPair3 Pair3;

void Number_show(Number *);
void Pair1_show(Pair1 *);
void Pair2_show(Pair2 *);
void Pair3_show(Pair3 *);

struct vtbl_Number {
    void (*show)(Number *);
} vtable_Number = {
    Number_show
};

struct vtbl_Pair1 {
    void (*show)(Pair1 *);
} vtable_Pair1 = {
    Pair1_show
};

struct vtbl_Pair2 {
    void (*show)(Pair2 *);
} vtable_Pair2 = {
    Pair2_show
};

struct vtbl_Pair3 {
    void (*show)(Pair3 *);
} vtable_Pair3 = {
    Pair3_show
};

struct tagNumber {
    struct vtbl_Number *vtable;
    int n;
};

void Number_init(Number *this, int n) {
    this->vtable = &vtable_Number;
    this->n = n;
}

Number *Number_new(int n) {
    Number *this = (Number *)malloc(sizeof(Number));
    Number_init(this, n);
    return this;
}

void Number_delete(Number *this) {
    free(this);
}

void Number_show(Number *this) {
    printf("%p: n = %d\n", &this->n, this->n);
}

struct tagPair1 {
    union {
        struct vtbl_Pair1 *vtable;
        Number base;
    };
    int n2;
};

void Pair1_init(Pair1 *this, int n, int n2) {
    Number_init(&this->base, n);
    this->vtable = &vtable_Pair1;
    this->n2 = n2;
}

Pair1 *Pair1_new(int n, int n2) {
    Pair1 *this = (Pair1 *)malloc(sizeof(Pair1));
    Pair1_init(this, n, n2);
    return this;
}

void Pair1_delete(Pair1 *this) {
    Number_delete(&this->base);
}

void Pair1_show(Pair1 *this) {
    Number_show(&this->base);
    printf("%p: n2 = %d\n", &this->n2, this->n2);
}

struct tagPair2 {
    union {
        struct vtbl_Pair2 *vtable;
        Number base;
    };
    int n3;
};

void Pair2_init(Pair2 *this, int n, int n3) {
    Number_init(&this->base, n);
    this->vtable = &vtable_Pair2;
    this->n3 = n3;
}

Pair2 *Pair2_new(int n, int n3) {
    Pair2 *this = (Pair2 *)malloc(sizeof(Pair2));
    Pair2_init(this, n, n3);
    return this;
}

void Pair2_delete(Pair2 *this) {
    Number_delete(&this->base);
}

void Pair2_show(Pair2 *this) {
    Number_show(&this->base);
    printf("%p: n3 = %d\n", &this->n3, this->n3);
}

struct tagPair3 {
    union {
        struct vtbl_Pair3 *vtable;
        Pair1 base;
    };
    union {
        struct vtbl_Pair3 *vtable2;
        Pair2 base2;
    };
    int n4;
};

void Pair3_init(Pair3 *this, int n, int n2, int nn, int n3, int n4) {
    Pair1_init(&this->base , n , n2);
    Pair2_init(&this->base2, nn, n3);
    this->vtable = &vtable_Pair3;
    this->vtable2 = &vtable_Pair3;
    this->n4 = n4;
}

Pair3 *Pair3_new(int n, int n2, int nn, int n3, int n4) {
    Pair3 *this = (Pair3 *)malloc(sizeof(Pair3));
    Pair3_init(this, n, n2, nn, n3, n4);
    return this;
}

void Pair3_delete(Pair3 *this) {
    Pair1_delete(&this->base);
}

void Pair3_show(Pair3 *this) {
    Pair1_show(&this->base);
    Pair2_show(&this->base2);
    printf("%p: n4 = %d\n", &this->n4, this->n4);
}

int main() {
	Pair3 *p3 = Pair3_new(1, 2, 3, 4, 5);
	Pair1 *p1 = &p3->base;
	Pair2 *p2 = &p3->base2;
    Pair2 *p2_2 = (Pair2 *)p3;
	Number *n1 = &p1->base;
	Number *n2 = &p2->base;
	printf("%p: Pair3\n", p3);
	printf("%p:   Pair1\n", p1);
	printf("%p:    Number\n", n1);
	printf("%p:   Pair2\n", p2);
	printf("%p:    Number\n", n2);
	printf("%p:   Pair2 (cast)\n", p2_2);
	p3->vtable->show(p3);
    Pair3_delete(p3);
}
