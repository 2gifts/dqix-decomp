#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" unsigned short* func_02012fe4(void);
extern "C" char* func_0203bd08(void);
ARM void* GetData02105254(void);

extern "C" void func_02021428(void* unused0, int amount);
extern "C" void func_02020720(char* obj);
extern "C" void _Z20InitSubScreenDisplayv(void* ctx);
extern "C" void _Z19TailForward0203b66cPc(char* obj);
extern "C" void _Z21InitSubObject0203bd78Pc(char* obj);
extern "C" void _Z25InitBattleContext0203bd24Pc(char* obj);

struct AxisFloats0203b5a0;
int IsAxisIntWithin16(struct AxisFloats0203b5a0* s, int axis);

extern "C" int _Z28DispatchCharTransfer0203b784Piiiijj(int* arr1, int idx, int category, int addr, unsigned int len, unsigned int len2);
extern "C" void _Z24SetArraySlotFlag0203b718Pviii(void* objPtr, int mode, int idx, int fillByte);
extern "C" void func_0203ba74(void* obj);

struct Struct0205a198 { char pad[0x28]; };
extern "C" void _Z12Init0205a198P14Struct0205a198(struct Struct0205a198* p);
extern "C" void _Z18InitStruct0205a444Pc(char* obj);

#if defined(jpn)
extern "C" void func_02020aec(char* self, int handle, int arg2);
#else
extern "C" void func_02020aec(char* self, int* handle, int arg2);
#endif
extern "C" void _Z26InitFourEntrySlots02020aa0Pv(void* obj);

struct State0xbb1c;
void ClearFields0x8(struct State0xbb1c* obj);

struct Obj0203bb3c;
extern "C" void _Z36SetupAndDispatchCharTransfer0203bb3cP11Obj0203bb3cPcP13SafeAllocatorit(struct Obj0203bb3c* obj, char* src, SafeAllocator* allocator, int category, unsigned short arg5);

struct Bcb8Params;
void ForwardParamsToB8bc(struct Bcb8Params* s, int arg1, int arg2);

struct ResetStruct {
    int w0;
    int w4;
    int w8;
    int wc;
    int w10;
    int w14;
    int w18;
    int w1c;
    int w20;
    int w24;
    int w28;
    char pad[0x400];
    unsigned char b42c;
};
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* p, void* q);

struct StreamHeader;
struct StreamState;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

extern "C" void func_0202445c(void* obj);
extern "C" void func_ov017_02191234(void* obj);
void DelayThenSyncBit0(void);
extern "C" void func_0202343c(void* obj);
extern "C" void _Z32MarkActiveCombatantSlots02026b7cPh(unsigned char* obj);
extern "C" void func_02026bdc(void* obj, int flag);

extern char data_020ef67c;
extern int data_020ef460;
extern char data_020ef692;
extern char data_020ef69f;
extern int data_020ef498;
extern char data_020ef6b5;

#if defined(jpn)
enum { ContextTailRegionOffset = 0xac, GlobalHeaderRegionOffset = 4 };
#else
enum { ContextTailRegionOffset = 0, GlobalHeaderRegionOffset = 0 };
#endif

struct Global020fdc4c_020227dc {
    char pad[0x8 - GlobalHeaderRegionOffset];
    void* allocatorPtr;   // 0x8
    char pad2[0x10 - 0xc];
    void* ctxPtr;          // 0x10
};
extern struct Global020fdc4c_020227dc data_020fdc4c;

struct Obj020227dc {
    char pad0[0x2];
    char nameBuf[1];              // 0x2
    char pad1[0x12 - 0x3];
    unsigned char field0x12;      // 0x12
    char pad2[0x14 - 0x13];
    int field0x14;                // 0x14
    char pad3[0x20 - 0x18];
    void* field0x20;              // 0x20
    int field0x24;                // 0x24
    char pad4[0x30 - 0x28];
    int field0x30;                // 0x30
    char pad5[0x94 - 0x34];
    char field0x94[1];            // 0x94
    char pad6[0xd4 - 0x95];
    struct Struct0205a198* field0xd4;  // 0xd4
    char pad7[0xe0 - 0xd8];
    unsigned short field0xe0;     // 0xe0
    char pad7b[0xe4 - 0xe2];
    unsigned char field0xe4;      // 0xe4
    char pad8[0xe8 - 0xe5];
    struct Struct0205a198 arr_e8[0x1c];  // 0xe8..0x548
    char pad9[0x55c - 0x548];
    unsigned char field0x55c;     // 0x55c
    char pad10[0x779 - ContextTailRegionOffset - 0x55d];
    unsigned char field0x779;     // 0x779
    char pad11[0x9ba - 0x77a];
    unsigned char field0x9ba;     // 0x9ba
    char pad12[0x9c2 - 0x9bb];
    signed char initState;        // 0x9c2
    unsigned char field0x9c3;     // 0x9c3
    unsigned char field0x9c4;     // 0x9c4
    char pad13[0x9c8 - 0x9c5];
    unsigned char field0x9c8;     // 0x9c8
    char pad14[0xa20 - 0x9c9];
    int taskA20;                  // 0xa20
    int taskA24;                  // 0xa24
    int taskA28;                  // 0xa28
};

// USA: func_020227dc
extern "C" ARM void func_020227dc(struct Obj020227dc* ctx) {
    GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    unsigned short* p6 = func_02012fe4();
    char* axisObj = ((char*)func_ov017_0218b5b0());
    char* p8 = func_0203bd08();
    void* dataPtr = GetData02105254();
    int i;
    SafeAllocator* sb = (SafeAllocator*)(axisObj + 0x128);

    if (ctx->initState == 0) {
        func_02021428(ctx, 0x19);
        loader->AddFence();
        ctx->taskA24 = loader->QueueLoadFile(&data_020ef67c, 0);
        ctx->taskA20 = loader->QueueLoadFileInGP2((const char*)(*(int*)((char*)&data_020ef460 + 8 - GlobalHeaderRegionOffset)), &data_020ef692, 0);
        ctx->taskA28 = loader->QueueLoadFile(&data_020ef69f, 0);
        ctx->initState = ctx->initState + 1;
        return;
    }

    if (ctx->initState != 1) return;

    if (loader->GetTaskStatus(ctx->taskA24) == 0) return;
    if (loader->GetTaskStatus(ctx->taskA20) == 0) return;
    if (loader->GetTaskStatus(ctx->taskA28) == 0) return;

    func_02021428(ctx, 0x19);
    if (IsAxisIntWithin16((struct AxisFloats0203b5a0*)axisObj, 1) != 0) return;

    func_02020720((char*)ctx);
    _Z20InitSubScreenDisplayv(ctx);
    _Z19TailForward0203b66cPc((char*)dataPtr);
    sb->Reset();
    _Z21InitSubObject0203bd78Pc(p8);
    _Z25InitBattleContext0203bd24Pc(p8);

    char buf[0x20];
    memset(buf, 0, 0x20);
    _Z28DispatchCharTransfer0203b784Piiiijj((int*)dataPtr, 1, 1, (int)buf, 0x20, 1);
    _Z24SetArraySlotFlag0203b718Pviii(dataPtr, 1, 0, 0);
    _Z24SetArraySlotFlag0203b718Pviii(dataPtr, 1, 1, 0);
    func_0203ba74(dataPtr);

    for (i = 0; i < 0x1c; i++) {
        _Z12Init0205a198P14Struct0205a198(&ctx->arr_e8[i]);
    }

    _Z18InitStruct0205a444Pc(ctx->field0x94);
    ctx->field0xe4 = 1;
    ctx->field0xd4 = ctx->arr_e8;
    ctx->field0xe0 = 0x1c;
    ctx->field0x14 = 1;
#if defined(jpn)
    func_02020aec((char*)ctx, ctx->taskA24, (int)sb);
#else
    func_02020aec((char*)ctx, &ctx->taskA24, (int)sb);
#endif

    _Z26InitFourEntrySlots02020aa0Pv(ctx);
    ctx->field0x24 = 1;
    ctx->field0x30 = 1;

    void* fileData = 0;
    unsigned int fileSize = 0;
    loader->GetLoadedFileByID(ctx->taskA20, &fileData, &fileSize);

    ctx->field0x20 = sb->Allocate(0x24);
    ClearFields0x8((struct State0xbb1c*)((char*)ctx->field0x20 + 8));

    _Z36SetupAndDispatchCharTransfer0203bb3cP11Obj0203bb3cPcP13SafeAllocatorit((struct Obj0203bb3c*)((char*)ctx->field0x20 + 8), (char*)fileData, sb, 1, 0);
    ForwardParamsToB8bc((struct Bcb8Params*)((char*)ctx->field0x20 + 8), 0, 0);

    BackgroundLoader::GetInstance()->RemoveTask(ctx->taskA20);
    ctx->taskA20 = -1;

    loader->GetLoadedFileByID(ctx->taskA28, &fileData, &fileSize);

    struct ResetStruct local;
    data_020fdc4c.ctxPtr = ctx;
    data_020fdc4c.allocatorPtr = sb;
    _ZN6Script10InitializeEv(&local);
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(&local, &data_020ef498);
    _ZN6Script4LoadEPKvj((struct StreamState*)&local, (struct StreamHeader*)fileData, (int)fileSize);
    _ZN6Script7ExecuteEv((struct Struct02030774*)&local);

    if (*p6 == 10000 || *p6 == 10100) {
        ctx->field0x12 = 1;
        ctx->field0x779 = 0;
        ctx->field0x9ba = 0;
        strcpy(ctx->nameBuf, &data_020ef6b5);
    }

    BackgroundLoader::GetInstance()->RemoveTask(ctx->taskA28);
    ctx->taskA28 = -1;

    func_0202445c(ctx);
    func_ov017_02191234(axisObj);
    ctx->field0x55c = 1;
    ctx->field0x9c4 = 1;
    ctx->field0x9c8 = 0;
    ctx->field0x9c3 = 0;
    ctx->initState = ctx->initState + 1;
    DelayThenSyncBit0();
    func_0202343c(ctx);
    _Z32MarkActiveCombatantSlots02026b7cPh((unsigned char*)ctx);
    func_02026bdc(ctx, 0);
}
