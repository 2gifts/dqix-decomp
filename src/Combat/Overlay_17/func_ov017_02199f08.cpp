#include <globaldefs.h>

#include "GameState/GameState.h"

int IsField0Null_02046b08(void** obj);
void CancelActionIfHeadIdMatches_02199e98(void* obj);
void* GetPtrField0x2a04_02010828(GameState* gs);
int GetIntField0x260_02039750(void* obj);
int CheckField0xc4Low15BitsNonZero(struct BitField0203402c* p);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);
unsigned char GetByteField0x252_02039820(void* obj);
int CheckSubstructByte0x7cPositive_020535c8(signed char* obj);
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);
void* GetDataPtr02114e04_020d6c00(void);
void OrBitsIntoField0_020466e4(unsigned int* p, unsigned int mask);
extern "C" void func_ov017_021a5bac(unsigned char* base);
void InitFieldArenaListsAndCounters_021996fc(unsigned char* base);
int TestFlagInSecondWord_02012468(unsigned short* obj, unsigned int mask);
int TestFlags02046708(struct FlagWord02046708* word, unsigned int mask);
extern "C" void func_ov017_021999fc(unsigned char* self);
int TestFlagMask_02012430(unsigned short* obj, int mask);

struct Entry_02199684 { unsigned char pad[0x14]; int val; unsigned char pad2[0x20 - 0x18]; };
void FillEntriesEncoded_02199684(Entry_02199684* arr, int count, int value);
void ClearAndEncodeEntries_021996bc(Entry_02199684* arr, int count);

struct TileMap0204bc74;
extern "C" void func_0204bc74(TileMap0204bc74* obj, unsigned short tile, int x, int y, int w, int h, unsigned short palette);
struct List0204b0e8;
void FlushAndDispatchList0204b0e8(List0204b0e8* obj, void* buf);

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
    if (IsField0Null_02046b08((void**)*(struct HeadNode02046b24***)(self + 0x3000 + 0x6fc)) == 0) {
        CancelActionIfHeadIdMatches_02199e98(self);
        return;
    }

    GameState* gs = GameState::GetInstance();
    gs->GetProtagonist();
    GameObject* actor = gs->GetUnknownGameObject();
    unsigned char* party = (unsigned char*)GetPtrField0x2a04_02010828(gs);
    int mode = GetIntField0x260_02039750(actor);

    if (mode == -1) {
        if (CheckField0xc4Low15BitsNonZero((BitField0203402c*)actor) == 0 &&
            *(int*)(self + regionalOffset0) == 0) {
            if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 2) &&
                GetByteField0x252_02039820(actor) &&
                (*(int*)((char*)actor + 0x18c) & 1) == 0 &&
                CheckSubstructByte0x7cPositive_020535c8((signed char*)actor) == 0 &&
                *(short*)((char*)actor + 0xac) == 0) {
                CancelPendingAction020397cc((Obj020397cc*)actor, 1);
                *(unsigned short*)((char*)actor + 0xb2) = 0;
                OrBitsIntoField0_020466e4((unsigned int*)GetDataPtr02114e04_020d6c00(), 0x400);
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
                InitFieldArenaListsAndCounters_021996fc(self);
                *(int*)(self + regionalOffset0) = 1;
            }
            return;
        }
    }

    if (TestFlagInSecondWord_02012468(&data_02114e30, 2) != 0 ||
        *(short*)((char*)actor + 0xac) != 0 ||
        CheckField0xc4Low15BitsNonZero((BitField0203402c*)actor) != 0) {
        CancelActionIfHeadIdMatches_02199e98(self);
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

    if (TestFlags02046708((FlagWord02046708*)GetDataPtr02114e04_020d6c00(), 4) != 0) {
        CancelActionIfHeadIdMatches_02199e98(self);
        return;
    }

    func_ov017_021999fc(self);

    Entry_02199684* e;
    int i;
    if (TestFlagMask_02012430(&data_02114e30, 2) != 0 && mode != -1) {
        FillEntriesEncoded_02199684((Entry_02199684*)(self + regionalOffset3 + regionalOffset4), 2, 0x800);
        for (i = 0; i < 2; i++) {
            e = (Entry_02199684*)(self + regionalOffset3 + regionalOffset4) + i;
            func_0204bc74((TileMap0204bc74*)e, 0, 0, 0, 0x20, 0x19, 0);
            FlushAndDispatchList0204b0e8((List0204b0e8*)e, 0);
        }
        ClearAndEncodeEntries_021996bc((Entry_02199684*)(self + regionalOffset3 + regionalOffset4), 2);
    }
}
