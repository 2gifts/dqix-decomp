#include <globaldefs.h>
#include "System/Memory.h"

struct PacketWork022098d8 {
    char pad_0[0x1d4];
    void* resource;
    char pad_1d8[0x10c];
    char sections[8];
    char pad_2ec[0x168];
    unsigned char enabled;
    unsigned char state;
    unsigned char pending;
    char pad_457[0x155];
    unsigned char sectionFlag;
    char pad_5ad[0x277];
    unsigned char* packet;
    unsigned int packetLength;
    unsigned int packetOffset;
};
extern "C" unsigned int func_ov031_0220940c(PacketWork022098d8*, unsigned char*);
extern "C" void func_ov031_02208b78(PacketWork022098d8*, unsigned char*);
extern "C" void func_ov031_0220911c(PacketWork022098d8*, unsigned char*);
extern "C" void func_ov031_02208940(PacketWork022098d8*, unsigned char*);
extern "C" void func_ov031_0220871c(PacketWork022098d8*, unsigned char*);
extern "C" void func_ov031_02209310(PacketWork022098d8*, unsigned char*);
void InitTwoSections_022098ac(void*, int, int);
extern void (*data_ov031_0224c9c0)(unsigned char*);

// USA: func_ov031_022098d8
extern "C" ARM void func_ov031_022098d8(PacketWork022098d8* work, unsigned char* packet) {
    unsigned char state = work->state;
    if (state == 9) {
        data_ov031_0224c9c0(packet);
        return;
    }
    unsigned char* section;
    unsigned int length = (packet[3] << 8) + packet[4] + 5;
    unsigned int type = packet[0];
    if ((((unsigned char)(state + 0xf9) <= 1) && type != 21) || (type == 21 && length > 7)) {
        length = func_ov031_0220940c(work, packet);
        state = work->state;
        if (state == 9) {
            data_ov031_0224c9c0(packet);
            return;
        }
    }
    section = packet + 5;
    length -= 5;
    switch (type) {
    case 20:
        if (!work->resource) work->state = 9;
        else {
            VectorizedMemset(work->sections, 0, 8);
            work->state = 7;
        }
        break;
    case 21:
        if (section[0] == 2) work->state = 9;
        break;
    case 22:
        do {
            int sectionType = section[0];
            unsigned int middle = section[2] << 8;
            unsigned int sectionLength = (section[1] << 16) + middle + section[3];
            section += 4;
            switch (sectionType) {
            case 1:
                if (work->enabled && state == 0) func_ov031_02208b78(work, section);
                break;
            case 16:
                func_ov031_0220911c(work, section);
                break;
            case 2:
                func_ov031_02208940(work, section);
                break;
            case 11:
                func_ov031_0220871c(work, section);
                work->sectionFlag = 0;
                break;
            case 13:
                work->sectionFlag = 1;
                break;
            case 14:
                work->state = 4;
                break;
            case 20:
                func_ov031_02209310(work, section);
                break;
            default:
                work->state = 9;
                break;
            }
            InitTwoSections_022098ac(work, (int)(section - 4), sectionLength + 4);
            section += sectionLength;
            length -= sectionLength + 4;
            if (!length) break;
            state = work->state;
        } while (state != 9);
        break;
    case 23:
        work->packet = packet;
        work->packetOffset = 5;
        work->packetLength = length + 5;
        work->pending = 1;
        return;
    default:
        work->state = 9;
        break;
    }
    data_ov031_0224c9c0(packet);
}
