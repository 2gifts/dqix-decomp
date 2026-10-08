#include <globaldefs.h>

struct ChoiceGrid {
    int x_;
    int y_;
    int width_;
    int height_;
    int stepX_;
    int stepY_;
    int columns_;
    int rows_;
};

struct CharacterCreation {
    char unk_0[0xc2c];
    ChoiceGrid grid_;
    short cursorX_;
    short cursorY_;
    short cursorWidth_;
    short cursorHeight_;
    short lastX_;
    short lastY_;
};

// USA: func_ov009_02188e70
extern "C" ARM void func_ov009_02188e70(CharacterCreation* self, int choice)
{
    ChoiceGrid* grid = &self->grid_;
    int y;
    int width;
    int height;
    int stepY;
    int columns = grid->columns_;
    y = grid->y_;
    width = grid->width_;
    height = grid->height_;
    stepY = grid->stepY_;
    self->cursorX_ = grid->stepX_ * (choice % columns) + grid->x_;
    self->cursorY_ = stepY * (choice / columns) + y;
    self->cursorWidth_ = width;
    self->cursorHeight_ = height;
    self->lastX_ = self->cursorX_;
    self->lastY_ = self->cursorY_;
}
