#include <globaldefs.h>
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct02030774;

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void* state, void* dataPtr);

struct DataStruct02109404_95870 {
    char pad0;
    unsigned char f1;
    unsigned char f2;
    char pad3[3];
    unsigned short f6;
};
extern struct DataStruct02109404_95870 data_02109404;
extern short data_020f13d8;
extern char data_020f13fc[];

// USA: func_02095870
ARM int RunBufferedScript02095870(void* unused, struct StreamHeader* buffer, int length, int flag, unsigned char* outByte) {
    char local[0x430];

    data_02109404.f6 = 0;
    data_02109404.f1 = 0;
    data_02109404.f2 = 0;
    data_020f13d8 = (short)flag;

    if (flag <= 0) {
        return 1;
    }

    ((Script*)((struct ResetStruct*)local))->Initialize();
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(local, data_020f13fc);
    ((Script*)((struct StreamState*)local))->Load(buffer, length);
    ((Script*)((struct Struct02030774*)local))->Execute();

    *outByte = data_02109404.f2;
    return 0;
}
