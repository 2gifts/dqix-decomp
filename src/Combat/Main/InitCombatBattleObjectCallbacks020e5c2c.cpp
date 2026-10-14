#include <globaldefs.h>
#pragma define_section initcode ".init" RX

struct __register_global_object {
    struct __register_global_object* next;
    int b;
    int c;
};

char* InitCombatObject0203c73c(char* obj);
char* InitBattleObject0203c75c(char* obj);
extern "C" ARM void __register_global_object(int c, int b, struct __register_global_object* node);

extern void* data_02105ab4;
extern void* data_02105248;

// USA: func_020e5c2c
extern "C" __declspec(initcode) ARM void __sinit_020e5c2c(void) {
    InitCombatObject0203c73c((char*)&data_02105ab4);
    __register_global_object((int)&data_02105ab4, (int)(void*)InitBattleObject0203c75c, (struct __register_global_object*)&data_02105248);
}
