#include <globaldefs.h>

struct Container020e0310;

extern "C" void *_ZN9GameState11GetInstanceEv();
int ReadBattleField0x64f4Byte();
extern "C" void _Z22AppendFrameTag02041c08Pciiiii(char *buf, int x, int a, int b, int c, int d);
void AppendCursorTag(char *buf, int x);
extern "C" const char *_Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310 *tbl, int key);
extern "C" void _Z23AppendFormatted02041facPcii(char *buf, int str, int n);
void AppendNameTag(char *buf, int i, const char *str);
extern "C" void _Z20AppendString02042058PcPKc(char *buf, const char *str);

// USA: func_ov002_0215c52c
extern "C" ARM void func_ov002_0215c52c(unsigned char *self, char *buf, int frame) {
    if (buf == 0) return;
    short key = 0x3ea;
    int n     = 3;
    short x   = *(short *) (self + 0x1be4);
    _ZN9GameState11GetInstanceEv();
    if (ReadBattleField0x64f4Byte() == 0) n = 2;
    if (frame) _Z22AppendFrameTag02041c08Pciiiii(buf, x, 8, 5, 5, 5);
    AppendCursorTag(buf, x);
    _Z23AppendFormatted02041facPcii(
        buf, (int) _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310 *) (self + 0x20), 1000), 0x18);
    for (int i = 0; i < n; i++) {
        AppendNameTag(buf, i, _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310 *) (self + 0x20), key++));
        if (i != n - 1) _Z20AppendString02042058PcPKc(buf, *(const char **) (self + 0x1bdc));
    }
}
