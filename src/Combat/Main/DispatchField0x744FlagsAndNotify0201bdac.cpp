#include <globaldefs.h>

#if defined(jpn)
enum { kOffset6fc = 0x4ec, kOffset744 = 0x784, kOffsetb68 = 0x948, kOffset745 = 0x785, kOffset746 = 0x786, kOffset48 = 0x88, kOffsetbb8 = 0x998 };
#else
enum { kOffset6fc = 0x6fc, kOffset744 = 0x744, kOffsetb68 = 0xb68, kOffset745 = 0x745, kOffset746 = 0x746, kOffset48 = 0x48, kOffsetbb8 = 0xbb8 };
#endif

#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"

extern "C" void func_ov017_021a9bc4(void* node, int flag);
extern "C" void func_ov017_021a9a9c(void* node, int b1, int b2, int h3, int extra);
extern "C" void func_ov017_021aa4cc(void* overlay, int flag);
extern "C" void* func_0202ae18(void);
extern "C" void func_020ae53c(int arg);

void* GetPtrField0x2a04(GameState* battleStruct);
int IsField0Null(void** obj);

struct AxisFloats0203b5f8 { unsigned char pad0[0xc]; float f0c; unsigned char pad10[8]; float f18; };
int IsAxisIntZero(AxisFloats0203b5f8* s, int axis);

struct TailNode020469b4 { char unk0[2]; unsigned char inList; char unk3; TailNode020469b4* next; };
struct TailList020469b4 { TailNode020469b4* head; TailNode020469b4* tail; };
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);

struct Struct020d9850 { unsigned char byte0; unsigned char pad1[7]; unsigned char byte8; };
void Init020d9850(Struct020d9850* p);

int CheckField0NonZero(int* obj);

struct Obj02086b98;
int AreListedCombatantsBit0Set(Obj02086b98* o);

// USA: func_0201bdac
ARM void DispatchField0x744FlagsAndNotify(unsigned char* src) {
    GameState* bs = GameState::GetInstance();
    unsigned char* ov = (unsigned char*)func_ov017_0218b5b0();
    TailList020469b4* list = *(TailList020469b4**)(ov + 0x3000 + kOffset6fc);
    void* table = func_0202ae18();
    void* ptr2a04 = GetPtrField0x2a04(bs);

    if (!IsField0Null((void**)list)) return;
    if (!IsAxisIntZero((AxisFloats0203b5f8*)ov, 0)) return;
    if (!IsAxisIntZero((AxisFloats0203b5f8*)ov, 1)) return;

    unsigned char flags = *(src + 0x2000 + kOffset744);
    if (flags & 1) {
        struct GrottoStruct* grotto = bs->GetGrottoStruct();
        grotto->unknown_9 = 2;
        TailNode020469b4* node = *(TailNode020469b4**)(ov + 0x3000 + kOffsetb68);
        func_ov017_021a9bc4(node, 0);
        int extra = 0;
        int b1 = *(src + 0x2000 + kOffset745);
        int b2 = *(src + 0x2000 + kOffset746);
        int h3 = *(unsigned short*)(src + 0x2700 + kOffset48);
        func_ov017_021a9a9c(node, b1, b2, h3, extra);
        AppendNodeToTail(list, node);
        *(src + 0x2000 + kOffset744) &= ~1;
        return;
    }
    if (flags & 2) {
        Struct020d9850* node = *(Struct020d9850**)(ov + 0x3000 + kOffsetbb8);
        Init020d9850(node);
        AppendNodeToTail(list, (TailNode020469b4*)node);
        *(src + 0x2000 + kOffset744) &= ~2;
        return;
    }
    if (flags & 4) {
        func_020ae53c(0);
        *(src + 0x2000 + kOffset744) &= ~4;
        return;
    }

    if (CheckField0NonZero((int*)table)) {
        if (AreListedCombatantsBit0Set((Obj02086b98*)ptr2a04) != 0 || (*(src + 0x2000 + kOffset744) & 8)) {
            func_ov017_021aa4cc(ov, 1);
        }
    }
    *(src + 0x2000 + kOffset744) = 0;
}
