#include <globaldefs.h>

int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
struct Obj02184c68;
extern "C" void func_ov011_02184c68(struct Obj02184c68* obj, void* val);

extern unsigned short data_02114e30;
extern unsigned char data_02114e54;
extern int data_02108760;

// USA: func_ov011_021884d0  (semantic: TriggerDispatchIfFlagOrByte55_021884d0)
extern "C" ARM int func_ov011_021884d0(struct Obj02184c68* obj) {
    int state = 0;
    if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x7f3) || *(&data_02114e54 + 0x55)) {
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
        state = 1;
    }
    func_ov011_02184c68(obj, (void*)state);
    return 1;
}
