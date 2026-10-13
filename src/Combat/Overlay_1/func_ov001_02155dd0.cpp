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
extern "C" char* _Z26GetGlobalField0x1c020421a0v();
void* GetGlobalPtr021075f4(void);
extern "C" void* _Z17EmptyStub0203d004v(void* p);
extern "C" void* _Z24GetEntryUnlessFlag0x8000P17EntryList_203dce4i(void* list, int id);
extern "C" int* _Z11GetField0x8Pi(int* p);
extern "C" int _Z28FindEntryIndexByName02040404P17Container02040404PKc(Container0204039c* c, char* name);
extern "C" void _Z30ReleaseOrDecrementSlot0204039cP17Container0204039ci(Container0204039c* c, int idx);
extern "C" void _Z13Reset02040504Pi(int* p);
extern "C" void _Z21SetSlotIfIndexBelow32P17SlotArray0203dd10ji(SlotArray0203dd10* s, int idx, int emitter);
extern "C" void _Z24ReinitController02043204Pc(char* obj);
extern "C" void func_02043124(char* obj);
extern "C" void _Z17ClearBitsInField4Pjj(unsigned int* p, unsigned int bits);
extern "C" int _Z29IsScaledFieldPositive0203adfcPvS_(void* a, void* b);
extern "C" void _Z22ScaleAndNotify0203ad88PvS_i(void* a, void* b, int c);
extern "C" void _Z33SetField0x7cClearFields0x1ec0x1eePht(unsigned char* obj, short val);
extern "C" void _Z22SetFields0x1f0And0x1f4Pvii(void* obj, int a, int b);
extern "C" void* func_020704fc();
extern "C" void _Z28SetScaledEffectParam020708c8P19EffectParam020708c8j(void* p, unsigned int v);
extern "C" int _Z15GetBitsInField0Pjj(unsigned int* p, unsigned int bits);
extern "C" void _Z22ResetAndReinit0209c278Pv(void* obj);
extern "C" void _Z27Dispatch0203a974With0x57000Pv(void* obj);
extern "C" void _Z27SetupContextForMode0205ea20Pvi(void* obj, int mode);
extern "C" void _Z15ClearBitsInWordPjj(int p, unsigned int bits);
extern "C" void func_ov028_021d9714();
extern "C" void _Z19PopStack1AndTriggeri(int v);
extern "C" void* func_0205ec34();
extern "C" int _Z18TestBitInByteArrayiPhi(int p, unsigned char* arr, int bit);
extern "C" void _Z20SetByte0xbeShiftPrevP13Bytes02033b88i(Struct02033b88* obj, int val);
extern "C" void _Z18ClearCombatantSlotP9GameStatei(GameState* gs, int id);
extern "C" void _Z18SetField0x3b0ValueP9GameStatei(GameState* gs, int val);

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
    globalA = _Z26GetGlobalField0x1c020421a0v();
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
            _Z20SetByte0xbeShiftPrevP13Bytes02033b88i((Struct02033b88*)obj, 0);
        }
    }

    for (j = 0; j < 0x20; j++) {
        obj = gs->GetGameObjectByIndex(j + 0xa0);
        if (obj != 0) {
            obj->obj3D_.Destroy();
            _Z18ClearCombatantSlotP9GameStatei(gs, j + 0xa0);
        }
    }

    if (ptr6[1] != 0) {
        if (GetFieldIfFlag4((char*)gs) == 0) {
            _Z18SetField0x3b0ValueP9GameStatei(gs, ptr6[1]);
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
        int* entry = (int*)_Z24GetEntryUnlessFlag0x8000P17EntryList_203dce4i(list, k);
        if (entry != 0) {
            unsigned char* p = (unsigned char*)_Z11GetField0x8Pi(entry);
            if (p[2] == 3) {
                Container0204039c* cont = (Container0204039c*)_Z17EmptyStub0203d004v(list);
                sprintf(nameBuf, fmt, p + 4);
                int idx = _Z28FindEntryIndexByName02040404P17Container02040404PKc(cont, nameBuf);
                _Z30ReleaseOrDecrementSlot0204039cP17Container0204039ci(cont, idx);
                _Z13Reset02040504Pi(entry);
                _Z21SetSlotIfIndexBelow32P17SlotArray0203dd10ji((SlotArray0203dd10*)list, k, 0);
            }
        }
    }

    _Z24ReinitController02043204Pc(globalA);
    func_02043124(globalA);
    _Z17ClearBitsInField4Pjj((unsigned int*)res2, 8);
    if (_Z29IsScaledFieldPositive0203adfcPvS_(data_02108760, 0) != 0) {
        _Z22ScaleAndNotify0203ad88PvS_i(data_02109bf4, 0, 0);
    }
    _Z17ClearBitsInField4Pjj((unsigned int*)res2, 0x2000);
    _Z33SetField0x7cClearFields0x1ec0x1eePht((unsigned char*)hud, 0);
    _Z22SetFields0x1f0And0x1f4Pvii(hud, 0xf000, 0);
    _Z28SetScaledEffectParam020708c8P19EffectParam020708c8j(func_020704fc(), 0);
    loader->MaybeReset();

    REG_DISPSTAT_304 &= ~0x8000;
    if (_Z15GetBitsInField0Pjj((unsigned int*)res2, 0x1000) != 0) {
        _Z22ResetAndReinit0209c278Pv(data_02109bf4);
        _Z27Dispatch0203a974With0x57000Pv(data_02109bf4);
        _Z27SetupContextForMode0205ea20Pvi(data_02108760, 0x64);
        _Z15ClearBitsInWordPjj((int)res2, 0x1000);
        func_ov028_021d9714();
        _Z19PopStack1AndTriggeri(1);
    }

    DISPCNT = (DISPCNT & ~0x1f00) | 0x100;

    void* events = func_0205ec34();
    BmdjScriptNode* node = GetNodeAtDepth020196fc((Zone3D*)func_02012fe4(), 0);
    BmdjSceneElement* e;
    int count = node->scriptState.elementCount;
    if (node != 0) {
        for (int n = 0; n < count; n++) {
            e = &node->elements[n];
            if (_Z18TestBitInByteArrayiPhi((int)events, (unsigned char*)((char*)events + 0x45b), n & 0xff) != 0) {
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
