#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "System/ColorEffects.h"
#include "System/Graphics.h"
#include "std_library_functions.h"

struct StreamHeader;
struct Struct020e57e0 { int words[3]; };
struct FieldBlock63d6_115a8;
struct Actor0209c678;
struct Actor0209c174;
struct Obj_0205e88c;

struct MenuItem0218b5c4 { char data[0x40]; };

struct Menu0218b5c4 {
    char pad0[0x4c];
    int mode;
    char pad50[0x5c - 0x50];
    short top;
    short last;
    short cursor;
    char pad62[0x6d - 0x62];
    unsigned char flags;
    char pad6e[0x70 - 0x6e];
    unsigned char f70;
    char pad71;
    unsigned char f72;
};

struct Self0218b5c4 {
    SafeAllocator allocator;
    Menu0218b5c4 menu;
    char pad88[0x94 - 0x88];
    int f94;
};

struct ScriptNode0218b5c4 {
    unsigned short id;
    char pad2[2];
    int value;
    const char* mainName;
    const char* subName;
    char pad10;
    unsigned char fade;
};

struct NodeList0218b5c4 {
    ScriptNode0218b5c4* head;
    int count;
    int owner;
};

int EncodeSignFlaggedHalfword_020c39a0(short* out, int value);
extern "C" void MapVRAMBanksToMainBG(int v);
void SetDispcntModeAndFlags020c391c(int mode, int flagsA, int valB);
extern "C" void func_020a0cc4(unsigned int);
void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
void SetStructFieldsFromCode02028d68(int code);
void SetBuffer02028ddc(void* ptr);
void UploadPendingPalette02028dec(int);
void Set3DClearColor_020c5588(int color, int alpha, int depth, int polygonId, int fogEnable);
void ComputeAndLoadMatrix020c5770(int a0, int a1, int a2, int a3, int b0, int b1, int b2, int gate, void* outBuf);
int SetPowCnt1Bit15_0218bc70(int enable);
extern "C" void func_ov016_0218e00c(NodeList0218b5c4* list);
struct Obj0218e098;
void RegisterObjectAndRunScript0218e098(Obj0218e098*, int);
extern "C" void func_02029568(Menu0218b5c4* menu);
extern "C" void func_020294cc(void* self, const char* src);
int GetField4_0218e174(int*);
void Init0202949c(char*);
struct Node0218e14c;
ScriptNode0218b5c4* GetNthNode_0218e14c(Node0218e14c**, int);
struct ListHead0202a944;
struct ListNode0202a944;
void AppendNodeToList0202a944(ListHead0202a944*, ListNode0202a944*);
extern "C" void func_0202a6c4(Menu0218b5c4* menu);
void Deactivate0202a8cc(char*, int);
void DelayThenSyncBit0_020c9820();
void RestoreDisplayMode_020c38d4();
int GetByteField0x63d6_020115a8(FieldBlock63d6_115a8* gs);
void InitCombatSubsystems02012efc();
void ResetGxEngineState020c52e8();
extern "C" void func_020c5414();
int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);
void ClearBuffer02029060();
extern "C" void func_02029988(void* p, int flag);
void FlushBuffer02029088();
void WriteControlAndToggle020d86d0(int a, int b);
void ProcessRingJobs020bbcb4();
void FlushOrClearBuffer020290ac(int flag);
void ClearThreeWords020e57e0(Struct020e57e0* p);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
void InitAndRunBufferedScript020e57f4(int, int, StreamHeader*, int);
int GetWord0x7f6c_0201201c(void* gs);
struct Node0218e124;
ScriptNode0218b5c4* FindNodeByID_0218e124(Node0218e124**, int);
void DispatchContextByState0209c678(Actor0209c678* actor, int arg);
void ScaleAndNotify0203ad88(void* a, void* b, int c);
extern "C" void func_020bbd9c();
void ResetObjectState0205e8d4(void* p);
void FreeAndReinit0203a950(void* p);
void InitDisplayState0205e88c(Obj_0205e88c* p);
void ResetActor0209c174(Actor0209c174* p);
void Dispatch0203a974With0xA2000_0209c2b8(void* p);
void SetupContextForMode0205ea20(void* p, int mode);
void Dispatch0203a974With0x57000_0209c290(void* p);
void TailForward02012da4(AllocatorUnion* alloc, void* data);
extern "C" void func_020a0c0c();
extern "C" void func_ov016_0218d2f4(char* mainName, char* subName, Self0218b5c4* self, ScriptNode0218b5c4* node, int mode, Struct020e57e0* script);
extern "C" void func_ov016_0218caa8(char* name, Self0218b5c4* self, ScriptNode0218b5c4* node, int mode, Struct020e57e0* script);

extern AllocatorUnion data_02114e20;
extern unsigned short data_02114e30;
extern char data_02109bf4;
extern char data_02108760;
extern const char data_ov016_0219cfc0[];
extern const char data_ov016_0219cfc6[];
extern const char data_ov016_0219cfcc[];
extern const char data_ov016_0219cfe6[];
extern const char data_ov016_0219cff7[];
extern const char data_ov016_0219d011[];
extern const char data_ov016_0219d022[];

static inline void GX_SetBGCharOffset(int o) { DISPCNT = (DISPCNT & ~0x7000000) | (o << 24); }
static inline void GX_SetBGScrOffset(int o) { DISPCNT = (DISPCNT & ~0x38000000) | (o << 27); }
// USA: func_ov016_0218b5c4
extern "C" ARM void func_ov016_0218b5c4(Self0218b5c4* self) {
    char mainName[0x50];
    char subName[0x50];
    NodeList0218b5c4 nodes;
    char label[0x30];
    Struct020e57e0 script;
    char mainOnly[0x28];
    char subOnly[0x28];
    unsigned int size;

    GameState* gs = GameState::GetInstance();
    EncodeSignFlaggedHalfword_020c39a0((short*)0x400006c, -16);
    EncodeSignFlaggedHalfword_020c39a0((short*)0x400106c, -16);
    MapVRAMBanksToMainBG(1);
    GX_SetBGCharOffset(0);
    GX_SetBGScrOffset(0);
    SetDispcntModeAndFlags020c391c(1, 0, 1);
    volatile unsigned short* bgcnt = (volatile unsigned short*)0x4000008;
    bgcnt[0] = (bgcnt[0] & ~0x3) | 0x1;
    bgcnt[1] = bgcnt[1] & ~0x3;
    ColorEffect_ConfigureAlphaBlend(0x4000050, BLEND_TARGET_BG0, BLEND_TARGET_BACKDROP, 0x1f, 0x1f);
    ColorEffect_ConfigureAlphaBlend(0x4000050, BLEND_TARGET_BG1, BLEND_TARGET_BG0, 0x1f, 0);
    func_020a0cc4(0x100000);
    self->allocator.CreateTypeB(AllocateAligned4_02012d88(&data_02114e20, 0x100000), 0x100000, 4);
    void* buffer = self->allocator.Allocate(0x6000);
    SetStructFieldsFromCode02028d68(3);
    SetBuffer02028ddc(buffer);
    UploadPendingPalette02028dec(0);
    Set3DClearColor_020c5588(0, 0x10, 0x7fff, 0x3f, 0);
    ComputeAndLoadMatrix020c5770(0, 0xc0000, 0, 0x100000, -0x400000, 0x400000, 0x400000, 1, 0);
    *(volatile unsigned int*)0x400044c = 0;
    SetPowCnt1Bit15_0218bc70(0);

    func_ov016_0218e00c(&nodes);
    RegisterObjectAndRunScript0218e098((Obj0218e098*)&nodes, (int)self);
    func_02029568(&self->menu);
    func_020294cc(&self->menu, data_ov016_0219cfc0);
    MenuItem0218b5c4* items = (MenuItem0218b5c4*)self->allocator.Allocate(GetField4_0218e174((int*)&nodes) * sizeof(MenuItem0218b5c4));
    if (items != 0) {
        for (unsigned int i = 0; i < GetField4_0218e174((int*)&nodes); i++) {
            Init0202949c((char*)&items[i]);
            ScriptNode0218b5c4* node = GetNthNode_0218e14c((Node0218e14c**)&nodes, i);
            if (node != 0) {
                sprintf(label, data_ov016_0219cfc6, node->id, node->value);
                func_020294cc(&items[i], label);
                AppendNodeToList0202a944((ListHead0202a944*)&self->menu, (ListNode0202a944*)&items[i]);
            }
        }
    }
    func_0202a6c4(&self->menu);
    int count = GetField4_0218e174((int*)&nodes);
    self->menu.top = 0;
    self->menu.cursor = 0;
    self->menu.last = count - 1;
    self->menu.flags |= 6;
    self->menu.f72 = 1;
    self->menu.f70 = 1;
    self->menu.mode = 8;
    Deactivate0202a8cc((char*)&self->menu, 1);
    DelayThenSyncBit0_020c9820();
    RestoreDisplayMode_020c38d4();
    DISPCNTSUB |= 0x10000;
    DISPCNT = (DISPCNT & ~0x1f00) | 0x300;
    EncodeSignFlaggedHalfword_020c39a0((short*)0x400006c, -16);
    EncodeSignFlaggedHalfword_020c39a0((short*)0x400106c, -16);

    int id = -1;
    if (GetByteField0x63d6_020115a8((FieldBlock63d6_115a8*)gs) != 0) {
        id = GetByteField0x63d6_020115a8((FieldBlock63d6_115a8*)gs);
        self->f94 = 0;
    }
    InitCombatSubsystems02012efc();
    while (id < 0) {
        InitCombatSubsystems02012efc();
        ResetGxEngineState020c52e8();
        func_020c5414();
        DISP3DCNT &= (unsigned short)~0x3020;
        if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 1)) {
            ScriptNode0218b5c4* node = GetNthNode_0218e14c((Node0218e14c**)&nodes, self->menu.cursor);
            if (node != 0) {
                id = node->id;
            }
        } else if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 2)) {
            self->f94 = 0;
            break;
        }
        ClearBuffer02029060();
        func_02029988(&self->menu, 1);
        FlushBuffer02029088();
        WriteControlAndToggle020d86d0(0, 1);
        DelayThenSyncBit0_020c9820();
        ProcessRingJobs020bbcb4();
        FlushOrClearBuffer020290ac(0);
        EncodeSignFlaggedHalfword_020c39a0((short*)0x400006c, 0);
        EncodeSignFlaggedHalfword_020c39a0((short*)0x400106c, -16);
    }

    ClearThreeWords020e57e0(&script);
    BackgroundLoader::GetInstance();
    if (id > 0) {
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        void* file = 0;
        switch (id) {
        case 4:
            file = ExtractFileFromGP2(data_ov016_0219cfcc, data_ov016_0219cfe6, &size);
            break;
        case 8:
            file = ExtractFileFromGP2(data_ov016_0219cff7, data_ov016_0219d011, &size);
            break;
        }
        if (file != 0) {
            InitAndRunBufferedScript020e57f4((int)&script, (int)self, (StreamHeader*)file, size);
        }
        BackgroundLoader::RemoveLockGlobal();
    }
    ClearBuffer02029060();
    FlushBuffer02029088();
    WriteControlAndToggle020d86d0(0, 1);

    int mode = 2;
    if (GetWord0x7f6c_0201201c(gs) == 5) {
        mode = 1;
    } else if (GetByteField0x63d6_020115a8((FieldBlock63d6_115a8*)gs) != 0) {
        mode = 0;
    }

    if (id >= 0) {
        EncodeSignFlaggedHalfword_020c39a0((short*)0x400006c, -16);
        EncodeSignFlaggedHalfword_020c39a0((short*)0x400106c, -16);
        ScriptNode0218b5c4* node = FindNodeByID_0218e124((Node0218e124**)&nodes, id);
        if (node != 0) {
            if (node->fade != 0) {
                DispatchContextByState0209c678((Actor0209c678*)&data_02109bf4, 0);
                ScaleAndNotify0203ad88(&data_02109bf4, 0, 0);
                func_020bbd9c();
                ResetObjectState0205e8d4(&data_02108760);
                FreeAndReinit0203a950(&data_02109bf4);
                InitDisplayState0205e88c((Obj_0205e88c*)&data_02108760);
                ResetActor0209c174((Actor0209c174*)&data_02109bf4);
                Dispatch0203a974With0xA2000_0209c2b8(&data_02109bf4);
            }
            if (node->mainName != 0 && node->subName != 0) {
                SetPowCnt1Bit15_0218bc70(1);
                sprintf(mainName, data_ov016_0219d022, node->mainName);
                sprintf(subName, data_ov016_0219d022, node->subName);
                func_ov016_0218d2f4(mainName, subName, self, node, mode, &script);
            } else if (node->mainName != 0 && node->subName == 0) {
                SetPowCnt1Bit15_0218bc70(1);
                sprintf(mainOnly, data_ov016_0219d022, node->mainName);
                func_ov016_0218caa8(mainOnly, self, node, mode, &script);
            } else if (node->mainName == 0 && node->subName != 0) {
                SetPowCnt1Bit15_0218bc70(0);
                sprintf(subOnly, data_ov016_0219d022, node->subName);
                func_ov016_0218caa8(subOnly, self, node, mode, &script);
            }
            if (node->fade != 0) {
                ResetObjectState0205e8d4(&data_02108760);
                FreeAndReinit0203a950(&data_02109bf4);
                InitDisplayState0205e88c((Obj_0205e88c*)&data_02108760);
                ResetActor0209c174((Actor0209c174*)&data_02109bf4);
                SetupContextForMode0205ea20(&data_02108760, 100);
                Dispatch0203a974With0x57000_0209c290(&data_02109bf4);
            }
        }
    }

    EncodeSignFlaggedHalfword_020c39a0((short*)0x400006c, -16);
    EncodeSignFlaggedHalfword_020c39a0((short*)0x400106c, -16);
    SignedAllocatorHeader* signedAlloc = self->allocator.GetSignedAllocator();
    self->allocator.Destroy();
    TailForward02012da4(&data_02114e20, signedAlloc);
    func_020a0c0c();
    SetBuffer02028ddc(0);
}
