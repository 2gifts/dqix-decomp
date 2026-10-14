#include <globaldefs.h>

#if defined(jpn)
#define REGION_VALUE(jpnValue, usaValue) jpnValue
extern char* data_020f2a38;
extern "C" int func_020e04f8(void*, void*, const char*, short, bool);
#else
#define REGION_VALUE(jpnValue, usaValue) usaValue
#endif
#include "Combat/Main/BattleList.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "System/OverlayId.h"
#include "Graphics/LightingManager.h"
struct BattleStruct {
    int unk0;
    int unk4;
    struct CombatantStruct* combatantList[0xe9];
};
extern "C" struct BattleStruct* _ZN9GameState11GetInstanceEv();

extern "C" void* func_ov017_0218b5b0();
extern "C" void* func_0202ae18(void);
extern "C" void* func_0205ec34(void);
extern "C" void func_020703c8(int index, int hour, int minute, int second);
extern "C" void* func_ov017_021baedc(void* self, int flag);

struct TailNode020469b4;
struct TailList020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

struct SetFlagStruct;
void SetFlag0x9c6(struct SetFlagStruct* p, int value);
void InitContext020e1154(void* obj);

void* GetField0x3f8Address(GameState*);
void InitStruct02070378(char* obj);

void* GetGlobalPtr021075f4(void);
void* FindEntryPointerByKey0203df78(void* base, int key);
int GetField0x8(int* obj);

extern "C" void func_ov017_021b8d80(void*);
extern "C" void func_ov017_021b8d1c(void* obj);

int GetFieldIfFlag4(char* obj);
void ClearIntAt0x23c(unsigned char* obj);

extern "C" void _ZN8Vector3iaSERKS_(void* dst, const void* src);

extern "C" void func_ov017_021b6f18(void* node);
extern "C" void func_ov017_021b6e70(void* evt, unsigned short tag);
extern "C" int func_0202c540(void* p);
extern "C" void func_ov017_021b7104(void* node, void* out);

struct GameState;
void* GetPtrField0x2a04(GameState*);
void* ZeroInitReturn020de824(void* obj);
void ZeroInit020de848(void* obj);
extern char* data_020f2a38;
extern char* data_020f2a30;
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
int BuildDescriptorFlag1_020de980(void* a, void* b, void* c, int d, int e);
void InitStruct0207cbe8(char* obj);
extern "C" void func_0207d300(void* obj, short id, int a, int b);

int DecrementKeyEverywhere02086d88(unsigned char* self, int key);
unsigned char CopyOutRegion0x5718(char* obj, void* dst);
struct CombatantStruct;
extern "C" struct CombatantStruct* _Z25GetCombatantWithFlag0x100P9GameStatei(struct BattleStruct* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);
struct Container02083554;
void* FindEntryByShortField02083554(struct Container02083554* c, int id);
extern "C" void func_02083738(void* obj, int bits);
int CheckField0NonZero(int* obj);
extern "C" void func_ov017_021c3fb4(int combatantId, int flag);
extern "C" void func_ov017_021c4418(int combatantId, signed char flag10);
extern "C" void func_ov017_0218f5a4(void* a, int i, int b, int c, int d);

struct Ctx021a3498;
void ClearIfMatchAndFinalize_021a3498(struct Ctx021a3498* self);
struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);

extern "C" void* func_02012fe4(void);
extern "C" void func_0206461c(void* a, int b);
int GetField0x3acValue(GameState*);

void InitByteHeader_021c16a8(unsigned char* self);

extern "C" void func_ov017_021b65e0(void* obj, int arg1);

struct S021b2ba0;
void InitObjState_021b2174(unsigned char* obj);
void SetNameChecked_021b2ba0(S021b2ba0* obj, char* src);
void SetFields30And34_021b2bd0(void* obj, int a, int b);
struct S021b2bf4;
void SetBit4_021b2bf4(S021b2bf4* obj, unsigned int v);
struct S021b2c0c;
void SetBit5_021b2c0c(S021b2c0c* obj, unsigned int v);
struct S021b2bdc;
void SetBit3_021b2bdc(S021b2bdc* obj, unsigned int v);
struct HeadList020469f8;
struct HeadNode020469f8;
void PrependNodeToHead(struct HeadList020469f8* list, struct HeadNode020469f8* node);

extern "C" void _Z24InitAndRegister_0215e25cPvS_();
extern "C" void func_ov004_02168684();
extern "C" void _Z29AllocateAndCopyBuf20_021689d8P13SafeAllocatorPv();
extern char data_020f0b40[];
extern char data_020f0b4c[];
extern char data_020f0b56[];

struct AllocHolder0206f81c {
    char pad[0x164 - sizeof(SafeAllocator)];
    SafeAllocator allocs[2];
    SafeAllocator* GetAllocator(int i) { return &allocs[i]; }
};

struct SelfBuf0206f81c {
    SafeAllocator alloc;
    char pad[0x14 - sizeof(SafeAllocator)];
    char sub14[0x18];
    void* eventPtr;
    char pad2[8];
};

struct Entry02083554 {
    int unk0;
    int unk4;
    unsigned int kind : 4;
};

struct Flags0206f81c {
    unsigned short low : 13;
    unsigned short high : 3;
};

struct FlagsRoot0206f81c {
    char pad[0x5d0c];
    struct Flags0206f81c flags;
};

struct Desc0206f81c {
    unsigned char f0;
    unsigned char f1;
    unsigned short f2;
    unsigned short f4;
    unsigned char pad6[2];
    int f8;
    unsigned char fc;
    unsigned char fd;
    unsigned char fe;
    unsigned char ff;
    short f10;
    unsigned char f12;
    unsigned char pad13;
    int f14;
};

// USA: func_0206f81c
extern "C" ARM void func_0206f81c(void* a0) {
    void* searchPtr;
    void* miscCtx;
    int flag20;
    int val1c;
    int flag18;
    int flag14;
    short val10;
    struct BattleStruct* battle2;
    BackgroundLoader* inst;
    struct TailList020469b4* tailList;
    int vec[3];
    struct BattleStruct* battle = _ZN9GameState11GetInstanceEv();
    void* g = func_ov017_0218b5b0();
    void* gBase = (char*)g + 0x3000;
    tailList = *(struct TailList020469b4**)((char*)gBase + REGION_VALUE(0x4ec, 0x6fc));
    searchPtr = func_0202ae18();
    miscCtx = func_0205ec34();
    unsigned char* node = *(unsigned char**)((char*)a0 + 0x30);
    unsigned char slFlag;
    flag20 = 0;
    val1c = 0;
    slFlag = 0;
    flag18 = 0;
    flag14 = 0;

    if (node != NULL) {
        while (node != NULL) {
            unsigned short type = *(unsigned short*)(node + 0);
            switch (type) {
            case 0x84: {
                func_020703c8(((unsigned char*)miscCtx)[0x332], *(unsigned short*)(node + 4), *(unsigned short*)(node + 6), *(unsigned short*)(node + 8));
                flag20 = 1;
                break;
            }

            case 0x94: {
                for (int i = 0; i < 5; i++) {
                    func_020703c8(i, *(unsigned short*)(node + 4), *(unsigned short*)(node + 6), *(unsigned short*)(node + 8));
                }
                flag20 = 1;
                break;
            }

            case 0xd6: {
                func_020703c8(*(unsigned short*)(node + 2), *(unsigned short*)(node + 4), *(unsigned short*)(node + 6), *(unsigned short*)(node + 8));
                flag20 = 1;
                break;
            }

            case 0x77: case 0x80: case 0x9b: {
                struct TailNode020469b4* node7 = *(struct TailNode020469b4**)((char*)g + 0x3000 + REGION_VALUE(0x524, 0x734));
                func_ov017_021baedc(node7, 1);
                *(unsigned short*)((char*)node7 + 8) = *(unsigned short*)(node + 2);
                AppendNodeToTail(tailList, node7);
                SetFlag0x9c6(*(struct SetFlagStruct**)((char*)g + 0x3000 + REGION_VALUE(0x4c0, 0x6d0)), 1);
                InitContext020e1154((void*)0x1f4);
                break;
            }

            case 0x85: case 0x8a: case 0xe2: {
                unsigned char* f3f8 = (unsigned char*)GetField0x3f8Address((GameState*)battle);
                InitStruct02070378((char*)f3f8);
                f3f8[2] = 1;
                *(unsigned short*)(f3f8 + 0) = *(unsigned short*)(node + 2);
                *(unsigned int*)(f3f8 + 0x20) = *(unsigned short*)(node + 4);
                if (*(unsigned short*)(node + 0) == 0x8a) f3f8[6] = 1;
                if (*(unsigned short*)(node + 0) == 0xe2) f3f8[0xc] = 1;
                if (*((unsigned char*)battle + 0x5000 + REGION_VALUE(0xa4c, 0xcac)) != 0) f3f8[0x60] = 1;
                slFlag = 1;
                SetFlag0x9c6(*(struct SetFlagStruct**)((char*)g + 0x3000 + REGION_VALUE(0x4c0, 0x6d0)), slFlag);
                break;
            }

            case 0x76: {
                void* entry = FindEntryPointerByKey0203df78(GetGlobalPtr021075f4(), *(unsigned short*)(node + 2));
                int sb = 0;
                if (entry != NULL) {
                    sb = GetField0x8((int*)entry);
                }
                if (sb != 0) {
                    unsigned char r7flag;
                    unsigned char* r8 = *(unsigned char**)((char*)g + 0x3000 + REGION_VALUE(0x500, 0x710));
                    r7flag = *(unsigned char*)(r8 + 3);
                    if (r7flag != 0) {
                        func_ov017_021b8d80(r8);
                    }
                    unsigned char* p71c = *(unsigned char**)((char*)g + 0x3000 + REGION_VALUE(0x50c, 0x71c));
                    r7flag |= (*(unsigned char*)(p71c + 3) != 0 && *(unsigned char*)(p71c + 0x20) != 0);
                    func_ov017_021b8d1c(r8);
                    *(int*)(r8 + 0x114) = sb;
                    *(int*)(r8 + 0x124) = *(unsigned short*)(node + 4);
                    *(unsigned char*)(r8 + 0x139) = (r7flag != 0) ? 1 : 0;
                    AppendNodeToTail(tailList, (struct TailNode020469b4*)r8);
                    int flag4 = GetFieldIfFlag4((char*)battle);
                    if (flag4 != 0) {
                        ClearIntAt0x23c((unsigned char*)flag4);
                    }
                }
                break;
            }

            case 0x79: case 0x89: case 0xe1: {
                unsigned char* f3f8 = (unsigned char*)GetField0x3f8Address((GameState*)battle);
                InitStruct02070378((char*)f3f8);
                f3f8[2] = 1;
                *(unsigned short*)(f3f8 + 0) = *(unsigned short*)(node + 2);
                f3f8[0xc] = 1;
                if (*(unsigned short*)(node + 0) == 0x89) f3f8[6] = 1;
                if (*(unsigned short*)(node + 0) == 0xe1) f3f8[0xc] = 0;
                slFlag = 1;
                break;
            }

            case 0x7a: {
                _ZN8Vector3iaSERKS_(vec, node + 4);
                flag18 = 1;
                break;
            }

            case 0x7b: {
                val10 = *(short*)(node + 4);
                flag14 = 1;
                break;
            }

            case 0x78: {
                struct TailList020469b4* r7list;
                unsigned char* r8 = *(unsigned char**)((char*)g + 0x3000 + REGION_VALUE(0x508, 0x718));
                r7list = *(struct TailList020469b4**)((char*)g + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
                void* sb = LightingManager::GetInstance();
                func_ov017_021b6f18(r8);

                struct Desc0206f81c desc;
                desc.f0 = 1;
                desc.f1 = 0;
                desc.f2 = 0;
                desc.f4 = 0;
                desc.fc = 0;
                desc.fd = 0;
                desc.fe = 0;
                desc.ff = 0;
                desc.f14 = 0;
                desc.f10 = -1;
                desc.f12 = 2;
                desc.f8 = -1;

                desc.f1 = GetField0x3acValue((GameState*)battle);
                desc.f4 = *(unsigned short*)(node + 2) + 5 + 0x8000;
                desc.f2 = 0xffff;
                desc.f8 = *(unsigned short*)(node + 2);
                func_ov017_021b6e70(&desc, desc.f2);
                desc.f12 = *(int*)((char*)sb + 0x98);

                if (func_0202c540(searchPtr) != 0) {
                    if (desc.fc == 0 && desc.fd == 0) {
                        desc.f14 = 1;
                    }
                }
                func_ov017_021b7104(r8, &desc);
                AppendNodeToTail(r7list, (struct TailNode020469b4*)r8);
                break;
            }

            case 0x7c: {
                void* e = FindEntryPointerByKey0203df78(GetGlobalPtr021075f4(), *(unsigned short*)(node + 2));
                if (e != NULL) {
                    *(int*)e |= 0x8000;
                }
                break;
            }

            case 0x72: case 0x74: {
                if (GetPtrField0x2a04((GameState*)battle) != NULL) {
                    unsigned char eventBuf[0x18];
#if defined(jpn)
                    SafeAllocator* r7base = ((AllocHolder0206f81c*)g)->GetAllocator(1);
#else
                    void* r7base = ((AllocHolder0206f81c*)g)->GetAllocator(1);
#endif
                    ZeroInitReturn020de824(eventBuf);
                    ZeroInit020de848(eventBuf);
#if defined(jpn)
                    func_020e04f8(eventBuf, (void*)r7base, data_020f2a38, *(short*)(node + 2), true);
#else
                    BackgroundLoader::AddLockGlobal();
                    unsigned int outSize = 0;
                    void* loaded = ExtractFileFromGP2(data_020f2a38, data_020f2a30, &outSize);
                    if (loaded != NULL) {
                        BuildDescriptorFlag1_020de980(eventBuf, r7base, loaded, outSize, (int)(*(short*)(node + 2)));
                    }
                    BackgroundLoader::RemoveLockGlobal();
#endif
                    SelfBuf0206f81c selfBuf;
                    selfBuf.alloc.ResetAllocatorPointer();
                    ZeroInitReturn020de824(selfBuf.sub14);
                    InitStruct0207cbe8((char*)&selfBuf);
                    InitStruct0207cbe8((char*)&selfBuf);
                    selfBuf.eventPtr = eventBuf;
                    func_0207d300(&selfBuf, *(short*)(node + 2), (signed char)*(unsigned short*)(node + 4), 0);
                }
                break;
            }

            case 0x73: case 0x75: {
                void* p2a04 = GetPtrField0x2a04((GameState*)battle);
                if (p2a04 != NULL) {
                    int matchCount = 0;
                    for (int total = 0; total < *(unsigned short*)(node + 4); total++) {
                        if (DecrementKeyEverywhere02086d88((unsigned char*)p2a04, *(short*)(node + 2)) != 0) matchCount++;
                    }
                    if (matchCount < *(unsigned short*)(node + 4)) {
                        battle2 = _ZN9GameState11GetInstanceEv();
                        unsigned char buf40[4];
                        int idArr[4];
                        int arrCount = 0;
                        unsigned char count = CopyOutRegion0x5718((char*)battle2, buf40);
                        for (int i = 0; i < count; i++) {
                            struct CombatantStruct* combatant = _Z25GetCombatantWithFlag0x100P9GameStatei(battle2, buf40[i]);
                            if (combatant != NULL) {
                                int field150 = GetFieldAt0x150((unsigned char*)combatant);
                                if (field150 != 0) {
                                    struct Entry02083554* entry = (struct Entry02083554*)FindEntryByShortField02083554((struct Container02083554*)field150, *(unsigned short*)(node + 2));
                                    if (entry != NULL) {
                                        func_02083738((void*)field150, entry->kind);
                                        idArr[arrCount] = buf40[i];
                                        arrCount++;
                                        matchCount++;
                                        if (matchCount == *(unsigned short*)(node + 4)) break;
                                    }
                                }
                            }
                        }
                        int flag10 = -1;
                        for (int j = 0; j < arrCount; j++) {
                            if (CheckField0NonZero((int*)func_0202ae18())) {
                                int cid = idArr[j];
                                func_ov017_021c3fb4(cid, 1);
                                func_ov017_021c4418(cid, flag10);
                            }
                            void* g2 = func_ov017_0218b5b0();
                            void* field700 = *(void**)((char*)g2 + 0x3000 + REGION_VALUE(0x4f0, 0x700));
                            void* field704 = *(void**)((char*)g2 + 0x3000 + REGION_VALUE(0x4f4, 0x704));
                            inst = BackgroundLoader::GetInstance();
                            func_ov017_0218f5a4(g2, idArr[j], 1, 0, 0);
                            while (GetHeadNodeIdOrMinusOne((struct HeadNode02046b24**)field700) == 0x13) {
                                inst->RemoveAllLocks();
                                ClearIfMatchAndFinalize_021a3498((struct Ctx021a3498*)field700);
                                if (GetHeadNodeIdOrMinusOne((struct HeadNode02046b24**)field704) == 0x14) {
                                    ClearIfMatchAndFinalize_021a3498((struct Ctx021a3498*)field704);
                                }
                            }
                        }
                    }
                }
                break;
            }

            case 0x9c: case 0x9d: {
                if (type == 0x9c) {
                    void* p2a04 = GetPtrField0x2a04((GameState*)battle);
                    if (p2a04 == NULL) break;
                    int found = 0;
                    if (DecrementKeyEverywhere02086d88((unsigned char*)p2a04, *(short*)(node + 4)) != 0) found = 1;
                    if (found == 0) {
                        unsigned char buf3c[4];
                        unsigned char count = CopyOutRegion0x5718((char*)battle, buf3c);
                        for (int i = 0; i < count; i++) {
                            int cid = buf3c[i];
                            struct CombatantStruct* c = _Z25GetCombatantWithFlag0x100P9GameStatei(battle, cid);
                            if (c != NULL) {
                                int field150 = GetFieldAt0x150((unsigned char*)c);
                                if (field150 != 0) {
                                    struct Entry02083554* entry = (struct Entry02083554*)FindEntryByShortField02083554((struct Container02083554*)field150, *(short*)(node + 4));
                                    if (entry != NULL) {
                                        func_02083738((void*)field150, entry->kind);
                                        if (CheckField0NonZero((int*)func_0202ae18())) {
                                            func_ov017_021c3fb4(cid, 1);
                                            func_ov017_021c4418(cid, -1);
                                        }
                                        void* g2 = func_ov017_0218b5b0();
                                        void* field700 = *(void**)((char*)g2 + 0x3000 + REGION_VALUE(0x4f0, 0x700));
                                        void* field704 = *(void**)((char*)g2 + 0x3000 + REGION_VALUE(0x4f4, 0x704));
                                        BackgroundLoader* inst = BackgroundLoader::GetInstance();
                                        func_ov017_0218f5a4(g2, cid, 1, 0, 0);
                                        while (GetHeadNodeIdOrMinusOne((struct HeadNode02046b24**)field700) == 0x13) {
                                            inst->RemoveAllLocks();
                                            ClearIfMatchAndFinalize_021a3498((struct Ctx021a3498*)field700);
                                            if (GetHeadNodeIdOrMinusOne((struct HeadNode02046b24**)field704) == 0x14) {
                                                ClearIfMatchAndFinalize_021a3498((struct Ctx021a3498*)field704);
                                            }
                                        }
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                if (GetPtrField0x2a04((GameState*)battle) != NULL) {
                    unsigned char eventBuf2[0x18];
#if defined(jpn)
                    SafeAllocator* r7base2 = ((AllocHolder0206f81c*)g)->GetAllocator(1);
#else
                    void* r7base2 = ((AllocHolder0206f81c*)g)->GetAllocator(1);
#endif
                    ZeroInitReturn020de824(eventBuf2);
                    ZeroInit020de848(eventBuf2);
#if defined(jpn)
                    func_020e04f8(eventBuf2, (void*)r7base2, data_020f2a38, *(short*)(node + 6), true);
#else
                    BackgroundLoader::AddLockGlobal();
                    unsigned int outSize2 = 0;
                    void* loaded2 = ExtractFileFromGP2(data_020f2a38, data_020f2a30, &outSize2);
                    if (loaded2 != NULL) {
                        BuildDescriptorFlag1_020de980(eventBuf2, r7base2, loaded2, outSize2, (int)(*(short*)(node + 6)));
                    }
                    BackgroundLoader::RemoveLockGlobal();
#endif
                    SelfBuf0206f81c selfBuf2;
                    selfBuf2.alloc.ResetAllocatorPointer();
                    ZeroInitReturn020de824(selfBuf2.sub14);
                    InitStruct0207cbe8((char*)&selfBuf2);
                    InitStruct0207cbe8((char*)&selfBuf2);
                    selfBuf2.eventPtr = eventBuf2;
                    func_0207d300(&selfBuf2, *(short*)(node + 6), 1, 0);
                }
                break;
            }

            case 0x8d: {
                val1c = *(unsigned short*)(node + 2);
                break;
            }

            case 0x91: {
                void* g2 = func_ov017_0218b5b0();
                unsigned short sub = *(unsigned short*)(node + 2);
                struct HeadList020469f8* subTail = *(struct HeadList020469f8**)((char*)g2 + 0x3000 + REGION_VALUE(0x4ec, 0x6fc));
                switch (sub) {
                case 2:
                    func_ov017_021b65e0(g2, 1);
                    break;
                case 6:
                    ((struct FlagsRoot0206f81c*)((char*)battle + REGION_VALUE(0xc, 0x26c)))->flags.low |= 0x20;
                case 5: {
                    unsigned char* r8node = *(unsigned char**)((char*)g2 + 0x3000 + REGION_VALUE(0x92c, 0xb4c));
                    InitObjState_021b2174(r8node);
                    SetNameChecked_021b2ba0((S021b2ba0*)r8node, data_020f0b40);
                    SetFields30And34_021b2bd0(r8node, (int)_Z24InitAndRegister_0215e25cPvS_, OVERLAY_ID(4));
                    PrependNodeToHead(subTail, (struct HeadNode020469f8*)r8node);
                    break;
                }
                case 7: {
                    unsigned char* r8node = *(unsigned char**)((char*)g2 + 0x3000 + REGION_VALUE(0x92c, 0xb4c));
                    InitObjState_021b2174(r8node);
                    SetBit4_021b2bf4((S021b2bf4*)r8node, 1);
                    SetBit5_021b2c0c((S021b2c0c*)r8node, 1);
                    SetNameChecked_021b2ba0((S021b2ba0*)r8node, data_020f0b4c);
                    SetFields30And34_021b2bd0(r8node, (int)func_ov004_02168684, OVERLAY_ID(4));
                    PrependNodeToHead(subTail, (struct HeadNode020469f8*)r8node);
                    break;
                }
                case 8: {
                    unsigned char* r8node = *(unsigned char**)((char*)g2 + 0x3000 + REGION_VALUE(0x92c, 0xb4c));
                    InitObjState_021b2174(r8node);
                    SetBit4_021b2bf4((S021b2bf4*)r8node, 1);
                    SetBit5_021b2c0c((S021b2c0c*)r8node, 1);
                    SetBit3_021b2bdc((S021b2bdc*)r8node, 0);
                    SetNameChecked_021b2ba0((S021b2ba0*)r8node, data_020f0b56);
                    SetFields30And34_021b2bd0(r8node, (int)_Z29AllocateAndCopyBuf20_021689d8P13SafeAllocatorPv, OVERLAY_ID(4));
                    PrependNodeToHead(subTail, (struct HeadNode020469f8*)r8node);
                    break;
                }
                }
                break;
            }
            }

            node = *(unsigned char**)(node + 0x18);
        }

        if (flag18 != 0 && slFlag != 0) {
            unsigned char* f3f8 = (unsigned char*)GetField0x3f8Address((GameState*)battle);
            f3f8[7] = 1;
            _ZN8Vector3iaSERKS_(f3f8 + 0x10, vec);
        }
        if (flag14 != 0 && slFlag != 0) {
            unsigned char* f3f8 = (unsigned char*)GetField0x3f8Address((GameState*)battle);
            f3f8[7] = 1;
            *(short*)(f3f8 + 0x1c) = val10;
        }
        BackgroundLoader* inst2 = BackgroundLoader::GetInstance();
        if (flag20 != 0 && inst2->GetNumQueuedTasks() <= 0) {
            void* r4b = func_0205ec34();
            void* misc2 = func_02012fe4();
            func_0206461c(r4b, *(int*)((char*)misc2 + 8));
        }
        if (val1c != 0) {
            unsigned char* r4c = *(unsigned char**)((char*)g + 0x3000 + REGION_VALUE(0x938, 0xb58));
            if (r4c[2] == 0) {
                InitByteHeader_021c16a8(r4c);
                AppendNodeToTail(tailList, (struct TailNode020469b4*)r4c);
            }
        }
    }
}
