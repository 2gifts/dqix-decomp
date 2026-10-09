#include <globaldefs.h>
struct Panel020e1cdc { char pad[0x38]; unsigned char x, y, width, height; };
struct Object020e1cdc { const void* staging; Panel020e1cdc* panel; unsigned char count; };
int CallFunc020e0434With02153694(int);
extern "C" int func_020420e8(int, unsigned char);
extern "C" void func_020e1b2c(Object020e1cdc*, int);
extern "C" int func_020e1f1c(Object020e1cdc*);
extern "C" void func_020e2110(Object020e1cdc*);
void UpdateObj020e15f8Entry(char*, int, int, int, int, unsigned char, unsigned char);
extern "C" void func_020e23f4(Object020e1cdc*);
void FreeVRAMStagingMemory(const void*);
// USA: func_020e1cdc
extern "C" ARM int func_020e1cdc(Object020e1cdc* obj, int arg) {
    if (!obj->panel) return 1;
    obj->panel->x = 0xc2;
    obj->panel->y = 0x48;
    obj->panel->width = 0x3c;
    obj->panel->height = 0x2c;
    int first = CallFunc020e0434With02153694(27);
    int second = CallFunc020e0434With02153694(28);
    int width = func_020420e8(first, 1);
    int otherWidth = func_020420e8(second, 1);
    if (width < otherWidth) width = otherWidth;
    int span = width + 24;
    obj->panel->x = 256 - (span + 2);
    obj->panel->width = span;
    func_020e1b2c(obj, arg);
    if (func_020e1f1c(obj)) {
        obj->count = 0;
        func_020e2110(obj);
        UpdateObj020e15f8Entry((char*)obj, 0, 12, 8, first, 9, 1);
        UpdateObj020e15f8Entry((char*)obj, 1, 12, 24, second, 11, 1);
        func_020e23f4(obj);
        if (obj->staging) FreeVRAMStagingMemory(obj->staging);
        return 0;
    }
    return 1;
}
