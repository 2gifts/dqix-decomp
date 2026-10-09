#include <globaldefs.h>
#include <std_library_functions.h>

struct SearchStruct0202c1a4;
struct PacketIdentifier { unsigned char bytes[6]; };
struct PacketSlot {
    PacketIdentifier identifier;
    signed char sender;
    unsigned char active;
    unsigned char length;
    signed char record;
};
struct PacketRecord {
    PacketIdentifier identifier;
    char pad_6[0xc];
    unsigned short field_12 : 14;
    unsigned short enabled : 1;
    unsigned short field_12_hi : 1;
    unsigned char payload[24];
};
struct PacketStore {
    char pad_0[0x7200];
    PacketRecord records[16];
    PacketSlot slots[3];
};
struct PacketContext { char pad_0[0x3b84]; void* handler; };
struct Packet {
    char pad_0[4];
    unsigned char payload[14];
    unsigned char recipient : 2;
    unsigned char mode : 2;
    unsigned char field_12 : 4;
    unsigned char type : 2;
    unsigned char length : 4;
    unsigned char final : 1;
    unsigned char segmented : 1;
};
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
extern "C" void func_ov017_021a99dc(void*, void*, int, int, int);

// USA: func_ov017_021d15b0
extern "C" ARM void func_ov017_021d15b0(int sender, Packet* packet, PacketStore* store, PacketContext* context, SearchStruct0202c1a4* search) {
    void* handler = context->handler;
    int recipient = GetSearchStructCurrentArrEntry(search);
    if (!packet->segmented) {
        if (recipient == packet->recipient) func_ov017_021a99dc(handler, packet->payload, packet->type, packet->length, packet->final);
        return;
    }
    if (packet->type == 2) {
        if (packet->mode != 1) return;
        PacketSlot* slot = store->slots;
        for (int i = 0; i < 3; i++, slot++) {
            if (slot->sender == sender) return;
            if (slot->sender < 0) {
                memcpy(slot, packet->payload, packet->length);
                slot->sender = sender;
                return;
            }
        }
        return;
    }
    if (packet->type != 0) return;
    if (packet->mode == 0 && recipient != packet->recipient) return;
    PacketSlot* slot = store->slots;
    for (int i = 0; i < 3; i++, slot++) {
        if (slot->sender != sender) continue;
        if (slot->record < 0) {
            PacketRecord* record = store->records;
            int recordIndex;
            for (recordIndex = 0; recordIndex < 16; recordIndex++, record++) {
                if (record->enabled) {
                    PacketIdentifier identifier = slot->identifier;
                    int equal;
                    for (int byte = 0; byte < 6; byte++) {
                        if (identifier.bytes[byte] != record->identifier.bytes[byte]) {
                            equal = 0;
                            goto compared;
                        }
                    }
                    equal = 1;
compared:
                    if (equal) {
                        slot->record = recordIndex;
                        slot->active = 1;
                        break;
                    }
                }
            }
            if (recordIndex == 16) return;
        }
        PacketRecord* destination = &store->records[slot->record];
        memcpy(destination->payload + slot->length, packet->payload, packet->length);
        slot->length += packet->length;
        if (!packet->final) return;
        slot->active = 0;
        slot->length = 0;
        slot->record = -1;
        return;
    }
}
