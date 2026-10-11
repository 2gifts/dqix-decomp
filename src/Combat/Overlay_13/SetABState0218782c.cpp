#if defined(jpn)
#define R(j,u) (j)
#define func_ov013_021846a0 func_ov013_021856dc
#define func_ov013_02184d80 func_ov013_02185db4
#define func_ov013_02186160 func_ov013_02187178
#define func_ov013_021864f0 func_ov013_02187820
#define func_ov013_02186590 func_ov013_021878c0
#define func_ov013_0218678c func_ov013_02187ab8
#define func_ov013_0218683c func_ov013_02187b68
#define func_ov013_02186bd4 func_ov013_02187f00
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


// USA: func_ov013_0218782c  (semantic: SetABState0218782c)
extern "C" ARM void func_ov013_0218782c(void* obj, int a, int b) {
    char* o = (char*)obj;
    if (o[R(0x53,0x67)] == a && (unsigned char)o[R(0x54,0x68)] == (unsigned int)b) return;

    int valid = (a >= 0 && a <= 3);
    if (!valid) return;
    if ((unsigned int)b >= 5) return;

    o[R(0x53,0x67)] = (char)a;
    o[R(0x54,0x68)] = (char)b;

    if (*(int*)(o + R(0x48,0x5c)) >= 0) {
        int p = (int)BackgroundLoader::GetInstance();
        ((BackgroundLoader*)(p))->RemoveTask((int)(*(int*)(o + R(0x48,0x5c))));
        *(int*)(o + R(0x48,0x5c)) = -1;
    }

    ((unsigned char*)o)[R(0x55,0x69)] |= 1;
    o[R(0x52,0x66)] = 0;
}
