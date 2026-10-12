#include <globaldefs.h>

struct PacketHeader0221d3b0 {
    unsigned short version;
    char padding_0x02[4];
    unsigned short type;
    char padding_0x08[7];
    unsigned char protocol;
};

struct Packet0221d3b0 {
    char padding_0x00[12];
    PacketHeader0221d3b0 header;
};

extern "C" unsigned int func_ov031_0221e638(unsigned short);
extern "C" int func_ov031_0221d6a8(PacketHeader0221d3b0*);
extern "C" void* func_ov031_0221d450(void*, Packet0221d3b0*, int*, void*);
extern "C" void* func_ov031_0221d52c(void*, Packet0221d3b0*, int*, void*);
extern "C" void* func_ov031_0221d604(void*, Packet0221d3b0*, int*, void*);

// USA: func_ov031_0221d3b0
extern "C" THUMB void* func_ov031_0221d3b0(void* context, Packet0221d3b0* packet, int* rejected, void* parameter) {
    PacketHeader0221d3b0* header = &packet->header;
    if (func_ov031_0221e638(header->version) < 1) {
        (*rejected)++;
        return context;
    }
    if (header->protocol != 0x11) {
        (*rejected)++;
        return context;
    }
    if (func_ov031_0221d6a8(&packet->header) > 0) {
        (*rejected)++;
        return context;
    }
    switch (func_ov031_0221e638(header->type)) {
    case 0x1010:
        context = func_ov031_0221d450(context, packet, rejected, parameter);
        break;
    case 0x2010:
        context = func_ov031_0221d52c(context, packet, rejected, parameter);
        break;
    case 0x3010:
        context = func_ov031_0221d604(context, packet, rejected, parameter);
        break;
    }
    return context;
}
