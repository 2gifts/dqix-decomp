#include <globaldefs.h>

extern int data_020e7a94[];
int FindEntryIndexByKey020424e4(int key, int tableIdx);
void* GetBoundedEntry020425b4(int idx, int tableIdx);
int LookupKeyValue020425e4(int a, int b, int tableIdx);

struct Entry020420e8 {
    int val;
    char pad4;
    signed char field5 : 6;
    signed char unused2 : 2;
    char pad6[2];
};

#if defined(jpn)
struct Metrics0202a6c4 { int field_0; int rowHeight; int columnWidth; int font; };
extern Metrics0202a6c4 data_020ef74c;
// USA: func_020420e8
extern "C" ARM void func_02028ce4(const char* text, int* widthOut, int* heightOut) {
    if (text == 0) return;
    int advance = 10;
    int lineHeight = 11;
    int font = data_020ef74c.font;
    if ((unsigned int)(font - 3) <= 1) {
    } else if ((unsigned int)(font - 5) <= 1) {
        advance = 12;
        lineHeight = 13;
    }
    int width;
    int maxWidth = 0;
    width = 0;
    int height = lineHeight;
    unsigned char count = 0;
    const unsigned char* cursor = (const unsigned char*)text;
    while (*cursor != 0 && count < 25) {
        unsigned int ch = *cursor;
        if (ch == 10) {
            if (maxWidth < width) {
                maxWidth = width;
                width = 0;
            }
            height += lineHeight;
            cursor++;
        } else if ((ch >= 0x81 && ch <= 0x9f) || (ch >= 0xe0 && ch <= 0xea)) {
            width += advance;
            cursor += 2;
            count++;
        } else {
            width += advance;
            cursor++;
            count++;
        }
    }
    if (maxWidth < width) maxWidth = width;
    *widthOut = maxWidth;
    *heightOut = height;
}
#else
// USA: func_020420e8  (semantic: ProcessStringAndAccumulate_020420e8)
extern "C" ARM int func_020420e8(char* str, int id) {
    if (str == 0) return 0;
    int mask = data_020e7a94[id] & 0xff;
    int resetState = 0xff;
    int state = resetState;
    int masked;
    int total = 0;
    for (;;) {
        if (*str == 0) break;
        int delta = mask + 1;
        int idx = FindEntryIndexByKey020424e4((int)str, id);
        if (idx < 0) {
            state = resetState;
            str++;
        } else {
            masked = idx & 0xff;
            struct Entry020420e8* entry = (struct Entry020420e8*)GetBoundedEntry020425b4(idx, id);
            int val = LookupKeyValue020425e4(state, masked, id);
            state = masked;
            delta = (entry->pad4 + 1) + val;
            str = str + entry->field5;
        }
        total += delta;
    }
    return total - 1;
}
#endif
