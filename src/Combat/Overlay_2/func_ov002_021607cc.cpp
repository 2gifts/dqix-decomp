#include "GameState/GameState.h"
#include <globaldefs.h>

struct Container020e0310;

struct Ints8_0216caa4 {
    int v[8];
};
struct Ints7_0216ca88 {
    int v[7];
};

int AppendFrameTag02041c08(char *dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char *dst, int cursor);
int AppendWireTag02041c64(char *dst, int a1, int a2, int a3, int a4, int a5);
char *GetFieldByKey020e0434(struct Container020e0310 *c, int key);
extern "C" int func_020420e8(const char *text, int large);
int AppendXTag(char *dst, int x);
int AppendString02042058(char *dst, const char *src);
int AppendLineTag02041cc0(char *dst, int a1);
extern "C" void *__clear(void *destination, int count);
void AppendXYTag(char *text, int x, int y);
int AppendDotLeaderLabel02042084(char *buffer, char *label, int width, int extra);
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
        AppendFrameTag02041c08(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);
    AppendWireTag02041c64(dst, 0x64, 2, 2, 2, 2);
    char *title = GetFieldByKey020e0434((struct Container020e0310 *) (self + 0x20), 0x1194);
    AppendXTag(dst, (0x98 - func_020420e8(title, 0)) >> 1);
    AppendString02042058(dst, title);
    AppendLineTag02041cc0(dst, 0x11);
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
            AppendString02042058(
                buf, GetFieldByKey020e0434((struct Container020e0310 *) (self + 0x20), (short) key));
        } else {
            AppendDotLeaderLabel02042084(
                buf, GetFieldByKey020e0434((struct Container020e0310 *) (self + 0x20), (short) key),
                0x64, 0);
        }
        AppendNameTag(dst, i, buf);
    }
    AppendWireTag02041c64(dst, 0, 2, 2, 2, 2);
    AppendLineTag02041cc0(dst, 0xa2);
    AppendXYTag(dst, 0x2b, ys.v[i]);
    AppendNameTag(dst, i, GetFieldByKey020e0434((struct Container020e0310 *) (self + 0x20), 0x11fa));
}
