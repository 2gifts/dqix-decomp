#include <globaldefs.h>
#if defined(jpn)
enum { kInitialFlags = 0x3000 };
#else
enum { kInitialFlags = 0x1000 };
#endif


extern char data_021056b4;
extern void* data_02105244;
void ResetBattleState0203c304(char* obj);

// USA: func_0203bd24
ARM void InitBattleContext0203bd24(char* obj) {
    *(int*)(obj + 0x8) = 0;
    *(unsigned char*)(obj + 0xc) = 1;
    *(unsigned char*)(obj + 0xd) = 1;
    *(int*)(obj + 0x0) = kInitialFlags;
    *(int*)(obj + 0x4) = 0xe0;
    ResetBattleState0203c304(obj + 0x10);
    *(void**)(obj + 0x10) = &data_021056b4;
    data_02105244 = obj + 0x10;
}
