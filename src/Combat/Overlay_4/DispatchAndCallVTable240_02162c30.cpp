#include <globaldefs.h>


int HasCombatantWithFlag_0215f74c_0215f74c(int unused, int combatantId);
extern "C" void func_ov004_0215fdfc(void*);
extern "C" void func_ov004_0215eb40(void*);
extern "C" void func_ov011_021848a0(void* obj, int val);
void CallVTableFnAt240_021f66bc(void* a, int key, void* arg3);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern struct Obj0205eaa0 data_02108760;

extern unsigned char data_ov004_021707e8;
extern unsigned char data_ov004_02170b90;

#define D021707e8 ((char*)&data_ov004_021707e8)
#define D02170b90 ((char*)&data_ov004_02170b90)

// USA: func_ov004_02162c30
// JPN: func_ov004_021632cc
extern "C" ARM int func_ov004_02162c30(void* a) {
#if defined(jpn)
    if (*(unsigned char*)(D021707e8 + 0xb) == 1) return 0;
#else
    if (*(unsigned char*)(D021707e8 + 0) == 1) return 0;
#endif

    void* combatant = *(void**)(D021707e8 + 0x1c);
    if (!HasCombatantWithFlag_0215f74c_0215f74c((int)a, (int)combatant)) {
        func_ov004_0215fdfc(a);
        return 0;
    }

#if defined(jpn)
    *(unsigned char*)(D021707e8 + 0xb) = 1;
    switch (*(unsigned char*)(D021707e8 + 6) - 0x64) {
#else
    *(unsigned char*)(D021707e8 + 0) = 1;
    switch (*(unsigned char*)(D021707e8 + 7) - 0x64) {
#endif
    case 0:
#if defined(jpn)
        *(unsigned char*)(D021707e8 + 4) = *(signed char*)(D021707e8 + 0);
#else
        *(unsigned char*)(D021707e8 + 6) = *(signed char*)(D021707e8 + 5);
#endif
        func_ov011_021848a0(a, 0x65);
        break;
    case 1:
#if defined(jpn)
        *(unsigned char*)(D021707e8 + 4) = *(unsigned char*)(D02170b90 + 0x23f);
#else
        *(unsigned char*)(D021707e8 + 6) = *(unsigned char*)(D02170b90 + 0x23f);
#endif
        func_ov011_021848a0(a, 0x66);
        break;
    case 2:
#if defined(jpn)
        *(unsigned char*)(D021707e8 + 4) = *(unsigned char*)(D02170b90 + 0x47f);
#else
        *(unsigned char*)(D021707e8 + 6) = *(unsigned char*)(D02170b90 + 0x47f);
#endif
        func_ov004_0215eb40(a);
        func_ov011_021848a0(a, 0x67);
        break;
    case 3:
#if defined(jpn)
        *(unsigned char*)(D021707e8 + 4) = 1;
#else
        *(unsigned char*)(D021707e8 + 6) = 1;
#endif
        func_ov011_021848a0(a, 0x68);
        break;
    case 4:
#if defined(jpn)
        *(unsigned char*)(D021707e8 + 4) = *(signed char*)(D021707e8 + 5);
        *(unsigned char*)(D021707e8 + 7) = *(unsigned char*)(D021707e8 + 9);
#else
        *(unsigned char*)(D021707e8 + 6) = *(signed char*)(D021707e8 + 9);
        *(unsigned char*)(D021707e8 + 8) = *(unsigned char*)(D021707e8 + 3);
#endif
        func_ov011_021848a0(a, 0x64);
        break;
    }

    *(unsigned char*)(D02170b90 + 0x23c) = 0;
    *(unsigned char*)(D02170b90 + 0x47c) = 0;
#if defined(jpn)
    *(unsigned char*)(D021707e8 + 8) = 0;
#else
#endif
    *(unsigned char*)(D021707e8 + 0xb) = 0;
#if defined(jpn)
#else
    *(unsigned char*)(D021707e8 + 0) = 0;
#endif
    CallVTableFnAt240_021f66bc(a, 0x84, (void*)1);
    DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
    return 0;
}
