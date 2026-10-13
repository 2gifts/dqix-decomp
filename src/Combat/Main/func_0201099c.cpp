#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Util/Random.h"
#include "Combat/ResourceScriptEntry.h"
#include "std_library_functions.h"

struct PackedTriple0201099c {
    unsigned int x : 10;
    unsigned int y : 10;
    unsigned int z : 10;
    unsigned int reserved : 2;
};

struct Appearance0201099c {
    short equipment[10];
    unsigned char gender : 1;
    unsigned char hairStyle : 3;
    unsigned char hairColor : 4;
    unsigned char face : 4;
    short voice;
    short height;
    short width;
};

struct CombatSelection {
    signed char selected : 6;
    unsigned char active : 1;
    unsigned char reserved : 1;
    unsigned char count : 4;
    unsigned char ready : 1;
    unsigned char mode : 3;
    unsigned char levels[13];
    unsigned char status[13];
    int experience[13];
    int current;
    unsigned short selectionMask;
    char pad56[2];
    PackedTriple0201099c triples[13][3];
    unsigned short skillPoints;
    unsigned char flags[27];
    unsigned char groupFlags[9];
    unsigned char commandFlags[36];
    unsigned char field13e;
    unsigned char cursor : 3;
    unsigned char capacity : 5;
    unsigned char name[12];
    PackedTriple0201099c vectors[4];
    unsigned int timer : 10;
    unsigned int timerLimit : 10;
    unsigned int reserved15c : 12;
    Appearance0201099c appearance;
    unsigned char history[0xc0];
};

struct GameState0201099c {
    unsigned char pad[0x3984];
    CombatSelection members[13];
    unsigned char memberCount;
};

struct RecruitTemplate0201099c {
    unsigned char pad0[8];
    unsigned char gender;
    unsigned char pad9;
    short voice;
    unsigned char padc[0x10];
    short equipment[10];
    unsigned char levels[13];
    unsigned char vocation;
    unsigned char count;
};

struct ResetFieldsStruct {
    RecruitTemplate0201099c* entries;
    short count;
    short f6;
    short f8;
    char pad0a[2];
    int fc;
    short f10;
    char pad12[2];
    int f14;
    short f18;
};

struct SkillUnlock0201099c {
    unsigned short skill;
    unsigned short level;
};

struct SkillTable0201099c {
    unsigned char header[0x10c];
    SkillUnlock0201099c rows[13][20];
    unsigned char tail[0x34];
};

struct Element020de650 {
    unsigned int v[8];
};

struct Container020dedd0 {
    unsigned short count;
    unsigned char pad[10];
    Element020de650* base;
    unsigned char pad2[4];
    unsigned char useBinarySearch;
};

struct CharacterProfile0201099c {
    char name[0x30];
    unsigned short stat6c;
    unsigned short stat6e;
    unsigned short stat70;
    unsigned short stat72;
};

struct CharacterRecord0201099c {
    PackedTriple0201099c base[4];
    unsigned char pad10[0x2c];
    CharacterProfile0201099c profile;
    unsigned char pad74[0x120];
    Element020de650 equipment[8];
    unsigned char pad294[0x6d0];
};

struct ShortPair0201099c {
    short a;
    short b;
};

struct IdPair0201099c {
    short ids[2];
};

struct SlotMap0201099c {
    unsigned char appearanceIndex;
    unsigned char recordIndex;
};

struct Struct020dfc40 {
    unsigned char data[0x18];
};

struct Container020e0310;
struct SetFlagBitStruct;
struct Struct020865b0;
struct SetBitArrayStruct020865b8;
struct Ctx0209a810 {
    int handle;
};

void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern "C" void _Z19TailForward02012da4P14AllocatorUnionPv(AllocatorUnion* alloc, void* data);
extern "C" void _Z26ResetAndReturnSelf020dfc2cPv(void* p);
extern "C" void _Z19ResetStruct020dfc40P14Struct020dfc40(Struct020dfc40* p);
extern "C" void _Z22ResetAndDetach020dfc6cP14Struct020dfc40(Struct020dfc40* p);
extern "C" void func_020dfec0(Struct020dfc40* table, SafeAllocator* alloc, void* data, unsigned int size);
void ResetStructFields(ResetFieldsStruct* s);
extern "C" void _Z32ForwardResetStructFields02089ddcP17ResetFieldsStruct(ResetFieldsStruct* s);
extern "C" void _Z39SetupHeaderAndRunBufferedScript02089de8PvS_PKc(void* param0, void* param1, const char* param2);
void* GetElementStride0x40(unsigned char* obj, int index);
extern "C" void func_02086404(CombatSelection* selection);
void SetFlagBitAndIndex(SetFlagBitStruct* s, int n);
extern "C" char* _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310* c, int key);
extern "C" void __clear(void* dst, unsigned int size);
extern "C" int func_020426bc(void* a, void* b, int flag);
extern "C" void _Z19ClearField00209a804Pi(int* p);
extern "C" void _Z33SetupAndRunBufferedScript0209a810P11Ctx0209a810Pv(Ctx0209a810* ctx, void* value);
int GetFieldAt0x50(Struct020865b0* p);
extern "C" void _Z21SetBitInArray020865b8P25SetBitArrayStruct020865b8i(SetBitArrayStruct020865b8* s, int n);
extern "C" void _Z22ZeroInitReturn020de824Pv(void* p);
extern "C" void _Z16ZeroInit020de848Pv(void* p);
extern "C" int func_020dea64(void* a, void* b, void* c, unsigned int d, const void* e, short f);
extern "C" void* _Z22Clear0x54Bytes0208247cPv(void* obj);
extern "C" void func_02082828(CharacterRecord0201099c* record);
extern "C" void func_02083cbc(void* dst, void* src, void* tail);
extern "C" Element020de650* _Z24FindElementByKey020dedd0P17Container020dedd0i(Container020dedd0* c, int key);
extern "C" void func_02083e28(void* a, int arg2);

extern AllocatorUnion data_02114e20;
extern char data_020ef08c[];
extern char data_020ef0a5[];
extern const IdPair0201099c data_020e6d64;
extern const ShortPair0201099c data_020e6d98[];
extern const char* data_020f2a38;
extern const char* data_020f2a30;
extern const char data_020e6d6c[];
extern const char data_020ef0b5[];
extern unsigned char data_0211e33c[];
extern const SlotMap0201099c data_020e6d74[];

static inline const ShortPair0201099c* GetBodySize0201099c(int index) {
    return &data_020e6d98[index];
}

static inline const SlotMap0201099c* GetSlotMap0201099c(int index) {
    return &data_020e6d74[index];
}

static inline unsigned short GetStat6c0201099c(const CharacterProfile0201099c* profile) {
    unsigned short value = profile->stat6c;
    return value;
}

static inline unsigned short GetStat6e0201099c(const CharacterProfile0201099c* profile) {
    unsigned short value = profile->stat6e;
    return value;
}

static inline unsigned short GetStat700201099c(const CharacterProfile0201099c* profile) {
    unsigned short value = profile->stat70;
    return value;
}

static inline unsigned short GetStat720201099c(const CharacterProfile0201099c* profile) {
    unsigned short value = profile->stat72;
    return value;
}

// USA: func_0201099c
extern "C" ARM void func_0201099c(GameState0201099c* gs) {
    SkillTable0201099c skills;
    ResourceScriptEntry entry;
    Random* rng = GetBTRandom();
    RecruitTemplate0201099c* t;
    CombatSelection* m;
    long i;
    int slot;
    unsigned char vocations[3];
    vocations[0] = NextRandomMax(rng, 4);
    vocations[1] = NextRandomMax(rng, 2) + 4;
    unsigned char parity = vocations[0] % 2 + vocations[1] % 2;
    if (parity == 0) {
        vocations[2] = 7;
    } else if (parity == 2) {
        vocations[2] = 6;
    } else {
        vocations[2] = NextRandomMax(rng, 2) + 6;
    }

    SafeAllocator nameAlloc;
    nameAlloc.ResetAllocatorPointer();
    nameAlloc.ResetAllocatorPointer();
    nameAlloc.CreateTypeA(AllocateAligned4(&data_02114e20, 0x5000), 0x5000);
    Struct020dfc40 names;
    _Z26ResetAndReturnSelf020dfc2cPv(&names);
    _Z19ResetStruct020dfc40P14Struct020dfc40(&names);
    BackgroundLoader::AddLockGlobal();
    unsigned int nameSize = 0;
    void* nameData = ExtractFileFromGP2(data_020ef08c, data_020ef0a5, &nameSize);
    if (nameData != NULL) {
        func_020dfec0(&names, &nameAlloc, nameData, nameSize);
    }
    BackgroundLoader::RemoveLockGlobal();

    IdPair0201099c used = data_020e6d64;
    ResetFieldsStruct templates;
    SafeAllocator scriptAlloc;
    scriptAlloc.ResetAllocatorPointer();
    scriptAlloc.ResetAllocatorPointer();
    scriptAlloc.CreateTypeA(AllocateAligned4(&data_02114e20, 0x800), 0x800);
    ResetStructFields(&templates);
    _Z39SetupHeaderAndRunBufferedScript02089de8PvS_PKc(&templates, &scriptAlloc, NULL);
    int templateCount = templates.count;

    for (i = 0; i < 3; i++) {
        t = (RecruitTemplate0201099c*)GetElementStride0x40((unsigned char*)&templates, vocations[i]);
        if (t == NULL) {
            break;
        }
        slot = -1;
        if (t->vocation == 1) {
            slot = 0;
        } else if (t->vocation == 4) {
            slot = 0;
        } else if (t->vocation == 2) {
            slot = 1;
        } else if (t->vocation == 3) {
            slot = 2;
        }
        if (slot < 0) {
            continue;
        }
        m = &gs->members[slot];
        func_02086404(m);
        m->selected = slot;
        m->active = 0;
        m->reserved = 0;
        m->count = t->count;
        Appearance0201099c* look = &m->appearance;
        look->voice = t->voice;
        look->hairStyle = NextRandomMax(rng, 8);
        look->hairColor = NextRandomMax(rng, 8);
        look->face = NextRandomMax(rng, 10);
        look->gender = t->gender;
        int size = look->gender * 5 + NextRandomMax(rng, 5);
        look->height = GetBodySize0201099c(size)->a;
        look->width = GetBodySize0201099c(size)->b;
        SetFlagBitAndIndex((SetFlagBitStruct*)m, t->vocation);
        for (int j = 0; j < 13; j++) {
            m->levels[j] = t->levels[j];
        }
        short nameBase = 20000;
        if (look->gender == 1) {
            nameBase += 1000;
        }
        short nameId;
        int found;
        do {
            found = 0;
            nameId = nameBase + NextRandomMax(rng, 101);
            for (int k = i - 1; k >= 0; k--) {
                if (nameId == used.ids[k]) {
                    found = 1;
                }
            }
        } while (found);
        used.ids[i] = nameId;
        char* nameStr = _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)&names, nameId);
        unsigned char nameBuf[12];
        __clear(nameBuf, sizeof(nameBuf));
        func_020426bc(nameStr, nameBuf, 1);
        memcpy(m->name, nameBuf, sizeof(nameBuf));
        short* equipment = m->appearance.equipment;
        for (int k = 0; k < 10; k++) {
            if (k == 2) {
                equipment[k] = NextRandomMax(rng, 10) + 0x233c;
            } else if (k == 3) {
                equipment[k] = NextRandomMax(rng, 10) + 0x2328;
            } else {
                equipment[k] = t->equipment[k];
            }
        }
        gs->memberCount++;
    }

    _Z32ForwardResetStructFields02089ddcP17ResetFieldsStruct(&templates);
    SignedAllocatorHeader* scriptHeader = scriptAlloc.GetSignedAllocator();
    scriptAlloc.Destroy();
    _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, scriptHeader);
    _Z22ResetAndDetach020dfc6cP14Struct020dfc40(&names);
    SignedAllocatorHeader* nameHeader = nameAlloc.GetSignedAllocator();
    if (nameHeader != NULL) {
        nameAlloc.Destroy();
        _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, nameHeader);
    }

    if (templateCount > 0) {
        CharacterRecord0201099c record;
        Ctx0209a810 ctx;
        _Z19ClearField00209a804Pi(&ctx.handle);
        _Z33SetupAndRunBufferedScript0209a810P11Ctx0209a810Pv(&ctx, &skills);
        for (int j = 0; j < gs->memberCount; j++) {
            m = &gs->members[j];
            unsigned char vocation = GetFieldAt0x50((Struct020865b0*)m);
            unsigned char level = m->levels[vocation];
            SkillUnlock0201099c* row = skills.rows[vocation];
            for (int k = 0; k < 20; k++) {
                if (level >= row[k].level && row[k].level != 0) {
                    _Z21SetBitInArray020865b8P25SetBitArrayStruct020865b8i((SetBitArrayStruct020865b8*)m, row[k].skill);
                }
            }
        }

        SafeAllocator itemAlloc;
        itemAlloc.ResetAllocatorPointer();
        itemAlloc.ResetAllocatorPointer();
        itemAlloc.CreateTypeA(AllocateAligned4(&data_02114e20, 0x13800), 0x13800);
        itemAlloc.Reset();
        Container020dedd0 items;
        _Z22ZeroInitReturn020de824Pv(&items);
        _Z16ZeroInit020de848Pv(&items);
        BackgroundLoader::AddLockGlobal();
        unsigned int itemSize = 0;
        void* itemData = ExtractFileFromGP2(data_020f2a38, data_020f2a30, &itemSize);
        if (itemData != NULL) {
            func_020dea64(&items, &itemAlloc, itemData, itemSize, data_020e6d6c, 8);
        }
        BackgroundLoader::RemoveLockGlobal();
        BackgroundLoader::AddLockGlobal();
        CharacterRecord0201099c* rec;
        for (int v = 0; v < 13; v++) {
            char path[0x19];
            unsigned int size;
            sprintf(path, data_020ef0b5, v);
            if (LoadFileIntoMemory(path, data_0211e33c, &size) != NULL) {
                ResourceScriptEntry* res = &entry;
                for (int j = 0; j < gs->memberCount; j++) {
                    m = &gs->members[j];
                    _Z22Clear0x54Bytes0208247cPv(res);
                    func_02082490(res, data_0211e33c, size, m->levels[v], 0);
                    m->experience[v] = res->initial.value0;
                    m->skillPoints += res->initial.value4High;
                    if (v == GetFieldAt0x50((Struct020865b0*)m)) {
                        rec = &record;
                        CharacterProfile0201099c* profile = &rec->profile;
                        func_02082828(rec);
                        func_02083cbc(rec, &entry, entry.variants);
                        short* equipment = m->appearance.equipment;
                        for (int k = 0; k < 8; k++) {
                            Element020de650* item = _Z24FindElementByKey020dedd0P17Container020dedd0i(&items, equipment[GetSlotMap0201099c(k)->appearanceIndex]);
                            if (item != NULL) {
                                memcpy(&record.equipment[GetSlotMap0201099c(k)->recordIndex], item, sizeof(Element020de650));
                            }
                        }
                        func_02083e28(&record, 0);
                        m->vectors[0].x = rec->base[0].x;
                        m->vectors[0].y = rec->base[0].y;
                        m->vectors[0].z = rec->base[0].z;
                        m->vectors[1].x = rec->base[1].x;
                        m->vectors[1].y = rec->base[1].y;
                        m->vectors[1].z = rec->base[1].z;
                        m->vectors[2].x = rec->base[2].x;
                        m->vectors[2].y = GetStat6c0201099c(profile);
                        m->vectors[2].z = GetStat6e0201099c(profile);
                        PackedTriple0201099c* current = &m->vectors[3];
                        current->x = GetStat6c0201099c(profile);
                        current->y = GetStat6e0201099c(profile);
                        current->z = GetStat700201099c(profile);
                        m->timer = GetStat720201099c(profile);
                        m->timerLimit = rec->base[3].x;
                    }
                }
            }
        }
        BackgroundLoader::RemoveLockGlobal();
        SignedAllocatorHeader* itemHeader = itemAlloc.GetSignedAllocator();
        itemAlloc.Destroy();
        _Z19TailForward02012da4P14AllocatorUnionPv(&data_02114e20, itemHeader);
    }
}
