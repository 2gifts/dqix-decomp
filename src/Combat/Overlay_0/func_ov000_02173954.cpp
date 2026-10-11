#include <globaldefs.h>



struct Obj0204b010;
struct Obj0204b8d0;
struct Obj0204b878;
struct Cont0205d1e0;
struct Cont0205d228;
struct Cont0205d274;
struct EntryList0204af14;
struct Struct0217f5e4;

void ClearBuffer0204b010(struct Obj0204b010*, void*);
void DispatchEntry0204b8d0(struct Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
void ClearBuffers0204b010OverList0x98(struct Cont0205d1e0*);
void CallFunc0204c8f0OverList0x9c(struct Cont0205d228*);
void CallFunc0204b04cOverList0x98(struct Cont0205d274*);
void* GetEntryByIndexStride0x10(struct EntryList0204af14*, unsigned int);
void CallFunc0204b620IfField0x14_0204b878(struct Obj0204b878*, int, int, int, short, short, short, short, unsigned short);
void SetFieldRange0217f5e4(struct Struct0217f5e4*, int);


extern "C" void func_0204b04c(void*, int);
extern "C" void* func_0202ae18(void*);
extern "C" void func_0203bd08(void*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void func_ov000_0217a8f4(void*);
extern "C" void func_ov000_021750e4(void*);
extern "C" void func_ov000_02175544(void*);
extern "C" void func_ov000_02180bac(void*);
extern "C" void func_ov000_02170538(void*, int, int, int);
extern "C" int func_ov000_0217f5dc(void*);
extern "C" void func_ov000_021707f0(void*);
extern "C" void func_ov000_02181164(void*, int, int, int, int, int, int, int);
extern "C" int func_ov000_02174324(void*, int, int, int);
extern "C" void func_ov000_02180ca8(void*, void*, void*);
#if defined(jpn)
extern "C" void func_ov000_0218124c(void*, int, void*, int, short, short);
#else
extern "C" void func_ov000_0218124c(void*, int, void*, int, short, short, short, short);
#endif
extern "C" void func_ov000_021741e0(void* obj, float maxSpeed, float speed, int x, int argE,
    unsigned char slotIdx, unsigned char byteG, unsigned char byteH, unsigned char byteI, unsigned char flagJ);
#if defined(jpn)
extern "C" void _Z32InitSlotHPCategoryEntry_021811f4Pviii(void*, int, void*, int, short, short);
#else
extern "C" void _Z32InitSlotHPCategoryEntry_021811f4Pviii(void*, int, short, short);
#endif

extern const int data_ov000_021833cc[][2];
extern const int data_ov000_021833c8[][2];
extern const int data_ov000_02183390[];
extern const int data_ov000_02183398[];
extern const int data_ov000_021833dc[][2];
extern const int data_ov000_021833d8[][2];

struct Slot02173954 {
    char pad0[8];
    short s8;
    short sa;
    short sc;
    short se;
    char pad1[0x24 - 0x10];
    unsigned char flags;
    char pad2[0x44 - 0x25];
    int x;
    int y;
    int idx;
#if defined(jpn)
    char pad3[0x47f - 0x50];
    unsigned char b47f;
#else
    char pad3[0x440 - 0x50];
#endif
    unsigned char b440;
#if defined(jpn)
    char pad4[0x488 - 0x481];
#else
    char pad4[0x448 - 0x441];
#endif
};

static inline int InRange(int i) { return i >= 0 && i <= 3; }

// USA: func_ov000_02173954
// JPN: func_ov000_02174f18
extern "C" ARM void func_ov000_02173954(char* obj) {
#if defined(jpn)
    if (*(unsigned short*)(obj + 0x1faa) & 0x80) {
#else
    if (*(unsigned short*)(obj + 0x1d72) & 0x80) {
#endif
        ClearBuffer0204b010((struct Obj0204b010*)(obj + 0x8a4), 0);
        DispatchEntry0204b8d0((struct Obj0204b8d0*)(obj + 0x8c4), 0, 0, 0, 0, 0, 0x20, 0x19, 0xffff);
        ClearBuffers0204b010OverList0x98((struct Cont0205d1e0*)(obj + 0x188));
        func_0204b04c(obj + 0x8c4, 0);
        return;
    }
    func_ov000_0217a8f4(obj);
    func_ov000_021750e4(obj);
    ClearBuffer0204b010((struct Obj0204b010*)(obj + 0x8a4), 0);
    DispatchEntry0204b8d0((struct Obj0204b8d0*)(obj + 0x8c4), 0, 0, 0, 0, 0, 0x20, 0x19, 0xffff);
    ClearBuffers0204b010OverList0x98((struct Cont0205d1e0*)(obj + 0x188));
#if defined(jpn)
    if (*(unsigned char*)(obj + 0x1fb8) == 0 && (*(unsigned short*)(obj + 0x1faa) & 0x600)) {
#else
    if (*(unsigned char*)(obj + 0x1d80) == 0 && (*(unsigned short*)(obj + 0x1d72) & 0x600)) {
#endif
        CallFunc0204c8f0OverList0x9c((struct Cont0205d228*)(obj + 0x188));
        func_ov000_02175544(obj);
        func_0204b04c(obj + 0x8a4, 0);
        func_0204b04c(obj + 0x8c4, 0);
        CallFunc0204b04cOverList0x98((struct Cont0205d274*)(obj + 0x188));
        func_ov000_02180bac(obj);
        return;
    }
    func_0203bd08(func_0202ae18(_ZN9GameState11GetInstanceEv()));
    signed char* ids;
#if defined(jpn)
    int x, y;
#endif
    int tx, ty;
    int found;
    int kA, kB;
#if defined(jpn)
    int idx, w;
#endif
    short ww, hh;
    unsigned char e440;
#if defined(jpn)
    unsigned char e47f;
#else
    int x, y;
#endif
    struct Slot02173954* e;
#if defined(jpn)
    int i, h;
#else
    int i, idx, w, h;
#endif
    found = -1;
    for (i = 0; i < 4; i++) {
        ids = (signed char*)(obj + 0x6c);
        e = (struct Slot02173954*)(obj + 0x958) + ids[i];
        idx = e->idx;
        if (idx < 0) continue;
        w = e->sc;
        h = e->se;
        ww = e->s8;
        hh = e->sa;
        e440 = e->b440;
#if defined(jpn)
        e47f = e->b47f;
#endif
        if (e->flags & 8) {
            func_ov000_02170538(e, *(int*)(obj + 0x940), *(int*)(obj + 0x944), *(unsigned char*)(obj + 0x954));
        } else {
            func_ov000_02170538(e, 0, 0, *(unsigned char*)(obj + 0x954));
        }
        x = e->x;
        y = e->y;
        tx = x >> 3;
        ty = y >> 3;
        if (!func_ov000_0217f5dc(e)) continue;
        SetFieldRange0217f5e4((struct Struct0217f5e4*)obj, (int)e);
        if (e->flags & 4) {
            found = idx;
            int wh[2];
            int a[2] = { x + 0x37, x + 0x37 };
            int b[2] = { y + 0x1c, y + 0x2c };
#if defined(jpn)
            int c[2] = { i * 3 + 0x60, i * 3 + 0x6c };
#else
            int c[2] = { i * 3 + 0x64, i * 3 + 0x70 };
#endif
            int p = *(int*)(obj + 0x170) + 0x118;
            kA = 0;
            int d[2];
            wh[0] = w;
            wh[1] = h;
            d[0] = p;
            d[1] = p;
            for (; kA < 2; kA++) {
                func_ov000_02181164(obj, wh[kA], d[kA], a[kA], b[kA], 1, c[kA], 0xa);
            }
            float dv[2];
            dv[0] = (1.52f * (float)w) / (float)ww;
            dv[1] = (1.52f * (float)h) / (float)hh;
            int wh2[2] = { w, h };
            int j = 0;
#if defined(jpn)
#else
            int base = i * 2 + 1;
#endif
            for (; j < 2; j++) {
                if (wh2[j] > 0) {
                    int argE = y + data_ov000_021833cc[j][0];
                    unsigned char g = data_ov000_02183390[j];
                    unsigned char hb = i + data_ov000_02183398[j];
#if defined(jpn)
                    unsigned char ib = (i * 2 + 1) - (-j);
#else
                    unsigned char ib = base + j;
#endif
                    func_ov000_021741e0(obj, dv[j], 1.52f, x + data_ov000_021833c8[j][0], argE, g, hb, ib, 1, 0);
                }
            }
            DispatchEntry0204b8d0((struct Obj0204b8d0*)(obj + 0x8c4), 1, 0, 0, tx, ty, 0x20, 0x19, idx + 2);
#if defined(jpn)
            if (!func_ov000_02174324(obj, ids[i], x + 0x25, y + 0x17)) {
                _Z32InitSlotHPCategoryEntry_021811f4Pviii(obj, idx, obj + 0x8c4, e47f, tx + 7, ty + 3);
                func_ov000_0218124c(obj, idx, obj + 0x8c4, e440, tx + 2, ty + 2);
#else
            if (!func_ov000_02174324(obj, ids[i], x + 0x24, y + 0x16)) {
                _Z32InitSlotHPCategoryEntry_021811f4Pviii(obj, idx, x + 0x2c, y + 0x16);
                func_ov000_0218124c(obj, idx, obj + 0x8c4, e440, tx + 2, ty + 2, x + 0xc, y + 0x16);
#endif
            }
            func_ov000_021707f0(e);
        } else {
            int ox = 0;
            int oy = 0;
            if (e->flags & 8) {
                ox = *(int*)(obj + 0x940);
                oy = *(int*)(obj + 0x944);
            }
            int wh[2];
#if defined(jpn)
            int a[2] = { x + 0x72 + ox, x + 0x72 + ox };
#else
            int a[2] = { x + 0x6a + ox, x + 0x6a + ox };
#endif
            int b[2] = { y + 1 + oy, y + 0xf + oy };
#if defined(jpn)
            int c[2] = { i * 3 + 0x60, i * 3 + 0x6c };
#else
            int c[2] = { i * 3 + 0x64, i * 3 + 0x70 };
#endif
            int p = *(int*)(obj + 0x170) + 0x118;
            kB = 0;
            int d[2] = { p, p };
            wh[0] = w;
            wh[1] = h;
            for (; kB < 2; kB++) {
                func_ov000_02181164(obj, wh[kB], d[kB], a[kB], b[kB], 1, c[kB], 9);
            }
            float dv[2];
            dv[0] = (1.28f * (float)w) / (float)ww;
            dv[1] = (1.28f * (float)h) / (float)hh;
            int wh2[2] = { w, h };
            int j = 0;
#if defined(jpn)
#else
            int base = i * 2 + 1;
#endif
            for (; j < 2; j++) {
                if (wh2[j] > 0) {
                    int argE = y + data_ov000_021833dc[j][0];
                    unsigned char g = data_ov000_02183390[j];
                    unsigned char hb = i + data_ov000_02183398[j];
#if defined(jpn)
                    unsigned char ib = (i * 2 + 1) - (-j);
#else
                    unsigned char ib = base + j;
#endif
                    func_ov000_021741e0(obj, dv[j], 1.28f, x + data_ov000_021833d8[j][0], argE, g, hb, ib, 1, 1);
                }
            }
            char* list = obj + 0x8c4;
            if (e->flags & 8) list = obj + 0x8a4;
            void* ent = GetEntryByIndexStride0x10((struct EntryList0204af14*)(obj + 0x8c4), 2);
#if defined(jpn)
            CallFunc0204b620IfField0x14_0204b878((struct Obj0204b878*)list, (int)ent, 0, 0, tx + 2, ty, 0x20, 0x19, idx + 2);
#else
            CallFunc0204b620IfField0x14_0204b878((struct Obj0204b878*)list, (int)ent, 0, 0, tx + 1, ty, 0x20, 0x19, idx + 2);
#endif
            func_ov000_02180ca8(obj, e, list);
#if defined(jpn)
            if (!func_ov000_02174324(obj, idx, x + 0x30, y + 0x16)) {
                _Z32InitSlotHPCategoryEntry_021811f4Pviii(obj, idx, list, e47f, tx + 8, ty + 3);
                func_ov000_0218124c(obj, idx, list, e440, tx + 3, ty + 2);
#else
            if (!func_ov000_02174324(obj, idx, x + 0x28, y + 0x16)) {
                _Z32InitSlotHPCategoryEntry_021811f4Pviii(obj, idx, x + 0x2c, y + 0x16);
                func_ov000_0218124c(obj, idx, list, e440, tx + 2, ty + 2, x + 0x14, y + 0x16);
#endif
            }
        }
    }
    if (InRange(found)) {
        CallFunc0204c8f0OverList0x9c((struct Cont0205d228*)(obj + 0x188));
        func_ov000_02175544(obj);
    }
    func_0204b04c(obj + 0x8a4, 0);
    func_0204b04c(obj + 0x8c4, 0);
    CallFunc0204b04cOverList0x98((struct Cont0205d274*)(obj + 0x188));
}
