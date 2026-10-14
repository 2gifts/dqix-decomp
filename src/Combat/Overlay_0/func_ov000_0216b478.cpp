#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "Resource/Script.h"

struct Struct02184264 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct02184264 data_ov000_02184264;

extern "C" void __clear(void* buf, int size);
extern "C" void func_ov000_02169b78(void*);

struct Variant02030b0c { int tag; int u; };

struct Struct02030b7c;

struct Vec3s02030fc8 { signed short x, y, z; };
struct Vector3s;
void Vector3fix16Copy(Vector3s*, Vector3s const*);

struct VariantNodeTag0216b478 {
    int tag;
    int unused;
    void* strPtr;
    unsigned char byteC;
    unsigned char byteD;
    unsigned short halfE;
    unsigned char pad10;
    unsigned char pad11;
    struct Vec3s02030fc8 vec;
    unsigned short half18;
    unsigned char flag1a;
};

// USA: func_ov000_0216b478  (semantic: AllocateVariantNodeTag0x15)
extern "C" ARM int func_ov000_0216b478(struct Variant02030b0c* v, int count) {
    struct VariantNodeTag0216b478* node = (struct VariantNodeTag0216b478*)data_ov000_02184264.alloc->Allocate(sizeof(struct VariantNodeTag0216b478));

    struct Vec3s02030fc8 zeroVec;
    int byteVal;
    char* copied = 0;
    int flagC = 1;
    __clear(&zeroVec, 6);

    int intVal = ((Script::Parameter*)v)->ToInt();
    byteVal = ((Script::Parameter*)((struct Variant02030b0c*)((char*)v + 8)))->ToInt() - 0x1a;

    char* strPtr = (char*)(void*)((Script::Parameter*)((struct Struct02030b7c*)((char*)v + 0x10)))->ToString();
    if (strPtr != 0) {
        copied = (char*)data_ov000_02184264.alloc->Allocate(strlen(strPtr) + 1);
        strcpy(copied, strPtr);
    }

    if (count >= 4) {
        flagC = ((Script::Parameter*)((struct Variant02030b0c*)((char*)v + 0x18)))->ToInt();
    }

    node->tag = 0;
    node->unused = 0;
    node->tag = 0x15;
    node->halfE = (unsigned short)intVal;
    node->byteD = (unsigned char)byteVal;
    node->strPtr = copied;
    node->byteC = (unsigned char)flagC;
    node->half18 = 0;
    node->pad10 = 0;
    Vector3fix16Copy((Vector3s*)&node->vec, (Vector3s const*)&zeroVec);
    node->flag1a = 1;
    func_ov000_02169b78(node);
    return 1;
}
