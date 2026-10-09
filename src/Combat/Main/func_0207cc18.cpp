#include <globaldefs.h>
struct Save0207cc18 { char pad[0x8c]; unsigned char bits[1]; };
struct Entry0207cc18 {
    char pad[8];
    unsigned int type:4, unused8:28;
    unsigned int unusedc:12, key:11, unusedc23:9;
};
struct S_a04c8;
struct S_a0494;
struct BattleBlock0207cc18 { char data[0xb0]; };
static inline int IsType0207cc18(unsigned char type) { return type <= 7; }
static inline int IsTypeRange0207cc18(unsigned char type) { return type >= 8 && type <= 9; }
extern "C" Save0207cc18* func_0205ec34(void*);
int TestBitInByteArray(int, unsigned char*, int);
void SetOrClearBitInArray(void*, unsigned char*, int, int);
extern "C" int _Z23LoadBattleBlock020ac4c0Pv(void*);
void AddClamped11BitFieldAt0x14(S_a04c8*, unsigned int);
void AddClamped9BitFieldMidAt0x14(S_a0494*, unsigned int);
int CopyInBattleField0x7540(void*);
// USA: func_0207cc18
extern "C" ARM void func_0207cc18(void* obj, Entry0207cc18* entry) {
    if (entry) {
        Save0207cc18* save = func_0205ec34(obj);
        int key = (unsigned short)entry->key;
        if (key > 0) {
            int index = key + 0xc76;
            if (!TestBitInByteArray((int)save, save->bits, index)) {
                SetOrClearBitInArray(save, save->bits, index, 1);
                BattleBlock0207cc18 block;
                _Z23LoadBattleBlock020ac4c0Pv(&block);
                unsigned char type = entry->type;
                if (IsType0207cc18(type))
                    AddClamped11BitFieldAt0x14((S_a04c8*)&block, 1);
                else if (IsTypeRange0207cc18(type))
                    AddClamped9BitFieldMidAt0x14((S_a0494*)&block, 1);
                CopyInBattleField0x7540(&block);
            }
        }
    }
}
