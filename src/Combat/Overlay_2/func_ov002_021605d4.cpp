#include <globaldefs.h>
#include "GameState/GameState.h"

class GameState;
struct Container020e0310;
struct DstHolder0215b8c8 {
    char *dst;
};
struct StoreStruct;

extern "C" void func_ov002_02157480(void *self, int *slots);
unsigned char *GetFieldAt0x150(unsigned char *c);
const char *GetFieldByKey020e0434(Container020e0310 *tbl, int key);
extern "C" void __clear(void *buffer, unsigned long size);
void AppendTaggedString_0215b8c8(DstHolder0215b8c8 *dst, const char *src, int n);
void AppendFormatted02041fac(char *buf, int str, int n);
void *GetGlobalField0x1c020421a0();
extern "C" void func_02046380(void *messages);
void StoreInArray0x8b0(StoreStruct *messages, int index, int value);
void SetByteInRange(unsigned char *messages, int index, unsigned char digits);
void SetByteAtIndex(unsigned char *messages, int index, unsigned char value);
void AppendHeightTag(char *buf, int h);
extern "C" void func_02046608(void *messages, int a, const char *format, char *output, int size, int b, int c);
void AppendString02042058(char *buf, const char *str);

// USA: func_ov002_021605d4
extern "C" ARM void func_ov002_021605d4(char *self, char *buf) {
    char text[0x80];
    int slots[4];
    char line[0x40];
    DstHolder0215b8c8 holder;
    if (buf == 0) return;
    GameState *gs = GameState::GetInstance();
    short idx     = *(short *) (self + 0x1c08);
    func_ov002_02157480(self, slots);
    int slot = slots[idx];
    int ok   = (slot >= 0 && slot <= 3);
    if (!ok) return;
    unsigned char *c = (unsigned char *) GetCombatantWithFlag0x100(gs, slot);
    if (c == 0) return;
    unsigned char *f = GetFieldAt0x150(c);
    if (f == 0) return;
    const char *name = GetFieldByKey020e0434((Container020e0310 *) (self + 0x20), 0x1005);
    __clear(text, sizeof(text));
    holder.dst = text;
    AppendTaggedString_0215b8c8(&holder, name, 0);
    AppendFormatted02041fac(buf, (int) text, 0x10);
    void *msg = GetGlobalField0x1c020421a0();
    func_02046380(msg);
    StoreInArray0x8b0((StoreStruct *) msg, 0, *(unsigned short *) (f + 0x564));
    SetByteInRange((unsigned char *) msg, 0, 4);
    SetByteAtIndex((unsigned char *) msg, 0, 1);
    __clear(line, sizeof(line));
    AppendHeightTag(buf, -1);
    func_02046608(msg, 8, GetFieldByKey020e0434((Container020e0310 *) (self + 0x20), 0x1006), line,
                  0x100, 0, 0);
    AppendString02042058(buf, line);
}
