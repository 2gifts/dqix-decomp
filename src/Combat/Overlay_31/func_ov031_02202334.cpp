#include <globaldefs.h>
#include "System/ProcessorContext.h"

struct Connection02202334 {
    ProcessorContext* context;
    int pending;
    unsigned char state;
    char pad9[0x1b];
    unsigned int sequence;
    char pad28[4];
    unsigned short window;
    char pad2e[2];
    unsigned int acknowledgement;
};
struct Packet02202334 { unsigned short pad[2]; unsigned short sequenceHigh; unsigned short sequenceLow; unsigned short acknowledgementHigh; unsigned short acknowledgementLow; unsigned short fieldC; unsigned short window; };
extern "C" Connection02202334* func_ov031_02201e0c(void*, Packet02202334*, int);
extern "C" int func_ov031_02201fac(void*, Packet02202334*, unsigned int, int);
extern "C" void func_ov031_02201e70(Packet02202334*, Connection02202334*);
void TailCallType16_02201f84(int, int);
#define Swap16_02202334(value) (unsigned short)(((value) >> 8) | ((value) << 8))

// USA: func_ov031_02202334
extern "C" ARM void func_ov031_02202334(void* obj, Packet02202334* packet, int length) {
    Connection02202334* connection = func_ov031_02201e0c(obj, packet, length);
    if (!connection || connection->state != 2) {
        func_ov031_02201fac(obj, packet, length, 0);
        return;
    }
    CycleCurrentPriorityContexts();
    connection->sequence = (((unsigned int)Swap16_02202334(packet->sequenceHigh) << 16) | Swap16_02202334(packet->sequenceLow)) + 1;
    connection->acknowledgement = ((unsigned int)Swap16_02202334(packet->acknowledgementHigh) << 16) | Swap16_02202334(packet->acknowledgementLow);
    connection->window = Swap16_02202334(packet->window);
    func_ov031_02201e70(packet, connection);
    TailCallType16_02201f84((int)connection, 0);
    connection->state = 4;
    if (connection->pending == 1) {
        connection->pending = 0;
        MarkContextReadyAndSwitch(connection->context);
    }
}
