#include "System/OverlayResponse.h"

extern "C" unsigned int func_ov031_0221e610(unsigned int);
extern "C" void func_ov031_0221d060(int);

inline int CompareFinalIdentifier(ResponseIdentifier* identifier, ResponseHeader* header) {
    return func_ov031_0221d7e0(identifier, header->GetIdentifier());
}

// USA: func_ov031_0221d604
extern "C" THUMB int func_ov031_0221d604(int state, ResponsePacket* packet, int* counter, ResponseIdentifiers* identifiers) {
    if (state != 2) { ++*counter; return state; }
    ResponseBody* record = &packet->body;
    ResponseIdentifier* identifier = identifiers->GetFinalIdentifier();
    ResponseHeader* header = packet->GetHeader();
    if (CompareFinalIdentifier(identifier, header) < 0) { ++*counter; return state; }
    if (record->type != 7) { ++*counter; return state; }
    if (func_ov031_0221e638(record->identifier) == 0) { ++*counter; return state; }
    if (func_ov031_0221e610(record->status) == 0) return 100;
    if (func_ov031_0221e610(record->status) == -2) {
        func_ov031_0221d060(20);
        return -1;
    }
    if (func_ov031_0221e610(record->status) == -3) {
        func_ov031_0221d060(21);
        return -1;
    }
    func_ov031_0221d060(24);
    return -1;
}
