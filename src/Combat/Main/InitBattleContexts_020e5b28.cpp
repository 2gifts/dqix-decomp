#include <globaldefs.h>

#pragma define_section initcode ".init" RX

extern "C" void __register_global_object(void* obj, void* func, void* node);
void* InitReturnSelf0202c794(void* obj);
ARM void* InitReturnSelf0202c7a8(void* obj);
ARM void* ResetBattleArray0202c7bc(void* obj);
ARM void* ReleaseBattleArray0202c814(void* obj);

extern int data_020fefec;
extern int data_020fefe0;
extern int data_02100044;
extern int data_020fefd4;

// USA: func_020e5b28  (semantic: InitBattleContexts_020e5b28)
extern "C" __declspec(initcode) ARM void __sinit_020e5b28(void) {
    InitReturnSelf0202c794(&data_020fefec);
    __register_global_object(&data_020fefec, (void*)InitReturnSelf0202c7a8, &data_020fefe0);
    ResetBattleArray0202c7bc(&data_02100044);
    __register_global_object(&data_02100044, (void*)ReleaseBattleArray0202c814, &data_020fefd4);
}
