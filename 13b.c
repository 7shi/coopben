void _ZN1B4setAEi(void *this, int a) {
    int offset = (*(int **)this)[-3];
    void *base = ((char *)this) + offset;
    *(int *)base = a;
}

void _ZN1C4setAEi(void *this, int a) {
    _ZN1B4setAEi(this, a);
}
