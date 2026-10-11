#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x88
#define REGION_OFFSET_1 0x78
#define REGION_OFFSET_2 0x8b8
#define REGION_OFFSET_3 0x480
#define REGION_OFFSET_4 0x47f
#define REGION_OFFSET_5 0xc2
#define REGION_OFFSET_6 0xc4
#define REGION_OFFSET_7 0xc6
#else
#define REGION_OFFSET_0 0x68
#define REGION_OFFSET_1 0x5c
#define REGION_OFFSET_2 0x950
#define REGION_OFFSET_3 0x440
#define REGION_OFFSET_4 0x43f
#define REGION_OFFSET_5 0x82
#define REGION_OFFSET_6 0x84
#define REGION_OFFSET_7 0x86
#endif

#include "GameState/GameState.h"

int GetFieldAt0x150(unsigned char* obj);

struct Obj0203c108;
void SwapGlobalEntry0203c108(struct Obj0203c108* obj, char* fmt);

extern "C" void func_ov000_0216fe9c(void* obj);

int GetField0x3acValue(GameState* battleStruct);

// USA: func_ov000_02171138
extern "C" ARM void func_ov000_02171138(void* objRaw) {
    char* obj = (char*)objRaw;
    int combatantId = *(int*)(obj + 0x4c);
    if (combatantId < 0) {
        return;
    }
    GameState* bs = GameState::GetInstance();
    combatantId = *(int*)(obj + 0x4c);
    GameObject* c = GetCombatantWithFlag0x100(bs, combatantId);
    if (!c) {
        return;
    }
    char* field150 = (char*)(int)GetFieldAt0x150((unsigned char*)c);
    if (!field150) {
        return;
    }
    int off134 = *(int*)((char*)c + 0x134);
    SwapGlobalEntry0203c108((struct Obj0203c108*)(obj + REGION_OFFSET_0), (char*)off134);
    *(int*)(obj + REGION_OFFSET_1) = 2;
    int idx950 = *(int*)(field150 + REGION_OFFSET_2);
    *(unsigned char*)(obj + REGION_OFFSET_3) = (unsigned char)idx950;
    idx950 = *(int*)(field150 + REGION_OFFSET_2);
    char* p = field150 + idx950 * 2 + 0x100;
    unsigned short val = *(unsigned short*)(p + 0x6c);
    *(unsigned char*)(obj + REGION_OFFSET_4) = (unsigned char)val;

    short savedC = *(short*)(obj + 0xc);
    short saved8 = *(short*)(obj + 0x8);
    short savedE = *(short*)(obj + 0xe);
    short savedA = *(short*)(obj + 0xa);
    func_ov000_0216fe9c(obj + 8);
    *(short*)(obj + 0xc) = savedC;
    *(short*)(obj + 0x8) = saved8;
    *(short*)(obj + 0xe) = savedE;
    *(short*)(obj + 0xa) = savedA;

    *(int*)(obj + 0x28) = *(int*)(field150 + 0xa8);
    *(unsigned char*)(obj + 0x1c) = 0;
    *(unsigned short*)(obj + REGION_OFFSET_5) = 0;
    *(unsigned short*)(obj + REGION_OFFSET_6) = 0;
    *(unsigned char*)(obj + REGION_OFFSET_7) = 0;
    int fieldVal = GetField0x3acValue(bs);
    if (*(int*)(obj + 0x4c) == fieldVal) {
        *(unsigned char*)(obj + 0x24) |= 2;
    }
    *(unsigned char*)(obj + 0x24) &= ~1;
}
