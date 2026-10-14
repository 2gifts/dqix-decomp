#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/MapDisplay.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" unsigned short* func_02012fe4(void);
extern "C" char* func_0203bd08(void);
ARM void* GetData02105254(void);

extern "C" void func_02021428(void* unused0, int amount);
void InitSubScreenDisplay(void* context);
void TailForward0203b66c(char* obj);
void InitSubObject0203bd78(char* obj);
void InitBattleContext0203bd24(char* obj);

struct AxisFloats0203b5a0;
int IsAxisIntWithin16(struct AxisFloats0203b5a0* s, int axis);

int DispatchCharTransfer0203b784(int* arr1, int idx, int category, int addr, unsigned int len, unsigned int len2);
void SetArraySlotFlag0203b718(void* objPtr, int mode, int idx, int fillByte);
extern "C" void func_0203ba74(void* obj);

void Init0205a198(struct Struct0205a198* p);
void InitStruct0205a444(char* obj);

void InitFourEntrySlots02020aa0(void* obj);

struct State0xbb1c;
void ClearFields0x8(struct State0xbb1c* obj);

struct Obj0203bb3c;
void SetupAndDispatchCharTransfer0203bb3c(struct Obj0203bb3c* obj, char* src, SafeAllocator* allocator, int category, unsigned short arg5);

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
void MarkActiveCombatantSlots02026b7c(unsigned char* obj);
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
    void* allocatorPtr;
    char pad2[0x10 - 0xc];
    void* ctxPtr;
};
extern struct Global020fdc4c_020227dc data_020fdc4c;

// USA: func_020227dc
extern "C" ARM void func_020227dc(MapDisplay* ctx) {
    GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    unsigned short* p6 = func_02012fe4();
    char* axisObj = ((char*)func_ov017_0218b5b0());
    char* p8 = func_0203bd08();
    void* dataPtr = GetData02105254();
    int i;
    SafeAllocator* sb = (SafeAllocator*)(axisObj + 0x128);

    if (ctx->loadStage == 0) {
        func_02021428(ctx, 0x19);
        loader->AddFence();
        ctx->taska24 = loader->QueueLoadFile(&data_020ef67c, 0);
        ctx->taska20 = loader->QueueLoadFileInGP2((const char*)(*(int*)((char*)&data_020ef460 + 8 - GlobalHeaderRegionOffset)), &data_020ef692, 0);
        ctx->taska28 = loader->QueueLoadFile(&data_020ef69f, 0);
        ctx->loadStage = ctx->loadStage + 1;
        return;
    }

    if (ctx->loadStage != 1) return;

    if (loader->GetTaskStatus(ctx->taska24) == 0) return;
    if (loader->GetTaskStatus(ctx->taska20) == 0) return;
    if (loader->GetTaskStatus(ctx->taska28) == 0) return;

    func_02021428(ctx, 0x19);
    if (IsAxisIntWithin16((struct AxisFloats0203b5a0*)axisObj, 1) != 0) return;

    func_02020720(ctx);
    InitSubScreenDisplay(ctx);
    TailForward0203b66c((char*)dataPtr);
    sb->Reset();
    InitSubObject0203bd78(p8);
    InitBattleContext0203bd24(p8);

    char buf[0x20];
    memset(buf, 0, 0x20);
    DispatchCharTransfer0203b784((int*)dataPtr, 1, 1, (int)buf, 0x20, 1);
    SetArraySlotFlag0203b718(dataPtr, 1, 0, 0);
    SetArraySlotFlag0203b718(dataPtr, 1, 1, 0);
    func_0203ba74(dataPtr);

    for (i = 0; i < 0x1c; i++) {
        Init0205a198(&ctx->records[i]);
    }

    InitStruct0205a444((char*)&ctx->entryList);
    ctx->entryList.active = 1;
    ctx->entryList.records = ctx->records;
    ctx->entryList.count = 0x1c;
    ctx->displayMode = 1;
#if defined(jpn)
    func_02020aec(ctx, ctx->taska24, sb);
#else
    func_02020aec(ctx, &ctx->taska24, sb);
#endif

    InitFourEntrySlots02020aa0(ctx);
    ctx->nameCount = 1;
    ctx->forwardingCount = 1;

    void* fileData = 0;
    unsigned int fileSize = 0;
    loader->GetLoadedFileByID(ctx->taska20, &fileData, &fileSize);

    ctx->names = (Entry02021578*)sb->Allocate(sizeof(Entry02021578));
    ClearFields0x8((struct State0xbb1c*)((char*)ctx->names + 8));

    SetupAndDispatchCharTransfer0203bb3c((struct Obj0203bb3c*)((char*)ctx->names + 8), (char*)fileData, sb, 1, 0);
    ForwardParamsToB8bc((struct Bcb8Params*)((char*)ctx->names + 8), 0, 0);

    BackgroundLoader::GetInstance()->RemoveTask(ctx->taska20);
    ctx->taska20 = -1;

    loader->GetLoadedFileByID(ctx->taska28, &fileData, &fileSize);

    struct ResetStruct local;
    data_020fdc4c.ctxPtr = ctx;
    data_020fdc4c.allocatorPtr = sb;
    _ZN6Script10InitializeEv(&local);
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(&local, &data_020ef498);
    _ZN6Script4LoadEPKvj((struct StreamState*)&local, (struct StreamHeader*)fileData, (int)fileSize);
    _ZN6Script7ExecuteEv((struct Struct02030774*)&local);

    if (*p6 == 10000 || *p6 == 10100) {
        ctx->field12 = 1;
        ctx->refreshRecords = 0;
        ctx->field9ba = 0;
        strcpy(ctx->headerName, &data_020ef6b5);
    }

    BackgroundLoader::GetInstance()->RemoveTask(ctx->taska28);
    ctx->taska28 = -1;

    func_0202445c(ctx);
    func_ov017_02191234(axisObj);
    ctx->forwardingPending = 1;
    ctx->field9c4 = 1;
    ctx->field9c8 = 0;
    ctx->field9c3 = 0;
    ctx->loadStage = ctx->loadStage + 1;
    DelayThenSyncBit0();
    func_0202343c(ctx);
    MarkActiveCombatantSlots02026b7c((unsigned char*)ctx);
    func_02026bdc(ctx, 0);
}
