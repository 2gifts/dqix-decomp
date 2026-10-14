#include <globaldefs.h>

int ApplyElemFieldsSlot1(void* obj);
int ApplyElemFieldsSlot2(void* obj);
int ApplyElemFieldsSlot3(void* obj);
int ApplyElemFieldsSlot4(void* obj);
int ApplyElemFieldsSlot5(void* obj);
int ApplyElemFieldsSlot6(void* obj);
int ApplyElemFieldsSlot7_0217819c(void* obj);
int ApplyElemFieldsSlot8(void* obj);
int IsField0x118Equal2(void* obj);
void RunElemFieldsIfField_02176498_02176498(void* obj, int flag);
void ApplyElemFieldsSlot14_021788d8(void* obj, int a, int b);
int ApplyElemFieldsSlot15(void* obj, int a, int b);
int ApplyElemFieldsSlot16(void* obj, int a, int b);
int ApplyElemFieldsSlot17(void* obj, int a, int b);
void ApplyElemFieldsSlot18_02179a14(void* obj, int a, int b);
void ApplyElemFieldsSlot21_02179c6c(void* obj, int id);
extern "C" void func_ov000_0217a0a4(void* obj);
void ApplyElemFieldsSlot19_0217a628(void* obj, int a, int b);

// USA: func_ov000_02177038
extern "C" ARM void func_ov000_02177038(void* obj, int arg, int slot, int arg2, int arg3) {
    if (*(int*)((char*)obj + 0x118) == 0) {
        return;
    }
    switch (slot) {
    case 1:
        ApplyElemFieldsSlot1(obj);
        break;
    case 2:
        ApplyElemFieldsSlot2(obj);
        break;
    case 3:
        ApplyElemFieldsSlot3(obj);
        break;
    case 4:
        ApplyElemFieldsSlot4(obj);
        break;
    case 5:
        ApplyElemFieldsSlot5(obj);
        break;
    case 6:
        ApplyElemFieldsSlot6(obj);
        break;
    case 7:
        ApplyElemFieldsSlot7_0217819c(obj);
        break;
    case 8:
        ApplyElemFieldsSlot8(obj);
        break;
    case 13:
        if (arg != 0) {
            RunElemFieldsIfField_02176498_02176498((void*)arg, IsField0x118Equal2(obj));
        }
        break;
    case 14:
        ApplyElemFieldsSlot14_021788d8(obj, arg, arg3);
        break;
    case 15:
        ApplyElemFieldsSlot15(obj, arg2, arg3);
        break;
    case 16:
        ApplyElemFieldsSlot16(obj, arg2, arg3);
        break;
    case 17:
        ApplyElemFieldsSlot17(obj, arg2, arg3);
        break;
    case 18:
    case 19:
    case 20:
        ApplyElemFieldsSlot18_02179a14(obj, arg, arg2);
        break;
    case 21:
        ApplyElemFieldsSlot21_02179c6c(obj, arg);
        break;
    case 23:
        func_ov000_0217a0a4(obj);
        break;
    case 25:
        ApplyElemFieldsSlot19_0217a628(obj, arg, arg3);
        break;
    }
}
