#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Timing.h"
#include "System/ProcessorContext.h"
#include "System/Mutex.h"
#include "System/Memory.h"
#include "std_library_functions.h"

struct Obj022075a4;
struct Packet02207230 {
    unsigned char kind;
    unsigned char version;
    unsigned short length;
    unsigned char data[4];
};
struct SessionTime02244e44 { unsigned long long ticks; };
struct Struct_02245528 {
    unsigned char padding_0[0x2d];
    signed char attempt;
    unsigned char repeat;
    unsigned char padding_2f[6];
    unsigned char phase;
    unsigned char padding_36[0x390 - 0x36];
    unsigned char result;
    unsigned char done;
    unsigned char padding_392[0x16];
    SessionTime02244e44 deadline;
    unsigned char padding_3b0[8];
    SessionTime02244e44 started;
    SessionTime02244e44 retry_started;
    SessionTime02244e44 last_attempt;
    unsigned char padding_3d0[0x5c];
    Obj022075a4* handle;
};
struct PeerInfo02244e44 {
    unsigned char padding_0[2];
    unsigned char present;
    unsigned char padding_3;
    unsigned char address[6];
    signed short data_length;
    void** data;
};
struct SessionGlobals02244e44 {
    unsigned char padding_0[2];
    unsigned char present;
    unsigned char padding_3[5];
    unsigned short packet_length;
    unsigned char padding_a[0xe];
    PeerInfo02244e44* peer;
    unsigned char padding_1c[0x18];
    Obj022075a4* receive_handle;
};
struct SavedPeer02244e44 {
    unsigned char address[6];
    unsigned char status;
    unsigned char field_7;
};
struct SessionGame02244e44 {
    unsigned char padding_0[0x7fb0];
    SavedPeer02244e44 peers[8];
    SavedPeer02244e44* GetPeers() { return peers; }
};
struct RetryTime02244e44 { int milliseconds; int field_4; };
struct PeerReply02244e44 { unsigned char bytes[0x14]; };
extern RetryTime02244e44 data_ov031_02249594[4];
extern int data_ov031_0224c8a4;
extern Mutex data_ov031_02291e50;
extern SessionGlobals02244e44 data_ov031_02291e04;
extern "C" Obj022075a4* _Z21SelectAndCall022071d8ii(int, int, int);
extern "C" int _Z24QueryOrSetState_022075a4P11Obj022075a4ii(Obj022075a4*, int, int);
extern "C" PeerInfo02244e44* func_ov031_02207440(Obj022075a4*);
extern "C" int _Z20SendSwapped_02207230PvP14Packet02207230(void*, Packet02207230*);
extern "C" int func_ov031_0220783c(int*, int, int, int);
extern "C" int _Z29CallWithZeroZeroZero_0220728ciii(int, int, int);
extern "C" int func_02001aec(const void*, const void*, int);
extern "C" int func_ov031_02245750(Struct_02245528*, PeerReply02244e44*);
extern "C" int func_ov031_02207434(Obj022075a4*);
extern "C" void func_ov031_022077c0();
extern "C" void func_ov031_02245938();
extern "C" int _Z20GetField260_0220d540v();
extern "C" void _Z32SetField34AndClear35_37_02245528P15Struct_02245528i(Struct_02245528*, int);

// USA: func_ov031_02244e44
extern "C" ARM void func_ov031_02244e44(Struct_02245528* session) {
    switch (session->phase) {
    case 0:
        session->handle = _Z21SelectAndCall022071d8ii(2, 1, 0);
        if ((int)session->handle < 0) { session->phase = 5; break; }
        _Z24QueryOrSetState_022075a4P11Obj022075a4ii(session->handle, 4, _Z24QueryOrSetState_022075a4P11Obj022075a4ii(session->handle, 3, 0) & ~4);
        session->phase = 1;
        session->attempt = -1;
        session->repeat = 0;
    case 2: {
        int attempt = session->attempt;
        if (attempt >= 0 || session->repeat) {
            if (attempt < 0) attempt = 0;
            else if (attempt >= 4) attempt = 3;
            signed char index = attempt;
            int wait = session->repeat ? 0 : data_ov031_02249594[index].milliseconds;
            unsigned long long now = GetCurrentTimestamp();
            unsigned long long previous = session->last_attempt.ticks;
            if (((now - previous) << 6) / 0x82ea >= (unsigned long long)wait || now < previous) {
                session->phase = 1;
                if (session->repeat) session->repeat = 0;
                else {
                    session->attempt++;
                    session->retry_started.ticks = GetCurrentTimestamp();
                }
            } else {
                SleepCurrentContext(5);
                break;
            }
        } else {
            session->phase = 1;
            session->attempt = 0;
            session->repeat = 0;
            session->started.ticks = GetCurrentTimestamp();
            session->retry_started = session->started;
        }
    }
    case 1: {
        if (data_ov031_0224c8a4) {
            ZeroInitializeMutex(&data_ov031_02291e50);
            data_ov031_0224c8a4 = 0;
        }
        LockMutex(&data_ov031_02291e50);
        PeerInfo02244e44* info = func_ov031_02207440(data_ov031_02291e04.receive_handle);
        UnlockMutex(&data_ov031_02291e50);
        if (!info) { session->phase = 5; break; }
        Packet02207230 packet;
        memset(&packet, 0, 8);
        unsigned short length = data_ov031_02291e04.packet_length;
        packet.kind = 8;
        packet.version = 2;
        packet.length = ((length >> 8) & 0xff) | ((length << 8) & 0xff00);
        VectorizedInvertedMemcpy(*info->data, packet.data, info->data_length);
        GetCurrentTimestamp();
        _Z24QueryOrSetState_022075a4P11Obj022075a4ii(session->handle, 4, _Z24QueryOrSetState_022075a4P11Obj022075a4ii(session->handle, 3, 0) | 4);
        int status = _Z20SendSwapped_02207230PvP14Packet02207230(session->handle, &packet);
        if (status == -26) {
            unsigned long long elapsed = ((GetCurrentTimestamp() - session->retry_started.ticks) << 6) / 0x82ea;
            if (elapsed >= 0x3a98) status = -76;
        }
        if (status == -26) {
            session->last_attempt.ticks = GetCurrentTimestamp();
            session->repeat = 1;
            session->phase = 2;
            SleepCurrentContext(5);
            break;
        }
        if (status >= 0 || status == -30) {
            session->phase = 4;
            break;
        }
        if (status != -76) goto Failed;
        session->attempt = 5;
        session->repeat = 0;
        unsigned long long elapsed = ((GetCurrentTimestamp() - session->started.ticks) << 6) / 0x82ea;
        if (elapsed >= 0xafc8) {
            session->attempt = 5;
            session->repeat = 0;
        }
        if (session->attempt < 5) {
            session->last_attempt.ticks = GetCurrentTimestamp();
            session->phase = 2;
            SleepCurrentContext(5);
        } else {
        Failed:
            session->phase = 5;
        }
        break;
    }
    case 4: {
        GetCurrentTimestamp();
        _Z24QueryOrSetState_022075a4P11Obj022075a4ii(session->handle, 4, _Z24QueryOrSetState_022075a4P11Obj022075a4ii(session->handle, 3, 0) | 4);
        int descriptor[2];
        if (func_ov031_0220783c(descriptor, 1, 0x7fd88, 0) > 0) {
            PeerReply02244e44 reply;
            memset(&reply, 0, 0x14);
            if (_Z29CallWithZeroZeroZero_0220728ciii((int)session->handle, (int)&reply, 0x14) < 0) {
                GetCurrentTimestamp();
                if (data_ov031_02291e04.peer) {
                    SavedPeer02244e44* peer = ((SessionGame02244e44*)GameState::GetInstance())->GetPeers();
                    for (int index = 0; index < 8; index++, peer++) {
                        if (!func_02001aec(peer, data_ov031_02291e04.peer->address, 6)) {
                            if (!data_ov031_02291e04.present) peer->status = 0xff;
                            else memset(peer, 0, 8);
                            break;
                        }
                    }
                }
                session->phase = 5;
            } else {
                GetCurrentTimestamp();
                PeerReply02244e44 copy;
                memcpy(&copy, &reply, 0x14);
                session->result = func_ov031_02245750(session, &copy);
                session->phase = 5;
            }
        } else {
            session->phase = 5;
            _Z24QueryOrSetState_022075a4P11Obj022075a4ii(session->handle, 4, _Z24QueryOrSetState_022075a4P11Obj022075a4ii(session->handle, 3, 0) & ~4);
        }
        break;
    }
    case 5:
        GetCurrentTimestamp();
        _Z24QueryOrSetState_022075a4P11Obj022075a4ii(session->handle, 4, _Z24QueryOrSetState_022075a4P11Obj022075a4ii(session->handle, 3, 0) | 4);
        _Z24QueryOrSetState_022075a4P11Obj022075a4ii(session->handle, 4, _Z24QueryOrSetState_022075a4P11Obj022075a4ii(session->handle, 3, 0) | 4);
        if (func_ov031_02207434(session->handle) == 0) {
            SleepCurrentContext(1);
            for (int index = 0; index < 0x7530; index++) {
                if (func_ov031_02207434(session->handle) != -26) break;
                SleepCurrentContext(1);
            }
        }
        session->handle = (Obj022075a4*)-1;
        func_ov031_022077c0();
        func_ov031_02245938();
        session->deadline.ticks = GetCurrentTimestamp() + 0xefb5f7;
        session->phase = 6;
        break;
    case 6:
        if (!_Z20GetField260_0220d540v()) {
            GetCurrentTimestamp();
            _Z32SetField34AndClear35_37_02245528P15Struct_02245528i(session, 0);
            session->done = 1;
        }
        break;
    }
}
