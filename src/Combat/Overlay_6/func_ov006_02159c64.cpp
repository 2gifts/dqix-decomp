#include <globaldefs.h>

#if defined(jpn)
enum { kEntries = 0xc, kFiltered = 0x140 };
#else
enum { kEntries = 0x14, kFiltered = 0x14c };
#endif

struct Node02158cfc {
    char pad0[0x10];
    unsigned int padBits:22;
    unsigned int enabled:1;
    unsigned int remainingBits:9;
    char pad14[8];
    Node02158cfc* next;
};
struct Container02071ffc { Node02158cfc* head; };
struct Cont02158cfc {
    char pad0[kEntries];
    void* entries;
    char pad18[0x14];
    Node02158cfc* head;
    Node02158cfc* checkpoint;
    char pad34[kFiltered - kEntries - 0x20];
    Container02071ffc filtered;
    char pad150[0x35e - kFiltered - 4];
    short previousSelection;
    char pad360[0xa];
    short selection;
    char pad36c[0x18];
    signed char filter;
    signed char category;
    unsigned char reverse;
    char pad387;
    unsigned char page;
};
Node02158cfc* FindNodeOrMark_02158d8c(void*, short);
void FilterAndSortEntries02071ffc(Container02071ffc*, int, int, int, short, short*);
void ComputeField_02158cac_02158cac(void*);
struct Obj0205eaa0;
extern Obj0205eaa0 data_02108760 __attribute__((aligned(4)));
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
void Checkpoint02158cfc(Cont02158cfc*, Node02158cfc*);
void ClearSublistEntriesFlag4_020804fc(void*, int);
extern "C" void func_ov006_0215f7e8(Cont02158cfc*);
extern "C" void func_ov006_0215fcf0(Cont02158cfc*);

// USA: func_ov006_02159c64
extern "C" ARM void func_ov006_02159c64(Cont02158cfc* self) {
    Node02158cfc* selected = FindNodeOrMark_02158d8c(self, self->selection - 0x29);
    if (!selected) return;
    if (!selected->enabled) {
        self->selection = -1;
        self->previousSelection = -1;
        selected = 0;
    }
    self->reverse = !self->reverse;
    short count = 0;
    FilterAndSortEntries02071ffc(&self->filtered, self->filter, self->category, self->reverse, 16, &count);
    self->checkpoint = self->head = self->filtered.head;
    if (!selected) selected = self->checkpoint;
    ComputeField_02158cac_02158cac(self);
    DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
    short index = 0;
    for (Node02158cfc* node = self->checkpoint; node; node = node->next) {
        if (node == selected) break;
        ++index;
    }
    short row = index % 16;
    self->page = index / 16;
    Checkpoint02158cfc(self, selected);
    self->selection = row + 0x29;
    ClearSublistEntriesFlag4_020804fc(self->entries, 9);
    func_ov006_0215f7e8(self);
    func_ov006_0215fcf0(self);
}
