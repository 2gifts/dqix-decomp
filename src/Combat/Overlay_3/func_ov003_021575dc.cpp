#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
struct BattleStruct {
    int unk0;
    int unk4;
    struct CombatantStruct* combatantList[0xe9];
};
struct CombatantStruct {
    unsigned short flags;
    char unk[0x132];
    struct BaseCombatStats* baseStats;
    struct ModifiableCombatStats* currentStats;
};
extern "C" void* _Z17GetPtrField0x2a04P9GameState(struct BattleStruct* battleStruct);
extern "C" struct CombatantStruct* _Z25GetCombatantWithFlag0x100P9GameStatei(struct BattleStruct* battleStruct, int combatantId);
extern "C" struct BattleStruct* _ZN9GameState11GetInstanceEv();

// mangled (_Z...) callees -- declared under their literal mangled symbol via
// extern "C" so the linker resolves the exact ROM symbol without needing the
// callee's real (unknown) struct types. See doc_cache "EXTERN C AND MANGLING".
extern "C" int _Z26FindMappedMemberId02080468Pvi(void* obj, int id);
extern "C" void _Z20ResetWithSub0208203cP11Obj0208203c(void* obj);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(void* obj, int a, int b);
extern "C" void _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(void* obj);
extern "C" int _Z26IsTableValueNot99_02155ffcPvi(void* obj, int id);
extern "C" int _Z39IsCombatantFlagit2Set_02155f88_02155f88Pvi(void* obj, int id);
extern "C" void _Z20ResetFields_0215873cPv(void* obj);
extern "C" void _Z25SetFlag_02158a50_02158a50Ph(void* obj);
extern "C" void _Z27SetValueAndActivate0209c830P14Struct0209c830t(void* obj, unsigned short val);
extern "C" int _Z25IsAnimationActive0209ca2cPv(void* obj);
extern "C" int _ZNK8Object3D19HasAnimationStoppedEv(void* obj);
extern "C" void _Z20SetOrClearBitInArrayPvPhii(void* a, unsigned char* b, int c, int d);
extern "C" void* _Z22ZeroInitReturn020de824Pv(void* obj);
extern "C" void _Z18InitStruct0207cbe8Pc(char* obj);
extern "C" void _Z18InitStruct0207cc0cPc(char* obj);
extern "C" int _Z27TestBattleBlockBit_021ed6cci(int tag);
extern "C" void _Z19ClearStruct020a13c4P9S020a13c4(void* obj);
extern "C" void _Z31SetupGlobalAndRunScript020a13e4PvS_ith(void* p0, void* p1, int p2, unsigned short p3, unsigned char p4);
extern "C" void _Z19ResetBitfieldRecordP22BitfieldRecord020a1380(void* obj);
extern "C" void _Z20InitBuffers_021580a0P14Struct021580a0(void* obj);
extern "C" void* _Z26FindElementByField020a15bcP13Array020a15bci(void* arr, int id);
extern "C" void _Z30AppendFormattedNumber_02158140P11Obj02158140i(void* obj, int val);
extern "C" void _Z21BlankFunction02094b34v(void* p0, int p1, int p2, int p3, int p4);

// plain-C++ callees with already-known real signatures (project headers /
// sibling files already declare these with matching types).
extern "C" struct CombatantStruct* _ZN9GameState21GetPartyMemberByIndexEi(struct BattleStruct* battleStruct, int combatantId);
extern "C" int _Z18GetField0x3acValueP9GameState(struct BattleStruct* battleStruct);
int TestBitInByteArray(int, unsigned char*, int);
void ZeroInit020de848(void* obj);
ARM int BuildDescriptorFlag1_020de980(void* a, void* b, void* c, int d, int e);
int GetGlobalField0x1c020421a0(void);
void ReinitController02043204(char* obj);
int GetGlobal02109400(void);
void BlankFunction02094b40(void);
int AlwaysTrue02094b4c(void);
void SetCombatModeFromCase020dc2d0(int);
extern "C" ARM int _Z28IsBrightnessTransitionActiveP13GameResources(int* obj);
ARM void* Clear0x54Bytes0208247c(void* obj);

// func_ names -- raw hex symbols, extern "C" with our own convenient types.
extern "C" void __clear(void* buf, int len);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
extern "C" ARM int func_020813ec(void* obj, int id);
extern "C" void func_0207d300(void* obj, int a, int b, int c);
extern "C" void* func_0205ec34(void);
extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_020e046c(void* a, void* b, int c, int d);
extern "C" void func_02082490(void* a, void* b, int c, int d, int e);
extern "C" void func_ov003_02158334(void* self);
extern "C" int func_ov003_021550dc(void* self);
extern "C" int func_ov003_02155208(void* self);
extern "C" int func_ov003_02155fc0(void* self, int id);
extern "C" void func_ov003_02155580(void* self, int a);
extern "C" int func_ov003_02155618(void* self);
extern "C" void func_ov003_02155e38(void* self);
extern "C" void func_ov003_021580d8(void* dst, void* src);
extern "C" int func_ov003_02158754(void* self);
extern "C" int func_ov023_021ed724(void* a, void* b, int c);
extern "C" void func_ov023_021eb138(void* a, int b);
extern "C" void func_ov023_021eb080(void* a, void* b);
extern "C" void func_ov023_021eb564(void* a, void* b, int c);
extern "C" void func_ov023_021eb43c(void* a);
extern "C" void func_ov023_021eb26c(void* a);

extern char data_02108760;
extern char data_ov003_0217fdbb;
extern const char* data_020f2a38;
extern const char* data_020f2a30;
extern short data_ov003_0217f2e8[];
extern char data_02109bf4;
extern short data_ov003_0217f2ce[];
extern char data_ov003_0217fdd0;
extern char data_ov003_0217fde7;

struct Bit0x49c { unsigned char bit0 : 1; };

// USA: func_ov003_021575dc
extern "C" ARM void func_ov003_021575dc(void* self) {
    char* s = (char*)self;
    struct BattleStruct* bs = _ZN9GameState11GetInstanceEv();
    void* p2a04 = _Z17GetPtrField0x2a04P9GameState(bs);
    unsigned char state = *(unsigned char*)(s + 0x1f9);
    void* root;
    short* evt = (short*)(s + 0x1ec);
    void* obj18 = *(void**)(s + 0x18);

    if (state == 0) {
        *(short*)(s + 0x1e6) = 3;
        unsigned char v = *(unsigned char*)((char*)p2a04 + 0xf7c);
        switch (v) {
        case 3: *(short*)(s + 0x1e6) = 4; break;
        case 4: *(short*)(s + 0x1e6) = 5; break;
        }
        if (*(short*)(s + 0x1e2) < 0) {
            short id = (short)_Z26FindMappedMemberId02080468Pvi(obj18, *(short*)(s + 0x1e6));
            *(short*)(s + 0x1e2) = id;
            *(short*)(s + 0x1e8) = *(short*)(s + 0x1e2);
        }
        *(short*)((char*)obj18 + 0x36) = *(short*)(s + 0x1e2);
        func_ov003_02158334(self);
        _Z20ResetWithSub0208203cP11Obj0208203c(s + 0x80);
        *(int*)(s + 8) = 0;
        *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
    } else if (state == 1) {
        *(void**)(s + 8) = (void*)(s + 0x1e2);
        if (func_ov003_021550dc(self) != 0) {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
            _Z20ResetWithSub0208203cP11Obj0208203c(s + 0x80);
            *(void**)(s + 8) = 0;
            int mm = _Z26FindMappedMemberId02080468Pvi(obj18, *(short*)(s + 0x1e6));
            short diff = *(short*)(s + 0x1e2) - mm;
            unsigned char v = *(unsigned char*)(s + 0x1f2 + diff);
            *(unsigned char*)(s + 0x1f7) = v;
            *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
            _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(obj18);
        } else if (func_ov003_02155208(self) != 0) {
            *(void**)(s + 8) = 0;
            evt[0] = 7;
            *(unsigned char*)(s + 0x1f8) = 7;
            _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(obj18);
        }
    } else if (state == 2) {
        signed char idx = *(signed char*)(s + 0x1f7);
        if (_Z26IsTableValueNot99_02155ffcPvi(self, idx) != 0) {
            evt[0] = 0x10;
            *(unsigned char*)(s + 0x1f8) = 7;
            return;
        }
        evt[0] = 0x11;
        idx = *(signed char*)(s + 0x1f7);
        if (func_ov003_02155fc0(self, idx) != 0) {
            evt[1] = 0x41;
            *(unsigned char*)(s + 0x1f8) = 7;
            _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(obj18);
            return;
        }
        idx = *(signed char*)(s + 0x1f7);
        if (_Z39IsCombatantFlagit2Set_02155f88_02155f88Pvi(self, idx) != 0) {
            evt[1] = 0x12;
            *(unsigned char*)(s + 0x1f8) = 7;
            _Z28CallFunc0204c804OverAllElemsP12Cont0207fe44(obj18);
            return;
        }
        evt[1] = 0x13;
        *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
    } else if (state == 3) {
        func_ov003_02155580(self, 1);
        *(short*)(s + 0x1e8) = *(short*)(s + 0x1ea) = 7;
        *(short*)((char*)*(void**)(s + 0x18) + 0x36) = *(short*)(s + 0x1ea);
        func_020813ec(*(void**)(s + 0x18), *(short*)(s + 0x1e6));
        *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
    } else if (state == 4) {
        int r = func_ov003_02155618(self);
        if (r == -1) goto state4_neg1;
        if (r != 1) goto state4_done;
        evt[0] = 0x15;
        *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
        goto state4_done;
    state4_neg1:
        evt[0] = 0x14;
        *(unsigned char*)(s + 0x1f8) = 7;
    state4_done:;
    } else if (state == 5) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        signed char idx = *(signed char*)(s + 0x1f7);
        int val = 0;
        struct CombatantStruct* comb = _ZN9GameState21GetPartyMemberByIndexEi(bs, idx);
        if (comb != 0) {
            void* p150 = *(void**)((char*)comb + 0x150);
            val = *(int*)((char*)p150 + 0x950);
        }
        char buf[0x18];
        __clear(buf, 0x18);
        sprintf(buf, &data_ov003_0217fdbb, val);
        *(int*)(s + 0x1d0) = loader->QueueLoadFile(buf, (SafeAllocator*)0);
        *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
    } else if (state == 6) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(*(int*)(s + 0x1d0)) != 0) {
            void* outPtr; unsigned int outLen;
            loader->GetLoadedFileByID(*(int*)(s + 0x1d0), &outPtr, &outLen);
            Clear0x54Bytes0208247c(s + 0x90);
            if (outPtr != 0) {
                func_02082490(s + 0x90, outPtr, outLen, 1, 0);
            }
            loader->RemoveTask(*(int*)(s + 0x1d0));
            *(int*)(s + 0x1d0) = -1;
            *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
        }
    } else if (state == 7) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        *(int*)(s + 0x1d0) = loader->QueueLoadFileInGP2(data_020f2a38, data_020f2a30, (SafeAllocator*)0);
        *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
    } else if (state == 8) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(*(int*)(s + 0x1d0)) != 0) {
            void* outPtr; unsigned int outLen;
            loader->GetLoadedFileByID(*(int*)(s + 0x1d0), &outPtr, &outLen);
            ((SafeAllocator*)(*(char**)s + 0x78))->Reset();
            *(short*)(s + 0x1f0) = -1;
            signed char idx = *(signed char*)(s + 0x1f7);
            struct CombatantStruct* comb = _ZN9GameState21GetPartyMemberByIndexEi(bs, idx);
            if (comb != 0) {
                void* p150 = *(void**)((char*)comb + 0x150);
                int field950 = *(int*)((char*)p150 + 0x950);
                *(short*)(s + 0x1f0) = data_ov003_0217f2e8[field950];
            }
            loader->RemoveTask(*(int*)(s + 0x1d0));
            *(int*)(s + 0x1d0) = -1;
            short f0val = *(short*)(s + 0x1f0);
            ZeroInit020de848(s + 0x178);
            BuildDescriptorFlag1_020de980(s + 0x178, *(char**)s + 0x78, outPtr, outLen, f0val);
            *(unsigned char*)(s + 0x338) = 1;
            _Z20ResetFields_0215873cPv(self);
            *(unsigned char*)(s + 0x1f9) = 0x32;
        }
    } else if (state == 9) {
        ReinitController02043204((char*)GetGlobalField0x1c020421a0());
        _Z25SetFlag_02158a50_02158a50Ph(self);
        _Z27SetValueAndActivate0209c830P14Struct0209c830t(&data_02109bf4, 0x34);
        *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
    } else if (state == 0xa) {
        if (_Z25IsAnimationActive0209ca2cPv(&data_02109bf4) != 0) {
            goto tail;
        }
        if (_ZNK8Object3D19HasAnimationStoppedEv(s + 0x280) == 0) {
            goto tail;
        }
        *(int*)(s + 0x32c) = 0;
        func_ov003_02155e38(self);
        signed char idx = *(signed char*)(s + 0x1f7);
        struct CombatantStruct* comb = _ZN9GameState21GetPartyMemberByIndexEi(bs, idx);
        int field950 = -1;
        if (comb != 0) {
            void* p150 = *(void**)((char*)comb + 0x150);
            field950 = *(int*)((char*)p150 + 0x950);
        }
        if (field950 > 0) {
            void* base = func_0205ec34();
            if (TestBitInByteArray((int)base, (unsigned char*)base + 0x8c, field950 + 0x8b + 0x1100) == 0) {
                _Z20SetOrClearBitInArrayPvPhii(base, (unsigned char*)base + 0x8c, field950 + 0x8b + 0x1100, 1);
                evt[0] = 0x16;
                evt[1] = 0x17;
                *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;

                char bufFc[0x38];
                ((SafeAllocator*)bufFc)->ResetAllocatorPointer();
                _Z22ZeroInitReturn020de824Pv(bufFc + 0x14);
                _Z18InitStruct0207cbe8Pc(bufFc);
                _Z18InitStruct0207cbe8Pc(bufFc);
                *(void**)(bufFc + 0x2c) = s + 0x178;
                func_0207d300(bufFc, *(short*)(s + 0x1f0), 1, 0);
                _Z18InitStruct0207cc0cPc(bufFc);
                return;
            }
        }
        *(unsigned char*)(s + 0x1f9) = 0x64;
    } else if (state == 0xb) {
        evt[0] = 0x18;
        evt[1] = 0x19;
        *(unsigned char*)(s + 0x1f8) = 7;
    } else if (state == 0x64) {
        short tagBuffer[12];
        __clear(tagBuffer, 0x18);
        unsigned short sbCount = 0;
        int fieldVal = _Z18GetField0x3acValueP9GameState(bs);
        struct CombatantStruct* combatant = _Z25GetCombatantWithFlag0x100P9GameStatei(bs, fieldVal);
        for (int i = 1; i < 13; i++) {
            void* p150 = *(void**)((char*)combatant + 0x150);
            if (*(unsigned char*)((char*)p150 + (unsigned char)i + 0x186) >= 0xa) {
                short tag = data_ov003_0217f2ce[i];
                if (_Z27TestBattleBlockBit_021ed6cci(tag) == 0) {
                    tagBuffer[sbCount] = tag;
                    sbCount++;
                }
            }
        }
        if (sbCount == 0) goto emptyResult0x64;
        {
            root = *(void**)s;
            ((SafeAllocator*)((char*)root + 0x64))->Reset();
            char scratch[0x14];
            _Z19ClearStruct020a13c4P9S020a13c4(scratch);
            _Z31SetupGlobalAndRunScript020a13e4PvS_ith(scratch, (char*)root + 0x64, (int)tagBuffer, sbCount, 8);

            char arr[12 * 0x244];
            char* p = arr;
            do {
                _Z19ResetBitfieldRecordP22BitfieldRecord020a1380(p);
                _Z20InitBuffers_021580a0P14Struct021580a0(p);
                p += 0x244;
            } while (p < arr + sizeof(arr));

            short outBuf[12];
            __clear(outBuf, 0x18);
            int outCount = 0;
            for (int j = 0; j < sbCount; j++) {
                short tag = tagBuffer[j];
                void* found = _Z26FindElementByField020a15bcP13Array020a15bci(scratch, tag);
                if (found != 0) {
                    _Z20InitBuffers_021580a0P14Struct021580a0(arr + outCount * 0x244);
                    func_ov003_021580d8(arr + outCount * 0x244, found);
                    char buf80[0x38];
                    __clear(buf80, 0x38);
                    BackgroundLoader::AddLockGlobal();
                    unsigned int outLen = 0;
                    char buf40[0x40];
                    __clear(buf40, 0x40);
                    char buf20[0x20];
                    __clear(buf20, 0x20);
                    int bit1 = ((struct Bit0x49c*)((char*)*(void**)((char*)combatant + 0x150) + 0x49c))->bit0;
                    sprintf(buf40, &data_ov003_0217fdd0, bit1);
                    int bit2 = ((struct Bit0x49c*)((char*)*(void**)((char*)combatant + 0x150) + 0x49c))->bit0;
                    sprintf(buf20, &data_ov003_0217fde7, bit2);
                    void* extractResult = ExtractFileFromGP2(buf40, buf20, &outLen);
                    if (extractResult != 0) {
                        func_020e046c(buf80, extractResult, outLen, tagBuffer[j]);
                    }
                    BackgroundLoader::RemoveLockGlobal();
                    _Z30AppendFormattedNumber_02158140P11Obj02158140i(arr + outCount * 0x244, (int)buf80);
                    outBuf[outCount] = tagBuffer[j];
                    outCount++;
                }
            }
            if (outCount <= 0) goto emptyResult0x64;
            {
                int flags = func_ov023_021ed724(scratch, outBuf, outCount);
                ((SafeAllocator*)((char*)root + 0x64))->Reset();
                *(void**)(s + 0x200) = ((SafeAllocator*)((char*)root + 0x64))->Allocate(outCount * 0x244);
                for (int k = 0; k < outCount; k++) {
                    char* src = arr + k * 0x244;
                    char* elem = (char*)*(void**)(s + 0x200) + k * 0x244;
                    _Z20InitBuffers_021580a0P14Struct021580a0(elem);
                    func_ov003_021580d8(elem, src);
                    _Z30AppendFormattedNumber_02158140P11Obj02158140i(elem, (int)(src + 0xc));
                }
                void* buf204 = ((SafeAllocator*)((char*)root + 0x64))->Allocate(1100);
                *(void**)(s + 0x204) = buf204;
                func_ov023_021eb138(buf204, 6);
                func_ov023_021eb080(*(void**)(s + 0x204), (char*)root + 0x64);
                func_ov023_021eb564(*(void**)(s + 0x204), *(void**)(s + 0x200), sbCount);
                char* menu = *(char**)(s + 0x204);
                if (flags & 1) {
                    *(unsigned short*)(menu + 0x438) |= 0x400;
                } else {
                    *(unsigned short*)(menu + 0x438) &= ~0x400;
                }
                char* base400 = (char*)*(void**)(s + 0x204);
                unsigned short* f38;
                base400 += 0x400;
                f38 = (unsigned short*)(base400 + 0x38);
                *f38 = *f38 | 0x10;
                *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
                return;
            }
        }
        goto stateEnd;
    emptyResult0x64:
        *(unsigned char*)(s + 0x338) = 0;
        evt[0] = 0x16;
        evt[1] = 0x19;
        *(unsigned char*)(s + 0x1f8) = 7;
    stateEnd:;
    } else if (state == 0x65) {
        if (*(void**)(s + 0x204) != 0) {
            func_ov023_021eb43c(*(void**)(s + 0x204));
            if (*(unsigned short*)((char*)*(void**)(s + 0x204) + 0x400 + 0x38) & 4) {
                func_ov023_021eb26c(*(void**)(s + 0x204));
                ((SafeAllocator*)(*(char**)s + 0x64))->Reset();
                *(void**)(s + 0x200) = 0;
                *(void**)(s + 0x204) = 0;
                *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
            }
        }
    } else if (state == 0x66) {
        int g = GetGlobal02109400();
        BlankFunction02094b40();
        _Z21BlankFunction02094b34v((void*)g, 0x66, 501, 0, 0);
        *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
    } else if (state == 0x67) {
        GetGlobal02109400();
        if (AlwaysTrue02094b4c() != 0) {
            SetCombatModeFromCase020dc2d0(0);
            *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
        }
    } else if (state == 0x68) {
        int r = func_ov017_0218b5b0();
        if (_Z28IsBrightnessTransitionActiveP13GameResources((int*)r) != 0) {
            return;
        }
        *(unsigned char*)(s + 0x338) = 0;
        evt[0] = 0x16;
        evt[1] = 0x19;
        *(unsigned char*)(s + 0x1f8) = 7;
    }

tail:
    if (*(unsigned char*)(s + 0x1f9) == 0x32) {
        if (func_ov003_02158754(self) != 0) {
            *(unsigned char*)(s + 0x1f9) = 9;
        }
    }
}
