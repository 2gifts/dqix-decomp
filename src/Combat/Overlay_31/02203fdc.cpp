#include <globaldefs.h>
#include "System/Memory.h"

struct Network32 {
    unsigned short high;
    unsigned short low;
};
struct BootpHeader {
    unsigned short operationAndHardwareType;
    unsigned char hardwareAddressLength;
    unsigned char hops;
    Network32 transactionId;
    unsigned short seconds;
    unsigned short flags;
    Network32 clientAddress;
    Network32 offeredAddress;
    Network32 serverAddress;
    Network32 relayAddress;
    unsigned char clientHardwareAddress[16];
    char serverName[64];
    char bootFile[128];
};
struct DhcpContext {
    unsigned char unknown0[0x50];
    unsigned int clientAddress;
    unsigned char unknown54[0x14];
    unsigned long long randomState;
    unsigned long long randomMultiplier;
    unsigned long long randomIncrement;
};
extern DhcpContext data_ov031_0224c980;
extern unsigned char data_ov031_0224ce68[];
extern const char data_ov031_02249698[];

enum DhcpOption {
    DhcpHostName = 12,
    DhcpMessageType = 53,
    DhcpParameterRequestList = 55,
    DhcpClientIdentifier = 61
};

// USA: func_ov031_02203fdc
extern "C" ARM unsigned char* func_ov031_02203fdc(void* buffer, int messageType, int* output) {
    unsigned char* bytes = (unsigned char*)buffer;
    BootpHeader* header = (BootpHeader*)buffer;
    VectorizedMemset(buffer, 0, sizeof(BootpHeader));
    header->operationAndHardwareType = 0x101;
    header->hardwareAddressLength = 6;
    data_ov031_0224c980.randomState = data_ov031_0224c980.randomMultiplier * data_ov031_0224c980.randomState + data_ov031_0224c980.randomIncrement;
    unsigned int random = data_ov031_0224c980.randomState / 0x100000000ULL;
    if (output) *output = random;
    int randomHigh = (unsigned short)(random / 0x10000U);
    header->transactionId.high = (randomHigh >> 8) | (randomHigh << 8);
    int randomLow = (unsigned short)random;
    header->transactionId.low = (randomLow >> 8) | (randomLow << 8);
    int addressHigh = (unsigned short)(data_ov031_0224c980.clientAddress / 0x10000U);
    header->clientAddress.high = (addressHigh >> 8) | (addressHigh << 8);
    int addressLow = (unsigned short)data_ov031_0224c980.clientAddress;
    header->clientAddress.low = (addressLow >> 8) | (addressLow << 8);
    VectorizedInvertedMemcpy(data_ov031_0224ce68, header->clientHardwareAddress, 6);
    ((unsigned short*)(bytes + sizeof(BootpHeader)))[0] = 0x8263;
    ((unsigned short*)(bytes + sizeof(BootpHeader)))[1] = 0x6353;
    ((unsigned short*)(bytes + sizeof(BootpHeader)))[2] = DhcpMessageType | (1 << 8);
    bytes[0xf2] = messageType;
    bytes[0xf3] = DhcpClientIdentifier;
    bytes[0xf4] = 7;
    bytes[0xf5] = 1;
    VectorizedInvertedMemcpy(data_ov031_0224ce68, bytes + 0xf6, 6);
    bytes[0xfc] = DhcpHostName;
    bytes[0xfd] = 10;
    VectorizedInvertedMemcpy(data_ov031_02249698, bytes + 0xfe, 10);
    bytes[0x108] = DhcpParameterRequestList;
    bytes[0x109] = 3;
    bytes[0x10a] = 1;
    bytes[0x10b] = 3;
    bytes[0x10c] = 6;
    return bytes + 0x10d;
}
