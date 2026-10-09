#include <globaldefs.h>
extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "Combat/Main/BattleList.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/GPC.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/FileAccessor.h"
#include "Filesystem/LowNitroHandle.h"
#include "Filesystem/NitroVM.h"
#include "std_library_functions.h"
struct BattleStruct {
    int unk0;
    int unk4;
    struct CombatantStruct* combatantList[0xe9];
};
extern "C" struct BattleStruct* _ZN9GameState11GetInstanceEv();

struct Struct_020652b4 { int field0; };
extern "C" int _Z20IsListEmpty_020652b4P15Struct_020652b4(struct Struct_020652b4* p);
int IsField0Zero(int* p);

struct Pool020401fc {
    unsigned int count;
    unsigned char field4;
    unsigned char field5;
    unsigned char pad6[2];
    void* elements;
};
extern "C" void _Z16InitPool020401fcP12Pool020401fcjP13SafeAllocator(struct Pool020401fc* pool, unsigned int count, SafeAllocator* alloc);

extern "C" int _Z21GetFieldAt0x0020652c8Pi(int* obj);

extern "C" void* func_02012fe4(void);
extern "C" unsigned int* _Z27GetDataPtr02114e04_020d6c00v(void);

extern "C" int _Z19IsIdInRange020981e4ii(int a, int id);
extern "C" int _Z17IsIdInSet02098210ii(int a, int id);

extern "C" void _Z12Init020404c0Pi(int* obj);

struct NodeInfo0203d028 {
    char pad0[0xa];
    unsigned char lowA : 7;
    unsigned char flag7 : 1;
    unsigned char pad0b;
    int fieldC;
    int field10;
    int field14;
    int field18;
    short field1c;
    unsigned char field1e;
    unsigned char field1f;
    char pad20[0x38 - 0x20];
    int field38;
    int field3c;
    char pad40[0x54 - 0x40];
    int field54;
    int field58;
};
struct NodeInfo0203d028* FindNodeByByteId(void* base, int key);

void SetField0x8(int* obj, int value);
void SetField0xc(int* obj, int value);

struct State02041244 {
    char pad_00[0xac];
    unsigned short field_ac;
    char pad_ae[2];
    int field_b0;
    char pad_b4[0xc];
    int field_c0;
    unsigned char field_c4;
    char pad_c5[3];
    int field_c8;
    int field_cc;
    int field_d0;
    unsigned char flags_d4;
};
extern "C" void _Z18ResetState02041244P13State02041244(struct State02041244* obj);

struct Struct_203dafc {
    int field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    int field14;
    int field18;
    int field1c;
};
void ClearEightWords(struct Struct_203dafc* obj);

extern "C" void _Z25RestorePairTables0207df90Pc(char* obj);
extern "C" void _Z24BackupPairTables0207dfacPc(char* obj);
extern "C" void _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(void* obj, void* params, int flag);

struct Entry0209854c;
extern "C" struct Entry0209854c* _Z25FindEntryByFieldC0209854cP13Entry0209854ci(struct Entry0209854c* list, int target);

extern "C" void* _Z24GetGlobalContext020daf90v(void);
int GetField0x50(void* obj);
extern "C" void _Z33DispatchWithGlobalContext020daf9ciiii(int a, int b, int c, int d);

extern "C" void _Z17SetMainBrightnessP13GameResourcesii(void* mgr, int a, int b);
void OrBitsIntoField0(unsigned int* p, unsigned int mask);
int IsPowcntBit0Set(void);
int DispatchIfEquals1(int a);
void SleepCurrentContext(unsigned int ms);

extern "C" void func_ov017_0218f064(void* mgr, int a, int b, int c, int d);

struct CombatantStruct;
extern "C" struct CombatantStruct* _ZN9GameState20GetGameObjectByIndexEi(struct BattleStruct* battleStruct, int combatantId);

struct U16Field0x6_020375f0 { char unk[6]; unsigned short field; };
extern "C" void _ZN8Object3D10SetField06Et(struct U16Field0x6_020375f0* obj, int v);

extern "C" int* func_ov017_021a4658(void* mgr, int a);

struct Ctx021a3498;
extern "C" void _Z32ClearIfMatchAndFinalize_021a3498P11Ctx021a3498(struct Ctx021a3498* ctx);

struct HeadNode02046b24 { signed char id; };
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);

extern "C" void _Z30InitializeRandomMotion0203c794Pv(void* obj);
void StoreValueViaField0x14(unsigned char* obj, int val);

struct Obj0203f02c;
extern "C" void _Z27UpdateElementStream0203f02cP11Obj0203f02ciiPcii(struct Obj0203f02c* obj, int param1, int param2, char* param3, int param5, int param6);

extern "C" void func_0203f138(void* obj, int b);

extern "C" void func_0203e8f8(void* a, void* b, void* c);

struct Foo0207df50;
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(struct Foo0207df50* p);

extern "C" void _Z18ClearCombatantSlotP9GameStatei(struct BattleStruct* battleStruct, int id);

struct FlagWord020466f4 { unsigned int flags; };
extern "C" void _Z18ClearFlags020466f4P16FlagWord020466f4j(struct FlagWord020466f4* word, unsigned int mask);

struct FieldsA02040774 { char pad4[4]; int a; int b; int c; };
struct Node02040774 {
    char pad[0x14];
    struct FieldsA02040774* f14;
    void* f18;
    void* f1c;
};
extern "C" void _Z28SetActiveChildFields02040774P12Node02040774iii(struct Node02040774* obj, int a, int b, int c);

struct State0xcda8;
struct Obj0204085c {
    char pad[0x14];
    struct State0xcda8* field14;
    unsigned char* field18;
    unsigned char* field1c;
};
extern "C" void _Z22HandleObjEvent0204085cP11Obj0204085ciii(struct Obj0204085c* obj, int a, int b, int c);

struct Struct_203cec4;
struct S02037418;
struct ChildFlags_02040540 { char pad[0xc]; unsigned int val; };
struct Obj02040540 {
    unsigned int flags;
    unsigned int unk4;
    unsigned int unk8;
    struct ChildFlags_02040540* child;
    unsigned int unk10;
    struct Struct_203cec4* b;
    struct S02037418* c;
};
extern "C" void _Z26ApplyFlagsToTarget02040540P11Obj02040540(struct Obj02040540* obj);

extern "C" int _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo(int a, int b);
extern "C" void _ZN8Object3D10InitializeEv(void* obj);

struct Shorts5c_374e0 { char unk0[0x5c]; short a; short b; short c; };
extern "C" void _ZN8Object3D8SetScaleEiii(struct Shorts5c_374e0* obj, short a, short b, short c);
extern "C" void _ZN8Object3D9SetFlag16Ev(unsigned char* obj);

extern "C" void _ZN8Object3D14ShallowCloneToEPS_(void* a, void* b);

struct FieldsA020408c8 { char pad1c[0x1c]; int a; int b; int c; };
struct Node020408c8 {
    char pad[0x14];
    struct FieldsA020408c8* f14;
    void* f18;
    void* f1c;
};
extern "C" void _Z28SetActiveChildShorts020408c8P12Node020408c8sss(struct Node020408c8* obj, short a, short b, short c);

struct Obj02041598 {
    char pad_00[0xc4];
    char field_c4;
    char pad_c5[0xb];
    int field_d0;
};
extern "C" int _Z28SetByteC4AndDispatch02041598P11Obj02041598i(struct Obj02041598* obj, int value, int z);

extern "C" void _ZN8Object3D10EnableFlagEi(unsigned char* obj, unsigned int mask);
void StoreVec3AtField0x50(unsigned char* obj, int a, int b, int c);

struct Obj020415b0 {
    char pad_00[0xcc];
    int field_cc;
    int field_d0;
};
extern "C" int _Z28SetWordCCAndDispatch020415b0P11Obj020415b0i(struct Obj020415b0* obj, int value, int z);

extern "C" void func_0203db44(void* a, void* b, void* c);

extern "C" void _Z31SetByte0x2e8AndDispatch02041628Pvi(void* obj, int v, int z);
extern "C" void _Z31SetWord0x2f4AndDispatch02041640Pvi(void* obj, int v, int z);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

extern "C" int func_02018fbc(void* globalStruct, int* vec3);

struct TargetA02040bfc { char unk[0x8c]; int value; };
struct TargetB02040bfc { char unk[0xc8]; int value; };
struct TargetC02040bfc { char unk[0x2ec]; int value; };
struct Obj02040bfc {
    char unk[0x14];
    struct TargetA02040bfc* a;
    struct TargetB02040bfc* b;
    struct TargetC02040bfc* c;
};
extern "C" void _Z27StoreToFirstNonNull02040bfcP11Obj02040bfci(struct Obj02040bfc* obj, int value);

struct RegNode0203d028 {
    unsigned short id;
    unsigned char type;
    unsigned char field3;
    char name[12];
    struct RegNode0203d028* next;
};

struct Node0203d028 {
    unsigned int flags;
    int randSeed;
    struct RegNode0203d028* entry;
    struct NodeInfo0203d028* info;
    void* field0x10;
    void* stateB;
    struct State02041244* state;
    struct CombatantStruct* combatant;
};

struct SelfObj0203d028 {
    struct Pool020401fc pool;
    struct Node0203d028* entries[0x20];
    int loopCount;
    int listHead;
    void* nodeTableBase;
    char pad0x98[4];
    unsigned char field0x9c;
};

extern char data_020efdc4;
extern char data_020efdda;
extern char data_020efde9;
extern char data_020efdf0;
extern char data_020efe08;
extern char data_020efe0e;
extern char data_020efe20;
extern char data_020efe27;
extern char data_020efe30;
extern char data_020efe38;

static inline char* GetSub1840(void* run) {
    return (char*)((int)run + 0x1840);
}

struct BitFlag0203d028 { unsigned int b0 : 1; };

static inline void Set2e0203d028(void* m, short v) { *(short*)((char*)m + 0x2e) = v; }
static inline void Set95_0203d028(void* m, unsigned char v) { *((unsigned char*)m + 0x95) = v; }

static inline SafeAllocator& GetResourceAllocator(GameResources* resources, int index) {
    return resources->allocator_array_1a0[index];
}

static inline char& GetResourceBuffer(GameResources* resources, int offset) {
    return resources->unknown_2cc[offset];
}

static inline void SetX90_0203d028(void* motion, int v)
{
    if (motion != 0) {
        *(int*)((char*)motion + 0x90) = v;
    }
}


// USA: func_0203d028
extern "C" ARM void func_0203d028(struct SelfObj0203d028* self, void* unused1, SafeAllocator* sb, char* fp)
{
    if (_Z20IsListEmpty_020652b4P15Struct_020652b4((struct Struct_020652b4*)&self->listHead) ||
        IsField0Zero((int*)&self->nodeTableBase))
    {
        _Z16InitPool020401fcP12Pool020401fcjP13SafeAllocator(&self->pool, 0xc, sb);
        return;
    }

    struct BattleStruct* battleStruct = _ZN9GameState11GetInstanceEv();
    GameResources* mgr = func_ov017_0218b5b0();
    struct RegNode0203d028* entry = (struct RegNode0203d028*)_Z21GetFieldAt0x0020652c8Pi(&self->listHead);
    void* globalStruct = func_02012fe4();
    unsigned int* dataFlags = _Z27GetDataPtr02114e04_020d6c00v();
    unsigned int idVal = *(unsigned short*)globalStruct;
    void* childModelPtr = 0;
    unsigned int loopIndex = 0;
    int assignedFlag = 0;
    _Z16InitPool020401fcP12Pool020401fcjP13SafeAllocator(&self->pool, 0xc, sb);

    if (_Z19IsIdInRange020981e4ii((int)((char*)globalStruct + 0x840), idVal) &&
        _Z17IsIdInSet02098210ii((int)((char*)globalStruct + 0x840), idVal) == 0) {
        self->pool.field5 = 1;
    } else {
        self->pool.field5 = 0;
    }
    self->loopCount = 0;
    self->field0x9c = 0;
    BackgroundLoader::AddLockGlobal();

    while (entry != 0) {
        struct Node0203d028* node = (struct Node0203d028*)sb->Allocate(0x20);
        if (node == 0) goto abort_unlock;
        _Z12Init020404c0Pi((int*)node);
        struct NodeInfo0203d028* info = FindNodeByByteId(&self->nodeTableBase, entry->id);
        SetField0x8((int*)node, (int)entry);
        SetField0xc((int*)node, (int)info);

        {
            char* p = (char*)((int)battleStruct + 0x278);
            p = (char*)((int)p + 0x7c00);
            unsigned char b = *(unsigned char*)(p + 6);
            if (b != 0xff && info != 0 && info->field1f != 0) {
                node->flags |= 0x40000;
            }
        }

        int handledFlag = 0;
        unsigned int outLen;
        unsigned int length2;
        unsigned int gpcLen;
        unsigned int fileSize;
        const void* filePtr;
        unsigned int decompSize;
        unsigned int outLen64;
        unsigned int mdlOutLen;
        void* childModelPtr2;
        void* mdlPtr;
        void* decompressed;

        if (entry->type == 2) {
            node->state = (struct State02041244*)sb->Allocate(0xd8);
            if (node->state == 0) goto abort_unlock;
            _Z18ResetState02041244P13State02041244(node->state);
            char pathBuf[40];
            sprintf(pathBuf, &data_020efdc4, entry->name);
            void* loadedPtr = LoadFileIntoNewAllocation(pathBuf, *sb, &outLen);
            if (loadedPtr == 0) goto abort_unlock;
            struct Struct_203dafc params;
            ClearEightWords(&params);
            _Z25RestorePairTables0207df90Pc(fp);
            params.fieldc = (int)sb;
            params.field4 = (int)loadedPtr;
            params.field8 = (int)outLen;
            _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(node->state, &params, 0);
            _Z24BackupPairTables0207dfacPc(fp);
        }
        else if (entry->type == 4) {
            unsigned char* table = *(unsigned char**)(GetSub1840(globalStruct) + 0xb5c);
            int slot = 5;
            struct Entry0209854c* found = _Z25FindEntryByFieldC0209854cP13Entry0209854ci((struct Entry0209854c*)((char*)globalStruct + 0x840), entry->id);
            if (found != 0) {
                {
                    if (GetField0x50(_Z24GetGlobalContext020daf90v()) == 0) {
                        _Z33DispatchWithGlobalContext020daf9ciiii(1, 0, 1, 0);
                        _Z17SetMainBrightnessP13GameResourcesii(mgr, ~0xf, 0);
                    }
                    OrBitsIntoField0(dataFlags, 0x400000);
                    if (!IsPowcntBit0Set()) {
                        while (DispatchIfEquals1(1) == 0) {
                        }
                        SleepCurrentContext(1);
                    }
                    *(short*)(table + 0x568) = slot;
                    ((unsigned char*)table)[0x56a] = ((unsigned char*)found)[0x4f];
                    memcpy(table + 0x488, (unsigned char*)found + 0x1a, 0x1c);

                    func_ov017_0218f064(mgr, 5, 0x4000, 1, 0);

                    node->combatant = _ZN9GameState20GetGameObjectByIndexEi(battleStruct, 5);
                    _ZN8Object3D10SetField06Et((struct U16Field0x6_020375f0*)node->combatant, idVal);

                    int* extra = func_ov017_021a4658(mgr, 5);
                    extra[3] = 1;

                    char* base = (char*)mgr + 0x3000;
                    void* ctxA = *(void**)(base + 0x700);
                    void* ctxB = *(void**)(base + 0x704);
                    BackgroundLoader* instance = BackgroundLoader::GetInstance();

                    while (GetHeadNodeIdOrMinusOne((struct HeadNode02046b24**)ctxA) == 0x13) {
                        instance->RemoveAllLocks();
                        _Z32ClearIfMatchAndFinalize_021a3498P11Ctx021a3498((struct Ctx021a3498*)ctxA);
                        if (GetHeadNodeIdOrMinusOne((struct HeadNode02046b24**)ctxB) == 0x14) {
                            _Z32ClearIfMatchAndFinalize_021a3498P11Ctx021a3498((struct Ctx021a3498*)ctxB);
                        }
                    }

                    node->stateB = sb->Allocate(0x9c);
                    if (node->stateB == 0) goto abort_unlock;
                    _Z30InitializeRandomMotion0203c794Pv(node->stateB);
                    StoreValueViaField0x14((unsigned char*)node, (int)self);

                    const char* motName = &data_020efdda;
                    if (node->stateB != 0) {
                        _Z27UpdateElementStream0203f02cP11Obj0203f02ciiPcii(*(struct Obj0203f02c**)((char*)node + 0x14), (int)motName, (int)sb, fp, 0, 0);
                    }
                    if (node->stateB != 0) {
                        func_0203f138(node->stateB, 1);
                    }
                    Set2e0203d028(node->stateB, 0x3d);
                    Set95_0203d028(node->stateB, 1);
                    StoreValueViaField0x14((unsigned char*)node, (int)self);

                    SafeAllocator* savedAlloc = &GetResourceAllocator(mgr, 8);
                    savedAlloc->Reset();
                    func_0203e8f8(self, node, savedAlloc);

                    node->combatant = 0;
                    SafeAllocator* alloc3 = &GetResourceAllocator(mgr, 3);
                    char* buf930 = &GetResourceBuffer(mgr, 0x930);
                    entry->type = 0;
                    alloc3->Reset();
                    _Z26CopyInternalFields0207df50P11Foo0207df50((struct Foo0207df50*)buf930);
                    _Z18ClearCombatantSlotP9GameStatei(battleStruct, 5);
                    _Z18ClearFlags020466f4P16FlagWord020466f4j((struct FlagWord020466f4*)dataFlags, 0x400000);
                }
            }
        }
        else if (entry->type == 5) {
            node->state = (struct State02041244*)sb->Allocate(0xd8);
            if (node->state == 0) goto abort_unlock;
            _Z18ResetState02041244P13State02041244(node->state);
            BackgroundLoader::FreeAllocationsGlobal();

            GPCReadPair pair;
            ZeroInitGPCPointer(&pair.pGPCFile);
            pair.ZeroInitializeMachine();

            char innerName[16];
            sprintf(innerName, &data_020efde9, entry->name);

            if (!LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine,
                    &data_020efdf0, data_0211e33c, length2, 0x30000, false, NULL))
            {
                pair.Reset();
                ZeroDestroyGPCPointer(&pair.pGPCFile);
                goto abort_unlock;
            }

            unsigned char* dst = data_0211e33c + length2;
            if (!DecompressFileFromGPCByName(pair.pGPCFile, pair.machine,
                    dst, gpcLen, 0x30000 - length2, innerName))
            {
                pair.Reset();
                pair.Reset();
                ZeroDestroyGPCPointer(&pair.pGPCFile);
                goto abort_unlock;
            }

            if (!FindFilesInNarcBySubstring(dst, &data_020efe08, &filePtr, &fileSize, 1)) {
                pair.Reset();
                pair.Reset();
                ZeroDestroyGPCPointer(&pair.pGPCFile);
                goto abort_unlock;
            }

            decompressed = DecompressLZ77FileIntoAllocatedSpace(*sb, filePtr, decompSize);

            struct Struct_203dafc params;
            ClearEightWords(&params);
            _Z25RestorePairTables0207df90Pc(fp);
            params.fieldc = (int)sb;
            params.field4 = (int)decompressed;
            params.field8 = (int)decompSize;
            _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(node->state, &params, 0);
            _Z24BackupPairTables0207dfacPc(fp);

            node->state->flags_d4 |= 2;
            pair.Reset();
            pair.Reset();
            ZeroDestroyGPCPointer(&pair.pGPCFile);
        }
        else {
            node->stateB = sb->Allocate(0x9c);
            if (node->stateB == 0) goto abort_unlock;
            _Z30InitializeRandomMotion0203c794Pv(node->stateB);
            StoreValueViaField0x14((unsigned char*)node, (int)self);

            if (entry->name[0] != 0 && entry->type == 0) {
                int successFlag = 0;
                char pathBuf[40];
                if (info != 0 && (info->fieldC & 0x800)) {
                    successFlag = 1;
                    sprintf(pathBuf, &data_020efe0e, entry->name);
                    NitroVM vm;
                    NitroVM_Initialize(&vm);
                    if (!NitroVM_PrepareReadFileByPath(&vm, pathBuf)) {
                        successFlag = 0;
                    }
                }
                if (successFlag == 0) {
                    sprintf(pathBuf, &data_020efe20, entry->name);
                } else {
                    sprintf(pathBuf, &data_020efe27, entry->name);
                }
                if (node->stateB != 0) {
                    _Z27UpdateElementStream0203f02cP11Obj0203f02ciiPcii(*(struct Obj0203f02c**)((char*)node + 0x14), (int)pathBuf, (int)sb, fp, 0, 0);
                }
                if (node->stateB != 0) {
                    func_0203f138(node->stateB, 1);
                }
                Set2e0203d028(node->stateB, 0x3d);
                handledFlag = 1;
            }
        }

        if (loopIndex < 0x20) {
            self->entries[loopIndex] = node;
        }

        if (info != 0) {
            _Z28SetActiveChildFields02040774P12Node02040774iii((struct Node02040774*)node, info->field10, info->field14, info->field18);
            _Z22HandleObjEvent0204085cP11Obj0204085ciii((struct Obj0204085c*)node, 0, info->field1c, 0);
            _Z26ApplyFlagsToTarget02040540P11Obj02040540((struct Obj02040540*)node);

            if (handledFlag == 0 && info->field54 != 0) {
                char buf[60];
                sprintf(buf, &data_020efe30, info->field54);
                void* loadedPtr = LoadFileIntoNewAllocation(buf, *sb, &outLen64);
                if (loadedPtr != 0) {
                    int bit = 0;
                    struct BitFlag0203d028* p = 0;
                    if (node->state != 0) p = *(struct BitFlag0203d028**)((char*)node->state + 0xc);
                    else if (node->combatant != 0) p = *(struct BitFlag0203d028**)((char*)node->combatant + 0xc);
                    if (p != 0) bit = p->b0;

                    struct Struct_203dafc lockParams;
                    lockParams.field4 = (int)loadedPtr;
                    lockParams.fieldc = (int)sb;
                    lockParams.field8 = (int)outLen64;
                    lockParams.field1c = 1;

                    if (bit == 0) {
                        _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo((int)node->state, (int)&lockParams);
                    } else if (bit == 1) {
                        _ZN8Object3D25LoadFromCCHROrCMOTArchiveEP21ObjectArchiveLoadInfoPFiPN4BCFG15AnimationRecordEE(node->state, &lockParams, 0);
                    }
                }
            }

            if (info->fieldC & 0x2000) {
                if (childModelPtr == 0) {
                    childModelPtr = sb->Allocate(0xac);
                    if (childModelPtr == 0) goto abort_unlock;
                    _ZN8Object3D10InitializeEv(childModelPtr);
                    mdlPtr = LoadFileIntoNewAllocation(&data_020efe38, *sb, &mdlOutLen);
                    if (mdlPtr != 0) {
                        struct Struct_203dafc mdlParams;
                        ClearEightWords(&mdlParams);
                        _Z25RestorePairTables0207df90Pc(fp);
                        mdlParams.field4 = (int)mdlPtr;
                        mdlParams.field8 = (int)mdlOutLen;
                        mdlParams.fieldc = (int)sb;
                        _ZN8Object3D18LoadFromCHRArchiveEP21ObjectArchiveLoadInfo((int)childModelPtr, (int)&mdlParams);
                        _Z24BackupPairTables0207dfacPc(fp);
                    }
                    _ZN8Object3D8SetScaleEiii((struct Shorts5c_374e0*)childModelPtr, 0x10a, 0x10a, 0x10a);
                    _ZN8Object3D9SetFlag16Ev((unsigned char*)childModelPtr);
                }
                if (assignedFlag == 0) {
                    node->field0x10 = childModelPtr;
                    assignedFlag = 1;
                } else {
                    childModelPtr2 = sb->Allocate(0xac);
                    if (childModelPtr2 == 0) goto abort_unlock;
                    _ZN8Object3D10InitializeEv(childModelPtr2);
                    _ZN8Object3D14ShallowCloneToEPS_(childModelPtr, childModelPtr2);
                    _ZN8Object3D9SetFlag16Ev((unsigned char*)childModelPtr2);
                    node->field0x10 = childModelPtr2;
                }
            }

            if (node->stateB != 0) {
                _Z28SetActiveChildShorts020408c8P12Node020408c8sss((struct Node020408c8*)node, 0x8f, 0x8f, 0x8f);
            }
            else if (node->state != 0) {
                _ZN8Object3D8SetScaleEiii((struct Shorts5c_374e0*)node->state, 0x10a, 0x10a, 0x10a);
                _Z28SetByteC4AndDispatch02041598P11Obj02041598i((struct Obj02041598*)node->state, info->field1e, 0);
                if (node->flags & 0x800) {
                    _ZN8Object3D9SetFlag16Ev((unsigned char*)node->state);
                    _ZN8Object3D10EnableFlagEi((unsigned char*)node->state, 0x2000000);
                    StoreVec3AtField0x50((unsigned char*)node->state, 0x4b5c, info->field1c, 0);
                }
                if (info->field58 != 0) {
                    _Z28SetWordCCAndDispatch020415b0P11Obj020415b0i((struct Obj020415b0*)node->state, info->field58, 0);
                }
                if (info->flag7) {
                    func_0203db44(self, node, sb);
                }
            }
            else if (node->combatant != 0) {
                _ZN8Object3D8SetScaleEiii((struct Shorts5c_374e0*)node->combatant, 0x10a, 0x10a, 0x10a);
                _Z31SetByte0x2e8AndDispatch02041628Pvi(node->combatant, info->field1e, 0);
                if (node->flags & 0x800) {
                    _ZN8Object3D9SetFlag16Ev((unsigned char*)node->combatant);
                    StoreVec3AtField0x50((unsigned char*)node->combatant, 0x4b5c, info->field1c, 0);
                }
                if (info->field58 != 0) {
                    _Z31SetWord0x2f4AndDispatch02041640Pvi(node->combatant, info->field58, 0);
                }
                int localVec3[3];
                _ZN8Vector3iaSERKS_(localVec3, (int*)((char*)node->combatant + 0x44));
                localVec3[1] = func_02018fbc(globalStruct, localVec3);
                _ZN8Vector3iaSERKS_((int*)((char*)node->combatant + 0x44), localVec3);
            }
            _Z27StoreToFirstNonNull02040bfcP11Obj02040bfci((struct Obj02040bfc*)node, info->field38);

            SetX90_0203d028(node->stateB, info->field3c);
        }

        loopIndex++;
        self->loopCount++;
        entry = entry->next;
    }

abort_unlock:
    BackgroundLoader::RemoveLockGlobal();
}
