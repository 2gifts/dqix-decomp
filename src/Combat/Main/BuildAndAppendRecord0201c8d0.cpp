#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/Script.h"

struct Variant02030b0c {
    int tag;
    union {
        int i;
        float f;
    } u;
};

struct Struct02030b7c;

struct Name0201e3c4 { char c[9]; };
struct Code0201e3c4 { char c[5]; };
struct Elem0201e3c4 {
    unsigned short id;
    struct Name0201e3c4 name;
    struct Code0201e3c4 code;
};
struct List0201e3c4;
extern "C" extern void _ZN12ZoneFeatures46CreateGrottoTileFeaturePlacementEntry_0201e3c4ERK24TileFeaturePlacementData(struct List0201e3c4* list, struct Elem0201e3c4* src);

struct GlobalList020fdc20_0201c8d0 {
    int pad0;
    void* pad4;
    struct List0201e3c4* list;
};
extern struct GlobalList020fdc20_0201c8d0 data_020fdc20;

// USA: func_0201c8d0
extern "C" ARM int _Z29WarpScript_Opcode_7e_0201c8d0PN6Script9ParameterEi(unsigned char* src) {
    struct Elem0201e3c4 elem;
    elem.id = ((Script::Parameter*)((struct Variant02030b0c*)src))->ToInt();
    struct Struct02030b7c* strFieldPtr = (struct Struct02030b7c*)(src + 8);
    src += 0x10;
    char* namePtr = (char*)(extern void*)((Script::Parameter*)strFieldPtr)->ToString();
    strcpy(elem.code.c, namePtr);
    int i;
    for (i = 0; i < 9; i++) {
        elem.name.c[i] = (char)((Script::Parameter*)((struct Variant02030b0c*)src))->ToInt();
        src += 8;
    }
    _ZN12ZoneFeatures46CreateGrottoTileFeaturePlacementEntry_0201e3c4ERK24TileFeaturePlacementData(data_020fdc20.list, &elem);
    return 1;
}
