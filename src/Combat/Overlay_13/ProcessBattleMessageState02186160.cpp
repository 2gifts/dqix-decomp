#include <globaldefs.h>

#if defined(jpn)
#define func_ov013_02186160 func_ov013_02187178
#define func_ov013_02186c64 func_ov013_02187f78
#define func_ov013_02186bd4 func_ov013_02187f00
extern unsigned char data_02114e54[];
extern "C" int func_020124b0(void*, int, int, int, int);
int IsWithinRect(unsigned char*, int, int, int, int);
extern "C" void func_ov013_02186964(void*);
#endif

extern "C" void* __clear(void* dst, int count);
struct Obj0205dee8;
void SetFieldB0AndUpdate0205dee8(struct Obj0205dee8* obj, int val);
struct Struct_0205c570;
int GetActiveScaledSum0205d794(struct Struct_0205c570* s);
extern unsigned short data_02114e30;
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern "C" void func_0205d7a0(unsigned char* obj, int val);
#if defined(jpn)
extern "C" int func_0205d97c(void*);
#else
extern "C" int func_0205d97c(int);
#endif
struct Obj0201248c;
extern "C" int func_0201248c(struct Obj0201248c* obj, int mask);
extern "C" int func_ov013_021842a0(void* obj, int index);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern int data_02108760;
void SetupBattleMessage02185774(void* obj);
void InitTag02185828(unsigned char* obj);
struct Entry_0205d6a0;
void ResetEntryList0205d6a0(struct Entry_0205d6a0* a, int flag);
extern "C" void func_ov013_02186c64(void* obj, int a, int b);
extern "C" void func_ov013_02186bd4(void* obj);

// USA: func_ov013_02186160  (semantic: ProcessBattleMessageState02186160)
extern "C" ARM void func_ov013_02186160(void* obj) {
#if defined(jpn)
    unsigned char* o = (unsigned char*)obj;
    o[0x644] |= 1;
    o[0x5c4] = 0;
    o[0x5c5] = 0;
    SetFieldB0AndUpdate0205dee8((Obj0205dee8*)(o + 0x34), 0);

    int arr[5];
    for (int j = 0; j < 5; j++)
        arr[j] = ((int*)(o + 0x610))[j];
    int dirty = 0;
    int success = dirty;
    if (func_0201248c((Obj0201248c*)&data_02114e30, 0x80)) {
        ++*(int*)(o + 0x5e4);
        dirty = 1;
    }
    if (func_0201248c((Obj0201248c*)&data_02114e30, 0x40)) {
        --*(int*)(o + 0x5e4);
        dirty = 1;
    }
    if (*(int*)(o + 0x5e4) < 0) *(int*)(o + 0x5e4) = 5;
    if (*(int*)(o + 0x5e4) >= 6) *(int*)(o + 0x5e4) = 0;
    int hit = func_020124b0(data_02114e54, 0x1e, 0x5a, 0x2a, 0xa);
    if (*(int*)(o + 0x5d4) == 2) {
        *(int*)(o + 0x5e4) = (signed char)GetActiveScaledSum0205d794((Struct_0205c570*)(o + 0x34));
        dirty = 1;
    }
    if (*(int*)(o + 0x5f4) >= 0 && *(int*)(o + 0x5e4) < 5) {
        if (func_0201248c((Obj0201248c*)&data_02114e30, 0x20) ||
            func_0201248c((Obj0201248c*)&data_02114e30, 2) ||
            (data_02114e54[0x5c] && IsWithinRect(data_02114e54, 0x52, *(int*)(o + 0x5e4) * 0xd + 0x12, 0xe, 0xb))) {
            if ((o + *(int*)(o + 0x5e4))[0x624] == 0) {
                ((int*)(o + 0x610))[*(int*)(o + 0x5e4)]--;
                dirty = 1;
                if (((int*)(o + 0x610))[*(int*)(o + 0x5e4)] < 0)
                    ((int*)(o + 0x610))[*(int*)(o + 0x5e4)] = 0;
                else
                    DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 0x5d, 0);
            }
        } else if (*(int*)(o + 0x5f4) > 0) {
            if (((int*)(o + 0x5fc))[*(int*)(o + 0x5e4)] != 0x64) {
                if (((int*)(o + 0x5fc))[*(int*)(o + 0x5e4)] > *(int*)(o + 0x5f8)) {
                    if (func_0201248c((Obj0201248c*)&data_02114e30, 0x611) ||
                        (data_02114e54[0x5c] && IsWithinRect(data_02114e54, 0x8c, *(int*)(o + 0x5e4) * 0xd + 0x14, 0xe, 0xb))) {
                        o[0x644] &= ~1;
                        o[0x5c8] = 2;
                        success = 1;
                        dirty = success;
                        if (o[0x5cc]) InitTag02185828(o);
                        else func_ov013_02186964(o);
                        if (!o[0x5cc]) {
                            SetFieldB0AndUpdate0205dee8((Obj0205dee8*)(o + 0x34), 4);
                            ResetEntryList0205d6a0((Entry_0205d6a0*)(o + 0x34), 0);
                        }
                    }
                } else {
                    int changed = 0;
                    if (func_0201248c((Obj0201248c*)&data_02114e30, 0x611) ||
                        (data_02114e54[0x5c] && IsWithinRect(data_02114e54, 0x84, *(int*)(o + 0x5e4) * 0xd + 0x14, 0xe, 0xb))) {
                        if ((o + *(int*)(o + 0x5e4))[0x624] == 0) {
                            ((int*)(o + 0x610))[*(int*)(o + 0x5e4)]++;
                            changed = 1;
                            dirty = changed;
                        }
                    }
                    if (((int*)(o + 0x610))[*(int*)(o + 0x5e4)] + ((int*)(o + 0x5fc))[*(int*)(o + 0x5e4)] > *(int*)(o + 0x5f8)) {
                        ((int*)(o + 0x610))[*(int*)(o + 0x5e4)]--;
                        changed = 0;
                        if (*(int*)(o + 0x5f8) != 0x64) {
                        o[0x644] &= ~1;
                        o[0x5c8] = 2;
                        success = 1;
                        dirty = success;
                        if (o[0x5cc]) InitTag02185828(o);
                        else func_ov013_02186964(o);
                        if (!o[0x5cc]) {
                            SetFieldB0AndUpdate0205dee8((Obj0205dee8*)(o + 0x34), 4);
                            ResetEntryList0205d6a0((Entry_0205d6a0*)(o + 0x34), 0);
                        }
                        }
                    }
                    if (changed)
                        DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 0x5d, 0);
                }
            }
        }
    }
    int mode = -1;
    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601) && o[0x5c8] != 2) {
        if (*(int*)(o + 0x5e4) != 5 && *(int*)(o + 0x5f4) == 0) {
            *(int*)(o + 0x5e4) = 5;
            dirty = 1;
        } else if (*(int*)(o + 0x5e4) == 5) {
            mode = 3;
        } else if (func_0205d97c(o + 0x34) == 2) {
            mode = 4;
        }
    } else {
        if ((func_0201248c((Obj0201248c*)&data_02114e30, 0x611) ||
             (data_02114e54[0x5c] && IsWithinRect(data_02114e54, 0x84, *(int*)(o + 0x5e4) * 0xd + 0x14, 0xe, 0xb))) &&
            *(int*)(o + 0x5e4) != 5 && *(int*)(o + 0x5f4) == 0) {
            *(int*)(o + 0x5e4) = 5;
            dirty = 1;
        } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2) && o[0x5c8] != 2) {
            if (arr[*(int*)(o + 0x5e4)] == 0 || *(int*)(o + 0x5e4) == 5 || *(int*)(o + 0x5e4) == 6)
                mode = 4;
        } else if (*(int*)(o + 0x5e4) == 5 && o[0x5c8] != 2 && data_02114e54[0x54] &&
                   *(unsigned int*)(data_02114e54 + 0x44) < 0x14 && o[0x5ed] == 1) {
            if (hit) {
                o[0x5ed] = 0;
                mode = 3;
            }
        } else if (func_0205d97c(o + 0x34) == 2 && o[0x5c8] != 2) {
            mode = 4;
        }
    }
    if (mode == 3 || mode == 4) {
        if (mode == 3) o[0x5c8] = 3;
        else o[0x5c8] = 4;
        o[0x644] &= ~1;
        success = 1;
        dirty = success;
        if (o[0x5cc] == 0) {
            DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, success, 0);
            SetFieldB0AndUpdate0205dee8((Obj0205dee8*)(o + 0x34), 4);
            ResetEntryList0205d6a0((Entry_0205d6a0*)(o + 0x34), 0);
        } else {
            DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 5, 0);
        }
        if (o[0x5cc]) InitTag02185828(o);
        else func_ov013_02186964(o);
    } else {
        if (*(int*)(o + 0x5e4) == 5 && data_02114e54[0x54] && hit)
            o[0x5ed] = 1;
        else if (data_02114e54[0x55] && !hit)
            o[0x5ed] = 0;
    }
    int sum = 0;
    for (int k = 0; k < 5; k++)
        sum += ((int*)(o + 0x610))[k];
    *(int*)(o + 0x5f4) = *(int*)(o + 0x5f0) - sum;
    if (success)
        func_ov013_02186c64(o, 0, 1);
    else if (dirty)
        func_ov013_02186bd4(o);
#else
    unsigned char* o = (unsigned char*)obj;

    o[0x6bc] |= 1;
    o[0x638] = 0;
    o[0x639] = 0;
    SetFieldB0AndUpdate0205dee8((struct Obj0205dee8*)(o + 0x38), 0);

    int arr[6];
    __clear(arr, 0x18);
    for (int j = 0; j < 5; j++) {
        arr[j] = ((int*)(o + 0x688))[j];
    }

    int dirty, success, mode, oldF65c;
    oldF65c = *(int*)(o + 0x65c);
    dirty = 0;
    success = dirty;
    mode = dirty - 1;
    *(int*)(o + 0x65c) = GetActiveScaledSum0205d794((struct Struct_0205c570*)(o + 0x38));

    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601) != 0) {
        if (*(int*)(o + 0x65c) != 5) {
            if (*(int*)(o + 0x66c) == 0) {
                *(int*)(o + 0x65c) = 5;
                func_0205d7a0(o + 0x38, 5);
                *(int*)(o + 0x64c) = dirty;
                dirty = 1;
            }
        } else {
            mode = 3;
        }
    } else {
        int b = func_0205d97c((int)(o + 0x38));
        if (b == 2) {
            mode = 4;
        } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2) != 0) {
            if (arr[*(int*)(o + 0x65c)] == 0) {
                mode = 4;
            }
        }
    }

    int f648 = *(int*)(o + 0x648);
    if (f648 == 0) {
        if (*(int*)(o + 0x66c) >= 0 && *(int*)(o + 0x65c) < 5) {
            if (func_0201248c((struct Obj0201248c*)&data_02114e30, 0x20) != 0 ||
                func_0201248c((struct Obj0201248c*)&data_02114e30, 2) != 0 ||
                func_ov013_021842a0((void*)(o + 0x38), 0xa) != 0) {
                *(int*)(o + 0x64c) = 0;
                if ((o + *(int*)(o + 0x65c))[0x69c] == 0) {
                    ((int*)(o + 0x688))[*(int*)(o + 0x65c)]--;
                    dirty = 1;
                    if (((int*)(o + 0x688))[*(int*)(o + 0x65c)] >= 0) {
                        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 0x5d, 0);
                    } else {
                        ((int*)(o + 0x688))[*(int*)(o + 0x65c)] = 0;
                    }
                }
            } else if (*(int*)(o + 0x66c) > 0) {
                int r7flag = 0;
                *(int*)(o + 0x64c) = 0;
                int v674b = ((int*)(o + 0x674))[*(int*)(o + 0x65c)];
                if (v674b != 0x64) {
                    int v688b = ((int*)(o + 0x688))[*(int*)(o + 0x65c)];
                    if (v674b + v688b < 0x64) {
                        if (func_0201248c((struct Obj0201248c*)&data_02114e30, 0x611) != 0 ||
                            func_ov013_021842a0((void*)(o + 0x38), 0xb) != 0) {
                            if ((o + *(int*)(o + 0x65c))[0x69c] == 0) {
                                ((int*)(o + 0x688))[*(int*)(o + 0x65c)]++;
                                r7flag = 1;
                                dirty = r7flag;
                            }
                        }
                        if (r7flag != 0) {
                            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 0x5d, 0);
                        }
                    }
                }
            }
        }
    } else {
        dirty = 1;
        if (f648 == 2 && *(int*)(o + 0x64c) == f648 && oldF65c == 5 && *(int*)(o + 0x65c) == 5) {
            mode = 3;
        }
        *(int*)(o + 0x64c) = f648;
    }

    if (mode >= 0) {
        *(int*)(o + 0x64c) = 0;
        o[0x63c] = (unsigned char)mode;
        o[0x665] = 0;
        o[0x6bc] &= ~1;
        success = 1;
        dirty = 1;
        if (o[0x640] == 0) {
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, success, 0);
            SetFieldB0AndUpdate0205dee8((struct Obj0205dee8*)(o + 0x38), 4);
            ResetEntryList0205d6a0((struct Entry_0205d6a0*)(o + 0x38), 0);
        } else {
            DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 5, 0);
        }
        if (o[0x640] != 0) {
            InitTag02185828(o);
        } else {
            SetupBattleMessage02185774(o);
        }
    }

    int sum = 0;
    for (int k = 0; k < 5; k++) {
        sum += ((int*)(o + 0x688))[k];
    }
    *(int*)(o + 0x66c) = *(int*)(o + 0x668) - sum;

    if (success != 0) {
        func_ov013_02186c64(o, 0, 1);
    } else if (dirty != 0) {
        func_ov013_02186bd4(o);
    }
#endif
}
