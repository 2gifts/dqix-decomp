#include <globaldefs.h>
#include "GameState/GameState.h"

signed char GetFlagByte_021570f0(int idx);
extern "C" void* func_ov004_02156f04(void* a, int key);
extern "C" int func_020dcc98(int);

struct Struct021707d8_02159470 { char pad[8]; char* ptr; };
extern Struct021707d8_02159470 data_ov004_021707d8;

class VObj02159470 {
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
    virtual void v52(); virtual void v53();
    virtual void Handle(int v);
    int pad4[7];
    void* field0x20;
};

// USA: func_ov004_02159470  (semantic: DispatchFlagsWithCombatant_02159470)
extern "C" ARM int func_ov004_02159470(void* self) {
    GameState* battle = GameState::GetInstance();
    GetPtrField0x2a04_02010828(battle);
    char* ptr = data_ov004_021707d8.ptr;
    unsigned char count = (unsigned char)(*(short*)(ptr + 0x3a));
    int key = 0x322;
    for (unsigned char i = 0; i < count; key++, i++) {
        int idVal = GetFlagByte_021570f0(i);
        GameObject* c = battle->GetPartyMemberByIndex(idVal);
        if (!c) continue;
        VObj02159470* node = (VObj02159470*)func_ov004_02156f04(self, key);
        if (!node) continue;
        node->field0x20 = c->baseStats_;
        int v = func_020dcc98(idVal);
        node->Handle(v);
    }
    return 0;
}
