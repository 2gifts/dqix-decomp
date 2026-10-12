#include <globaldefs.h>

int CheckField0x9cSetWhenField0xd4Present(unsigned char* obj);
struct ScaledElementList0204aa28;
void* GetScaledElementPtr(struct ScaledElementList0204aa28* list);

struct SubStruct02081e18 {
    char pad[0x1c];
    unsigned char loNibble1c : 4;
    unsigned char hiNibble1c : 4;
};

struct Elem02081e18 {
    char pad0[0x4];
    void* f4;
    char pad1[0xa0 - 0x8];
    int a0;
    int a4;
    char pad2[0xe0 - 0xa8];
};

struct Obj02081e18 {
#if defined(jpn)
    char pad0[0x20];
#else
    char pad0[0x2c];
#endif
    int f2c;
    Elem02081e18* f30;
    char pad1[0x39 - 0x34];
    unsigned char f39;
};

#if defined(jpn)
#define FindMatchingElemSumOrScaledPtr02081e18 func_02082754
extern "C" ARM void* func_02082754(Obj02081e18* obj, int type);
#endif

// USA: func_02081e18
ARM void* FindMatchingElemSumOrScaledPtr02081e18(Obj02081e18* obj, int type) {
    if (obj->f2c == 0 || obj->f30 == 0) return NULL;
    Elem02081e18* elem;
    int i;
    for (i = (int)obj->f39 - 1; i >= 0; i--) {
        elem = &obj->f30[i];
        if (CheckField0x9cSetWhenField0xd4Present((unsigned char*)elem) != 0 && elem->f4 != NULL) {
            SubStruct02081e18* sub = (SubStruct02081e18*)elem->f4;
            if (type == sub->hiNibble1c) {
                return (void*)(elem->a0 + elem->a4);
            }
        }
    }
    return GetScaledElementPtr((struct ScaledElementList0204aa28*)obj->f30->f4);
}
