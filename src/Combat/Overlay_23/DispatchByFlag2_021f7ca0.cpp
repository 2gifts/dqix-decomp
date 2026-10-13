#include <globaldefs.h>

struct Obj_02184540;
int GetFieldB0_02184540(struct Obj_02184540* obj);
struct Obj_02184548;
int GetFieldB4_02184548(struct Obj_02184548* obj);

struct Obj021f7aac;
struct Rec020467f0;
extern "C" void func_ov023_021f7aac(struct Obj021f7aac* obj, void* keyObj, struct Rec020467f0* entry, unsigned int entryLength);
extern "C" void func_ov023_021f7b98(struct Obj021f7aac* obj, void* keyObj, int flag, struct Rec020467f0* entry, unsigned int entryLength);

struct Obj021f7ca0 {
    char pad0[0xc];
    unsigned char fieldC;
};

// USA: func_ov023_021f7ca0  (semantic: DispatchByFlag2_021f7ca0)
extern "C" ARM void func_ov023_021f7ca0(struct Obj021f7ca0* obj, void* keyObj) {
    struct Rec020467f0* entry = (struct Rec020467f0*)GetFieldB0_02184540((struct Obj_02184540*)keyObj);
    unsigned int entryLength = GetFieldB4_02184548((struct Obj_02184548*)keyObj);
    if (entry != 0 && entryLength != 0) {
        if (obj->fieldC & 0x2) {
            func_ov023_021f7b98((struct Obj021f7aac*)obj, keyObj, 1, entry, entryLength);
        } else {
            func_ov023_021f7aac((struct Obj021f7aac*)obj, keyObj, entry, entryLength);
        }
    }
}
