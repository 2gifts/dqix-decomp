#include <globaldefs.h>

#if defined(jpn)
#define func_ov014_02185c90 func_ov014_02186d00
#endif

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
struct ActiveEntry02046900;
int CountActiveEntries(ActiveEntry02046900*);
struct Rec020467f0;
void* FindRecordByIndex(Rec020467f0*, int, void**, int*);
extern "C" void func_0204c684(void*);
struct BinarySearch020971a8Container;
int BinarySearchByField4_02097224(BinarySearch020971a8Container*, int);
extern "C" void __clear(void*, int);
void CopyTextAndUppercaseIfFlagged0206819c(const char*, char*, int);
void* GetGlobalField0x1c020421a0();
extern "C" void func_02046608(void*, int, char*, char*, int, int, int);
void SetPackedFields_021e24b0(void*, int, int, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
void SetEntryFields_021e23d0(void*, int, int, unsigned char, unsigned char);
struct Container020e0310;
void* GetFieldByKey020e0434(Container020e0310*, int);
extern "C" struct Ent* func_ov014_021842a0(void*, short);
struct IndexedArrayStruct021893c4;
void* FindOrGetDefaultElement_021893c4(IndexedArrayStruct021893c4*, int);
extern "C" struct Slot* func_ov014_0218940c(void*, int, void*);
extern "C" int* func_ov014_02189430(void*, int, void*);
extern "C" void func_ov023_021e257c(void*);
struct List0204af64;
void ResetList0204af64(List0204af64*);
void SetWord0x18ClearByte0x1f(unsigned char*, int);
extern "C" void func_0204b5b4(void*, int);
struct Obj0204b5e8;
void DispatchViaTable0204b5e8(Obj0204b5e8*, int, int);
extern "C" void func_0204b4c0(void*, void*);
extern "C" void memcpy(void*, void*, int);
void DispatchByTag0204b2e0(void*, char*);
struct SelfTag0204b3a0;
void DispatchByTagLookup0204b3a0(SelfTag0204b3a0*, char*);

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
        count = CountActiveEntries((ActiveEntry02046900*)file);
        if (count != 0) {
            char* rec = (char*)FindRecordByIndex((Rec020467f0*)file, 0, &rp, &rs);
            if (rec != 0) {
                func_0204c684(&draw);
                draw.s28 = 0x20;
                draw.s2a = 0x18;
                draw.s34 = 0xa;
                draw.s36 = 0xb;
                draw.p8 = rec + 0x10;
                BinarySearchByField4_02097224((BinarySearch020971a8Container*)((char*)self + 0xc), self->rec->fc);
                __clear(buf358, 0x48);
                __clear(buf310, 0x48);
                __clear(buf110, 0x200);
                __clear(bufc8, 0x48);
                __clear(buf80, 0x48);
                CopyTextAndUppercaseIfFlagged0206819c(self->text60, buf358, 0);
                CopyTextAndUppercaseIfFlagged0206819c(self->text64, buf310, 0);
                char* n1 = bufc8;
                char* n2 = buf80;
                char* n3 = buf110;
                void* g = GetGlobalField0x1c020421a0();
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
                    SetPackedFields_021e24b0(ents, 2, r->f1a, 8, 0xf, 1, 3, 0, 1);
                    SetEntryFields_021e23d0(ents, 3, (int)r->f8, 0xa, 0xf);
                    SetEntryFields_021e23d0(ents, 4, (int)(GetFieldByKey020e0434((Container020e0310*)cont, r->f12)), 0xa, 0xf);
                    SetBit4(ents, 4);
                    if (&self->blk && self->blk.cnt > 0) {
                        SetPackedFields_021e24b0(ents, 5, self->blk.a, 8, 0xf, 1, 6, 0, 0);
                        SetPackedFields_021e24b0(ents, 6, self->blk.b, 8, 0xf, 1, 6, 0, 0);
                    }
                    SetPackedFields_021e24b0(ents, 7, pk->lo, 8, 0xf, 1, 6, 0, 0);
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
                            SetEntryFields_021e23d0(ents, 8, (int)n1, 0xa, 0xf);
                            SetPackedFields_021e24b0(ents, 0xa, pk->c, 8, 0xf, 1, 3, 0, 0);
                            SetEntryFields_021e23d0(ents, 0xc, (int)(GetFieldByKey020e0434((Container020e0310*)cont, 0xf)), 0xa, 0xf);
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
                            SetEntryFields_021e23d0(ents, a, (int)n2, 0xa, 0xf);
                            SetPackedFields_021e24b0(ents, b, pk->d, 8, 0xf, 1, 3, 0, 0);
                            SetEntryFields_021e23d0(ents, c, (int)(GetFieldByKey020e0434((Container020e0310*)cont, 0xf)), 0xa, 0xf);
                        }
                    }
                    if (ok == 0) {
                        SetBit0(ents, 0x16);
                        SetEntryFields_021e23d0(ents, 0x16, (int)(GetFieldByKey020e0434((Container020e0310*)cont, 0xe)), 0xa, 0xf);
                    }
                    SetEntryFields_021e23d0(ents, 0x13, (int)n3, 0xa, 0xf);
                    if (pk->b10) {
                        ClrBit0(ents, 0x14);
                        SetBit0(ents, 0x17);
                        SetEntryFields_021e23d0(ents, 0x17, (int)(GetFieldByKey020e0434((Container020e0310*)cont, 0x1c)), 8, 0xf);
                        SetBit0(ents, 0x18);
                        SetPackedFields_021e24b0(ents, 0x18, b80 + 1, 8, 0xf, 0, 1, 0, 0);
                        SetBit0(ents, 0x19);
                        SetPackedFields_021e24b0(ents, 0x19, 2, 8, 0xf, 0, 1, 0, 0);
                    }
                    ClrBit0(ents, 0xe);
                    ClrBit0(ents, 0xf);
                    ClrBit0(ents, 0x10);
                    int i;
                    short id;
                    struct ArrHdr* arr = (struct ArrHdr*)FindOrGetDefaultElement_021893c4((IndexedArrayStruct021893c4*)self->arr, -1);
                    if (arr) {
                        id = 0xe;
                        for (i = 0; i < 2; i++) {
                            if (i < arr->n) {
                                SetBit0(ents, id);
                                struct Slot* s = func_ov014_0218940c(self->arr, i, arr);
                                int* v = func_ov014_02189430(self->arr, i, arr);
                                if (s->bit0) {
                                    SetEntryFields_021e23d0(ents, id, (int)((void*)*v), 0xa, 0xf);
                                } else {
                                    SetEntryFields_021e23d0(ents, id, (int)(GetFieldByKey020e0434((Container020e0310*)cont, 0x15)), 0xa, 0xf);
                                }
                                id++;
                            }
                        }
                        if (arr->n >= 3) {
                            if (func_ov014_0218940c(self->arr, 2, arr)->bit0) {
                                SetBit0(ents, 0x10);
                                SetEntryFields_021e23d0(ents, 0x10, (int)(GetFieldByKey020e0434((Container020e0310*)cont, 0x10)), 0xa, 0xf);
                            }
                        }
                    }
                }
                struct EntObj* e = self->ents;
                e->p4 = &draw;
                e->s12 = 1;
                func_ov023_021e257c(self->ents);
                ResetList0204af64((List0204af64*)&list);
                SetWord0x18ClearByte0x1f((unsigned char*)&list, 0);
                list.lo = 0;
                list.hi = 1;
                func_0204b5b4(&list, 1);
                DispatchViaTable0204b5e8((Obj0204b5e8*)&list, 0, 0);
                for (int i = 0; i < count; i++) {
                    void* r2 = FindRecordByIndex((Rec020467f0*)file, i, &rp, &rs);
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
        int count = CountActiveEntries((ActiveEntry02046900*)file);
        ResetList0204af64((List0204af64*)&list);
        SetWord0x18ClearByte0x1f((unsigned char*)&list, 0);
        list.lo = 0;
        list.hi = 1;
        func_0204b5b4(&list, 1);
        DispatchViaTable0204b5e8((Obj0204b5e8*)&list, 0, 0);
        for (int i = 0; i < count; i++) {
            void* rec = FindRecordByIndex((Rec020467f0*)file, i, &rp, &rs);
            if (rec) {
                DispatchByTag0204b2e0(&list, (char*)rec);
                DispatchByTagLookup0204b3a0((SelfTag0204b3a0*)&list, (char*)rec);
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
