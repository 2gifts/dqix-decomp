#include <globaldefs.h>
#include "System/Memory.h"

struct AddressState02200ccc { char pad[0x50]; unsigned int address; };
struct AddressPacket02200ccc {
    unsigned char destination[6];
    unsigned char source[6];
    unsigned short type;
    unsigned char hardwareHigh;
    unsigned char hardwareLow;
    unsigned char protocolHigh;
    unsigned char protocolLow;
    unsigned short lengths;
    unsigned char operationHigh;
    unsigned char operationLow;
    unsigned char sender[6];
    unsigned short senderHigh;
    unsigned short senderLow;
    unsigned char target[6];
    unsigned short targetHigh;
    unsigned short targetLow;
};
extern AddressState02200ccc data_ov031_0224c980;
extern unsigned char data_ov031_0224ce68[6];
void CopyHeaderAndDispatch_02200850(void*, unsigned int, void*, unsigned int);

#define Swap16_02200ccc(value) (unsigned short)(((value) >> 8) | ((value) << 8))

// USA: func_ov031_02200ccc
extern "C" ARM void func_ov031_02200ccc(unsigned int address) {
    AddressPacket02200ccc packet;
    VectorizedMemset(&packet, 0, 42);
    VectorizedMemset(packet.destination, 255, 6);
    VectorizedInvertedMemcpy(data_ov031_0224ce68, packet.source, 6);
    packet.type = 0x0608;
    packet.hardwareLow = 1;
    packet.protocolHigh = 8;
    packet.lengths = 0x0406;
    packet.operationLow = 1;
    VectorizedInvertedMemcpy(data_ov031_0224ce68, packet.sender, 6);
    unsigned short targetHigh;
    unsigned short targetLow;
    unsigned int source = data_ov031_0224c980.address;
    unsigned short sourceHigh = source >> 16;
    unsigned short sourceLow = source;
    targetHigh = address >> 16;
    targetLow = address;
    packet.senderHigh = Swap16_02200ccc(sourceHigh);
    packet.senderLow = Swap16_02200ccc(sourceLow);
    packet.targetHigh = Swap16_02200ccc(targetHigh);
    packet.targetLow = Swap16_02200ccc(targetLow);
    CopyHeaderAndDispatch_02200850(&packet, 42, NULL, 0);
}
