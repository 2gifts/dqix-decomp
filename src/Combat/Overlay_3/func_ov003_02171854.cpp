#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue732_62E = 0x62e };
enum { kRegionValue72C_628 = 0x628 };
enum { kRegionValue71C_618 = 0x618 };
enum { kRegionValue720_61C = 0x61c };
enum { kRegionValue724_620 = 0x620 };
#else
enum { kRegionValue732_62E = 0x732 };
enum { kRegionValue72C_628 = 0x72c };
enum { kRegionValue71C_618 = 0x71c };
enum { kRegionValue720_61C = 0x720 };
enum { kRegionValue724_620 = 0x724 };
#endif


extern "C" void* func_0202ae18(void);
extern "C" int func_0202b000(void* obj);
extern "C" void func_0202b0f4(void* p);
extern int SetStateToThreeAndDispatch0202b800(int* p);
extern "C" void func_0202c360(void* self, int value);
extern "C" void func_0202b2f0(void* obj);
void CopyBattleTailToObjField0x102c(void* obj);

struct SearchStruct;
extern void RemoveSearchEntry0202c21c(struct SearchStruct* obj, int value);
extern "C" void func_0202c288(void* obj);
extern "C" unsigned int _u32_div_f(unsigned int a, unsigned int b);

// USA: func_ov003_02171854
// JPN: func_ov003_02170ba0
extern "C" ARM void func_ov003_02171854(char* self) {
    GameState* battle = GameState::GetInstance();
    void* search = func_0202ae18();
    GameObject* combatant = battle->GetProtagonist();

    int r = func_0202b000(search);
    if (r != 0) {
        if (r == 3) {
            return;
        }
        func_0202b0f4(search);
        self[0] = 0xa;
        return;
    }

    SetStateToThreeAndDispatch0202b800((int*)search);
    func_0202c360(search, *(int*)((char*)combatant + 0x134));
    func_0202b2f0(search);
    CopyBattleTailToObjField0x102c(search);
    RemoveSearchEntry0202c21c((struct SearchStruct*)search, 0xf);
    func_0202c288(search);

    int v = (rand() % 4 + 2) * 500;
    *(int*)(self + 4) = v;

    signed char b732 = *(volatile signed char*)(self + kRegionValue732_62E);
    unsigned int half = (unsigned int)v >> 1;
    unsigned int q = _u32_div_f(half * b732, 3);
    *(int*)(self + 4) = q + half;

    *(int*)(self + kRegionValue72C_628) = 0;
    *(int*)(self + kRegionValue71C_618) = 0;
    *(int*)(self + kRegionValue720_61C) = 0;
    *(int*)(self + kRegionValue724_620) = 0;
    self[0] = 5;
}
