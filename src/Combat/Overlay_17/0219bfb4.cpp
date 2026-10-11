// JPN: func_ov017_0219caa4
#include <globaldefs.h>

#if defined(jpn)
enum { kStatusOffset = 0x240c, kStatusFlagOffset = 0x282, kFieldXOffset = 0x27c6, kFieldYOffset = 0x27c4, kFieldFlagOffset = 0x27c8, kFieldPositionOffset = 0x27b4, kFieldHalfwordAOffset = 0x27f4, kFieldHalfwordBOffset = 0x27f6, kControllerBufferOffset = 0x28, kControllerBufferSize = 0x800 };
#else
enum { kStatusOffset = 0x23ec, kStatusFlagOffset = 0x262, kFieldXOffset = 0x2786, kFieldYOffset = 0x2784, kFieldFlagOffset = 0x2788, kFieldPositionOffset = 0x2774, kFieldHalfwordAOffset = 0x27b4, kFieldHalfwordBOffset = 0x27b6, kControllerBufferOffset = 0x5c, kControllerBufferSize = 0x960 };
#endif

#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "System/OverlayId.h"
#include "World/Object3D.h"

struct StreamHeader;
struct Struct020a8170;
struct Container020a83fc;
struct TailList020469b4;
struct TailNode020469b4;
struct List020727d8;
struct S021b2ba0;
struct S021b2bf4;
struct S021b2c0c;
struct S021b2bdc;
struct Obj021ba90c;

struct Entry020a83fc {
    char pad0[0x1a];
    unsigned short x;
    unsigned short y;
    char pad1e[2];
    int posX;
    int posZ;
};

extern "C" void* func_0202ae18(void);
extern "C" void* func_02012fe4(void);
extern "C" void* func_0205ec34(void);
void* GetPtrField0x2a04(GameState* gameState);
void* GetField0x3f8Address(GameState* battleStruct);
extern "C" int func_0202c540(void* p);
extern "C" int func_0206e558(void* obj);
extern "C" int func_0202c508(void* p);
int TestBitInByteArray(int unused, unsigned char* arr, int index);
extern "C" void __clear(void* dst, unsigned int size);
extern "C" void _Z19ClearStruct020a8170P14Struct020a8170(Struct020a8170* s);
extern "C" void func_020a818c(void* cont, SafeAllocator* alloc);
extern "C" void func_020a8304(void* cont);
extern "C" Entry020a83fc* _Z21FindEntryById020a83fcP17Container020a83fci(Container020a83fc* cont, int id);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" void func_ov017_021d1a18(short a, short b, int c, int d);
extern "C" void _Z40SetHalfFieldsAndEnqueueIfActive_021d1c2ctt(unsigned short a, unsigned short b);
extern "C" void _Z18InitStruct02070378Pc(char* obj);
extern "C" void _Z27InitAndResetHeader_0219e310Phi(unsigned char* node, int v);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
extern "C" void _Z22ClearFlagBytes02017d7cPv(void* obj);
void ClearFlag0x1ceBit0x4(unsigned char* obj);
void SetFlag0x1ceBit0x4(unsigned char* obj);
extern "C" int _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void _Z24ReinitController02043204Pc(char* obj);
extern "C" int func_ov017_0219ff58(void* base, int a, int b, int c);
extern "C" void _Z21InitObjState_021b2174Ph(unsigned char* obj);
extern "C" void _Z23SetNameChecked_021b2ba0P9S021b2ba0Pc(S021b2ba0* obj, char* name);
extern "C" void _Z25SetFields30And34_021b2bd0Pvii(void* obj, int a, int b);
extern "C" void _Z16SetBit4_021b2bf4P9S021b2bf4j(S021b2bf4* obj, unsigned int v);
extern "C" void _Z16SetBit5_021b2c0cP9S021b2c0cj(S021b2c0c* obj, unsigned int v);
extern "C" void _Z16SetBit3_021b2bdcP9S021b2bdcj(S021b2bdc* obj, unsigned int v);
int LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);
extern "C" void _Z23ResetListHeader020727d8P12List020727d8(List020727d8* list);
int GetField5cb0Value(char* obj);
extern "C" void _Z26SubmitAndRunScript02072928PvP12StreamHeaderiiS_h(void* list, StreamHeader* header, int length, int id, void* out, unsigned char index);
int CompareStrings(const char* a, const char* b);
extern "C" int func_02005a94(signed char* s);
extern "C" void _Z20InitState16_021ba90cP11Obj021ba90c(Obj021ba90c* p);
extern "C" void _Z29AllocateAndCopyBuf20_021689d8P13SafeAllocatorPv(SafeAllocator* a, void* target);

extern char data_ov017_021d75d0;
extern char data_ov017_021d75dc;
extern char data_ov017_021d75fa;
extern char data_0211e33c;

static inline unsigned char GetScriptIndex(int slot, int offset) {
    return slot * 4 + offset;
}

// USA: func_ov017_0219bfb4
extern "C" ARM void func_ov017_0219bfb4(int mode, unsigned short id) {
    GameResources* res = func_ov017_0218b5b0();
    GameState* gs = GameState::GetInstance();
    char* party = (char*)GetPtrField0x2a04(gs);
    char* record = (char*)GetField0x3f8Address(gs);
    void* search = func_0202ae18();
    char* field = (char*)func_02012fe4();
    unsigned char* flags = (unsigned char*)func_0205ec34();
    char* status = field + kStatusOffset;
    TailList020469b4* list = (TailList020469b4*)res->unknown_ptr_array_36fc[0];
    unsigned char* node = (unsigned char*)res->unknown_ptr_array_36fc[4];
    unsigned char* marker = (unsigned char*)res->unknown_ptr_array_371c[4];
    BackgroundLoader::GetInstance()->MaybeFreeAllocations();

    unsigned short sceneId = id;
    if (id == 0) {
        sceneId = *(int*)(party + 0x2c94);
    }

    if (func_0202c540(search)) {
        func_0206e558(flags);
    }
    if (mode == 2) {
        status[kStatusFlagOffset] = 0;
    }
    if (mode == 2 && func_0202c508(search)) {
        if (TestBitInByteArray((int)flags, flags + 0x8c, 0x2b)) {
            char buf[0x533];
            __clear(buf, 0x533);
            SafeAllocator alloc;
            alloc.ResetAllocatorPointer();
            alloc.ResetAllocatorPointer();
            alloc.CreateTypeA(buf, 0x533);
            char cont[0x10];
            _Z19ClearStruct020a8170P14Struct020a8170((Struct020a8170*)cont);
            func_020a818c(cont, &alloc);
            func_020a8304(cont);
            Entry020a83fc* entry = _Z21FindEntryById020a83fcP17Container020a83fci((Container020a83fc*)cont, sceneId);
            if (entry) {
                *(unsigned short*)(field + kFieldXOffset) = entry->x;
                *(unsigned short*)(field + kFieldYOffset) = entry->y;
                field[kFieldFlagOffset] = 0;
                Vector3i pos = *(Vector3i*)(field + kFieldPositionOffset);
                pos.x = entry->posX;
                pos.z = entry->posZ;
                _ZN8Vector3iaSERKS_((int*)(field + kFieldPositionOffset), (int*)&pos);
                func_ov017_021d1a18(entry->x, entry->y, 0, 1);
            }
            alloc.Destroy();
        }
        if (sceneId == 0x119a) {
            *(unsigned short*)(field + kFieldHalfwordAOffset) = 1;
            *(unsigned short*)(field + kFieldHalfwordBOffset) = 0;
            _Z40SetHalfFieldsAndEnqueueIfActive_021d1c2ctt(1, 0);
        }
    }

    if (node[2] == 0) {
        _Z18InitStruct02070378Pc(record);
        *(unsigned short*)record = sceneId;
        record[0xc] = 0;
        _Z27InitAndResetHeader_0219e310Phi(node, 0);
        AppendNodeToTail(list, (TailNode020469b4*)node);
    } else if (node[3] == 0) {
        _Z18InitStruct02070378Pc(record);
        *(unsigned short*)record = sceneId;
        record[0xc] = 0;
    }

    _Z22ClearFlagBytes02017d7cPv(field);
    ((unsigned char*)record)[0x6e] |= 0x20;
    for (int i = 0; i < *(unsigned char*)(party + 0xf7c); i++) {
        GameObject* member = gs->GetPartyMemberByIndex(*(unsigned char*)(party + i + 0xf78));
        if (member) {
            if (i == 0) {
                ClearFlag0x1ceBit0x4((unsigned char*)member);
                ((Object3D*)member)->SetInheritedAlpha(0x1f);
            } else {
                SetFlag0x1ceBit0x4((unsigned char*)member);
                ((Object3D*)member)->SetInheritedAlpha(0);
            }
        }
    }

    if (marker[2] != 0) {
        return;
    }

    char* controller = (char*)_Z26GetGlobalField0x1c020421a0v();
    memset(*(void**)(controller + kControllerBufferOffset), 0, kControllerBufferSize);
    _Z24ReinitController02043204Pc(controller);
    if (func_ov017_0219ff58(res, 0, 0, 1)) {
        unsigned char* obj = (unsigned char*)res->unknown_ptr_array_3afc[0x14];
        _Z21InitObjState_021b2174Ph(obj);
        _Z23SetNameChecked_021b2ba0P9S021b2ba0Pc((S021b2ba0*)obj, &data_ov017_021d75d0);
        _Z25SetFields30And34_021b2bd0Pvii(obj, (int)_Z29AllocateAndCopyBuf20_021689d8P13SafeAllocatorPv, OVERLAY_ID(4));
        _Z16SetBit4_021b2bf4P9S021b2bf4j((S021b2bf4*)obj, 1);
        _Z16SetBit5_021b2c0cP9S021b2c0cj((S021b2c0c*)obj, 1);
        _Z16SetBit3_021b2bdcP9S021b2bdcj((S021b2bdc*)obj, 0);
        AppendNodeToTail(list, (TailNode020469b4*)obj);
        return;
    }

    BackgroundLoader::AddLockGlobal();
    unsigned int length = 0;
    LoadFileIntoMemory(&data_ov017_021d75dc, &data_0211e33c, &length);
    if (length == 0) {
        BackgroundLoader::RemoveLockGlobal();
        return;
    }

    char scripts[8];
    _Z23ResetListHeader020727d8P12List020727d8((List020727d8*)scripts);
    char result[8];
    __clear(result, 8);
    short scriptId = *(int*)(party + 0x2c94);
    if (id != 0) {
        scriptId = id;
    }
    int now = GetField5cb0Value((char*)gs);
    for (int j = 0; j < 3; j++) {
        unsigned char fromIndex = GetScriptIndex(j, 0);
        unsigned char toIndex = GetScriptIndex(j, 1);
        char from[8];
        __clear(from, 8);
        char to[8];
        __clear(to, 8);
        _Z26SubmitAndRunScript02072928PvP12StreamHeaderiiS_h(scripts, (StreamHeader*)&data_0211e33c, length, scriptId, from, fromIndex);
        _Z26SubmitAndRunScript02072928PvP12StreamHeaderiiS_h(scripts, (StreamHeader*)&data_0211e33c, length, scriptId, to, toIndex);
        int start = 0;
        int end = 0;
        if (CompareStrings(from, &data_ov017_021d75fa)) {
            start = func_02005a94((signed char*)from);
        }
        if (CompareStrings(to, &data_ov017_021d75fa)) {
            end = func_02005a94((signed char*)to);
        }
        int inRange = 0;
        if (start == 0 && end == 0) {
            inRange = 1;
        } else if (now >= start && now <= end) {
            inRange = 1;
        }
        if (inRange) {
            unsigned char index;
            if (gs->IsMorningDayOrEvening()) {
                index = (unsigned int)j * 4 + 2;
            } else {
                index = (unsigned int)j * 4 + 3;
            }
            _Z26SubmitAndRunScript02072928PvP12StreamHeaderiiS_h(scripts, (StreamHeader*)&data_0211e33c, length, scriptId, result, index);
            break;
        }
    }
    BackgroundLoader::RemoveLockGlobal();

    signed char state = 1;
    if (CompareStrings(result, &data_ov017_021d75fa)) {
        state = func_02005a94((signed char*)result);
    }
    if (state != 3) {
        _Z20InitState16_021ba90cP11Obj021ba90c((Obj021ba90c*)marker);
        marker[0x20] = mode;
        marker[0x21] = state;
        AppendNodeToTail(list, (TailNode020469b4*)marker);
    }
}
