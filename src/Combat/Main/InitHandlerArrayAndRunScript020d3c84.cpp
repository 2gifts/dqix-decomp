#include <globaldefs.h>
#if defined(jpn)
#define HANDLER_BYTES 0xa0
#define data_021142c4 data_02113f64
#define data_020f22d0 data_020f243c
#else
#define HANDLER_BYTES 0xb4
#endif
#include "std_library_functions.h"

struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);

struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);

struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, int*);

struct HandlerSlotArray020d3c84 {
    unsigned char entries[HANDLER_BYTES];
    int count;
};
extern struct HandlerSlotArray020d3c84* data_021142c4;
extern int data_020f22d0;

// USA: func_020d3c84
ARM void InitHandlerArrayAndRunScript020d3c84(struct HandlerSlotArray020d3c84* arr, struct StreamHeader* buffer, int length) {
    char local[0x430];
    memset(arr, 0, HANDLER_BYTES);
    arr->count = 0;
    data_021142c4 = arr;
    _ZN6Script10InitializeEv((struct ResetStruct*)local);
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_020f22d0);
    _ZN6Script4LoadEPKvj((struct StreamState*)local, buffer, length);
    _ZN6Script7ExecuteEv((struct Struct02030774*)local);
}

// JPN: 0x020d56e8
