#include <globaldefs.h>
#include "World/Zone3D.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"
#include "System/Graphics.h"
#include "World/Object3D.h"
#include "std_library_functions.h"

struct Struct02033b88;
struct EntryList_203dce4;
struct Container0204039c;
struct SlotArray0203dd10;

struct Scene02155dd0 {
    char pad0[0xa];
    unsigned short fieldA;
};

extern "C" GameResources* func_ov017_0218b5b0();
char* GetFieldIfFlag4(char* obj);
void* GetFieldPtrAt0x5ca4(void* obj);
extern "C" void* func_02012fe4();
char* GetGlobalField0x1c020421a0();
void* GetGlobalPtr021075f4(void);
void* EmptyStub0203d004(void* p);
void* GetEntryUnlessFlag0x8000(EntryList_203dce4*, int);
int* GetField0x8(int* p);
struct Container02040404;
int FindEntryIndexByName02040404(Container02040404*, char const*);
void ReleaseOrDecrementSlot0204039c(Container0204039c* c, int idx);
void Reset02040504(int* p);
void SetSlotIfIndexBelow32(SlotArray0203dd10*, unsigned int, int);
void ReinitController02043204(char* obj);
extern "C" void func_02043124(char* obj);
void ClearBitsInField4(unsigned int* p, unsigned int bits);
int IsScaledFieldPositive0203adfc(void* a, void* b);
void ScaleAndNotify0203ad88(void* a, void* b, int c);
void SetField0x7cClearFields0x1ec0x1ee(unsigned char*, unsigned short);
void SetFields0x1f0And0x1f4(void* obj, int a, int b);
extern "C" void* func_020704fc();
struct EffectParam020708c8;
void SetScaledEffectParam020708c8(EffectParam020708c8*, unsigned int);
int GetBitsInField0(unsigned int* p, unsigned int bits);
void ResetAndReinit0209c278(void* obj);
void Dispatch0203a974With0x57000(void* obj);
void SetupContextForMode0205ea20(void* obj, int mode);
void ClearBitsInWord(unsigned int*, unsigned int);
extern "C" void func_ov028_021d9714();
void PopStack1AndTrigger(int v);
extern "C" void* func_0205ec34();
int TestBitInByteArray(int p, unsigned char* arr, int bit);
struct Bytes02033b88;
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
void ClearCombatantSlot(GameState* gs, int id);
void SetField0x3b0Value(GameState* gs, int val);

extern char data_ov001_02164c4a[];
extern char data_02108760[];
extern char data_02109bf4[];

#define REG_DISPSTAT_304 (*(volatile unsigned short*)0x04000304)

// USA: func_ov001_02155dd0
extern "C" ARM unsigned short func_ov001_02155dd0(Scene02155dd0* self) {
    GameResources* res = func_ov017_0218b5b0();
    if (IsBrightnessTransitionActive(res)) {
        return self->fieldA;
    }

        BackgroundLoader* loader;
        char* globalA;
        GameObject* obj;
        int i;
        int* ptr6;
        GameResources* res2;
        Zone3D* area;
        int k;
        int j;
        char* hud;
        GameState* gs;

    gs = GameState::GetInstance();
    hud = GetFieldIfFlag4((char*)gs);
    res2 = func_ov017_0218b5b0();
    area = (Zone3D*)func_02012fe4();
    globalA = GetGlobalField0x1c020421a0();
    loader = BackgroundLoader::GetInstance();
    ptr6 = (int*)GetFieldPtrAt0x5ca4(gs);

    for (i = 0; i < 4; i++) {
        obj = gs->GetMaybeWanderingMonsterByIndex(i);
        if (obj != 0) {
            obj->obj3D_.RemoveAnimationPackageByID(3);
            unsigned short af = area->currentZoneID_;
            if (af == obj->obj3D_.GetField06()) {
                obj->obj3D_.MakeVisible();
            }
            SetByte0xbeShiftPrev((Bytes02033b88*)obj, 0);
        }
    }

    for (j = 0; j < 0x20; j++) {
        obj = gs->GetGameObjectByIndex(j + 0xa0);
        if (obj != 0) {
            obj->obj3D_.Destroy();
            ClearCombatantSlot(gs, j + 0xa0);
        }
    }

    if (ptr6[1] != 0) {
        if (GetFieldIfFlag4((char*)gs) == 0) {
            SetField0x3b0Value(gs, ptr6[1]);
            hud = GetFieldIfFlag4((char*)gs);
        }
    }

    void* list = GetGlobalPtr021075f4();
    char buf[16];
    const char* fmt;
    char* nameBuf;

    k = 0;
    nameBuf = buf;
    fmt = data_ov001_02164c4a;
    for (; k < 0x20; k++) {
        int* entry = (int*)GetEntryUnlessFlag0x8000((EntryList_203dce4*)list, k);
        if (entry != 0) {
            unsigned char* p = (unsigned char*)GetField0x8(entry);
            if (p[2] == 3) {
                Container0204039c* cont = (Container0204039c*)EmptyStub0203d004(list);
                sprintf(nameBuf, fmt, p + 4);
                int idx = FindEntryIndexByName02040404((Container02040404*)cont, nameBuf);
                ReleaseOrDecrementSlot0204039c(cont, idx);
                Reset02040504(entry);
                SetSlotIfIndexBelow32((SlotArray0203dd10*)list, k, 0);
            }
        }
    }

    ReinitController02043204(globalA);
    func_02043124(globalA);
    ClearBitsInField4((unsigned int*)res2, 8);
    if (IsScaledFieldPositive0203adfc(data_02108760, 0) != 0) {
        ScaleAndNotify0203ad88(data_02109bf4, 0, 0);
    }
    ClearBitsInField4((unsigned int*)res2, 0x2000);
    SetField0x7cClearFields0x1ec0x1ee((unsigned char*)hud, 0);
    SetFields0x1f0And0x1f4(hud, 0xf000, 0);
    SetScaledEffectParam020708c8((EffectParam020708c8*)func_020704fc(), 0);
    loader->MaybeReset();

    REG_DISPSTAT_304 &= ~0x8000;
    if (GetBitsInField0((unsigned int*)res2, 0x1000) != 0) {
        ResetAndReinit0209c278(data_02109bf4);
        Dispatch0203a974With0x57000(data_02109bf4);
        SetupContextForMode0205ea20(data_02108760, 0x64);
        ClearBitsInWord((unsigned int*)((int)res2), 0x1000);
        func_ov028_021d9714();
        PopStack1AndTrigger(1);
    }

    DISPCNT = (DISPCNT & ~0x1f00) | 0x100;

    void* events = func_0205ec34();
    BmdjScriptNode* node = GetNodeAtDepth020196fc((Zone3D*)func_02012fe4(), 0);
    BmdjSceneElement* e;
    int count = node->scriptState.elementCount;
    if (node != 0) {
        for (int n = 0; n < count; n++) {
            e = &node->elements[n];
            if (TestBitInByteArray((int)events, (unsigned char*)((char*)events + 0x45b), n & 0xff) != 0) {
                if (e != 0) {
                    e->flags &= ~4;
                }
            } else {
                if (e != 0) {
                    e->flags |= 4;
                }
            }
        }
    }
    return 0xf;
}
