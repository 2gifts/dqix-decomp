#include <globaldefs.h>

struct Struct_0205d81c;
struct Struct_0205c4a8;
struct Struct_0205bb84;
struct Struct_0205bcdc;

struct Element_021e6448 {
    char pad0[0xa8];
    short width;
    short height;
    short x;
    short y;
};

struct TouchState_021e6448 {
    char pad0[0x55];
    unsigned char touching_;
};

struct ListState_021e6448 {
    char data[0x50];
};

struct ScrollList_021e6448 {
    char pad0[0x4];
    ListState_021e6448 states[2];
};

static inline ListState_021e6448* GetState(ScrollList_021e6448* list, int i) { return &list->states[i]; }

struct ListMenu_021e6448 {
#if defined(jpn)
    char pad0[0x90];
#else
    char pad0[0xac];
#endif

    ScrollList_021e6448 list_;
#if defined(jpn)
    char pad[0x1341 - 0x90 - sizeof(ScrollList_021e6448)];
#else
    char pad[0x1371 - 0xac - sizeof(ScrollList_021e6448)];
#endif

    unsigned char selectedKey_;
#if defined(jpn)
    char pad1372[0x1360 - 0x1342];
#else
    char pad1372[0x1398 - 0x1372];
#endif

    int scrolled_;
};

int SelectField0x8Or0x58ByFlags(unsigned char* obj);
void SelectCoordsByFlag0x24(unsigned char* obj, int* out1, int* out2);
extern "C" Element_021e6448* _Z23FindElementByC40205d81cP15Struct_0205d81ci(Struct_0205d81c* s, int key);
extern "C" void _Z33AdvanceWrappedAccumulator0205c4a8P15Struct_0205c4a8i(Struct_0205c4a8* s, int delta);
extern "C" int _Z24ComputeScaledSum0205bb84P15Struct_0205bb84(Struct_0205bb84* s);
extern "C" void _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci(Struct_0205bcdc* s, int index);
extern "C" void func_0205bb04(void* s, int index);

extern "C" TouchState_021e6448 data_02114e54;

// JPN: func_ov023_021e66bc
// USA: func_ov023_021e6448
extern "C" ARM int func_ov023_021e6448(ListMenu_021e6448* self) {
    if (SelectField0x8Or0x58ByFlags((unsigned char*)&self->list_) <= 1)
        return 0;
    if (data_02114e54.touching_ != 0) {
        int x, y;
        SelectCoordsByFlag0x24((unsigned char*)&data_02114e54, &x, &y);
        Element_021e6448* e = _Z23FindElementByC40205d81cP15Struct_0205d81ci((Struct_0205d81c*)&self->list_, self->selectedKey_);
        if (e != NULL) {
            short right = e->x;
            short bottom = e->y;
            short height = e->height;
            right += e->width;
            bottom += height;
            bottom <<= 3;
            if (bottom - 16 <= y && y < bottom) {
                ListState_021e6448* scroll = GetState(&self->list_, 1);
                short left = e->x << 3;
                if (x >= left && x < left + 16) {
                    _Z33AdvanceWrappedAccumulator0205c4a8P15Struct_0205c4a8i((Struct_0205c4a8*)scroll, -1);
                    self->scrolled_ = 1;
                }
                right <<= 3;
                if (right - 16 <= x && x < right) {
                    _Z33AdvanceWrappedAccumulator0205c4a8P15Struct_0205c4a8i((Struct_0205c4a8*)scroll, 1);
                    self->scrolled_ = 1;
                }
                int index = _Z24ComputeScaledSum0205bb84P15Struct_0205bb84((Struct_0205bb84*)scroll);
                _Z23SetIndexIfValid0205bcdcP15Struct_0205bcdci((Struct_0205bcdc*)&self->list_.states[0], index);
                func_0205bb04(&self->list_.states[1], index);
            }
            return 1;
        }
    }
    return 0;
}
