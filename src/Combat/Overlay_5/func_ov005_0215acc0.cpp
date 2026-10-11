#if defined(jpn)
#define R(j,u) (j)
#define func_02045f3c func_02046c78
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <Resource/GameResources.h>

struct Container020dedd0;
struct DigitSprite { short data[3]; };
struct CombatEntry { short key; signed char value; char pad[9]; int x; int y; char tail[8]; };
struct CombatDisplay { char pad0[0xdf4]; Container020dedd0* container; char pad1[R(0x1f10,0x1f98)]; CombatEntry entries[24]; char pad2[0xddc]; DigitSprite digits[20]; };
struct CombatObject { char pad[R(0x4f8,0x4fc)]; int index; };
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" void* _Z24FindElementByKey020dedd0P17Container020dedd0i(Container020dedd0*, int);
extern "C" CombatObject* _Z19GetField1c_021a193cPi(int*);
extern "C" int func_020dd4c4(signed char, void*);
#if defined(jpn)
extern "C" void func_02045f3c(void*, DigitSprite*, int, int, int, int, int, int);
#else
extern "C" void func_02045f3c(void*, DigitSprite*, int, int, int, int, int, int, int, int);
#endif
#define REG_GEOMETRY ((volatile unsigned int*)0x04000444)

// USA: func_ov005_0215acc0
extern "C" ARM void func_ov005_0215acc0(CombatDisplay* display) {
    void* renderer = _Z26GetGlobalField0x1c020421a0v();
    int y;
    int x;
    for (int i = 8; i < 24; i++) {
        CombatEntry* current = &display->entries[i];
        int key = current->key;
        if (key >= 0) {
            int value = current->value;
            x = current->x >> 12;
            y = current->y >> 12;
            int tens = current->value / 10;
            int ones = value % 10;
            int color = 0x7fff;
            if (current->key > 0) {
                void* entry = _Z24FindElementByKey020dedd0P17Container020dedd0i(display->container, (short)key);
                if (entry && func_020dd4c4((signed char)_Z19GetField1c_021a193cPi((int*)func_ov017_0218b5b0()->unknown_ptr_array_36fc[3])->index, entry)) color = 0x1ce7;
            }
            REG_GEOMETRY[0] = 0;
            REG_GEOMETRY[0x2f] = 1;
            REG_GEOMETRY[11] = 0;
            REG_GEOMETRY[11] = 0;
            REG_GEOMETRY[11] = 0xffc01000;
#if defined(jpn)
            if (tens) func_02045f3c(renderer, &display->digits[tens + 10], x + 11, y + 16, color, 8, 0, 0);
#else
            if (tens) func_02045f3c(renderer, &display->digits[tens + 10], x + 11, y + 12, color, 8, 0, 0, 0, 17);
#endif
#if defined(jpn)
            func_02045f3c(renderer, &display->digits[ones + 10], x + 17, y + 16, color, 8, 0, 0);
#else
            func_02045f3c(renderer, &display->digits[ones + 10], x + 17, y + 12, color, 8, 0, 0, 0, 17);
#endif
            REG_GEOMETRY[0x30] = 0;
            REG_GEOMETRY[1] = 1;
        }
    }
}
