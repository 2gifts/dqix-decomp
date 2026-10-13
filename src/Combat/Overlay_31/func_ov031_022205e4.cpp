#include <globaldefs.h>

#if defined(jpn)
#define data_ov031_0224b1d4 data_ov031_0224bdd4
#define data_ov031_0224fb20 data_ov031_02250720
#define func_ov031_022228f4 func_ov031_022230d4
#endif

struct HardwareAddress {
    unsigned char bytes[6];
};
struct InternetAddress {
    unsigned char bytes[4];
};
struct AddressPair {
    HardwareAddress first;
    HardwareAddress second;
    InternetAddress network;
};
struct AddressDebug {
    int field_0x0;
    int enabled;
};
extern InternetAddress data_ov031_0224b1d4 __attribute__((aligned(4)));
extern HardwareAddress data_ov031_0224fb20;
extern HardwareAddress data_ov031_0224fb18;
extern AddressDebug data_ov031_0224b114;
extern "C" int func_ov031_022205d8(void* address);
extern "C" int func_02001aec(const void* first, const void* second, unsigned int size);
extern "C" void func_ov031_022228f4(char* destination, const HardwareAddress* address);

#define COPY_ADDRESS(destination, source) do { \
    HardwareAddress* targetAddress = &(destination); \
    const HardwareAddress* sourceAddress = &(source); \
    targetAddress->bytes[0] = sourceAddress->bytes[0]; \
    targetAddress->bytes[1] = sourceAddress->bytes[1]; \
    targetAddress->bytes[2] = sourceAddress->bytes[2]; \
    targetAddress->bytes[3] = sourceAddress->bytes[3]; \
    targetAddress->bytes[4] = sourceAddress->bytes[4]; \
    targetAddress->bytes[5] = sourceAddress->bytes[5]; \
} while (0)

// USA: func_ov031_022205e4
// KEEP-NAME: func_ov031_022205e4
extern "C" THUMB int func_ov031_022205e4(AddressPair* output) {
    char firstText[32];
    char secondText[32];
    HardwareAddress addresses[2];
    unsigned char* network = output->network.bytes;
    const unsigned char* sourceNetwork = data_ov031_0224b1d4.bytes;
    network[0] = sourceNetwork[0];
    network[1] = sourceNetwork[1];
    network[2] = sourceNetwork[2];
    network[3] = sourceNetwork[3];
    COPY_ADDRESS(addresses[1], data_ov031_0224fb20);
    addresses[1].bytes[0] &= 0xfd;
    func_ov031_022205d8(&addresses[0]);
    const HardwareAddress* primary = &addresses[0];
    COPY_ADDRESS(data_ov031_0224fb18, *primary);
    const HardwareAddress* second;
    if (func_02001aec(&addresses[1], primary, 6) <= 0) {
        COPY_ADDRESS(output->first, addresses[0]);
        second = &addresses[1];
    } else {
        COPY_ADDRESS(output->first, addresses[1]);
        second = &addresses[0];
    }
    COPY_ADDRESS(output->second, *second);
    if (data_ov031_0224b114.enabled) {
        func_ov031_022228f4(firstText, &addresses[0]);
        func_ov031_022228f4(secondText, &addresses[1]);
    }
    return 1;
}
