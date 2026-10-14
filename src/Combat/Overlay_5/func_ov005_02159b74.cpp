#include <globaldefs.h>

#if defined(jpn)
enum { kYesNo = 0xe60 };
#else
enum { kYesNo = 0xe64 };
#endif

#include <GameState/GameState.h>

struct Obj0205eaa0;

struct YesNoLabel {
    char unk_0[0x38];
    unsigned char label_;
    unsigned char palette_;
};

struct YesNoWindow {
    char unk_0[0xc];
    YesNoLabel* label_;
    unsigned char* panel_;

    YesNoLabel* GetLabel() { return label_; }
};

struct EquipmentMenu {
    char unk_0[kYesNo];
    YesNoWindow* yesNo_;
};

extern int data_02108760;

struct Obj020e280c;
void ResetAndReposition020e280c(Obj020e280c*, void*);
void SetHalfwordAtIndex020e16dc(unsigned char* panel, int idx, short val);
struct Obj020e1674;
void TransferObjPaletteEntry020e1674(Obj020e1674*, int, int);
struct Wf11Outer;
void ComputeElementPositions_020e1e24(Wf11Outer*, unsigned short*, unsigned short*, int);
struct WinObj020e28f0;
void SetEntryPositionFromObject(WinObj020e28f0*, short, short);
struct Ctx020e263c;
void UpdateEntryStateAndPosition(Ctx020e263c*, int);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0* obj, int a, int b);

// USA: func_ov005_02159b74
extern "C" ARM void func_ov005_02159b74(EquipmentMenu* self) {
    short x;
    short y;
    ResetAndReposition020e280c((Obj020e280c*)self->yesNo_, (void*)-1);
#if defined(jpn)
    YesNoLabel* label = self->yesNo_->GetLabel();
    label->label_ = 0xc2;
    label->palette_ = 0x4c;
#else
    self->yesNo_->GetLabel()->palette_ = 0x4c;
#endif
    unsigned char* panel = self->yesNo_->panel_;
    SetHalfwordAtIndex020e16dc(panel, 0, 0x18c6);
    TransferObjPaletteEntry020e1674((Obj020e1674*)panel, 1, 0);
    ComputeElementPositions_020e1e24((Wf11Outer*)panel, (unsigned short*)&x, (unsigned short*)&y, 0);
    SetEntryPositionFromObject((WinObj020e28f0*)self->yesNo_, x, y + 4);
    int tick = GameState::GetInstance()->GetTickCount();
    if (tick == 0)
        tick = 1;
    UpdateEntryStateAndPosition((Ctx020e263c*)self->yesNo_, tick);
    DispatchWithShortB4_0205eaa0((Obj0205eaa0*)&data_02108760, 5, 0);
}
