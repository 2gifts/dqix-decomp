#include <globaldefs.h>
#include "GameState/GameState.h"

struct SrcStruct0208baec { int x, y; float scale; unsigned short value; unsigned short field_e; };
struct DstStruct0208baec { unsigned char field_0[0xc]; int x, y, width, height; unsigned short value; unsigned short field_1e; unsigned short style; unsigned char flags; unsigned char field_23[5]; };
struct ShakeState0208ca00 {
    unsigned char field_0[0x60];
    DstStruct0208baec destination;
    unsigned char field_88[0xb4 - 0x88];
    DstStruct0208baec* entries;
    unsigned char field_b8[0xc8 - 0xb8];
    float angle;
    float factor;
    unsigned char field_d0[2];
    short id;
    unsigned char action;
    unsigned char field_d5[2];
    unsigned char shakeCount;
    unsigned char kind;
    signed char countdown;
    unsigned short flags;
};
typedef void (ShakeState0208ca00::*Action0208bb78)();
struct Actions0208bb78 { Action0208bb78 actions[5]; };
#if defined(jpn)
extern Actions0208bb78 data_020e8e00;
#else
extern Actions0208bb78 data_020e8ce4;
#endif
extern Action0208bb78 data_020e6d5c;
struct HeadNode02046b24;
struct Struct0200fb08;
struct GetTableByteOrFFData;
int AnimateSubBG0Shake0208ca00(ShakeState0208ca00*, int);
extern "C" void func_0208bf78(ShakeState0208ca00*);
extern "C" void func_0208b788(int, float, SrcStruct0208baec*, int);
int SetupDstFromSrcAndScale0208baec(int, DstStruct0208baec*, SrcStruct0208baec*, int, float, int, unsigned char);
int GetWord0x0_0200fb8c(int*);
unsigned char NormalizeField5_0200fb08(Struct0200fb08*);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
int* GetGlobal02109418_02094d6c();
unsigned char GetTableByteOrFF_020965ac(GetTableByteOrFFData*, unsigned char);
int TestBitInByteArrayAt0x84_02096088(void*, int);

// USA: func_0208bb78
extern "C" ARM int func_0208bb78(ShakeState0208ca00* self, int delta) {
    if (self->id < 0) return 1;
    if (!delta) delta = 1;
    int pivot = AnimateSubBG0Shake0208ca00(self, (signed char)delta);
    if (self->countdown) {
        self->countdown -= delta;
        if (self->countdown < 0) self->countdown = 0;
    }
    if (self->flags & 0x20) func_0208bf78(self);
    else {
#if defined(jpn)
        Actions0208bb78 actions = data_020e8e00;
#else
        Actions0208bb78 actions = data_020e8ce4;
#endif
        actions.actions[4] = data_020e6d5c;
        if (!actions.actions[self->action]) return 1;
        (self->*actions.actions[self->action])();
    }
    GameState* state = GameState::GetInstance();
    GameResources* resources = (GameResources*)GetWord0x0_0200fb8c((int*)state);
    float scale;
    unsigned char slot;
    HeadNode02046b24** head = (HeadNode02046b24**)resources->unknown_ptr_array_36fc[0];
    if (self->flags & 8) {
        int adjust = (self->flags & 0x100) != 0;
        SrcStruct0208baec values;
        func_0208b788(self->kind, self->factor, &values, adjust);
        scale = values.scale;
        if (!self->kind) scale *= scale;
        slot = 0;
        if (adjust) slot = 1;
        if (self->flags & 0x100) {
            values.y -= 16;
#if defined(jpn)
            SetupDstFromSrcAndScale0208baec((int)&self->destination, &self->entries[slot], &values, 0x40, scale, pivot, 1);
#else
            SetupDstFromSrcAndScale0208baec((int)&self->destination, &self->entries[slot], &values, 0x20, scale, pivot, 1);
#endif
            SrcStruct0208baec second;
            memcpy(&second, &values, sizeof(second));
            second.y += 0x38;
#if !defined(jpn)
            if (NormalizeField5_0200fb08((Struct0200fb08*)state) == 5) second.y += 16;
#endif
#if defined(jpn)
            SetupDstFromSrcAndScale0208baec((int)&self->destination, &self->entries[(unsigned char)(slot + 1)], &second, 0x60, scale, pivot, 1);
#else
            SetupDstFromSrcAndScale0208baec((int)&self->destination, &self->entries[(unsigned char)(slot + 1)], &second, 0x30, scale, pivot, 1);
#endif
        } else {
            int draw = 1;
            if (GetHeadNodeIdOrMinusOne(head) == 0x2d) slot = draw;
            else if (self->kind == 1) draw = 0;
            if (draw) SetupDstFromSrcAndScale0208baec((int)&self->destination, &self->entries[slot], &values, 0x40, scale, pivot, 1);
        }
    }
    if (self->id != 9999 && self->id >= 0 && self->action != 0 && self->action != 3 && GetHeadNodeIdOrMinusOne(head) != 0x2d) {
        int* global = GetGlobal02109418_02094d6c();
        int value = GetTableByteOrFF_020965ac((GetTableByteOrFFData*)global, (unsigned char)self->id);
        if (TestBitInByteArrayAt0x84_02096088(global, value)) {
            SrcStruct0208baec values;
            func_0208b788(1, 1.0f, &values, 0);
            SetupDstFromSrcAndScale0208baec((int)&self->destination, &self->entries[1], &values, 0x20, values.scale, pivot, 2);
        }
    }
    return 0;
}
