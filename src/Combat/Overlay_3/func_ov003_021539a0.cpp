#include <globaldefs.h>

struct Loader;
struct AxisFloats0203b5a0;

struct Packed3x10 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int pad : 2;
};

struct Stats_021539a0 {
    char pad0[8];
    struct Packed3x10 w[3];
};

struct Entry_021539a0 {
    short id;
    char pad2[0x14];
    unsigned char f16;
    char pad17;
};

struct Layout_021539a0 {
    int pad0;
    void* p4;
    struct Entry_021539a0* arr;
    char padc[6];
    short s12;
    unsigned short count;
    char pad16[0x4a - 0x16];
    short s4a;
};

struct ListObj_021539a0 {
    char pad[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
    char pad2[3];
};

struct Draw_021539a0 {
    char pad0[8];
    void* p8;
    char pad1[0x9c];
    short s28;
    short s2a;
    char pad2[8];
    short s34;
    short s36;
    short s38;
    short s3a;
    char pad3[0x24];
};

struct Self_021539a0 {
    int pad0;
    void* cont;
    struct Stats_021539a0* stats;
    struct Layout_021539a0* ents;
    int f10;
    int idx;
    char list[0x38];
    int task50;
    int task54;
    char pad58;
    signed char member;
    char pad5a[2];
    unsigned char state;
    unsigned char flags;
};

extern "C" struct Loader* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" int _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(struct Loader*, const char*, void*);
extern "C" int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(struct Loader*, const char*, const char*, void*);
extern "C" int _ZN16BackgroundLoader13GetTaskStatusEi(struct Loader*, int);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(struct Loader*, int, void**, unsigned int*);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(struct Loader*, int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* _ZN9GameState21GetPartyMemberByIndexEi(void*, int);
extern "C" void __clear(void*, int);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" void* _Z22Clear0x54Bytes0208247cPv(void*);
extern "C" unsigned char* _Z15GetFieldAt0x150Ph(unsigned char*);
extern "C" int func_02082490(void*, void*, unsigned int, int, int);
extern "C" char* _Z17FindRecordByIndexP11Rec020467f0iPPvPi(void*, int, void**, int*);
extern "C" void _Z24SetWord0x18ClearByte0x1fPhi(void*, int);
extern "C" void func_0204b5b4(void*, int);
extern "C" void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(void*, int, int);
extern "C" void func_0204c684(void*);
extern "C" void _Z28DispatchIndexedEntry0204b988P11Obj0204b988jiit(void*, unsigned int, int, int, unsigned short);
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(void*, void*);
extern "C" char* _Z21GetFieldByKey020e0434P17Container020e0310i(void*, short);
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" void func_02046608(void*, int, char*, char*, int, int, int);
extern "C" void _Z23SetEntryFields_021e23d0Pviihh(void*, int, const char*, short, short);
extern "C" int _Z33AccumulateFlaggedSlotBits02085fb4Ph(unsigned char*);
extern "C" int _Z33AccumulateFlaggedSlotBits02086020Ph(unsigned char*);
extern "C" int _Z33AccumulateFlaggedSlotBits0208608cPh(unsigned char*);
extern "C" int _Z33AccumulateFlaggedSlotBits020860f8Ph(unsigned char*);
extern "C" int _Z33AccumulateFlaggedSlotBits02086164Ph(unsigned char*);
extern "C" int _Z33AccumulateFlaggedSlotBits020861d0Ph(unsigned char*);
extern "C" int _Z33AccumulateFlaggedSlotBits0208623cPh(unsigned char*);
extern "C" int _Z35AccumulateSlotBitsFromTable020862a8Ph(unsigned char*);
extern "C" int _Z35AccumulateSlotBitsFromTable02086314Ph(unsigned char*);
extern "C" void _Z24SetPackedFields_021e24b0Pviihhhhhh(void*, int, int, short, short, short, short, short, short);
extern "C" void func_ov023_021e257c(void*);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*, unsigned int);
extern "C" void LoadToSubBG0CharacterData(int, int, unsigned int);
extern "C" void* _Z10GetWord0x0Pi(void*);
extern "C" int _Z17IsAxisIntWithin16P18AxisFloats0203b5a0i(void*, int);
extern "C" void _Z16SetSubBrightnessP13GameResourcesii(void*, int, int);

extern char data_ov003_0217fca0[];
extern char data_ov003_0217fcb5[];
extern char data_ov003_0217fcc7[];
extern char data_ov003_0217fcd5[];
extern char data_ov003_0217fcde[];
extern short data_ov003_0217f288[];

#define CAP999(x) ((x) > 999 ? 999 : (x))

static inline unsigned char* GetRecordData_021539a0(unsigned char* rec) { return rec + 0x10; }

// USA: func_ov003_021539a0
extern "C" ARM void func_ov003_021539a0(struct Self_021539a0* self) {
    if (self->member < 0) return;
    if (!(self->flags & 1)) return;
    struct Loader* loader = _ZN16BackgroundLoader11GetInstanceEv();
    if (self->state == 0) {
        char path[0x18];
        __clear(path, 0x18);
        sprintf(path, data_ov003_0217fca0, self->idx);
        self->task50 = _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader, path, 0);
        self->task54 = _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader, data_ov003_0217fcb5, data_ov003_0217fcc7, 0);
        self->state++;
    } else if (self->state == 1) {
        if (_ZN16BackgroundLoader13GetTaskStatusEi(loader, self->task50) == 0) return;
        if (_ZN16BackgroundLoader13GetTaskStatusEi(loader, self->task54) == 0) return;
        struct Draw_021539a0 draw;
        char text[0x400];
        char fmt[0x400];
        struct ListObj_021539a0 list;
        int vals[9];
        void* file;
        unsigned int size;
        void* rp;
        int rs;
        _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader, self->task50, &file, &size);
        void* gs = _ZN9GameState11GetInstanceEv();
        unsigned char* obj = _ZN9GameState21GetPartyMemberByIndexEi(gs, self->member);
        _Z22Clear0x54Bytes0208247cPv(self->stats);
        unsigned char* base = 0;
        unsigned char* gfx;
        if (obj != 0 && file != 0) {
            base = _Z15GetFieldAt0x150Ph(obj);
            func_02082490(self->stats, file, size, *(unsigned short*)(base + 0x100 + self->idx * 2 + 0x6c), 0);
        }
        _ZN16BackgroundLoader10RemoveTaskEi(loader, self->task50);
        self->task50 = -1;
        _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader, self->task54, &file, &size);
        obj = (unsigned char*)_Z17FindRecordByIndexP11Rec020467f0iPPvPi(file, 0, &rp, &rs);
        if (obj != 0) {
            list.lo = 1;
            list.hi = 0;
            _Z24SetWord0x18ClearByte0x1fPhi(&list, 0);
            func_0204b5b4(&list, 0);
            _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(&list, 0, 0);
            gfx = obj + 0x10;
            func_0204c684(&draw);
            draw.s28 = 0x20;
            draw.s2a = 0x18;
            draw.s34 = 0xc;
            draw.p8 = gfx;
            draw.s36 = 0x10;
            struct Layout_021539a0* ents;
            struct Stats_021539a0* stats;
            int idx;
            void* cont;
            cont = self->cont;
            idx = self->idx;
            stats = self->stats;
            ents = self->ents;
            if (base != 0) {
                struct Entry_021539a0* e;
                unsigned short i;
                unsigned short count;
                struct Entry_021539a0* arr;
                arr = ents->arr;
                if (arr == NULL) {
                    e = 0;
                } else {
                    count = ents->count;
                    if (count == 0) {
                        e = 0;
                    } else {
                        for (i = 0; i < count; i++) {
                            short id = arr[i].id;
                            if (id == 1) {
                                e = &arr[i];
                                goto found;
                            }
                        }
                        e = 0;
                    }
                }
            found:
                if (e) {
                    e->f16 &= ~1;
                }
                _Z28DispatchIndexedEntry0204b988P11Obj0204b988jiit(self->list, (unsigned char)(idx + 1) & 0xff, 3, 2, 0xffff);
                _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(self->list, 0);
                unsigned char cls = idx - 1;
                draw.s38 = 0xa;
                draw.s3a = 0x10;
                ents->s4a = 0x10;
                __clear(text, 0x400);
                unsigned char key = cls + cls * 2;
                char* s2 = _Z21GetFieldByKey020e0434P17Container020e0310i(cont, key + 2);
                char* s1 = _Z21GetFieldByKey020e0434P17Container020e0310i(cont, key + 1);
                char* s0 = _Z21GetFieldByKey020e0434P17Container020e0310i(cont, key);
                sprintf(fmt, data_ov003_0217fcd5, s0, s1, s2);
                func_02046608(_Z26GetGlobalField0x1c020421a0v(), 0xc, fmt, text, 0xdc, 0, 1);
                _Z23SetEntryFields_021e23d0Pviihh(ents, 7, text, 0xc, 0xf);
                _Z23SetEntryFields_021e23d0Pviihh(ents, 8, data_ov003_0217fcde, 0xc, 0xf);
                _Z23SetEntryFields_021e23d0Pviihh(ents, 9, data_ov003_0217fcde, 0xc, 0xf);
                _Z23SetEntryFields_021e23d0Pviihh(ents, 0x14, data_ov003_0217fcde, 0xc, 0xf);
                int off = (idx & 0xff) * 0xc;
                unsigned char* statBase = base + 0x850;
                struct Packed3x10* row = (struct Packed3x10*)(statBase + off);
                vals[0] = CAP999(_Z33AccumulateFlaggedSlotBits02085fb4Ph(base) + stats->w[0].a + row[0].a);
                vals[1] = CAP999(_Z33AccumulateFlaggedSlotBits02086020Ph(base) + stats->w[0].b + row[0].b);
                vals[2] = CAP999(_Z33AccumulateFlaggedSlotBits0208608cPh(base) + stats->w[0].c + row[0].c);
                vals[3] = CAP999(_Z33AccumulateFlaggedSlotBits020860f8Ph(base) + stats->w[1].a + row[1].a);
                vals[4] = CAP999(_Z33AccumulateFlaggedSlotBits02086164Ph(base) + stats->w[1].b + row[1].b);
                vals[5] = CAP999(_Z33AccumulateFlaggedSlotBits020861d0Ph(base) + stats->w[1].c + row[1].c);
                vals[6] = CAP999(_Z33AccumulateFlaggedSlotBits0208623cPh(base) + stats->w[2].a + row[2].a);
                vals[7] = CAP999(_Z35AccumulateSlotBitsFromTable020862a8Ph(base) + stats->w[2].b + row[2].b);
                vals[8] = CAP999(_Z35AccumulateSlotBitsFromTable02086314Ph(base) + stats->w[2].c + row[2].c);
                for (unsigned char i = 0; data_ov003_0217f288[i] >= 0; i++) {
                    _Z24SetPackedFields_021e24b0Pviihhhhhh(ents, data_ov003_0217f288[i], vals[i], 8, 0xf, 1, 3, 0, 0);
                }
                ents->p4 = &draw;
                ents->s12 = 1;
                func_ov023_021e257c(ents);
            }
            _Z25CleanInvalidateCacheRangePKvj(gfx, 0x6000);
            LoadToSubBG0CharacterData((int)gfx, 0, 0x6000);
        }
        _ZN16BackgroundLoader10RemoveTaskEi(loader, self->task54);
        self->task54 = -1;
        self->f10 = self->idx;
        void* axis = _Z10GetWord0x0Pi(gs);
        if ((self->flags & 2) || !_Z17IsAxisIntWithin16P18AxisFloats0203b5a0i(axis, 1)) {
            self->flags &= ~2;
            self->state++;
        } else {
            self->flags &= ~1;
            self->state = 0;
        }
    } else if (self->state == 2) {
        _Z16SetSubBrightnessP13GameResourcesii(_Z10GetWord0x0Pi(_ZN9GameState11GetInstanceEv()), 0, 1);
        self->state = 0;
        self->flags &= ~1;
    }
}
