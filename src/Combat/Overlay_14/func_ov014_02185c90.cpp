#include <globaldefs.h>

struct Loader;
struct Ent {
    char pad[0x16];
    unsigned char f16;
};
struct Pk {
    unsigned int lo : 10;
    unsigned int b10 : 1;
    unsigned int c : 7;
    unsigned int d : 7;
};
struct Rec {
    char pad0[8];
    int f8;
    short fc;
    char pad1[4];
    signed char f12;
    char pad2[7];
    short f1a;
};
struct ArrHdr {
    unsigned short a;
    unsigned short pad : 12;
    unsigned short n : 4;
};
struct Slot {
    unsigned short off;
    unsigned short bit0 : 1;
};
struct ListObj {
    char pad[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
    char pad2[3];
};
struct EntObj {
    int pad0;
    void* p4;
    char pad8[10];
    short s12;
};
struct Blk {
    int a;
    short cnt;
    unsigned short b;
};
struct Panel {
    void** bufs;
    char pad4[0x18];
    char arr[0x2c];
    struct Rec* rec;
    char pad4c[4];
    struct Pk* pk;
    char pad54[4];
    struct EntObj* ents;
    void* cont;
    const char* text60;
    const char* text64;
    void* p68;
    char pad6c[4];
    int id70;
    char pad74[10];
    unsigned char b7e;
    unsigned char b7f;
    unsigned char b80;
    unsigned char b81;
    char pad82[10];
    short s8c;
    char pad8e[5];
    unsigned char b93;
    unsigned char b94;
    char pad95[7];
    struct Blk blk;
};
struct Draw {
    char pad0[8];
    void* p8;
    char pad1[0x9c];
    short s28;
    short s2a;
    char pad2[8];
    short s34;
    short s36;
    char pad3[0x28];
};

extern "C" struct Loader* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" int _ZN16BackgroundLoader13GetTaskStatusEi(struct Loader*, int);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(struct Loader*, int, void**, unsigned int*);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(struct Loader*, int);
extern "C" int _Z18CountActiveEntriesP19ActiveEntry02046900(void*);
extern "C" void* _Z17FindRecordByIndexP11Rec020467f0iPPvPi(void*, int, void**, int*);
extern "C" void func_0204c684(void*);
extern "C" int _Z29BinarySearchByField4_02097224P29BinarySearch020971a8Containeri(void*, int);
extern "C" void __clear(void*, int);
extern "C" void _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(const char*, char*, int);
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" void func_02046608(void*, int, char*, char*, int, int, int);
extern "C" void _Z24SetPackedFields_021e24b0Pviihhhhhh(void*, int, int, short, short, short, short, short, short);
extern "C" void _Z23SetEntryFields_021e23d0Pviihh(void*, int, void*, short, short);
extern "C" void* _Z21GetFieldByKey020e0434P17Container020e0310i(void*, int);
extern "C" struct Ent* func_ov014_021842a0(void*, short);
extern "C" void* _Z32FindOrGetDefaultElement_021893c4P26IndexedArrayStruct021893c4i(void*, int);
extern "C" struct Slot* func_ov014_0218940c(void*, int, void*);
extern "C" int* func_ov014_02189430(void*, int, void*);
extern "C" void func_ov023_021e257c(void*);
extern "C" void _Z17ResetList0204af64P12List0204af64(void*);
extern "C" void _Z24SetWord0x18ClearByte0x1fPhi(void*, int);
extern "C" void func_0204b5b4(void*, int);
extern "C" void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(void*, int, int);
extern "C" void func_0204b4c0(void*, void*);
extern "C" void memcpy(void*, void*, int);
extern "C" void _Z21DispatchByTag0204b2e0PvPc(void*, void*);
extern "C" void _Z27DispatchByTagLookup0204b3a0P15SelfTag0204b3a0Pc(void*, void*);

#define FLAGOP(e, id, stmt) do { struct Ent* p = func_ov014_021842a0(e, id); if (p) { stmt; } } while (0)
#define SetBit4(e, id) FLAGOP(e, id, p->f16 |= 0x10)
#define SetBit0(e, id) FLAGOP(e, id, p->f16 |= 1)
#define ClrBit0(e, id) FLAGOP(e, id, p->f16 &= ~1)

// USA: func_ov014_02185c90
extern "C" ARM void func_ov014_02185c90(struct Panel* self) {
    struct Loader* loader = _ZN16BackgroundLoader11GetInstanceEv();
    if ((self->b81 & 1) && self->b7f == 5 && _ZN16BackgroundLoader13GetTaskStatusEi(loader, self->s8c)) {
        void* rp;
        void* file;
        unsigned int size;
        int rs;
        struct Draw draw;
        char buf358[0x48];
        char buf310[0x48];
        char buf110[0x200];
        char bufc8[0x48];
        char buf80[0x48];
        struct ListObj list;
        int count;
        _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader, self->s8c, &file, &size);
        count = _Z18CountActiveEntriesP19ActiveEntry02046900(file);
        if (count != 0) {
            char* rec = (char*)_Z17FindRecordByIndexP11Rec020467f0iPPvPi(file, 0, &rp, &rs);
            if (rec != 0) {
                func_0204c684(&draw);
                draw.s28 = 0x20;
                draw.s2a = 0x18;
                draw.s34 = 0xa;
                draw.s36 = 0xb;
                draw.p8 = rec + 0x10;
                _Z29BinarySearchByField4_02097224P29BinarySearch020971a8Containeri((char*)self + 0xc, self->rec->fc);
                __clear(buf358, 0x48);
                __clear(buf310, 0x48);
                __clear(buf110, 0x200);
                __clear(bufc8, 0x48);
                __clear(buf80, 0x48);
                _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(self->text60, buf358, 0);
                _Z37CopyTextAndUppercaseIfFlagged0206819cPKcPci(self->text64, buf310, 0);
                char* n1 = bufc8;
                char* n2 = buf80;
                char* n3 = buf110;
                void* g = _Z26GetGlobalField0x1c020421a0v();
                func_02046608(g, 0xa, buf358, n1, 0x400, 0, 0);
                func_02046608(g, 0xa, buf310, n2, 0x400, 0, 0);
                func_02046608(g, 0xa, (char*)self->p68, n3, 0x8c, 0, 0);
                void* ents;
                void* cont;
                struct Pk* pk;
                struct Rec* r;
                unsigned char b80 = self->b80;
                ents = self->ents;
                pk = self->pk;
                cont = self->cont;
                r = self->rec;
                if (ents && r && cont && pk && pk->lo) {
                    _Z24SetPackedFields_021e24b0Pviihhhhhh(ents, 2, r->f1a, 8, 0xf, 1, 3, 0, 1);
                    _Z23SetEntryFields_021e23d0Pviihh(ents, 3, (void*)r->f8, 0xa, 0xf);
                    _Z23SetEntryFields_021e23d0Pviihh(ents, 4, _Z21GetFieldByKey020e0434P17Container020e0310i(cont, r->f12), 0xa, 0xf);
                    SetBit4(ents, 4);
                    if (&self->blk && self->blk.cnt > 0) {
                        _Z24SetPackedFields_021e24b0Pviihhhhhh(ents, 5, self->blk.a, 8, 0xf, 1, 6, 0, 0);
                        _Z24SetPackedFields_021e24b0Pviihhhhhh(ents, 6, self->blk.b, 8, 0xf, 1, 6, 0, 0);
                    }
                    _Z24SetPackedFields_021e24b0Pviihhhhhh(ents, 7, pk->lo, 8, 0xf, 1, 6, 0, 0);
                    ClrBit0(ents, 8);
                    ClrBit0(ents, 0xa);
                    ClrBit0(ents, 0xc);
                    ClrBit0(ents, 9);
                    ClrBit0(ents, 0xb);
                    ClrBit0(ents, 0xd);
                    ClrBit0(ents, 0x16);
                    ClrBit0(ents, 0x14);
                    ClrBit0(ents, 0x1a);
                    ClrBit0(ents, 0x1b);
                    ClrBit0(ents, 0x17);
                    ClrBit0(ents, 0x18);
                    ClrBit0(ents, 0x19);
                    SetBit0(ents, 0x15);
                    short c;
                    short b;
                    short a;
                    int ok;
                    ok = 0;
                    a = 8;
                    b = 0xa;
                    c = 0xc;
                    if (pk->b10 || pk->lo) {
                        ok = 1;
                        if (n1[0] != 0) {
                            SetBit0(ents, 8);
                            SetBit0(ents, 0xa);
                            SetBit0(ents, 0xc);
                            _Z23SetEntryFields_021e23d0Pviihh(ents, 8, n1, 0xa, 0xf);
                            _Z24SetPackedFields_021e24b0Pviihhhhhh(ents, 0xa, pk->c, 8, 0xf, 1, 3, 0, 0);
                            _Z23SetEntryFields_021e23d0Pviihh(ents, 0xc, _Z21GetFieldByKey020e0434P17Container020e0310i(cont, 0xf), 0xa, 0xf);
                            a = 9;
                            b = 0xb;
                            c = 0xd;
                        }
                    }
                    if (pk->d || pk->b10) {
                        if (n2[0] != 0) {
                            ok = 1;
                            SetBit0(ents, a);
                            SetBit0(ents, b);
                            SetBit0(ents, c);
                            _Z23SetEntryFields_021e23d0Pviihh(ents, a, n2, 0xa, 0xf);
                            _Z24SetPackedFields_021e24b0Pviihhhhhh(ents, b, pk->d, 8, 0xf, 1, 3, 0, 0);
                            _Z23SetEntryFields_021e23d0Pviihh(ents, c, _Z21GetFieldByKey020e0434P17Container020e0310i(cont, 0xf), 0xa, 0xf);
                        }
                    }
                    if (ok == 0) {
                        SetBit0(ents, 0x16);
                        _Z23SetEntryFields_021e23d0Pviihh(ents, 0x16, _Z21GetFieldByKey020e0434P17Container020e0310i(cont, 0xe), 0xa, 0xf);
                    }
                    _Z23SetEntryFields_021e23d0Pviihh(ents, 0x13, n3, 0xa, 0xf);
                    if (pk->b10) {
                        ClrBit0(ents, 0x14);
                        SetBit0(ents, 0x17);
                        _Z23SetEntryFields_021e23d0Pviihh(ents, 0x17, _Z21GetFieldByKey020e0434P17Container020e0310i(cont, 0x1c), 8, 0xf);
                        SetBit0(ents, 0x18);
                        _Z24SetPackedFields_021e24b0Pviihhhhhh(ents, 0x18, b80 + 1, 8, 0xf, 0, 1, 0, 0);
                        SetBit0(ents, 0x19);
                        _Z24SetPackedFields_021e24b0Pviihhhhhh(ents, 0x19, 2, 8, 0xf, 0, 1, 0, 0);
                    }
                    ClrBit0(ents, 0xe);
                    ClrBit0(ents, 0xf);
                    ClrBit0(ents, 0x10);
                    int i;
                    short id;
                    struct ArrHdr* arr = (struct ArrHdr*)_Z32FindOrGetDefaultElement_021893c4P26IndexedArrayStruct021893c4i(self->arr, -1);
                    if (arr) {
                        id = 0xe;
                        for (i = 0; i < 2; i++) {
                            if (i < arr->n) {
                                SetBit0(ents, id);
                                struct Slot* s = func_ov014_0218940c(self->arr, i, arr);
                                int* v = func_ov014_02189430(self->arr, i, arr);
                                if (s->bit0) {
                                    _Z23SetEntryFields_021e23d0Pviihh(ents, id, (void*)*v, 0xa, 0xf);
                                } else {
                                    _Z23SetEntryFields_021e23d0Pviihh(ents, id, _Z21GetFieldByKey020e0434P17Container020e0310i(cont, 0x15), 0xa, 0xf);
                                }
                                id++;
                            }
                        }
                        if (arr->n >= 3) {
                            if (func_ov014_0218940c(self->arr, 2, arr)->bit0) {
                                SetBit0(ents, 0x10);
                                _Z23SetEntryFields_021e23d0Pviihh(ents, 0x10, _Z21GetFieldByKey020e0434P17Container020e0310i(cont, 0x10), 0xa, 0xf);
                            }
                        }
                    }
                }
                struct EntObj* e = self->ents;
                e->p4 = &draw;
                e->s12 = 1;
                func_ov023_021e257c(self->ents);
                _Z17ResetList0204af64P12List0204af64(&list);
                _Z24SetWord0x18ClearByte0x1fPhi(&list, 0);
                list.lo = 0;
                list.hi = 1;
                func_0204b5b4(&list, 1);
                _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(&list, 0, 0);
                for (int i = 0; i < count; i++) {
                    void* r2 = _Z17FindRecordByIndexP11Rec020467f0iPPvPi(file, i, &rp, &rs);
                    if (r2) {
                        memcpy(self->bufs[i], r2, rs);
                        func_0204b4c0(&list, self->bufs[i]);
                    }
                }
                self->b81 &= ~0x20;
            }
        }
        _ZN16BackgroundLoader10RemoveTaskEi(loader, self->s8c);
        self->s8c = -1;
        self->b7f++;
    }
    if ((self->b81 & 0x10) && self->b7e == 1 && _ZN16BackgroundLoader13GetTaskStatusEi(loader, self->id70)) {
        void* rp;
        void* file;
        unsigned int size;
        int rs;
        struct ListObj list;
        _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader, self->id70, &file, &size);
        int count = _Z18CountActiveEntriesP19ActiveEntry02046900(file);
        _Z17ResetList0204af64P12List0204af64(&list);
        _Z24SetWord0x18ClearByte0x1fPhi(&list, 0);
        list.lo = 0;
        list.hi = 1;
        func_0204b5b4(&list, 1);
        _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(&list, 0, 0);
        for (int i = 0; i < count; i++) {
            void* rec = _Z17FindRecordByIndexP11Rec020467f0iPPvPi(file, i, &rp, &rs);
            if (rec) {
                _Z21DispatchByTag0204b2e0PvPc(&list, rec);
                _Z27DispatchByTagLookup0204b3a0P15SelfTag0204b3a0Pc(&list, rec);
            }
        }
        _ZN16BackgroundLoader10RemoveTaskEi(loader, self->id70);
        self->id70 = -1;
        self->b7e = 0;
        self->b81 &= ~0x10;
        self->b94 = self->b93;
        self->b93 = 0;
    }
}
