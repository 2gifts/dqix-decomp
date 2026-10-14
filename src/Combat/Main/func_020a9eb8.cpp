#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/GrottoStruct.h"
#include "Resource/GameResources.h"
#include "System/Memory.h"
#include "Memory/AllocatorUnion.h"
#include "std_library_functions.h"

struct Struct020a99d0 {
    unsigned short header[70];
    unsigned char flagBits[0x15f];
    unsigned char block[0xd5];
    unsigned short counters[6];
    unsigned char extra[102];
    unsigned char last;
};

struct BattleMemberData {
    signed char entryId : 6;
    unsigned char unk1[0x23c - 1];
};

struct BattleData {
    unsigned char head[0x1d4];
    unsigned char roster[0xe04 - 0x1d4];
    unsigned char tactics[0x128];
    unsigned char unkf2c[0xf68 - 0xf2c];
    int valueF68;
    int valueF6c;
    int valueF70;
    int valueF74;
    unsigned char unkf78[5];
    unsigned char byteF7d;
    unsigned char unkf7e[2];
    BattleMemberData members[13];
    unsigned char memberCount;
    unsigned char extraIds[7];
    unsigned int areaId;
};

struct FieldSubState {
    unsigned char current[0xd98];
    unsigned char saved[0xd98];
    unsigned char unk1b30[4];
    int value1b34;
    int value1b38;
    int value1b3c;
    unsigned char unk1b40[4];
    int value1b44;
    int savedPosA;
    int savedPosB;
    int posA;
    int posB;
    unsigned char unk1b58[9];
    unsigned char byte1b61;
};

struct FieldState {
    unsigned short mapId;
    unsigned char unk2[0x840 - 2];
    FieldSubState sub;
    unsigned char unk23a4[0x2774 - 0x23a4];
    Vector3i savedPos;
    int savedValue;
    short savedAngle;
    unsigned short savedDir;
    unsigned char savedFlag;
    unsigned char unk2789[0x2794 - 0x2789];
    int savedExtra;
    Vector3i pos;
    int value;
    short angle;
    unsigned short dir;
    unsigned char flag;
    unsigned char unk27ad[3];
    int extra;
    unsigned short savedCountA;
    unsigned short savedCountB;
    unsigned char unk27b8[0x27d0 - 0x27b8];
    unsigned char savedCountC;
    unsigned char countC;
    unsigned short countA;
    unsigned short countB;
};

struct SessionState {
    int state;
    unsigned char unk4[0x100d - 4];
    unsigned char subState;
};

struct Global02109418 {
    unsigned char block0[0xa0];
    unsigned char unka0[0x178 - 0xa0];
    unsigned char block178[0x330];
    unsigned char block4a8[0x1a];
};

struct Global02109bf4 {
    unsigned char unk0[0xc8];
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
};

struct TreasureMapList {
    unsigned char numMaps;
    unsigned char padding;
    TreasureMapMetadata maps[99];
};

struct GameStateSaveView {
    unsigned char unk0[0x3e4];
    float savedDayTimer;
    unsigned char unk3e8[0x569c - 0x3e8];
    unsigned char block569c[0x7c];
    unsigned char unk5718[0x5cc8 - 0x5718];
    unsigned char saving;
    unsigned char unk5cc9[7];
    unsigned char grottoBits[10];
    unsigned char byte5cda;
    unsigned char unk5cdb;
    unsigned char block5cdc[0x190];
    unsigned char block5e6c[0x110];
    int value5f7c;
    unsigned char block5f80[0x200];
    unsigned char block6180[0x200];
    unsigned char unk6380[0x63dc - 0x6380];
    unsigned char byte63dc;
    unsigned char unk63dd[0x64f4 - 0x63dd];
    TreasureMapList treasureMaps;
    unsigned char unk6fca[2];
    unsigned char grottoLarge[0x200];
    unsigned int grottoFlags;
    unsigned char unk71d0[0x71fc - 0x71d0];
    unsigned char block71fc[0x2c4];
    unsigned char unk74c0[0x74fe - 0x74c0];
    struct Bytes6 { unsigned char v[6]; } name74fe;
    unsigned char block7504[0xec];
    unsigned char block75f0[0x4d0];
    unsigned char block7ac0[0x3b4];
    int value7e74;
};

struct MonsterRecord {
    unsigned char unk0[0x454];
    unsigned char name[0x10];
};

struct Entry_02028bd0 {
    unsigned short id;
    unsigned short low : 4;
    unsigned short area : 12;
    unsigned short value;
};

struct EntryList_203dce4;
struct Vec3s32_020c3030;
struct OutVec3s16_0203e524 {
    short x, y, z;
};
struct EntryTable02087574;
struct Entry02087574 {
    unsigned char data[0x14];
};

struct BattleSave {
    BattleMemberData members[13];
    unsigned char memberCount;
    unsigned char ids[4];
    unsigned char idCount;
    struct Name { unsigned char v[0x12]; } names[4];
    unsigned char unk1d5a[2];
    unsigned char head[0x1d4];
    unsigned short rosterWords[0x3f0];
    unsigned char rosterBytes[0x3f0];
    unsigned char rosterFlags[8];
    unsigned char tactics[0x128];
    int valueF6c;
    int valueF68;
    int valueF70;
    int valueF74;
    int zero;
    unsigned char extraIds[7];
    unsigned char unk2c4b;
    unsigned short areaId;
    unsigned short zero2;
    unsigned short words[4];
    unsigned char globalByte;
    unsigned char globalByte2;
    unsigned char byteF7d;
    unsigned char byte63dc;
    unsigned short dir;
    short angle;
    Vector3i pos;
    int value;
    int extra;
    unsigned char flag;
    unsigned char countA;
    unsigned char countB;
    unsigned char countC;
    GameStateSaveView::Bytes6 name;
    unsigned char unk2c7e[2];
    int posA;
    int posB;
    unsigned char block4a8[0x1a];
    unsigned char inspect;
    unsigned char unk2ca3[5];
};

struct SaveHeader {
    int checksum;
    struct Info {
        unsigned char resumed;
        unsigned char version;
        unsigned char unk2[2];
        char name[8];
        float dayTimer;
    } info;
};

struct StatsSave {
    int value5cb0;
    int value5cb4;
    int value5cb8;
    int value5cbc;
    Struct020a99d0 record;
};

struct Block194 {
    unsigned char value;
    unsigned char unk1[3];
    unsigned char data[0x190];
};

struct FieldSave {
    unsigned char data[0xd98];
    int value1b38;
    int value1b34;
    int value1b44;
    unsigned short value1b3c;
    unsigned char byte1b61;
    unsigned char zero;
};

struct ItemSave {
    unsigned char blockA[0x200];
    unsigned char blockB[0x200];
    int value;
};

struct PositionSave {
    unsigned short objectId;
    unsigned short rotation;
    Vector3i pos;
    unsigned short area;
    unsigned short entryValue;
    unsigned char globalBit;
    unsigned char distance;
    OutVec3s16_0203e524 nearest;
};

struct GrottoSave {
    unsigned char largeBuffer[0x200];
    unsigned int flags;
    unsigned char bits[10];
};

struct EntrySave {
    unsigned short valid;
    unsigned short count;
    Entry02087574 entries[3];
};

struct SaveBody {
    unsigned int checksum;
    BattleSave battle;
    StatsSave stats;
    unsigned char global0[0xa0];
    unsigned char global178[0x330];
    Block194 block194;
    unsigned char block75f0[0x4d0];
    unsigned char block7ac0[0x3b4];
    unsigned char block7504[0xec];
    unsigned char field[0xd98];
    FieldSave fieldSaved;
    ItemSave items;
    TreasureMapList treasureMaps;
    unsigned char unk68de[2];
    unsigned char block569c[0x7c];
    PositionSave position;
    unsigned char block71fc[0x2c4];
    unsigned char block5e6c[0x110];
    GrottoSave grotto;
    unsigned char unk6f5c[4];
};

struct SaveFile {
    unsigned char header[0x84];
    SaveBody body;
};

struct SaveTask {
    unsigned char state;
    SaveFile* file;
};

extern "C" int func_01ff85b8(void* buf, int size);
extern "C" FieldState* func_02012fe4(void);
extern "C" SessionState* func_0202ae18(void);
extern "C" Struct020a99d0* func_0205ec34(void);
extern "C" int func_0202c540(SessionState* session);
extern "C" int func_0202c508(SessionState* session);
extern "C" int func_02075acc(int offset, void* buf, unsigned int size, int flag);
extern "C" void func_020830cc(MonsterRecord* record, BattleMemberData* dst);
extern "C" void func_020a0c0c(void);
extern "C" void func_020a0cc4(unsigned int size);

Global02109418* GetGlobal02109418_02094d6c(void);
int GetField0x3acValue_020100a8(GameState* gs);
int CheckField0NonZero_0202b7d8(int* p);
int GetFieldAt0x0_0202ba00(int* p);
int TestBitInByteArray_0206dfb0(int base, unsigned char* bits, int bit);
MonsterRecord* GetFieldAt0x150_02053c6c(unsigned char* obj);
unsigned short* GetPointerFromArray0xbd0_0207c5f8(unsigned char* roster, unsigned int idx);
unsigned char* GetPointerAt0xbf0_0207c60c(void* roster, unsigned int idx);
short GetShortFromArray0xc10_0207c620(unsigned char* roster, unsigned int idx);
unsigned char GetByteFromArray0xc28_0207c694(unsigned char* roster, unsigned int idx);
unsigned short* GetField0x74deForValidIndex_020120a0(char* gs, unsigned int idx);
unsigned char GetField0xcc0209ca98(char* p);
unsigned char GetByteFieldAt0xcc_0205ea18(unsigned char* p);
int GetField5cb0Value_0201079c(char* gs);
int GetField5cb4Value_020107d0(char* gs);
int GetField5cb8Value_02010804(char* gs);
int GetField5cbcValue_0201081c(char* gs);
void UpdatePlayClocks020ac4f8(int running);
int IsInRange0201b588(int mapId);
void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
void TailForward02012da4(AllocatorUnion* alloc, void* p);
int CopyOutRegion0x5718_02011494(char* gs, void* out);
void CopyStruct020a99d0(Struct020a99d0* dst, Struct020a99d0* src);
int SendBattleSaveBufferOrSetFlag020ac7b4(int flag);
void EnqueueEventTag23Field_021d0d58(void);
Entry_02028bd0* GetEntryTableBase_02027ca4(void);
Entry_02028bd0* FindInlineEntryById(Entry_02028bd0* base, int id);
EntryList_203dce4* GetGlobalPtr021075f4_0203cf4c(void);
int FindNearestEntryDistance0203e524(EntryList_203dce4* list, Vec3s32_020c3030* pos, OutVec3s16_0203e524* out);
Entry02087574* FindEntryBySignedId02087574(EntryTable02087574* table, int id);

extern char data_020f1bf0[];
extern AllocatorUnion data_02114e20;
extern Global02109bf4 data_02109bf4;
extern unsigned char data_02108760[];

static inline int CalcSaveChecksum(void* data, unsigned int size) {
    return func_01ff85b8((unsigned char*)data + 4, size - 4);
}

// USA: func_020a9eb8
extern "C" ARM int func_020a9eb8(SaveTask* task, SaveBody* body, unsigned int flags, int mode) {
    GameState* gs;
    Struct020a99d0* record;
    Global02109418* global;
    BattleData* battle;
    bool useArea;
    unsigned short savedArea;
    int inspect;
    int k;
    int total;
    int j;
    int slot;
    int i;
    Global02109418* global2;
    SessionState* session2;
    int keepTimer;
    int idCount;
    gs = GameState::GetInstance();
    FieldState* field = func_02012fe4();
    SessionState* session = func_0202ae18();
    record = func_0205ec34();
    global = GetGlobal02109418_02094d6c();
    battle = static_cast<BattleData*>(GetPtrField0x2a04_02010828(gs));
    reinterpret_cast<GameStateSaveView*>(gs)->saving = 1;

    useArea = false;
    savedArea = 0;
    if ((flags & 1) || (flags & 8)) {
        useArea = true;
        if (CheckField0NonZero_0202b7d8(&session->state)) {
            if (func_0202c540(session)) {
                useArea = false;
            }
        }
        if (flags & 8) {
            useArea = true;
        }
        if (useArea) {
            if (TestBitInByteArray_0206dfb0((int)record, record->flagBits, 0x113c)) {
                savedArea = battle->areaId;
            }
            battle->areaId = field->mapId;
            if (flags & 8) {
                battle->areaId = 0x6d;
            }
        }
    }

    GameStateSaveView* view = reinterpret_cast<GameStateSaveView*>(GameState::GetInstance());
    SaveHeader header;
    strcpy(header.info.name, data_020f1bf0);
    keepTimer = flags & 4;
    float dayTimer;
    if (keepTimer) {
        dayTimer = view->savedDayTimer;
    } else {
        dayTimer = reinterpret_cast<GameState*>(view)->GetDayTimer();
    }
    header.info.dayTimer = dayTimer;
    if (!keepTimer) {
        view->savedDayTimer = dayTimer;
    }
    header.info.resumed = mode != 0;
    header.info.version = 1;
    header.checksum = CalcSaveChecksum(&header, sizeof(header));
    func_02075acc(0x10, &header, sizeof(header), 0);
    SendBattleSaveBufferOrSetFlag020ac7b4(0);

    char* base = (char*)body - 0x84;
    inspect = 0;
    if (mode == 0 && (flags & 0x10)) {
        inspect = 1;
    }

    {
        BattleSave* save;
        FieldState* field2;
        GameState* gs2 = GameState::GetInstance();
        BattleData* battle2 = static_cast<BattleData*>(GetPtrField0x2a04_02010828(gs2));
        session2 = func_0202ae18();
        field2 = func_02012fe4();
        func_ov017_0218b5b0();
        global2 = GetGlobal02109418_02094d6c();
        func_020a0cc4(sizeof(BattleSave));
        save = (BattleSave*)AllocateAligned4_02012d88(&data_02114e20, sizeof(BattleSave));
        if (save != NULL) {
            memset(save, 0, sizeof(BattleSave));
            GameStateSaveView::Bytes6 name;
            unsigned char ids[4];
            idCount = CopyOutRegion0x5718_02011494((char*)gs2, ids);
            memcpy(save->members, battle2->members, battle2->memberCount * sizeof(BattleMemberData));
            for (i = 0; i < idCount; i++) {
                slot = i + battle2->memberCount;
                GameObject* obj = GetCombatantWithFlag0x100_0200ff1c(gs2, ids[i]);
                if (obj != NULL) {
                    MonsterRecord* rec = GetFieldAt0x150_02053c6c((unsigned char*)obj);
                    if (rec != NULL) {
                        func_020830cc(rec, &save->members[slot]);
                    }
                }
            }
            save->memberCount = battle2->memberCount;
            for (j = 0; j < idCount; j++) {
                GameObject* obj = GetCombatantWithFlag0x100_0200ff1c(gs2, ids[j]);
                if (obj != NULL) {
                    memcpy(&save->names[j], GetFieldAt0x150_02053c6c((unsigned char*)obj)->name, 0x10);
                }
            }
            memcpy(save->ids, ids, 4);
            save->idCount = idCount;
            if (GetField0x3acValue_020100a8(gs2) != 0 || func_0202c540(session2) != 0) {
                save->ids[0] = 0;
                save->idCount = 1;
            }
            memcpy(save->head, battle2->head, sizeof(battle2->head));
            total = 0;
            for (k = 0; k < 8; k++) {
                unsigned short* words = GetPointerFromArray0xbd0_0207c5f8(battle2->roster, k);
                unsigned char* bytes = GetPointerAt0xbf0_0207c60c(battle2->roster, k);
                short count = GetShortFromArray0xc10_0207c620(battle2->roster, k);
                memcpy(&save->rosterWords[total], words, count * 2);
                memcpy(&save->rosterBytes[total], bytes, count);
                total += count;
                save->rosterFlags[k] = GetByteFromArray0xc28_0207c694(battle2->roster, k);
            }
            memcpy(save->tactics, battle2->tactics, sizeof(battle2->tactics));
            save->valueF6c = battle2->valueF6c;
            save->valueF68 = battle2->valueF68;
            save->valueF70 = battle2->valueF70;
            save->valueF74 = battle2->valueF74;
            save->zero = 0;
            memcpy(save->extraIds, battle2->extraIds, sizeof(battle2->extraIds));
            GameStateSaveView* view2 = reinterpret_cast<GameStateSaveView*>(gs2);
            if (useArea) {
                save->areaId = battle2->areaId;
                view2->value7e74 = battle2->areaId;
                if (func_0202c508(session2)) {
                    EnqueueEventTag23Field_021d0d58();
                }
            } else {
                save->areaId = view2->value7e74;
            }
            save->zero2 = 0;
            unsigned short* words = GetField0x74deForValidIndex_020120a0((char*)gs2, GetField0x3acValue_020100a8(gs2));
            save->words[0] = words[0];
            save->words[1] = words[1];
            save->words[2] = words[2];
            save->words[3] = words[3];
            save->globalByte = GetField0xcc0209ca98((char*)&data_02109bf4);
            save->globalByte2 = GetByteFieldAt0xcc_0205ea18(data_02108760);
            save->byteF7d = battle2->byteF7d;
            save->byte63dc = view2->byte63dc;
            GameStateSaveView::Bytes6* namePtr = &name;
            *namePtr = view2->name74fe;
            save->name = *namePtr;
            if (func_0202c540(session2)) {
                FieldSubState* sub = &field2->sub;
                save->posA = sub->posA;
                save->posB = sub->posB;
                save->dir = field2->dir;
                save->angle = field2->angle;
                save->pos = field2->pos;
                save->value = field2->value;
                save->flag = field2->flag;
                save->extra = field2->extra;
                save->countA = field2->countA;
                save->countB = field2->countB;
                save->countC = field2->countC;
            } else {
                FieldSubState* sub = &field2->sub;
                save->posA = sub->savedPosA;
                save->posB = sub->savedPosB;
                sub->posA = save->posA;
                sub->posB = save->posB;
                save->dir = field2->savedDir;
                save->angle = field2->savedAngle;
                save->pos = field2->savedPos;
                save->value = field2->savedValue;
                save->flag = field2->savedFlag;
                save->extra = field2->savedExtra;
                field2->dir = save->dir;
                field2->angle = save->angle;
                field2->pos = save->pos;
                field2->value = save->value;
                field2->flag = save->flag;
                field2->extra = save->extra;
                save->countA = field2->savedCountA;
                save->countB = field2->savedCountB;
                save->countC = field2->savedCountC;
                field2->countA = save->countA;
                field2->countB = save->countB;
                field2->countC = save->countC;
            }
            memcpy(save->block4a8, global2->block4a8, sizeof(global2->block4a8));
            save->inspect = inspect;
            func_02075acc((char*)&body->battle - base, save, sizeof(BattleSave), 0);
            TailForward02012da4(&data_02114e20, save);
        }
        func_020a0c0c();
        if (TestBitInByteArray_0206dfb0((int)record, record->flagBits, 0x113c)) {
            battle->areaId = savedArea;
        }
    }

    {
        GameState* gs3 = GameState::GetInstance();
        func_0202ae18();
        if (keepTimer) {
            func_02075acc((char*)&body->stats - base + 0x1fb, record->block, sizeof(record->block), 0);
        } else {
            StatsSave stats;
            stats.value5cb0 = GetField5cb0Value_0201079c((char*)gs3);
            stats.value5cb4 = GetField5cb4Value_020107d0((char*)gs3);
            stats.value5cb8 = GetField5cb8Value_02010804((char*)gs3);
            stats.value5cbc = GetField5cbcValue_0201081c((char*)gs3);
            CopyStruct020a99d0(&stats.record, record);
            func_02075acc((char*)&body->stats - base, &stats, sizeof(stats), 0);
        }
    }

    if (!keepTimer) {
        GameStateSaveView* view4 = reinterpret_cast<GameStateSaveView*>(GameState::GetInstance());
        Block194* block = (Block194*)AllocateAligned4_02012d88(&data_02114e20, sizeof(Block194));
        if (block != NULL) {
            block->value = view4->byte5cda;
            memcpy(block->data, view4->block5cdc, sizeof(block->data));
            func_02075acc((char*)&body->block194 - base, block, sizeof(Block194), 0);
            TailForward02012da4(&data_02114e20, block);
        }
        int offset = (char*)body->field - base;
        FieldSubState* sub = &func_02012fe4()->sub;
        func_02075acc(offset, sub->current, sizeof(sub->current), 0);
        func_020a0cc4(sizeof(FieldSave));
        FieldSave* fieldSave = (FieldSave*)AllocateAligned4_02012d88(&data_02114e20, sizeof(FieldSave));
        if (fieldSave != NULL) {
            VectorizedInvertedMemcpy(sub->saved, fieldSave->data, sizeof(sub->saved));
            fieldSave->value1b38 = sub->value1b38;
            fieldSave->value1b34 = sub->value1b34;
            fieldSave->value1b44 = sub->value1b44;
            fieldSave->value1b3c = sub->value1b3c;
            fieldSave->byte1b61 = sub->byte1b61;
            fieldSave->zero = 0;
            func_02075acc(offset + sizeof(sub->current), fieldSave, sizeof(FieldSave), 0);
            TailForward02012da4(&data_02114e20, fieldSave);
        }
        func_020a0c0c();
        GameStateSaveView* view5 = reinterpret_cast<GameStateSaveView*>(GameState::GetInstance());
        ItemSave items;
        items.value = view5->value5f7c;
        memcpy(items.blockA, view5->block5f80, sizeof(items.blockA));
        memcpy(items.blockB, view5->block6180, sizeof(items.blockB));
        func_02075acc((char*)&body->items - base, &items, sizeof(items), 0);
        func_02075acc((char*)body->block5e6c - base, reinterpret_cast<GameStateSaveView*>(GameState::GetInstance())->block5e6c, 0x110, 0);
    }
    func_02075acc((char*)body->global0 - base, global->block0, sizeof(global->block0), 0);
    func_02075acc((char*)body->global178 - base, GetGlobal02109418_02094d6c()->block178, 0x330, 0);
    func_02075acc((char*)body->block75f0 - base, reinterpret_cast<GameStateSaveView*>(gs)->block75f0, 0x4d0, 0);
    func_02075acc((char*)body->block7ac0 - base, reinterpret_cast<GameStateSaveView*>(gs)->block7ac0, 0x3b4, 0);

    SessionState* session3 = func_0202ae18();
    int state = GetFieldAt0x0_0202ba00(&session3->state);
    int subState = session3->subState;
    int running = 0;
    if ((state == 5 && subState > 1) || state == 6) {
        running = 1;
    }
    UpdatePlayClocks020ac4f8(running);

    func_02075acc((char*)body->block7504 - base, reinterpret_cast<GameStateSaveView*>(GameState::GetInstance())->block7504, 0xec, 0);

    {
        int offset;
        int n;
        offset = (char*)&body->treasureMaps - base;
        GameState* gs5 = GameState::GetInstance();
        FieldState* field5 = func_02012fe4();
        TreasureMapList maps;
        if (mode) {
            offset += 0x8000;
        }
        VectorizedInvertedMemcpy(&reinterpret_cast<GameStateSaveView*>(gs5)->treasureMaps, &maps, sizeof(maps));
        if (!IsInRange0201b588(field5->mapId)) {
            TreasureMapMetadata* map = maps.maps;
            for (n = 0; n < maps.numMaps; n++) {
                map->ClearInitialByteUnknownBit();
                map++;
            }
        }
        func_02075acc(offset, &maps, sizeof(maps), 0);
    }

    unsigned char* src6 = reinterpret_cast<GameStateSaveView*>(GameState::GetInstance())->block569c;
    func_02075acc((char*)body->block569c - base, src6, 0x7c, 0);

    if (mode) {
        PositionSave position;
        GameObject* obj = GameState::GetInstance()->GetUnknownGameObject();
        if (obj != NULL) {
            position.objectId = obj->obj3D_.GetField06();
            position.pos = obj->obj3D_.position_;
            position.rotation = obj->obj3D_.rotation_.y;
        }
        FieldState* field6 = func_02012fe4();
        Entry_02028bd0* entry = FindInlineEntryById(GetEntryTableBase_02027ca4(), field6->mapId);
        if (entry == NULL) {
            position.entryValue = 0;
            position.area = 0;
        } else {
            position.entryValue = entry->value;
            position.area = entry->area;
        }
        position.globalBit = data_02109bf4.bit2;
        position.distance = FindNearestEntryDistance0203e524(GetGlobalPtr021075f4_0203cf4c(), (Vec3s32_020c3030*)&obj->obj3D_.position_, &position.nearest);
        func_02075acc((char*)&body->position - base, &position, sizeof(position), 0);
    }

    unsigned char* src8 = reinterpret_cast<GameStateSaveView*>(GameState::GetInstance())->block71fc;
    func_02075acc((char*)body->block71fc - base, src8, 0x2c4, 0);

    if (mode) {
        if (mode) {
            GameState* gs7 = GameState::GetInstance();
            GameStateSaveView* view7 = reinterpret_cast<GameStateSaveView*>(gs7);
            func_ov017_0218b5b0();
            GrottoSave grotto;
            VectorizedInvertedMemcpy(view7->grottoLarge, grotto.largeBuffer, sizeof(grotto.largeBuffer));
            VectorizedInvertedMemcpy(view7->grottoBits, grotto.bits, sizeof(grotto.bits));
            grotto.flags = view7->grottoFlags;
            if (gs7->GetGrottoStruct()->unknown_0[3]) {
                grotto.flags |= 1;
            }
            func_02075acc((char*)&body->grotto - base, &grotto, sizeof(grotto), 0);
        }
    } else if ((flags & 0x10) && mode == 0) {
        int i;
        int count;
        BattleData* battle8 = static_cast<BattleData*>(GetPtrField0x2a04_02010828(GameState::GetInstance()));
        EntrySave entries;
        memset(&entries, 0, sizeof(entries));
        count = 0;
        for (i = 0; i < battle8->memberCount; i++) {
            Entry02087574* entry = FindEntryBySignedId02087574((EntryTable02087574*)battle8, battle8->members[i].entryId);
            if (entry != NULL) {
                memcpy(&entries.entries[count], entry, sizeof(Entry02087574));
                count++;
            }
        }
        if (count) {
            entries.valid = 1;
            entries.count = count;
        }
        func_02075acc((char*)&body->grotto - base, &entries, sizeof(entries), 0);
    }

    SaveFile* file = task->file;
    if (file != NULL) {
        body->checksum = CalcSaveChecksum(&file->body, sizeof(file->body));
        func_02075acc((char*)&body->checksum - base, body, sizeof(body->checksum), 0);
    }
    return 1;
}
