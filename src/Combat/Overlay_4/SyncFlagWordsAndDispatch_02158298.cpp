#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { stateOffset = 0x8c, battleOffset = 0xc, pointerOffset = 0x3500 };
#else
enum { stateOffset = 0x6c, battleOffset = 0x26c, pointerOffset = 0x3710 };
#endif

void ClearBitsInWord(unsigned int* obj, unsigned int mask);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);
void ClearBitsInField8(unsigned int* obj, unsigned int mask);
void SetBitsInWord(unsigned int* obj, unsigned int mask);
void SetBitsInField4(unsigned int* obj, unsigned int mask);
void SetBitsInField8(unsigned int* obj, unsigned int mask);

struct S_e828;
extern "C" void _Z14SetFieldAt0x7eP6S_e828s(struct S_e828* p, unsigned short v);

void SetByteField0x253(void* obj);

extern "C" void* func_02012fe4(void);

void* GetDataPtr02114e04_020d6c00(void);
struct FlagWord020466f4;
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);

struct Masks021707d8_02158298 { unsigned int m0; unsigned int m4; unsigned int m8; unsigned short mc; };
struct Data021707d8_02158298 { char pad[8]; struct Masks021707d8_02158298* ptr; };
extern struct Data021707d8_02158298 data_ov004_021707d8;

struct BitField5d00c_02158298 { char pad[0xc]; unsigned short lo13 : 13; unsigned short hi3 : 3; };
struct Outer26c_02158298 { char pad[0x5d00]; struct BitField5d00c_02158298 area; };

// USA: func_ov004_02158298  (semantic: SyncFlagWordsAndDispatch_02158298)
#pragma optimize_for_size off
extern "C" ARM int func_ov004_02158298(void) {
    GameState* battle = GameState::GetInstance();
    unsigned int* word = (unsigned int*)((int)func_ov017_0218b5b0());
    ClearBitsInWord(word, ~0);
    ClearBitsInField4(word, ~0);
    ClearBitsInField8(word, ~0);
    SetBitsInWord(word, data_ov004_021707d8.ptr->m0);
    SetBitsInField4(word, data_ov004_021707d8.ptr->m4);
    SetBitsInField8(word, data_ov004_021707d8.ptr->m8);

    void* p = func_02012fe4();
    if (!p) return 0;
    p = (char*)p + stateOffset;
    if (!p) return 0;
    _Z14SetFieldAt0x7eP6S_e828s((struct S_e828*)p, data_ov004_021707d8.ptr->mc);

    SetByteField0x253(battle->GetUnknownGameObject());

    struct Outer26c_02158298* outer = (struct Outer26c_02158298*)((char*)battle + battleOffset);
    outer->area.lo13 &= ~0x20;

    ClearFlags020466f4((struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0xf);

    unsigned char* p2 = *(unsigned char**)((char*)word + pointerOffset);
    if (p2[2] != 0) {
        p2[0x139] = 1;
    }
    return 0;
}
