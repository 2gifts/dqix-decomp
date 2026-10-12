#include <globaldefs.h>

struct S02098834
{
    unsigned char name[11];
    unsigned char slot : 7;
    unsigned char field_0xb : 1;
    unsigned int flagsLow : 4;
    unsigned int category : 4;
    unsigned int field_0xc_bit8 : 7;
    unsigned int priority : 4;
    unsigned int level : 5;
    unsigned int field_0xc_bit24 : 6;
    unsigned int dirty : 1;
    unsigned int field_0xc_bit31 : 1;
    unsigned int used : 2;
    unsigned int serial : 30;
    unsigned char key[6];
    unsigned char field_0x1a[0x6c - 0x1a];
    unsigned int field_0x6c_bit0 : 26;
    unsigned int eligible : 1;
    unsigned int field_0x6c_bit27 : 5;
    unsigned char field_0x70[0xe8 - 0x70];
};

struct Base020989cc
{
    S02098834 records[30];
    int field_0x1b30;
    unsigned int nextSerial;
    unsigned int count;
    unsigned char field_0x1b3c[0x1b68 - 0x1b3c];
    unsigned int pendingSerials[3];
    int pendingCount;
};

struct SlotRegistration02098630
{
    int slot;
    int priority;
    int level;
    int field_0xc;
};

extern "C" int func_02001aec(const void*, const void*, int);
extern "C" int func_02098a84(Base020989cc*);
extern "C" S02098834* _Z18CopyStruct02098834P9S02098834S0_(S02098834*, S02098834*);
extern "C" void _Z23UpdateRankLevel020989ccP12Base020989cc(Base020989cc*);
extern "C" int _Z21RegisterSlotA020cf0fci(int);

// USA: func_02098630
extern "C" ARM int func_02098630(Base020989cc* self, S02098834* source, int advanceSerial, int updateRank)
{
    if (!source->eligible)
        return 0;
    for (int i = 0; i < 30; i++)
    {
        if (func_02001aec(self->records[i].key, source->key, 6) == 0)
            return 0;
    }
    int index = func_02098a84(self);
    if (advanceSerial)
        self->nextSerial++;
    self->count = 0;
    S02098834* cursor = self->records;
    for (int i = 0; i < 30; i++, cursor++)
    {
        if (cursor->serial)
            self->count++;
    }
    if (++self->count > 30)
        self->count = 30;
    S02098834* record = &self->records[index];
    _Z18CopyStruct02098834P9S02098834S0_(record, source);
    record->category = 2;
    record->used = 2;
    record->dirty = 1;
    record->serial = self->nextSerial;
    SlotRegistration02098630 registration;
    if (_Z21RegisterSlotA020cf0fci((int)&registration) == 0)
    {
        self->records[index].slot = (unsigned char)registration.slot;
        self->records[index].priority = registration.priority;
        self->records[index].level = registration.level;
    }
    if (updateRank)
        _Z23UpdateRankLevel020989ccP12Base020989cc(self);
    unsigned int serial = record->serial;
    for (int i = 0; i < 3; i++)
    {
        if (self->pendingSerials[i] == 0xffffffff)
        {
            self->pendingSerials[i] = serial;
            self->pendingCount++;
            break;
        }
    }
    return 1;
}
