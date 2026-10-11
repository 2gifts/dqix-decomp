#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif


#if defined(jpn)
extern "C" void func_0203b8e4(char* obj);
#define InitStruct0203be8c func_0203b8e4
#else
void InitStruct0203be8c(char* obj);
#endif

// USA: func_0203c304
ARM void ResetBattleState0203c304(char* obj) {
    int i;
    for (i = 0; i < (IS_JPN ? 0x60 : 0x20); i++) {
        InitStruct0203be8c(obj + 4 + i * (IS_JPN ? 0x10 : 0x28));
    }
    *(int*)obj = 0;
    *(short*)(obj + (IS_JPN ? 0x612 : 0x512)) = 0;
    *(int*)(obj + (IS_JPN ? 0x604 : 0x504)) = 1;
    *(int*)(obj + (IS_JPN ? 0x60c : 0x50c)) = 0;
    *(int*)(obj + (IS_JPN ? 0x608 : 0x508)) = 0;
    *(short*)(obj + (IS_JPN ? 0x610 : 0x510)) = (IS_JPN ? 0 : 4);
}
