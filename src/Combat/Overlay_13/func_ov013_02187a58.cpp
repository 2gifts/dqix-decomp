#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct SkillEntry02187a58 {
    short id;
    unsigned short low : 2;
    unsigned short points : 7;
    unsigned short kind : 7;
    const char* name;
    const char* prefix;
    SkillEntry02187a58* next;
};
struct SkillSortEntry02187a58 {
    int id;
    float points;
};
extern "C" SkillEntry02187a58* func_0208e934(void* list, int kind, int index);
extern "C" SkillEntry02187a58* func_0208e97c(void* list, int id);
int GetTableByte020dd11c(unsigned int, unsigned int);
int GetFieldAt0x150(unsigned char*);
struct TableA68;
void* FindEntryByKey(TableA68*, int);
int StringLength(const char*);
extern "C" void __clear(void*, int);
extern "C" void func_02050678(void*, short, short, const char*, int, unsigned char, short*, short*);
extern "C" void func_020749ac(void*, int, int, int);
extern char data_ov013_02188e2b[];
extern char data_ov013_02188e56[];
extern char data_ov013_02188e61[];
extern char data_ov013_02188e64[];

// USA: func_ov013_02187a58
extern "C" ARM void func_ov013_02187a58(void* self, void* canvas) {
    unsigned char* menu = (unsigned char*)self;
    if (!canvas) return;
    GameObject* combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), *(signed char*)(menu + 0x53));
    if (!combatant) return;
    int palette;
    unsigned char* stats = (unsigned char*)GetFieldAt0x150((unsigned char*)combatant);
    if (!stats) return;
    int kind = GetTableByte020dd11c(*(unsigned int*)(stats + 0x8b8) & 0xff, menu[0x54]);
    int availablePoints = (stats + kind)[0x464];
    int y = 30;
    const char* title = (const char*)FindEntryByKey((TableA68*)(menu + 4), kind);
    short width, height;
    SkillSortEntry02187a58 entries[10];
    char nameText[256];
    char pointsText[32];
    char suffix[16];

    func_02050678(canvas, (short)(128 - (StringLength(title) >> 2) * 10), 12, title, 10, 15, &width, &height);
    memset(entries, 0, sizeof(entries));
    for (unsigned char i = 0; i < 10; i++) {
        SkillSortEntry02187a58* sorted = &entries[i];
        SkillEntry02187a58* skill = func_0208e934(menu + 0xc, kind, i);
        if (skill) {
            sorted->id = skill->id;
            sorted->points = skill->points;
        }
    }
    func_020749ac(entries, 0, 9, 0);
    for (unsigned char i = 0; i < 10; i++) {
        palette = 3;
        SkillEntry02187a58* skill = func_0208e97c(menu + 0xc, (short)entries[i].id);
        if (skill) {
            int points = skill->points;
            if (availablePoints >= points) palette = 15;
            __clear(pointsText, sizeof(pointsText));
            sprintf(pointsText, data_ov013_02188e2b, points);
            int pointsX = 33;
            if ((unsigned int)points < 100) pointsX += 10;
            if ((unsigned int)points < 10) pointsX += 10;
            func_02050678(canvas, (short)pointsX, (short)y, pointsText, 10, (unsigned char)palette, &width, &height);
            __clear(nameText, sizeof(nameText));
            sprintf(nameText, data_ov013_02188e56, skill->prefix, skill->name);
            char* plus = strstr(nameText, data_ov013_02188e61);
            if (plus) {
                int length = strlen(plus);
                __clear(suffix, sizeof(suffix));
                memcpy(suffix, plus, length + 1);
                memcpy(plus, data_ov013_02188e64, 18);
                memcpy(plus + 18, suffix, length + 1);
            }
            func_02050678(canvas, 84, (short)y, nameText, 10, (unsigned char)palette, &width, &height);
            y += 15;
        }
    }
}
#else
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Node02187a58 {
    short id;
    unsigned short pad : 2;
    unsigned short level : 7;
    unsigned short kind : 6;
    unsigned short high : 1;
    int field4;
    struct Node02187a58* next;
};

struct List0208e024;
struct List0208e06c;
struct TableA68;

ARM struct Node02187a58* FindNthNodeByKind0208e024(struct List0208e024* list, int kind, int index);
ARM struct Node02187a58* FindNodeById0208e06c(struct List0208e06c* list, int id);
ARM void* FindEntryByKey(struct TableA68* table, int key);
ARM int GetTableByte020dd11c(unsigned int a, unsigned int b);
int GetFieldAt0x150(unsigned char* obj);
void* GetGlobalField0x1c020421a0(void);

extern "C" void __clear(void* buf, int n);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" float _ffltu(unsigned int v);
extern "C" int func_020420e8(void* p, int flag);
extern "C" void func_0204f41c(void* ctx, short x, short y, void* str, int size,
                              unsigned char palette, short* outA, short* outB, int flag);
extern "C" void func_020749ac(void* arr, int lo, int hi, int mode);
extern "C" void func_02046608(void* g, int a, int b, void* dst, int cap, int e, int f);
extern "C" void func_020e4864(void* src, void* dst, int a, int b, int c, int d);

extern signed char data_ov013_02187dc8[];
extern char data_ov013_02187ec3;

struct Entry02187a58 {
    int id;
    float weight;
};

// USA: func_ov013_02187a58
extern "C" ARM void func_ov013_02187a58(void* self, void* ctx) {
    unsigned char* obj = (unsigned char*)self;
    if (ctx == 0) {
        return;
    }

    GameObject* combatant =
        GetCombatantWithFlag0x100(GameState::GetInstance(), *(signed char*)(obj + 0x67));
    if (combatant == 0) {
        return;
    }

    int palette;
    unsigned char* field = (unsigned char*)GetFieldAt0x150((unsigned char*)combatant);
    if (field == 0) {
        return;
    }

    int kind = GetTableByte020dd11c(*(unsigned int*)(field + 0x950) & 0xff, obj[0x68]);
    int cap = (field + kind)[0x464];
    int y = 0x1e;
    void* label = FindEntryByKey((struct TableA68*)(obj + 4), kind);

    short outA;
    short outB;
    char text[0x20];
    struct Entry02187a58 entries[10];
    char rawBuf[0x100];
    char nameBuf[0x100];

    func_0204f41c(ctx, (short)((0x100 - func_020420e8(label, 0)) >> 1), 0xc, label,
                  0xa, 0xf, &outA, &outB, 0);

    memset((void*)entries, (int)(0), (unsigned int)(0x50));
    for (unsigned char i = 0; i < 10; i++) {
        struct Entry02187a58* e = &entries[i];
        struct Node02187a58* n = FindNthNodeByKind0208e024((struct List0208e024*)(obj + 0xc), kind, i);
        if (n != 0) {
            e->id = n->id;
            e->weight = _ffltu(n->level);
        }
    }
    func_020749ac(entries, 0, 9, 0);

    struct Node02187a58* first =
        FindNodeById0208e06c((struct List0208e06c*)(obj + 0xc), (short)entries[0].id);
    int k = 0;
    while (data_ov013_02187dc8[k] >= 0) {
        if (data_ov013_02187dc8[k] == first->kind) {
            obj[0x6a] = (unsigned char)k;
            break;
        }
        k++;
    }

    for (unsigned char j = 0; j < 10; j++) {
        palette = 3;
        struct Node02187a58* n =
            FindNodeById0208e06c((struct List0208e06c*)(obj + 0xc), (short)entries[j].id);
        if (n != 0) {
            int level = n->level;
            if (cap >= level) {
                palette = 0xf;
            }
            __clear(text, 0x20);
            sprintf(text, &data_ov013_02187ec3, level);
            func_0204f41c(ctx, (short)(0x22 - func_020420e8(text, 0)), (short)y, text,
                          0xa, (unsigned char)palette, &outA, &outB, 0);

            __clear(rawBuf, 0x100);
            __clear(nameBuf, 0x100);
            func_02046608(GetGlobalField0x1c020421a0(), 0xa, n->field4, rawBuf, 0x100, 0, 0);
            func_020e4864(rawBuf, nameBuf, 1, 0, 0, 0);

            if (n->high != 0 && *(signed char*)(obj + 0x6a) >= 0) {
                (*(short**)(obj + 0x50))[j] = (short)(func_020420e8(nameBuf, 0) + 0x2e);
                (*(short**)(obj + 0x54))[j] = (short)(y - 2);
                if (palette == 0xf) {
                    (*(unsigned char**)(obj + 0x58))[j] = 1;
                }
            }

            func_0204f41c(ctx, 0x2e, (short)y, nameBuf, 0xa, (unsigned char)palette, &outA, &outB, 0);
            y += 0xf;
        }
    }
}
#endif
