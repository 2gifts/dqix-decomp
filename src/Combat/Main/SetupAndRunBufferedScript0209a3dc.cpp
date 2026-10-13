#include <globaldefs.h>

#if defined(jpn)
#define data_020f1628 data_020f1790
#endif

#if defined(jpn)
#define func_0209a3dc func_0209c130
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Resource/Script.h"

extern char data_020f1628[];
extern Script::OpcodeLookupEntry data_020f1608[];

struct Ctx0209a3dc { void* field0; };
extern struct Ctx0209a3dc* data_02109ba4;

// USA: func_0209a3dc  (semantic: SetupAndRunBufferedScript0209a3dc)
extern "C" ARM void func_0209a3dc(struct Ctx0209a3dc* ctx, void* value) {
    unsigned int count;
    Script script;

    BackgroundLoader::AddLockGlobal();

    void* header = LoadFileIntoMemory(data_020f1628, data_0211e33c, &count);
    if (header != NULL) {
        ctx->field0 = value;
        data_02109ba4 = ctx;
        script.Initialize();
        script.SetOpcodeLookup(data_020f1608);
        script.Load(header, count);
        script.Execute();
        data_02109ba4 = NULL;
    }
    BackgroundLoader::RemoveLockGlobal();
}
