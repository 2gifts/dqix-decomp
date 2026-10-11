#include <globaldefs.h>

struct List0204af64 {
    char pad0[0xc];
    unsigned char b0c;
    unsigned char pad0d;
    unsigned short h0e;
    int w10;
    int w14;
    int w18;
    unsigned char b1c_lo : 4;
    unsigned char b1c_hi : 4;
    unsigned char b1d;
    unsigned char b1e;
    unsigned char b1f;

    unsigned char GetLo() { return b1c_lo; }
    unsigned char GetHi() { return b1c_hi; }
    void SetLo(unsigned char v) { b1c_lo = v; }
    void SetHi(unsigned char v) { b1c_hi = v; }
};
extern "C" void _Z17ResetList0204af64P12List0204af64(struct List0204af64* obj);

struct ActiveEntry02046900;
int CountActiveEntries(struct ActiveEntry02046900* entry);

struct Rec020467f0;
void* FindRecordByIndex(struct Rec020467f0* rec, int index, void** out, int* out44);

extern "C" void _Z21DispatchByTag0204b2e0PvPc(void* obj, char* str);

struct SelfTag0204b3a0;
extern "C" void _Z27DispatchByTagLookup0204b3a0P15SelfTag0204b3a0Pc(struct SelfTag0204b3a0* self, char* str);

struct Obj021f7b98 {
#if defined(jpn)
    char pad0[0x24];
#else
    char pad0[0x28];
#endif
    struct List0204af64 list;
};

// JPN: func_ov023_021f7090
// USA: func_ov023_021f7b98
extern "C" ARM void func_ov023_021f7b98(struct Obj021f7b98* self, void* keyObj, int useTag, struct Rec020467f0* entry, void* next) {
    int size;
    void* rp;
    struct List0204af64 list;

    if (entry == 0 || next == 0) {
        return;
    }
    int count = CountActiveEntries((struct ActiveEntry02046900*)entry);
    for (int i = 0; i < count; i++) {
        char* rec = (char*)FindRecordByIndex(entry, i, &rp, &size);
        if (rec) {
            _Z17ResetList0204af64P12List0204af64(&list);
            list.SetLo(self->list.GetLo());
            list.SetHi(self->list.GetHi());
            if (useTag) {
                _Z21DispatchByTag0204b2e0PvPc(&list, rec);
            } else {
                _Z27DispatchByTagLookup0204b3a0P15SelfTag0204b3a0Pc((struct SelfTag0204b3a0*)&list, rec);
            }
        }
    }
}
