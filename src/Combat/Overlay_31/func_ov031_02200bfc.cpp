#include <globaldefs.h>
#include "System/Interrupts.h"
#include "System/Timing.h"

struct AddressState02200bfc { char pad[0x50]; unsigned int address; };
struct AddressEntry02200bfc { unsigned int address; unsigned char hardware[6]; unsigned short timestamp; };
struct AddressTime02200bfc { unsigned short timestamp; char pad[10]; };
extern AddressState02200bfc data_ov031_0224c980;
extern unsigned char data_ov031_0224ce68[6];
extern unsigned char data_ov031_02249684[6];
extern AddressEntry02200bfc data_ov031_0224ca00[8];
extern AddressTime02200bfc data_ov031_0224ca0a[8];
int IsMaskComplementSet_02200754(unsigned int);
int IsHighNibbleE_02200790(unsigned int);

// USA: func_ov031_02200bfc
extern "C" ARM unsigned char* func_ov031_02200bfc(unsigned int address) {
    unsigned int index;
    int irqState = DisableIRQInterrupts();
    unsigned char* hardware = NULL;
    if (address == 0x7f000001 || address == data_ov031_0224c980.address) hardware = data_ov031_0224ce68;
    else if (IsMaskComplementSet_02200754(address) || IsHighNibbleE_02200790(address)) hardware = data_ov031_02249684;
    else {
        AddressEntry02200bfc* entry = data_ov031_0224ca00;
        index = 0;
        do {
            if (address == entry->address) {
                unsigned int time = GetCurrentTimestamp() >> 16;
                data_ov031_0224ca0a[index].timestamp = time;
                hardware = data_ov031_0224ca00[index].hardware;
                break;
            }
            index++;
            entry++;
        } while (index < 8);
    }
    SetIRQInterruptState(irqState);
    return hardware;
}
