#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct02030774;

void* LoadFileIntoMemory(const char*, void*, unsigned int*);

struct Obj0218e098 {
    char pad[8];
    int field8;
};
extern struct Obj0218e098* data_ov016_0219d1bc;
extern char data_ov016_0219d054[];
extern char data_0211e33c[];
extern char data_ov016_0219d044[];

// USA: func_ov016_0218e098
ARM void RegisterObjectAndRunScript0218e098(struct Obj0218e098* param0, int param1) {
    unsigned int count;
    char local[0x430];

    param0->field8 = param1;
    data_ov016_0219d1bc = param0;
    BackgroundLoader::AddLockGlobal();

    struct StreamHeader* header = (struct StreamHeader*)LoadFileIntoMemory(data_ov016_0219d054, data_0211e33c, &count);
    if (header != 0) {
        ((Script*)((struct ResetStruct*)local))->Initialize();
        ((Script*)local)->SetOpcodeLookup((Script::OpcodeLookupEntry*)data_ov016_0219d044);
        ((Script*)((struct StreamState*)local))->Load(header, count);
        ((Script*)((struct Struct02030774*)local))->Execute();
    }
    BackgroundLoader::RemoveLockGlobal();
    param0->field8 = 0;
}
