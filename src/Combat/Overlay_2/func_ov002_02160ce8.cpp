#include "GameState/GameState.h"
#include <globaldefs.h>

struct Container020e0310;

extern "C" int _Z22AppendFrameTag02041c08Pciiiii(char *dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag(char *dst, int cursor);
extern "C" char *_Z21GetFieldByKey020e0434P17Container020e0310i(struct Container020e0310 *c, int key);
extern "C" int func_020420e8(const char *text, int large);
void AppendXYTag(char *text, int x, int y);
extern "C" int _Z20AppendString02042058PcPKc(char *dst, const char *src);
extern "C" int _Z23AppendFormatted02041facPcii(char *dst, int str, int b);
int AppendHeightTag(char *dst, int h);
int AppendPaletteTag(char *dst, int palette);
int AppendNameTag(char *dst, int n, const char *name);
int AppendXTag(char *dst, int x);
int AppendSourceRectTag(char *dst, int a, int b, int c, int d, int e);
extern "C" int _Z21AppendLineTag02041cc0Pci(char *dst, int a1);
extern "C" void *__clear(void *destination, int count);

extern "C" char data_ov002_0216d2b3[];

// USA: func_ov002_02160ce8
extern "C" ARM void func_ov002_02160ce8(unsigned char *self, char *dst, int flag) {
    unsigned char *sels[3];
    short key;
    int selX;
    unsigned char r;
    short k;
    int x;
    unsigned char c;
    if (dst == NULL) return;
    GameState::GetInstance();
    int cursor  = *(short *) (self + 0x1c0e);
    int row     = 0;
    int nameIdx = 3;
    __clear(sels, 0xc);
    sels[0] = self + 0x1c2c;
    sels[1] = self + 0x1c2d;
    if (flag) {
        _Z22AppendFrameTag02041c08Pciiiii(dst, cursor, 8, 5, 5, 5);
    }
    AppendCursorTag(dst, cursor);
    char *title = _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310 *) (self + 0x20), 0xfa6);
    AppendXYTag(dst, (0xf0 - func_020420e8(title, 0)) >> 1, 4);
    _Z20AppendString02042058PcPKc(dst, title);
    _Z23AppendFormatted02041facPcii(dst, (int) data_ov002_0216d2b3, 0x10);
    key = 0x11f8;
    for (r = 0; r < 3; r++) {
        if (r == 2) {
            AppendHeightTag(dst, 7);
        }
        AppendPaletteTag(dst, 0xf);
        AppendNameTag(dst, row,
                      _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310 *) (self + 0x20), key++));
        if (r != 2) {
            AppendXTag(dst, 0x5a);
            k = 0x11fb;
            AppendPaletteTag(dst, 3);
            _Z20AppendString02042058PcPKc(
                dst, _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310 *) (self + 0x20), k++));
            x = 0x7d;
            for (c = 0; c < 5; c++) {
                AppendXTag(dst, x);
                int pal = 0xf;
                if (c + 1 == *sels[r]) {
                    pal  = 5;
                    selX = x;
                }
                AppendPaletteTag(dst, pal);
                AppendNameTag(dst, nameIdx,
                              _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310 *) (self + 0x20), k++));
                nameIdx++;
                x += 0x10;
            }
            AppendXTag(dst, 0xce);
            AppendPaletteTag(dst, 3);
            _Z20AppendString02042058PcPKc(
                dst, _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310 *) (self + 0x20), k));
            AppendXTag(dst, selX + 3);
            AppendPaletteTag(dst, 0xf);
            _Z20AppendString02042058PcPKc(
                dst, _Z21GetFieldByKey020e0434P17Container020e0310i((struct Container020e0310 *) (self + 0x20), 0x1202));
        }
        if (r != 2) {
            _Z20AppendString02042058PcPKc(dst, *(char **) (self + 0x1bdc));
        }
        row++;
    }
    AppendSourceRectTag(dst, 0xf, 0x4e, 0x10, 1, 0x24);
    _Z21AppendLineTag02041cc0Pci(dst, 0x34);
}
