#include <globaldefs.h>

#if defined(jpn)
#include "GameState/GameState.h"

struct RequestState02094b30 {
    char pad0[0x34];
    int pending;
    char pad38[4];
    int current;
    int cached;
    char pad44[0x56 - 0x44];
    unsigned char flag56;
    unsigned char flag57;
    unsigned char cachedValue;
    char cachedName[8];
    unsigned char requestFlag;
};

extern "C" void __clear(void*, unsigned int);
extern "C" int func_020952f4(char*);
extern "C" int func_02001aec(const void*, const void*, unsigned int);
extern "C" int _Z17GetField5cb0ValuePc(char*);
extern "C" void func_02094ab0(void*);

// USA: func_02094b30
extern "C" ARM void _Z21BlankFunction02094b30v(RequestState02094b30* obj, int id, int flag) {
    if (id < 0 || obj->pending >= 0 || obj->current == id) return;
    if (obj->cached == id) {
        int unchanged = 1;
        char name[8] = {};
        switch (obj->cached) {
        case 5000:
            if (func_02001aec(name, obj->cachedName, func_020952f4(name)) != 0) {
                unchanged = 0;
            }
            break;
        case 1000: {
            int value = _Z17GetField5cb0ValuePc((char*)GameState::GetInstance());
            value &= 0xff;
            if (value != obj->cachedValue) {
                unchanged = 0;
            }
            break;
        }
        }
        if (unchanged) return;
    }
    func_02094ab0(obj);
    obj->pending = id;
    obj->flag56 = 0;
    obj->flag57 = 0;
    obj->requestFlag = flag;
}
#else
// USA: func_02094b30
ARM void BlankFunction02094b30(void) {
}
#endif
