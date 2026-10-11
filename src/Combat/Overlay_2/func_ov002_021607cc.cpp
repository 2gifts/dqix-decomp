#include "GameState/GameState.h"
#include <globaldefs.h>

struct Container020e0310;

struct Ints8_0216caa4 {
    int v[8];
};
struct Ints7_0216ca88 {
    int v[7];
};

extern "C" int _Z22AppendFrameTag02041c08Pciiiii(char *dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char *dst, int cursor);
extern "C" int _Z21AppendWireTag02041c64Pciiiii(char *dst, int a1, int a2, int a3, int a4, int a5);
extern "C" char *_Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310 *c, int key);
extern "C" int func_020420e8(const char *text, int large);
int AppendXTag(char *dst, int x);
extern "C" int _Z20AppendString02042058PcPKc(char *dst, const char *src);
extern "C" int _Z21AppendLineTag02041cc0Pci(char *dst, int a1);
extern "C" void *__clear(void *destination, int count);
void AppendXYTag(char *text, int x, int y);
extern "C" int _Z28AppendDotLeaderLabel02042084PcS_ii(char *buffer, char *label, int width, int extra);
int AppendNameTag(char *dst, int n, const char *name);

extern Ints8_0216caa4 data_ov002_0216caa4;
extern Ints7_0216ca88 data_ov002_0216ca88;

// USA: func_ov002_021607cc
extern "C" ARM void func_ov002_021607cc(unsigned char *self, char *dst, int flag) {
    if (dst == NULL) return;
    GameState::GetInstance();
    int cursor        = *(short *) (self + 0x1c0a);
    Ints8_0216caa4 ys = data_ov002_0216caa4;
    if (flag) {
        _Z22AppendFrameTag02041c08Pciiiii(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);
    _Z21AppendWireTag02041c64Pciiiii(dst, 0x64, 2, 2, 2, 2);
    char *title = _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310 *) (self + 0x20), 0x1194);
    AppendXTag(dst, (0x98 - func_020420e8(title, 0)) >> 1);
    _Z20AppendString02042058PcPKc(dst, title);
    _Z21AppendLineTag02041cc0Pci(dst, 0x11);
    Ints7_0216ca88 offs = data_ov002_0216ca88;
    char buf[0x40];
    int i;
    for (i = 0; i < 7; i++) {
        signed char v = *(signed char *) (self + offs.v[i] + 0x1c7c);
        int key;
        if (v < 0) {
            key = 0x119d;
        } else {
            key = v;
            key += 0x119d;
        }
        __clear(buf, 0x40);
        AppendXYTag(dst, 0x2b, ys.v[i]);
        if (key != 0x119d) {
            _Z20AppendString02042058PcPKc(
                buf, _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310 *) (self + 0x20), (short) key));
        } else {
            _Z28AppendDotLeaderLabel02042084PcS_ii(
                buf, _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310 *) (self + 0x20), (short) key),
                0x64, 0);
        }
        AppendNameTag(dst, i, buf);
    }
    _Z21AppendWireTag02041c64Pciiiii(dst, 0, 2, 2, 2, 2);
    _Z21AppendLineTag02041cc0Pci(dst, 0xa2);
    AppendXYTag(dst, 0x2b, ys.v[i]);
    AppendNameTag(dst, i, _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310 *) (self + 0x20), 0x11fa));
}
