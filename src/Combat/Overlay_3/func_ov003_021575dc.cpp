#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Combat/Main/BattleList.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "World/Object3D.h"
#include "GameState/GameState.h"
struct CombatantStruct {
    unsigned short flags;
    char unk[0x132];
    struct BaseCombatStats* baseStats;
    struct ModifiableCombatStats* currentStats;
};
void* GetPtrField0x2a04_02010828(GameState*);

int FindMappedMemberId02080468(void* obj, int id);
struct Obj0208203c;
void ResetWithSub0208203c(Obj0208203c*);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
struct Cont0207fe44;
void CallFunc0204c804OverAllElems(Cont0207fe44*);
int IsTableValueNot99_02155ffc(void* obj, int id);
int IsCombatantFlagit2Set_02155f88_02155f88(void* obj, int id);
void ResetFields_0215873c(void* obj);
void SetFlag_02158a50_02158a50(unsigned char*);
struct Struct0209c830;
void SetValueAndActivate0209c830(Struct0209c830*, int);
int IsAnimationActive0209ca2c(void* obj);
void SetOrClearBitInArray_0206df6c(void* a, unsigned char* b, int c, int d);
void* ZeroInitReturn020de824(void* obj);
void InitStruct0207cbe8(char* obj);
void InitStruct0207cc0c(char* obj);
int TestBattleBlockBit_021ed6cc(int tag);
struct S020a13c4;
void ClearStruct020a13c4(S020a13c4*);
void SetupGlobalAndRunScript020a13e4(void* p0, void* p1, int p2, unsigned short p3, unsigned char p4);
struct BitfieldRecord020a1380;
void ResetBitfieldRecord(BitfieldRecord020a1380*);
struct Struct021580a0;
void InitBuffers_021580a0(Struct021580a0*);
struct Array020a15bc;
void* FindElementByField020a15bc(Array020a15bc*, int);
struct Obj02158140;
void AppendFormattedNumber_02158140(Obj02158140*, int);

int GetField0x3acValue_020100a8(GameState*);
int TestBitInByteArray_0206dfb0(int, unsigned char*, int);
void ZeroInit020de848(void* obj);
ARM int BuildDescriptorFlag1_020de980(void* a, void* b, void* c, int d, int e);
int GetGlobalField0x1c020421a0(void);
void ReinitController02043204(char* obj);
void SetCombatModeFromCase020dc2d0(int);
struct GameResources;
ARM int IsBrightnessTransitionActive(GameResources*);
ARM void* Clear0x54Bytes0208247c(void* obj);

extern "C" void __clear(void* buf, int len);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
extern "C" ARM int func_020813ec(void* obj, int id);
extern "C" void func_0207d300(void* obj, int a, int b, int c);
extern "C" void* func_0205ec34(void);
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
    GameState* bs = GameState::GetInstance();
    void* p2a04 = GetPtrField0x2a04_02010828(bs);
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
            short id = (short)FindMappedMemberId02080468(obj18, *(short*)(s + 0x1e6));
            *(short*)(s + 0x1e2) = id;
            *(short*)(s + 0x1e8) = *(short*)(s + 0x1e2);
        }
        *(short*)((char*)obj18 + 0x36) = *(short*)(s + 0x1e2);
        func_ov003_02158334(self);
        ResetWithSub0208203c((Obj0208203c*)(s + 0x80));
        *(int*)(s + 8) = 0;
        *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
    } else if (state == 1) {
        *(void**)(s + 8) = (void*)(s + 0x1e2);
        if (func_ov003_021550dc(self) != 0) {
            DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 1, 0);
            ResetWithSub0208203c((Obj0208203c*)(s + 0x80));
            *(void**)(s + 8) = 0;
            int mm = FindMappedMemberId02080468(obj18, *(short*)(s + 0x1e6));
            short diff = *(short*)(s + 0x1e2) - mm;
            unsigned char v = *(unsigned char*)(s + 0x1f2 + diff);
            *(unsigned char*)(s + 0x1f7) = v;
            *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
            CallFunc0204c804OverAllElems((Cont0207fe44*)obj18);
        } else if (func_ov003_02155208(self) != 0) {
            *(void**)(s + 8) = 0;
            evt[0] = 7;
            *(unsigned char*)(s + 0x1f8) = 7;
            CallFunc0204c804OverAllElems((Cont0207fe44*)obj18);
        }
    } else if (state == 2) {
        signed char idx = *(signed char*)(s + 0x1f7);
        if (IsTableValueNot99_02155ffc(self, idx) != 0) {
            evt[0] = 0x10;
            *(unsigned char*)(s + 0x1f8) = 7;
            return;
        }
        evt[0] = 0x11;
        idx = *(signed char*)(s + 0x1f7);
        if (func_ov003_02155fc0(self, idx) != 0) {
            evt[1] = 0x41;
            *(unsigned char*)(s + 0x1f8) = 7;
            CallFunc0204c804OverAllElems((Cont0207fe44*)obj18);
            return;
        }
        idx = *(signed char*)(s + 0x1f7);
        if (IsCombatantFlagit2Set_02155f88_02155f88(self, idx) != 0) {
            evt[1] = 0x12;
            *(unsigned char*)(s + 0x1f8) = 7;
            CallFunc0204c804OverAllElems((Cont0207fe44*)obj18);
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
        GameObject* comb = bs->GetPartyMemberByIndex(idx);
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
            GameObject* comb = bs->GetPartyMemberByIndex(idx);
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
            ResetFields_0215873c(self);
            *(unsigned char*)(s + 0x1f9) = 0x32;
        }
    } else if (state == 9) {
        ReinitController02043204((char*)GetGlobalField0x1c020421a0());
        SetFlag_02158a50_02158a50((unsigned char*)self);
        SetValueAndActivate0209c830((Struct0209c830*)&data_02109bf4, 0x34);
        *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
    } else if (state == 0xa) {
        if (IsAnimationActive0209ca2c(&data_02109bf4) != 0) {
            goto tail;
        }
        if (((Object3D*)(s + 0x280))->HasAnimationStopped() == 0) {
            goto tail;
        }
        *(int*)(s + 0x32c) = 0;
        func_ov003_02155e38(self);
        signed char idx = *(signed char*)(s + 0x1f7);
        GameObject* comb = bs->GetPartyMemberByIndex(idx);
        int field950 = -1;
        if (comb != 0) {
            void* p150 = *(void**)((char*)comb + 0x150);
            field950 = *(int*)((char*)p150 + 0x950);
        }
        if (field950 > 0) {
            void* base = func_0205ec34();
            if (TestBitInByteArray_0206dfb0((int)base, (unsigned char*)base + 0x8c, field950 + 0x8b + 0x1100) == 0) {
                SetOrClearBitInArray_0206df6c(base, (unsigned char*)base + 0x8c, field950 + 0x8b + 0x1100, 1);
                evt[0] = 0x16;
                evt[1] = 0x17;
                *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;

                char bufFc[0x38];
                ((SafeAllocator*)bufFc)->ResetAllocatorPointer();
                ZeroInitReturn020de824(bufFc + 0x14);
                InitStruct0207cbe8(bufFc);
                InitStruct0207cbe8(bufFc);
                *(void**)(bufFc + 0x2c) = s + 0x178;
                func_0207d300(bufFc, *(short*)(s + 0x1f0), 1, 0);
                InitStruct0207cc0c(bufFc);
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
        int fieldVal = GetField0x3acValue_020100a8(bs);
        struct CombatantStruct* combatant = (CombatantStruct*)GetCombatantWithFlag0x100_0200ff1c(bs, fieldVal);
        for (int i = 1; i < 13; i++) {
            void* p150 = *(void**)((char*)combatant + 0x150);
            if (*(unsigned char*)((char*)p150 + (unsigned char)i + 0x186) >= 0xa) {
                short tag = data_ov003_0217f2ce[i];
                if (TestBattleBlockBit_021ed6cc(tag) == 0) {
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
            ClearStruct020a13c4((S020a13c4*)scratch);
            SetupGlobalAndRunScript020a13e4(scratch, (char*)root + 0x64, (int)tagBuffer, sbCount, 8);

            char arr[12 * 0x244];
            char* p = arr;
            do {
                ResetBitfieldRecord((BitfieldRecord020a1380*)p);
                InitBuffers_021580a0((Struct021580a0*)p);
                p += 0x244;
            } while (p < arr + sizeof(arr));

            short outBuf[12];
            __clear(outBuf, 0x18);
            int outCount = 0;
            for (int j = 0; j < sbCount; j++) {
                short tag = tagBuffer[j];
                void* found = FindElementByField020a15bc((Array020a15bc*)scratch, tag);
                if (found != 0) {
                    InitBuffers_021580a0((Struct021580a0*)(arr + outCount * 0x244));
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
                    AppendFormattedNumber_02158140((Obj02158140*)(arr + outCount * 0x244), (int)buf80);
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
                    InitBuffers_021580a0((Struct021580a0*)elem);
                    func_ov003_021580d8(elem, src);
                    AppendFormattedNumber_02158140((Obj02158140*)elem, (int)(src + 0xc));
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
            if (*(unsigned short*)(*(char**)(s + 0x204) + 0x438) & 4) {
                func_ov023_021eb26c(*(void**)(s + 0x204));
                ((SafeAllocator*)(*(char**)s + 0x64))->Reset();
                *(void**)(s + 0x200) = 0;
                *(void**)(s + 0x204) = 0;
                *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
            }
        }
    } else if (state == 0x66) {
        FontBankLoader* g = GetGlobal02109400_02094a00();
        BlankFunction02094b40(g);
        BlankFunction02094b34(g, 0x66, 501, 0, 0);
        *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
    } else if (state == 0x67) {
        if (AlwaysTrue02094b4c(GetGlobal02109400_02094a00()) != 0) {
            SetCombatModeFromCase020dc2d0(0);
            *(unsigned char*)(s + 0x1f9) = *(unsigned char*)(s + 0x1f9) + 1;
        }
    } else if (state == 0x68) {
        GameResources* r = func_ov017_0218b5b0();
        if (IsBrightnessTransitionActive(r) != 0) {
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
