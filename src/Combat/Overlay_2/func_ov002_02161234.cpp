#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"
#include <globaldefs.h>

struct Container020e0310;
struct Obj02046574;
struct StoreStruct;
struct Src020e4e38;

struct Pair02161234 {
    char *a;
    char *b;
    int c;
};

struct Obj12_02161234 {
    int f0;
    int f4;
    int f8;
};

char *GetFieldByKey020e0434(struct Container020e0310 *c, int key);
char *GetGlobalField0x1c020421a0();
extern "C" void func_02046380(void *messages);
void SetIndexedName02046574(struct Obj02046574 *obj, int index, char *str);
void *Clear12Bytes020e46c4(void *p);
extern "C" void *__clear(void *dst, int count);
void InitObjFromCombatantId020e4bf4(void *obj, int combatantId);
void StoreInArray0x8b0(StoreStruct *messages, int index, int value);
void *GetData02108e10(void);
void *SearchBothTables02079e2c(char *p, int key);
void InitObjFromPackedFields020e4e38(void *obj, struct Src020e4e38 *src);
unsigned char GetField0x397cValue(GameState *battleStruct);
void Zero4Bytes(void *reader);
void TryInvoke020e53bc(void *reader, int file, int size);
void *CallFunc020e52a0(void *p, int key);
extern "C" void func_020e4f18(void *src, void *dst, int n);
extern "C" void func_02046608(void *messages, int a, const char *format, char *output, int size, int b, int c);
int AppendString02042058(char *dst, const char *src);
int StringLength(const char *s);

extern "C" char data_ov002_0216d2bc[];
extern "C" char data_ov002_0216d2d2[];
extern "C" char data_ov002_0216d2e4[];
extern "C" char data_ov002_0216d2ea[];

static inline int InParty02161234(int i) {
    return (i >= 0 && i <= 3) ? 1 : 0;
}

// USA: func_ov002_02161234
extern "C" ARM void func_ov002_02161234(char *self, char *dst) {
    char buf1[0x80];
    char buf2[0x80];
    char buf3[0x80];
    char buf4[0x80];
    Obj12_02161234 name1;
    Obj12_02161234 name2;
    Pair02161234 pa;
    Pair02161234 pb;
    Obj12_02161234 packed;
    Obj12_02161234 table;
    unsigned int size;
    if (dst == 0) {
        return;
    }
    GetFieldByKey020e0434((struct Container020e0310 *) (self + 0x20), 0x270e);
    GameState *gs = GameState::GetInstance();
    char *msgs    = GetGlobalField0x1c020421a0();
    func_ov017_0218b5b0();
    func_02046380(msgs);
    char *name;
    short sel;
    short key = *(short *) (self + 0x1c28);
    int sub;
    GameObject *u = gs->GetUnknownGameObject();
    if (u != 0) {
        SetIndexedName02046574((struct Obj02046574 *) msgs, 4, *(char **) ((char *) u + 0x134));
    }
    sel = *(signed char *) (self + 0x1c20);
    sub = *(signed char *) (self + 0x1c21);
    Clear12Bytes020e46c4(&pa);
    Clear12Bytes020e46c4(&pb);
    __clear(buf1, 0x80);
    __clear(buf2, 0x80);
    __clear(buf3, 0x80);
    __clear(buf4, 0x80);
    pa.a = buf1;
    pa.b = buf2;
    pb.a = buf3;
    pb.b = buf4;
    InitObjFromCombatantId020e4bf4(&name1, sel);
    InitObjFromCombatantId020e4bf4(&name2, sub);
    *(void **) (msgs + 0)    = &name1;
    *(void **) (msgs + 0x10) = &name2;
    if (InParty02161234(sub)) {
        int k = *(signed char *) (self + 0x1c20);
        if (k == 4) {
            k = 9;
        }
        StoreInArray0x8b0((StoreStruct *) msgs, 9, (k + 1) * 10 + sub);
    }
    if (*(short *) (self + 0x1c26) != -1) {
        if (InParty02161234(sel)) {
            name          = (char *) func_ov017_0218b5b0() + 0x435c + sel * 0x30;
            GameObject *m = gs->GetPartyMemberByIndex(sel);
            if (m != 0) {
                name = *(char **) ((char *) m + 0x134);
            }
            SetIndexedName02046574((struct Obj02046574 *) msgs, 0, name);
        }
        char **p = (char **) SearchBothTables02079e2c((char *) GetData02108e10(), *(short *) (self + 0x1c26));
        if (*p != 0) {
            name = *p;
        }
        SetIndexedName02046574((struct Obj02046574 *) msgs, 1, name);
        InitObjFromPackedFields020e4e38(&packed, (struct Src020e4e38 *) p);
        *(void **) (msgs + 8) = &packed;
        if (InParty02161234(sub)) {
            SetIndexedName02046574((struct Obj02046574 *) msgs, 2, self + 0x1ab0 + sub * 0x3c);
        }
        for (int i = 0; i < 2; i++) {
            StoreInArray0x8b0((StoreStruct *) msgs, i, *(int *) (self + i * 4 + 0x2490));
        }
    } else {
        if (InParty02161234(sel)) {
            name          = (char *) func_ov017_0218b5b0() + 0x435c + sel * 0x30;
            GameObject *m = gs->GetPartyMemberByIndex(sel);
            if (m != 0) {
                name = *(char **) ((char *) m + 0x134);
            }
            SetIndexedName02046574((struct Obj02046574 *) msgs, 0, name);
            StoreInArray0x8b0((StoreStruct *) msgs, 0, 1);
        } else if (*(signed char *) (self + 0x1c20) == 4) {
            StoreInArray0x8b0((StoreStruct *) msgs, 0, 0);
            InitObjFromCombatantId020e4bf4(&name1, GetField0x397cValue(gs));
        }
        BackgroundLoader::AddLockGlobal();
        void *file = ExtractFileFromGP2(data_ov002_0216d2bc, data_ov002_0216d2d2, &size);
        Zero4Bytes(&table);
        TryInvoke020e53bc(&table, (int) file, size);
        void *ea = CallFunc020e52a0(&table, *(short *) (self + 0x1c22));
        void *eb = CallFunc020e52a0(&table, *(short *) (self + 0x1c24));
        if (ea != 0) {
            func_020e4f18(ea, &pa, 3);
            *(void **) (msgs + 0x18) = &pa;
        }
        if (eb != 0) {
            func_020e4f18(eb, &pb, 3);
            *(void **) (msgs + 0x1c) = &pb;
        }
        if (sub == 4) {
            InitObjFromCombatantId020e4bf4(&name2, GetField0x397cValue(gs));
        }
        BackgroundLoader::RemoveLockGlobal();
    }
    func_02046608(msgs, 0xc, GetFieldByKey020e0434((struct Container020e0310 *) (self + 0x20), *(short *) (self + 0x1c28)),
                  dst, 0xe3, 0, 1);
    AppendString02042058(dst, *(char **) (self + 0x1bdc));
    int len   = StringLength(dst);
    char *fmt = GetFieldByKey020e0434((struct Container020e0310 *) (self + 0x20), *(short *) (self + 0x1c2a));
    if (fmt != 0) {
        func_02046608(msgs, 0xc, fmt, dst + len, 0xe3, 0, 1);
    }
    *(short *) (self + 0x1c18) = StringLength(dst);
    int flag                   = 1;
    if (*(int *) (self + 0x1bbc) == 0x11 && key == 0x232b) {
        flag = 0;
    }
    if (*(int *) (self + 0x1bbc) == 0x17) {
        AppendString02042058(dst, data_ov002_0216d2e4);
        return;
    }
    if (flag && (key == 0x2367 || key == 0x2365 || key == 0x236f || key == 0x2372 || key == 0x238d || key == 0x125c ||
                 key == 0x125d || key == 0x125e || key == 0x232b || key == 0x797c || key == 0x2371))
    {
        if (*(short *) (self + 0x1c26) == 0xd5 && key == 0x232b) {
            AppendString02042058(dst, data_ov002_0216d2ea);
        } else {
            AppendString02042058(dst, data_ov002_0216d2e4);
        }
    } else {
        AppendString02042058(dst, data_ov002_0216d2ea);
    }
}
