#include <globaldefs.h>

#include "GameState/GameState.h"

int IsField0Null(void** obj);
extern "C" void _Z36CancelActionIfHeadIdMatches_02199e98Pv(void* obj);
extern "C" void* _Z17GetPtrField0x2a04P9GameState(GameState* gs);
int GetIntField0x260(void* obj);
int CheckField0xc4Low15BitsNonZero(struct BitField0203402c* p);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
unsigned char GetByteField0x252(void* obj);
int CheckSubstructByte0x7cPositive(signed char* obj);
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(struct Obj020397cc* obj, int arg1);
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v(void);
void OrBitsIntoField0(unsigned int* p, unsigned int mask);
extern "C" void func_ov017_021a5bac(unsigned char* base);
extern "C" void _Z39InitFieldArenaListsAndCounters_021996fcPh(unsigned char* base);
int TestFlagInSecondWord(unsigned short* obj, unsigned int mask);
extern "C" int _Z17TestFlags02046708P16FlagWord02046708j(struct FlagWord02046708* word, unsigned int mask);
extern "C" void func_ov017_021999fc(unsigned char* self);
int TestFlagMask(unsigned short* obj, int mask);

struct Entry_02199684 { unsigned char pad[0x14]; int val; unsigned char pad2[0x20 - 0x18]; };
extern "C" void _Z27FillEntriesEncoded_02199684P14Entry_02199684ii(Entry_02199684* arr, int count, int value);
extern "C" void _Z30ClearAndEncodeEntries_021996bcP14Entry_02199684i(Entry_02199684* arr, int count);

struct TileMap0204bc74;
extern "C" void func_0204bc74(TileMap0204bc74* obj, unsigned short tile, int x, int y, int w, int h, unsigned short palette);
struct List0204b0e8;
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(List0204b0e8* obj, void* buf);

struct BackgroundControlFields {
    unsigned short priority : 2;
    unsigned short tileBase : 4;
    unsigned short unused6 : 1;
    unsigned short colorMode : 1;
    unsigned short mapBase : 5;
    unsigned short wrap : 1;
    unsigned short size : 2;
};

extern unsigned short data_02114e30;

// USA: func_ov017_02199f08
extern "C" ARM void func_ov017_02199f08(unsigned char* self) {
#if defined(jpn)
    enum {regionalOffset0 = 0x3e60, regionalOffset1 = 0x3e54, regionalOffset2 = 0x3e58, regionalOffset3 = 0x294, regionalOffset4 = 0x3800, regionalOffset5 = 0xa90};
#else
    enum {regionalOffset0 = 0x4080, regionalOffset1 = 0x4074, regionalOffset2 = 0x4078, regionalOffset3 = 0xb4, regionalOffset4 = 0x3c00, regionalOffset5 = 0xcb0};
#endif

    struct HeadNode02046b24;
    if (IsField0Null((void**)*(struct HeadNode02046b24***)(self + 0x3000 + 0x6fc)) == 0) {
        _Z36CancelActionIfHeadIdMatches_02199e98Pv(self);
        return;
    }

    GameState* gs = GameState::GetInstance();
    gs->GetProtagonist();
    GameObject* actor = gs->GetUnknownGameObject();
    unsigned char* party = (unsigned char*)_Z17GetPtrField0x2a04P9GameState(gs);
    int mode = GetIntField0x260(actor);

    if (mode == -1) {
        if (CheckField0xc4Low15BitsNonZero((BitField0203402c*)actor) == 0 &&
            *(int*)(self + regionalOffset0) == 0) {
            if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2) &&
                GetByteField0x252(actor) &&
                (*(int*)((char*)actor + 0x18c) & 1) == 0 &&
                CheckSubstructByte0x7cPositive((signed char*)actor) == 0 &&
                *(short*)((char*)actor + 0xac) == 0) {
                _Z27CancelPendingAction020397ccP11Obj020397cci((Obj020397cc*)actor, 1);
                *(unsigned short*)((char*)actor + 0xb2) = 0;
                OrBitsIntoField0((unsigned int*)_Z27GetDataPtr02114e04_020d6c00v(), 0x400);
                func_ov017_021a5bac(self);

                volatile unsigned short* reg = (volatile unsigned short*)0x400000a;
                volatile short v1, v2;
                {
                    unsigned short raw = reg[0];
                    *(volatile unsigned short*)(*(BackgroundControlFields**)(self + 0x3000 + 0xca8)) = raw;
                    v1 = raw;
                    v1;
                }
                {
                    unsigned short raw = reg[1];
                    v2 = raw;
                    v2;
                    *(volatile unsigned short*)(*(BackgroundControlFields**)(self + 0x3000 + 0xcac)) = raw;
                    v2;
                }
                _Z39InitFieldArenaListsAndCounters_021996fcPh(self);
                *(int*)(self + regionalOffset0) = 1;
            }
            return;
        }
    }

    if (TestFlagInSecondWord(&data_02114e30, 2) != 0 ||
        *(short*)((char*)actor + 0xac) != 0 ||
        CheckField0xc4Low15BitsNonZero((BitField0203402c*)actor) != 0) {
        _Z36CancelActionIfHeadIdMatches_02199e98Pv(self);
        return;
    }

    if (mode != -1) {
        int i = 0;
        while (i < *(unsigned char*)(party + 0xf7c)) {
            unsigned char* e = party + i;
            GameObject* member = gs->GetPartyMemberByIndex(e[0xf78]);
            *(unsigned short*)((char*)member + 0xac) = 0;
            i++;
        }
    }

    if (_Z17TestFlags02046708P16FlagWord02046708j((FlagWord02046708*)_Z27GetDataPtr02114e04_020d6c00v(), 4) != 0) {
        _Z36CancelActionIfHeadIdMatches_02199e98Pv(self);
        return;
    }

    func_ov017_021999fc(self);

    Entry_02199684* e;
    int i;
    if (TestFlagMask(&data_02114e30, 2) != 0 && mode != -1) {
        _Z27FillEntriesEncoded_02199684P14Entry_02199684ii((Entry_02199684*)(self + regionalOffset3 + regionalOffset4), 2, 0x800);
        for (i = 0; i < 2; i++) {
            e = (Entry_02199684*)(self + regionalOffset3 + regionalOffset4) + i;
            func_0204bc74((TileMap0204bc74*)e, 0, 0, 0, 0x20, 0x19, 0);
            _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv((List0204b0e8*)e, 0);
        }
        _Z30ClearAndEncodeEntries_021996bcP14Entry_02199684i((Entry_02199684*)(self + regionalOffset3 + regionalOffset4), 2);
    }
}