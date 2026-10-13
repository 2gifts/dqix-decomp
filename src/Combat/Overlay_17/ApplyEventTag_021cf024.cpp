#include <globaldefs.h>
#include "Resource/GameResources.h"

#if defined(jpn)
enum { kWorkByteOffset = 0x7938 };
#else
enum { kWorkByteOffset = 0x7748 };
#endif


#if defined(jpn)
#define ApplyEventTag_021cf024 func_ov017_021cf4cc
#endif

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
void SetByteFieldOffset5950_02163338(unsigned char* obj, unsigned char val);

struct LocalEvt021cf024 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned char field6;
    unsigned char field7;
};

struct WorkRecord {
    unsigned char unknown0[8];
    unsigned short key;
};

struct EventPairWork {
    unsigned char unknown0[kWorkByteOffset];
    unsigned char unknownEventByte;
};

// USA: func_ov017_021cf024
#if defined(jpn)
extern "C"
#endif
ARM void ApplyEventTag_021cf024(int unused0, LocalEvt021cf024* evt, int unused2, unsigned char* base) {
    void* table = ((GameResources*)base)->unknown_ptr_3718;
    WorkRecord* record = (WorkRecord*)func_ov017_021b8478(table);
    EventPairWork* work = (EventPairWork*)func_ov017_021b8468(table);
    if (work == NULL) {
        return;
    }
    if (record->key != evt->field4) {
        return;
    }
    SetByteFieldOffset5950_02163338((unsigned char*)work, evt->field6);
    work->unknownEventByte = evt->field7;
}
