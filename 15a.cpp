#include <stdio.h>

class IMalloc {
public:
    virtual void _stdcall QueryInterface(void *, void **) = 0;
    virtual int _stdcall AddRef() = 0;
    virtual int _stdcall Release() = 0;
    virtual void *_stdcall Alloc(int) = 0;
    virtual void *_stdcall Realloc(void *, int) = 0;
    virtual void _stdcall Free(void *) = 0;
    virtual int _stdcall GetSize(void *) = 0;
    virtual int _stdcall DidAlloc(void *) = 0;
    virtual void _stdcall HeapMinimize() = 0;
};

extern "C" int _stdcall SHGetMalloc(IMalloc **);

int main() {
    IMalloc *pMalloc;
    if (SHGetMalloc(&pMalloc)) return 1;
    void *p = pMalloc->Alloc(10);
    int s = pMalloc->GetSize(p);
    printf("%p: %d\n", p, s);
    pMalloc->Free(p);
    pMalloc->Release();
}
