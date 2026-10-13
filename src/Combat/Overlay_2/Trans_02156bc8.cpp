#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Pair0209a338;

extern const char* data_020f2a0c;
extern const char* data_020f2a18;
extern char data_ov002_0216cf21[];
extern char data_ov002_0216cf39[];
void ClearField00209a804(int*);
void ClearFirstTwoWords0209a338(Pair0209a338*);

// USA: func_ov002_02156bc8  (semantic: Trans_02156bc8)
extern "C" ARM void func_ov002_02156bc8(char* self) {
    if (*(unsigned int*)(self + 0x247c) & 0x10) {
        return;
    }
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    loader->AddFence();
    *(int*)(self + 0x1ba4) = loader->QueueLoadFileInGP2(data_020f2a18, data_020f2a0c, 0);
    *(int*)(self + 0x1ba8) = loader->QueueLoadFile(data_ov002_0216cf21, 0);
    *(int*)(self + 0x1bac) = loader->QueueLoadFile(data_ov002_0216cf39, 0);
    ClearField00209a804((int*)(self + 0x2444));
    ClearFirstTwoWords0209a338((Pair0209a338*)(self + 0x243c));
    *(unsigned int*)(self + 0x247c) |= 0x10;
}
