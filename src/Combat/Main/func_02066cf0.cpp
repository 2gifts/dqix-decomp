#include <globaldefs.h>

struct CE28Obj;
void LoadStateBytePair0206b804(char* obj, int* out1, int* out2);
int IsField440Empty(struct CE28Obj* obj);
struct Field440Obj0202f6a4;
void SetupField440Type1(struct Field440Obj0202f6a4* obj);
void UpdateTimedState0202f380(void* obj, int amount);
struct Field440XYObj;
void GetField440XY(struct Field440XYObj* obj, short* outX, short* outY);
struct Holder02042c24;
void SetSubstructXY02042c24(struct Holder02042c24* holder, int x, int y);
void EmitScaledField0x440(void* obj, int a, int b);
bool IsCommandInRange02067a9c(void* obj, void* src);
void MeasureTextWidth0206b6b8(unsigned char* obj);
int GetWordFromTable02042648(int idx);
bool IsHighByteFF02044494(void* obj, void* src);
int LookupKeyValue020425e4(int a, int b, int tableIdx);
int GetGlobalField0x1c020421a0();
struct Holder020416cc;
int GetField0OfSubstructAt0x18(struct Holder020416cc* holder);
void UpdateObj020e15f8Entry(char* obj, int idx, int a2, int a3, int a4, unsigned char a5, unsigned char a6);
struct SetIntIntShortAt0xcStruct;
void SetIntIntShortAt0xc(struct SetIntIntShortAt0xcStruct* s, int a, int b, short c);
void CallFunc0205c96cIfMode6AndFlag(char* obj, int flag);

extern "C" void _Z15Forward02044830v(void* obj, int* lineX, int* lineY);
int AllocateVRAMStagingMemory(unsigned int);
extern "C" int _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(int a, int b, int c, int d, unsigned char e, unsigned char f);
int FreeVRAMStagingMemory(void const*);

extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, int c, int d);
extern "C" void* __clear(void* dst, int count);
extern "C" void func_02066a6c(void* obj, int flag);
extern "C" void func_020e2110(void* target);
extern "C" void func_020675fc(void* obj);
extern "C" void func_020654b8(void* obj, int cfg, void* glyph, short x, short y, int flags);
extern "C" void func_02045864(int x, int y, void* metrics, int staging, int p5, int p6, int p7, unsigned char table);
extern "C" void func_020417b0(void* glyph, unsigned short font, void* palette, int alpha);
extern "C" void func_0204459c(void* obj, int flag);
extern "C" void func_020653e4(int a, int b);

extern short data_020e7e54[];
extern short data_020e7e3c[];
extern int data_021077fc;

struct GlyphMetrics02066cf0 {
    char pad[4];
    signed char advance;
};

struct Glyph02066cf0 {
    char pad[0x17];
    unsigned char width;
    GlyphMetrics02066cf0* metrics;
};

struct TextBox02066cf0 {
    char pad0[0x34];
    int context;
    void* target;
    char pad3c[4];
    unsigned int drawn;
    int field44;
    char pad48[4];
    unsigned short* text;
    char pad50[4];
    int field54;
    int field58;
    char pad5c[0x10];
    int field6c;
    char pad70[4];
    unsigned int start;
    unsigned int end;
    char pad7c[0xc];
    unsigned int minStart;
    char pad8c[0x998 - 0x8c];
    int active;
    char pad99c[0x9b0 - 0x99c];
    int fade;
    char pad9b4[4];
    Glyph02066cf0 glyphs[80];
    char pad1278[0x1848 - 0x1278];
    char palette[0x10];
    int lineX;
    int lineY;
    char pad1860[4];
    int lineHeight;
    int yOffset;
    char pad186c[0x187c - 0x186c];
    unsigned short font;
    char pad187e[0x195b - 0x187e];
    unsigned char effects;
    char pad195c[0x19b1 - 0x195c];
    unsigned char showName;
    char pad19b2[0x19b8 - 0x19b2];
    unsigned char customLayout;
    unsigned char usePalette;
    char pad19ba[0x19c5 - 0x19ba];
    unsigned char checkFirst;
    char pad19c6[0x19cb - 0x19c6];
    unsigned char refreshHolder;
    unsigned char hidden;
    char pad19cd;
    unsigned char toVram;
    char pad19cf[0x19dc - 0x19cf];
    unsigned char table;
    char pad19dd[3];
    char holder[0x1e28 - 0x19e0];
    void* texture;
};

struct GlobalFlags02066cf0 {
    char pad[0x195b];
    unsigned char effects;
};

// USA: func_02066cf0
extern "C" ARM void func_02066cf0(TextBox02066cf0* obj, int flag) {
    Glyph02066cf0* glyph;
    int x;
    int y;
    unsigned int pos;
    unsigned char width;

    if (obj->hidden) return;

    int offsetX, offsetY;
    LoadStateBytePair0206b804((char*)obj, &offsetX, &offsetY);

    if ((obj->active && obj->showName) || obj->refreshHolder) {
        if (obj->refreshHolder) {
            if (IsField440Empty((CE28Obj*)obj->holder)) {
                SetupField440Type1((Field440Obj0202f6a4*)obj->holder);
                UpdateTimedState0202f380(obj->holder, 1);
            }
        }

        if (obj->active && obj->showName) {
            func_02066a6c(obj, flag);
        }

        short boxX, boxY;
        GetField440XY((Field440XYObj*)obj->holder, &boxX, &boxY);
        SetSubstructXY02042c24((Holder02042c24*)obj->holder, (short)(boxX + offsetX), (short)(boxY + offsetY));

        if (flag == 0) {
            if (obj->target) {
                func_020e2110(obj->target);
            } else {
                EmitScaledField0x440(obj->holder, 1, 1);
            }
        }

        SetSubstructXY02042c24((Holder02042c24*)obj->holder, boxX, boxY);
    }

    if (!obj->active) return;
    func_020675fc(obj);

    void* palette = 0;
    if (obj->usePalette == 1) {
        palette = obj->palette;
    }

    if (!obj->field54 || !obj->field58) return;
    if (!obj->field6c) return;

    CallFunc0205c96cIfMode6AndFlag((char*)obj, flag);

    int lineX[16];
    int lineY[16];
    int line = 0;
    __clear(lineX, sizeof(lineX));
    __clear(lineY, sizeof(lineY));

    int blend = 0x1f;
    int alpha = 0x1f;
    if (obj->effects & 4) {
        alpha = obj->fade >> 16;
        if (flag != 0) {
            alpha &= 0x1f;
            if (alpha != 0) {
                blend = 0xf - (alpha >> 1);
            }
            ColorEffect_ConfigureAlphaBlend((unsigned int*)0x04000050, 8, 1, alpha, blend);
        }
    }

    unsigned short ch;
    if (obj->checkFirst) {
        ch = obj->text[obj->end];
        if (!IsCommandInRange02067a9c(obj, &ch)) return;
    }

    if (obj->effects & 0x40) {
        MeasureTextWidth0206b6b8((unsigned char*)obj);
    }

    if (obj->customLayout) {
        _Z15Forward02044830v(obj, lineX, lineY);
        for (int i = 0; i < 0x10; i++) {
            lineY[i] = obj->lineY;
        }
    } else {
        for (int i = 0; i < 0x10; i++) {
            lineX[i] = obj->lineX + 0xc;
            lineY[i] = obj->lineY;
        }
    }

    unsigned char prevWidth;
    unsigned int end = obj->end;
    pos = obj->start;
    unsigned int minStart = obj->minStart;
    prevWidth = 0xff;
    if (pos < minStart) pos = minStart;

    unsigned char spacing = GetWordFromTable02042648(obj->table);
    y = lineY[0] - obj->yOffset;
    x = lineX[0];

    for (; pos < end; pos++) {
        ch = obj->text[pos];

        if (IsHighByteFF02044494(obj, &ch)) {
            if (IsCommandInRange02067a9c(obj, &ch)) {
                break;
            }
            if (ch == 0xff18) {
                int lineHeight = obj->lineHeight;
                x = lineX[line + 1];
                line++;
                y += lineHeight;
                prevWidth = 0xff;
            } else if (ch == 0xff19) {
                x += spacing + 1;
                prevWidth = 0xff;
            }
            continue;
        }

        glyph = &obj->glyphs[ch];
        width = glyph->width;
        x += LookupKeyValue020425e4(prevWidth, width, obj->table);
        prevWidth = width;

        if (flag != 0) {
            if (obj->drawn <= pos) {
                func_020654b8(obj, obj->context, glyph, (short)x, (short)(y + 2), 0xf);
            }
        } else if (obj->toVram) {
            if (obj->field44 != obj->end) {
                int staging = AllocateVRAMStagingMemory(0x3000);
                if (staging != 0) {
                    unsigned char j;
                    int vramOffset = (int)(((unsigned int)*(int*)((char*)obj->texture + 0x50) << 16) >> 13);
                    unsigned char table = obj->table;
                    GlyphMetrics02066cf0* metrics = glyph->metrics;

                    if (metrics) {
                        unsigned char effects = ((GlobalFlags02066cf0*)GetGlobalField0x1c020421a0())->effects;
                        if (effects & 0x80) {
                            for (j = 0; j < 4; j++) {
                                func_02045864(data_020e7e54[j] + (short)x, data_020e7e3c[j] + (short)(y - 0x74),
                                              metrics, staging, 0x100, 0x60, 0xf, table);
                            }
                            func_02045864((short)x + 1, (short)(y - 0x74) + 1, metrics, staging, 0x100, 0x60, 0xf, table);
                        } else if (effects & 2) {
                            short sy = y - 0x74;
                            short sx = x;
                            func_02045864(sx + 1, sy + 1, metrics, staging, 0x100, 0x60, 0xf, table);
                            func_02045864(sx, sy, metrics, staging, 0x100, 0x60, 0xf, table);
                        } else {
                            func_02045864((short)x, (short)(y - 0x74), metrics, staging, 0x100, 0x60, 0xf, table);
                        }
                    }

                    _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(1, staging, vramOffset, 0x3000, 1, 0);
                    FreeVRAMStagingMemory((void const*)staging);
                }
            }
        } else if (obj->target) {
            int a4 = GetField0OfSubstructAt0x18((Holder020416cc*)glyph);
            UpdateObj020e15f8Entry((char*)obj->target, 0, x, y - 0x74, a4, 0xf, obj->table);
        } else {
            SetIntIntShortAt0xc((SetIntIntShortAt0xcStruct*)glyph, x, y, 0);
            func_020417b0(glyph, obj->font, palette, alpha);
        }

        if (glyph->metrics) {
            x += glyph->metrics->advance + 1;
        }
    }

    func_0204459c(obj, flag);
    obj->drawn = end;

    if (!obj->toVram) return;
    void* texture = obj->texture;
    if (!texture) return;

    unsigned int texOffset = *(int*)((char*)texture + 0x50) << 16;

    *(volatile unsigned int*)0x04000444 = 0;
    *(volatile unsigned int*)0x04000470 = 0;
    *(volatile unsigned int*)0x04000470 = 0x74000;
    *(volatile unsigned int*)0x04000470 = 0x400000;
    *(volatile unsigned int*)0x0400046c = 0x1000;
    *(volatile unsigned int*)0x0400046c = 0x1000;
    *(volatile unsigned int*)0x0400046c = 0x1000;

    *(volatile unsigned int*)0x04000444 = 0;
    *(volatile unsigned int*)0x04000470 = 0;
    *(volatile unsigned int*)0x04000470 = 0x80000;
    *(volatile unsigned int*)0x04000470 = 0;
    *(volatile unsigned int*)0x0400046c = 0x1000;
    *(volatile unsigned int*)0x0400046c = 0xfffff000;
    *(volatile unsigned int*)0x0400046c = 0x1000;

    *(volatile unsigned int*)0x04000444 = 0;
    *(volatile unsigned int*)0x040004c0 = 0x7fffffff;
    *(volatile unsigned int*)0x040004c4 = 0x4210;
    *(volatile unsigned int*)0x040004a8 = 0x6e500000u | (texOffset >> 16);
    *(volatile unsigned int*)0x040004ac = (unsigned int)data_021077fc >> 4;
    *(volatile unsigned int*)0x040004a4 = 0x3e1f00c0;

    *(volatile unsigned int*)0x0400046c = 0x100000;
    *(volatile unsigned int*)0x0400046c = 0x80000;
    *(volatile unsigned int*)0x0400046c = 0x1000;

    *(volatile unsigned int*)0x04000500 = 1;
    *(volatile unsigned int*)0x04000480 = 0x7fff;

    int size = 0x80;
    float t = 0.0f;
    int scaledT = (int)(size * t);
    float comp = 1.0f - t;
    scaledT = scaledT << 12;
    func_020653e4(0, scaledT);

    unsigned int packed1 = ((unsigned int)(unsigned short)(int)(4096.0f * comp)) << 16;
    *(volatile unsigned int*)0x0400048c = packed1;
    *(volatile unsigned int*)0x0400048c = 0;
    func_020653e4(0x100000, scaledT);

    unsigned int packed2 = ((unsigned int)(unsigned short)(int)(4096.0f * comp)) << 16;
    packed2 |= 0x1000;
    *(volatile unsigned int*)0x0400048c = packed2;
    *(volatile unsigned int*)0x0400048c = 0;
    func_020653e4(0x100000, 0x80000);

    *(volatile unsigned int*)0x0400048c = 0x1000;
    *(volatile unsigned int*)0x0400048c = 0;
    func_020653e4(0, 0x80000);

    *(volatile unsigned int*)0x0400048c = 0;
    *(volatile unsigned int*)0x0400048c = 0;
    *(volatile unsigned int*)0x04000504 = 0;
    *(volatile unsigned int*)0x04000448 = 1;
    *(volatile unsigned int*)0x04000448 = 1;
    *(volatile unsigned int*)0x04000448 = 1;
}
