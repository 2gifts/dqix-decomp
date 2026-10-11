#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov000_02161318(void* obj, int id);
int GetField0x3acValue(GameState* battleStruct);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern int data_02108760;
struct Obj02171d90;
extern "C" void func_ov000_02171d90(struct Obj02171d90* obj, int key);
extern "C" void func_ov000_02170db0(void* obj);

// USA: func_ov000_02174428
extern "C" ARM void func_ov000_02174428(void* obj, int id, int val100, int param3,
                                          signed char param4, short param5, signed char param6, unsigned short param7) {
    void* r4 = func_ov000_02161318(obj, id);
    if (!r4) return;
    GameState* bs = GameState::GetInstance();
    int f3ac = GetField0x3acValue(bs);
    if (id != f3ac && val100 == 0x64) {
        signed char off = *(signed char*)((char*)r4 + 0x18);
        signed char pval = *(signed char*)((char*)r4 + off + 0x10);
        if (val100 != pval) {
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 0x19, 0);
        }
    }
#if defined(jpn)
    enum { guardOffset = 0x47e };
#else
    enum { guardOffset = 0x43e };
#endif
    if (*((unsigned char*)r4 + guardOffset)) return;
    int valid = 0;
    int val4c = *(int*)((char*)r4 + 0x4c);
    if (val4c >= 0 && val4c <= 3) valid = 1;
    if (!valid) return;
    signed char off2 = *(signed char*)((char*)r4 + 0x18);
    signed char* p10 = (signed char*)((char*)r4 + off2 + 0x10);
    *p10 = (signed char)val100;
    *((unsigned char*)r4 + 0x1c) = (unsigned char)param3;
    *((unsigned char*)r4 + 0x1d) = (unsigned char)param4;
    *(short*)((char*)r4 + 0x2c) = param5;
    *((unsigned char*)r4 + 0x2e) = (unsigned char)param6;
    *(unsigned short*)((char*)r4 + 0x26) = param7;
    func_ov000_02171d90((struct Obj02171d90*)r4, param5);
    func_ov000_02170db0(r4);
}
