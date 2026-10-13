#include "System/OverlayResponse.h"

extern "C" int func_ov031_0221d6a8(ResponseHeader*);

// USA: func_ov031_0221d3b0
extern "C" THUMB int func_ov031_0221d3b0(int state, ResponsePacket* packet, int* rejected, ResponseIdentifiers* identifiers) {
    ResponseHeader* header = &packet->header;
    if (func_ov031_0221e638(header->version) < 1) {
        (*rejected)++;
        return state;
    }
    if (header->transport != 0x11) {
        (*rejected)++;
        return state;
    }
    if (func_ov031_0221d6a8(&packet->header) > 0) {
        (*rejected)++;
        return state;
    }
    switch (func_ov031_0221e638(header->type)) {
    case 0x1010:
        state = func_ov031_0221d450(state, packet, rejected, identifiers);
        break;
    case 0x2010:
        state = func_ov031_0221d52c(state, packet, rejected, identifiers);
        break;
    case 0x3010:
        state = func_ov031_0221d604(state, packet, rejected, identifiers);
        break;
    }
    return state;
}
