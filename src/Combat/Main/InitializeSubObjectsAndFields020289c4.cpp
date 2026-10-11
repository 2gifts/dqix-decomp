#include <globaldefs.h>
#if defined(jpn)
#define SUBOBJECT_OFFSET(x) ((x) - 4)
#else
#define SUBOBJECT_OFFSET(x) (x)
#endif

struct InitStruct;
struct ResetObject0209af34Struct;
struct ZeroWordAndByte0206ee60Struct;

ARM void InitializeStruct(struct InitStruct* s);
ARM void ClearHalfword0x18(void* obj);
ARM void ClearBuffer0209bc84(void* obj);
ARM void ResetObject0209af34(struct ResetObject0209af34Struct* obj);
ARM void* Clear12Bytes0206efc4(void* obj);
ARM void ZeroWordAndByte0206ee60(struct ZeroWordAndByte0206ee60Struct* s);
ARM void Clear12Bytes020a8e88(void* p);

struct BigRecord020289c4 {
    unsigned short field0;
    unsigned short flagsX : 2;
    unsigned short flagB : 1;
    unsigned short flagC : 1;
    unsigned short flagD : 12;
    unsigned short field4;
    unsigned short field6;
    unsigned int field8;
    unsigned char fieldC;
    signed char fieldD;
};

// USA: func_020289c4
ARM void InitializeSubObjectsAndFields020289c4(struct BigRecord020289c4* obj) {
    obj->flagB = 0;
    obj->flagC = 0;
    obj->field0 = 0;
    obj->field8 = 0;
    obj->field6 = 0;
    obj->fieldC = 0;
    obj->flagD = 0;
    obj->field4 = 0;
    obj->fieldD = -1;
    InitializeStruct((struct InitStruct*)((char*)obj + SUBOBJECT_OFFSET(0x18)));
    ClearHalfword0x18((char*)obj + SUBOBJECT_OFFSET(0x44));
    ClearBuffer0209bc84((char*)obj + SUBOBJECT_OFFSET(0x60));
    ResetObject0209af34((struct ResetObject0209af34Struct*)((char*)obj + SUBOBJECT_OFFSET(0x124)));
    Clear12Bytes0206efc4((char*)obj + SUBOBJECT_OFFSET(0x2f8));
    ZeroWordAndByte0206ee60((struct ZeroWordAndByte0206ee60Struct*)((char*)obj + SUBOBJECT_OFFSET(0x304)));
    Clear12Bytes020a8e88((char*)obj + SUBOBJECT_OFFSET(0x30c));
}

// JPN: 0x0202821c
