#pragma once

struct NetworkIdentity {
    unsigned int size;
    unsigned char unknown04[0x1c];
    unsigned int flags;
    unsigned int gameCode;
    unsigned int signature;
    unsigned int unknown2C;
    unsigned char unknown30[0xc];
    unsigned int checksum;
};

extern "C" unsigned long long func_ov031_022457e0(int unused, NetworkIdentity identity);
