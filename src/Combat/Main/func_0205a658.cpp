#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>

struct Cell0205a658 { unsigned short y, x, attributes; };
struct Struct0205a198 {
    unsigned short count, flags;
    Cell0205a658* cells;
    Cell0205a658* copy;
    char pad_c[0x12];
    unsigned short index;
    char pad_20[2];
    unsigned char firstCell;
    char pad_23[5];
};
struct Hdr02b00e0 {
    unsigned short count, field_2;
    int field_4, mappingMode;
};
struct CellScript0205a658 {
    char pad_0[0x38];
    int mappingMode;
    int field_3c;
    Struct0205a198* records;
    int field_44;
    unsigned int capacity;
    unsigned short recordCount, entryCount;
};
int GetCellBankBlock(void*, void**);
void* GetEntryVarStride(Hdr02b00e0*, unsigned int);
void Init0205a198(Struct0205a198*);

// USA: func_0205a658
extern "C" ARM int func_0205a658(CellScript0205a658* self, void* data, unsigned int length, SafeAllocator* allocator) {
    void* buffer = data;
    Hdr02b00e0* header;
    if (!buffer) buffer = 0;
    else if (!length) buffer = 0;
    else {
        memcpy(buffer, data, length);
        if (!GetCellBankBlock(buffer, (void**)&header)) buffer = 0;
    }
    if (!buffer) return 1;
    if (allocator && !self->records) {
        self->recordCount = header->count;
        self->records = (Struct0205a198*)allocator->Allocate(self->recordCount * sizeof(Struct0205a198));
        for (unsigned short i = 0; i < self->recordCount; ++i) Init0205a198(&self->records[i]);
    }
    Struct0205a198* records;
    unsigned short recordCount = self->recordCount;
    unsigned short count;
    records = self->records;
    if (records && recordCount && allocator) {
        Struct0205a198* record;
        Struct0205a198* entry;
        unsigned short i;
        count = header->count;
        unsigned short total = 0;
        for (i = 0; i < count; ++i) {
            if (recordCount <= i) break;
            entry = (Struct0205a198*)GetEntryVarStride(header, i);
            if (!entry) break;
            unsigned short cellCount = entry->count;
            record = &records[i];
            record->index = i;
            record->firstCell = total;
            record->count = entry->count;
            record->flags = entry->flags;
            record->cells = entry->cells;
            Cell0205a658* allocated = (Cell0205a658*)allocator->Allocate(cellCount * sizeof(Cell0205a658));
            record->copy = allocated;
            record->cells = allocated;
            for (unsigned short j = 0; j < entry->count; ++j) {
                Cell0205a658* from = &entry->cells[j];
                Cell0205a658* to = &record->copy[j];
                to->y = from->y;
                to->x = from->x;
                to->attributes = from->attributes;
            }
            total += entry->count;
        }
    }
    self->entryCount = header->count;
    self->mappingMode = header->mappingMode;
    int mode;
    Struct0205a198* last = (Struct0205a198*)GetEntryVarStride(header, (unsigned short)(header->count - 1));
    if (!last) return 1;
    struct { int mappingMode; Cell0205a658* cell; } lastCellInfo;
    lastCellInfo.mappingMode = self->mappingMode;
    lastCellInfo.cell = &last->cells[last->count - 1];
    mode = lastCellInfo.mappingMode;
    Cell0205a658* cell = lastCellInfo.cell;
    unsigned int attributes = cell->attributes;
    int x = cell->x;
    int y = cell->y;
    unsigned int minimum = mode + 5;
    unsigned int tiles = (attributes & 0x3ff) << minimum;
    unsigned int size = (x & 0xc000) >> 14;
    unsigned int shape = (y & 0xc000) >> 14;
    unsigned int shift = 5;
    switch (shape) {
    case 0:
        switch (size) {
        case 0: shift = 5; break;
        case 1: shift = 7; break;
        case 2: shift = 9; break;
        case 3: shift = 11; break;
        }
        break;
    case 1:
        switch (size) {
        case 0: shift = 6; break;
        case 1: shift = 7; break;
        case 2: shift = 8; break;
        case 3: shift = 10; break;
        }
        break;
    case 2:
        switch (size) {
        case 0: shift = 6; break;
        case 1: shift = 7; break;
        case 2: shift = 8; break;
        case 3: shift = 10; break;
        }
        break;
    }
    if (minimum < shift) minimum = shift;
    self->capacity = tiles + (1 << minimum);
    return 0;
}
