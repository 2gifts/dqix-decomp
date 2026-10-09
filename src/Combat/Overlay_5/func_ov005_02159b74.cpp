#include <globaldefs.h>
#include <GameState/GameState.h>

struct Obj0205eaa0;

struct YesNoLabel {
    char unk_0[0x39];
    unsigned char palette_;
};

struct YesNoWindow {
    char unk_0[0xc];
    YesNoLabel* label_;
    unsigned char* panel_;

    YesNoLabel* GetLabel() { return label_; }
};

struct EquipmentMenu {
    char unk_0[0xe64];
    YesNoWindow* yesNo_;
};

extern int data_02108760;

extern "C" void _Z26ResetAndReposition020e280cP11Obj020e280cPv(YesNoWindow* window, void* pos);
extern "C" void _Z26SetHalfwordAtIndex020e16dcPhis(unsigned char* panel, int idx, short val);
extern "C" void _Z31TransferObjPaletteEntry020e1674P11Obj020e1674ii(unsigned char* panel, int idx, int sel);
extern "C" void _Z23ComputeElementPositionsP9Wf11OuterPtS1_i(unsigned char* panel, short* outX, short* outY, int index);
extern "C" void _Z26SetEntryPositionFromObjectP14WinObj020e28f0ss(YesNoWindow* window, short x, short y);
extern "C" void _Z27UpdateEntryStateAndPositionP11Ctx020e263ci(YesNoWindow* window, int value);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(Obj0205eaa0* obj, int a, int b);

// USA: func_ov005_02159b74
extern "C" ARM void func_ov005_02159b74(EquipmentMenu* self) {
    short x;
    short y;
    _Z26ResetAndReposition020e280cP11Obj020e280cPv(self->yesNo_, (void*)-1);
    self->yesNo_->GetLabel()->palette_ = 0x4c;
    unsigned char* panel = self->yesNo_->panel_;
    _Z26SetHalfwordAtIndex020e16dcPhis(panel, 0, 0x18c6);
    _Z31TransferObjPaletteEntry020e1674P11Obj020e1674ii(panel, 1, 0);
    _Z23ComputeElementPositionsP9Wf11OuterPtS1_i(panel, &x, &y, 0);
    _Z26SetEntryPositionFromObjectP14WinObj020e28f0ss(self->yesNo_, x, y + 4);
    int tick = GameState::GetInstance()->GetTickCount();
    if (tick == 0)
        tick = 1;
    _Z27UpdateEntryStateAndPositionP11Ctx020e263ci(self->yesNo_, tick);
    _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((Obj0205eaa0*)&data_02108760, 5, 0);
}
