#include <globaldefs.h>

int ApplyElemFieldsSlot1(void* obj);
int ApplyElemFieldsSlot2(void* obj);
int ApplyElemFieldsSlot3(void* obj);
int ApplyElemFieldsSlot4(void* obj);
int ApplyElemFieldsSlot5(void* obj);
int ApplyElemFieldsSlot6(void* obj);
extern "C" int _Z29ApplyElemFieldsSlot7_0217819cPv(void* obj);
int ApplyElemFieldsSlot8(void* obj);
int IsField0x118Equal2(void* obj);
extern "C" void _Z38RunElemFieldsIfField_02176498_02176498Pvi(void* obj, int flag);
extern "C" void _Z30ApplyElemFieldsSlot14_021788d8Pvii(void* obj, int a, int b);
extern "C" int _Z21ApplyElemFieldsSlot15Pv(void* obj, int a, int b);
extern "C" int _Z21ApplyElemFieldsSlot16Pv(void* obj, int a, int b);
extern "C" int _Z21ApplyElemFieldsSlot17Pv(void* obj, int a, int b);
extern "C" void _Z30ApplyElemFieldsSlot18_02179a14Pvii(void* obj, int a, int b);
extern "C" void _Z30ApplyElemFieldsSlot21_02179c6cPvi(void* obj, int id);
extern "C" void func_ov000_0217a0a4(void* obj);
extern "C" void _Z30ApplyElemFieldsSlot19_0217a628Pvii(void* obj, int a, int b);

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
        _Z29ApplyElemFieldsSlot7_0217819cPv(obj);
        break;
    case 8:
        ApplyElemFieldsSlot8(obj);
        break;
    case 13:
        if (arg != 0) {
            _Z38RunElemFieldsIfField_02176498_02176498Pvi((void*)arg, IsField0x118Equal2(obj));
        }
        break;
    case 14:
        _Z30ApplyElemFieldsSlot14_021788d8Pvii(obj, arg, arg3);
        break;
    case 15:
        _Z21ApplyElemFieldsSlot15Pv(obj, arg2, arg3);
        break;
    case 16:
        _Z21ApplyElemFieldsSlot16Pv(obj, arg2, arg3);
        break;
    case 17:
        _Z21ApplyElemFieldsSlot17Pv(obj, arg2, arg3);
        break;
    case 18:
    case 19:
    case 20:
        _Z30ApplyElemFieldsSlot18_02179a14Pvii(obj, arg, arg2);
        break;
    case 21:
        _Z30ApplyElemFieldsSlot21_02179c6cPvi(obj, arg);
        break;
    case 23:
        func_ov000_0217a0a4(obj);
        break;
    case 25:
        _Z30ApplyElemFieldsSlot19_0217a628Pvii(obj, arg, arg3);
        break;
    }
}
