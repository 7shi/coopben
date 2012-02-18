#include <stdio.h>

typedef struct { int a; } mult_A;
typedef struct { mult_A base; int b; } mult_B;
typedef struct { mult_A base; int c; } mult_C;
typedef struct { mult_B base; mult_C base2; int d; } mult_D;

typedef struct { int offset_A, _1, _2, ptr; } vtbl;

typedef struct { int a; } virt_A;
typedef struct { void *vtable; int b; } virt__B;
typedef struct { void *vtable; int b; virt_A base; } virt_B;
typedef struct { void *vtable; int c; } virt__C;
typedef struct { void *vtable; int c; virt_A base; } virt_C;
typedef struct {
    virt__B base;
    virt__C base2;
    int d;
    virt_A base3;
} virt_D;

vtbl vtbl_virt_B = { sizeof(virt__B) };
vtbl vtbl_virt_C = { sizeof(virt__C) };
vtbl vtbl_virt_D_B = {
    sizeof(virt__B) + sizeof(virt__C) + sizeof(int)
};
vtbl vtbl_virt_D_C = {
    sizeof(virt__C) + sizeof(int)
};

void virt_B_init(virt_B *this) {
    this->vtable = &vtbl_virt_B.ptr;
}

void virt_C_init(virt_C *this) {
    this->vtable = &vtbl_virt_C.ptr;
}

void virt_D_init(virt_D *this) {
    this->base .vtable = &vtbl_virt_D_B.ptr;
    this->base2.vtable = &vtbl_virt_D_C.ptr;
}

int main(void) {
    mult_D d1;
    virt_D d2;

    printf("%p: &d1\n", &d1);
    mult_B *d1b = &d1.base;
    printf("%p: &d1b->a\n", &d1b->base.a);
    printf("%p: &d1.b\n", &d1b->b);
    mult_C *d1c = &d1.base2;
    printf("%p: &d1c->a\n", &d1c->base.a);
    printf("%p: &d1.c\n", &d1c->c);
    printf("%p: &d1.d\n", &d1.d);

    virt_D_init(&d2);
    printf("\n%p: &d2\n", &d2);
    virt__B *d2b = &d2.base;
    void **d2bvt = *(void ***)d2b;
    printf("%p: %p (vtable)\n", d2b, d2bvt);
    printf("%p: %p\n", &d2bvt[-3], d2bvt[-3]);
    printf("%p: &d2.b\n", &d2b->b);
    virt__C *d2c = &d2.base2;
    void **d2cvt = *(void ***)d2c;
    printf("%p: %p (vtable)\n", d2c, d2cvt);
    printf("%p: %p\n", &d2cvt[-3], d2cvt[-3]);
    printf("%p: &d2.c\n", &d2c->c);
    printf("%p: &d2.d\n", &d2.d);
    printf("%p: &d2.a\n", &d2.base3.a);

    return 0;
}
