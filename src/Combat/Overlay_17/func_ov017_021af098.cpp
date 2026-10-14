#include <globaldefs.h>
#include "Combat/SearchEntry.h"
#include "GameState/GameState.h"

struct SearchStruct;

struct SearchStruct0202c1a4;
struct FlagWord020466f4;
struct BitArrayObj0205e854;
struct BitArrayObj0205e870;

extern "C" SearchStruct* func_0202ae18(void);
void* GetData02100044_0202ae24(void);
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* obj);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short* flags, int mask);
void SetBitsInWord_0203b4a0(unsigned int* obj, unsigned int mask);
extern "C" void func_0202b0f4(void* obj);
void ClearTwoBytesAtField_02195748(unsigned char* base);
void SetFlag1ForFlagombatants_02192594_02192594(unsigned char* base);
void* FillBitArray0x1524WithFF(BitArrayObj0205e854* obj);
void ClearBitsInWord_0203b4b0(unsigned int* obj, unsigned int mask);
int TestFlagBitAt0xe_0202c578(SearchStruct* obj, int value);
int GetGlobalField0x10_0202d6a8(void);
void* GetDataPtr02114e04_020d6c00(void);
void ClearFlags020466f4(FlagWord020466f4* word, unsigned int mask);
int* GetGlobal02109030_020936f8(void);
void ResetAndSetFlag0x3c9Bit0_020939dc(void* obj);
extern "C" void func_02094030(int* obj, short a, short b, signed char c);
void SetSearchFlagBitAt0xc_0202c1e8(SearchStruct* obj, int value);
void* FillBitArray0x1524WithZero(BitArrayObj0205e870* obj);
void SetBitInArray0x1524_0205e7dc(unsigned char* obj, int index);
void EnqueueEventTag43_021cc0cc(void);

extern unsigned short data_02114e30;

struct Obj021af098 {
    unsigned char pad0;
    unsigned char complete;
    unsigned char pad2[6];
    unsigned char state;
    unsigned char pad9[6];
    signed char fieldF;
    signed char previousSlot;
    unsigned char pad11;
    unsigned short elapsedMilliseconds;
};

// USA: func_ov017_021af098
extern "C" ARM unsigned char func_ov017_021af098(Obj021af098* obj) {
    GameState* gs = GameState::GetInstance();
    unsigned int* flags = (unsigned int*)func_ov017_0218b5b0();
    SearchStruct* search = func_0202ae18();
    BitArrayObj0205e854* bits = (BitArrayObj0205e854*)GetData02100044_0202ae24();

    if (GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search) == 0) {
        GetEntryBySignedByteIndex_0202c178(search, 0);
        if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 2)) {
            obj->fieldF = -1;
            SetBitsInWord_0203b4a0(flags, 2);
            func_0202b0f4(search);
            ClearTwoBytesAtField_02195748((unsigned char*)flags);
            SetFlag1ForFlagombatants_02192594_02192594((unsigned char*)flags);
            FillBitArray0x1524WithFF(bits);
            ClearBitsInWord_0203b4b0(flags, 0x40);
            obj->complete = 1;
        } else if (TestFlagBitAt0xe_0202c578(search, 0) != 0 || GetGlobalField0x10_0202d6a8() == 8) {
            ClearFlags020466f4((FlagWord020466f4*)GetDataPtr02114e04_020d6c00(), 0x8020);
            int* g = GetGlobal02109030_020936f8();
            ResetAndSetFlag0x3c9Bit0_020939dc(g);
            func_02094030(g, 4, -1, 0);
            return 3;
        } else {
            obj->elapsedMilliseconds = obj->elapsedMilliseconds + gs->GetEffectiveDeltaTime();
            if (obj->elapsedMilliseconds > 5000) {
                obj->fieldF = 0;
                SetBitsInWord_0203b4a0(flags, 2);
                func_0202b0f4(search);
                ClearTwoBytesAtField_02195748((unsigned char*)flags);
                SetFlag1ForFlagombatants_02192594_02192594((unsigned char*)flags);
                FillBitArray0x1524WithFF(bits);
                ClearBitsInWord_0203b4b0(flags, 0x40);
                obj->complete = 1;
                return obj->state;
            }
        }
        return obj->state;
    }

    if (GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search) >= 4) {
        obj->fieldF = 0;
        SetBitsInWord_0203b4a0(flags, 2);
        func_0202b0f4(search);
        ClearTwoBytesAtField_02195748((unsigned char*)flags);
        SetFlag1ForFlagombatants_02192594_02192594((unsigned char*)flags);
        FillBitArray0x1524WithFF(bits);
        ClearBitsInWord_0203b4b0(flags, 0x40);
        obj->complete = 1;
        return obj->state;
    }

    obj->previousSlot = GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search);
    SetSearchFlagBitAt0xc_0202c1e8(search, GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search));
    ClearBitsInWord_0203b4b0(flags, 2);
    FillBitArray0x1524WithZero((BitArrayObj0205e870*)bits);
    SetBitInArray0x1524_0205e7dc((unsigned char*)bits, 0x2c);
    SetBitInArray0x1524_0205e7dc((unsigned char*)bits, 0x2a);
    SetBitInArray0x1524_0205e7dc((unsigned char*)bits, 0x2e);
    SetBitInArray0x1524_0205e7dc((unsigned char*)bits, 0x3d);
    SetBitInArray0x1524_0205e7dc((unsigned char*)bits, 0x33);
    EnqueueEventTag43_021cc0cc();
    obj->elapsedMilliseconds = 0;
    return 2;
}
