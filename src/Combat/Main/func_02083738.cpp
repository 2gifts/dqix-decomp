#include <globaldefs.h>
#include <std_library_functions.h>

struct Elem02083738 {
    void* pB;
    void* pResult;
    char pad[0x18];
};

struct ElemB02083738 {
    char data[0x20];
};

struct Obj02083738 {
    char pad[0x194];
    struct Elem02083738 arrA[11];
    char pad2[0x3fc];
    struct ElemB02083738 arrB[11];
};

struct StructDE1D4;
extern "C" void _Z18InitStruct020de1d4P11StructDE1D4(struct StructDE1D4*);
extern "C" unsigned char* _Z30GetIndexedBlockPointer0208349cPhi(unsigned char* base, int idx);

// USA: func_02083738
extern "C" ARM void func_02083738(struct Obj02083738* o, int a1) {
    int i = -1;
    int j = -1;
    switch (a1) {
    case 0: i = 8; j = 7; break;
    case 1: i = 9; j = 8; break;
    case 4: i = 7; j = 6; break;
    case 2: i = 0; j = 0; break;
    case 5: i = 5; j = 4; break;
    case 3: i = 1; j = 1; break;
    case 6: i = 6; j = 5; break;
    case 7: i = 10; j = 9; break;
    }
    if (i >= 0 && j >= 0) {
        struct Elem02083738* e = &o->arrA[i];
        void* pb = e->pB;
        void* pr = e->pResult;
        *(short*)((char*)o + j * 2 + 0x488) = -1;
        memset(pb, 0, 0x20);
        *(unsigned char*)pr = 0;
        _Z18InitStruct020de1d4P11StructDE1D4((struct StructDE1D4*)e);
        e->pB = &o->arrB[i];
        e->pResult = _Z30GetIndexedBlockPointer0208349cPhi((unsigned char*)o, i);
    }
}