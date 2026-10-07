struct Overlay9Grid {
    int x, y, width, height, stepX, stepY, columns, rows;
};
struct Overlay9TouchView {
    unsigned char unknown000[0xbec];
    unsigned char cursor[12];
    int cursorMode;
    unsigned char unknownbfc[0xc2c - 0xbfc];
    Overlay9Grid grid;
    short selectionX, selectionY, selectionWidth, selectionHeight;
    unsigned char unknownc54[4];
    signed char state;
    unsigned char unknownc59[0xd9c - 0xc59];
    unsigned int flags;
};

extern "C" {
    int _Z18GetField0_0205bafcPv(void*);
    int _Z24ComputeScaledSum0205bb84P15Struct_0205bb84(void*);
    void func_0205bb04(void*, int);
    void func_ov009_02188c2c(Overlay9TouchView*);
    void func_ov009_02188e70(Overlay9TouchView*, int);

    int func_ov009_02189854(Overlay9TouchView* menu, int touchX, int touchY) {
        if (touchY >= 0xa9 && touchY <= 0xb1) {
            if (touchX >= 0x8e && touchX <= 0xbe)
                return -2;
            if (touchX >= 0xc8 && touchX <= 0xf0)
                return -3;
        }
        if (touchY >= 8 && touchY <= 24) {
            for (int i = 0; i < 8; ++i) {
                int x = (i << 4) + 0x78;
                int maxX = x + 16;
                if (touchX >= x && touchX <= maxX)
                    return i + 0x65;
            }
        }

        Overlay9Grid* grid = &menu->grid;
        int width = grid->width;
        int height = grid->height;
        int stepX = grid->stepX;
        int stepY = grid->stepY;
        int columns = grid->columns;
        int rows = grid->rows;
        int selected = -4;
        for (int row = 0; row < rows; ++row) {
            for (int column = 0; column < columns; ++column) {
                int x = grid->x + stepX * column;
                if (menu->state == 8)
                    break;
                int maxX = x + width;
                if (touchX >= x && touchX <= maxX) {
                    int y = grid->y + stepY * row;
                    int maxY = y + height;
                    if (touchY >= y && touchY <= maxY) {
                        selected = column + row * columns;
                        menu->selectionX = x;
                        menu->selectionY = y;
                        menu->selectionWidth = width;
                        menu->selectionHeight = height;
                        break;
                    }
                }
            }
            if (selected >= 0)
                break;
        }

        int cursorMode = menu->cursorMode;
        int count = _Z18GetField0_0205bafcPv(menu->cursor);
        if (cursorMode == 1 && count == 8 && selected >= 0 && selected != 0x65 && selected != 0x6c) {
            func_ov009_02188c2c(menu);
            func_0205bb04(menu->cursor, selected);
            menu->flags |= 0x2000;
            int index = _Z24ComputeScaledSum0205bb84P15Struct_0205bb84(menu->cursor);
            func_ov009_02188e70(menu, index);
        }
        return selected;
    }
}
