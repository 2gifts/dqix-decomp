#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "System/OverlayId.h"

#if defined(jpn)
enum { Field36d0 = 0x34c0, Field36d4 = 0x34c4, Field36fc = 0x34ec, Field3700 = 0x34f0, Field371c = 0x350c, Field3720 = 0x3510, Field3b4c = 0x392c, Field3b50 = 0x3930, Field3b70 = 0x3950, Field3b74 = 0x3954, Field41c0 = 0x3fa0, Field41c4 = 0x3fa4, Field42e4 = 0x40c4, CombatantFlagOffset = 0x180 };
#else
enum { Field36d0 = 0x36d0, Field36d4 = 0x36d4, Field36fc = 0x36fc, Field3700 = 0x3700, Field371c = 0x371c, Field3720 = 0x3720, Field3b4c = 0x3b4c, Field3b50 = 0x3b50, Field3b70 = 0x3b70, Field3b74 = 0x3b74, Field41c0 = 0x41c0, Field41c4 = 0x41c4, Field42e4 = 0x42e4, CombatantFlagOffset = 0x18c };
#endif

struct SearchStruct;
struct FlagWord02046708;
struct BitField0203402c;
struct Struct0200fb08;
struct Obj021befe4;
struct Obj0205eaa0;
struct Obj020397cc;
struct S021b2ba0;
struct TailList020469b4;
struct TailNode020469b4;
struct SetFlagStruct;
struct FlagBlob02027bac;
struct SafeAllocator;

int GetGlobalField0x1c020421a0();
extern "C" SearchStruct* func_0202ae18(void);
extern "C" void* func_02012fe4(void);
FlagWord02046708* GetDataPtr02114e04_020d6c00();
unsigned char* GetField0x3f8Address(GameState* gs);
int IsField0Null(void** list);
int GetByteField0x252(void* obj);
int CheckSubstructByte0x7cPositive(signed char* obj);
int TestFlags02046708(FlagWord02046708* flags, unsigned int mask);
int TestFlag0SetAndFlag1Clear(unsigned short* flags, int mask);
int CheckField0xc4Low15BitsNonZero(BitField0203402c* obj);
int GetSignedField020c39c8(volatile unsigned short* reg);
int NormalizeField5_0200fb08(Struct0200fb08* obj);
extern "C" int func_0202c508(SearchStruct* search);
extern "C" int func_0202c540(SearchStruct* search);
void InitState53_021befe4(Obj021befe4* obj);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
void CancelPendingAction020397cc(Obj020397cc* obj, int flag);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0* obj, int a, int b);
extern "C" void func_ov017_021a5568(void* node);
int GetByte0x26c(char* obj);
void InitObjState_021b2174(unsigned char* obj);
void SetNameChecked_021b2ba0(S021b2ba0* obj, char* name);
void SetFields30And34_021b2bd0(void* obj, int handler, int overlayId);
void SetCombatModeFromCase020dc2d0(int mode);
void SetFlag0x9c6(SetFlagStruct* obj, int value);
void SetFlagsAt0xa97(FlagBlob02027bac* obj, unsigned char value);
void AllocateAndCopyBuf28_0216ae2c(SafeAllocator* allocator, void* arg);
extern unsigned short data_02114e30;
extern char data_02108760;
extern char data_ov017_021d76dc;

struct Touch02114e54 {
    char pad0[0x24];
    unsigned short active;
    char pad1[0x30 - 0x26];
    int x;
    int y;
    char pad2[0x5f - 0x38];
    unsigned char enabled;
};

extern Touch02114e54 data_02114e54;

struct Thresholds021d6a80 {
    short values[5];
};

extern Thresholds021d6a80 data_ov017_021d6a80;

struct Unknown021a51a4 {
    char pad0[0xac];
    short fac;
    char pad1[0xb2 - 0xae];
    short fb2;
    char pad2[CombatantFlagOffset - 0xb4];
    int f18c;
};

struct Node021a51a4 {
    char pad0[0x24];
    unsigned char f24;
    char pad1[0x28 - 0x25];
    int f28;
    int f2c;
};

struct Grotto021a51a4 {
    char pad0[0xc];
    unsigned char kind : 4;
};

struct Res021a51a4 {
    char pad0[Field36d0];
    SetFlagStruct* flags;
    char pad1[Field36fc - Field36d4];
    TailList020469b4* list;
    char pad2[Field371c - Field3700];
    Node021a51a4* node;
    char pad3[Field3b4c - Field3720];
    unsigned char* dialog;
    char pad4[Field3b70 - Field3b50];
    Obj021befe4* state53;
    char pad5[Field41c0 - Field3b74];
    int f41c0;
    char pad6[Field42e4 - Field41c4];
    unsigned char pending;
};

// USA: func_ov017_021a51a4
extern "C" ARM void func_ov017_021a51a4(Res021a51a4* res) {
    GameState* gs;
    Unknown021a51a4* unknown;
    unsigned char* dialog;
    SearchStruct* search;
    FlagWord02046708* flagWord;
    unsigned char* field3f8;
    int start;
    int x;
    int y;
    unsigned char* grotto;
    int level;
    Grotto021a51a4* grottoInfo;
    gs = GameState::GetInstance();
    unknown = (Unknown021a51a4*)gs->GetUnknownGameObject();
    GetGlobalField0x1c020421a0();
    search = func_0202ae18();
    grottoInfo = *(Grotto021a51a4**)((char*)func_02012fe4() + 8);
    flagWord = GetDataPtr02114e04_020d6c00();
    field3f8 = GetField0x3f8Address(gs);
    if (!IsField0Null((void**)res->list)) {
        return;
    }
    if (!GetByteField0x252(unknown)) {
        return;
    }
    if (CheckSubstructByte0x7cPositive((signed char*)unknown)) {
        return;
    }
    if (unknown->f18c & 1) {
        return;
    }
    if (unknown->fac > 0) {
        return;
    }
    if (field3f8[2] != 0) {
        return;
    }
    start = 0;
    if (!TestFlags02046708(flagWord, 0x800)) {
        if ((TestFlag0SetAndFlag1Clear(&data_02114e30, 0x400) || res->pending == 1) && unknown->fac == 0) {
            if (!CheckField0xc4Low15BitsNonZero((BitField0203402c*)unknown)) {
                start = 1;
            }
        }
    } else {
        res->pending = start;
    }
    x = data_02114e54.x;
    y = data_02114e54.y;
    if (GetSignedField020c39c8((volatile unsigned short*)0x400006c) != 0) {
        return;
    }
    grotto = (unsigned char*)gs->GetGrottoStruct();
#if !defined(jpn)
    Thresholds021d6a80 thresholds = data_ov017_021d6a80;
    level = NormalizeField5_0200fb08((Struct0200fb08*)GameState::GetInstance());
#endif
    int touched;
    if (data_02114e54.enabled && data_02114e54.active &&
#if defined(jpn)
        0xb0 <= x
#else
        thresholds.values[level - 1] <= x
#endif
         && x <= 0xf8 && y >= 0xa2 && y <= 0xb2) {
        touched = 1;
    } else {
        touched = 0;
    }
    if (func_0202c508(search) && grotto[0] != 0 && grottoInfo->kind == 0
        && (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x800) || touched)) {
        InitState53_021befe4(res->state53);
        AppendNodeToTail(res->list, (TailNode020469b4*)res->state53);
        return;
    }
    if (start) {
        CancelPendingAction020397cc((Obj020397cc*)unknown, 1);
        unknown->fb2 = 0;
        res->pending = 0;
        DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 1, 0);
        func_ov017_021a5568(res->node);
        Node021a51a4* node = res->node;
        node->f24 = 0;
        node->f28 = 0;
        node->f2c = -1;
        AppendNodeToTail(res->list, (TailNode020469b4*)res->node);
        return;
    }
    if (grotto[0] != 0 && func_0202c540(search) == 0 && grottoInfo->kind == 0) {
        return;
    }
    if (res->f41c0 != 0) {
        return;
    }
    if (!TestFlag0SetAndFlag1Clear(&data_02114e30, 0x800)) {
        return;
    }
    if (res->pending != 0 || unknown->fac != 0) {
        return;
    }
    if (CheckField0xc4Low15BitsNonZero((BitField0203402c*)unknown)) {
        return;
    }
    if (GetByte0x26c((char*)unknown)) {
        return;
    }
    CancelPendingAction020397cc((Obj020397cc*)unknown, 1);
    unknown->fb2 = 0;
    dialog = res->dialog;
    InitObjState_021b2174(dialog);
    SetNameChecked_021b2ba0((S021b2ba0*)dialog, &data_ov017_021d76dc);
    SetFields30And34_021b2bd0(dialog, (int)AllocateAndCopyBuf28_0216ae2c, OVERLAY_ID(4));
    AppendNodeToTail(res->list, (TailNode020469b4*)dialog);
    SetCombatModeFromCase020dc2d0(3);
    SetFlag0x9c6(res->flags, 1);
    SetFlagsAt0xa97((FlagBlob02027bac*)res->flags, 1);
}
