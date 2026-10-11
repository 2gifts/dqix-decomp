#include <globaldefs.h>

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


extern "C" void* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v(void);
extern "C" void* func_0202ae18(void);
extern "C" void _Z25AppendFieldTwice_02159290Pvii(void*, int, int);
extern "C" void func_ov003_02159250(void*, void*);
extern "C" void _Z17SetElementFieldC2P15Struct_0205d81cii(void*, int, int);
extern "C" int _Z18CheckField0NonZeroPi(void*);
extern "C" int func_0202c540(void*);
extern "C" void* _Z21GetFieldByKey020e0434P17Container020e0310i(void*, int);
extern "C" int func_ov003_0215bf18(void*, int);
extern "C" int func_020457e0(void*);
extern "C" void* func_0205ec34(void);
extern "C" int _Z28LookupAndForEachNode020649b0PviS_(void*, int, void*);
extern "C" void func_0206f81c(void*);
extern "C" void _Z16OrBitsIntoField0Pjj(void*, unsigned int);
extern "C" void func_ov017_021d1118(int, int, int, int);
extern "C" void func_ov017_021d1014(int, int, int);
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void _Z27SetValueAndActivate0209c830P14Struct0209c830t(void*, int);
extern "C" int _Z23CountEntriesType1WithIdi(int);
extern "C" void _Z19ClearStruct020a9ea4P14Struct020a9ea4(void*);
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv(void);
extern "C" void _ZN16BackgroundLoader21FreeAllocationsGlobalEv(void);
extern "C" int func_020aad1c(void*, void*, int, int);
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv(void);
extern "C" void _Z20StopAndReset0209c7fcPv(void*);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" int _ZN16BackgroundLoader17GetNumQueuedTasksEv(void);
extern "C" void* _ZN9GameState20GetUnknownGameObjectEv(void);
extern "C" void func_02046380(void*);
extern "C" void _Z22SetIndexedName02046574P11Obj02046574iPc(void*, int, void*);
extern "C" void _Z20AppendString02042058PcPKc(void*, void*);
extern "C" void _Z18ClearFlags020466f4P16FlagWord020466f4j(void*, unsigned int);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(void*, int);
extern "C" void* memset(void*, int, unsigned int);

extern int data_02109bf4;
extern int data_0211e33c;

// USA: func_ov003_02159d0c
// JPN: func_ov003_0215b18c
extern "C" ARM void func_ov003_02159d0c(void* self) {
    unsigned char* s = (unsigned char*)self;
    unsigned char* g = (unsigned char*)_Z26GetGlobalField0x1c020421a0v();
    void* dp = _Z27GetDataPtr02114e04_020d6c00v();
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
            _Z25AppendFieldTwice_02159290Pvii(self, 0x3e8, 0x64);
            func_ov003_02159250(self, *(void**)(s + 0x7c));
            *(unsigned char*)(s + 0x5b3) = 5;
            *(unsigned char*)(s + 0x580) = 2;
            return;
        }
        _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 0, 1);
        _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 1, 1);
        _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 2, 1);
        int key = 0x3f2;
        if (_Z18CheckField0NonZeroPi(f) && func_0202c540(f)) {
            key += 8;
        }
        func_ov003_02159250(self, _Z21GetFieldByKey020e0434P17Container020e0310i(s + 0x64, key));
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state == 1) {
        if (*(int*)(g + kRegionValue9A0_870) != 3) return;
        int r = func_ov003_0215bf18(self, 0);
        if (r == -1) return;
        if (r == -2 || r == 1) {
            memset(*(void**)(s + 0x7c), 0, kRegionValue960_800);
            _Z25AppendFieldTwice_02159290Pvii(self, 0x3f4, 0x3f5);
            func_ov003_02159250(self, *(void**)(s + 0x7c));
            *(unsigned char*)(s + 0x580) = 4;
        } else if (r == 0) {
            *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
        }
        _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 0, 1);
        _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 1, 1);
        _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 2, 1);
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
        if (_Z28LookupAndForEachNode020649b0PviS_(func_0205ec34(), 0xc, buf)) {
            func_0206f81c(buf);
        }
        if (*(unsigned char*)(s + 0x5b4) == 0) {
            func_ov003_02159250(self, _Z21GetFieldByKey020e0434P17Container020e0310i(s + 0x64, 0x64));
        }
        _Z16OrBitsIntoField0Pjj(dp, 0x80);
        *(int*)(s + 0x598) = 0xf;
        if (_Z18CheckField0NonZeroPi(f)) {
            func_ov017_021d1118(-1, 1, 1, 2);
            func_ov017_021d1014(-1, 1, 0);
        }
        *(unsigned char*)(s + 0x580) = 0x64;
    }

    if (state == 0x64) {
        if (_Z18CheckField0NonZeroPi(f)) {
            signed char* p = (signed char*)_ZN9GameState11GetInstanceEv() + kRegionValue34C0_3280;
            p += 0x4000;
            for (int i = 0; i < 3; i++, p += 10) {
                if (p[6] >= 4) {
                    if (((unsigned char*)p)[7] != 0 || ((unsigned char*)p)[8] != 0) return;
                    if (p[9] >= 0) return;
                }
            }
        }
        _Z27SetValueAndActivate0209c830P14Struct0209c830t(&data_02109bf4, 0x3c);
        *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) | 2;
        *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
    }

    if (state == 0x65) {
        if (*(int*)(g + kRegionValue9A0_870) != 3) return;
        if (_Z23CountEntriesType1WithIdi(0x3c) == 0) return;
        if (*(int*)(g + kRegionValue9A0_870) == 3) {
            *(unsigned char*)(g + 0x1000 + kRegionValue9AE_7DE) = 0;
        }
        if (*(unsigned char*)(s + 0x59c) == 0) {
            *(unsigned char*)(s + 0x59c) = 1;
        }
        _Z19ClearStruct020a9ea4P14Struct020a9ea4(s + 0x1b8 + 0x400);
        *(unsigned char*)(s + 0x580) = 0x66;
    }

    if (state == 0x66) {
        int flags = 1;
        if (func_0202c540(f)) flags |= 0x14;
        _ZN16BackgroundLoader13AddLockGlobalEv();
        _ZN16BackgroundLoader21FreeAllocationsGlobalEv();
        if (func_020aad1c(s + 0x1b8 + 0x400, &data_0211e33c, flags, 0) == 1) {
            *(unsigned char*)(s + 0x580) = 3;
        }
        _ZN16BackgroundLoader16RemoveLockGlobalEv();
    }

    if (state == 3) {
        if (*(int*)(g + kRegionValue9A0_870) == 3) {
            *(unsigned char*)(g + 0x1000 + kRegionValue9AE_7DE) = 0;
        }
        _Z20StopAndReset0209c7fcPv(&data_02109bf4);
        _ZN16BackgroundLoader11GetInstanceEv();
        if (_ZN16BackgroundLoader17GetNumQueuedTasksEv() > 0) return;
        *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) & ~2;
        memset(*(void**)(s + 0x7c), 0, kRegionValue960_800);
        if (*(unsigned char*)(s + 0x5b4) != 0) {
            _ZN9GameState11GetInstanceEv();
            unsigned char* obj = (unsigned char*)_ZN9GameState20GetUnknownGameObjectEv();
            func_02046380(g);
            _Z22SetIndexedName02046574P11Obj02046574iPc(g, 0, *(void**)(obj + 0x134));
            _Z20AppendString02042058PcPKc(*(void**)(s + 0x7c),
                _Z21GetFieldByKey020e0434P17Container020e0310i(s + 0x64, 0x3f3));
        } else {
            _Z25AppendFieldTwice_02159290Pvii(self, 0x3f3, 0x3f5);
        }
        func_ov003_02159250(self, *(void**)(s + 0x7c));
        _Z18ClearFlags020466f4P16FlagWord020466f4j(dp, 0x80);
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
                _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 0, 1);
                _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 1, 1);
                _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 2, 1);
                func_ov003_02159250(self, _Z21GetFieldByKey020e0434P17Container020e0310i(s + 0x64, 0x3f7));
                *(unsigned char*)(s + 0x580) = *(unsigned char*)(s + 0x580) + 1;
                return;
            }
            if (_Z18CheckField0NonZeroPi(f)) {
                _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 0, 1);
                _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 1, 1);
                _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 2, 1);
                func_ov003_02159250(self, _Z21GetFieldByKey020e0434P17Container020e0310i(s + 0x64, 0x3f9));
                *(unsigned char*)(s + 0x580) = 6;
                return;
            }
            _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(s + 0xf4, 1);
            func_ov003_02159250(self, _Z21GetFieldByKey020e0434P17Container020e0310i(s + 0x64, 0x3f6));
            *(unsigned char*)(s + 0x59f) = *(unsigned char*)(s + 0x59f) | 0x10;
            *(unsigned char*)(s + 0x588) = 9;
            *(unsigned char*)(s + 0x580) = 0;
            return;
        } else if (r == 0) {
            _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(s + 0xf4, 1);
            func_ov003_02159250(self, _Z21GetFieldByKey020e0434P17Container020e0310i(s + 0x64, 0x442));
            *(unsigned char*)(s + 0x580) = 7;
        }
    }

    if (state == 5) {
        if (*(int*)(g + kRegionValue9A0_870) != 3) return;
        int r = func_ov003_0215bf18(self, 1);
        if (r == -1) return;
        if (r == -2 || r == 1) {
            _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 0, 1);
            _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 1, 1);
            _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 2, 1);
            func_ov003_02159250(self, _Z21GetFieldByKey020e0434P17Container020e0310i(s + 0x64, 0x3f8));
            *(unsigned char*)(s + 0x580) = 1;
            return;
        } else if (r == 0) {
            if (_Z18CheckField0NonZeroPi(f)) {
                _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 0, 1);
                _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 1, 1);
                _Z17SetElementFieldC2P15Struct_0205d81cii(s + 0xf4, 2, 1);
                func_ov003_02159250(self, _Z21GetFieldByKey020e0434P17Container020e0310i(s + 0x64, 0x3f9));
                *(unsigned char*)(s + 0x580) = 6;
                return;
            }
            _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(s + 0xf4, 1);
            func_ov003_02159250(self, _Z21GetFieldByKey020e0434P17Container020e0310i(s + 0x64, 0x3f6));
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
            _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(s + 0xf4, 1);
            func_ov003_02159250(self, _Z21GetFieldByKey020e0434P17Container020e0310i(s + 0x64, 0x442));
            *(unsigned char*)(s + 0x580) = 7;
            return;
        } else if (r == 0) {
            _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(s + 0xf4, 1);
            func_ov003_02159250(self, _Z21GetFieldByKey020e0434P17Container020e0310i(s + 0x64, 0x3f6));
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
