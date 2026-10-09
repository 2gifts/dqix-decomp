#include <globaldefs.h>
#include "std_library_functions.h"

struct StructA0205d5d0;
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);
extern "C" void _Z25AppendEntryNames_0215e13cPcS_i(char* base, char* dst, int flag);
extern "C" void _Z28SetupFieldAndFormat_0215de6cPcPv(char* base, void* buf);

struct TouchState_02114e54 {
    char unk_0[0x24];
    unsigned short field_0x24;
    char unk_26[0x5f - 0x26];
    unsigned char field_0x5f;
};
extern struct TouchState_02114e54 data_02114e54;

struct MenuCursor_0215db2c {
    char unk_0[0x30];
    int index;
};

struct MenuList_0215db2c {
    int unk_0;
    struct MenuCursor_0215db2c cursors[1];
};

static inline struct MenuCursor_0215db2c* GetCursor(struct MenuList_0215db2c* list) {
    struct MenuCursor_0215db2c* cursor = list->cursors;
    return cursor;
}

// USA: func_ov003_0215db2c
extern "C" ARM void func_ov003_0215db2c(char* self) {
    unsigned char mode = *(unsigned char*)(self + 0x3ba);
    if (mode != 0) {
        int flag = 0;
        if (mode == 2 && data_02114e54.field_0x5f != 0 && data_02114e54.field_0x24 != 0) {
            if (GetCursor((struct MenuList_0215db2c*)(self + 0x98))->index < 0) {
                return;
            }
            flag = 1;
        }
        memset(*(void**)(self + 0x7c), 0, 0x960);
        unsigned char page = *(unsigned char*)(self + 0x148);
        if (page == 1) {
            _Z25AppendEntryNames_0215e13cPcS_i(self, *(char**)(self + 0x7c), flag);
        }
        if (page != 0) {
            _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)(self + 0x98), page, *(int*)(self + 0x7c), 1, 0);
        }
    }
    if (*(unsigned char*)(self + 0x3bb) != 0) {
        memset(*(void**)(self + 0x7c), 0, 0x960);
        _Z28SetupFieldAndFormat_0215de6cPcPv(self, *(void**)(self + 0x7c));
        _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)(self + 0x98), 0, *(int*)(self + 0x7c), 1, 0);
        *(unsigned char*)(self + 0x3bb) = 0;
    }
}
