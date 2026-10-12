#include <globaldefs.h>

int CheckField0NonZero(int*);

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4*);

int TrySetMode02076ccc(void*, int);

extern "C" void* func_0202ae18(void* obj);
extern "C" unsigned short func_02078e60(void* obj, char* out);

struct Obj02078d84 {
    char pad1[0x138];
    unsigned char field138;
    char pad2[0x13];
    unsigned int field14c;
    char pad3[0x14];
    unsigned short field164;
};

#if defined(jpn)
#define UpdateActorMode02078d84 func_02079ca0
extern "C" ARM void func_02079ca0(struct Obj02078d84* obj);
#endif

// USA: func_02078d84
ARM void UpdateActorMode02078d84(struct Obj02078d84* obj) {
    void* s = func_0202ae18(obj);
    if (CheckField0NonZero((int*)s) != 0) {
        if (GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)s) != 0) {
            return;
        }
    }
    if (obj->field14c <= 0xbb8) {
        return;
    }
    char localFlag = 0;
    switch (obj->field138) {
    case 0:
        TrySetMode02076ccc(obj, 1);
        return;
    case 1:
    case 3:
    case 4:
    case 5:
#if !defined(jpn)
        if (TrySetMode02076ccc(obj, 2) != 0) {
            return;
        }
        obj->field164 = func_02078e60(obj, &localFlag);
#endif
        TrySetMode02076ccc(obj, 2);
        return;
    case 2:
        obj->field164 = func_02078e60(obj, &localFlag);
        TrySetMode02076ccc(obj, 3);
        return;
    }
}
