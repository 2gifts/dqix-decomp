#include <globaldefs.h>

struct SessionAddress {
    unsigned char octets[4];
};

struct SessionLog {
    unsigned char padding[0x4cc];
    SessionAddress address;
};

extern SessionLog* data_ov031_02290cfc;
extern const char data_ov031_0224be50[];
int VariadicForward020c7130(int, int, ...);

// USA: func_ov031_02236038
extern "C" ARM void func_ov031_02236038(int category) {
    SessionAddress* address = &data_ov031_02290cfc->address;
    unsigned char first = data_ov031_02290cfc->address.octets[0];
    unsigned char second = address->octets[1];
    unsigned char third = address->octets[2];
    unsigned char fourth = address->octets[3];
    VariadicForward020c7130(category, (int)data_ov031_0224be50, first, second, third, fourth);
}
