#include <globaldefs.h>
#include <std_library_functions.h>

struct Glyph0218e240 {
    int val;
    signed char width;
    signed char skip : 6;
    signed char rest : 2;
    char pad6[2];
};

extern "C" char data_ov016_0219d06d[];
extern "C" char data_ov016_0219d06f[];

extern "C" int _Z24GetWordFromTable02042648i(int idx);
extern "C" int _Z27FindEntryIndexByKey020424e4ii(int key, int tableIdx);
extern "C" struct Glyph0218e240* _Z23GetBoundedEntry020425b4ii(int idx, int tableIdx);
extern "C" int _Z22LookupKeyValue020425e4iii(int a, int b, int tableIdx);
extern "C" void* __clear(void* dst, int count);
extern "C" int func_020420e8(char* str, int id);
extern "C" int func_02001aec(unsigned char* a, unsigned char* b, int n);
extern "C" void func_ov016_0218e17c(unsigned short* dst, int x, int y, void* glyph, int color, int fontId);

// USA: func_ov016_0218e240
extern "C" ARM void func_ov016_0218e240(unsigned short* dst, char* text, unsigned short color, int x0, int y0, unsigned char center, unsigned short outline, int count) {
    int i = 0;
    int x = x0;
    struct Glyph0218e240* glyph;
    int line;
    int y = y0;
    short prev = 0xff;
    int font = _Z24GetWordFromTable02042648i(1) & 0xff;
    int adv;
    int xs[3];
    xs[0] = x;
    xs[1] = x;
    xs[2] = x;

    if (center != 0) {
        int len = 1;
        char* hit = strstr(text, data_ov016_0219d06d);
        if (hit == 0) {
            hit = strstr(text, data_ov016_0219d06f);
            len = 2;
        }
        if (hit != 0) {
                        int off = hit - text;
            char buf[0x200];
            __clear(buf, 0x200);
            sprintf(buf, text);
            memset(buf + off, 0, len);
            xs[0] = (0x100 - func_020420e8(buf, 1)) >> 1;
            xs[1] = (0x100 - func_020420e8(buf + (off + len), 1)) >> 1;
            y -= 0xe;
        } else {
            xs[0] = (0x100 - func_020420e8(text, 1)) >> 1;
        }
    }

    line = 0;
    x = xs[line];
    line++;

    for (;;) {
        if (count <= i) break;
        if (text[0] == 0) break;
        int step = 1;
                int ctrl = (text[0] == '\n') ? step : 0;
        if (func_02001aec((unsigned char*)text, (unsigned char*)data_ov016_0219d06f, 2) == 0) {
                        ctrl = 1; 1;
            step = 2;
        }
        if (ctrl != 0) {
            x = xs[line];
            text += step;
            line++;
            prev = 0xff;
            y += 0xe;
            continue;
        }

                int wide = font + 1;
        adv = 1;
        unsigned char code = _Z27FindEntryIndexByKey020424e4ii((int)text, 1);
        if (code != 0xff) {
                        glyph = _Z23GetBoundedEntry020425b4ii(code, 1);
            if (outline != 0) {
                func_ov016_0218e17c(dst, x - 1, y, glyph, 0, 1);
                func_ov016_0218e17c(dst, x + 1, y, glyph, 0, 1);
                func_ov016_0218e17c(dst, x, y - 1, glyph, 0, 1);
                func_ov016_0218e17c(dst, x, y + 1, glyph, 0, 1);
            }
            x += _Z22LookupKeyValue020425e4iii(prev, code, 1);
            func_ov016_0218e17c(dst, x, y, glyph, color, 1);
            prev = code;
                        wide = glyph->width + 1;
            adv = glyph->skip;
        } else {
            prev = 0xff;
        }
        x += wide;
        text += adv;
        i++;
    }
}
