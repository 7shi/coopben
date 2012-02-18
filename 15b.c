#include <stdio.h>

typedef struct tagIMalloc IMalloc;

struct tagIMalloc {
    struct {
        void *QueryInterface;
        void *AddRef;
        int (*_stdcall Release)(IMalloc *);
        void *(*_stdcall Alloc)(IMalloc *, int);
        void *Realloc;
        void (*_stdcall Free)(IMalloc *, void *);
        int (*_stdcall GetSize)(IMalloc *, void *);
        void *DidAlloc;
        void *HeapMinimize;
    } *lpVtbl;
};

#define IMalloc_Release(T) (T)->lpVtbl->Release(T)
#define IMalloc_Alloc(T, s) (T)->lpVtbl->Alloc(T, s)
#define IMalloc_Free(T, p) (T)->lpVtbl->Free(T, p)
#define IMalloc_GetSize(T, p) (T)->lpVtbl->GetSize(T, p)

int _stdcall SHGetMalloc(IMalloc **);

int main() {
    void *p;
    size_t s;
    IMalloc *pMalloc;
    if (SHGetMalloc(&pMalloc)) return 1;
    p = IMalloc_Alloc(pMalloc, 10);
    s = IMalloc_GetSize(pMalloc, p);
    printf("%p: %d\n", p, s);
    IMalloc_Free(pMalloc, p);
    IMalloc_Release(pMalloc);
    return 0;
}
