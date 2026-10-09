#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

extern "C" void func_ov000_02169b78(void* node);
extern "C" void __clear(void* buf, int size);

struct Struct02184264 {
    unsigned char pad[8];
    SafeAllocator* alloc;
};
extern struct Struct02184264 data_ov000_02184264;

struct VariantNodeTag0x15 {
    int tag;
    int unused;
    char* name;
    unsigned char fieldC;
    signed char fieldD;
    short fieldE;
    unsigned char field10;
    Vector3fix16 pos;
    short angle;
    unsigned char flagA;
    unsigned char flagB;
};

// USA: func_ov000_0216a68c
extern "C" ARM int func_ov000_0216a68c(Script::Parameter* p, int n) {
    VariantNodeTag0x15* node = (VariantNodeTag0x15*)data_ov000_02184264.alloc->Allocate(sizeof(VariantNodeTag0x15));
    int fieldE;
    int fieldD = -1;
    const char* s;
    char* name = NULL;
    int field10 = 0;
    int fieldC = 1;
    int flagA = 0;
    int flagB = 0;
    short angle = 0;
    Vector3fix16 pos;
    __clear(&pos, sizeof(pos));
    if (p[0].type == 1) {
        if (n >= 3 && p[2].type == 0) {
            fieldE = p++->ToInt();
            fieldD = p++->ToInt() - 0x1a;
            s = p++->ToString();
            if (s != NULL) {
                name = (char*)data_ov000_02184264.alloc->Allocate(strlen(s) + 1);
                strcpy(name, s);
            }
            if (n >= 4) {
                fieldC = p++->ToInt();
            }
            if (n >= 5) {
                flagA = p++->ToInt() != 0;
            }
            if (n >= 6) {
                flagB = p++->ToInt() != 0;
            }
        } else {
            fieldE = p++->ToInt() + 100;
            if (n >= 2) {
                field10 = p++->ToInt();
            }
            if (n >= 3) {
                p->ToVec3fix16(&pos);
            }
        }
    } else if (p[0].type == 2) {
        angle = p++->ToFloat() * 4096.0f;
        if (n >= 2) {
            fieldE = p++->ToInt() + 100;
        } else {
            return 0;
        }
        if (n >= 3) {
            field10 = p++->ToInt();
        }
        if (n >= 4) {
            p->ToVec3fix16(&pos);
        }
    } else {
        return 0;
    }
    node->tag = 0;
    node->unused = 0;
    node->tag = 0x15;
    node->angle = angle;
    node->fieldE = fieldE;
    node->fieldD = fieldD;
    node->field10 = field10;
    node->name = name;
    node->fieldC = fieldC;
    Vector3fix16Copy(&node->pos, &pos);
    node->flagA = flagA;
    node->flagB = flagB;
    func_ov000_02169b78(node);
    return 1;
}
