// JPN: func_ov025_021d94f0
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "System/Matrix.h"

#if defined(jpn)
enum { CombatantSubobject = 0x144, Field9ec = 0x968, Field9e0 = 0x95c, Field826 = 0x7a2, Field4c8 = 0x444, Field4c4 = 0x440, Fieldeb8 = 0xe34, Fieldea8 = 0xe24, Field4d0 = 0x44c, Field4ca = 0x446, Field2a0 = 0x21c, Field46c = 0x3e8, Field18c = 0x180, CameraPosition = 0xc04, EntryList = 0x371c, Field6e4e = 0x703e, Field6efe = 0x70ee, Field6fd8 = 0x71c8, Field6fe8 = 0x71d8, Field7744 = 0x7934, Field7745 = 0x7935, Field7746 = 0x7936, PendingShake = 0x71cc, PendingState = 0x71ec, Auxiliary = 0x224, MessageQueue = 0x80c, CameraBase = 0xb94, ModeByte = 0xdb4 };
#else
enum { CombatantSubobject = 0x150, Field9ec = 0x9ec, Field9e0 = 0x9e0, Field826 = 0x826, Field4c8 = 0x4c8, Field4c4 = 0x4c4, Fieldeb8 = 0xeb8, Fieldea8 = 0xea8, Field4d0 = 0x4d0, Field4ca = 0x4ca, Field2a0 = 0x2a0, Field46c = 0x46c, Field18c = 0x18c, CameraPosition = 0xc88, EntryList = 0x3760, Field6e4e = 0x6e4e, Field6efe = 0x6efe, Field6fd8 = 0x6fd8, Field6fe8 = 0x6fe8, Field7744 = 0x7744, Field7745 = 0x7745, Field7746 = 0x7746, PendingShake = 0x6fdc, PendingState = 0x6ffc, Auxiliary = 0x2a8, MessageQueue = 0x890, CameraBase = 0xc18, ModeByte = 0xe38 };
#endif

struct List02160094;
struct ListNode02160094 {
    char pad0[0x20];
    unsigned short combatantId;
};

struct List021600f8;
struct ListNode021600f8 {
    char pad0[0xe];
    short ids[3];
    unsigned char codes[3];
    unsigned char count;
    unsigned char pad18[4];
    unsigned char pad1c : 7;
    unsigned char firstIsTarget : 1;
};

struct ListNode0215feb4;

struct HitEntry_021d8c30 {
    unsigned long long mask;
    char pad8[4];
    short amount;
    short s0e;
    short s10;
    short s12;
    short s14;
    char pad16[2];
    unsigned int flags18;
    unsigned char show;
    unsigned char b1d;
    unsigned char b1e;
};

struct HitCell_021d8c30 {
    char pad0[0xc];
    short value;
    char pad0e[0x12];
    struct HitCell_021d8c30* next;
};

struct HitRow_021d8c30 {
    struct HitCell_021d8c30* cells[3];
    char pad0c[0xc];
    unsigned char counts[3];
    char pad1b[5];
    struct HitRow_021d8c30* next;
};

struct EventRow_021d8c30 {
    unsigned short type;
    char pad2[7];
    unsigned char rowCount;
    char pad0a;
    unsigned char lo : 3;
    unsigned char needsInit : 1;
    unsigned char queued : 1;
    unsigned char group : 3;
    char pad0c[8];
    struct HitRow_021d8c30* rows;
    char pad18[0xa];
    unsigned short pendingA;
    unsigned short pendingB;
};

struct TableEntry_021d8c30 {
    char pad0[0x14];
    unsigned int pad14 : 28;
    unsigned int kind14 : 4;
    unsigned int pad18a : 12;
    unsigned int kind18 : 4;
    unsigned int pad18b : 16;
};

struct MonsterInfo_021d8c30 {
    char pad0[0x10];
    unsigned int pad10 : 31;
    unsigned int bit31 : 1;
    char pad14[0x10];
    unsigned int pad24a : 28;
    unsigned int bit28 : 1;
    unsigned int pad24b : 3;
};

struct Nibbles_021d8c30 {
    unsigned char lo : 4;
    unsigned char hi : 4;
};

struct MsgPair_021d8c30 {
    unsigned short duration;
    short strength;
};

struct RowEntry_021d8c30 {
    void* w0;
    int w1;
    int w2;
    int w3;
    int w4;
    unsigned char b;
    unsigned char pad[3];
    short s18;
    short s1a;
    int w1c;
};

struct SlotEntry_021d8c30 {
    unsigned int w0;
    unsigned int w1;
    unsigned int w2;
    unsigned int w3;
    unsigned int w4;
    unsigned char b;
    unsigned char pad[3];
    short s18;
    short s1a;
};

struct FiveWordsAndByte_021dcd28 {
    unsigned int w0;
    unsigned int w1;
    unsigned int w2;
    unsigned int w3;
    unsigned int w4;
    unsigned char b;
};

struct InitStruct02078484Struct {
    unsigned char f00;
    unsigned char pad01[0xf];
    unsigned char f10;
    unsigned char flags11;
    short f12;
    short objectId;
    short f16;
    short f18;
    short f1a;
    short f1c;
    short pad1e;
    int f20;
    int f24;
    int f28;
    Vector3fix offset;
    Vector3fix rotation;
    Vector3fix scale;
};

struct Obj0205eaa0;
struct Obj0203a48c;
struct Vec3Int0203a48c;
struct Obj0203a588;
struct ShortPair0xba0xbc;
struct Struct5e00;
struct Bytes02033b88;
struct Obj02176134;
struct Obj02176150;

extern "C" void* func_0202ae18(void);
int GetField0x3b0Value(GameState* battleStruct);
struct Obj0203a588* GetData02104b6c(void);
extern "C" int _Z16GetField02163524Pv(void* obj);
void* GetData02108e10(void);
extern "C" void* _Z24SearchBothTables02079e2cPci(char* p, int key);
extern "C" unsigned char _Z25GetByte_021dcc64_021dcc64Pv(void* obj);
extern "C" ListNode021600f8* _Z22GetNodeAtIndex021600f8P12List021600f8i(List021600f8* list, int index);
extern "C" void _Z18AppendRow_021dcc70PcS_(char* obj, char* src);
extern "C" void _Z24AppendSlotEntry_021dcde8PhP25FiveWordsAndByte_021dcd28(unsigned char* obj, struct FiveWordsAndByte_021dcd28* src);
extern "C" ListNode02160094* _Z22GetNodeAtIndex02160094P12List02160094i(List02160094* list, int index);
extern "C" struct ListNode0215feb4* _Z22GetNodeAtIndex0215feb4Pcii(char* base, int threshold, int slot);
extern "C" int func_ov000_0215ffa0(void* node);
extern "C" void* _Z23FindNodeAtDepth0215fff4Pvii(void* obj, int limit, int idx);
extern "C" void _Z23SetOrInitField_02182498Pvi(void* objRaw, int flag);
extern "C" int strcmp(const char* a, const char* b);
extern "C" void func_ov025_021eaf48(unsigned char* obj, int idx, int category, int entry);
extern "C" void func_ov025_021ea604(unsigned char* obj, int idx, int category, int entry);
extern "C" void func_ov000_02162dc4(unsigned char* sl, GameObject* lead, GameObject* actor, unsigned int flags,
                                    int b1d, int b1e, unsigned long long mask, int zero);
void ClearSubstructFlag0x4(unsigned char* obj);
extern "C" void _Z23SetPosAndFields0216f1e4PvPiii(void* obj, int* srcVec3, int a, int b);
void StoreFields0x1e4And0x1e8IfNonZero(unsigned char* obj, int a, int b);
void SetShortTriple0x6e44(void* obj, unsigned short a, unsigned short b, unsigned short c);
extern "C" void _Z15Forward0205ec20PvS_i(void* obj, void* target, int arg);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);
GameObject* GetCombatantWithFlag0x400(GameState* battleStruct, int combatantId);
extern "C" int func_ov025_021ed444(char* obj, int id, int val2, int type, int val3, short val4, unsigned short val5);
extern "C" int func_ov025_021ed380(char* obj, int id, int val2, int type, int val3, short val4, unsigned short val5);
extern "C" void* func_02057924(void);
extern "C" void _Z18InitStruct02078484P24InitStruct02078484Struct(struct InitStruct02078484Struct* p);
extern "C" void _ZN8Vector3iaSERKS_(Vector3fix* dst, const Vector3fix& src);
extern "C" void _Z26FindNodeAndProcess02057fb4Pvii(void* list, int id, int a3);
int TestBit0At0x2f4(unsigned char* obj);
int TestBit1At0x2f4(unsigned char* obj);
extern "C" int func_ov000_0215fd90(void* entry, int effect);
void SetFields0xbaAnd0xbc(struct ShortPair0xba0xbc* obj, short a, short b);
void* GetActiveCombatWork(void);
extern "C" void* _Z20GetOffsetPtr02160f08Pv(void* obj);
extern "C" void* _Z22FindEntryById_021dafd0Pci(char* obj, int id);
extern "C" void func_ov000_0217616c(void* p);
void SetSubstructWord0x68(unsigned char* obj, int value);
extern "C" void _Z23QueuePopupEntry0203a48cP11Obj0203a48ctP15Vec3Int0203a48chii(
    struct Obj0203a48c* obj, int id, Vector3fix* pos, int style, int field4, int field2);
void SetSubstructByte0x56(unsigned char* obj);
extern "C" void _Z24CopyObjectFields02048588PhS_(unsigned char* self, unsigned char* dst);
extern "C" void _Z37AllocateSlotAndConfigureField02166784P10Struct5e00PhS1_(struct Struct5e00* obj1, unsigned char* obj2, unsigned char* obj3);
extern "C" void func_ov000_021677fc(void* p);
int SetByte0xbeShiftPrev(struct Bytes02033b88* p, int val);
int GetSubstructByte0x56(unsigned char* obj);
extern "C" void _Z26ResetCombatantSlot020d7334Phi(unsigned char* base, int index);
void ClearSubstructByte0x56(unsigned char* obj);
extern "C" void _Z28ClearBitIfValueFound02167434Phi(unsigned char* obj, int value);
extern "C" void func_ov017_02191aac(char* obj, int mode, int idx, unsigned char mask);
extern "C" void func_02054028(void* obj, int n);
int GetWord0x0(int* obj);
void SetMainBrightness(GameResources* resources, int brightness, int duration);
extern "C" void _Z34DispatchIfField0xc4NonNeg_0205ebfcPvii(void* obj, int a, int b);
extern "C" void func_ov000_021823dc(unsigned char* obj, int val);
extern "C" int _Z31IsCombatantStateSpecial02163c0cPvi(void* unused, int id);
extern "C" void* __clear(void* dst, int count);
extern "C" void _Z24SetShortField0xC02176134P11Obj02176134s(struct Obj02176134* obj, short val);
extern "C" void _Z24SetShortField0xE02176150P11Obj02176150s(struct Obj02176150* obj, short val);
extern "C" void _Z23SetByteField37_0216ff20Pch(char* obj, unsigned char val);
int GetField0x3acValue(GameState* battleStruct);
extern "C" void func_ov017_021c9d2c(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);

extern struct Obj0205eaa0 data_02108760;
extern char data_ov025_021ef3d0[];
extern char data_ov025_021ef3d5[];
extern char data_ov025_021ef3e0[];
extern char data_ov025_021ef3e8[];
extern char data_ov025_021ef3ef[];
extern char data_ov025_021ef3f5[];
extern char data_ov025_021ef3fc[];
extern const int data_ov025_021eeea4[];
extern const int data_ov025_021eeebc[];

static inline int IsPartyMember(int id) {
    return id >= 0 && id <= 3;
}

static inline int IsPartyIndex(unsigned short id) {
    return id <= 3;
}

static inline unsigned char* Codes(ListNode021600f8* row) {
    return row->codes;
}

static inline int PopupDelay(int inner) {
    return data_ov025_021eeea4[inner];
}

static inline int PopupColor(int inner) {
    return data_ov025_021eeebc[inner];
}

static inline fix32_t MulFx(fix32_t a, fix32_t b) {
    return FIX32_MULTIPLY(a, b);
}

static inline Vector3fix GetPendingShake(void* work) {
    return *(Vector3fix*)((unsigned char*)work + PendingShake);
}

// USA: func_ov025_021d8c30
extern "C" ARM int func_ov025_021d8c30(unsigned char* sl, struct EventRow_021d8c30* sb, int kind, int category,
                                        int idx, int inner, unsigned char flag) {
    ListNode02160094* first;
    GameState* battle;
    char* ov17;
    unsigned char* camera;
    struct Obj0203a48c* popups;
    int slotBase;
    struct TableEntry_021d8c30* entry;
    int entryIsKind2;
    int result;
    int fromRow;
    int animSaved;
    int savedAnimTime;
    int leadId;
    GameObject* leadObj;
    ListNode02160094* leadNode;
    int didAnim;
    int soundId;
    GameObject* animObj;
    unsigned char textKind;
    int keepDefault;
    int cleared;
    int specialRow;
    int wantAlt;
    int hadTarget;
    int skipSe;
    GameObject* slotObj;
    int critical;
    int alt;
    void* work;
    int amount;
    unsigned char played;
    int sfx;
    unsigned char deadly;
    unsigned char tough;
    unsigned char party;
    int negAmount;
    void* list;
    int facing;
    int radHalf;
    int leadHeight;
    int leadRadHalf;
    int special;
    struct MsgPair_021d8c30* msg;
    int slot;
    int i;
    int rowKind;
    unsigned char flags;
    bool useFacing;

    battle = GameState::GetInstance();
    ov17 = (char*)func_ov017_0218b5b0();
    func_0202ae18();
    camera = (unsigned char*)GetField0x3b0Value(battle);
    popups = (struct Obj0203a48c*)GetData02104b6c();
    slotBase = _Z16GetField02163524Pv(sl);
    entry = (struct TableEntry_021d8c30*)_Z24SearchBothTables02079e2cPci((char*)GetData02108e10(), *(short*)sb);
    entryIsKind2 = 0;
    if (entry != 0 && entry->kind18 == 2) {
        entryIsKind2 = 1;
    }

    if (kind == 0 && sl[Field6e4e] == 6) return 0;
    if (kind == 1 && sl[Field6e4e] == 4) return 0;

    *(unsigned short*)(sl + Field9ec) = sl[Field9e0];

    int id = -1;
    result = 0;
    struct HitEntry_021d8c30* target = 0;
    ListNode021600f8* row = 0;
    const char* animName;
    int quiet;

    if (flag == 0) {
        if (_Z25GetByte_021dcc64_021dcc64Pv(sl) != 0) {
            ListNode021600f8* node = _Z22GetNodeAtIndex021600f8P12List021600f8i((List021600f8*)sb, idx);
            struct RowEntry_021d8c30 tmp;
            if (node) {
                tmp.s18 = node->ids[1];
                tmp.s1a = node->ids[0];
            }
            tmp.w2 = category;
            tmp.w0 = sb;
            tmp.w1 = kind;
            tmp.w3 = idx;
            tmp.w4 = inner;
            tmp.b = 1;
            _Z18AppendRow_021dcc70PcS_((char*)sl, (char*)&tmp);
            return 0;
        }
        int queued = sl[Field6efe];
        if (queued > 0) {
            struct SlotEntry_021d8c30 tmp2;
            tmp2.w2 = category;
            tmp2.w0 = (unsigned int)sb;
            tmp2.w1 = kind;
            tmp2.w3 = idx;
            tmp2.w4 = inner;
            tmp2.b = 1;
            _Z24AppendSlotEntry_021dcde8PhP25FiveWordsAndByte_021dcd28(sl, (struct FiveWordsAndByte_021dcd28*)&tmp2);
            return result;
        }
    }

    fromRow = 0;
    if (kind == 0) {
        ListNode02160094* node = _Z22GetNodeAtIndex02160094P12List02160094i((List02160094*)sb, idx);
        if (node) {
            id = node->combatantId;
            if (category == 0) {
                result = (int)_Z22GetNodeAtIndex0215feb4Pcii((char*)node, inner, 0);
            } else if (category == 1) {
                result = (int)_Z22GetNodeAtIndex0215feb4Pcii((char*)node, inner, 2);
            } else if (category == 2) {
                result = (int)_Z22GetNodeAtIndex0215feb4Pcii((char*)node, inner, 3);
            } else if (category == 3) {
                result = (int)_Z22GetNodeAtIndex0215feb4Pcii((char*)node, inner, 5);
            } else if (category == 4) {
                result = (int)_Z22GetNodeAtIndex0215feb4Pcii((char*)node, inner, 4);
            } else if (category == 5) {
                result = (int)_Z22GetNodeAtIndex0215feb4Pcii((char*)node, inner, 1);
            }
        }
    } else if ((unsigned int)(kind - 1) <= 2) {
        ListNode021600f8* node = _Z22GetNodeAtIndex021600f8P12List021600f8i((List021600f8*)sb, idx);
        if (node) {
            row = node;
            id = func_ov000_0215ffa0(node);
            if (category == 0) {
                result = (int)_Z23FindNodeAtDepth0215fff4Pvii(node, inner, 0);
            } else if (category == 1) {
                result = (int)_Z23FindNodeAtDepth0215fff4Pvii(node, inner, 1);
            } else if (category == 2) {
                result = (int)_Z23FindNodeAtDepth0215fff4Pvii(node, inner, 2);
            }
            fromRow = 1;
        }
    }
    if (sb->needsInit) {
        _Z23SetOrInitField_02182498Pvi(sl + PendingState, 1);
    }

    GameObject* actor = battle->GetCombatantByIndex(id);
    if (result != 0) target = (struct HitEntry_021d8c30*)result;
    if (id < 0 || actor == 0 || target == 0) {
        return result;
    }

    animSaved = 0;
    savedAnimTime = 0;
    animName = (const char*)actor->obj3D_.activeAnimationRecord_;
    if (animName != 0 && strcmp(animName, data_ov025_021ef3d0) == 0) {
        animSaved = 1;
        savedAnimTime = actor->obj3D_.GetCurrentAnimationTime();
    }

    first = _Z22GetNodeAtIndex02160094P12List02160094i((List02160094*)sb, 0);
    leadId = -1;
    leadObj = 0;
    leadNode = 0;
    if (first) {
        leadId = first->combatantId;
        leadObj = battle->GetCombatantByIndex(leadId);
        leadNode = first;
    }

    msg = (struct MsgPair_021d8c30*)(sl + Field826);
    didAnim = 0;
    sfx = *(short*)(sl + Field4c8);
    animObj = actor;
    soundId = *(unsigned short*)(sl + Field4c4);
    keepDefault = textKind = didAnim;
    if (row != 0 && (row->codes[1] == 8 || row->codes[1] == 7 || row->codes[1] == 6) && row->codes[2] == 3) {
        soundId = 1;
        sfx = 0x1e;
        keepDefault = soundId;
    }

    if (kind == 0) {
        func_ov025_021eaf48(sl + Auxiliary, idx, category, result);
    } else if (kind == 1) {
        func_ov025_021ea604(sl + Auxiliary, idx, category, result);
    } else if (kind == 3) {
        func_ov025_021ea604(sl + Auxiliary, idx, category, result);
    }
    if (kind != 2) {
        func_ov000_02162dc4(sl, leadObj, actor, target->flags18, target->b1d, target->b1e, target->mask, 0);
    }
    if (actor) {
        ClearSubstructFlag0x4((unsigned char*)actor);
    }

    cleared = 0;
    specialRow = 0;
    wantAlt = 0;
    flags = 0;
    hadTarget = 0;
    skipSe = 0;
    rowKind = kind - 1;

    if ((unsigned int)rowKind <= 1) {
        for (i = 1; i < row->count; i++) {
            slot = i - 1;
            int slotId = row->ids[slot];
            slotObj = battle->GetCombatantByIndex(slotId);
            if (slotObj == 0) continue;

            if (row->codes[i] == 3 && kind == 2) {
                Vector3fix pos = *(Vector3fix*)(sl + CameraPosition);
                fix32_t q = fix32_Divide(0x6000, pos.z);
                pos.y = FIX32_MULTIPLY(pos.y, q);
                pos.z = 0x7000;
                _Z23SetPosAndFields0216f1e4PvPiii(sl + CameraBase, &pos.x, 0xb33, 0);
                StoreFields0x1e4And0x1e8IfNonZero(sl + CameraBase, 0xcc, 0x3e8);
                if (kind != 2) {
                    SetShortTriple0x6e44(sl, 0x199, 0x258, 0x32);
                }
                if (sl[Field6fd8]) {
                    _Z15Forward0205ec20PvS_i(&data_02108760, 0, 0);
                }
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 0x44, 0);
                skipSe = 1;
                sfx = -1;
                if (!slotObj->obj3D_.MaybeSetRegularAnimation(data_ov025_021ef3d5, 9)) {
                    slotObj->obj3D_.MaybeSetRegularAnimation(data_ov025_021ef3e0, 9);
                }
                animSaved = 0;
                if (!IsPartyMember(slotId)) {
                    GameObject* f = GetCombatantWithFlag0x400(battle, slotId);
                    if (f && f->obj3D_.unknown_2_ == 0xf4) {
                        animObj = slotObj;
                        didAnim = 1;
                        soundId = 0x1a;
                        flags |= 3;
                    }
                } else {
                    animObj = slotObj;
                    didAnim = 1;
                    soundId = 0x22;
                }
                if ((row->codes[slot] == 8 || row->codes[slot] == 7 || row->codes[slot] == 6) && kind != 2) continue;
                if (sl[Field7744] == slotId) continue;
                func_ov025_021ed444((char*)(sl + MessageQueue), 0x1b8, slotId, 0, 0, -1, 0);
                sl[Field7744] = slotId;
            } else if (row->codes[i] == 1 || row->codes[i] == 2) {
                if (kind != 2) continue;
                didAnim = 1;
                soundId = 0xe;
                animObj = slotObj;
                critical = 0;
                if (row->codes[i] == 2) critical = 1;
                if (critical) soundId = 0x20;
                void* list = func_02057924();
                struct InitStruct02078484Struct req;
                _Z18InitStruct02078484P24InitStruct02078484Struct(&req);
                Vector3fix off;
                Vector3fix pos = slotObj->obj3D_.position_;
                off.x = 0;
                off.y = pos.y + (slotObj->obj3D_.GetHeight() >> 1);
                off.z = slotObj->obj3D_.GetRadius() >> 1;
                _ZN8Vector3iaSERKS_(&req.offset, off);
                req.objectId = slotObj->obj3D_.unknown_4_;
                _Z26FindNodeAndProcess02057fb4Pvii(list, soundId, (int)&req);
                int text;
                if (critical) {
                    text = IsPartyMember(slotId) ? 0x28 : 0x29;
                } else {
                    text = IsPartyMember(slotId) ? 0xa9 : 0xaa;
                }
                func_ov025_021ed444((char*)(sl + MessageQueue), text, slotId, 0, 0, -1, 0);
            } else if (row->codes[i] == 8 || row->codes[i] == 7 || row->codes[i] == 6) {
                specialRow = 1;
                if (row->codes[2] == 1 || row->codes[2] == 2) continue;
                alt = 0;
                if (leadNode && IsPartyIndex(leadNode->combatantId)) {
                    GameObject* lead = GetCombatantWithFlag0x100(battle, leadNode->combatantId);
                    if (lead && (TestBit0At0x2f4(*(unsigned char**)((unsigned char*)lead + CombatantSubobject)) ||
                                 TestBit1At0x2f4(*(unsigned char**)((unsigned char*)lead + CombatantSubobject)))) {
                        if (entry && entry->kind14 != 2) alt = 1;
                    }
                }
                if (!alt) {
                    if (entry == 0) continue;
                    if (entry->kind14 != 3 && entry->kind14 != 4) continue;
                }
                if (sl[Field7745] == row->ids[i] && sl[Field7746] == row->ids[slot]) continue;
                int msgId = 0x7f;
                int slotParty = 0;
                if (row->ids[slot] >= 0 && row->ids[slot] <= 3) slotParty = 1;
                if (slotParty) msgId = 0x7e;
                idx = i - 1;
                func_ov025_021ed444((char*)(sl + MessageQueue), msgId, row->ids[slot], 0, 0, row->ids[i], 0);
                sl[Field7745] = row->ids[i];
                sl[Field7746] = row->ids[idx];
            } else if (row->codes[i] == 0xa) {
                if (sl[Field7744] == slotId) continue;
                func_ov025_021ed444((char*)(sl + MessageQueue), 0x143, slotId, 0, 0, -1, 0);
                sl[Field7744] = slotId;
            } else if (row->codes[i] == 4 || row->codes[i] == 5) {
                if (sl[Field7744] == slotId) continue;
                if (sl[Field6fd8]) {
                    _Z15Forward0205ec20PvS_i(&data_02108760, 0, 0);
                }
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 0x44, 0);
                func_ov025_021ed444((char*)(sl + MessageQueue), 0x142, slotId, 0, 0, -1, 0);
                sl[Field7744] = slotId;
                if (IsPartyMember(slotId)) {
                    animObj = slotObj;
                    didAnim = 1;
                    soundId = 0x23;
                } else {
                    GameObject* f = GetCombatantWithFlag0x400(battle, slotId);
                    if (f && (f->obj3D_.unknown_2_ == 0x3c || f->obj3D_.unknown_2_ == 0x3d)) {
                        slotObj->obj3D_.MaybeSetRegularAnimation(data_ov025_021ef3e8, 0x19);
                    }
                    animObj = slotObj;
                    didAnim = 1;
                    soundId = 0x23;
                }
            }
        }
    }

    if (kind == 2) {
        if (soundId == 0x22 || soundId == 0x1a || soundId == 0x21 || soundId == 0x23) {
            void* list = func_02057924();
            struct InitStruct02078484Struct req;
            _Z18InitStruct02078484P24InitStruct02078484Struct(&req);
            Vector3fix off;
            off.x = 0;
            off.y = animObj->obj3D_.position_.y + (animObj->obj3D_.GetHeight() >> 1);
            off.z = animObj->obj3D_.GetRadius();
            req.objectId = animObj->obj3D_.unknown_4_;
            if (flags & 2) {
                off.z = 0;
                off.y = 0;
                off.x = 0;
            }
            if (soundId == 0x21 || soundId == 0x23) off.z = 0xb33;
            _ZN8Vector3iaSERKS_(&req.offset, off);
            _Z26FindNodeAndProcess02057fb4Pvii(list, soundId, (int)&req);
        }
        if (sb->pendingA) {
            func_ov025_021ed444((char*)(sl + MessageQueue), sb->pendingA, -1, 0, 0, -1, 0);
            sb->pendingA = 0;
        }
        if (sb->pendingB) {
            if (soundId == 0xe) {
                if (row->firstIsTarget) {
                    short who = -1;
                    for (int j = 1; j < row->count; j++) {
                        if (row->codes[j] == 1) {
                            who = row->ids[j - 1];
                            break;
                        }
                    }
                    func_ov025_021ed380((char*)(sl + MessageQueue), sb->pendingB, -1, 0, 0, who, 0);
                }
            } else {
                func_ov025_021ed380((char*)(sl + MessageQueue), sb->pendingB, -1, 0, 0, -1, 0);
                sb->pendingB = 0;
            }
        }
        return result;
    }

    if (target->show) {
        if (!entryIsKind2) {
            soundId = 3;
            textKind = 1;
            int generic = 0;
            if (!IsPartyMember(leadId)) {
                generic = 1;
                soundId = 1;
            }
            if (row->codes[1] == 3 || row->codes[1] == 4 || row->codes[1] == 5) {
                int slotParty = 0;
                if (row->ids[0] >= 0 && row->ids[0] <= 3) slotParty = 1;
                if (!slotParty) {
                    generic = 1;
                } else {
                    generic = 0;
                    soundId = 3;
                    textKind = 1;
                }
            } else if (row->codes[2] == 3) {
                generic = 0;
                soundId = 3;
                textKind = 1;
            }
            if (generic) {
                if (sb->type == 0xf4 || sb->type == 0xf5 || sb->type == 0x48 || sb->type == 0x70) {
                    soundId = 0x24;
                    textKind = 2;
                }
            }
        }
        hadTarget = 1;
    }

    if (func_ov000_0215fd90(target, 0xc)) {
        if (sb->type != 0x150) {
            didAnim = 1;
            soundId = 0x19;
            flags |= 3;
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 0x3b, 0);
        }
    } else if (func_ov000_0215fd90(target, 9) || func_ov000_0215fd90(target, 0xa)) {
        if (func_ov000_0215fd90(target, 9)) {
            int total = 0;
            struct HitRow_021d8c30* hr = sb->rows;
            for (int n = 0; n < sb->rowCount; n++) {
                if (hr == 0) break;
                for (int c = 0; c < 3; c++) {
                    struct HitCell_021d8c30* cell = hr->cells[c];
                    if (cell == 0) continue;
                    for (int k = 0; k < hr->counts[c]; k++) {
                        if (cell == 0) break;
                        short v = cell->value;
                        cell = cell->next;
                        if (v > 0) total += v;
                    }
                }
                hr = hr->next;
            }
            if (total == 0) {
                SetFields0xbaAnd0xbc((struct ShortPair0xba0xbc*)actor, 0x800, 0x1f4);
            }
        }
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 0x3a, 0);
    } else if (func_ov000_0215fd90(target, 6)) {
        if (sb->type != 0x1df) {
            didAnim = 1;
            soundId = 0x1c;
        }
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 0x39, 0);
        actor->obj3D_.MaybeSetRegularAnimation(data_ov025_021ef3ef, 0x10);
        animSaved = 0;
        hadTarget = 1;
    } else if (func_ov000_0215fd90(target, 4) || func_ov000_0215fd90(target, 5) || func_ov000_0215fd90(target, 0x26)) {
        if (!func_ov000_0215fd90(target, 0xd)) {
            if (IsPartyMember(id)) {
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 0x36, 0);
            } else {
                _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 0x37, 0);
            }
            if (func_ov000_0215fd90(target, 5)) {
                if (!animSaved) {
                    actor->obj3D_.MaybeSetRegularAnimation(data_ov025_021ef3d0, 1);
                }
            } else {
                SetFields0xbaAnd0xbc((struct ShortPair0xba0xbc*)actor, 0xcc, 0x12c);
            }
        }
    }

    if (func_ov000_0215fd90(target, 0x2b)) {
        actor->obj3D_.MaybeSetRegularAnimation(data_ov025_021ef3f5, 1);
    }

    work = GetActiveCombatWork();
    void* off = 0;
    void* hud = 0;
    if (work) off = _Z20GetOffsetPtr02160f08Pv(work);
    if (off) hud = _Z22FindEntryById_021dafd0Pci((char*)off, id);
    if (func_ov000_0215fd90(target, 0x2d) && hud) {
        *(unsigned int*)((unsigned char*)hud + 0x28) &= ~0x100;
        func_ov000_0217616c(hud);
    }
    if (func_ov000_0215fd90(target, 0x27)) {
        SetSubstructWord0x68((unsigned char*)actor, (int)target);
    }
    if ((target->flags18 & 0x80000) && target->b1d == 0xa) {
        SetSubstructWord0x68((unsigned char*)actor, (int)target);
    }
    if (func_ov000_0215fd90(target, 0x23) || func_ov000_0215fd90(target, 7)) {
        int popupId = 0;
        if (func_ov000_0215fd90(target, 7)) {
            popupId = 0x64;
        } else if (target->amount == 1) {
            popupId = 5;
        } else if (target->amount == 2) {
            popupId = 0x14;
        } else if (target->amount == 3) {
            popupId = 0x32;
        }
        Vector3fix pos = actor->obj3D_.position_;
        pos.y += actor->obj3D_.GetHeight();
        _Z23QueuePopupEntry0203a48cP11Obj0203a48ctP15Vec3Int0203a48chii(popups, popupId, &pos, 4, 0, 0);
    }

    if (func_ov000_0215fd90(target, 3)) {
        SetSubstructByte0x56((unsigned char*)actor);
        actor->obj3D_.MakeVisible();
        actor->obj3D_.SetInheritedAlpha(0x1f);
        if (actor->obj3D_.unknown_0_ & 0x100) {
            *(unsigned int*)((unsigned char*)actor + Field18c) &= ~1;
        } else {
            unsigned char* found = 0;
            for (int j = 0; j < 4; j++) {
                unsigned char* e = ((unsigned char**)(sl + Fieldeb8))[j];
                if (e && *(short*)(e + 2) == actor->obj3D_.unknown_2_) {
                    found = e;
                    break;
                }
            }
            if (found) {
                if (actor->obj3D_.pModel_ == 0) {
                    _Z24CopyObjectFields02048588PhS_(found, (unsigned char*)actor);
                }
                _Z37AllocateSlotAndConfigureField02166784P10Struct5e00PhS1_((struct Struct5e00*)sl, found, (unsigned char*)actor);
                func_ov000_021677fc(sl);
            }
        }
        SetByte0xbeShiftPrev((struct Bytes02033b88*)actor, 0);
        actor->obj3D_.SkipAnimationTransition();
    } else if (func_ov000_0215fd90(target, 0xd)) {
        if (GetSubstructByte0x56((unsigned char*)actor)) {
            SetByte0xbeShiftPrev((struct Bytes02033b88*)actor, 4);
        }
        _Z26ResetCombatantSlot020d7334Phi((unsigned char*)slotBase, id);
        ClearSubstructByte0x56((unsigned char*)actor);
        _Z28ClearBitIfValueFound02167434Phi(sl, actor->obj3D_.GetTexturePaletteOffset());
        func_ov017_02191aac(ov17, 0, id, 2);
        func_ov017_02191aac(ov17, 0, id, 4);
        if (!entryIsKind2 && kind != 0) {
            LightingManager::GetInstance()->BeginFade(0x800, 0x12c);
            SetShortTriple0x6e44(sl, 0x199, 0x258, 0x96);
            didAnim = 1;
            soundId = 0x1b;
            flags |= 1;
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 0x42, 0);
        }
        cleared = 1;
    } else if (func_ov000_0215fd90(target, 0x24)) {
        actor->obj3D_.MaybeSetRegularAnimation(data_ov025_021ef3fc, 0);
        actor->obj3D_.TransitionInheritedAlpha(0, 0x1f4);
        _Z28ClearBitIfValueFound02167434Phi(sl, actor->obj3D_.GetTexturePaletteOffset());
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 9, 0);
    }

    if (hadTarget) {
        if (!specialRow && (*(int*)(sl + Fieldea8) != 8 || *(int*)(sl + Field4d0) == 0) &&
            (sb->type == 1 || sb->type == 2)) {
            LightingManager::GetInstance()->BeginFade(0x800, 0x12c);
            Vector3fix pos = *(Vector3fix*)(sl + CameraPosition);
            pos.z = FIX32_MULTIPLY(pos.z, 0xe66);
            _Z23SetPosAndFields0216f1e4PvPiii(sl + CameraBase, &pos.x, 0xccc, 0);
            StoreFields0x1e4And0x1e8IfNonZero(sl + CameraBase, 0xcc, 0x3e8);
        }
        if (!((unsigned char*)GetField0x3b0Value(battle) == sl + CameraBase && sl[ModeByte] == 2) &&
            *(int*)(sl + Field4d0) == 0) {
            SetShortTriple0x6e44(sl, 0x199, 0x2bc, 0x96);
        }
    }

    if ((unsigned int)rowKind <= 2 && sb->pendingA) {
        func_ov025_021ed444((char*)(sl + MessageQueue), sb->pendingA, -1, 0, 0, -1, 0);
        sb->pendingA = 0;
    }
    if (func_ov000_0215fd90(target, 8)) {
        func_ov017_02191aac(ov17, 0, actor->obj3D_.unknown_4_, 4);
        if (!fromRow) wantAlt = 1;
    }
    if (func_ov000_0215fd90(target, 0x2c)) {
        func_ov017_02191aac(ov17, 1, actor->obj3D_.unknown_4_, 2);
    }
    if (func_ov000_0215fd90(target, 0x28)) {
        func_ov017_02191aac(ov17, 0, actor->obj3D_.unknown_4_, 2);
    }

    quiet = 0;
    if ((sb->type == 1 || sb->type == 2 || sb->type == 0xdb) && func_ov000_0215fd90(target, 0x2a)) {
        quiet = 1;
    }

    if (func_ov000_0215fd90(target, 1) && !func_ov000_0215fd90(target, 0x29)) {
        amount = target->amount;
        if (func_ov000_0215fd90(target, 2)) {
            SetByte0xbeShiftPrev((struct Bytes02033b88*)actor, 4);
            _Z26ResetCombatantSlot020d7334Phi((unsigned char*)slotBase, id);
            ClearSubstructByte0x56((unsigned char*)actor);
            _Z28ClearBitIfValueFound02167434Phi(sl, actor->obj3D_.GetTexturePaletteOffset());
            func_ov017_02191aac(ov17, 0, id, 2);
            func_ov017_02191aac(ov17, 0, id, 4);
            cleared = 1;
        } else {
            GameState* gs = GameState::GetInstance();
            if (actor->obj3D_.unknown_0_ & 0x400) {
                GameObject* f = GetCombatantWithFlag0x400(gs, actor->obj3D_.unknown_4_);
                unsigned char* info;
                if (f && (info = *(unsigned char**)((unsigned char*)f + 0x144)) != 0) {
                    short k = *(short*)(info + 8);
                    if (k == 0x2d || k == 0x2e || k == 0x2f || k == 0x11b) goto skipFlash;
                }
            }
            if (actor->obj3D_.unknown_0_ & 0x100) {
                func_02054028(actor, 0x64);
            } else {
                actor->obj3D_.SetNoTextureTimer(2);
            }
        skipFlash:
            if (((struct Nibbles_021d8c30*)((unsigned char*)actor + 0xc1))->hi != 1 && !animSaved &&
                GetSubstructByte0x56((unsigned char*)actor)) {
                actor->obj3D_.MaybeSetRegularAnimation(data_ov025_021ef3f5, 9);
            }
        }

        played = 0;
        deadly = 0;
        tough = played;
        party = IsPartyMember(id);
        if (!party) {
            GameObject* f = GetCombatantWithFlag0x400(battle, id);
            struct MonsterInfo_021d8c30* m;
            if (f && (m = *(struct MonsterInfo_021d8c30**)((unsigned char*)f + 0x148)) != 0) {
                deadly = m->bit28;
                tough = m->bit31;
            }
            if (deadly) {
                if (cleared) {
                    sfx = 0x25;
                    GameResources* res = (GameResources*)GetWord0x0((int*)battle);
                    if (res) {
                        SetMainBrightness(res, 0x10, 0);
                        SetMainBrightness(res, 0, 0x1e);
                        SetShortTriple0x6e44(sl, 0x199, 0x3e8, 0x96);
                    }
                } else if (sfx >= 0) {
                    sfx = 0x24;
                }
            }
        }
        if (sfx >= 0) {
            if (sfx != 0x25) {
                if (wantAlt) {
                    if (party) {
                        sfx = 0x27;
                    } else {
                        sfx = 0x26;
                    }
                } else if (party) {
                    if (sfx < 0x3c || sfx > 0x41) sfx = 0x1f;
                } else if (tough && !deadly) {
                    if (sfx < 0x3c || sfx > 0x41) sfx = 0x20;
                }
                if (target->show) {
                    if (row && (row->codes[1] == 3 || row->codes[1] == 4 || row->codes[1] == 5)) {
                        int slotParty = 0;
                        if (row->ids[0] >= 0 && row->ids[0] <= 3) slotParty = 1;
                        if (!slotParty && soundId == 1) sfx = 0x1f;
                    }
                    if (textKind == 1) {
                        sfx = 0x26;
                    } else if (textKind == 2) {
                        sfx = 0x27;
                    }
                }
            }
            if (!skipSe) {
                if (!quiet) {
                    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, sfx, 0);
                }
                played = 1;
            }
        }
        if (!played && (textKind == 1 || textKind == 2)) {
            int se = 0x26;
            if (textKind == 2) se = 0x27;
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, se, 0);
        } else if (*(short*)(sl + Field4ca) >= 0 && !keepDefault) {
            _Z34DispatchIfField0xc4NonNeg_0205ebfcPvii(&data_02108760, *(short*)(sl + Field4ca), 0);
        }
        if (msg->duration) {
            if (!quiet) {
                StoreFields0x1e4And0x1e8IfNonZero(camera, msg->strength, msg->duration);
            }
        } else if (target->show) {
            StoreFields0x1e4And0x1e8IfNonZero(camera, 0x333, 0x1f4);
        }
        Vector3fix pos = actor->obj3D_.position_;
        pos.y += actor->obj3D_.GetHeight();
        int big = 0;
        if (func_ov000_0215fd90(target, 0x2a)) big = 1;
        _Z23QueuePopupEntry0203a48cP11Obj0203a48ctP15Vec3Int0203a48chii(popups, amount, &pos, big, PopupDelay(inner), PopupColor(inner));
        if (!sb->queued && sl[Field6e4e] != 4) {
            func_ov000_021823dc(sl + PendingState, sb->group);
            sb->queued = 1;
        }
        didAnim = 1;
    }

    if (func_ov000_0215fd90(target, 0x25) || func_ov000_0215fd90(target, 0x22)) {
        int style = 2;
        if (func_ov000_0215fd90(target, 0x22)) style = 3;
        negAmount = -target->amount;
        Vector3fix pos = actor->obj3D_.position_;
        if (kind == 0) {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 0x65, 0);
        }
        pos.y += actor->obj3D_.GetHeight();
        _Z23QueuePopupEntry0203a48cP11Obj0203a48ctP15Vec3Int0203a48chii(popups, negAmount, &pos, style, 0, 0);
    }

    if (didAnim && leadObj && soundId > 0) {
        if (target->mask == 1 && kind == 2 && actor == leadObj) flags |= 1;
        list = func_02057924();
        struct InitStruct02078484Struct req;
        _Z18InitStruct02078484P24InitStruct02078484Struct(&req);
        if (kind == 3) {
            for (int j = 1; j < row->count; j++) {
                if (row->codes[j] == 3) leadObj = battle->GetCombatantByIndex(row->ids[j - 1]);
            }
        }
        Vector3fix out;
        Vector3fix dir;
        Vector3fix leadPos = leadObj->obj3D_.position_;
        Vector3fix animPos = animObj->obj3D_.position_;
        facing = animObj->obj3D_.rotation_.y;
        int cutscene;
        if (sl[ModeByte] == 1 || sl[ModeByte] == 2) {
            cutscene = 1;
        } else {
            cutscene = 0;
        }
        useFacing = cutscene | !leadObj->obj3D_.IsVisible();
        radHalf = animObj->obj3D_.GetRadius() >> 1;
        int animHeight = animObj->obj3D_.GetHeight();
        leadHeight = leadObj->obj3D_.GetHeight();
        leadRadHalf = leadObj->obj3D_.GetRadius() >> 1;
        int dist = Vector3fix_Distance(&leadPos, &animPos);
        if (useFacing) {
            fix32_t c = fix32cos(facing);
            fix32_t s = fix32sin(facing);
            Matrix3x3 rot;
            Mat3x3_WriteRotationY(&rot, s, c);
            dir.x = 0;
            dir.y = 0;
            dir.z = 0x1000;
            Mat3x3_ApplyToVector(&dir, &rot, &dir);
            Vector3fixMultiplyScalar(&dir, radHalf, &dir);
            Vector3fix base = animObj->obj3D_.position_;
            Vector3fix_Add(&base, &dir, &out);
        } else {
            int near = 0;
            leadPos.y = 0;
            animPos.y = 0;
            if (IsPartyMember(leadId)) {
                if (dist < radHalf) near = 1;
            }
            if (!near) {
                Vector3fix_Subtract(&leadPos, &animPos, &dir);
                Vector3fix_Normalize(&dir, &dir);
                Vector3fixMultiplyScalar(&dir, radHalf, &dir);
                Vector3fix base = animObj->obj3D_.position_;
                Vector3fix_Add(&base, &dir, &out);
            } else {
                Vector3fix_Subtract(&animPos, &leadPos, &dir);
                Vector3fix_Normalize(&dir, &dir);
                Vector3fixMultiplyScalar(&dir, leadRadHalf + 0x4cc, &dir);
                Vector3fix base = leadObj->obj3D_.position_;
                Vector3fix_Add(&base, &dir, &out);
            }
        }

        special = 0;
        if (IsPartyMember(id)) {
            int h = MulFx(animHeight, 0x999);
            out.y += h;
        } else if (*((unsigned char*)work + Field6fe8) == 0) {
            if (soundId == 0x1c) {
                int h = MulFx(animHeight, 0x999);
                out.y += h;
            } else {
                out.y += (leadHeight + animHeight) >> 2;
                if (_Z31IsCombatantStateSpecial02163c0cPvi(sl, id)) {
                    special = 1;
                    out.y += 0x800;
                }
            }
        } else {
            Vector3fix shake = GetPendingShake(work);
            out.x += shake.x;
            out.y = shake.y;
            out.z += shake.z;
            Vector3fix zero;
            __clear(&zero, sizeof(zero));
            _ZN8Vector3iaSERKS_((Vector3fix*)(sl + PendingShake), zero);
            sl[Field6fe8] = 0;
        }
        if (0.8f * leadHeight < out.y && !special) {
            out.y = 0.8f * leadHeight;
        }
        if (flags & 1) {
            out.x = 0;
            out.z = animObj->obj3D_.GetRadius() >> 1;
            req.objectId = animObj->obj3D_.unknown_4_;
        } else {
            _ZN8Vector3iaSERKS_(&req.rotation, animObj->obj3D_.rotation_);
            _ZN8Vector3iaSERKS_(&req.scale, leadObj->obj3D_.GetScale());
        }
        if (flags & 2) {
            out.z = 0;
            out.y = 0;
            out.x = 0;
        }
        _ZN8Vector3iaSERKS_(&req.offset, out);
        _Z26FindNodeAndProcess02057fb4Pvii(list, soundId, (int)&req);
    }

    if (IsPartyMember(id)) {
        unsigned char* e = (unsigned char*)_Z22FindEntryById_021dafd0Pci((char*)(sl + EntryList), id);
        if (e) {
            if (category != 1 || kind == 0) {
                if (sb->type != 0x3af && sb->type != 0x39a && sb->type != 0x3a0) {
                    short v = target->s0e;
                    _Z24SetShortField0xC02176134P11Obj02176134s((struct Obj02176134*)e, v);
                    *(short*)(e + 0xc) = v;
                }
            }
            if (row && (row->codes[1] == 8 || row->codes[1] == 7 || row->codes[1] == 6)) {
                if (target && (func_ov000_0215fd90(target, 0x22) || func_ov000_0215fd90(target, 0x2a))) {
                    short v = target->s10;
                    _Z24SetShortField0xE02176150P11Obj02176150s((struct Obj02176150*)e, v);
                    *(short*)(e + 0xe) = v;
                }
            } else {
                short v = target->s10;
                _Z24SetShortField0xE02176150P11Obj02176150s((struct Obj02176150*)e, v);
                *(short*)(e + 0xe) = v;
            }
            *(short*)(e + 8) = target->s12;
            *(short*)(e + 0xa) = target->s14;
            *(unsigned int*)(e + 0x28) = target->flags18;
            func_ov000_0217616c(e);
            _Z23SetByteField37_0216ff20Pch((char*)e, target->b1d);
            e[0x2f] = target->b1e;
        }
    }

    if ((*(signed char**)(sl + Field2a0))[0x2a] == GetField0x3acValue(battle) && IsPartyMember(id) &&
        GetCombatantWithFlag0x100(battle, id)) {
        func_ov017_021c9d2c(id, target->s0e, target->s12, target->s10, target->s14, target->flags18, 0, 0, 0);
    }

    *(unsigned int*)(sl + Field46c) |= 0x10;
    if (animSaved && !cleared) {
        actor->obj3D_.MaybeSetRegularAnimation(data_ov025_021ef3d0, 1);
        actor->obj3D_.SetCurrentAnimationTime(savedAnimTime);
    }
    if (cleared) {
        ((struct Nibbles_021d8c30*)((unsigned char*)actor + 0xc1))->hi = 0;
    }
end:
    return result;
}
