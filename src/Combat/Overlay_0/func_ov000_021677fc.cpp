#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int _Z29GetSubstructByte0x56_02049ee8Ph(unsigned char* obj);
extern "C" int _Z29GetThresholdOrDefault021681f8ii(int id, int count);
extern "C" int _Z26ComputeScaledRatio02167b5cii(int a, int b);
extern "C" void _Z24StoreThreeFields02167b54Piiii(int* obj, int a, int b, int c);
extern "C" void _Z46SetSubstructFields4And0xcClearFlag0x2_02049b20PhPi(unsigned char* obj, int* src);
extern "C" void _Z41SetSubstructField0x8ClearFlag0x2_02049bacPhPi(unsigned char* obj, int* src);
extern "C" void _Z23SetIntField560_0216f718Pvi(void* obj, int val);
extern "C" void _Z23SetIntField564_0216f720Pvi(void* obj, int val);

struct EnemyGroup_021677fc {
    unsigned char field_0x0;
    unsigned char lo : 4;
    unsigned char groupCount : 2;
    unsigned char hi : 2;
    char pad_2[2];
    unsigned short kind;
    unsigned char ids[8];
    unsigned char count : 4;
    unsigned char rest : 4;
    char pad_f[0x18 - 0xf];
};

struct Formation_021677fc {
    struct EnemyGroup_021677fc groups[3];
};

struct BattleData_021677fc {
    char pad_0[0x81b0];
    struct Formation_021677fc formation;
    char pad_81fc[0x8de0 - 0x81b0 - sizeof(struct Formation_021677fc)];
    int slots[8];
};

struct Owner_021677fc {
    char pad_0[0x18];
    char sub[0x284];
    struct BattleData_021677fc* data;
    char pad_2a0[0x55dc - 0x2a0];
    int totalWidth;
    int maxHeight;
};

static inline int MulFix(int a, int b) { return (int)(((long long)a * b + 0x800) >> 12); }

// USA: func_ov000_021677fc
extern "C" ARM void func_ov000_021677fc(Owner_021677fc* obj) {
    struct EnemyGroup_021677fc* group;
    struct Formation_021677fc* formation;
    int g;
    char* sub;
    GameState* battle = GameState::GetInstance();
    func_ov017_0218b5b0();
    struct BattleData_021677fc* data = obj->data;
    obj->totalWidth = 0;
    obj->maxHeight = 0;
    sub = obj->sub + 0xc00;
    formation = &data->formation;
    for (g = 0; g < formation->groups[0].groupCount; g++) {
        group = &formation->groups[g];
        for (int j = 0; j < group->count; j++) {
            int id = group->ids[j] + 0xc0;
            GameObject* c = battle->GetCombatantByIndex(id);
            if (c != 0 && _Z29GetSubstructByte0x56_02049ee8Ph((unsigned char*)c) != 0) {
                int found;
                struct BattleData_021677fc* d = obj->data;
                int i = 0;
                for (; i < 8; i++) {
                    if (id == (d->slots[i] & 0xff)) {
                        found = 1;
                        goto done;
                    }
                }
                found = 0;
done:
                if (!found) {
                    int free = -1;
                    for (int i = 0; i < 8; i++) {
                        GameObject* o = battle->GetCombatantByIndex(obj->data->slots[i] & 0xff);
                        if (o == 0 || _Z29GetSubstructByte0x56_02049ee8Ph((unsigned char*)o) == 0) {
                            free = i;
                            break;
                        }
                    }
                    if (free != -1) {
                        obj->data->slots[free] = id;
                    }
                }
            }
        }
    }
    int n = 0;
    for (int i = 0; i < 8; i++) {
        if (battle->GetCombatantByIndex(obj->data->slots[i] & 0xff) != 0) {
            n++;
        }
    }
    for (int i = 0; i < 8; i++) {
        GameObject* c = battle->GetCombatantByIndex(obj->data->slots[i] & 0xff);
        if (c != 0) {
            int radius = c->obj3D_.GetRadius();
            int height = c->obj3D_.GetHeight();
            int thr = _Z29GetThresholdOrDefault021681f8ii(c->obj3D_.unknown_2_, n);
            obj->totalWidth += MulFix(radius, thr);
            if (obj->maxHeight < height) {
                obj->maxHeight = height;
            }
        }
    }
    obj->maxHeight += 0x800;
    int ratio = _Z26ComputeScaledRatio02167b5cii(obj->totalWidth, n & 0xff);
    obj->totalWidth += ratio * (n - 1);
    int x = -(obj->totalWidth / 2);
    for (int i = 0; i < 8; i++) {
        GameObject* c = battle->GetCombatantByIndex(obj->data->slots[i] & 0xff);
        if (c != 0) {
            int radius = c->obj3D_.GetRadius();
            int thr = _Z29GetThresholdOrDefault021681f8ii(c->obj3D_.unknown_2_, n);
            int w = MulFix(radius, thr);
            int half = w / 2;
            int a[3];
            int b[3];
            x += half;
            _Z24StoreThreeFields02167b54Piiii(a, x, 0xcc, -0x2800);
            _Z46SetSubstructFields4And0xcClearFlag0x2_02049b20PhPi((unsigned char*)c, a);
            _Z24StoreThreeFields02167b54Piiii(b, 0, 0, 0);
            _Z41SetSubstructField0x8ClearFlag0x2_02049bacPhPi((unsigned char*)c, b);
            x += half;
            x += ratio;
        }
    }
    _Z23SetIntField560_0216f718Pvi(sub, obj->totalWidth);
    _Z23SetIntField564_0216f720Pvi(sub, obj->maxHeight);
}
