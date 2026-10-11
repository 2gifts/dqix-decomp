#include <globaldefs.h>
#include "GameState/GameState.h"

int DispatchNodeIfType7_02156e2c(void* a, int key);
void* GetEntryFor_021570a4(void* obj, int index);
extern "C" void* func_ov004_02156f38(void* a, int key);
struct Obj02086aec;
short SumCombatantKeyMatches02086aec(struct Obj02086aec* obj, int key);
extern "C" void* func_ov004_02156f6c(void* a, int key);
extern "C" void func_ov023_021f809c(void* obj, void* param2);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
int ScaleStatsIfType12_021f6f10(void* self);
struct Struct0200fb08;
int NormalizeField5_0200fb08(struct Struct0200fb08* s);

struct Args0215d384 { int a; int b; int c; };

class VObjA0215d384 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void MethodE0(int arg);
};

class VObjB0215d384 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06();
    virtual void Method1c(const Args0215d384& args);
};

// USA: func_ov004_0215d384
extern "C" ARM int func_ov004_0215d384(void* a) {
    GameState* bs = GameState::GetInstance();
    int idx = DispatchNodeIfType7_02156e2c(a, 0x5b);
    if (idx < 0) return 0;
    void* entry = GetEntryFor_021570a4(a, idx & 0xff);
    if (!entry) return 0;
    VObjA0215d384* nodeA = (VObjA0215d384*)func_ov004_02156f38(a, 0x1dc);
    if (!nodeA) return 0;

    int matches = SumCombatantKeyMatches02086aec((struct Obj02086aec*)GetPtrField0x2a04(bs), *(short*)entry);
    nodeA->MethodE0(matches);

    void* nodeC = func_ov004_02156f6c(a, 0x1b);
    if (nodeC) func_ov023_021f809c(nodeC, a);

#if !defined(jpn)
    VObjB0215d384* nodeB = (VObjB0215d384*)func_ov023_021f6880(func_ov011_021849c8(a), 0x1dd);
    if (!nodeB) return 0;
    if (ScaleStatsIfType12_021f6f10(nodeB) != 8) return 0;

    Args0215d384 args;
    args.b = 0x4000;
    args.c = 0;
    int kind = NormalizeField5_0200fb08((struct Struct0200fb08*)bs);
    switch (kind) {
    case 1: args.a = 0x14000; nodeB->Method1c(args); break;
    case 2: args.a = 0xe000; nodeB->Method1c(args); break;
    case 3: args.a = 0xb000; nodeB->Method1c(args); break;
    case 4: args.a = 0x6000; nodeB->Method1c(args); break;
    case 5: args.a = 0x9000; nodeB->Method1c(args); break;
    default: break;
    }
#endif
    return 0;
}
