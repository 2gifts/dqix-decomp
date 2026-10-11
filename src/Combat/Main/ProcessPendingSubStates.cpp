#include <globaldefs.h>
#if defined(jpn)
enum { kRegionalFieldOffset = 0x2e4 };
#else
enum { kRegionalFieldOffset = 0x2f0 };
#endif


struct StateWithFourPtrs02040910 {
    char pad[0x10];
    void* field10;
    void* field14;
    void* field18;
    void* field1c;
};

struct Field18Obj02040910 {
    char pad[0xd4];
    unsigned char bit0 : 1;
};

extern "C" int _ZN8Object3D4DrawEb(void* obj, int arg1);
extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_ov017_0218eafc(int arg0, int arg1);
int Dispatch0203cd64(char* obj, int arg1);

// USA: func_02040910
ARM int ProcessPendingSubStates(struct StateWithFourPtrs02040910* obj, int arg1) {
    if (obj->field10) {
        _ZN8Object3D4DrawEb(obj->field10, 1);
    }
    if (obj->field14) {
        return Dispatch0203cd64((char*)obj->field14, arg1);
    }
    if (obj->field18) {
        struct Field18Obj02040910* p = (struct Field18Obj02040910*)obj->field18;
        if (p->bit0) {
            return 1;
        }
        return _ZN8Object3D4DrawEb(p, 1);
    }
    if (obj->field1c) {
        void* p = obj->field1c;
        if (*(unsigned char*)((char*)p + kRegionalFieldOffset) != 0) {
            return 1;
        }
        signed short val = *(signed short*)((char*)p + 4);
        int r = func_ov017_0218b5b0();
        func_ov017_0218eafc(r, val);
        return 1;
    }
    return 0;
}
