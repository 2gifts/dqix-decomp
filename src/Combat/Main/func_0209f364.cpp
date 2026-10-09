#include <globaldefs.h>
#include "std_library_functions.h"

struct FilterRecord0209f364 {
    char field_0x0[0x12];
    short kind;
    char field_0x14[0xc];
    float value;
    unsigned char category;
    char field_0x25[0x1b];
};

struct FilterTable0209f364 {
    union {
        struct {
            char field_0x0[0x5c60];
            FilterRecord0209f364 records[256];
        };
        struct {
            char field_0x0_count[0x8e07];
            unsigned char count;
        };
    };
};

struct FilterRecords0209f364 {
    FilterRecord0209f364 records[16];
    int secondaryCount;
};

struct FilterContext0209f364 {
    int field_0x0;
    FilterTable0209f364* table;
    char field_0x8[0x90];
    int count;
    FilterRecords0209f364 primary;
    FilterRecord0209f364 secondary[16];
};

// USA: func_0209f364
extern "C" ARM void func_0209f364(FilterContext0209f364* context, int mode, float threshold, int below) {
    int recordSize = sizeof(FilterRecord0209f364);
    if (mode == 0) {
        int count;
        int index;
        context->count = 0;
        count = context->table->count;
        for (index = 0; index < count; index++) {
            FilterRecord0209f364* record = &context->table->records[index];
            if (record == NULL) continue;
            if (below) {
                if (record->value < threshold) continue;
            } else {
                if (record->value >= threshold) continue;
            }
            {
                int destination = context->count++;
                memcpy(&context->primary.records[destination], record, recordSize);
            }
        }
        return;
    }
    context->primary.secondaryCount = 0;
    memset(context->secondary, 0, 0x400);
    {
        FilterRecords0209f364* primary = &context->primary;
        int index;
        for (index = 0; index < context->count; index++) {
            FilterRecord0209f364* record = &primary->records[index];
            if (below) {
                if (record->value < threshold) continue;
            } else {
                if (record->value >= threshold) continue;
            }
            {
                int destination = context->primary.secondaryCount;
                int current = primary->secondaryCount;
                primary->secondaryCount = current + 1;
                memcpy(&context->secondary[destination], record, recordSize);
            }
        }
    }
    context->count = context->primary.secondaryCount;
    memcpy(context->primary.records, context->secondary, 0x400);
}
