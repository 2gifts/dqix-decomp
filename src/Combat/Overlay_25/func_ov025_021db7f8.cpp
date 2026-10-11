#if defined(jpn)
enum {regionalOffset0=0x218, regionalOffset1=0x21c, regionalOffset2=0xe0c, regionalOffset3=0xe14, regionalOffset4=0x71ec, regionalOffset5=0x17ee};
#else
enum {regionalOffset0=0x29c, regionalOffset1=0x2a0, regionalOffset2=0xe90, regionalOffset3=0xe98, regionalOffset4=0x6ffc, regionalOffset5=0x19be};
#endif
#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov000_0215e9fc(void* party, short* buf, int max, int start);
extern "C" int func_ov000_0215ec1c(void* party, short* buf, int max, int start);
void SetSubstructWord0x68(unsigned char* obj, int value);
extern "C" void _Z23SetOrInitField_02182498Pvi(void* obj, int flag);
extern "C" void _Z19SetFlag320_02195530Ph(unsigned char* obj);
extern "C" unsigned char* _Z26GetGlobalField0x1c020421a0v();

struct StatusNibbles_021db7f8 {
    unsigned char lo : 4;
    unsigned char hi : 4;
};

struct BattleCtrl_021db7f8 {
    char pad0[regionalOffset0];
    void* party;
    char pad2a0[regionalOffset2 - regionalOffset1];
    unsigned char fieldE90;
    char padE91[3];
    int fieldE94;
    char padE98[regionalOffset4 - regionalOffset3];
    char field6ffc[4];
};

// JPN: func_ov025_021dc0f4
// USA: func_ov025_021db7f8
extern "C" ARM void func_ov025_021db7f8(BattleCtrl_021db7f8* obj) {
    GameState* bs = GameState::GetInstance();
    short buf[16];
    int n = 0;
    n = n + func_ov000_0215e9fc(obj->party, buf, 0x10, n);
    n = n + func_ov000_0215ec1c(obj->party, buf + n, 0x10 - n, 0);
    short* p = buf;
    for (int i = 0; i < n; i++, p++) {
        GameObject* c = bs->GetCombatantByIndex(*p);
        if (c) {
            StatusNibbles_021db7f8* s = (StatusNibbles_021db7f8*)((char*)c + 0xc1);
            if (s->hi == 1 || s->hi == 6) {
                s->hi = 0;
            }
            SetSubstructWord0x68((unsigned char*)c, 0);
        }
    }
    _Z23SetOrInitField_02182498Pvi(obj->field6ffc, 1);
    _Z19SetFlag320_02195530Ph((unsigned char*)func_ov017_0218b5b0());
    _Z26GetGlobalField0x1c020421a0v()[regionalOffset5] = 0;
    obj->fieldE90 = 0;
    obj->fieldE94 = 0;
}
