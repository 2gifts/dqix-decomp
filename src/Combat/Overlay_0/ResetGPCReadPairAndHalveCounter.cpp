#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/GPC.h"


// USA: func_ov000_0216638c
ARM void ResetGPCReadPairAndHalveCounter(void* unused, GPCReadPair* pair, int) {
    pair->Reset();
    BackgroundLoader::RemoveLockGlobal();
}
