#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct02030774;

int LoadFileIntoMemory(const char*, void*, unsigned int*);

extern char data_0211e33c;
extern char data_020ef418;

struct Container0201f040 {
    int f0;
    void* field4;
    void* field8;
};
extern struct Container0201f040 data_020fdc40;

// USA: func_0201f040
ARM void RegisterAndRunBufferedScript0201f040(void* p0, void* p1, struct StreamHeader* headerIn, unsigned int countIn) {
    unsigned int count = countIn;
    int flag = 0;
    struct StreamHeader* header = headerIn;
    char buf[0x430];

    if (header == NULL) {
        int usedFlag;
        BackgroundLoader::AddLockGlobal();
        usedFlag = flag;
        flag = 1;
        header = (struct StreamHeader*)LoadFileIntoMemory((const char*)usedFlag, &data_0211e33c, &count);
    }
    if (header != NULL) {
        data_020fdc40.field4 = p1;
        data_020fdc40.field8 = p0;
        ((Script*)((struct ResetStruct*)buf))->Initialize();
        ((Script*)buf)->SetOpcodeLookup((Script::OpcodeLookupEntry*)&data_020ef418);
        ((Script*)((struct StreamState*)buf))->Load(header, count);
        ((Script*)((struct Struct02030774*)buf))->Execute();
        data_020fdc40.field8 = 0;
        data_020fdc40.field4 = 0;
    }
    if (flag) {
        BackgroundLoader::RemoveLockGlobal();
    }
}
