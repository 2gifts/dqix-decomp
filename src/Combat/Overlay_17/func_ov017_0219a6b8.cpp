#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/Zone3D.h"

struct FlagWord02046708;
struct HeadNode02046b24;
struct PointerField32c_ffc0;
struct Obj020397cc;
struct BitField0203402c;
void* GetGlobalField0x1c020421a0();
extern "C" Zone3D* func_02012fe4();
FlagWord02046708* GetDataPtr02114e04_020d6c00();
int IsField0Null(void**);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
int TestFlags02046708(FlagWord02046708*, unsigned int);
unsigned char* GetPointerAt0x32c(PointerField32c_ffc0*);
int CheckSubstructByte0x7cPositive(signed char*);
int TestFlagMask(unsigned short*, int);
int CheckField0xc4Low15BitsNonZero(BitField0203402c*);
unsigned char GetByte0x26c(char*);
extern "C" void __clear(void*, int);
void SelectCoordsByFlag0x24(unsigned char*, int*, int*);
void CancelPendingAction020397cc(Obj020397cc*, int);
void ClearByteFlagAt0x154(unsigned char*);
void SetByteFlagAt0x154(unsigned char*);
void SetByteField0x253(void*);
extern unsigned short data_02114e30[];
extern unsigned char data_02114e54[];

// USA: func_ov017_0219a6b8
extern "C" ARM void func_ov017_0219a6b8(GameResources* self) {
    GameState* game = GameState::GetInstance();
    unsigned char* other;
    GetGlobalField0x1c020421a0();
    unsigned short zone = func_02012fe4()->currentZoneID_;
    FlagWord02046708* flags = GetDataPtr02114e04_020d6c00();
    if (!IsField0Null((void**)self->unknown_ptr_array_36fc[0])) return;
    if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)(void**)self->unknown_ptr_array_36fc[0]) == 2) return;
    if (TestFlags02046708(flags, 0x800)) return;
    GameObject* actor = game->GetUnknownGameObject();
    if (!actor) return;
    other = GetPointerAt0x32c((PointerField32c_ffc0*)game);
    if (CheckSubstructByte0x7cPositive((signed char*)actor)) return;
    if (TestFlagMask(data_02114e30, 2) && !self->fieldButtonState[0]) return;
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
        if (data_02114e54[0x55]) {
            int x, y;
            SelectCoordsByFlag0x24(data_02114e54, &x, &y);
            if (self->fieldButtonX[index] < x && x < self->fieldButtonX[index] + width && self->fieldButtonY[index] < y && y < self->fieldButtonY[index] + height) {
                CancelPendingAction020397cc((Obj020397cc*)actor, 1);
                if (other && zone == 0x2710) ClearByteFlagAt0x154(other);
                self->fieldButtonState[index] = 1;
            }
        } else if (data_02114e54[0x5f] && (*(unsigned short*)(data_02114e54 + 0x24))) {
            int x, y;
            SelectCoordsByFlag0x24(data_02114e54, &x, &y);
            if (self->fieldButtonState[index] == 1) {
                if (!(self->fieldButtonX[index] < x && x < self->fieldButtonX[index] + width && self->fieldButtonY[index] < y && y < self->fieldButtonY[index] + height)) self->fieldButtonState[index] = 2;
            } else if (self->fieldButtonState[index] == 2) {
                int nextX = (x - 12 + self->fieldButtonX[index]) / 2;
                int nextY = (y - 12 + self->fieldButtonY[index]) / 2;
                if (nextX < 0) nextX = 0;
                if (256 - width < nextX) nextX = 256 - width;
                if (nextY < 0) nextY = 0;
                if (192 - height < nextY) nextY = 192 - height;
                self->fieldButtonX[index] = nextX;
                self->fieldButtonY[index] = nextY;
            }
        } else if (data_02114e54[0x54]) {
            if (self->fieldButtonState[index]) {
                SetByteField0x253(actor);
                if (other && zone == 0x2710) SetByteFlagAt0x154(other);
            }
            if (self->fieldButtonState[index] == 1) {
                self->unknown_42e3[1] = 1;
                SetByteField0x253(actor);
                if (other && zone == 0x2710) SetByteFlagAt0x154(other);
            }
            self->fieldButtonState[index] = 0;
        } else if (self->fieldButtonState[index]) {
            SetByteField0x253(actor);
            if (other && zone == 0x2710) SetByteFlagAt0x154(other);
            self->fieldButtonState[index] = 0;
        }
        if (self->fieldButtonState[index]) return;
    }
}
