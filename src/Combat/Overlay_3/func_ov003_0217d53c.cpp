#include <globaldefs.h>
#if defined(jpn)
enum { kRegion10b = 0x107 };
enum { kRegion36fc = 0x34ec };
enum { kRegion9a0 = 0x870 };
enum { kRegion3734 = 0x3524 };
enum { kRegion370c = 0x34fc };
#else
enum { kRegion10b = 0x10b };
enum { kRegion36fc = 0x36fc };
enum { kRegion9a0 = 0x9a0 };
enum { kRegion3734 = 0x3734 };
enum { kRegion370c = 0x370c };
#endif
#include "GameState/GameState.h"

extern "C" char* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" char* func_02012fe4(void);
extern "C" int func_020457e0(char* obj);
extern "C" void func_ov017_021baedc(void* self, int flag);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);
extern "C" void _Z27InitAndResetHeader_0219e310Phi(unsigned char* obj, int arg);
void* GetField0x3f8Address(GameState* state);
extern "C" void _Z18InitStruct02070378Pc(char* obj);

struct Progress02012fe4 {
#if defined(jpn)
    unsigned char pad0[0x1b3c];
#else
    unsigned char pad0[0xb3c];
#endif
    int chapter;
};

#if !defined(jpn)
static inline struct Progress02012fe4* GetProgress(void* run) {
    return (struct Progress02012fe4*)((int)run + 0x1840);
}
#endif

struct BattleEvent_0217d53c {
    unsigned char pad0[0x8];
    unsigned short messageId;
    unsigned char padA[kRegion10b - 0xa];
    unsigned char active;
};

struct EventRecord_0217d53c {
    unsigned short id;
    unsigned char pad2[0x7 - 0x2];
    unsigned char field_0x7;
    unsigned char pad8[0xc - 0x8];
    unsigned char field_0xc;
    unsigned char padD[0x14 - 0xd];
    int field_0x14;
    int field_0x18;
};

struct State_0217d53c {
    unsigned char pad0[0x4];
    unsigned char state;
    signed char busy;
};

// JPN: func_ov003_0217c1dc
// USA: func_ov003_0217d53c
extern "C" ARM void func_ov003_0217d53c(State_0217d53c* self) {
    GameState* gs = GameState::GetInstance();
    char* global = _Z26GetGlobalField0x1c020421a0v();
    char* res = (char*)func_ov017_0218b5b0();
    struct TailList020469b4* list = *(struct TailList020469b4**)(res + kRegion36fc);
#if defined(jpn)
    Progress02012fe4* current = (Progress02012fe4*)(func_02012fe4() + 0x860);
#else
    char* current = func_02012fe4();
#endif
    if (self->busy != 0 || *(int*)(global + kRegion9a0) != 0) return;
    if (func_020457e0(global) == 0) {
        BattleEvent_0217d53c* event = *(BattleEvent_0217d53c**)(res + kRegion3734);
        func_ov017_021baedc(event, 1);
        event->active = 1;
        switch (
#if defined(jpn)
            current->chapter
#else
            GetProgress(current)->chapter
#endif
        ) {
            case 0:
            case 1:
            case 2:
                event->messageId = 0xd067;
                break;
            case 3:
            case 4:
                event->messageId = 0xd068;
                break;
            case 5:
                event->messageId = 0xd069;
                break;
            case 6:
                event->messageId = 0xd06a;
                break;
        }
        AppendNodeToTail(list, (struct TailNode020469b4*)event);
        unsigned char* header = *(unsigned char**)(res + kRegion370c);
        _Z27InitAndResetHeader_0219e310Phi(header, 0);
        EventRecord_0217d53c* record = (EventRecord_0217d53c*)GetField0x3f8Address(gs);
        _Z18InitStruct02070378Pc((char*)record);
        record->id = 0xc3bc;
        record->field_0x7 = 1;
        record->field_0x14 = 0x266;
        record->field_0x18 = -0x7b33;
        record->field_0xc = 1;
        AppendNodeToTail(list, (struct TailNode020469b4*)header);
        self->state = 4;
        self->busy = 0;
    } else {
        self->state = 4;
        self->busy = 0;
    }
}
