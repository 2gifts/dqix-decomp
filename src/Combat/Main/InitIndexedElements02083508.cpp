#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif


struct ElemA02083508 {
    void* pB;       // 0x0
    void* pResult;  // 0x4
    char pad[0x18];
};

struct ElemB02083508 {
    char data[0x20];
};

struct Obj02083508 {
    char pad[0x194];
    struct ElemA02083508 arrA[11];  // 0x194
    char pad2[IS_JPN ? 0x364 : 0x3fc];
    struct ElemB02083508 arrB[11];  // 0x6f0
};

struct StructDE1D4;
void InitStruct020de1d4(struct StructDE1D4*);
unsigned char* GetIndexedBlockPointer0208349c(unsigned char* base, int idx);

// USA: func_02083508
ARM void InitIndexedElements02083508(struct Obj02083508* o) {
    int i;
    for (i = 0; i < 11; i++) {
        InitStruct020de1d4((struct StructDE1D4*)&o->arrA[i]);
#if defined(jpn)
        o->arrA[i].pResult = (unsigned char*)o + 0x56f + i * 0x15;
#else
        o->arrA[i].pResult = GetIndexedBlockPointer0208349c((unsigned char*)o, i);
#endif
        o->arrA[i].pB = &o->arrB[i];
    }
}
