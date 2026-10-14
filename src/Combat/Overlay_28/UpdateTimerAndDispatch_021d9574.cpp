#include <globaldefs.h>

struct PMFClass021d8d40;

struct Timer021d9574 {
    char pad0[0x80];
    unsigned char f80;
    char pad81[3];
    long long f84;
    long long f8c;
    int f94;
    int f98;
    unsigned char f9c;
    char pad9d[3];
    long long fa0;
    long long fa8;
};

long long GetCurrentTimestamp(void);
extern "C" void _Z29DispatchHandlerTable_021d8d40P16PMFClass021d8d40t(
    struct PMFClass021d8d40* obj, int delta);

// USA: func_ov028_021d9574  (semantic: UpdateTimerAndDispatch_021d9574)
extern "C" ARM void func_ov028_021d9574(struct Timer021d9574* obj) {
    if (obj->f80 == 0) {
        return;
    }
    obj->f94 = obj->f98;
    obj->f8c = GetCurrentTimestamp();
    obj->f98 = (int)((unsigned long long)(obj->f8c - obj->f84) * 0x3c / 0x7fd88);
    if (obj->f98 == obj->f94) {
        return;
    }
    _Z29DispatchHandlerTable_021d8d40P16PMFClass021d8d40t(
        (struct PMFClass021d8d40*)obj, obj->f98 - obj->f94);
    obj->f9c = (obj->f9c == 0);
    obj->fa8 = obj->f8c - obj->fa0;
}
