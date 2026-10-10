#include <globaldefs.h>
#include "GameState/GameState.h"

struct FlaggedEntryContainer02086e9c;
struct FindEntryContainer02086e50;
struct FindEntryContainer02086a04;
struct EntryTable02087574;
struct Struct020865b0;
struct LocalBuf020dcd40 { unsigned char pad[0x30]; };

extern "C" unsigned short* func_02012fe4(void* p);
extern "C" int _Z28GetFirstFlaggedValue02086e9cP29FlaggedEntryContainer02086e9c(FlaggedEntryContainer02086e9c* p);
extern "C" FindEntryContainer02086e50* _Z27FindEntryBySignedId02086e50P26FindEntryContainer02086e50i(FindEntryContainer02086e50* p, int idx);
extern "C" void* _Z30FindRecordByShortField020108f0Pvi(void* state, int slot);
extern "C" char* _Z28FindSlotWithNegShort02010954Pc(char* state);
extern "C" void _Z24ResetShortFields02086380Ph(unsigned char* rec);
extern "C" void func_02082d6c(void* rec, void* entry);
extern "C" void func_ov017_0218f064(void* v, int slot, int flags, int a, int b);
GameObject* GetCombatantWithFlag0x1000(GameState* state, int id);
void ArchiveEntryToCombatantField0x150(EntryTable02087574* p, int idx, int slot);
unsigned char GetField0x3acValue(GameState* state);
void SetField0x2d0(void* obj, unsigned char value);
int GetSignedByte0x2d0(void* obj);
void SetField0x2d1(void* obj, unsigned char value);
unsigned char* GetFieldAt0x150(unsigned char* obj);
extern "C" void __clear(void* p, int size);
extern "C" void func_02042764(void* dst, void* src, int n);
int GetFieldAt0x50(Struct020865b0* entry);
void SetBit0x954StoreIndex0x950(unsigned char* p, int idx);
extern "C" void func_ov017_02191108(void* v, int a, int b, int c, int d);
extern "C" void _Z32RemoveOrShiftMarkedEntry02086a04P26FindEntryContainer02086a04i(FindEntryContainer02086a04* p, int idx);

// USA: func_020dcd40
extern "C" ARM int func_020dcd40() {
    int count = 0;
    GameResources* v14 = func_ov017_0218b5b0();
    GameState* battle = GameState::GetInstance();
    void* p10 = GetPtrField0x2a04(battle);
    unsigned short* v0c = func_02012fe4(p10);
    while (true) {
        int idx = _Z28GetFirstFlaggedValue02086e9cP29FlaggedEntryContainer02086e9c((FlaggedEntryContainer02086e9c*)p10);
        if (idx < 0) {
            break;
        }
        FindEntryContainer02086e50* entry = _Z27FindEntryBySignedId02086e50P26FindEntryContainer02086e50i((FindEntryContainer02086e50*)p10, idx);
        if (entry == NULL) {
            break;
        }
        int slot = -1;
        for (int i = 3; i >= 0; i--) {
            if (battle->GetGameObjectByIndex(i) == NULL) {
                slot = i;
                break;
            }
        }
        if (slot < 0) {
            break;
        }
        void* rec = _Z30FindRecordByShortField020108f0Pvi(battle, slot);
        if (rec == NULL) {
            rec = _Z28FindSlotWithNegShort02010954Pc((char*)battle);
        }
        *(short*)((char*)rec + 0x568) = slot;
        _Z24ResetShortFields02086380Ph((unsigned char*)rec);
        func_02082d6c(rec, entry);
        func_ov017_0218f064(v14, slot, 0x1000, 1, 0);
        GameObject* c = GetCombatantWithFlag0x1000(battle, slot);
        if (c == NULL) {
            break;
        }
        void* p8 = GetPtrField0x2a04(battle);
        ArchiveEntryToCombatantField0x150((EntryTable02087574*)p8, idx, (signed char)slot);
        c->obj3D_.SetField06(*v0c);
        battle->GetProtagonist();
        unsigned char v4 = GetField0x3acValue(battle);
        SetField0x2d0(c, v4);
        int n = 0;
        for (int j = 0; j < 4; j++) {
            GameObject* other = GetCombatantWithFlag0x1000(battle, j);
            if (other != NULL && j != slot && v4 == GetSignedByte0x2d0(other)) {
                n++;
            }
        }
        ((void (*)(void*, int))SetField0x2d1)(c, n);
        GetPtrField0x2a04(battle);
        unsigned char* v7 = GetFieldAt0x150((unsigned char*)c);
        LocalBuf020dcd40 local;
        __clear(&local, 0x30);
        func_02042764((char*)entry + 0x140, &local, 1);
        strcpy((char*)c->baseStats_, (const char*)&local);
        int a = GetFieldAt0x50((Struct020865b0*)entry);
        unsigned char* p = (unsigned char*)entry + GetFieldAt0x50((Struct020865b0*)entry);
        *(unsigned short*)(v7 + a * 2 + 0x16c) = p[2];
        SetBit0x954StoreIndex0x950(v7, GetFieldAt0x50((Struct020865b0*)entry));
        func_ov017_02191108(v14, 1, 1, 1, 1);
        _Z32RemoveOrShiftMarkedEntry02086a04P26FindEntryContainer02086a04i((FindEntryContainer02086a04*)p8, idx);
        count++;
    }
    return count;
}
