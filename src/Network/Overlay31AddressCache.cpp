#include <globaldefs.h>
#include "System/Memory.h"
#include "System/Timing.h"

struct Overlay31AddressEntry {
    unsigned int address;
    unsigned char identifier[6];
    unsigned short timestamp;
};
struct Overlay31AddressState {
    char unknown[0x50];
    unsigned int localAddress;
};
extern Overlay31AddressState data_ov031_0224c980;
extern Overlay31AddressEntry data_ov031_0224ca00[8];
struct Overlay31TimestampView { unsigned short timestamp; char stride[10]; };
extern Overlay31TimestampView data_ov031_0224ca0a[];
extern "C" {
int _Z29IsSpecialOrMaskMatch_022006f0i(unsigned int);
int _Z22IsHighNibbleE_02200790j(unsigned int);

ARM void func_ov031_02200e38(const void* identifier, unsigned int address, int allowInsert) {
    if (address == 0x7f000001 || address == data_ov031_0224c980.localAddress) return;
    if (!_Z29IsSpecialOrMaskMatch_022006f0i(address)) return;
    if (_Z22IsHighNibbleE_02200790j(address)) return;
    unsigned short timestamp = GetCurrentTimestamp() >> 16;
    {
    unsigned int i = 0;
    Overlay31AddressEntry* entry = data_ov031_0224ca00;
    do {
        if (address == entry->address) {
            data_ov031_0224ca0a[i].timestamp = timestamp;
            VectorizedInvertedMemcpy(identifier, data_ov031_0224ca00[i].identifier, 6);
            return;
        }
        ++i;
        ++entry;
    } while (i < 8);
    }
    if (!allowInsert) return;
    unsigned int selected;
    unsigned short oldestAge = 0;
    selected = oldestAge;
    Overlay31AddressEntry* entry = data_ov031_0224ca00;
    unsigned int i = 0;
    do {
        if (!entry->address) {
            selected = i;
            break;
        }
        unsigned int age = timestamp - entry->timestamp;
        if (oldestAge < static_cast<short>(age)) {
            selected = i;
            oldestAge = age;
        }
        ++i;
        ++entry;
    } while (i < 8);
    data_ov031_0224ca00[selected].address = address;
    VectorizedInvertedMemcpy(identifier, data_ov031_0224ca00[selected].identifier, 6);
    data_ov031_0224ca0a[selected].timestamp = timestamp;
}
}
