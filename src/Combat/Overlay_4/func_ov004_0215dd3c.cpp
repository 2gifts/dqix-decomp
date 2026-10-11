#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov004_02157128(void* a);
extern "C" int func_ov004_02157a28(void* a, int flag);
void* GetPtrField0x2a04(GameState* battleStruct);
extern "C" void func_02052d7c(void* combatant, int arg1, int arg2);
extern "C" void func_0207c378(void* a, int b, int c, int d);
struct Bytes8 { unsigned char b[8]; };
extern Bytes8 data_ov004_0216fb20;
extern int data_ov004_0216fc1c[];
struct Entry { unsigned int _p0; unsigned int _p4; unsigned int lowNibble : 4; unsigned int _r : 28; };
struct Bits { unsigned int lo : 27; unsigned int b27 : 1; unsigned int b28 : 1;
              unsigned int b29 : 1;  unsigned int hi : 2; };
struct Node { unsigned int w0; Bits f; };
struct FlagByte { unsigned char bit0 : 1; unsigned char _rest : 7; };
#if defined(jpn)

extern "C" GameObject* GetCombatantWithFlag0x100(GameState*, int);
#else
#endif

// USA: func_ov004_0215dd3c
// JPN: func_ov004_0215ec6c
extern "C" ARM int func_ov004_0215dd3c(void* a) {
    int prev = func_ov004_02157128(a);
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100(bs, prev);
    if (!combatant) return 0;
    void* ptr = GetPtrField0x2a04(bs);
    Bytes8 buf;
    buf = data_ov004_0216fb20;
    unsigned char flags[2];
    for (unsigned char i = 0; i < 8; i++) {
        unsigned char byte = buf.b[i];
        if (byte == 0xff) break;
#if defined(jpn)
        char* entry = (char*)(*(unsigned char**)((char*)combatant + 0x144) + 0x194) + byte * 0x20;
#else
        char* entry = (char*)(*(unsigned char**)((char*)combatant + 0x150) + 0x194) + byte * 0x20;
#endif
        if (entry) {
            char* p2 = *(char**)entry;
            if (p2) {
                if (!((Node*)p2)->f.b29) {
                    int bit27 = ((Node*)p2)->f.b27 ? 1 : 0;
                    flags[1] = ((Node*)p2)->f.b28 ? 1 : 0;
                    flags[0] = bit27;
#if defined(jpn)
                    unsigned int idx = ((FlagByte*)(*(unsigned char**)((char*)combatant + 0x144) + 0x49c))->bit0;
#else
                    unsigned int idx = ((FlagByte*)(*(unsigned char**)((char*)combatant + 0x150) + 0x49c))->bit0;
#endif
                    if (!flags[idx]) {
                        func_02052d7c(combatant, data_ov004_0216fc1c[i], -1);
                        if (entry) {
                            unsigned int lowNibble = ((Entry*)entry)->lowNibble;
                            short s18 = *(short*)(entry + 0x18);
                            func_0207c378((char*)ptr + 0x1d4, s18, 1, lowNibble);
                        }
                    }
                }
            }
        }
    }
    return func_ov004_02157a28(a, 1);
}
