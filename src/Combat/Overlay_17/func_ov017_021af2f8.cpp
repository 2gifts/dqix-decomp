#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct {
    char pad0[0xfc0];
    int fieldFC0;
};

struct SearchEntry_021af2f8 {
    unsigned short unk0;
    unsigned short active : 1;
};

struct SearchStruct0202c1a4;
struct FlagWord020466f4;
struct BitArrayObj0205e854;

extern "C" SearchStruct* func_0202ae18(void);
SearchEntry_021af2f8* GetEntryBySignedByteIndex(SearchStruct* obj, int value);
void* GetData02100044(void);
int TestFlagBitAt0xe(SearchStruct* obj, int value);
int GetGlobalField0x10(void);
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v(void);
extern "C" void _Z18ClearFlags020466f4P16FlagWord020466f4j(FlagWord020466f4* word, unsigned int mask);
int* GetGlobal02109030(void);
extern "C" void _Z33ResetAndSetFlag0x3c9Bit0_020939dcPv(void* obj);
extern "C" void func_02094030(int*, short, short, signed char);
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* obj);
int TestMaskBitBySignedByteIndex(SearchStruct* obj, int value);
int TestFlag0SetAndFlag1Clear(unsigned short* flags, int mask);
void SetBitsInWord(unsigned int* obj, unsigned int mask);
extern "C" void func_0202b0f4(void* obj);
extern "C" void _Z29ClearTwoBytesAtField_02195748Ph(unsigned char* base);
extern "C" void _Z42SetFlag1ForFlagombatants_02192594_02192594v(unsigned int* obj);
void* FillBitArray0x1524WithFF(BitArrayObj0205e854* obj);
void ClearBitsInWord(unsigned int* obj, unsigned int mask);

extern unsigned short data_02114e30;

struct Obj021af2f8 {
    unsigned char pad0;
    unsigned char field1;
    unsigned char pad2[6];
    unsigned char field8;
    unsigned char pad9[6];
    signed char fieldF;
    signed char field10;
};

// USA: func_ov017_021af2f8
extern "C" ARM unsigned char func_ov017_021af2f8(Obj021af2f8* obj) {
    GameState::GetInstance();
    unsigned int* flags = (unsigned int*)func_ov017_0218b5b0();
    SearchStruct* search = func_0202ae18();
    GetEntryBySignedByteIndex(search, 0);
    BitArrayObj0205e854* bits = (BitArrayObj0205e854*)GetData02100044();

    if (TestFlagBitAt0xe(search, 0) != 0 || GetGlobalField0x10() == 8) {
        _Z18ClearFlags020466f4P16FlagWord020466f4j((FlagWord020466f4*)_Z27GetDataPtr02114e04_020d6c00v(), 0x8020);
        int* g = GetGlobal02109030();
        _Z33ResetAndSetFlag0x3c9Bit0_020939dcPv(g);
        func_02094030(g, 4, -1, 0);
        return 3;
    }

    int done = 0;
    if (GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search) == 0) {
        done = 1;
    } else {
        for (int i = 0; i < 4; i++) {
            if (i == GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search)) {
                continue;
            }
            if (TestMaskBitBySignedByteIndex(search, i) == 0) {
                continue;
            }
            SearchEntry_021af2f8* entry = GetEntryBySignedByteIndex(search, i);
            if (entry == 0) {
                continue;
            }
            if (entry->active == 0) {
                done = 1;
                break;
            }
        }
        if (obj->field10 != GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search)) {
            obj->fieldF = 0;
        }
    }

    if (obj->fieldF == -1 || done) {
        if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2)) {
            obj->fieldF = -1;
            SetBitsInWord(flags, 2);
            func_0202b0f4(search);
            _Z29ClearTwoBytesAtField_02195748Ph((unsigned char*)flags);
            _Z42SetFlag1ForFlagombatants_02192594_02192594v(flags);
            FillBitArray0x1524WithFF(bits);
            ClearBitsInWord(flags, 0x40);
            obj->field1 = 1;
        }
    } else if (obj->fieldF == 1) {
        if (search->fieldFC0 == 0) {
            obj->field1 = 1;
        }
    } else {
        SetBitsInWord(flags, 2);
        func_0202b0f4(search);
        _Z29ClearTwoBytesAtField_02195748Ph((unsigned char*)flags);
        _Z42SetFlag1ForFlagombatants_02192594_02192594v(flags);
        FillBitArray0x1524WithFF(bits);
        ClearBitsInWord(flags, 0x40);
        obj->field1 = 1;
    }
    return obj->field8;
}
