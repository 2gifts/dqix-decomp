#include <globaldefs.h>

#if defined(jpn)
#define data_020f1088 data_020f11ac
#define data_020f1048 data_020f116c
#endif

#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Resource/Script.h"

extern char data_020f1088;
extern char data_020f109e;
extern Script::OpcodeLookupEntry data_020f1048[];

struct Container02108efc {
    void* field0;
    int field4;
    int field8;
    void* fieldc;
};
extern struct Container02108efc data_02108efc;

// USA: func_02089de8
ARM void SetupHeaderAndRunBufferedScript02089de8(void* param0, void* param1, const char* param2) {
    BackgroundLoader::AddLockGlobal();
    unsigned int count;
    Script script;
    void* header;
    void* srcBuf = data_0211e33c;
    unsigned int* pCount = &count;
    if (param2 != 0) {
        header = LoadFileIntoMemory(param2, srcBuf, pCount);
    } else {
        #if defined(jpn)
        header = LoadFileIntoMemory(&data_020f1088, srcBuf, pCount);
#else
        header = ExtractFileFromGP2(&data_020f1088, &data_020f109e, pCount);
#endif
    }
    if (header != 0) {
        data_02108efc.field0 = param0;
        data_02108efc.fieldc = param1;
        data_02108efc.field8 = 0;
        data_02108efc.field4 = 0;
        script.Initialize();
        script.SetOpcodeLookup(data_020f1048);
        script.Load(header, count);
        script.Execute();
    }
    BackgroundLoader::RemoveLockGlobal();
}
