#include <globaldefs.h>

#if defined(jpn)
#define func_ov013_0218683c func_ov013_02187b68
#endif

void InitTag02185aac(unsigned char* obj);
struct Obj0205dee8;
void SetFieldB0AndUpdate0205dee8(struct Obj0205dee8* obj, int val);
extern unsigned short data_02114e30;
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
struct Struct_0205c570;
int GetActiveScaledSum0205d794(struct Struct_0205c570* s);
struct Obj0205eaa0;
extern struct Obj0205eaa0 data_02108760;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
struct Entry_0205d6a0;
void ResetEntryList0205d6a0(struct Entry_0205d6a0* a, int flag);
void InvalidateBattlerField0x18(unsigned char* obj);
extern "C" void func_ov013_02186c64(void* obj, int a, int b);
extern "C" void func_ov013_02185cc0(void* obj);
extern "C" int _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(void* a, int b);
extern "C" void func_ov013_02186c1c(void* obj);

// USA: func_ov013_0218683c  (semantic: AdvanceOrResetTagState0218683c)
extern "C" ARM void func_ov013_0218683c(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    int dirty = 0;
    o[0x6bc] |= 1;
    o[0x63a] = dirty;

    if (o[0x63e] == 0) {
        if (o[0x63c] == 4) *(int*)(o + 0x660) = 1;
        else *(int*)(o + 0x660) = dirty;
        InitTag02185aac(o);
        o[0x63e] = o[0x63e] + 1;
        return;
    }
    if (o[0x63e] != 1) return;

    SetFieldB0AndUpdate0205dee8((struct Obj0205dee8*)(o + 0x38), 3);
    o[0x63b] = 0;
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0xc0) != 0) {
        if (*(int*)(o + 0x660) == 0) *(int*)(o + 0x660) = 1;
        else *(int*)(o + 0x660) = 0;
        dirty = 1;
    }

    if (*(int*)(o + 0x648) == 2) {
        *(int*)(o + 0x660) = (signed char)GetActiveScaledSum0205d794((struct Struct_0205c570*)(o + 0x38));
        dirty = 1;
    }

    if (o[0x63d] == o[0x63c]) {
        if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601) != 0) {
            DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
            if (o[0x63c] == 4) {
                int one = 1;
                if (*(int*)(o + 0x660) == 0) {
                    o[0x63c] = 5;
                    ResetEntryList0205d6a0((struct Entry_0205d6a0*)(o + 0x38), one);
                    o[0x664] = 0;
                } else {
                    o[0x63c] = one;
                    InvalidateBattlerField0x18((unsigned char*)&data_02114e30);
                    o[0x664] = 0;
                    SetFieldB0AndUpdate0205dee8((struct Obj0205dee8*)(o + 0x38), 3);
                    ResetEntryList0205d6a0((struct Entry_0205d6a0*)(o + 0x38), 0);
                    SetFieldB0AndUpdate0205dee8((struct Obj0205dee8*)(o + 0x38), 2);
                    ResetEntryList0205d6a0((struct Entry_0205d6a0*)(o + 0x38), 0);
                    o[0x639] = 0;
                    o[0x6bc] &= ~1;
                    func_ov013_02186c64(o, 0, 0);
                    func_ov013_02185cc0(o);
                }
            } else {
                if (*(int*)(o + 0x660) == 0) {
                    int one = 1;
                    o[0x664] = one;
                    o[0x63c] = 5;
                    ResetEntryList0205d6a0((struct Entry_0205d6a0*)(o + 0x38), one);
                } else {
                    SetFieldB0AndUpdate0205dee8((struct Obj0205dee8*)(o + 0x38), 3);
                    ResetEntryList0205d6a0((struct Entry_0205d6a0*)(o + 0x38), 0);
                    SetFieldB0AndUpdate0205dee8((struct Obj0205dee8*)(o + 0x38), 2);
                    ResetEntryList0205d6a0((struct Entry_0205d6a0*)(o + 0x38), 0);
                    o[0x639] = 0;
                    o[0x63c] = 1;
                    InvalidateBattlerField0x18((unsigned char*)&data_02114e30);
                    o[0x6bc] &= ~1;
                    func_ov013_02186c64(o, 0, 0);
                    func_ov013_02185cc0(o);
                }
            }
            o[0x63e] = 0;
        } else {
            if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2) != 0 ||
                (*(int*)(o + 0x660) == 1 && _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38((void*)(o + 0x38), 0x14) != 0)) {
                if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2) == 0) {
                    DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
                }
                SetFieldB0AndUpdate0205dee8((struct Obj0205dee8*)(o + 0x38), 3);
                ResetEntryList0205d6a0((struct Entry_0205d6a0*)(o + 0x38), 0);
                SetFieldB0AndUpdate0205dee8((struct Obj0205dee8*)(o + 0x38), 2);
                ResetEntryList0205d6a0((struct Entry_0205d6a0*)(o + 0x38), 0);
                o[0x639] = 0;
                o[0x63c] = 1;
                InvalidateBattlerField0x18((unsigned char*)&data_02114e30);
                o[0x63e] = 0;
                o[0x6bc] &= ~1;
                func_ov013_02186c64(o, 0, 0);
                func_ov013_02185cc0(o);
            } else {
                if (*(int*)(o + 0x660) == 0 &&
                    _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38((void*)(o + 0x38), 0x14) != 0) {
                    DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
                    int one = 1;
                    if (o[0x63c] == 4) {
                        o[0x63c] = 5;
                        ResetEntryList0205d6a0((struct Entry_0205d6a0*)(o + 0x38), one);
                        o[0x664] = 0;
                    } else {
                        o[0x664] = one;
                        o[0x63c] = 5;
                        ResetEntryList0205d6a0((struct Entry_0205d6a0*)(o + 0x38), one);
                        o[0x63e] = 0;
                    }
                }
            }
        }
    }

    if (dirty != 0) {
        func_ov013_02186c1c(o);
    }
}
