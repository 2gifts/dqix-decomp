#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"
#include <globaldefs.h>

struct Obj0205eaa0;
struct Obj02048350;
void *SearchBothTables02079e2c(char *p, int key);
GameObject *GetCombatantChecked_0200ff94(GameState *gs, int id);
extern "C" int *func_0202ae18(void);
extern "C" void *__clear(void *dst, int count);
int CopyOutRegion0x571d_020114ec(char *dst, void *src);
void ConsumeCounter02048350(struct Obj02048350 *p, int a);
int CheckField0NonZero_0202b7d8(int *p);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0 *p, int a, int b);
void InitStateArray02157ce0(char *p);
extern "C" void func_ov002_021536e0(void *p);
extern "C" int func_ov002_021536ec(void *a, void *b, int c);
extern "C" void func_ov016_0218b5c0(int a, int b);
extern "C" void func_ov017_021c9e00(signed char a, int b, int c, int d);
extern "C" int data_02108760;

struct TableEntry021594e8 {
    char *name;
    int unk4;
    unsigned int lo8 : 8;
    unsigned int b8 : 2;
    unsigned int b10 : 2;
    unsigned int rest : 20;
};
struct StateSlot021594e8 {
    unsigned char a[4];
    unsigned char active;
    unsigned char pad;
};
struct StateArray021594e8 {
    short id;
    signed char actor;
    unsigned char count;
    signed char ids[4];
    struct StateSlot021594e8 first[4];
    struct StateSlot021594e8 second[4];
    int tail;
};
struct Menu021594e8 {
    char pad0[0x1bb8];
    int state;
    int nextState;
    char pad1bc0[0x1c26 - 0x1bc0];
    short command;
    short msgId;
    short msgId2;
};

// USA: func_ov002_021594e8
extern "C" ARM void func_ov002_021594e8(struct Menu021594e8 *p, short cmd, signed char actor, int target) {
    struct StateArray021594e8 st;
    struct StateArray021594e8 st2;
    unsigned char buf[4];
    void *ctx;
    void *ctx2;

    p->command                        = cmd;
    GameState *gs                     = GameState::GetInstance();
    ActionDataTables* tbl                         = GetData02108e10_020797dc();
    struct TableEntry021594e8 *entryA = (struct TableEntry021594e8 *) SearchBothTables02079e2c((char*)tbl, p->command);
    GameObject *comb                  = GetCombatantChecked_0200ff94(gs, actor);
    int *checkPtr                     = func_0202ae18();
    int flagA                         = 0;
    if (p->state == 0x17) {
        p->msgId  = 0x232d;
        p->msgId2 = 0x232b;
        int res   = 0;
        if (p->command == 0x22) {
            InitStateArray02157ce0((char *) &st);
            InitStateArray02157ce0((char *) &st);
            struct TableEntry021594e8 *entry = (struct TableEntry021594e8 *) SearchBothTables02079e2c((char*)tbl, p->command);
            if (entry != NULL) {
                __clear(buf, 4);
                int n = CopyOutRegion0x571d_020114ec((char *) gs, buf);
                if (entry->b10 & 1) {
                    st.id    = p->command;
                    st.actor = actor;
                    st.count = n;
                    for (int i = 0; i < n; i++) {
                        st.ids[i] = buf[i];
                    }
                    func_ov002_021536e0(&ctx);
                    ctx = tbl;
                    res = func_ov002_021536ec(&ctx, &st, 0);
                }
            }
        } else {
            struct TableEntry021594e8 *entry = (struct TableEntry021594e8 *) SearchBothTables02079e2c((char*)tbl, p->command);
            if (entry != NULL && (entry->b10 & 1)) {
                func_ov016_0218b5c0(res, -1);
                InitStateArray02157ce0((char *) &st2);
                InitStateArray02157ce0((char *) &st2);
                st2.id     = p->command;
                st2.actor  = actor;
                st2.count  = 1;
                st2.ids[0] = target;
                func_ov002_021536e0(&ctx2);
                ctx2 = tbl;
                res  = func_ov002_021536ec(&ctx2, &st2, res);
            }
        }
        if (res != 0) {
            if (p->command == 0x1f || p->command == 0x1e || p->command == 0x20 || p->command == 0x21) {
                p->msgId2 = 0x2339;
                flagA     = 1;
            } else if (p->command == 0x23) {
                p->msgId2 = 0x794c;
                flagA     = 1;
            } else if (p->command == 0x22) {
                p->msgId2 = 0x2339;
                flagA     = 1;
            }
        }
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0 *) &data_02108760, 0x64, 0);
        p->state     = 0x26;
        p->nextState = 0x17;
    }
    if (flagA != 0) {
        ConsumeCounter02048350((struct Obj02048350 *) comb, entryA->lo8);
        if (CheckField0NonZero_0202b7d8(checkPtr) != 0) {
            func_ov017_021c9e00(actor, 0, 0, 1);
        }
    }
}
