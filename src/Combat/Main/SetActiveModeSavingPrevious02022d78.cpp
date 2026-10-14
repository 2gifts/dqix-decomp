#include <globaldefs.h>

#if defined(jpn)
#define func_02022bb0 func_02022644
#endif

extern "C" int func_ov017_0218b5b0(void);
struct GameResources;
void SetSubBrightness(GameResources*, int, int);
extern "C" void func_02022bb0(void* obj);

struct Obj02022d78 {
    #if defined(jpn)
    char pad[0x915];
#else
    char pad[0x9c1];
#endif
    unsigned char curValue;
    unsigned char field9c2;
    unsigned char activeFlag;
    char pad2[0xa34 - 0x9c4];
    unsigned char prevValue;
};

// USA: func_02022d78
ARM void SetActiveModeSavingPrevious02022d78(struct Obj02022d78* obj, int newValue) {
    if (obj->activeFlag != 0) {
        SetSubBrightness((GameResources*)func_ov017_0218b5b0(), -16, 0);
    }
    func_02022bb0(obj);
    obj->prevValue = obj->curValue;
    obj->curValue = newValue;
    obj->activeFlag = 1;
    obj->field9c2 = 0;
}
