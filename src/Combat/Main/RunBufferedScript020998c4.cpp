#include <globaldefs.h>
#if defined(jpn)
#define data_020f155c data_020f16c4
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct02030774;

void* LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* state, void* dataPtr);

struct Obj020995c0;
extern struct Obj020995c0* data_02109924;

extern char data_020f155c[];
extern char data_0211e33c[];
extern char data_020f1524[];

// USA: func_020998c4
ARM void RunBufferedScript020998c4(struct Obj020995c0* param0) {
    int count;
    char buf[0x430];

    BackgroundLoader::AddLockGlobal();

    struct StreamHeader* header = (struct StreamHeader*)LoadFileIntoMemory(data_020f155c, data_0211e33c, (unsigned int*)&count);
    if (header != 0) {
        data_02109924 = param0;
        ((Script*)((struct ResetStruct*)buf))->Initialize();
        _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(buf, data_020f1524);
        ((Script*)((struct StreamState*)buf))->Load(header, count);
        ((Script*)((struct Struct02030774*)buf))->Execute();
        data_02109924 = 0;
    }
    BackgroundLoader::RemoveLockGlobal();
}
