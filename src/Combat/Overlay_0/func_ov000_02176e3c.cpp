#include <globaldefs.h>

struct Struct_0205d81c;

struct Elem_0205d81c {
    char pad0[0xc5];
    unsigned char flags;
};

struct BattleMenu {
    char pad0[0x118];
    int mode;
    char pad11c[0x188 - 0x11c];
    char elements[1];
};

Elem_0205d81c* FindElementByC40205d81c(Struct_0205d81c* list, int key);
void ApplyElemFieldsSlot1_ov000_02177330(void*);
void ApplyElemFieldsSlot2_ov000_02177558(void*);
void ApplyElemFieldsSlot3_ov000_02177798(void*);
void ApplyElemFieldsSlot4_ov000_02177a7c(void*);
void ApplyElemFieldsSlot5_ov000_02177cb8(void*);
void ApplyElemFieldsSlot6_ov000_02177f28(void*);
void ApplyElemFieldsSlot7_0217819c(void*);
void ApplyElemFieldsSlot8_ov000_021785fc(void*);
int IsField0x118Equal2_ov000_0217542c(void*);
void RunElemFieldsIfField_02176498_02176498(void* obj, int flag);
void ApplyElemFieldsSlot14_021788d8(void*, int, int);
void ApplyElemFieldsSlot15_ov000_02178cbc(void* menu, int a, int b);
void ApplyElemFieldsSlot16_ov000_02179128(void* menu, int a, int b);
void ApplyElemFieldsSlot17_ov000_021795e0(void* menu, int a, int b);
void ApplyElemFieldsSlot18_02179a14(void*, int, int);
void ApplyElemFieldsSlot21_02179c6c(void*, int);
extern "C" void func_ov000_0217a0a4(BattleMenu* menu, int a);
void ApplyElemFieldsSlot19_0217a628(void*, int, int);

// USA: func_ov000_02176e3c
extern "C" ARM void func_ov000_02176e3c(BattleMenu* menu, int arg, int slot, int arg2, int arg3, unsigned char highlight) {
    Elem_0205d81c* elem = FindElementByC40205d81c(
        (Struct_0205d81c*)menu->elements, (unsigned char)slot);
    if (elem == 0) {
        return;
    }
    int savedMode = menu->mode;
    int alt = (elem->flags & 2) ? 1 : 0;
    menu->mode = 1;
    if (alt) {
        menu->mode = 2;
    }
    if (highlight) {
        elem->flags |= 0x40;
    } else {
        elem->flags &= ~0x40;
    }
    switch (slot) {
    case 1:
        ApplyElemFieldsSlot1_ov000_02177330(menu);
        break;
    case 2:
        ApplyElemFieldsSlot2_ov000_02177558(menu);
        break;
    case 3:
        ApplyElemFieldsSlot3_ov000_02177798(menu);
        break;
    case 4:
        ApplyElemFieldsSlot4_ov000_02177a7c(menu);
        break;
    case 5:
        ApplyElemFieldsSlot5_ov000_02177cb8(menu);
        break;
    case 6:
        ApplyElemFieldsSlot6_ov000_02177f28(menu);
        break;
    case 7:
        ApplyElemFieldsSlot7_0217819c(menu);
        break;
    case 8:
        ApplyElemFieldsSlot8_ov000_021785fc(menu);
        break;
    case 13:
        if (arg != 0) {
            RunElemFieldsIfField_02176498_02176498((void*)arg, IsField0x118Equal2_ov000_0217542c(menu));
        }
        break;
    case 14:
        ApplyElemFieldsSlot14_021788d8(menu, arg, arg3);
        break;
    case 15:
        ApplyElemFieldsSlot15_ov000_02178cbc(menu, arg2, arg3);
        break;
    case 16:
        ApplyElemFieldsSlot16_ov000_02179128(menu, arg2, arg3);
        break;
    case 17:
        ApplyElemFieldsSlot17_ov000_021795e0(menu, arg2, arg3);
        break;
    case 18:
    case 19:
    case 20:
        ApplyElemFieldsSlot18_02179a14(menu, arg, arg2);
        break;
    case 21:
        ApplyElemFieldsSlot21_02179c6c(menu, arg);
        break;
    case 23:
        func_ov000_0217a0a4(menu, arg);
        break;
    case 25:
        ApplyElemFieldsSlot19_0217a628(menu, arg, arg3);
        break;
    }
    menu->mode = savedMode;
}
