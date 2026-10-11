#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void func_ov017_021b6f18(void* node);
int GetField0x3acValue(GameState* battleStruct);
extern "C" void func_ov017_021b6e70(void* evt, unsigned short tag);
extern "C" void func_ov017_021b7104(void* node, void* out);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

struct LocalEvt021b8bb0 {
    unsigned char f0;
    unsigned char f1;
    unsigned short f2;
    unsigned short f4;
    unsigned short pad6;
    int f8;
    unsigned char fc;
    unsigned char fd;
    unsigned char fe;
    unsigned char ff;
    short f10;
    unsigned char f12;
    unsigned char pad13;
    int f14;
};

// JPN: func_ov017_021b90a8
// USA: func_ov017_021b8bb0  (semantic: ApplyOrEnqueueEvent_021b8bb0)
extern "C" ARM void func_ov017_021b8bb0(int id) {
#if defined(jpn)
 enum {regionalOffset0=0x4ec, regionalOffset1=0x508};
#else
 enum {regionalOffset0=0x6fc, regionalOffset1=0x718};
#endif
    GameState* bs = GameState::GetInstance();
    char* base = (char*)(long)((int)func_ov017_0218b5b0()) + 0x3000;
    struct TailList020469b4* list = *(struct TailList020469b4**)(base + regionalOffset0);
    struct TailNode020469b4* node = *(struct TailNode020469b4**)(base + regionalOffset1);
    func_ov017_021b6f18(node);

    struct LocalEvt021b8bb0 evt;
    evt.f0 = 1;
    evt.f12 = 2;
    evt.f1 = 0;
    evt.f2 = 0;
    evt.f4 = 0;
    evt.f8 = -1;
    evt.fc = 0;
    evt.fd = 0;
    evt.fe = 0;
    evt.f10 = -1;
    evt.ff = 0;
    evt.f14 = 0;

    evt.f1 = GetField0x3acValue(bs);
    evt.f2 = 0xffff;
    evt.f4 = (unsigned short)(id + 0x8005);
    evt.f8 = id;
    func_ov017_021b6e70(&evt, evt.f2);
    func_ov017_021b7104(node, &evt);
    AppendNodeToTail(list, node);
}
