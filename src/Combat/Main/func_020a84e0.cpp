#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { EntryListOffset = 0x8c };
#else
enum { EntryListOffset = 0x6c };
#endif

struct FlagWord02046708 { unsigned int flags; };

extern "C" void* _Z27GetDataPtr02114e04_020d6c00v(void);
extern "C" void* func_02012fe4(void);
extern "C" void* func_0205ec34(void);
void* GetElementStride0x74(unsigned char* obj, int index);
void* GetPtrField0x2a04(GameState* battleStruct);
extern "C" int _Z17TestFlags02046708P16FlagWord02046708j(struct FlagWord02046708* word, unsigned int mask);
int ForwardCombatantField0x44(void* self, int combatantId);
unsigned char GetField0x397cValue(GameState* battleStruct);
void SetByteFlagBitAndCombatantField0x6c(unsigned char* obj, int bit);
extern "C" void func_020a8c4c(void* obj, unsigned char axis);
extern "C" void func_020a8b0c(void* obj, int bit);
extern "C" void func_020a8d08(void* obj, int bit);
extern "C" void func_020a87d0(void* obj);
struct Obj020a8874 {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char byte3_pad;
    unsigned char flag_0x4;
    unsigned char mask_0x5;
};
extern "C" void _Z30NotifyOv017SlotCleared020a8874P11Obj020a8874(struct Obj020a8874* obj);
extern "C" void func_020a88e8(void* obj);
extern "C" void func_020aeb34(void);
int TestBitInByteArray(int unused, unsigned char* arr, int index);

// USA: func_020a84e0
// JPN: func_020a84e0
extern "C" ARM void func_020a84e0() {
    GameState* gs = GameState::GetInstance();
    func_ov017_0218b5b0();
    struct FlagWord02046708* fw = (struct FlagWord02046708*)_Z27GetDataPtr02114e04_020d6c00v();
    unsigned char* obj = (unsigned char*)func_02012fe4();
    int ctx = (int)func_0205ec34();
    unsigned char* list;
    int j;
    GameObject* po;
    int i = 0;
    for (;;) {
        unsigned char* entry = (unsigned char*)GetElementStride0x74(obj + EntryListOffset, i);
        i++;
        if (!entry) {
            break;
        }
        if (*(int*)(entry + 4) != 0xc) {
            continue;
        }
        unsigned char* sub = entry + 0x2c;
        list = (unsigned char*)GetPtrField0x2a04(gs);
        j = 0;
        while (j < *(unsigned char*)(list + 0xf7c)) {
            po = gs->GetPartyMemberByIndex(*(unsigned char*)(list + 0xf78 + j));
            if (po) {
                if (!_Z17TestFlags02046708P16FlagWord02046708j(fw, 0x200000) &&
                    ForwardCombatantField0x44(entry, *(short*)((char*)po + 4)) != 0) {
                    switch (sub[0]) {
                    case 2:
                        SetByteFlagBitAndCombatantField0x6c(sub, *(short*)((char*)po + 4) & 0xff);
                        break;
                    case 3:
                        func_020a8c4c(sub, *(short*)((char*)po + 4) & 0xff);
                        break;
                    }
                }
                switch (sub[0]) {
                case 2:
                    func_020a8b0c(sub, *(short*)((char*)po + 4) & 0xff);
                    break;
                case 3:
                    func_020a8d08(sub, *(short*)((char*)po + 4) & 0xff);
                    break;
                }
            }
            j++;
        }
        if (!_Z17TestFlags02046708P16FlagWord02046708j(fw, 0x200000) &&
            ForwardCombatantField0x44(entry, GetField0x397cValue(gs)) != 0) {
            if (sub[0] == 1) {
                func_020a87d0(sub);
            }
        } else {
            if (sub[0] == 1) {
                _Z30NotifyOv017SlotCleared020a8874P11Obj020a8874((struct Obj020a8874*)sub);
            }
        }
        if (sub[0] == 1) {
            func_020a88e8(sub);
        }
    }
    if (*(unsigned short*)obj != 0x1644) {
        return;
    }
    if (TestBitInByteArray(ctx, (unsigned char*)ctx + 0x8c, 0x384) == 0) {
        return;
    }
    func_020aeb34();
}
