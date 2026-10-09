#include <globaldefs.h>
#include "GameState/GameState.h"

struct HitEntry_021eb8e8 {
    unsigned long long mask;
    char pad8[0x10];
    unsigned int flags18;
    unsigned char show;
    unsigned char b1d;
    unsigned char b1e;
};

struct HudEntry_021eb8e8 {
    char pad0[0x28];
    unsigned int flags28;
    char pad2c[3];
    unsigned char b2f;
};

struct Owner_021eb8e8 {
    char pad0[0xc];
    int field_c;
};

void* GetActiveCombatWork(void);
extern "C" char* _Z20GetOffsetPtr02160f08Pv(void* obj);
extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" int func_ov000_0215ec1c(int a, short* buf, int max, int start);
HitEntry_021eb8e8* GetSubstructField0x68(unsigned char* obj);
extern "C" void func_ov000_02162dc4(void* work, GameObject* lead, GameObject* actor, unsigned int flags,
                                    int b1d, int b1e, unsigned long long mask, int flag);
extern "C" HudEntry_021eb8e8* _Z22FindEntryById_021dafd0Pci(char* obj, int id);
extern "C" void func_ov000_0217616c(HudEntry_021eb8e8* p);
extern "C" void _Z23SetByteField37_0216ff20Pch(HudEntry_021eb8e8* obj, unsigned char val);
void SetSubstructWord0x68(unsigned char* obj, int value);
int CheckSubstructFlag0x400(unsigned char* obj);
void ClearSubstructFlag0x400(unsigned char* obj);
int GetSubstructByte0x6c(unsigned char* obj);
void SetSubstructByte0x6c(unsigned char* obj, unsigned char value);
extern "C" void func_02033920(GameObject* obj, int id, int flag);

// USA: func_ov025_021eb8e8
extern "C" ARM void func_ov025_021eb8e8(Owner_021eb8e8* obj) {
    GameState* gs = GameState::GetInstance();
    void* work = GetActiveCombatWork();
    char* hudList = _Z20GetOffsetPtr02160f08Pv(work);
    short buf[16];
    int n = 0;
    n = n + func_ov000_0215e9fc(obj->field_c, buf, 0x10, n);
    n = n + func_ov000_0215ec1c(obj->field_c, buf + n, 0x10 - n, 0);
    short* p = buf;
    for (int i = 0; i < n; p++, i++) {
        GameObject* c = gs->GetCombatantByIndex(*p);
        if (c == 0) {
            continue;
        }
        HitEntry_021eb8e8* hit = GetSubstructField0x68((unsigned char*)c);
        if (hit != 0) {
            unsigned int flags = hit->flags18 & ~0x80000;
            func_ov000_02162dc4(work, 0, c, flags, hit->b1d, hit->b1e, hit->mask, 1);
            HudEntry_021eb8e8* hud = _Z22FindEntryById_021dafd0Pci(hudList, *p);
            if (hud != 0) {
                hud->flags28 = flags;
                func_ov000_0217616c(hud);
                _Z23SetByteField37_0216ff20Pch(hud, hit->b1d);
                hud->b2f = hit->b1e;
            }
            SetSubstructWord0x68((unsigned char*)c, 0);
        }
        if (CheckSubstructFlag0x400((unsigned char*)c)) {
            c->obj3D_.SetInheritedAlpha(0x1f);
            ClearSubstructFlag0x400((unsigned char*)c);
        }
        if (GetSubstructByte0x6c((unsigned char*)c) != 0xff) {
            func_02033920(c, GetSubstructByte0x6c((unsigned char*)c), 1);
            SetSubstructByte0x6c((unsigned char*)c, 0xff);
        }
    }
}
