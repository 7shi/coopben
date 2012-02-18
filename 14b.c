void call_Test_show(void *t) {
    void **vtbl = *(void ***)t;
    void (*show)(void *) = (void (*)(void *))vtbl[0];
    (*show)(t);
}
