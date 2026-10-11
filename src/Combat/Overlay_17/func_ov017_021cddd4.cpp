#include <globaldefs.h>

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
extern "C" void* func_ov017_021b8478(void* obj);

struct Src021bd35c { unsigned short h0, h2, h4, h6, h8; };
struct S021bd35c {
    unsigned char pad0[0x16];
    unsigned short field_0x16;
    unsigned short field_0x18;
    unsigned short field_0x1a;
    unsigned char pad1c[0x52 - 0x1c];
    unsigned short field_0x52;
};
struct Obj_021bd3a4;

extern "C" void _Z26CopyFiveHalfwords_021bd35cP9S021bd35cP11Src021bd35c(S021bd35c* obj, Src021bd35c* src);
extern "C" void _Z18SetFieldA_021bb9ecPvt(void* obj, unsigned short v);
extern "C" int _Z29HasFlag3orFlag2And9a_021bd3a4P12Obj_021bd3a4(Obj_021bd3a4* obj);
extern "C" void _Z27EnqueueEventTag107_021cdd70tttttth(unsigned short a0, unsigned short a1, unsigned short a2, unsigned short a3, unsigned short a4, unsigned short a5, unsigned char a6);

struct ByteTable3 { unsigned char v[3]; };
extern const ByteTable3 data_ov017_021d6ce8;

struct Evt021cddd4 {
    unsigned char pad0[4];
    unsigned short field_0x4;
    unsigned short field_0x6;
    unsigned short field_0x8;
    unsigned short field_0xa;
    unsigned short field_0xc;
    unsigned short field_0xe;
    unsigned char field_0x10;
};

struct Entry021cddd4 {
    unsigned char pad0[0xc];
    int field_0xc;
};

struct Base021cddd4 {
#if defined(jpn)
    unsigned char pad0[0x3508];
#else
    unsigned char pad0[0x3718];
#endif
    void* table;
    unsigned char pad371c[0x3734 - 0x371c];
    S021bd35c* obj;
};

// JPN: func_ov017_021ce27c
// USA: func_ov017_021cddd4
extern "C" ARM void func_ov017_021cddd4(int p0, Evt021cddd4* evt, int unused, Base021cddd4* base, SearchStruct0202c1a4* search) {
    Entry021cddd4* entry = (Entry021cddd4*)func_ov017_021b8478(base->table);
    S021bd35c* obj = base->obj;
    if (p0 == 0) {
        if (evt->field_0x10 == GetSearchStructCurrentArrEntry(search)) {
            Src021bd35c src;
            src.h0 = evt->field_0x4;
            src.h2 = evt->field_0x8;
            src.h4 = evt->field_0xa;
            src.h8 = evt->field_0xc;
            src.h6 = evt->field_0xe;
            _Z26CopyFiveHalfwords_021bd35cP9S021bd35cP11Src021bd35c(obj, &src);
            ByteTable3 tbl = data_ov017_021d6ce8;
            _Z18SetFieldA_021bb9ecPvt(obj, tbl.v[evt->field_0x6]);
        }
    } else if (GetSearchStructCurrentArrEntry(search) == 0) {
        int kind = entry->field_0xc;
        S021bd35c* cur = base->obj;
        if (kind == evt->field_0x4) {
            _Z27EnqueueEventTag107_021cdd70tttttth(evt->field_0x4, 0, 0, 0, 0, 0, p0);
        } else if (kind == 0x13) {
            _Z27EnqueueEventTag107_021cdd70tttttth(evt->field_0x4, 1, 0x71e8, 0xffff, 0x199, 0x71e8, p0);
        } else if (_Z29HasFlag3orFlag2And9a_021bd3a4P12Obj_021bd3a4((Obj_021bd3a4*)cur)) {
            S021bd35c* o = base->obj;
            _Z27EnqueueEventTag107_021cdd70tttttth(evt->field_0x4, 1, o->field_0x16, o->field_0x52, o->field_0x1a, o->field_0x18, p0);
        } else {
            _Z27EnqueueEventTag107_021cdd70tttttth(evt->field_0x4, 2, 0, 0, 0, 0, p0);
        }
    }
}
