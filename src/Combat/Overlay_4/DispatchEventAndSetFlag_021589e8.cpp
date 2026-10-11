#include <globaldefs.h>
#if defined(jpn)
#define R(j,u) (j)
#define func_ov017_021b213c func_ov017_021b2854
#else
#define R(j,u) (u)
#endif

#include "GameState/GameState.h"

struct Struct021707d8_021589e8 { char pad[8]; int* ptr; };
extern Struct021707d8_021589e8 data_ov004_021707d8;

extern "C" int func_ov017_021b213c(int, int);
int GetGlobalField0x1c020421a0();
void ReinitController02043204(char* obj);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void func_ov023_021f65d4(void* obj, int a, int b);

// USA: func_ov004_021589e8
ARM int DispatchEventAndSetFlag_021589e8(void* obj) {
    char* battle = (char*)GameState::GetInstance() + R(0xc, 0x26c) + 0x5c00;
    int a = *(int*)(battle + 0xf4);
    int b = data_ov004_021707d8.ptr[0x18 / 4];
    if (func_ov017_021b213c(a, b) != 0) {
        char* g = (char*)GetGlobalField0x1c020421a0();
        ReinitController02043204(g);
        func_ov011_021848a0(obj, 0x387);
    } else {
        func_ov011_021848a0(obj, 0x3a2);
    }
    func_ov023_021f65d4(obj, 2, 8);
    return 0;
}
