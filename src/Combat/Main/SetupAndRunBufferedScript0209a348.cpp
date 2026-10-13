#include <globaldefs.h>

#if defined(jpn)
#define data_020f1628 data_020f1790
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Resource/Script.h"

extern char data_020f1628[];
extern Script::OpcodeLookupEntry data_020f15e8[];

struct Ctx0209a348 { void* field0; };
extern struct Ctx0209a348* data_02109ba4;

#if defined(jpn)
#define SetupAndRunBufferedScript0209a348 func_0209c09c
extern "C" ARM void func_0209c09c(struct Ctx0209a348* ctx, void* value);
#endif

// USA: func_0209a348
ARM void SetupAndRunBufferedScript0209a348(struct Ctx0209a348* ctx, void* value) {
    unsigned int count;
    Script script;

    BackgroundLoader::AddLockGlobal();

    void* header = LoadFileIntoMemory(data_020f1628, data_0211e33c, &count);
    if (header != NULL) {
        ctx->field0 = value;
        data_02109ba4 = ctx;
        script.Initialize();
        script.SetOpcodeLookup(data_020f15e8);
        script.Load(header, count);
        script.Execute();
        data_02109ba4 = NULL;
    }
    BackgroundLoader::RemoveLockGlobal();
}
