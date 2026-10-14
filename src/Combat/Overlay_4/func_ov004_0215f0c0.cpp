#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "System/Cache.h"
#include "System/LoadToVRAM.h"
#include "System/Matrix.h"

class HudNode {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06();
    virtual void SetPosition(Vector3i* pos);
    virtual Vector3i GetPosition();
    virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28();
    virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32();
    virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36();
    virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40();
    virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48();
    virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52();
    virtual void v53();
    virtual void SetPalette(int palette);
    virtual void v55();
    virtual void SetIcon(unsigned short icon);

    unsigned char pad4[8];
    unsigned char flags;
    unsigned char padd[0x13];
    void* data;
    unsigned char pad24[0x14];
    short frame;
    unsigned char pad3a[0xa];
    unsigned char kind : 4;
};

struct BattleMenuState {
    unsigned char pad0[2];
    unsigned char slot;
    unsigned char pad3[0x19];
    int combatantId;
    unsigned char pad20[8];
    char* textBuf;
};

struct HpStats {
    unsigned char pad0[4];
    unsigned short hp;
};

struct HudCombatant {
    unsigned char pad0[0x130];
    struct HpStats* stats;
    void* baseStats;
};

struct MemberSub150 {
    unsigned char pad0[0x950];
    int portraitBank;
};

struct HudMember {
    unsigned char pad0[0x150];
    struct MemberSub150* sub150;
};

struct HudField150 {
    unsigned char pad0[0x16c];
    unsigned short icons[13];
    unsigned char levels[1];
};

struct PortraitInfo {
    unsigned char pad0[4];
    unsigned short tile;
};

struct PortraitEntry {
    unsigned char pad0[8];
    struct PortraitInfo* info;
};

struct CombatantName {
    int words[3];
};

struct Struct0200fb08;
struct TableA68;

unsigned char* GetFieldAt0x150(unsigned char* obj);
extern "C" HudNode* func_ov004_0215e47c(void* a, int key);
extern "C" void* func_ov023_021fad18(void* node);
struct PortraitEntry* GetArrayEntry_0215e438(void* arr, int idx);
extern "C" int func_ov017_021bdbcc(void* obj);
void* GetTableEntry020421b0(int idx);
unsigned char NormalizeField5_0200fb08(struct Struct0200fb08* obj);
extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" HudNode* func_ov023_021f6880(void* list, int key);
extern "C" int func_ov023_021f6f10(HudNode* node);
int IsValueEqual12(int x);
extern "C" int func_020420e8(void* p, int flag);
int CallFunc020e0434With02153694(int value);
int CheckAfterTwoCalls_0215e460(void);
void SetField38IfState8_0215e49c(void*, int, int);
extern "C" struct TableA68* func_ov023_021fa598(HudNode* node);
void InitObjFromCombatantId020e4bf4(void* obj, int combatantId);
int GetGlobalField0x1c020421a0(void);
extern "C" void func_02046380(void* global);
void* FindEntryByKey(struct TableA68* table, int key);
extern "C" void func_02046608(int a, int b, void* fmt, void* dst, int p4, int p5, int p6);
void* CheckNodeState6_0215e4c0(void* a, int key);
extern "C" void func_ov023_021f809c(void* obj, void* param2);

extern struct BattleMenuState data_ov004_021707e8;
extern int data_ov004_0216fe04[];
extern unsigned short data_ov004_0216fdd0[];

// USA: func_ov004_0215f0c0
extern "C" ARM void func_ov004_0215f0c0(void* self) {
    GameState* gs = GameState::GetInstance();
    struct HudCombatant* combatant = (struct HudCombatant*)GetCombatantWithFlag0x100(gs, data_ov004_021707e8.combatantId);
    struct HudField150* field150 = (struct HudField150*)GetFieldAt0x150((unsigned char*)combatant);
    int dead = 0;
    int palette = 0xf;
    if ((int)combatant->stats->hp <= 0) {
        dead = 1;
    }
    if (dead) {
        palette = 9;
    }
    HudNode* marker = func_ov004_0215e47c(self, 0x1f5);
    if (!dead) {
        void* portraitNode = func_ov004_0215e47c(self, 0x1f4);
        if (portraitNode != 0) {
            int bank;
            void* arr = func_ov023_021fad18(portraitNode);
            int memberIdx = data_ov004_021707e8.combatantId;
            if (memberIdx >= 0) {
                struct HudMember* member = (struct HudMember*)GameState::GetInstance()->GetPartyMemberByIndex(memberIdx);
                if (arr != 0 && member != 0) {
                    struct PortraitEntry* entry = GetArrayEntry_0215e438(arr, 0);
                    struct PortraitInfo* info;
                    if (entry != 0 && (info = entry->info) != 0) {
                        bank = member->sub150->portraitBank;
                        int alt = func_ov017_021bdbcc(func_ov017_0218b5b0());
                        if (alt != 0) {
                            bank = 0;
                        }
                        int i;
                        unsigned int offset;
                        unsigned char tableIdx = bank * 4 + 0x28;
                        offset = (unsigned short)(info->tile & 0x3ff) << 5;
                        for (i = 0; i < 4; i++, tableIdx++) {
                            void* tile = GetTableEntry020421b0(tableIdx);
                            CleanInvalidateCacheRange(tile, 0x20);
                            LoadToMainObjVRAM(tile, offset, 0x20);
                            CleanCacheRange(tile, 0x20);
                            offset += 0x20;
                        }
                    }
                }
            }
        }
        if (marker != 0) {
            marker->flags &= ~8;
        }
    } else {
        if (marker != 0) {
            marker->flags |= 8;
        }
    }

    unsigned char level = NormalizeField5_0200fb08((struct Struct0200fb08*)gs);
    void* list = func_ov011_021849c8(self);
    HudNode* node = func_ov023_021f6880(list, 0x7f);
    if (node == 0) {
        return;
    }
    node->SetIcon(field150->icons[data_ov004_021707e8.slot]);

    node = func_ov023_021f6880(list, 0x7b);
    if (func_ov023_021f6f10(node) == 8) {
        void* baseStats = node->data = combatant->baseStats;
        int width = 0;
        if (baseStats != 0) {
            width = func_020420e8(baseStats, IsValueEqual12(node->kind));
        }
        Vector3i pos;
        pos = node->GetPosition();
        pos.x = (0x23 - (width >> 1)) << 12;
        pos.y = 0x2000;
        node->SetPosition(&pos);
        node->SetPalette(palette);
    }

    int lv = field150->levels[data_ov004_021707e8.slot];
    if (lv != 0) {
        node = func_ov023_021f6880(list, 0x7e);
        if (node == 0) {
            return;
        }
        if (func_ov023_021f6f10(node) == 8) {
            node->frame = lv + 0x1d3;
            if (lv == 10) {
                node->SetPalette(0xd);
            } else {
                node->SetPalette(5);
            }
        }
        node = func_ov023_021f6880(list, 0x7f);
        if (node != 0) {
            Vector3i pos;
            pos = node->GetPosition();
            pos.x = (data_ov004_0216fe04[level] + 0x72) << 12;
            node->SetPosition(&pos);
        }
        node = func_ov023_021f6880(list, 0x7d);
        if (node != 0) {
            node->data = (void*)CallFunc020e0434With02153694(0x3f3);
        }
    } else {
        node = func_ov023_021f6880(list, 0x7e);
        if (node != 0) {
            if (func_ov023_021f6f10(node) == 8) {
                node->frame = 0x3a;
            }
        }
        node = func_ov023_021f6880(list, 0x7f);
        if (node != 0) {
            Vector3i pos;
            pos = node->GetPosition();
            pos.x = (data_ov004_0216fe04[level] + 0x72) << 12;
            node->SetPosition(&pos);
        }
        node = func_ov023_021f6880(list, 0x7d);
        if (node != 0) {
            node->data = (void*)CallFunc020e0434With02153694(0x3f3);
        }
    }

    if (CheckAfterTwoCalls_0215e460() != 0) {
        SetField38IfState8_0215e49c(self, 0x7c, 0x201);
    } else {
        SetField38IfState8_0215e49c(self, 0x7c, data_ov004_021707e8.slot + 0x1e4);
    }

    char* text = data_ov004_021707e8.textBuf;
    memset(text, 0, 0x80);
    unsigned short ids[3];
    ids[0] = data_ov004_0216fdd0[15];
    ids[1] = data_ov004_0216fdd0[16];
    ids[2] = data_ov004_0216fdd0[17];

    if (dead) {
        HudNode* label = func_ov023_021f6880(list, 0x7c);
        if (label != 0) {
            Vector3i pos;
            pos = label->GetPosition();
            pos.x = 0x53000;
            pos.y = 0x2000;
            label->SetPosition(&pos);
            label->SetPalette(palette);
        }
        HudNode* msg = func_ov023_021f6880(list, 6);
        if (msg != 0 && func_ov023_021f6f10(msg) == 4) {
            struct TableA68* table = func_ov023_021fa598(msg);
            struct CombatantName name;
            InitObjFromCombatantId020e4bf4(&name, data_ov004_021707e8.combatantId);
            int g = GetGlobalField0x1c020421a0();
            func_02046380((void*)g);
            *(struct CombatantName**)g = &name;
            func_02046608(g, 0, FindEntryByKey(table, 0x202), text, 0x1e, 0, 0);
            label->data = text;
        }
        for (int i = 0; i < 3; i++) {
            HudNode* n = func_ov023_021f6880(list, ids[i]);
            if (n != 0) {
                n->flags |= 8;
            }
        }
    } else {
        HudNode* label = func_ov023_021f6880(list, 0x7c);
        if (label != 0) {
            label->SetPalette(palette);
        }
        for (int i = 0; i < 3; i++) {
            HudNode* n = func_ov023_021f6880(list, ids[i]);
            if (n != 0) {
                n->flags &= ~8;
            }
        }
    }

    func_ov023_021f809c(CheckNodeState6_0215e4c0(self, 5), self);
}
