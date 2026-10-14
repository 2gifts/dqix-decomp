#include <globaldefs.h>

struct GameState;
struct Obj0205eaa0;

struct TouchState
{
    char unk_0[0x24];
    unsigned short touching_;
    char unk_26[0x54 - 0x26];
    unsigned char released_;
    unsigned char pressed_;
    char unk_56[0x5f - 0x56];
    unsigned char unk_5f;
};

struct GameResources0215c058
{
    char pad[0x3708];
    int* ptr;
};

struct Member0215c058
{
    char pad0[0x4fc];
    int member;
    char pad1[0x634 - 0x500];
    unsigned short flags;
};

struct CursorFrame0215c058
{
    void* target;
    int scale;
    int minX;
    int maxX;
    int minY;
    int maxY;
    int unk_18[8];
    int speed;
};

struct Menu0215c058
{
    char pad0[0x19f4];
    char scroll[0x1a34 - 0x19f4];
    void* cursorTarget;
    char pad1[0x3daa - 0x1a38];
    unsigned char f3daa;
    char pad2[0x3db8 - 0x3dab];
    unsigned char cursorMode;
    char pad3;
    unsigned char state;
    signed char selected;
    unsigned char tab;
    signed char page;
    char pad4[0x3dcc - 0x3dbe];
    struct { unsigned int b0 : 2; unsigned int f2 : 1; unsigned int f3 : 1; unsigned int b4 : 2; unsigned int f6 : 1; unsigned int rest : 25; } dirty;
    char pad5[0x3de0 - 0x3dd0];
    short held;
};

extern "C" GameResources0215c058* func_ov017_0218b5b0();
Member0215c058* GetField1c_021a193c(int*);
void DispatchByIdxAndCond021551fc(char*, int, int);
extern "C" GameState* _ZN9GameState11GetInstanceEv();
void SelectCoordsByFlag0x24_02012a84(unsigned char* obj, int* out1, int* out2);
extern "C" void func_ov005_02156658(Menu0215c058* self, int x, int y);
extern "C" int func_ov005_02155670(Menu0215c058* self, int x, int y);
extern "C" void func_0205bb04(void* obj, int v);
extern "C" void func_ov005_021579ec(Menu0215c058* self, unsigned int state, unsigned char slot);
extern "C" unsigned int _ZNK9GameState12GetTickCountEv(GameState* gs);
extern "C" int func_0205bf58(void* obj, int v);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);
extern "C" int func_ov005_021585fc(Menu0215c058* self, int direction);
extern "C" void func_ov005_021555c0(Menu0215c058* self);
extern "C" void func_ov005_021536e0(CursorFrame0215c058* frame);
extern "C" void func_ov005_021553b4(Menu0215c058* self, int slot, int* x, int* y);
extern "C" void func_ov005_02154d18(CursorFrame0215c058* obj, int a, int b);
extern "C" void func_ov005_02154d34(CursorFrame0215c058* obj, int a, int b);
extern "C" void func_ov005_02154d50(CursorFrame0215c058* obj, int a, int b);
extern "C" void func_ov005_02154d7c(CursorFrame0215c058* obj, int a, int b);
extern "C" void func_ov005_021537bc(CursorFrame0215c058* frame, int mode, unsigned short value);
struct Struct_0205bb84;
int ComputeScaledSum0205bb84(Struct_0205bb84*);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
int CheckFlag30Or401_02157190(void* self);
unsigned char* GetPtrField0x2a04_02010828(GameState*);
short* GetPointerFromArray0xbd0_0207c5f8(unsigned char*, unsigned int);
signed char* GetPointerAt0xbf0_0207c60c(void*, unsigned int);
extern "C" void func_ov005_0215792c(Menu0215c058* self, int mode);

extern "C" TouchState data_02114e54;
extern unsigned short data_02114e30;
extern char data_02108760[];
extern unsigned char data_ov005_0215cd10[];

// USA: func_ov005_0215c058
extern "C" ARM void func_ov005_0215c058(Menu0215c058* self)
{
    if (self->state == 0)
    {
        self->held = self->selected - 8 + self->page * 16;
        self->cursorTarget = (char*)self + 0x2a60;
        self->state++;
    }
    else if (self->state == 1)
    {
        Member0215c058* screen = GetField1c_021a193c(func_ov017_0218b5b0()->ptr);
        DispatchByIdxAndCond021551fc((char*)self, screen->member, 0);
        GameState* gs = _ZN9GameState11GetInstanceEv();
        int touched = 0;
        int moved = 0;
        if (data_02114e54.pressed_)
        {
            int x;
            int y;
            touched = 1;
            SelectCoordsByFlag0x24_02012a84((unsigned char*)&data_02114e54, &x, &y);
            self->dirty.f2 = 0;
            self->dirty.f3 = 1;
            func_ov005_02156658(self, x, y);
            int slot = func_ov005_02155670(self, x, y);
            if (slot >= 8 && slot < 0x18)
            {
                self->selected = slot;
                moved = 1;
                func_0205bb04(self->scroll, self->selected - 8);
                func_ov005_021579ec(self, self->cursorMode, self->selected);
            }
        }
        else if (data_02114e54.unk_5f != 0 && data_02114e54.touching_ != 0)
        {
            touched = 1;
        }
        else if (data_02114e54.released_ != 0)
        {
            touched = 1;
        }

        if (!touched)
        {
            int tick = _ZNK9GameState12GetTickCountEv(gs);
            if (tick == 0)
                tick = 1;
            func_0205bf58(self->scroll, tick);
            int changed = 0;
            int col = (self->selected - 8) % 4;
            if (col == 0)
            {
                if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x20))
                    changed = func_ov005_021585fc(self, -1);
            }
            else if (col == 3)
            {
                if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x10))
                    changed = func_ov005_021585fc(self, 1);
            }
            if (changed)
                func_ov005_021555c0(self);
        }

        short top = self->page * 16;
        short bottom = top + 16;
        if (self->held >= top && self->held < bottom)
        {
            CursorFrame0215c058 frame;
            int x;
            int y;
            func_ov005_021536e0(&frame);
            frame.target = (char*)self + 0x2840;
            frame.scale = 0x8000;
            frame.minX = -0x3000;
            frame.maxX = 0x3000;
            frame.maxY = 0x3000;
            frame.minY = -0x3000;
            func_ov005_021553b4(self, self->held % 16 + 8, &x, &y);
            int fx = x << 12;
            int fy = y << 12;
            func_ov005_02154d18(&frame, fx, fy);
            func_ov005_02154d34(&frame, fx, fy);
            func_ov005_02154d50(&frame, 0x18000, 0x18000);
            func_ov005_02154d7c(&frame, 0x18000, 0x18000);
            frame.speed = 0x4800;
            func_ov005_021537bc(&frame, 0, 0x7fff);
        }

        int sel = ComputeScaledSum0205bb84((Struct_0205bb84*)self->scroll) + 8;
        if (sel != self->selected)
        {
            self->selected = sel;
            DispatchWithShortB4_0205eaa0((Obj0205eaa0*)data_02108760, 2, 0);
            func_ov005_021579ec(self, self->cursorMode, self->selected);
        }
        else if (sel == self->selected)
        {
        if (CheckFlag30Or401_02157190(self) != 0 || moved)
        {
            short index = self->selected - 8 + self->page * 16;
            unsigned char* bag = GetPtrField0x2a04_02010828(gs);
            short* ids = GetPointerFromArray0xbd0_0207c5f8(bag + 0x1d4, data_ov005_0215cd10[self->tab]);
            signed char* amounts = GetPointerAt0xbf0_0207c60c(bag + 0x1d4, data_ov005_0215cd10[self->tab]);
            short id = ids[self->held];
            signed char amount = amounts[self->held];
            ids[self->held] = ids[index];
            amounts[self->held] = amounts[index];
            ids[index] = id;
            amounts[index] = amount;
            func_ov005_021555c0(self);
            self->dirty.f6 = 1;
            self->f3daa = 0;
            self->held = -1;
            func_ov005_0215792c(self, 4);
            DispatchWithShortB4_0205eaa0((Obj0205eaa0*)data_02108760, 1, 0);
            screen->flags |= 0x81;
            self->cursorTarget = (char*)self + 0x1a70;
            self->dirty.f2 = 1;
            self->dirty.f3 = 1;
        }
        else if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 2))
        {
            self->held = -1;
            func_ov005_0215792c(self, 4);
            screen->flags |= 0x81;
            self->cursorTarget = (char*)self + 0x1a70;
            self->dirty.f2 = 1;
            self->dirty.f3 = 1;
        }
        }
    }
}
