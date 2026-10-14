#include <globaldefs.h>

struct Name0201e3c4 {
    char c[9];
};

struct Code0201e3c4 {
    char c[5];
};

struct Elem0201e3c4 {
    unsigned short id;
    struct Name0201e3c4 name;
    struct Code0201e3c4 code;
};

struct List0201e3c4 {
    char unk[0x30];
    struct Elem0201e3c4* data;
    int count;
    int capacity;
};

// USA: func_0201e3c4
extern "C" ARM void _ZN12ZoneFeatures46CreateGrottoTileFeaturePlacementEntry_0201e3c4ERK24TileFeaturePlacementData(struct List0201e3c4* list, struct Elem0201e3c4* src) {
    int count = list->count;
    struct Elem0201e3c4* dst;
    if (count >= list->capacity) {
        return;
    }
    dst = &list->data[count];
    dst->id = src->id;
    dst->name = src->name;
    dst->code = src->code;
    list->count++;
}
