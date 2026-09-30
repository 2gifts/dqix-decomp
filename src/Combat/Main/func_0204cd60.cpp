#include <globaldefs.h>
#include <std_library_functions.h>
#include <System/BGBases.h>

struct Wnd0204cd60 {
    char pad0[8];
    unsigned char* buf;
    short arrA[18];
    short arrB[18];
    short arrC[18];
    short arrD[18];
    char pad9C[4];
    int fA0;
    int fA4;
    short fA8;
    short fAA;
    char padAC[4];
    short fB0;
    short fB2;
    char padB4[2];
    short fB6;
    char padB8[2];
    short fBA;
    short fBC;
    short fBE;
    char padC0[5];
    unsigned char flags;
    unsigned char fC6;
    unsigned char fC7;
    char padC8[0x10];
    unsigned char bit0 : 2;
    unsigned char useBg : 1;
    unsigned char bit3 : 5;
    char padD9[2];
    signed char margins[4];
};

struct Glyph0204cd60 {
    int val;
    char width;
    signed char skip : 6;
    signed char unused : 2;
    char pad6[2];
};

extern "C" void* __clear(void* dst, int count);
extern "C" int func_020420e8(char* str, int id);
extern "C" int _Z27FindEntryIndexByKey020424e4ii(int key, int tableIdx);
extern "C" Glyph0204cd60* _Z23GetBoundedEntry020425b4ii(int idx, int tableIdx);
extern "C" int _Z22LookupKeyValue020425e4iii(int a, int b, int tableIdx);
extern "C" void func_0204cc68(Wnd0204cd60* wnd, int mode, short x0, short y0, short x1, short y1);
extern "C" void func_0204f914(Wnd0204cd60* wnd, int mode, short x0, short y0, short x1, short y1);
extern "C" void func_0204ea5c(Wnd0204cd60* wnd);
extern "C" void func_0204ecb4(Wnd0204cd60* wnd, int a, int b, int w, int h, signed char* margins);
extern "C" int func_0204fc40(void* unused0, char** cursor, char* tag, short* out, int max);
extern "C" void func_0204f3bc(Wnd0204cd60* wnd, int idx);
extern "C" void func_0204df9c(Wnd0204cd60* wnd, Glyph0204cd60* glyph, int x, int y, int color, int font);
extern "C" void func_0204fae8(Wnd0204cd60* wnd);
extern "C" void func_0204fa0c(Wnd0204cd60* wnd, short x, short y);

extern const unsigned char data_020e7bdc[];
extern char data_020f0248[];
extern char data_020f024e[];
extern char data_020f0251[];
extern char data_020f0254[];
extern char data_020f0258[];
extern char data_020f025b[];
extern char data_020f025e[];
extern char data_020f0262[];
extern char data_020f0268[];
extern char data_020f026f[];
extern char data_020f0276[];
extern char data_020f027c[];
extern char data_020f0283[];
extern char data_020f0288[];
extern char data_020f028c[];
extern char data_020f0292[];
extern char data_020f0298[];
extern char data_020f029d[];
extern char data_020f02a0[];
extern char data_020f02a3[];
extern char data_020f02aa[];
extern char data_020f02b1[];
extern char data_020f02b9[];
extern char data_020f02bd[];
extern char data_020f02c1[];
extern char data_020f02c5[];
extern char data_020f02c9[];
extern char data_020f02cf[];
extern char data_020f02d4[];
extern char data_020f02db[];
extern char data_020f02e2[];
extern char data_020f02e7[];
extern char data_020f02eb[];
extern char data_020f02f1[];

static inline void SetCursorPos(Wnd0204cd60* wnd, short x, short y) {
    wnd->fBC = x;
    wnd->fBE = y;
}

// USA: func_0204cd60
extern "C" ARM void func_0204cd60(Wnd0204cd60* wnd, char* text, short border, short font) {
    char* p;
    short out[8];
    char tmp[0x100];
    int sel;
    short x;
    short y;
    unsigned char* dst;
    short pitch;
    unsigned char* buf;
    short stride;
    Glyph0204cd60* glyph;
    unsigned char prev;
    int code;
    int hilite;
    short boxOn;
    short boxCount;
    short boxSize;
    short frameOn, frameW, padL, padT, padR, padB;
    int cursorIdx;
    int adj0, adj1, adj2, adj3;
    int sel2;
    short insL, insT, insR, insB;
    int glyphH;
    short savedX;
    short lineH;
    int mode;
    int color, colorIdx, saveColor, saveColorIdx;
    int handled;
    short ax, aw, ay, ah;
    short x0, x1, y0, y1;
    unsigned char adv;
    int ch;
    char* cursor;

    cursor = text;
    if (cursor == 0) return;

    boxOn = 0;
    prev = 0xff;
    wnd->flags &= ~2;
    hilite = -1;
    pitch = (wnd->fA8 << 3) >> 1;
    lineH = wnd->fB6;
    stride = lineH * pitch;
    y = wnd->fB2;
    buf = wnd->buf;
    dst = buf + y * pitch;
    boxCount = boxOn;
    boxSize = boxOn;
    frameOn = boxOn;
    frameW = boxOn;
    padL = boxOn;
    padT = boxOn;
    padR = boxOn;
    padB = boxOn;
    sel2 = adj3 = cursorIdx = adj2 = adj1 = adj0 = hilite;
    insL = boxOn;
    insT = boxOn;
    insR = boxOn;
    insB = boxOn;
    sel = hilite;
    glyphH = wnd->fC7;
    x = wnd->fB0;

    if (wnd->useBg) {
        memcpy(wnd->buf, (char*)GetSubBG2CharacterBase() + wnd->fA0, wnd->fA4);
    } else {
        memset(wnd->buf, 0, wnd->fA4);
    }

    if (wnd->flags & 4) {
        mode = 0;
    } else {
        if (!wnd->useBg) {
            short rx = 0;
            short ry = 0;
            short rw = wnd->fA8 << 3;
            short rh = wnd->fAA << 3;
            ry += wnd->margins[0];
            rh -= wnd->margins[0] + wnd->margins[1];
            rx += wnd->margins[2];
            rw -= wnd->margins[2] + wnd->margins[3];
            func_0204f914(wnd, 0x11, rx, ry, rw, rh);
            func_0204ea5c(wnd);
        }
        mode = 0x11;
    }

    if (border > 0) {
        short w = wnd->fA8 << 3;
        short h = wnd->fAA << 3;
        func_0204cc68(wnd, 3, 0, 0, w, h);
        func_0204cc68(wnd, mode, (int)border, (int)border, w - border, h - border);
    } else if (!(wnd->flags & 0x10)) {
        func_0204ecb4(wnd, 0, 0, wnd->fA8, wnd->fAA, wnd->margins);
    }

    color = 0xf0;
    colorIdx = 0xf;
    saveColor = color;
    saveColorIdx = colorIdx;

    while ((ch = *cursor) != 0) {
        int next = cursor[1];
        if ((ch == '\\' && next == 'n') || (ch == '\r' && next == '\n')) {
            y += lineH;
            x = wnd->fB0;
            cursor += 2;
            dst += stride;
            continue;
        }
        if (ch == '\n') {
            y += lineH;
            x = wnd->fB0;
            cursor += 1;
            dst += stride;
            continue;
        }
        if (ch == '<') {
            handled = 1;
            p = cursor + 1;
            if (func_0204fc40(wnd, &p, data_020f0248, out, 1)) {
                switch (out[0]) {
                case 8:
                    glyphH = 8;
                    lineH = 9;
                    break;
                case 12:
                    glyphH = 12;
                    lineH = 13;
                    break;
                default:
                    glyphH = 10;
                    lineH = wnd->fB6;
                    break;
                }
                if (wnd->fBA != 0) lineH = wnd->fBA;
            } else if (func_0204fc40(wnd, &p, data_020f024e, out, 1)) {
                x = out[0];
                prev = 0xff;
            } else if (func_0204fc40(wnd, &p, data_020f0251, out, 1)) {
                y = out[0];
                dst = buf + pitch * y;
                prev = 0xff;
            } else if (func_0204fc40(wnd, &p, data_020f0254, out, 2)) {
                y = out[1];
                x = out[0];
                dst = buf + pitch * y;
                prev = 0xff;
            } else if (func_0204fc40(wnd, &p, data_020f0258, out, 1)) {
                x += out[0];
                prev = 0xff;
            } else if (func_0204fc40(wnd, &p, data_020f025b, out, 1)) {
                dst += pitch * out[0];
                y += out[0];
                prev = 0xff;
            } else if (func_0204fc40(wnd, &p, data_020f025e, out, 2)) {
                x += out[0];
                y += out[1];
                dst += pitch * out[1];
                prev = 0xff;
            } else if (func_0204fc40(wnd, &p, data_020f0262, out, 1)) {
                func_0204f3bc(wnd, out[0]);
            } else if (func_0204fc40(wnd, &p, data_020f0268, out, 4)) {
                func_0204cc68(wnd, (unsigned char)out[0], out[1], out[3], out[2], out[3] + 1);
            } else if (func_0204fc40(wnd, &p, data_020f026f, out, 4)) {
                func_0204cc68(wnd, (unsigned char)out[0], out[1], out[2], out[1] + 1, out[3]);
            } else if (func_0204fc40(wnd, &p, data_020f0276, out, 0)) {
                color = 0xf0;
                colorIdx = 0xf;
            } else if (func_0204fc40(wnd, &p, data_020f027c, out, 0)) {
                color = 0xd0;
                colorIdx = 0xd;
            } else if (func_0204fc40(wnd, &p, data_020f0283, out, 0)) {
                color = 0xb0;
                colorIdx = 0xb;
            } else if (func_0204fc40(wnd, &p, data_020f0288, out, 0)) {
                color = 0x90;
                colorIdx = 0x9;
            } else if (func_0204fc40(wnd, &p, data_020f028c, out, 1)) {
                out[0] &= 0xf;
                color = (unsigned char)(out[0] << 4);
                colorIdx = (unsigned char)out[0];
            } else if (func_0204fc40(wnd, &p, data_020f0292, out, 5)) {
                func_0204cc68(wnd, (unsigned char)out[0], out[1], out[2], out[1] + out[3], out[2] + out[4]);
            } else if (func_0204fc40(wnd, &p, data_020f0298, out, 1)) {
            } else if (func_0204fc40(wnd, &p, data_020f029d, out, 1)) {
                sel = out[0];
                if (sel >= 0 && sel < 18) {
                    wnd->arrA[sel] = x;
                    wnd->arrB[sel] = y;
                }
                if (sel >= 0 && sel == hilite) {
                    saveColor = color;
                    saveColorIdx = colorIdx;
                    color = 0xe0;
                    colorIdx = 0xe;
                } else if (sel >= 0 && sel == sel2) {
                    saveColor = color;
                    saveColorIdx = colorIdx;
                    color = 0x50;
                    colorIdx = 0x5;
                }
            } else if (func_0204fc40(wnd, &p, data_020f02a0, out, 0)) {
                if (sel >= 0) {
                    if (sel == hilite || sel == sel2) {
                        color = saveColor;
                        colorIdx = saveColorIdx;
                    }
                }
                if (sel >= 0 && sel < 18) {
                    wnd->arrC[sel] = x - wnd->arrA[sel];
                    wnd->arrD[sel] = glyphH + (y - wnd->arrB[sel]) + 1;
                    if (wnd->arrC[sel] < 4) wnd->arrC[sel] = 4;
                }
                if (sel2 >= 0 && sel == sel2) {
                    if (!(wnd->flags & 0x10) && (adj0 >= 0 || adj1 >= 0 || adj2 >= 0 || adj3 >= 0)) {
                        wnd->arrA[sel] -= insL + wnd->fC6;
                        wnd->arrB[sel] -= insT;
                        wnd->arrC[sel] += insL + insR;
                        wnd->arrD[sel] += insT + insB;
                    }
                    wnd->flags |= 2;
                }
                if (!(wnd->flags & 0x10) && frameOn != 0) {
                    wnd->arrC[sel] = frameW;
                    ax = wnd->arrA[sel];
                    aw = wnd->arrC[sel];
                    ay = wnd->arrB[sel];
                    ah = wnd->arrD[sel];
                    x0 = ax - padL;
                    x1 = padR + (ax + aw);
                    y0 = ay - padT;
                    y1 = padB + (ay + ah);
                    func_0204cc68(wnd, 3, x0 + 1, y0, x1 - 1, y0 + 1);
                    func_0204cc68(wnd, 3, x0 + 1, y1 - 1, x1 - 1, y1);
                    func_0204cc68(wnd, 3, x0, y0 + 1, x0 + 1, y1 - 1);
                    func_0204cc68(wnd, 3, x1 - 1, y0 + 1, x1, y1 - 1);
                }
                sel = -1;
            } else if (func_0204fc40(wnd, &p, data_020f02a3, out, 2)) {
            } else if (func_0204fc40(wnd, &p, data_020f02aa, out, 5)) {
                sel2 = out[0];
                insL = out[1];
                insT = out[2];
                insR = out[3];
                insB = out[4];
            } else if (func_0204fc40(wnd, &p, data_020f02b1, out, 1)) {
                cursorIdx = out[0];
            } else if (func_0204fc40(wnd, &p, data_020f02b9, out, 3)) {
                adj0 = (signed char)out[0];
            } else if (func_0204fc40(wnd, &p, data_020f02bd, out, 3)) {
                adj1 = (signed char)out[0];
            } else if (func_0204fc40(wnd, &p, data_020f02c1, out, 3)) {
                adj2 = (signed char)out[0];
            } else if (func_0204fc40(wnd, &p, data_020f02c5, out, 3)) {
                adj3 = (signed char)out[0];
            } else if (func_0204fc40(wnd, &p, data_020f02c9, out, 5)) {
                frameOn = 1;
                frameW = out[0];
                padL = out[1];
                padT = out[2];
                padR = out[3];
                padB = out[4];
                if (frameW == 0) frameOn = 0;
            } else if (func_0204fc40(wnd, &p, data_020f02cf, out, 2)) {
                boxCount = out[0];
                boxSize = out[1];
            } else if (func_0204fc40(wnd, &p, data_020f02d4, out, 1)) {
                boxOn = 1;
                func_0204f3bc(wnd, out[0]);
                dst = buf + wnd->fB2 * pitch;
                y = (out[0] - 10) >> 1;
            } else if (func_0204fc40(wnd, &p, data_020f02db, out, 0)) {
                if (boxOn != 0) {
                    y = wnd->fB2;
                    x = wnd->fB0;
                    dst = buf + y * pitch;
                    boxOn = 0;
                }
            } else if (func_0204fc40(wnd, &p, data_020f02e2, out, 1)) {
                hilite = out[0];
            } else if (func_0204fc40(wnd, &p, data_020f02e7, out, 1)) {
                x = out[0];
                prev = 0xff;
                savedX = x;
                __clear(tmp, 0x100);
                char* start = p;
                char* end = strstr(start, data_020f02eb);
                if (end != 0) {
                    int len = end - start;
                    if (len < 0x100) {
                        memcpy(tmp, start, len);
                        x -= func_020420e8(tmp, font);
                    }
                }
            } else if (func_0204fc40(wnd, &p, data_020f02f1, out, 0)) {
                x = savedX;
                prev = 0xff;
            } else {
                handled = 0;
            }
            if (handled) {
                cursor = p;
                continue;
            }
        }
        adv = data_020e7bdc[font] + 1;
        int idx = _Z27FindEntryIndexByKey020424e4ii((int)cursor, font);
        if (idx >= 0) {
            code = idx & 0xff;
            glyph = _Z23GetBoundedEntry020425b4ii(idx, font);
            x += _Z22LookupKeyValue020425e4iii(prev, code, font);
            func_0204df9c(wnd, glyph, x, y, colorIdx, font);
            prev = code;
            adv = (unsigned char)(glyph->width + 1);
            cursor += glyph->skip;
        } else {
            if (ch != ' ') {
                func_0204df9c(wnd, _Z23GetBoundedEntry020425b4ii(0, font), x, y, colorIdx, font);
            }
            cursor++;
        }
        x += adv;
    }

    { int dbg = 0; if (dbg) func_0204fae8((Wnd0204cd60*)dst); }
    if (wnd->flags & 8) func_0204fae8(wnd);
    if (!(wnd->flags & 0x10)) {
        if (sel2 >= 0) wnd->flags |= 2;
        if (cursorIdx >= 0) {
            short cx = wnd->arrA[cursorIdx] - 8;
            short cy = wnd->arrB[cursorIdx] - 1;
            wnd->fBC = cx;
            wnd->fBE = cy;
            func_0204fa0c(wnd, cx, cy);
        }
    }
    if (boxCount > 0 && boxSize > 0) {
        short base = y + glyphH;
        short bx = (short)(wnd->fA8 << 3) - (boxSize * 2 + 2);
        short by = base - boxSize;
        short i;
        for (i = 0; i < boxCount; i++) {
            func_0204cc68(wnd, 0xf, bx, by, bx + boxSize, by + boxSize);
            bx -= boxSize * 2;
        }
    }
}
