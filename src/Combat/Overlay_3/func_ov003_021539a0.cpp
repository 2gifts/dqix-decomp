#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

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
struct SafeAllocator;
extern "C" unsigned char* _ZN9GameState21GetPartyMemberByIndexEi(void*, int);
extern "C" void __clear(void*, int);
extern "C" int sprintf(char* dst, const char* fmt, ...);
void* Clear0x54Bytes0208247c(void*);
unsigned char* GetFieldAt0x150(unsigned char*);
extern "C" int func_02082490(void*, void*, unsigned int, int, int);
struct Rec020467f0;
char* FindRecordByIndex(Rec020467f0*, int, void**, int*);
void SetWord0x18ClearByte0x1f(unsigned char*, int);
extern "C" void func_0204b5b4(void*, int);
struct Obj0204b5e8;
void DispatchViaTable0204b5e8(Obj0204b5e8*, int, int);
extern "C" void func_0204c684(void*);
struct Obj0204b988;
void DispatchIndexedEntry0204b988(Obj0204b988*, unsigned int, int, int, unsigned short);
struct List0204b0e8;
void FlushAndDispatchList0204b0e8(List0204b0e8*, void*);
struct Container020e0310;
char* GetFieldByKey020e0434(Container020e0310*, int);
void* GetGlobalField0x1c020421a0();
extern "C" void func_02046608(void*, int, char*, char*, int, int, int);
void SetEntryFields_021e23d0(void*, int, int, unsigned char, unsigned char);
int AccumulateFlaggedSlotBits02085fb4(unsigned char*);
int AccumulateFlaggedSlotBits02086020(unsigned char*);
int AccumulateFlaggedSlotBits0208608c(unsigned char*);
int AccumulateFlaggedSlotBits020860f8(unsigned char*);
int AccumulateFlaggedSlotBits02086164(unsigned char*);
int AccumulateFlaggedSlotBits020861d0(unsigned char*);
int AccumulateFlaggedSlotBits0208623c(unsigned char*);
int AccumulateSlotBitsFromTable020862a8(unsigned char*);
int AccumulateSlotBitsFromTable02086314(unsigned char*);
void SetPackedFields_021e24b0(void*, int, int, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
extern "C" void func_ov023_021e257c(void*);
void CleanInvalidateCacheRange(const void*, unsigned int);
extern "C" void LoadToSubBG0CharacterData(int, int, unsigned int);
void* GetWord0x0(int*);
int IsAxisIntWithin16(AxisFloats0203b5a0*, int);
struct GameResources;
void SetSubBrightness(GameResources*, int, int);

extern char data_ov003_0217fca0[];
extern char data_ov003_0217fcb5[];
extern char data_ov003_0217fcc7[];
extern char data_ov003_0217fcd5[];
extern char data_ov003_0217fcde[];
extern short data_ov003_0217f288[];

#define CAP999(x) ((x) > 999 ? 999 : (x))

// USA: func_ov003_021539a0
extern "C" ARM void func_ov003_021539a0(struct Self_021539a0* self) {
    if (self->member < 0) return;
    if (!(self->flags & 1)) return;
    struct Loader* loader = _ZN16BackgroundLoader11GetInstanceEv();
    if (self->state == 0) {
        char path[0x18];
        __clear(path, 0x18);
        sprintf(path, data_ov003_0217fca0, self->idx);
        self->task50 = ((BackgroundLoader*)loader)->QueueLoadFile(path, (SafeAllocator*)0);
        self->task54 = ((BackgroundLoader*)loader)->QueueLoadFileInGP2(data_ov003_0217fcb5, data_ov003_0217fcc7, (SafeAllocator*)0);
        self->state++;
    } else if (self->state == 1) {
        if (((BackgroundLoader*)loader)->GetTaskStatus(self->task50) == 0) return;
        if (((BackgroundLoader*)loader)->GetTaskStatus(self->task54) == 0) return;
        struct Draw_021539a0 draw;
        char text[0x400];
        char fmt[0x400];
        struct ListObj_021539a0 list;
        int vals[9];
        void* file;
        unsigned int size;
        void* rp;
        int rs;
        ((BackgroundLoader*)loader)->GetLoadedFileByID(self->task50, &file, &size);
        void* gs = GameState::GetInstance();
        unsigned char* obj = _ZN9GameState21GetPartyMemberByIndexEi(gs, self->member);
        Clear0x54Bytes0208247c(self->stats);
        unsigned char* base = 0;
        unsigned char* gfx;
        if (obj != 0 && file != 0) {
            base = GetFieldAt0x150(obj);
            func_02082490(self->stats, file, size, *(unsigned short*)(base + 0x100 + self->idx * 2 + 0x6c), 0);
        }
        ((BackgroundLoader*)loader)->RemoveTask(self->task50);
        self->task50 = -1;
        ((BackgroundLoader*)loader)->GetLoadedFileByID(self->task54, &file, &size);
        obj = (unsigned char*)FindRecordByIndex((Rec020467f0*)file, 0, &rp, &rs);
        if (obj != 0) {
            list.lo = 1;
            list.hi = 0;
            SetWord0x18ClearByte0x1f((unsigned char*)&list, 0);
            func_0204b5b4(&list, 0);
            DispatchViaTable0204b5e8((Obj0204b5e8*)&list, 0, 0);
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
                DispatchIndexedEntry0204b988((Obj0204b988*)self->list, (unsigned char)(idx + 1) & 0xff, 3, 2, 0xffff);
                FlushAndDispatchList0204b0e8((List0204b0e8*)self->list, 0);
                unsigned char cls = idx - 1;
                draw.s38 = 0xa;
                draw.s3a = 0x10;
                ents->s4a = 0x10;
                __clear(text, 0x400);
                unsigned char key = cls + cls * 2;
                char* s2 = GetFieldByKey020e0434((Container020e0310*)cont, (short)(key + 2));
                char* s1 = GetFieldByKey020e0434((Container020e0310*)cont, (short)(key + 1));
                char* s0 = GetFieldByKey020e0434((Container020e0310*)cont, (short)key);
                sprintf(fmt, data_ov003_0217fcd5, s0, s1, s2);
                func_02046608(GetGlobalField0x1c020421a0(), 0xc, fmt, text, 0xdc, 0, 1);
                SetEntryFields_021e23d0(ents, 7, (int)text, 0xc, 0xf);
                SetEntryFields_021e23d0(ents, 8, (int)data_ov003_0217fcde, 0xc, 0xf);
                SetEntryFields_021e23d0(ents, 9, (int)data_ov003_0217fcde, 0xc, 0xf);
                SetEntryFields_021e23d0(ents, 0x14, (int)data_ov003_0217fcde, 0xc, 0xf);
                int off = (idx & 0xff) * 0xc;
                unsigned char* statBase = base + 0x850;
                struct Packed3x10* row = (struct Packed3x10*)(statBase + off);
                vals[0] = CAP999(AccumulateFlaggedSlotBits02085fb4(base) + stats->w[0].a + row[0].a);
                vals[1] = CAP999(AccumulateFlaggedSlotBits02086020(base) + stats->w[0].b + row[0].b);
                vals[2] = CAP999(AccumulateFlaggedSlotBits0208608c(base) + stats->w[0].c + row[0].c);
                vals[3] = CAP999(AccumulateFlaggedSlotBits020860f8(base) + stats->w[1].a + row[1].a);
                vals[4] = CAP999(AccumulateFlaggedSlotBits02086164(base) + stats->w[1].b + row[1].b);
                vals[5] = CAP999(AccumulateFlaggedSlotBits020861d0(base) + stats->w[1].c + row[1].c);
                vals[6] = CAP999(AccumulateFlaggedSlotBits0208623c(base) + stats->w[2].a + row[2].a);
                vals[7] = CAP999(AccumulateSlotBitsFromTable020862a8(base) + stats->w[2].b + row[2].b);
                vals[8] = CAP999(AccumulateSlotBitsFromTable02086314(base) + stats->w[2].c + row[2].c);
                for (unsigned char i = 0; data_ov003_0217f288[i] >= 0; i++) {
                    SetPackedFields_021e24b0(ents, data_ov003_0217f288[i], vals[i], 8, 0xf, 1, 3, 0, 0);
                }
                ents->p4 = &draw;
                ents->s12 = 1;
                func_ov023_021e257c(ents);
            }
            CleanInvalidateCacheRange(gfx, 0x6000);
            LoadToSubBG0CharacterData((int)gfx, 0, 0x6000);
        }
        ((BackgroundLoader*)loader)->RemoveTask(self->task54);
        self->task54 = -1;
        self->f10 = self->idx;
        void* axis = GetWord0x0((int*)gs);
        if ((self->flags & 2) || !IsAxisIntWithin16((AxisFloats0203b5a0*)axis, 1)) {
            self->flags &= ~2;
            self->state++;
        } else {
            self->flags &= ~1;
            self->state = 0;
        }
    } else if (self->state == 2) {
        SetSubBrightness((GameResources*)(GetWord0x0((int*)GameState::GetInstance())), 0, 1);
        self->state = 0;
        self->flags &= ~1;
    }
}
