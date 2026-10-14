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

int GetWordFromTable02042648(int idx);
int FindEntryIndexByKey020424e4(int key, int tableIdx);
struct Glyph0218e240* GetBoundedEntry020425b4(int idx, int tableIdx);
int LookupKeyValue020425e4(int a, int b, int tableIdx);
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
    int font = GetWordFromTable02042648(1) & 0xff;
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
        unsigned char code = FindEntryIndexByKey020424e4((int)text, 1);
        if (code != 0xff) {
                        glyph = GetBoundedEntry020425b4(code, 1);
            if (outline != 0) {
                func_ov016_0218e17c(dst, x - 1, y, glyph, 0, 1);
                func_ov016_0218e17c(dst, x + 1, y, glyph, 0, 1);
                func_ov016_0218e17c(dst, x, y - 1, glyph, 0, 1);
                func_ov016_0218e17c(dst, x, y + 1, glyph, 0, 1);
            }
            x += LookupKeyValue020425e4(prev, code, 1);
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
