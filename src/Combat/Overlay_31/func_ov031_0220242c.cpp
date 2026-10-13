#include <globaldefs.h>
#include "System/ProcessorContext.h"
#include "System/Interrupts.h"
#include "System/Memory.h"

struct TcpConnection {
    ProcessorContext* context;
    int pending;
    unsigned char state;
    unsigned char padding9[0x1b];
    unsigned int sequence;
    unsigned char padding28[4];
    unsigned short window;
    unsigned short padding2e;
    unsigned int acknowledgement;
    unsigned int receivedPackets;
    unsigned char padding38[4];
    unsigned int receiveCapacity;
    unsigned char* receiveBuffer;
    unsigned int receivedBytes;
};

struct TcpPacket {
    unsigned short ports[2];
    unsigned short sequenceHigh;
    unsigned short sequenceLow;
    unsigned short acknowledgementHigh;
    unsigned short acknowledgementLow;
    unsigned char headerLength;
    unsigned char flags;
    unsigned short window;
};

extern "C" TcpConnection* func_ov031_02201e0c(void*, TcpPacket*, unsigned int);
extern "C" int func_ov031_02201fac(void*, TcpPacket*, unsigned int, int);
int TailCallType16_02201f84(int, int);
int TailCallType17_02201f98(int, int);

#define Swap16_0220242c(value) (unsigned short)(((value) >> 8) | ((value) << 8))

// USA: func_ov031_0220242c
extern "C" ARM void func_ov031_0220242c(void* object, TcpPacket* packet, unsigned int length) {
    TcpConnection* connection = func_ov031_02201e0c(object, packet, length);
    if (!connection) {
        func_ov031_02201fac(object, packet, length, 0);
        return;
    }
    unsigned int acknowledgement = ((unsigned int)Swap16_0220242c(packet->acknowledgementHigh) << 16) | Swap16_0220242c(packet->acknowledgementLow);
    unsigned char flags = packet->flags;
    if ((int)(acknowledgement - connection->acknowledgement) > 0)
        connection->acknowledgement = acknowledgement;
    unsigned int sequence = ((unsigned int)Swap16_0220242c(packet->sequenceHigh) << 16) | Swap16_0220242c(packet->sequenceLow);
    if (connection->state == 4 && connection->sequence != sequence) {
        TailCallType16_02201f84((int)connection, 0);
        return;
    }
    connection->window = Swap16_0220242c(packet->window);
    switch (connection->state) {
    case 0:
    case 2:
        func_ov031_02201fac(object, packet, length, 0);
        break;
    case 3:
        connection->state = 4;
        if (connection->pending == 1) {
            connection->pending = 0;
            MarkContextReadyAndSwitch(connection->context);
        }
        if (!length)
            break;
    case 4:
        ++connection->receivedPackets;
        unsigned int capacity = connection->receiveCapacity;
        unsigned int remaining = capacity - connection->receivedBytes;
        int complete;
        if (length > remaining) {
            complete = 0;
            length = remaining;
        } else {
            complete = 1;
        }
        if (length) {
            int irqState = DisableIRQInterrupts();
            int headerBytes = (packet->headerLength & 0xf0) / 4;
            VectorizedInvertedMemcpy((unsigned char*)packet + headerBytes, connection->receiveBuffer + connection->receivedBytes, length);
            connection->receivedBytes += length;
            connection->sequence += length;
            SetIRQInterruptState(irqState);
            if (connection->pending == 2) {
                connection->pending = 0;
                MarkContextReadyAndSwitch(connection->context);
            }
        }
        if (complete && (flags & 1)) {
            connection->state = 6;
            ++connection->sequence;
            TailCallType17_02201f98((int)connection, 0);
            if (!length && connection->pending == 2) {
                connection->pending = 0;
                MarkContextReadyAndSwitch(connection->context);
            }
        } else if (length) {
            TailCallType16_02201f84((int)connection, 0);
        }
        break;
    case 7:
    case 8:
        if (flags & 1) {
            connection->sequence += length + 1;
            TailCallType16_02201f84((int)connection, 0);
            connection->state = 0;
            if (connection->pending == 2) {
                connection->pending = 0;
                MarkContextReadyAndSwitch(connection->context);
            }
        } else {
            if (length) {
                connection->sequence += length;
                TailCallType16_02201f84((int)connection, 0);
            }
            connection->state = 8;
        }
        break;
    case 6:
    case 9:
        connection->state = 0;
        if (connection->pending == 2) {
            connection->pending = 0;
            MarkContextReadyAndSwitch(connection->context);
        }
        break;
    default:
        if (flags & 1)
            ++connection->sequence;
        TailCallType16_02201f84((int)connection, 0);
        break;
    }
    CycleCurrentPriorityContexts();
}
