// JPN: func_ov017_0218dccc
#if defined(jpn)
enum { RegionOffset6fc = 0x4ec, RegionOffset718 = 0x508 };
#else
enum { RegionOffset6fc = 0x6fc, RegionOffset718 = 0x718 };
#endif

#include <globaldefs.h>
#include "Graphics/LightingManager.h"
#include "GameState/GameState.h"

extern "C" void* func_02012fe4(void);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c508(void* obj);
extern "C" void* func_0205ec34(void);
void SetOrClearBitInArray(void* unused, unsigned char* array, int bit, int value);

struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);
unsigned char GetByte0x4(char* obj);
int GetWord0x7f6c(void* obj);

struct ScaledAccum02010240;

void EnqueueEventTag147_021cdaa0(void);
int IsField600B4Zero_021b8b54(void* obj);

struct Data02107930 { unsigned char pad0[0x94]; float accum; int tableIndex; };


struct Struct020fb3f0 { unsigned char pad0[8]; unsigned char* field8; };
struct NibbleByte0218d0ec { unsigned char lowNibble : 4; unsigned char highNibble : 4; };

// USA: func_ov017_0218d0ec  (semantic: SyncTableIndexAndAccumIfEligible_0218d0ec)
extern "C" ARM void func_ov017_0218d0ec(unsigned char* ov) {
    GameState* bs = GameState::GetInstance();
    Struct020fb3f0* p1 = (Struct020fb3f0*)func_02012fe4();
    void* p2 = func_0202ae18();

    if (GetHeadNodeIdOrMinusOne(*(struct HeadNode02046b24***)(ov + 0x3000 + RegionOffset6fc)) == 3) return;
    if (GetByte0x4((char*)bs) == 6) return;
    if (GetWord0x7f6c(bs) == 5) return;

    NibbleByte0218d0ec* nb = (NibbleByte0218d0ec*)(p1->field8 + 0xc);
    unsigned int nibble = nb->lowNibble;
    int flagNibble = 1;
    if (nibble != 0 && nibble != 7) flagNibble = 0;

    int idx1 = bs->GetTimeOfDay();
    if (flagNibble != 0) {
        ((GameState*)((struct ScaledAccum02010240*)bs))->AdvanceDayTimer();
    }

    int idx2 = bs->GetTimeOfDay();
    if (func_0202c508(p2) != 0 && idx1 != idx2) {
        EnqueueEventTag147_021cdaa0();
    }

    if (GetHeadNodeIdOrMinusOne(*(struct HeadNode02046b24***)(ov + 0x3000 + RegionOffset6fc)) == 0xa) {
        if (IsField600B4Zero_021b8b54(*(void**)(ov + 0x3000 + RegionOffset718)) != 0) return;
    }
    if (GetHeadNodeIdOrMinusOne(*(struct HeadNode02046b24***)(ov + 0x3000 + RegionOffset6fc)) == 4) return;
    if (GetHeadNodeIdOrMinusOne(*(struct HeadNode02046b24***)(ov + 0x3000 + RegionOffset6fc)) == 0x16) return;

    Data02107930* d = (Data02107930*)LightingManager::GetInstance();
    int prevIdx = d->tableIndex;
    if (prevIdx != bs->GetTimeOfDay()) {
        if (bs->GetTimeOfDay() == 1 || bs->GetTimeOfDay() == 0) {
            void* base = func_0205ec34();
            SetOrClearBitInArray(base, (unsigned char*)base + 0x8c, 0x1140, 1);
        }
    }

    d->accum = bs->GetDayTimer();
    d->tableIndex = bs->GetTimeOfDay();
}
