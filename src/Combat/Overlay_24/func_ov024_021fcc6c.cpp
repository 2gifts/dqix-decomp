#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int func_ov024_021fe698(char* obj, int type);
extern "C" void func_ov024_021f9874(void* obj, void* buf, int slot, int value);

struct State_021fcc6c {
    char pad[4];
    unsigned short field4;
};

struct Entry_021fcc6c {
    char pad0[4];
    short field4;
    char pad6[0x148 - 6];
    State_021fcc6c* state;
    char pad14c[0x17c - 0x14c];
    unsigned char slot;
};

struct Record_021fcc6c {
    char pad[0x16];
    unsigned char field16;
    unsigned char field17;
};

struct Obj_021fcc6c {
    unsigned char* base;
    char pad4[2];
    unsigned char type;
    char pad7[5];
    int fieldC;
    char pad10[0x7c - 0x10];
    Entry_021fcc6c* entries[8];
    int count;
};

struct WorkBuffer_021fcc6c {
    char prefix[0xc4];
    float threshold;
};

// USA: func_ov024_021fcc6c
extern "C" ARM void func_ov024_021fcc6c(Obj_021fcc6c* obj) {
    float threshold = 1000.0f;
    int ok;
    if (obj->type == 2) {
        ok = 1;
    } else if (obj->type == 0) {
        return;
    } else {
        ok = 1;
        if (obj->fieldC >= 4) threshold = 50.0f;
    }
    if (!ok) return;
    if (!func_ov024_021fe698((char*)obj, 0x12)) return;
    WorkBuffer_021fcc6c buf;
    for (int i = 0; i < obj->count; i++) {
        Entry_021fcc6c* entry = obj->entries[i];
        if ((int)entry->slot >= 0 && (int)entry->slot < 3) {
            State_021fcc6c* state = entry->state;
            if (!state) return;
            if (state->field4 != 0) {
                Record_021fcc6c* record = (Record_021fcc6c*)(obj->base + 0x81b4) + entry->slot;
                if (record->field16 == 0 && record->field17 == 0) {
                    memset(&buf, 0, sizeof(buf));
                    buf.threshold = threshold;
                    func_ov024_021f9874(obj, &buf, entry->slot, (unsigned char)entry->field4);
                }
            }
        }
    }
}
