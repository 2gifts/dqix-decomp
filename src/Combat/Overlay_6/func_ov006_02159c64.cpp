#include <globaldefs.h>

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
    char pad0[0x14];
    void* entries;
    char pad18[0x14];
    Node02158cfc* head;
    Node02158cfc* checkpoint;
    char pad34[0x14c-0x34];
    Container02071ffc filtered;
    char pad150[0x35e - 0x150];
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
extern "C" Node02158cfc* _Z23FindNodeOrMark_02158d8cPvs(void*, short);
extern "C" void _Z28FilterAndSortEntries02071ffcP17Container02071ffciiisPs(Container02071ffc*, int, int, int, short, short*);
extern "C" void _Z30ComputeField_02158cac_02158cacPv(void*);
struct Obj0205eaa0;
extern Obj0205eaa0 data_02108760 __attribute__((aligned(4)));
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0*, int, int);
extern "C" void _Z18Checkpoint02158cfcP12Cont02158cfcP12Node02158cfc(Cont02158cfc*, Node02158cfc*);
void ClearSublistEntriesFlag4(void*, int);
extern "C" void func_ov006_0215f7e8(Cont02158cfc*);
extern "C" void func_ov006_0215fcf0(Cont02158cfc*);

// USA: func_ov006_02159c64
extern "C" ARM void func_ov006_02159c64(Cont02158cfc* self) {
    Node02158cfc* selected = _Z23FindNodeOrMark_02158d8cPvs(self, self->selection - 0x29);
    if (!selected) return;
    if (!selected->enabled) {
        self->selection = -1;
        self->previousSelection = -1;
        selected = 0;
    }
    self->reverse = !self->reverse;
    short count = 0;
    _Z28FilterAndSortEntries02071ffcP17Container02071ffciiisPs(&self->filtered, self->filter, self->category, self->reverse, 16, &count);
    self->checkpoint = self->head = self->filtered.head;
    if (!selected) selected = self->checkpoint;
    _Z30ComputeField_02158cac_02158cacPv(self);
    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
    short index = 0;
    for (Node02158cfc* node = self->checkpoint; node; node = node->next) {
        if (node == selected) break;
        ++index;
    }
    short row = index % 16;
    self->page = index / 16;
    _Z18Checkpoint02158cfcP12Cont02158cfcP12Node02158cfc(self, selected);
    self->selection = row + 0x29;
    ClearSublistEntriesFlag4(self->entries, 9);
    func_ov006_0215f7e8(self);
    func_ov006_0215fcf0(self);
}
