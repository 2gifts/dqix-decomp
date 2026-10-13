#include <globaldefs.h>
#include "Resource/Script.h"
#if defined(jpn)
#include "Filesystem/NarcHandle.h"
#include "Filesystem/LowNitroHandle.h"
#include "Filesystem/FileAccessor.h"
extern const char data_ov017_021d8489[];
extern const char data_ov017_021d848d[];
#endif

struct Data_ov017_021d8438 {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char pad3;
    int fields[];
};
extern struct Data_ov017_021d8438 data_ov017_021d8438;

struct Data_ov017_021d7c54 {
    signed char byte0;
    signed char byte1;
};
extern struct Data_ov017_021d7c54 data_ov017_021d7c54;

#if defined(jpn)
extern "C" Script::OpcodeLookupEntry data_ov017_021d8434[];
#else
extern "C" Script::OpcodeLookupEntry data_ov017_021d7c58[];
#endif

// JPN: func_ov017_021bad0c
// USA: func_ov017_021ba810
extern "C" ARM int func_ov017_021ba810(const void* code, unsigned int length, int id, int a3, int a4, int a5, int a6) {
#if defined(jpn)
    NarcHandle archive;
    NitroVM file;
    char path[0x50];
#endif
    Script script;
#if defined(jpn)
    char recordName[4];
#endif
    if (id < 0 || id > 999) {
        return 0;
    }
#if defined(jpn)
    if (!archive.Initialize(data_ov017_021d8489, static_cast<const unsigned char*>(code))) return 0;
    NitroVM_Initialize(&file);
    unsigned int scriptLength;
    bool found;
    unsigned int fileIndex = 0;
    sprintf(recordName, data_ov017_021d848d, id);
    found = false;
    while (PrepareReadFileInNARCByID(&file, &archive, fileIndex)) {
        NitroVM_WriteOutFilePath(&file, path, sizeof(path));
        scriptLength = file.fileInfo.endOffset - file.fileInfo.startOffset;
        NitroVM_FinishRead(&file);
        if (strstr(path, recordName)) {
            found = true;
            break;
        }
        ++fileIndex;
    }
    if (!found) {
        archive.Destroy();
        return 0;
    }
    code = archive.GetFileByIndex(fileIndex);
#endif
    data_ov017_021d8438.fields[0] = a3;
    data_ov017_021d8438.fields[6] = id;
    data_ov017_021d8438.fields[1] = a4;
    data_ov017_021d8438.fields[3] = 0;
    data_ov017_021d8438.fields[4] = 0;
    data_ov017_021d8438.fields[5] = a5;
    data_ov017_021d8438.fields[7] = a6;
    data_ov017_021d8438.byte2 = 0;
    data_ov017_021d7c54.byte0 = -1;
    data_ov017_021d8438.byte0 = 0;
    data_ov017_021d8438.byte1 = 0;
    data_ov017_021d8438.fields[2] = 0;
    data_ov017_021d7c54.byte1 = -1;
    script.Initialize();
#if defined(jpn)
    script.SetOpcodeLookup(data_ov017_021d8434);
#else
    script.SetOpcodeLookup(data_ov017_021d7c58);
#endif
#if defined(jpn)
    script.Load(code, scriptLength);
#else
    script.Load(code, length);
#endif
    script.Execute();
#if defined(jpn)
    archive.Destroy();
#endif
    if (data_ov017_021d8438.fields[3] != 0) {
        return data_ov017_021d8438.fields[3];
    }
    return data_ov017_021d8438.fields[4];
}
