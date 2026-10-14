#include <globaldefs.h>

struct Hdr02b0074;
unsigned char* GetTableEnd_020b0074(Hdr02b0074* h);
struct Hdr02b00e0;
unsigned char* GetEntryVarStride_020b00e0(Hdr02b00e0* h, unsigned int i);
void RelocateOffsetArrayAtOffset8_020b0094(char* base);

struct EntryField020b0108 {
    char pad[4];
    int offset4;
};

struct Table020b0108 {
    unsigned short count;
    unsigned short flags;
    unsigned char* base;
    char pad1[0xc - 0x8];
    EntryField020b0108* sub;
    char pad2[0x14 - 0x10];
    char* offsetArrayBase;
};

// USA: func_020b0108  (semantic: RelocateTable020b0108)
extern "C" ARM void func_020b0108(Table020b0108* self) {
    self->base = self->base + (unsigned int)self;
    unsigned char* tableEnd = GetTableEnd_020b0074((Hdr02b0074*)self);
    unsigned short i = 0;
    if (i < self->count) {
        do {
            EntryField020b0108* e = (EntryField020b0108*)GetEntryVarStride_020b00e0((Hdr02b00e0*)self, i);
            e->offset4 = e->offset4 + (int)tableEnd;
            i = i + 1;
        } while (i < self->count);
    }
    if (self->sub != 0) {
        EntryField020b0108* sub = (EntryField020b0108*)((char*)self->sub + (unsigned int)self);
        self->sub = sub;
        sub->offset4 = sub->offset4 + (int)sub;
        self->sub = sub;
    }
    if (self->offsetArrayBase != 0) {
        self->offsetArrayBase = self->offsetArrayBase + (unsigned int)self;
        RelocateOffsetArrayAtOffset8_020b0094(self->offsetArrayBase);
    }
}
