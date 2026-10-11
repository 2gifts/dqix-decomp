#if defined(jpn)
#define R(j,u) (j)
#define _Z24IssueBattleCommandSlot25ii func_020d84e0
#define data_ov001_02164ca4 data_ov001_02166270
#define data_ov028_021d9aa0 data_ov028_021da400
#define func_ov014_02188330 func_ov014_02189234
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_02191f04 func_ov015_02192a48
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "System/Cache.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void* _Z17GetGlobal02109400v();
extern "C" void* _Z10GetWord0x0Pi(void* battle);
extern "C" void func_02094ab0(void*);
extern "C" void _Z21BlankFunction02094b34v(void*, int, int, int, int);
extern "C" int _Z18AlwaysTrue02094b4cv(void*);
extern "C" void _Z16OrGlobalFlag0x40v();
extern "C" void func_02074af4(void*);
extern "C" unsigned int _Z7GetWordPj(unsigned int*);
extern "C" unsigned int _Z9GetField4Pj(unsigned int*);
extern "C" unsigned int _Z9GetField8Pj(unsigned int*);
void SetBitsInField4(unsigned int*, unsigned int);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void*, int, int);

struct FieldSet02097bc4;
void SetFieldGroupFromFlags02097bc4(struct FieldSet02097bc4*, int);
extern "C" void func_02097c18(void*, int, int, int, int, int, int, int);

extern "C" void _Z17ResetList0204af64P12List0204af64(void*);
extern "C" void _Z24SetWord0x18ClearByte0x1fPhi(void*, int);
extern "C" void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(void*, int, int);
extern "C" void _Z21DispatchByTag0204b2e0PvPc(void*, char*);
extern "C" void _Z27DispatchByTagLookup0204b3a0P15SelfTag0204b3a0Pc(void*, char*);

extern "C" void LoadToSubBGStandardPalette(int, int, unsigned int);
extern "C" void LoadToSubBG1ScreenData(int, int, unsigned int);
extern "C" void LoadToSubBG1CharacterData(int, int, unsigned int);

extern "C" void func_ov028_021d98e0(void*, void*, int, int);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(void*);

extern int data_ov028_021d9aa0;

// USA: func_ov028_021d8dd0  (semantic: AdvanceStateMachine_021d8dd0)  (semantic: AdvanceStateMachine_021d8dd0)
extern "C" ARM void func_ov028_021d8dd0(unsigned char* self) {
    void* g = _Z17GetGlobal02109400v();
    void* data = BackgroundLoader::GetInstance();
    void* battle = GameState::GetInstance();
    void* word = _Z10GetWord0x0Pi(battle);
    unsigned char state = self[0x81];

    if (state == 0) {
        func_02094ab0(g);
        _Z21BlankFunction02094b34v(g, 0x7a, 0x20b, 0, 0);
        self[0x81] = self[0x81] + 1;
    } else if (state == 1) {
        if (_Z18AlwaysTrue02094b4cv(g) != 0) {
            self[0x81] = self[0x81] + 1;
        }
    } else if (state == 2) {
        _Z16OrGlobalFlag0x40v();
        func_02074af4(self + 0xc);
        *(unsigned int*)(self + 0x74) = _Z7GetWordPj((unsigned int*)word);
        *(unsigned int*)(self + 0x78) = _Z9GetField4Pj((unsigned int*)word);
        *(unsigned int*)(self + 0x7c) = _Z9GetField8Pj((unsigned int*)word);
        SetBitsInField4((unsigned int*)word, 0x90);
        void* buf40 = *(void**)(self + 0x40);
        SetFieldGroupFromFlags02097bc4((struct FieldSet02097bc4*)(self + 0x20), 2);
        func_02097c18(self + 0x20, 2, 0, 0, 0, 0, 0x180, 0);

        unsigned short* reg400100a = (unsigned short*)0x400100a;
        *reg400100a = (*reg400100a & 0x43) | 0x1000;

        unsigned char list[0x20];
        _Z17ResetList0204af64P12List0204af64(list);
        unsigned char v = list[0x1c];
        v = (v & ~0xf) | 1;
        v = v & 0xff;
        v = (v & ~0xf0) | 0x10;
        list[0x1c] = v;
        _Z24SetWord0x18ClearByte0x1fPhi(list, 0);
        _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(list, 0, 0);
        int tag = *(int*)((char*)word + 0x2c);
        _Z21DispatchByTag0204b2e0PvPc(list, (char*)tag);
        _Z27DispatchByTagLookup0204b3a0P15SelfTag0204b3a0Pc(list, (char*)tag);

        unsigned short tmpVal = 0x67f5;
        memcpy(buf40, &tmpVal, 2);
        CleanInvalidateCacheRange(buf40, 2);
        LoadToSubBGStandardPalette((int)buf40, 0xa, 2);

        unsigned short* p = (unsigned short*)buf40;
        for (unsigned short i = 0; i < 0x400; i++) {
            p[i] = i;
        }

        CleanInvalidateCacheRange(buf40, 0x800);
        LoadToSubBG1ScreenData((int)buf40, 0, 0x800);
        memset(buf40, 0x11111111, 0x8000);
        CleanInvalidateCacheRange(buf40, 0x8000);
        LoadToSubBG1CharacterData((int)buf40, 0, 0x8000);
        void* buf2 = *(void**)(self + 0x40);
        memset(buf2, 0x11111111, 0x8000);
        buf2 = *(void**)(self + 0x40);
        CleanInvalidateCacheRange(buf2, 0x8000);

        unsigned short* r1008 = (unsigned short*)0x4001008;
        r1008[0] = (r1008[0] & ~3) | 1;
        r1008[1] = r1008[1] & ~3;
        r1008[2] = (r1008[2] & ~3) | 2;
        r1008[3] = (r1008[3] & ~3) | 3;
        unsigned int* reg0 = (unsigned int*)0x4000000;
        *reg0 = (*reg0 & ~0x1f00) | 0x1100;
        unsigned int* reg1 = (unsigned int*)0x4001000;
        *reg1 = (*reg1 & ~0x1f00) | 0x200;

        self[0x81] = self[0x81] + 1;
    } else if (state == 3) {
        int r = ((BackgroundLoader*)((int)data))->QueueLoadFile((const char*)((int)&data_ov028_021d9aa0), (SafeAllocator*)(0));
        *(int*)(self + 0x70) = r;
        self[0x81] = self[0x81] + 1;
    } else if (state == 4) {
        if (((BackgroundLoader*)(data))->GetTaskStatus((int)(*(int*)(self + 0x70))) != 0) {
            int a, b;
            ((BackgroundLoader*)(data))->GetLoadedFileByID((int)(*(int*)(self + 0x70)), (void**)(&a), (unsigned int*)(&b));
            if (a != 0 && b != 0) {
                ((SafeAllocator*)(self + 0x44))->Reset();
                func_ov028_021d98e0(self, self + 0x44, a, b);
            }
            ((BackgroundLoader*)(data))->RemoveTask((int)(*(int*)(self + 0x70)));
            *(int*)(self + 0x70) = -1;
            self[0x81] = self[0x81] + 1;
        }
    } else if (state == 5) {
        self[0x81] = state + 1;
        _Z13SetBrightnessP13GameResourcesii(word, 0, 0x1e);
    } else if (state == 6) {
        if (_Z28IsBrightnessTransitionActiveP13GameResources(word) == 0) {
            self[0x80] = 1;
            self[0x81] = 0;
        }
    }
}
