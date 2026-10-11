#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_ov017_021959b4(void);
extern "C" void* _Z26GetGlobalField0x1c020421a0v(void);
extern "C" int _Z17GetGlobal02109400v(void);
extern "C" void* func_0202ae18(void);
extern "C" char* _Z15GetFieldIfFlag4Pc(void* obj);
extern "C" unsigned short* func_02012fe4(void);
extern "C" void _Z25InitBattleIfListHasId0x1cPv(void* self);
extern "C" int _Z18CheckField0NonZeroPi(int* p);
extern "C" int func_0202c508(void* obj);
extern "C" void func_ov017_021cf730(int a, int b);
extern "C" void _Z15ClearIntAt0x23cPh(unsigned char* obj);
extern "C" void _Z21BlankFunction02094b30v(void* a, int b, int c);
extern "C" int _Z18AlwaysTrue02094b4cv(void* a);
extern "C" void func_020531f0(void* obj);
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(void* obj, int arg1);
extern "C" void _Z25ResetElapsedState020e11a4v(void);
extern "C" void func_02046380(void* global);
extern "C" int _Z28CallFunc020e0434With02153694i(int value);
extern "C" void func_0204500c(void* global, void* entry, int a, int b);
extern "C" int func_020457e0(void* global);
extern "C" void func_ov017_021ab860(short value, int flag);
extern "C" void _Z19InitContext020e1154Pv(void* obj);
extern "C" void _Z24ReinitController02043204Pc(char* obj);
extern "C" void _Z17SetByteField0x253Pv(void* obj);
extern "C" void _Z28InitBattleAndControllerStatePv(void* self);
extern "C" int _Z22IsValueInRange0201b5d8i(int x);

struct Obj020d9870 {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char pad2[0x8 - 0x2];
    unsigned char state;
};

// USA: func_020d9870
extern "C" ARM void func_020d9870(struct Obj020d9870* self) {
    GameState* gs = GameState::GetInstance();
    func_ov017_0218b5b0();
    void* unkObj = gs->GetUnknownGameObject();
    void* g1c = _Z26GetGlobalField0x1c020421a0v();
    int g = _Z17GetGlobal02109400v();
    void* t = func_0202ae18();
    char* f4 = _Z15GetFieldIfFlag4Pc(gs);
    unsigned short* p = func_02012fe4();

    if (func_ov017_021959b4() != 0) {
        _Z25InitBattleIfListHasId0x1cPv(self);
        return;
    }

    if (self->state == 0) {
        if (_Z18CheckField0NonZeroPi((int*)t) != 0 && func_0202c508(t) != 0) {
            func_ov017_021cf730(-1, 0);
        }
        _Z15ClearIntAt0x23cPh((unsigned char*)f4);
        self->state = 1;
    } else if (self->state == 1) {
        _Z21BlankFunction02094b30v((void*)g, 0x20e, 0);
        self->state = 2;
    } else if (self->state == 2) {
        if (_Z18AlwaysTrue02094b4cv((void*)g) != 0) {
            self->state = 3;
        }
    } else if (self->state == 3) {
        if (unkObj != NULL) {
            func_020531f0(unkObj);
            _Z27CancelPendingAction020397ccP11Obj020397cci(unkObj, 1);
        }
        _Z25ResetElapsedState020e11a4v();
        func_02046380(g1c);
        func_0204500c(g1c, (void*)_Z28CallFunc020e0434With02153694i(0x3e), 0, 0xe3);
        *(unsigned char*)((char*)g1c + 0x19b2) = 0;
        *(int*)((char*)g1c + 0x998) = 1;
        self->state = 4;
    } else if (self->state == 4) {
        if (*(int*)((char*)g1c + 0x998) == 0) {
            if (func_020457e0(g1c) == 0) {
                func_ov017_021ab860(*(short*)((char*)unkObj + 4), 1);
                _Z19InitContext020e1154Pv((void*)0xbb8);
            }
            _Z24ReinitController02043204Pc((char*)g1c);
            self->state = 5;
        }
    } else if (self->state == 5) {
        _Z17SetByteField0x253Pv(unkObj);
        _Z28InitBattleAndControllerStatePv(self);
    }

    if (_Z22IsValueInRange0201b5d8i(*p) != 0) {
        return;
    }
    _Z28InitBattleAndControllerStatePv(self);
}
