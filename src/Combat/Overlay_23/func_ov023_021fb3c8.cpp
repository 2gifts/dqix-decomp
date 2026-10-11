#include <globaldefs.h>
#include "GameState/GameState.h"


struct Container0205a3d0;
struct Elem0205a3d0_021fb3c8 {
    char pad0[0x15];
    unsigned char flags15;
};
void SetEntryFlag2ByKey0205a370(struct Container0205a3d0*, int);
void SetEntryByte14ByKey0205a42c(struct Container0205a3d0*, int, int);
struct Elem0205a3d0_021fb3c8* FindEntryByHalfword0205a3d0(struct Container0205a3d0*, int);

extern "C" void* func_ov011_021849c8(void* p);
extern "C" void* func_ov023_021f6880(void* listHead, int key);
extern "C" void* func_ov023_021fad18(void* node);
extern "C" void func_0205a254(struct Container0205a3d0*, unsigned char, unsigned int);
extern "C" void func_0205addc(void*, unsigned char);

struct Obj021fb3c8 {
    char pad0[0xc];
    unsigned char flags0xc;
    char pad0d[0x20 - 0xd];
    unsigned short field20;
    unsigned short field22;
    unsigned short field24;
    char pad26[0x28 - 0x26];
    short field28;
    short field2a;
};

// USA: func_ov023_021fb3c8  (semantic: UpdateEntryFieldsFromObj_021fb3c8)
extern "C" ARM void func_ov023_021fb3c8(struct Obj021fb3c8* obj, void* arg1) {
    if (obj->flags0xc & 8) {
        return;
    }
    GameState* battleStruct = GameState::GetInstance();
    void* listHead = func_ov011_021849c8(arg1);
    void* node = func_ov023_021f6880(listHead, obj->field20);
    void* p = func_ov023_021fad18(node);
    struct Container0205a3d0* container = *(struct Container0205a3d0**)((char*)p + 0x3c);
    if (container == NULL) {
        return;
    }
    SetEntryFlag2ByKey0205a370(container, obj->field22);
    struct Elem0205a3d0_021fb3c8* entry = FindEntryByHalfword0205a3d0(container, obj->field22);
    if (entry != NULL) {
        entry->flags15 |= 8;
    }
    SetEntryByte14ByKey0205a42c(container, obj->field22, (unsigned char)obj->field24);
    unsigned int scaleCount = battleStruct->GetTickCount();
    func_0205a254(container, (unsigned char)obj->field22, scaleCount);
    short f28, f2a;
    f2a = obj->field2a;
    f28 = obj->field28;
    struct Elem0205a3d0_021fb3c8* entry2 = FindEntryByHalfword0205a3d0(container, obj->field22);
    if (entry2 != NULL) {
        *(short*)((char*)entry2 + 0x4) = f28;
        *(short*)((char*)entry2 + 0x6) = f2a;
    }
    func_0205addc(p, (unsigned char)obj->field22);
}
