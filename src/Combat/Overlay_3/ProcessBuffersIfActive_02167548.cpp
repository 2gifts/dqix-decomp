// USA: func_ov003_02167548
#include <globaldefs.h>

struct Obj0207fcb8;
void ClearAllBuffers0207fcb8(Obj0207fcb8* obj);
struct Obj0207fd00;
void CallFunc0204c8f0OverEntries0207fd00(Obj0207fd00* obj);
struct Cont0207fd44;
void CallFunc0204b04cOverList0x2c(Cont0207fd44* obj);

struct Obj02167548 {
    char pad0[0x10];
    void* field10;
#if defined(jpn)
    char pad14[0x44 - 0x14];
#else
    char pad14[0x74 - 0x14];
#endif
    unsigned char flag74;
};

ARM void ProcessBuffersIfActive_02167548(Obj02167548* obj) {
    if (obj->flag74 && obj->field10) {
        ClearAllBuffers0207fcb8((Obj0207fcb8*)obj->field10);
        CallFunc0204c8f0OverEntries0207fd00((Obj0207fd00*)obj->field10);
        CallFunc0204b04cOverList0x2c((Cont0207fd44*)obj->field10);
    }
}
