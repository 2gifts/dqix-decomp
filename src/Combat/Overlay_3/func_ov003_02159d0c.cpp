#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue9A0_870 = 0x870 };
enum { kRegionValue9AE_7DE = 0x7de };
enum { kRegionValue960_800 = 0x800 };
enum { kRegionValue998_868 = 0x868 };
enum { kRegionValue34C0_3280 = 0x3280 };
#else
enum { kRegionValue9A0_870 = 0x9a0 };
enum { kRegionValue9AE_7DE = 0x9ae };
enum { kRegionValue960_800 = 0x960 };
enum { kRegionValue998_868 = 0x998 };
enum { kRegionValue34C0_3280 = 0x34c0 };
#endif

void* GetGlobalField0x1c020421a0(void);
void* GetDataPtr02114e04_020d6c00(void);
extern "C" void* func_0202ae18(void);
void AppendFieldTwice_02159290(void*, unsigned short, int);
extern "C" void func_ov003_02159250(void*, void*);
struct Struct_0205d81c;
void SetElementFieldC2_0205deb4(Struct_0205d81c*, int, int);
int CheckField0NonZero_0202b7d8(int*);
extern "C" int func_0202c540(void*);
struct Container020e0310;
void* GetFieldByKey020e0434(Container020e0310*, int);
extern "C" int func_ov003_0215bf18(void*, int);
extern "C" int func_020457e0(void*);
extern "C" void* func_0205ec34(void);
int LookupAndForEachNode020649b0(void*, int, void*);
extern "C" void func_0206f81c(void*);
void OrBitsIntoField0_020466e4(unsigned int*, unsigned int);
extern "C" void func_ov017_021d1118(int, int, int, int);
extern "C" void func_ov017_021d1014(int, int, int);
struct Struct0209c830;
void SetValueAndActivate0209c830(Struct0209c830*, int);
int CountEntriesType1WithId_020bc0a4(int);
struct Struct020a9ea4;
void ClearStruct020a9ea4(Struct020a9ea4*);
extern "C" int func_020aad1c(void*, void*, int, int);
void StopAndReset0209c7fc(void*);
extern "C" void func_02046380(void*);
struct Obj02046574;
void SetIndexedName02046574(Obj02046574*, int, char*);
void AppendString02042058(char*, char const*);
struct FlagWord020466f4;
void ClearFlags020466f4(FlagWord020466f4*, unsigned int);
struct Entry_0205d6a0;
void ResetEntryList0205d6a0(Entry_0205d6a0*, int);
extern "C" void* memset(void*, int, unsigned int);

extern int data_02109bf4;
extern int data_0211e33c;

// USA: func_ov003_02159d0c
extern "C" ARM void func_ov003_02159d0c(void* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char* g = (unsigned char*)GetGlobalField0x1c020421a0();
    void* dp = GetDataPtr02114e04_020d6c00();
    void* f = func_0202ae18();
    char buf[0x34];

    if (*(int*)(g + kRegionValue9A0_870) == 3) {
        *(unsigned char*)(g + 0x1000 + kRegionValue9AE_7DE) = 0;
    }

    unsigned char state = *(unsigned char*)(s + 0x580);

    if (state == 0) {
        if (*(unsigned char*)(s + 0x5b4) != 0) {
            if (*(unsigned char*)(s + 0x59d) != 0) return;
            memset(*(void**)(s + 0x7c), 0, kRegionValue960_800);
            AppendFieldTwice_02159290(self, 0x3e8, 0x64);
            func_ov003_02159250(self, *(void**)(s + 0x7c));
            *(unsigned char*)(s + 0x5b3) = 5;
            *(unsigned char*)(s + 0x580) = 2;
            return;
        }
        SetElementFieldC2_0205deb4((Struct_0205d81c*)(s + 0xf4), 0, 1);
        SetElementFieldC2_0205deb4((Struct_0205d81c*)(s + 0xf4), 1, 1);
        SetElementFieldC2_0205deb4((Struct_0205d81c*)(s + 0xf4), 2, 1);
        int key = 0x3f2;
        if (CheckField0NonZero_0202b7d8((int*)f) && func_0202c540(f)) {
            key += 8;
        }
        func_ov003_02159250(self, GetFieldByKey020e0434((Container020e0310*)(s + 0x64), key));
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state == 1) {
        if (*(int*)(g + kRegionValue9A0_870) != 3) return;
        int r = func_ov003_0215bf18(self, 0);
        if (r == -1) return;
        if (r == -2 || r == 1) {
            memset(*(void**)(s + 0x7c), 0, kRegionValue960_800);
            AppendFieldTwice_02159290(self, 0x3f4, 0x3f5);
            func_ov003_02159250(self, *(void**)(s + 0x7c));
            *(unsigned char*)(s + 0x580) = 4;
        } else if (r == 0) {
            *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
        }
        SetElementFieldC2_0205deb4((Struct_0205d81c*)(s + 0xf4), 0, 1);
        SetElementFieldC2_0205deb4((Struct_0205d81c*)(s + 0xf4), 1, 1);
        SetElementFieldC2_0205deb4((Struct_0205d81c*)(s + 0xf4), 2, 1);
    }

    if (state == 2) {
        if (*(unsigned char*)(s + 0x5b4) != 0) {
            if (*(int*)(g + kRegionValue998_868) == 0) {
                *(unsigned char*)(s + 0x588) = 0xb;
                *(unsigned char*)(s + 0x580) = 0;
                return;
            }
            unsigned char prev = *(unsigned char*)(s + 0x5b3);
            int cur = *(int*)(g + kRegionValue9A0_870);
            unsigned char low = cur;
            int ok = 1;
            if (prev == 6 && low == 5) {
                if (func_020457e0(g) == 0) ok = 0;
            }
            *(unsigned char*)(s + 0x5b3) = (unsigned char)*(int*)(g + kRegionValue9A0_870);
            if (ok) return;
        }
        *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) | 0x10;
        if (LookupAndForEachNode020649b0(func_0205ec34(), 0xc, buf)) {
            func_0206f81c(buf);
        }
        if (*(unsigned char*)(s + 0x5b4) == 0) {
            func_ov003_02159250(self, GetFieldByKey020e0434((Container020e0310*)(s + 0x64), 0x64));
        }
        OrBitsIntoField0_020466e4((unsigned int*)dp, 0x80);
        *(int*)(s + 0x598) = 0xf;
        if (CheckField0NonZero_0202b7d8((int*)f)) {
            func_ov017_021d1118(-1, 1, 1, 2);
            func_ov017_021d1014(-1, 1, 0);
        }
        *(unsigned char*)(s + 0x580) = 0x64;
    }

    if (state == 0x64) {
        if (CheckField0NonZero_0202b7d8((int*)f)) {
            signed char* p = (signed char*)GameState::GetInstance() + 0x4000 + kRegionValue34C0_3280;
            for (int i = 0; i < 3; i++, p += 10) {
                if (p[6] >= 4) {
                    if (((unsigned char*)p)[7] != 0 || ((unsigned char*)p)[8] != 0) return;
                    if (p[9] >= 0) return;
                }
            }
        }
        SetValueAndActivate0209c830((Struct0209c830*)&data_02109bf4, 0x3c);
        *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) | 2;
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state == 0x65) {
        if (*(int*)(g + kRegionValue9A0_870) != 3) return;
        if (CountEntriesType1WithId_020bc0a4(0x3c) == 0) return;
        if (*(int*)(g + kRegionValue9A0_870) == 3) {
            *(unsigned char*)(g + 0x1000 + kRegionValue9AE_7DE) = 0;
        }
        if (*(unsigned char*)(s + 0x59c) == 0) {
            *(unsigned char*)(s + 0x59c) = 1;
        }
        ClearStruct020a9ea4((Struct020a9ea4*)(s + 0x1b8 + 0x400));
        *(unsigned char*)(s + 0x580) = 0x66;
    }

    if (state == 0x66) {
        int flags = 1;
        if (func_0202c540(f)) flags |= 0x14;
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        if (func_020aad1c(s + 0x1b8 + 0x400, &data_0211e33c, flags, 0) == 1) {
            *(unsigned char*)(s + 0x580) = 3;
        }
        BackgroundLoader::RemoveLockGlobal();
    }

    if (state == 3) {
        if (*(int*)(g + kRegionValue9A0_870) == 3) {
            *(unsigned char*)(g + 0x1000 + kRegionValue9AE_7DE) = 0;
        }
        StopAndReset0209c7fc(&data_02109bf4);
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0) return;
        *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) & ~2;
        memset(*(void**)(s + 0x7c), 0, kRegionValue960_800);
        if (*(unsigned char*)(s + 0x5b4) != 0) {
            unsigned char* obj = (unsigned char*)GameState::GetInstance()->GetUnknownGameObject();
            func_02046380(g);
            SetIndexedName02046574((Obj02046574*)g, 0, (char*)(*(void**)(obj + 0x134)));
            AppendString02042058((char*)(*(void**)(s + 0x7c)), (char const*)GetFieldByKey020e0434((Container020e0310*)(s + 0x64), 0x3f3));
        } else {
            AppendFieldTwice_02159290(self, 0x3f3, 0x3f5);
        }
        func_ov003_02159250(self, *(void**)(s + 0x7c));
        ClearFlags020466f4((FlagWord020466f4*)dp, 0x80);
        *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) & ~0x10;
        if (*(unsigned char*)(s + 0x5b4) != 0) {
            *(unsigned char*)(s + 0x580) = 7;
            return;
        }
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state == 4) {
        if (*(int*)(g + kRegionValue9A0_870) != 3) return;
        int r = func_ov003_0215bf18(self, 0);
        if (r == -1) return;
        if (r == -2 || r == 1) {
            if (*(unsigned char*)(s + 0x59c) == 0) {
                SetElementFieldC2_0205deb4((Struct_0205d81c*)(s + 0xf4), 0, 1);
                SetElementFieldC2_0205deb4((Struct_0205d81c*)(s + 0xf4), 1, 1);
                SetElementFieldC2_0205deb4((Struct_0205d81c*)(s + 0xf4), 2, 1);
                func_ov003_02159250(self, GetFieldByKey020e0434((Container020e0310*)(s + 0x64), 0x3f7));
                *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
                return;
            }
            if (CheckField0NonZero_0202b7d8((int*)f)) {
                SetElementFieldC2_0205deb4((Struct_0205d81c*)(s + 0xf4), 0, 1);
                SetElementFieldC2_0205deb4((Struct_0205d81c*)(s + 0xf4), 1, 1);
                SetElementFieldC2_0205deb4((Struct_0205d81c*)(s + 0xf4), 2, 1);
                func_ov003_02159250(self, GetFieldByKey020e0434((Container020e0310*)(s + 0x64), 0x3f9));
                *(unsigned char*)(s + 0x580) = 6;
                return;
            }
            ResetEntryList0205d6a0((Entry_0205d6a0*)(s + 0xf4), 1);
            func_ov003_02159250(self, GetFieldByKey020e0434((Container020e0310*)(s + 0x64), 0x3f6));
            *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) | 0x10;
            *(unsigned char*)(s + 0x588) = 9;
            *(unsigned char*)(s + 0x580) = 0;
            return;
        } else if (r == 0) {
            ResetEntryList0205d6a0((Entry_0205d6a0*)(s + 0xf4), 1);
            func_ov003_02159250(self, GetFieldByKey020e0434((Container020e0310*)(s + 0x64), 0x442));
            *(unsigned char*)(s + 0x580) = 7;
        }
    }

    if (state == 5) {
        if (*(int*)(g + kRegionValue9A0_870) != 3) return;
        int r = func_ov003_0215bf18(self, 1);
        if (r == -1) return;
        if (r == -2 || r == 1) {
            SetElementFieldC2_0205deb4((Struct_0205d81c*)(s + 0xf4), 0, 1);
            SetElementFieldC2_0205deb4((Struct_0205d81c*)(s + 0xf4), 1, 1);
            SetElementFieldC2_0205deb4((Struct_0205d81c*)(s + 0xf4), 2, 1);
            func_ov003_02159250(self, GetFieldByKey020e0434((Container020e0310*)(s + 0x64), 0x3f8));
            *(unsigned char*)(s + 0x580) = 1;
            return;
        } else if (r == 0) {
            if (CheckField0NonZero_0202b7d8((int*)f)) {
                SetElementFieldC2_0205deb4((Struct_0205d81c*)(s + 0xf4), 0, 1);
                SetElementFieldC2_0205deb4((Struct_0205d81c*)(s + 0xf4), 1, 1);
                SetElementFieldC2_0205deb4((Struct_0205d81c*)(s + 0xf4), 2, 1);
                func_ov003_02159250(self, GetFieldByKey020e0434((Container020e0310*)(s + 0x64), 0x3f9));
                *(unsigned char*)(s + 0x580) = 6;
                return;
            }
            ResetEntryList0205d6a0((Entry_0205d6a0*)(s + 0xf4), 1);
            func_ov003_02159250(self, GetFieldByKey020e0434((Container020e0310*)(s + 0x64), 0x3f6));
            *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) | 0x10;
            *(unsigned char*)(s + 0x588) = 9;
            *(unsigned char*)(s + 0x580) = 0;
            return;
        }
    }

    if (state == 6) {
        if (*(int*)(g + kRegionValue9A0_870) != 3) return;
        int r = func_ov003_0215bf18(self, 1);
        if (r == -1) return;
        if (r == -2 || r == 1) {
            ResetEntryList0205d6a0((Entry_0205d6a0*)(s + 0xf4), 1);
            func_ov003_02159250(self, GetFieldByKey020e0434((Container020e0310*)(s + 0x64), 0x442));
            *(unsigned char*)(s + 0x580) = 7;
            return;
        } else if (r == 0) {
            ResetEntryList0205d6a0((Entry_0205d6a0*)(s + 0xf4), 1);
            func_ov003_02159250(self, GetFieldByKey020e0434((Container020e0310*)(s + 0x64), 0x3f6));
            *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) | 0x10;
            *(unsigned char*)(s + 0x588) = 9;
            *(unsigned char*)(s + 0x580) = 0;
            return;
        }
    }

    if (state == 7) {
        if (*(int*)(g + kRegionValue998_868) == 0) {
            *(unsigned char*)(s + 0x588) = 0xb;
            *(unsigned char*)(s + 0x580) = 0;
        }
    }
}
