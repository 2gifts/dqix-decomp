#include <globaldefs.h>

#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

#if defined(jpn)
#define func_ov008_0218aee4 func_ov008_0218bb50
#endif

struct Elem_0205d81c {
    char pad0[0xa8];
    short width;
    char pad1[0xac - 0xaa];
    short tileX;
    short tileY;
};

struct Struct_0205d81c;

struct Cell0218aee4 {
    char pad0[0x14];
    int x;
    int y;
    char pad1[0x28 - 0x1c];
};

struct Cursor0218aee4 {
    char pad0[0xf0];
    Cell0218aee4 cells[2];
};

struct Manager0218aee4 {
    char pad0[0x18];
    char elements[0x1f4 - 0x18];
    void* renderer;
    Cursor0218aee4* cursor;
    char pad1[LOW_REGION(0xe95, 0xe99) - 0x1fc];
    signed char state;
};

Elem_0205d81c* FindElementByC40205d81c(Struct_0205d81c* s, int key);
extern "C" void func_0205ac40(void* renderer, Cell0218aee4* cell);

// USA: func_ov008_0218aee4
extern "C" ARM void func_ov008_0218aee4(Manager0218aee4* self) {
    if (self->state != 1) {
        return;
    }
    Elem_0205d81c* elem = FindElementByC40205d81c((Struct_0205d81c*)self->elements, 0);
    if (elem == NULL) {
        return;
    }
    short x = elem->tileX * 8;
    short tileY = elem->tileY;
    Cursor0218aee4* cursor = self->cursor;
    short width = elem->width;
    cursor->cells[0].x = (x - 1) << 12;
    short y = tileY * 8;
    cursor->cells[0].y = (y - 1) << 12;
    func_0205ac40(self->renderer, &cursor->cells[0]);
    cursor = self->cursor;
    cursor->cells[1].x = LOW_REGION((x + 0x50), (x + (short)(width * 8) - 8)) << 12;
    cursor->cells[1].y = (y - 1) << 12;
    func_0205ac40(self->renderer, &cursor->cells[1]);
}
