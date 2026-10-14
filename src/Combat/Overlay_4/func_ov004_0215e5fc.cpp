#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
struct BattleStruct {
    int unk0;
    int unk4;
    struct CombatantStruct* combatantList[0xe9];
};
struct CombatantStruct {
    unsigned short flags;
    char unk[0x132];
    struct BaseCombatStats* baseStats;
    struct ModifiableCombatStats* currentStats;
};

struct Container020dedd0;
struct Element020de650;

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov004_0215e47c(void*, int);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" short func_ov023_021f6f10(void*);
extern "C" void func_ov023_021f809c(void*, void*);
void* CheckNodeState6_0215e4c0(void*, int);
void SetOffset100Fields_021f8960(char*, short, unsigned short);
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0*, int);
extern "C" void func_02083738(void*, int);
extern "C" void func_0208358c(void*, void*, int);
extern "C" int func_02046608(int, int, void*, void*, int, int, int);
extern "C" void func_02083e28(void*, int);
int GetGlobalField0x1c020421a0(void);
int GetFieldAt0x150(unsigned char*);
char* FindSubstring(char*, char*);

struct Triple0215e5fc { int a, b, c; };

class Node0215e5fc {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Apply(struct Triple0215e5fc*);
    virtual struct Triple0215e5fc Get();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void SetMode(int);
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void* GetContainer();

    char pad04[8];
    unsigned char f0c;
    char pad0d[0x13];
    char* f20;
    char pad21[0x21];
    unsigned char f45;
};

struct Elem0215e5fc {
    void** v0;
    char* f04;
    char pad08[0x10];
    short f18;
};

struct VtblBits0215e5fc { unsigned int :7; unsigned int f :4; };

extern int data_ov004_0216fe3c[];
extern unsigned char data_ov004_0216fdfc[];
extern char data_ov004_021707e8[];
extern char* data_ov004_021704a4[8][4];
extern short data_ov004_02170818[];
extern unsigned char data_ov004_02170814[];
extern short data_ov004_02170888[][4];
extern char data_ov004_02170524[];
extern char data_ov004_02170525[];

// USA: func_ov004_0215e5fc
extern "C" ARM void func_ov004_0215e5fc(void* a, int idx) {
    struct Element020de650* el;
    void* A = func_ov011_021849c8(a);
    char* p488;
    short key;
    int i;
    struct GameState* gs = GameState::GetInstance();
    int found = 0;
    char* prot;
    int flag;
    int key2;
    int v2;
    void* c;
    void* combatant = GetCombatantWithFlag0x100(gs, idx);
    if (combatant != 0) {
        prot = (char*)GetFieldAt0x150((unsigned char*)combatant);
        Node0215e5fc* node = (Node0215e5fc*)func_ov004_0215e47c(a, 0x81);
        if (node != 0) {
            c = node->GetContainer();
            if (c != 0) {
                p488 = prot + 0x488;
                for (i = 0; i < 8; i++) {
                    key = *(short*)(p488 + data_ov004_0216fe3c[i] * 2);
                    if (key == data_ov004_02170888[i][idx] && data_ov004_0216fdfc[i] != 1) continue;
                    found = 1;
                    el = (struct Element020de650*)FindElementByKey020dedd0((struct Container020dedd0*)c, key);
                    if (el == 0) {
                        flag = data_ov004_0216fdfc[i];
                        func_02083738(prot, flag);
                        data_ov004_02170888[i][idx] = -1;
                        if (key < 0 && i == 0) {
                            data_ov004_02170818[idx] = 0xe;
                        }
                        key2 = -1;
                        v2 = -1;
                        if (flag == 2) {
                            key2 = 1000;
                            v2 = 0;
                        }
                        void* el2 = FindElementByKey020dedd0((struct Container020dedd0*)c, key2);
                        if (el2 != 0) {
                            func_0208358c(prot, el2, v2);
                        }
                        data_ov004_02170814[idx] = 0;
                    } else {
                        char* buf = *(char**)(data_ov004_021707e8 + 0x18) + (i + idx * 8) * 0x80;
                        memset(buf, 0, 0x80);
                        func_02046608(GetGlobalField0x1c020421a0(), 0, ((struct Elem0215e5fc*)el)->f04, buf, 0x60, 0, 0);
                        func_0208358c(prot, el, -1);
                        data_ov004_02170888[i][idx] = ((struct Elem0215e5fc*)el)->f18;
                        data_ov004_021704a4[i][idx] = buf;
                        if (i == 0) {
                            short s = ((struct VtblBits0215e5fc*)((struct Elem0215e5fc*)el)->v0)->f;
                            if (s == 0) s = 0xe;
                            data_ov004_02170818[idx] = s;
                        }
                        if (i == 1) {
                            data_ov004_02170814[idx] = 0;
                            if (((struct Elem0215e5fc*)el)->f18 != -1) {
                                data_ov004_02170814[idx] = 1;
                            }
                        }
                    }
                }
                if (found) {
                    func_02083e28(prot, 0);
                }
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        Node0215e5fc* n = (Node0215e5fc*)func_ov023_021f6880(A, i + 0xfa);
        if (n == 0) continue;
        if (func_ov023_021f6f10(n) != 8) continue;
        short v = data_ov004_02170888[i][idx];
        if (v < 10000 || (v >= 14000 && v < 15000)) {
            n->f20 = data_ov004_02170524;
            Node0215e5fc* n2 = (Node0215e5fc*)func_ov023_021f6880(A, i + 0x141);
            if (n2 != 0) {
                n2->f0c &= ~8;
                n2->SetMode(3);
            }
        } else {
            char* buf = data_ov004_021704a4[i][idx];
            struct Triple0215e5fc t = n->Get();
            int off = (i * 20) << 12;
            if (FindSubstring(buf, data_ov004_02170525)) {
                off -= 0x5000;
            }
            t.b = off + 0x15000;
            n->Apply(&t);
            n->f20 = buf;
            n->f45 |= 0x80;
            n->SetMode(0xf);
            Node0215e5fc* n2 = (Node0215e5fc*)func_ov023_021f6880(A, i + 0x141);
            if (n2 != 0) {
                n2->f0c |= 8;
            }
        }
    }
    Node0215e5fc* nn = (Node0215e5fc*)CheckNodeState6_0215e4c0(a, 4);
    SetOffset100Fields_021f8960((char*)nn, 0, 0xffff);
    func_ov023_021f809c(nn, a);
}
