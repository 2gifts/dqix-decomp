#include <globaldefs.h>

extern "C" void func_0200ef44(void* obj, int count, int size, void* initFn);
char* InitStruct0203be78(char* obj);
void ResetBattleState0203c304(char* obj);

// USA: func_0203c75c
ARM char* InitBattleObject0203c75c(char* obj) {
    ResetBattleState0203c304(obj + 0x10);
    ResetBattleState0203c304(obj + 0x10);
#if defined(jpn)
    func_0200ef44(obj + 0x14, 0x60, 0x10, (void*)InitStruct0203be78);
#else
    func_0200ef44(obj + 0x14, 0x20, 0x28, (void*)InitStruct0203be78);
#endif
    return obj;
}
