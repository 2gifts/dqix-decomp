#include <globaldefs.h>

class GameState;
struct Container020e0310;
struct DstHolder0215b8c8 {
    char *dst;
};
struct StoreStruct;

extern "C" GameState *_ZN9GameState11GetInstanceEv();
extern "C" void func_ov002_02157480(void *self, int *slots);
void *GetCombatantWithFlag0x100(GameState *gs, int slot);
unsigned char *GetFieldAt0x150(unsigned char *c);
extern "C" const char *_Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310 *tbl, int key);
extern "C" void __clear(void *buffer, unsigned long size);
extern "C" void _Z27AppendTaggedString_0215b8c8P17DstHolder0215b8c8PKci(DstHolder0215b8c8 *dst, const char *src, int n);
extern "C" void _Z23AppendFormatted02041facPcii(char *buf, int str, int n);
extern "C" void *_Z26GetGlobalField0x1c020421a0v();
extern "C" void func_02046380(void *messages);
void StoreInArray0x8b0(StoreStruct *messages, int index, int value);
void SetByteInRange(unsigned char *messages, int index, unsigned char digits);
void SetByteAtIndex(unsigned char *messages, int index, unsigned char value);
void AppendHeightTag(char *buf, int h);
extern "C" void func_02046608(void *messages, int a, const char *format, char *output, int size, int b, int c);
extern "C" void _Z20AppendString02042058PcPKc(char *buf, const char *str);

// USA: func_ov002_021605d4
extern "C" ARM void func_ov002_021605d4(char *self, char *buf) {
    char text[0x80];
    int slots[4];
    char line[0x40];
    DstHolder0215b8c8 holder;
    if (buf == 0) return;
    GameState *gs = _ZN9GameState11GetInstanceEv();
    short idx     = *(short *) (self + 0x1c08);
    func_ov002_02157480(self, slots);
    int slot = slots[idx];
    int ok   = (slot >= 0 && slot <= 3);
    if (!ok) return;
    unsigned char *c = (unsigned char *) GetCombatantWithFlag0x100(gs, slot);
    if (c == 0) return;
    unsigned char *f = GetFieldAt0x150(c);
    if (f == 0) return;
    const char *name = _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310 *) (self + 0x20), 0x1005);
    __clear(text, sizeof(text));
    holder.dst = text;
    _Z27AppendTaggedString_0215b8c8P17DstHolder0215b8c8PKci(&holder, name, 0);
    _Z23AppendFormatted02041facPcii(buf, (int) text, 0x10);
    void *msg = _Z26GetGlobalField0x1c020421a0v();
    func_02046380(msg);
    StoreInArray0x8b0((StoreStruct *) msg, 0, *(unsigned short *) (f + 0x564));
    SetByteInRange((unsigned char *) msg, 0, 4);
    SetByteAtIndex((unsigned char *) msg, 0, 1);
    __clear(line, sizeof(line));
    AppendHeightTag(buf, -1);
    func_02046608(msg, 8, _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310 *) (self + 0x20), 0x1006), line,
                  0x100, 0, 0);
    _Z20AppendString02042058PcPKc(buf, line);
}
