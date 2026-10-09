#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void* func_02012fe4(void);
extern "C" int _Z19IsIdInRange020981e4ii(int a, int id);
extern "C" void* func_ov011_021845f8(void* a, int b);

struct MenuState021707e8 {
    char pad0[0xc];
    void* bufC;
    char pad10[8];
    void* buf18;
    char pad1c[0xc];
    void* buf28;
};

extern MenuState021707e8 data_ov004_021707e8;

static inline int GetZoneId(char* zone) {
    int id = *(unsigned short*)zone;
    return id;
}

// USA: func_ov004_02163304
extern "C" ARM int func_ov004_02163304(void* self) {
    int kind = 3;
    char* zone = (char*)func_02012fe4();
    char* grotto = zone + 0x840;
    if (grotto != NULL && _Z19IsIdInRange020981e4ii((int)grotto, GetZoneId(zone))) {
        kind = 7;
    }
    char* node = (char*)func_ov011_021845f8(self, kind);
    SafeAllocator* alloc = (SafeAllocator*)(node + 4);

    data_ov004_021707e8.buf18 = alloc->Allocate(0x1000);
    memset(data_ov004_021707e8.buf18, 0, 0x1000);
    data_ov004_021707e8.bufC = alloc->Allocate(0x800);
    memset(data_ov004_021707e8.bufC, 0, 0x800);
    data_ov004_021707e8.buf28 = alloc->Allocate(0x80);
    memset(data_ov004_021707e8.buf28, 0, 0x80);
    return 0;
}
