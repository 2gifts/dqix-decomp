#include "System/OverlayResponse.h"

extern "C" unsigned short func_ov031_0221e5f8(unsigned short);
extern "C" void func_ov031_0221e51c(void*, const void*, unsigned int);

// USA: func_ov031_0221e028
extern "C" THUMB void func_ov031_0221e028(void* buffer, int type, int protocol, int flags, signed char unknown0e, signed char transport, const void* identifier) {
    ResponseHeader* packet = (ResponseHeader*)buffer;
    packet->version = func_ov031_0221e5f8(1);
    packet->unknown02[0] = 0;
    packet->unknown02[1] = 0;
    packet->type = func_ov031_0221e5f8(type);
    packet->unknown08 = 0;
    packet->protocol = func_ov031_0221e5f8(protocol);
    packet->flags = func_ov031_0221e5f8(flags);
    packet->unknown0e = unknown0e;
    packet->transport = transport;
    func_ov031_0221e51c(&packet->identifier, identifier, sizeof(packet->identifier));
}
