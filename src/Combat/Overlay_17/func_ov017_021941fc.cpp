// JPN: func_ov017_02194dc4
#include <globaldefs.h>

#if defined(jpn)
enum {
    kRegionOffset173 = 0x16f,
    kRegionOffset6fc = 0x4ec,
    kRegionOffset734 = 0x524,
    kRegionOffset4400 = 0x4100,
    kRegionOffsetac = 0xfc,
    kRegionOffset2e3 = 0xc3,
    kRegionOffsetcf = 0xcb,
    kRegionOffset2e2 = 0xc2,
    kRegionOffset3c9 = 0x139,
    kRegionOffset2e1 = 0xc1,
    kRegionOffset41c = 0x16c,
    kRegionOffset2e5 = 0xc5,
    kRegionOffset2f0 = 0xd0,
    kRegionOffset31e = 0xfe,
    kRegionOffsetb00 = 0x8e0,
    kRegionOffsetb30 = 0x910,
    kRegionOffset15c = 0x150,
    kRegionOffset160 = 0x154,
    kRegionOffset16c = 0x160,
    kRegionOffsetb2c = 0x90c,
    kRegionOffset718 = 0x508,
    kRegionOffsetb5c = 0x93c,
    kRegionOffsetafc = 0x8dc,
    kRegionOffsetb0c = 0x8ec,
    kRegionOffsetb10 = 0x8f0,
    kRegionOffsetb24 = 0x904,
    kRegionOffsetb28 = 0x908,
    kRegionOffsetb88 = 0x968,
    kRegionOffsetbbc = 0x99c,
    kRegionOffset70c = 0x4fc,
    kRegionOffset55 = 0x35,
    kRegionOffset4300 = 0x4100,
    kRegionOffsetb2 = 0xa6,
    kRegionOffset355 = 0x135,
};
#else
enum {
    kRegionOffset173 = 0x173,
    kRegionOffset6fc = 0x6fc,
    kRegionOffset734 = 0x734,
    kRegionOffset4400 = 0x4400,
    kRegionOffsetac = 0xac,
    kRegionOffset2e3 = 0x2e3,
    kRegionOffsetcf = 0xcf,
    kRegionOffset2e2 = 0x2e2,
    kRegionOffset3c9 = 0x3c9,
    kRegionOffset2e1 = 0x2e1,
    kRegionOffset41c = 0x41c,
    kRegionOffset2e5 = 0x2e5,
    kRegionOffset2f0 = 0x2f0,
    kRegionOffset31e = 0x31e,
    kRegionOffsetb00 = 0xb00,
    kRegionOffsetb30 = 0xb30,
    kRegionOffset15c = 0x15c,
    kRegionOffset160 = 0x160,
    kRegionOffset16c = 0x16c,
    kRegionOffsetb2c = 0xb2c,
    kRegionOffset718 = 0x718,
    kRegionOffsetb5c = 0xb5c,
    kRegionOffsetafc = 0xafc,
    kRegionOffsetb0c = 0xb0c,
    kRegionOffsetb10 = 0xb10,
    kRegionOffsetb24 = 0xb24,
    kRegionOffsetb28 = 0xb28,
    kRegionOffsetb88 = 0xb88,
    kRegionOffsetbbc = 0xbbc,
    kRegionOffset70c = 0x70c,
    kRegionOffset55 = 0x55,
    kRegionOffset4300 = 0x4300,
    kRegionOffsetb2 = 0xb2,
    kRegionOffset355 = 0x355,
};
#endif
#include "Combat/NameEntryQueue.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

struct SearchStruct;
struct SearchStruct0202c1a4;
struct StateFlags3c9 {
    char pad[kRegionOffset3c9];
    unsigned char bit0 : 1;
    unsigned char rest : 7;
    unsigned char unk3ca;
    signed char value3cb;
};
struct FlagWord02046708;
struct FlagWord020466f4;
struct HeadList020469f8;
struct HeadNode020469f8;
struct HeadNode02046b24;
struct ListHead02046b60;
struct AxisFloats0203b5f8;
struct AxisFloats0203b57c;
struct BitField0203402c;
struct U16Field0x6_020375f8;
struct Obj_021bd3a4;
struct Obj02033834;
struct Obj02033874;
struct Obj02033b68;
struct Vec3s32_020c3030 {
    int x;
    int y;
    int z;
};

struct Src021cd6d8 {
    unsigned short f0;
    unsigned short f2;
    unsigned short f4;
    short f6;
    unsigned char f8;
    unsigned short fa;
    signed char fc;
    unsigned char pad;
    float f10;
};

/* The 16-byte record handed out by GetSubstructAt0x7c0 and by
   GetEntryBySignedByteIndex. */
struct Slot021941fc {
    unsigned short f0 : 8;
    unsigned short kind : 8;
    unsigned short active : 1;
    unsigned short members : 4;
    unsigned short unk5 : 6;
    unsigned short bit11 : 1;
    unsigned short bit12 : 1;
    unsigned short bit13 : 1;
    unsigned short bit14 : 1;
    unsigned short bit15 : 1;
    unsigned short f4 : 16;
    unsigned short f6 : 16;
    short x;
    short y;
    short z;
    short angle;
};

struct Bits0xc1 {
    unsigned char low : 2;
    unsigned char high : 6;
};

extern "C" struct SearchStruct* func_0202ae18(void);
extern "C" void* func_0205ec34(void);
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v(void);
int* GetGlobal02109030(void);
void* GetData02153634(void);
int IsField0Null(void** obj);
extern "C" void _Z27EnqueueEventTag142_021cd6d8P11Src021cd6d8(struct Src021cd6d8* src);
int IsAxisIntZero(struct AxisFloats0203b5f8* s, int axis);
extern "C" void func_ov017_0219577c(int a, int b, int c);
extern "C" void _Z30RegisterNodeAndNotify_0219593cv(void);
extern "C" void _Z33ResetAndSetFlag0x3c9Bit0_020939dcPv(void* obj);
int GetField0x3acValue(GameState* battleStruct);
extern "C" void _Z29SetCombatModeFromCase020dc2d0i(int mode);
void ResetEightRegionsAndFlags(char* obj);
extern "C" void func_02094030(int* a, int b, int c, signed char d);
int CheckFlag0x3c9Bit0OrByteNonPositive(struct StateFlags3c9* obj);
int CheckField0NonZero(int* obj);
extern "C" unsigned int _Z17TestFlags02046708P16FlagWord02046708j(struct FlagWord02046708* obj, unsigned int mask);
void ClearFlag0x3c9Bit0AndCleanup(unsigned char* obj);
unsigned int GetBitsInField0(unsigned int* obj, unsigned int mask);
extern "C" void func_ov017_021c37a4(void);
extern "C" int func_0202c508(struct SearchStruct* obj);
int TestFlagBitAt0xe(struct SearchStruct* obj, int value);
extern "C" int _Z25TestSearchFlagBit0202c758P12SearchStructi(struct SearchStruct* obj, int value);
extern "C" void _Z27EnqueueEventTag173_021d1810tth(int a, int b, signed char c);
extern "C" void _Z26EnqueueEventTag49_021cea34i(int a0);
extern "C" void _Z24SetSearchFlagBit0202c6dcP12SearchStructi(struct SearchStruct* obj, int value);
extern "C" int func_ov017_02195658(unsigned char* self);
extern "C" int func_0202c540(struct SearchStruct* obj);
extern "C" void _Z26SetFlagAndCleanup_02195618Ph(unsigned char* obj);
void UpdateGlobalAndCombatantFlagBytes(unsigned char* p);
extern "C" void _Z18ClearFlags020466f4P16FlagWord020466f4j(struct FlagWord020466f4* obj, unsigned int mask);
extern "C" int _Z34PopFrontAndCompactEntries_0219531cPvS_(void* obj, void* outEntry);
int CopyOutRegion0x5718(char* obj, void* dst);
int TestBitInByteArray(int unused, unsigned char* arr, int index);
extern "C" void func_ov017_02195250(void* d, void* buf);
int TestMaskBitBySignedByteIndex(struct SearchStruct* obj, int value);
void OrBitsIntoField0(unsigned int* obj, unsigned int mask);
extern "C" void _Z26EnqueueEventTag44_021cc198hi(unsigned char a, int b);
extern "C" void func_ov017_021d0b30(int a, int b, void* c);
extern "C" void _Z26ClearSearchFlagBit0202c69cP12SearchStructi(struct SearchStruct* obj, int value);
extern "C" void _Z26ClearSearchFlagBit0202c718P12SearchStructi(struct SearchStruct* obj, int value);
extern "C" void _Z24SetSearchFlagBit0202c660P12SearchStructi(struct SearchStruct* obj, int value);
int GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
GameObject* GetCombatantWithFlag0x200(GameState* battleStruct, int combatantId);
extern "C" void _Z27CallIndexedHandler_02195494Pvii(void* obj, int index, int val);
extern "C" int func_0202bd68(struct SearchStruct* self, int bitIndex);
extern "C" void _Z20SetField4b0_02167240Pv(void* obj);
int GetAxisIntValue(struct AxisFloats0203b57c* s, int axis);
extern "C" int abs(int x);
extern "C" void func_ov017_021af59c(void* obj);
void PrependNodeToHead(struct HeadList020469f8* list, struct HeadNode020469f8* node);
int TestBitBySignedByteIndex(struct SearchStruct* obj, int value);
extern "C" void func_ov017_021905b8(unsigned char* ov, int combatantId, int mode);
int ListContainsId(struct ListHead02046b60* list, int id);
void* GetSubstructAt0x7c0(void* base);
int GetField0x158(void* obj);
int CheckField0xc4Low15BitsNonZero(struct BitField0203402c* p);
extern "C" int _ZNK8Object3D10GetField06Ev(struct U16Field0x6_020375f8* obj);
extern "C" int _ZNK8Object3D9GetHeightEv(void* obj);
extern "C" int fix32_Divide(int a, int b);
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);
extern "C" unsigned short _Z32GetEntryField0x4OrFieldA0202bc8cP12SearchStruct(struct SearchStruct* obj);
extern "C" int _Z29HasFlag3orFlag2And9a_021bd3a4P12Obj_021bd3a4(struct Obj_021bd3a4* obj);
void* GetEntryBySignedByteIndex(struct SearchStruct* obj, int value);
int GetSignedByte0x1ca(void* obj);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" void _Z21SetVecYByMode02033834P11Obj02033834i(struct Obj02033834* obj, int value);
extern "C" void _Z24SetVecYFromValue02033874P11Obj02033874i(struct Obj02033874* obj, int value);
int CheckSubstructByte0x7cPositive(signed char* p);
extern "C" void func_020531f0(void* obj);
GameObject* FindCombatantByField0x16a(GameState* battleStruct, int id);
extern "C" void _Z18TrySetMode02076cccPvi(void* obj, int mode);
extern "C" void func_ov017_021917f0(int id, int flag);
extern "C" void _Z24SetByteIfChanged02033b68P11Obj02033b68i(struct Obj02033b68* obj, int value);
extern "C" void func_ov017_021bd4d0(void* obj, unsigned char id, int a, int b);
extern "C" void func_ov017_021d48f0(void);
void* GetData02108ea8(void);
extern "C" void func_0207dba8(void* p);

extern int data_ov017_021d63f0;
extern int data_ov017_021d63d8;
extern int data_ov017_021d63e4;
extern int data_ov017_021d63fc;
extern unsigned short data_02114e30;

// USA: func_ov017_021941fc
extern "C" ARM void func_ov017_021941fc(unsigned char* ov, unsigned char* mode, void** list) {
    struct Src021cd6d8 params;
    unsigned char entry[15];
    int posA[3];
    int posB[3];
    struct Vec3s32_020c3030 target;
    unsigned char region[4];

    /* PERMBLOCK */
    GameState* battle;
    struct SearchStruct* search;
    GameObject* actor;
    void* flags;
    int ctx;
    void* loader;
    void* owner;
    int* g;
    unsigned char* status;
    /* ENDPERM */
    battle = GameState::GetInstance();
    ctx = ((int)func_ov017_0218b5b0());
    search = func_0202ae18();
    actor = battle->GetUnknownGameObject();
    loader = (void*)(int)BackgroundLoader::GetInstance();
    list = *(void***)(ov + 0x3000 + kRegionOffset6fc);
    owner = func_0205ec34();
    flags = _Z27GetDataPtr02114e04_020d6c00v();
    g = GetGlobal02109030();
    mode = *(unsigned char**)(ov + 0x3000 + kRegionOffset734);
    status = (unsigned char*)GetData02153634();

    if (IsField0Null(list) != 0 && *(unsigned short*)(ov + kRegionOffset4400 + kRegionOffsetac) != 0) {
        params.f0 = 0;
        params.f2 = 0;
        params.f4 = 0;
        params.f6 = 0;
        params.f8 = 0;
        params.fa = 0;
        params.f10 = 0.0f;
        params.fc = -1;
        params.f2 = *(unsigned short*)(ov + kRegionOffset4400 + kRegionOffsetac);
        _Z27EnqueueEventTag142_021cd6d8P11Src021cd6d8(&params);
        *(unsigned short*)(ov + kRegionOffset4400 + kRegionOffsetac) = 0;
    }

    if (IsAxisIntZero((struct AxisFloats0203b5f8*)ov, 0) != 0) {
        int restart = 0;
        if (*(unsigned char*)(ov + 0x4000 + kRegionOffset2e3) != 0) {
            unsigned char* m = *(unsigned char**)((unsigned char*)ctx + 0x3000 + kRegionOffset734);
            if (m[3] != 0 && *(unsigned short*)(m + 8) == 0 && m[kRegionOffsetcf] == 2) {
                func_ov017_0219577c(0, 0, 0);
            } else {
                _Z30RegisterNodeAndNotify_0219593cv();
                _Z33ResetAndSetFlag0x3c9Bit0_020939dcPv(GetGlobal02109030());
            }
            restart = 1;
        } else if (IsField0Null(list) != 0 && *(unsigned char*)(ov + 0x4000 + kRegionOffset2e2) != 0) {
            if (GetField0x3acValue(battle) != 0) {
                func_ov017_0219577c(0, 1, 1);
            }
            restart = 1;
        }
        if (restart != 0) {
            _Z29SetCombatModeFromCase020dc2d0i(0);
            ResetEightRegionsAndFlags((char*)g);
            func_02094030(g, 4, -1, 0);
            *(unsigned char*)(ov + 0x4000 + kRegionOffset2e2) = 0;
            *(unsigned char*)(ov + 0x4000 + kRegionOffset2e3) = 0;
        }
    }

    if (((struct StateFlags3c9*)g)->bit0 &&
        CheckFlag0x3c9Bit0OrByteNonPositive((struct StateFlags3c9*)g) != 0 &&
        CheckField0NonZero((int*)search) == 0 &&
        _Z17TestFlags02046708P16FlagWord02046708j((struct FlagWord02046708*)flags, 0x1000) == 0) {
        ClearFlag0x3c9Bit0AndCleanup((unsigned char*)g);
    }

    if (GetBitsInField0((unsigned int*)ov, 2) != 0) return;
    if (CheckField0NonZero((int*)search) == 0) return;

    if (*(unsigned char*)(ov + 0x4000 + kRegionOffset2e1) != 0 &&
        ((BackgroundLoader*)loader)->GetNumQueuedTasks() == 0) {
        func_ov017_021c37a4();
        *(unsigned char*)(ov + 0x4000 + kRegionOffset2e1) = 0;
    }

    if (func_0202c508(search) != 0) {
        int noTarget = -1;
        for (int i = 1; i < 4; i++) {
            if (TestFlagBitAt0xe(search, i) == 0) continue;
            if (_Z25TestSearchFlagBit0202c758P12SearchStructi(search, i) != 0) continue;
            func_02094030(GetGlobal02109030(), 3, noTarget, i);
            _Z27EnqueueEventTag173_021d1810tth(3, noTarget, i);
            _Z26EnqueueEventTag49_021cea34i(i);
            _Z24SetSearchFlagBit0202c6dcP12SearchStructi(search, i);
        }
    }

    if (_Z17TestFlags02046708P16FlagWord02046708j((struct FlagWord02046708*)flags, 0x40000) == 0) {
        func_ov017_02195658(ov);
    }

    if (func_0202c540(search) != 0) {
        if (TestFlagBitAt0xe(search, 0) != 0) {
            _Z26SetFlagAndCleanup_02195618Ph(ov);
        }
    } else {
        for (int i = 1; i < 4; i++) {
            if (TestFlagBitAt0xe(search, i) == 0) continue;
            if (_Z25TestSearchFlagBit0202c758P12SearchStructi(search, i) != 0) continue;
            _Z26EnqueueEventTag49_021cea34i(i);
            _Z24SetSearchFlagBit0202c6dcP12SearchStructi(search, i);
        }
    }

    UpdateGlobalAndCombatantFlagBytes(status);

    if ((*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[0] == 0) {
        if (func_0202c508(search) != 0) {
            if (status[1] != 0) goto dispatched;
            _Z18ClearFlags020466f4P16FlagWord020466f4j((struct FlagWord020466f4*)flags, 0x800);
            if (_Z34PopFrontAndCompactEntries_0219531cPvS_(ov, entry) == 0) goto dispatched;
            int accept = 1;
            int used = CopyOutRegion0x5718((char*)battle, region);
            if (used + entry[1] > 4) accept = 0;
            unsigned char* bits = (unsigned char*)owner;
            bits += 0x8c;
            if (TestBitInByteArray((int)owner, bits, 3) != 0) {
                func_ov017_02195250(ov, entry);
                accept = 0;
            }
            if (TestMaskBitBySignedByteIndex(search, entry[0]) == 0) accept = 0;
            if (entry[0xe] != 0) accept = 0;
            if (accept != 0) {
                OrBitsIntoField0((unsigned int*)flags, 0x800);
                _Z26EnqueueEventTag44_021cc198hi(entry[0], 1);
                func_ov017_021d0b30(0, entry[0], entry + 2);
                _Z26ClearSearchFlagBit0202c69cP12SearchStructi(search, entry[0]);
                _Z26ClearSearchFlagBit0202c718P12SearchStructi(search, entry[0]);
                (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[0] = 1;
                (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[1] = 0;
                func_ov017_02195214((Entry15_02195214 *) (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c) + 2),
                    (Entry15_02195214 *) entry);
                *(unsigned char*)(ov + 0x4000 + kRegionOffset2e5) = 1;
            } else {
                _Z26EnqueueEventTag44_021cc198hi(entry[0], 0);
                _Z24SetSearchFlagBit0202c660P12SearchStructi(search, entry[0]);
                if (*(unsigned char*)(ov + 0x4000 + kRegionOffset2f0) == 0) {
                    _Z18ClearFlags020466f4P16FlagWord020466f4j((struct FlagWord020466f4*)flags, 0x800);
                }
            }
        } else if (*(unsigned char*)(ov + 0x4000 + kRegionOffset31e) != 0 &&
                   GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)search) > 0) {
            int slot = 0;
            for (int i = 1; i < 4; i++) {
                if ((*(unsigned char*)(ov + 0x4000 + kRegionOffset31e) & (1 << i)) != 0) {
                    *(unsigned char*)(ov + 0x4000 + kRegionOffset31e) =
                        *(volatile unsigned char*)(ov + 0x4000 + kRegionOffset31e) & ~(1 << i);
                    slot = i;
                    break;
                }
            }
            int side;
            if (GetCombatantWithFlag0x200(battle,
                    GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)search)) != NULL) {
                side = 1;
            } else {
                side = 2;
            }
            (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[0] = 1;
            (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[1] = (unsigned char)side;
            _Z27CallIndexedHandler_02195494Pvii(ov, slot,
                (int)(*(unsigned char**)(ov + 0x4000 + kRegionOffset41c) + 2));
            (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[2] = (unsigned char)slot;
            (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[3] = 1;
            if (side == 1) *(unsigned char*)(ov + 0x4000 + kRegionOffset2e5) = 1;
        }
    } else if ((*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[0] == 1) {
        if (func_0202bd68(search, (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[2]) != 0) {
            if ((*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[1] == 2) {
                void* holder = *(void**)(*(unsigned char**)(ov + 0x3000 + kRegionOffsetb00) + 0x24);
                if (holder != NULL) _Z20SetField4b0_02167240Pv(holder);
                (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[0] = 2;
            } else {
                if (func_0202c508(search) != 0 && *(int*)((char*)search + 0xfc0) == 0) {
                    if (TestMaskBitBySignedByteIndex(search,
                            (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[2]) == 0) {
                        unsigned char* st = *(unsigned char**)(ov + 0x4000 + kRegionOffset41c);
                        st[0] = 0;
                        st[1] = 0;
                    }
                }
                int ok = 1;
                if (IsField0Null(list) == 0) ok = 0;
                if (mode[3] != 0 && mode[kRegionOffsetcf] == 2) ok = 1;
                int dx = abs(GetAxisIntValue((struct AxisFloats0203b57c*)ov, 0));
                if (dx + abs(GetAxisIntValue((struct AxisFloats0203b57c*)ov, 1)) > 0) ok = 0;
                if (*(short*)((char*)actor + 0xac) != 0) ok = 0;
                if (_Z17TestFlags02046708P16FlagWord02046708j((struct FlagWord02046708*)flags, 0x200) != 0) ok = 1;
                if (_Z17TestFlags02046708P16FlagWord02046708j((struct FlagWord02046708*)flags, 0x400) != 0) ok = 0;
                if (((BackgroundLoader*)loader)->GetNumQueuedTasks() > 0) ok = 0;
                if (ok != 0) {
                    unsigned char* node = *(unsigned char**)(ov + 0x3000 + kRegionOffsetb30);
                    func_ov017_021af59c(node);
                    node[9] = (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[1];
                    func_ov017_02195214((Entry15_02195214 *) (node + 0xc),
                        (Entry15_02195214 *) (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c) + 2));
                    PrependNodeToHead((struct HeadList020469f8*)list,
                        (struct HeadNode020469f8*)node);
                    (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[0] = 2;
                } else if (*(unsigned char*)(ov + 0x4000 + kRegionOffset2e5) != 0) {
                    func_02094030(g, 5, -1, 0);
                    *(unsigned char*)(ov + 0x4000 + kRegionOffset2e5) = 0;
                }
            }
        } else if (TestBitBySignedByteIndex(search,
                       (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[2]) != 0) {
            if (_Z17TestFlags02046708P16FlagWord02046708j((struct FlagWord02046708*)flags, 0x40000) == 0) {
                func_ov017_021905b8(ov,
                    (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[2], 0);
            }
        } else if ((*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[1] != 2) {
            (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[0] = 2;
        }
    } else if ((*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[0] == 2) {
        if (ListContainsId((struct ListHead02046b60*)list, 0x26) != 0) goto dispatched;
        if (*(unsigned char*)(ov + 0x4000 + kRegionOffset2f0) == 0) {
            _Z18ClearFlags020466f4P16FlagWord020466f4j((struct FlagWord020466f4*)flags, 0x800);
        }
        (*(unsigned char**)(ov + 0x4000 + kRegionOffset41c))[0] = 0;
    }

dispatched:
    if (GetBitsInField0((unsigned int*)ov, 2) != 0) return;
    if (CheckField0NonZero((int*)search) == 0) return;

    struct Slot021941fc* slot = (struct Slot021941fc*)GetSubstructAt0x7c0(search);

    if (GetBitsInField0((unsigned int*)ov, 0x40) == 0) {
        int kind = 0;
        unsigned char placed = 0;
        if (_ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)actor) == 10000 ||
            *(int*)((char*)actor + kRegionOffset15c) == 10000) {
            _ZN8Vector3iaSERKS_(posA, &data_ov017_021d63f0);
            _ZN8Vector3iaSERKS_(posB, &data_ov017_021d63d8);
            kind = 0;
        } else if (_ZNK8Object3D10GetField06Ev((struct U16Field0x6_020375f8*)actor) == 10100 ||
                   *(int*)((char*)actor + kRegionOffset15c) == 10100) {
            _ZN8Vector3iaSERKS_(posA, &data_ov017_021d63e4);
            _ZN8Vector3iaSERKS_(posB, &data_ov017_021d63fc);
            kind = 0;
        } else if (GetField0x158(actor) == 0) {
            _ZN8Vector3iaSERKS_(posA, (int*)((char*)actor + 0x44));
            _ZN8Vector3iaSERKS_(posB, (int*)((char*)actor + 0x50));
            if (CheckField0xc4Low15BitsNonZero((struct BitField0203402c*)actor) != 0) {
                posA[1] = posA[1] - fix32_Divide(_ZNK8Object3D9GetHeightEv(actor), 0x1800);
            }
            kind = *(unsigned char*)((char*)actor + 0xbe);
            if (GetHeadNodeIdOrMinusOne((struct HeadNode02046b24**)list) == 0x26) kind = 0;
            placed = 1;
        } else {
            _ZN8Vector3iaSERKS_(posA, (int*)((char*)actor + kRegionOffset160));
            _ZN8Vector3iaSERKS_(posB, (int*)((char*)actor + kRegionOffset16c));
            if (GetField0x158(actor) == 1) {
                kind = 2;
            } else {
                kind = placed;
            }
        }

        slot->x = (short)(posA[0] >> 7);
        slot->y = (short)(posA[1] >> 7);
        slot->z = (short)(posA[2] >> 7);
        slot->angle = (short)posB[1];
        slot->kind = (unsigned short)kind;
        slot->f4 = _Z32GetEntryField0x4OrFieldA0202bc8cP12SearchStruct(search);
        slot->f6 = data_02114e30;
        slot->bit12 = 1;
        slot->bit15 = placed;
        slot->members = 0;
        for (int i = 0; i < 4; i++) {
            if (battle->GetGameObjectByIndex(i) != NULL) {
                slot->members |= (1 << i);
            }
        }
        if (_Z29HasFlag3orFlag2And9a_021bd3a4P12Obj_021bd3a4(
                *(struct Obj_021bd3a4**)(ov + 0x3000 + kRegionOffset734)) != 0) {
            unsigned char* base = *(unsigned char**)(ov + 0x3000 + kRegionOffset734);
            base++;
            slot->members &= ~base[kRegionOffset173];
        }
    } else {
        slot->kind = 0;
    }

    unsigned char* actorNode = *(unsigned char**)(ov + 0x3000 + kRegionOffsetb30);
    unsigned char* partyNode = *(unsigned char**)(ov + 0x3000 + kRegionOffsetb2c);
    unsigned char* menuNode = *(unsigned char**)(ov + 0x3000 + kRegionOffset718);
    unsigned char* extraNode = *(unsigned char**)(ov + 0x3000 + kRegionOffsetb5c);
    slot->active = 0;
    slot->active |= actorNode[3];
    slot->active |= partyNode[3];
    slot->bit11 = 0;
    slot->bit11 |= menuNode[3];
    slot->bit11 |= extraNode[3];
    slot->bit13 = 1;
    if (IsField0Null(list) == 0) {
        slot->bit13 = 0;
        slot->bit13 |= (*(unsigned char**)(ov + 0x3000 + kRegionOffsetafc))[3];
        slot->bit13 |= (*(unsigned char**)(ov + 0x3000 + kRegionOffsetb0c))[3];
        slot->bit13 |= (*(unsigned char**)(ov + 0x3000 + kRegionOffsetb10))[3];
        slot->bit13 |= (*(unsigned char**)(ov + 0x3000 + kRegionOffsetb24))[3];
        slot->bit13 |= (*(unsigned char**)(ov + 0x3000 + kRegionOffsetb28))[3];
        slot->bit13 |= (*(unsigned char**)(ov + 0x3000 + kRegionOffsetb88))[3];
        slot->bit13 |= (*(unsigned char**)(ov + 0x3000 + kRegionOffsetbbc))[3];
    }
    slot->bit14 = (*(unsigned char**)(ov + 0x3000 + kRegionOffset70c))[3];
    if (mode[kRegionOffsetcf] == 2) {
        slot->active |= mode[3];
    }

    if (GetBitsInField0((unsigned int*)ov, 0x40) == 0) {
    unsigned char* pending = ov + kRegionOffset4300 + kRegionOffset55;
    for (int i = 0; i < 4; i++) {
        if (i == 0 && GetBitsInField0((unsigned int*)ov, 0x200) != 0) continue;
        if (TestBitBySignedByteIndex(search, i) == 0) continue;
        if (i == GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)search)) continue;
        struct Slot021941fc* other = (struct Slot021941fc*)GetEntryBySignedByteIndex(search, i);
        if (other == NULL) continue;
        GameObject* c = battle->GetPartyMemberByIndex(i);
        if (c == NULL) continue;
        c = battle->GetPartyMemberByIndex(GetSignedByte0x1ca(c));
        if (c == NULL) continue;

        if ((((struct Bits0xc1*)((char*)c + 0xc1))->low & 1) == 0 && other->bit12) {
            target.x = other->x << 7;
            target.y = other->y << 7;
            target.z = other->z << 7;
            int angle = other->angle;
            _ZN8Vector3iaSERKS_((int*)((char*)c + 0xd4), (int*)&target);
            *(unsigned char*)((char*)c + 0xe0) |= 0x10;
            _Z21SetVecYByMode02033834P11Obj02033834i((struct Obj02033834*)c, angle);
            struct Vec3s32_020c3030 current = *(struct Vec3s32_020c3030*)((char*)c + 0x44);
            if (Vector3fix_Distance((const Vector3fix*)&target, (const Vector3fix*)&current) > 0x1000) {
                _ZN8Vector3iaSERKS_((int*)((char*)c + 0x44), (int*)&target);
                _Z24SetVecYFromValue02033874P11Obj02033874i((struct Obj02033874*)c, angle);
            }
        }

        if (other->kind == 2) {
            if (CheckSubstructByte0x7cPositive((signed char*)c) != 0) {
                func_020531f0(c);
            }
            GameObject* owner2 = FindCombatantByField0x16a(battle,
                *(unsigned short*)((char*)c + 0x100 + kRegionOffsetb2));
            if (owner2 != NULL && *(int*)((char*)owner2 + 0x130) != 9) {
                if ((**(int**)((char*)c + 0x130) & 1) == 0) {
                    _Z18TrySetMode02076cccPvi(owner2, 9);
                }
            }
        }

        if ((((struct Bits0xc1*)((char*)c + 0xc1))->low & 2) == 0) {
            int face = *(unsigned char*)((char*)c + 0xbe);
            if (face == 2 && other->kind != 2) {
                func_ov017_021917f0(i, 0);
            } else if (other->kind == 2 && face != 2) {
                func_ov017_021917f0(i, 1);
            }
            _Z24SetByteIfChanged02033b68P11Obj02033b68i((struct Obj02033b68*)c, other->kind);
        }

        if ((*(unsigned char*)(ov + 0x4000 + kRegionOffset355) & (1 << i)) == 0) continue;
        if (other->bit15 != 1) continue;
        func_ov017_021bd4d0(*(void**)(ov + 0x3000 + kRegionOffset734), i, 1, 1);
        *pending = *pending & ~(1 << i);
    }
    }

    func_ov017_021d48f0();
    func_0207dba8(GetData02108ea8());
}
