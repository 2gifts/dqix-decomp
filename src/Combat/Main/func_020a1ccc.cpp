#include <globaldefs.h>
#include "System/Mutex.h"
#include "Resource/ResourceMutex.h"
#include "Filesystem/OverlayFSManagement.h"

extern "C" void _Z22DispatchByFlag020d9834i(int flag);
extern "C" void _Z25CallAndReturnTrue020cd584v(OverlayMetadata* meta);

extern volatile int data_01ffd348;
extern volatile unsigned char data_01ffd344;
extern volatile unsigned char data_01ffd340;
extern signed char data_01ffd364;
extern Mutex data_01ffd34c;
extern struct OverlayMetadata data_01ffd394[35];

struct Entry020e8f20 {
    int col;
    int pad;
};
extern struct Entry020e8f20 data_020e8f20[];

// USA: func_020a1ccc
extern "C" ARM int func_020a1ccc(unsigned int id) {
    int ok = 0;
    if (id < 0x23) {
    struct Entry020e8f20* table;
    int rowIdx = data_01ffd348;
    table = data_020e8f20;

    if (data_01ffd344) {
        LockMutex(&data_01ffd34c);
    }
#if defined(jpn)
    volatile signed char* row = &data_01ffd364 + rowIdx * 6;
#else
    signed char* row = ((__typeof__(&data_01ffd364))0x01FFD364) + rowIdx * 6;
#endif
    int col1 = table[id].col;
    row[col1] = id | 0x40;
    if (data_01ffd344) {
        UnlockMutex(&data_01ffd34c);
    }

    while (data_01ffd340) {
        _Z22DispatchByFlag020d9834i(0);
    }

    data_01ffd340 = 1;
    LockResourceMutex();
    _Z25CallAndReturnTrue020cd584v(&data_01ffd394[id]);
    UnlockResourceMutex();
    data_01ffd340 = 0;

    if (data_01ffd344) {
        LockMutex(&data_01ffd34c);
    }
    int col2 = table[id].col;
    row[col2] = -1;
    if (data_01ffd344) {
        UnlockMutex(&data_01ffd34c);
    }

    ok = 1;
    }
    return ok;
}
