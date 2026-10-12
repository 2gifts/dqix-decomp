#include <globaldefs.h>
#include "GameState/GameState.h"

struct FlagWord02046708;
struct HeadNode02046b24;
struct PointerField32c_ffc0;
struct Obj020397cc;
struct BitField0203402c;
struct MenuInput0219a6b8 {
    unsigned char padding0[0x24];
    unsigned short button;
    unsigned char padding26[0x54 - 0x26];
    unsigned char active;
    unsigned char pressed;
    unsigned char padding56[9];
    unsigned char held;
};
struct Zone0219a6b8 { unsigned short id; };
struct MenuResources0219a6b8 {
    unsigned char padding0[0x3634];
    unsigned char x[0x12];
    unsigned char y[0x12];
    unsigned char state[0x12];
    unsigned char padding366a[0x36fc - 0x366a];
    void** list;
    unsigned char padding3700[0x42e4 - 0x3700];
    unsigned char action;
};
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" Zone0219a6b8* func_02012fe4();
extern "C" FlagWord02046708* _Z27GetDataPtr02114e04_020d6c00v();
int IsField0Null(void**);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
extern "C" int _Z17TestFlags02046708P16FlagWord02046708j(FlagWord02046708*, unsigned int);
unsigned char* GetPointerAt0x32c(PointerField32c_ffc0*);
int CheckSubstructByte0x7cPositive(signed char*);
int TestFlagMask(unsigned short*, int);
int CheckField0xc4Low15BitsNonZero(BitField0203402c*);
unsigned char GetByte0x26c(char*);
extern "C" void __clear(void*, int);
void SelectCoordsByFlag0x24(unsigned char*, int*, int*);
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(Obj020397cc*, int);
void ClearByteFlagAt0x154(unsigned char*);
void SetByteFlagAt0x154(unsigned char*);
void SetByteField0x253(void*);
extern unsigned short data_02114e30[];
extern MenuInput0219a6b8 data_02114e54;

// USA: func_ov017_0219a6b8
extern "C" ARM void func_ov017_0219a6b8(MenuResources0219a6b8* self) {
    GameState* game = GameState::GetInstance();
    unsigned char* other;
    _Z26GetGlobalField0x1c020421a0v();
    unsigned short zone = func_02012fe4()->id;
    FlagWord02046708* flags = _Z27GetDataPtr02114e04_020d6c00v();
    if (!IsField0Null(self->list)) return;
    if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)self->list) == 2) return;
    if (_Z17TestFlags02046708P16FlagWord02046708j(flags, 0x800)) return;
    GameObject* actor = game->GetUnknownGameObject();
    if (!actor) return;
    other = GetPointerAt0x32c((PointerField32c_ffc0*)game);
    if (CheckSubstructByte0x7cPositive((signed char*)actor)) return;
    if (TestFlagMask(data_02114e30, 2) && !self->state[0]) return;
    if (CheckField0xc4Low15BitsNonZero((BitField0203402c*)actor)) return;
    if (GetByte0x26c((char*)actor)) return;
    if (zone == 0x2774) return;
    int indices[1];
    __clear(indices, sizeof(indices));
    for (int i = 0; i < 1; ++i) {
        int index = indices[i];
        int width = 24;
        int height = 24;
        if (index == 0) { width = 32; height = 32; }
        if (data_02114e54.pressed) {
            int x, y;
            SelectCoordsByFlag0x24((unsigned char*)&data_02114e54, &x, &y);
            if (self->x[index] < x && x < self->x[index] + width && self->y[index] < y && y < self->y[index] + height) {
                _Z27CancelPendingAction020397ccP11Obj020397cci((Obj020397cc*)actor, 1);
                if (other && zone == 0x2710) ClearByteFlagAt0x154(other);
                self->state[index] = 1;
            }
        } else if (data_02114e54.held && data_02114e54.button) {
            int x, y;
            SelectCoordsByFlag0x24((unsigned char*)&data_02114e54, &x, &y);
            if (self->state[index] == 1) {
                if (!(self->x[index] < x && x < self->x[index] + width && self->y[index] < y && y < self->y[index] + height)) self->state[index] = 2;
            } else if (self->state[index] == 2) {
                int nextX = (x - 12 + self->x[index]) / 2;
                int nextY = (y - 12 + self->y[index]) / 2;
                if (nextX < 0) nextX = 0;
                if (256 - width < nextX) nextX = 256 - width;
                if (nextY < 0) nextY = 0;
                if (192 - height < nextY) nextY = 192 - height;
                self->x[index] = nextX;
                self->y[index] = nextY;
            }
        } else if (data_02114e54.active) {
            if (self->state[index]) {
                SetByteField0x253(actor);
                if (other && zone == 0x2710) SetByteFlagAt0x154(other);
            }
            if (self->state[index] == 1) {
                self->action = 1;
                SetByteField0x253(actor);
                if (other && zone == 0x2710) SetByteFlagAt0x154(other);
            }
            self->state[index] = 0;
        } else if (self->state[index]) {
            SetByteField0x253(actor);
            if (other && zone == 0x2710) SetByteFlagAt0x154(other);
            self->state[index] = 0;
        }
        if (self->state[index]) return;
    }
}
