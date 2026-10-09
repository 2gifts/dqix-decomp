#include <globaldefs.h>
#include <std_library_functions.h>

struct StructA0205d5d0;

struct Touch02114e54 {
    char pad0[0x24];
    unsigned short active;
    char pad1[0x30 - 0x26];
    int x;
    int y;
    char pad2[0x5f - 0x38];
    unsigned char enabled;
};

struct MenuList {
    char unk_0[0x30];
    int cursor_;
    int GetCursor() { return cursor_; }
};

struct MenuWindow {
    int unk_0;
    MenuList list_;
    char unk_38[0xb0 - 0x38];
    unsigned char style_;
    MenuList* GetList() { return &list_; }
};

struct EquipmentMenu {
    char unk_0[0xe10];
    unsigned short* text_;
    char unk_e14[0xee4 - 0xe14];
    MenuWindow window_;
    char unk_f98[0x3ddd - 0xf98];
    unsigned char textMode_;
    MenuWindow* GetWindow() { return &window_; }
};

extern Touch02114e54 data_02114e54;

extern "C" void func_ov005_02159a30(EquipmentMenu* self, unsigned short* text, int touched);
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(StructA0205d5d0* a, int b, int c, int d, unsigned char e);

// USA: func_ov005_02158ed0
extern "C" ARM void func_ov005_02158ed0(EquipmentMenu* self) {
    unsigned char mode = self->textMode_;
    if (mode == 0)
        return;
    int touched = 0;
    if (mode == 2 && data_02114e54.enabled && data_02114e54.active) {
        if (self->GetWindow()->GetList()->GetCursor() < 0)
            return;
        touched = 1;
    }
    memset(self->text_, 0, 0x960);
    unsigned char style = self->window_.style_;
    if (style == 1)
        func_ov005_02159a30(self, self->text_, touched);
    _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((StructA0205d5d0*)&self->window_, style, (int)self->text_, 1, 0);
}
