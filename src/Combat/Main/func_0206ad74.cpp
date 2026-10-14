#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry0204254c { int value; signed char width; signed char advance : 6; signed char field5 : 2; unsigned char field6[2]; };
Entry0204254c* FindEntryByKey0204254c(int, int);
int GetWordFromTable02042648(int);
struct CombatSlots0206b198;
void DecrementSlotRef0206b198(CombatSlots0206b198*, unsigned short);
extern char data_020f08dc[];
extern char data_020f0979[];
extern char data_020f097c[];
extern "C" void __clear(void*, int);
struct Caption0206ad74 {
    unsigned char field0[0x50];
    char* text;
    unsigned char field54[0x74-0x54];
    int start;
    int end;
    unsigned char field7c[8];
    int specialStart;
    int specialEnd;
    unsigned char field8c[0x912-0x8c];
    unsigned char mode;
    unsigned char field913[0x934-0x913];
    short boxWidth;
    short boxHeight;
    unsigned char field938[0x1882-0x938];
    unsigned short slots[64];
    char caption[64];
    unsigned short count;
    short width;
    short specialLength;
    unsigned char field1948[0x19c2-0x1948];
    unsigned char status;
    unsigned char changed;
    unsigned char field19c4[0x19dc-0x19c4];
    unsigned char font;
};

// USA: func_0206ad74
extern "C" ARM void func_0206ad74(Caption0206ad74* self) {
    int defaultWidth;
    int length = 0;
    self->specialStart = 0;
    self->specialEnd = 0;
    self->width = 0;
    self->count = 0;
    self->specialLength = 0;
    unsigned char previousStatus = self->status;
    int changed = 1;
    int prefixCount = 0;
    char caption[64];
    __clear(caption, sizeof(caption));
    unsigned char fontWidth;
    char* cursor;
    char* text = self->text;
    char* start = strstr(text, data_020f08dc);
    char* middle = strstr(text, data_020f0979);
    char* alternate = strstr(text, data_020f097c);
    fontWidth = GetWordFromTable02042648(self->font);
    if (start) {
        for (;;) {
            if (text == start) break;
            unsigned short code;
            memcpy(&code, text, 2);
            prefixCount++;
            if ((code & 0xff00) == 0xff00) text++;
            text++;
        }
        char* selected = start + 2;
        char* finish = strstr(selected, data_020f08dc);
        if (finish) {
            length = finish - selected;
            memcpy(caption, selected, length);
            changed = 0;
            self->status = changed;
            cursor = caption;
            for (;;) {
                defaultWidth = fontWidth + 1;
                if (!*cursor) break;
                Entry0204254c* entry = FindEntryByKey0204254c((int)cursor, self->font);
                if (entry) {
                    self->count++;
                    int width = entry->width;
                    int advance = entry->advance;
                    self->width += width + 1;
                    cursor += advance;
                } else {
                    self->count++;
                    cursor++;
                    self->width += defaultWidth;
                }
            }
            self->specialLength = finish - start;
            self->specialLength += 3;
            self->specialLength += prefixCount - 2;
            self->mode = 4;
            short padding = 8 - (self->width & 7);
            self->boxWidth = self->width + 18 + padding;
            self->boxHeight = 22;
        } else self->status = previousStatus;
    } else {
        if (middle || alternate) self->mode = 3;
        else self->specialLength = -1;
    }
    if (!self->status && length) changed = strcmp(self->caption, caption);
    if (changed) {
        for (int i = 0; i < self->count; i++) DecrementSlotRef0206b198((CombatSlots0206b198*)self, self->slots[i]);
        memset(self->slots, 0xff01, sizeof(self->slots));
        memset(self->caption, 0, sizeof(self->caption));
        memcpy(self->caption, caption, length);
        self->changed = 0;
        if (self->count) {
            self->specialStart = self->specialLength;
            self->specialEnd = self->count + prefixCount + 3;
        }
    } else if (self->count) {
        self->specialStart = self->specialLength;
        self->specialEnd = self->count + prefixCount + 3;
        self->start = self->count + prefixCount + 3;
        self->end = self->count + prefixCount + 3;
        self->count++;
        return;
    }
    self->count = 0;
}
