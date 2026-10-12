#include <globaldefs.h>
#include "System/Matrix.h"
#include "GameState/GameState.h"

struct Fields020407b4;
struct Obj02033874;
struct ShortField0x22e_020968c4;
struct Obj020968d0 {
    char pad_00[0x224];
    unsigned char active;
};
struct SteeringObject {
    char pad_00[0x44];
    Vector3i position;
    char pad_50[4];
    int heading;
    char pad_58[0x5a];
    short speed1;
    short speed2;
    char pad_b6[0x7e];
    int mode;
    char pad_138[0xc];
    int speed;
    int turnSpeed;
    char pad_14c[0x18];
    Vector3i vector164;
    char pad_170[4];
    Vector3i vector174;
    char pad_180[0x1c];
    unsigned char enabled;
    char pad_19d[3];
    unsigned char direction;
};
struct SteeringControl {
    char pad_00[0x40];
    int counter;
};

void* GetField0x3b0Value(GameState*);
extern "C" void func_02012fe4();
void SetFields0x44(Fields020407b4*, int, int, int);
int IsFlag0x40Set(unsigned short*);
int IsFlag0x20Set(unsigned short*);
int IsFlag0x10Set(unsigned short*);
int IsFlag0x80Set(unsigned short*);
extern "C" void* _Z21GetField4328_0218d268Pv(void*);
int GetField0x70(void*);
int GetShortAt0x22e(ShortField0x22e_020968c4*);
int fix32ReduceAngle0To2Pi(int);
int fix32SignedAngleDistance(int, int);
extern "C" int _Z31CheckAndComputeDistance020968d0P11Obj020968d0Pi(Obj020968d0*, int*);
extern "C" void _Z24SetVecYFromValue02033874P11Obj02033874i(Obj02033874*, int);
extern unsigned short data_02114e30;
extern SteeringControl data_02114e54;
extern const int data_020e9118[8];

// USA: func_020adaac
extern "C" ARM void func_020adaac(SteeringObject* self) {
    void* camera = GetField0x3b0Value(GameState::GetInstance());
    void* manager = func_ov017_0218b5b0();
    int targetHeading;
    func_02012fe4();
    SetFields0x44((Fields020407b4*)self, self->position.x, 0xa000, self->position.z);
    Vector3i first = self->vector164;
    first.y = 0xa000;
    self->vector164 = first;
    Vector3i second = self->vector174;
    second.y = 0xa000;
    self->vector174 = second;
    self->mode = 0;
    if (IsFlag0x40Set(&data_02114e30) && IsFlag0x20Set(&data_02114e30)) {
        self->mode = 1;
        self->direction = 12;
    } else if (IsFlag0x40Set(&data_02114e30) && IsFlag0x10Set(&data_02114e30)) {
        self->mode = 1;
        self->direction = 13;
    } else if (IsFlag0x80Set(&data_02114e30) && IsFlag0x20Set(&data_02114e30)) {
        self->mode = 1;
        self->direction = 14;
    } else if (IsFlag0x80Set(&data_02114e30) && IsFlag0x10Set(&data_02114e30)) {
        self->mode = 1;
        self->direction = 15;
    } else if (IsFlag0x40Set(&data_02114e30)) {
        self->mode = 1;
        self->direction = 8;
    } else if (IsFlag0x80Set(&data_02114e30)) {
        self->mode = 1;
        self->direction = 9;
    } else if (IsFlag0x20Set(&data_02114e30)) {
        self->mode = 1;
        self->direction = 10;
    } else if (IsFlag0x10Set(&data_02114e30)) {
        self->mode = 1;
        self->direction = 11;
    }
    if (data_02114e54.counter > 5) self->mode = 2;
    if (!self->enabled) {
        self->mode = 0;
        return;
    }
    if (self->mode == 1 || self->mode == 2) {
        Obj020968d0* target = (Obj020968d0*)_Z21GetField4328_0218d268Pv(manager);
        if (self->mode == 1) {
            int offset = data_020e9118[self->direction - 8];
            targetHeading = offset + GetField0x70(camera);
        } else if (target->active) {
            targetHeading = GetShortAt0x22e((ShortField0x22e_020968c4*)target);
        }
        int heading = self->heading;
        targetHeading = fix32ReduceAngle0To2Pi(targetHeading);
        heading = fix32ReduceAngle0To2Pi(heading);
        int turnSpeed = self->turnSpeed;
        int distance = fix32SignedAngleDistance(heading, targetHeading);
        if (distance > 0) {
            if (distance < turnSpeed) heading = targetHeading;
            else heading += turnSpeed;
        } else if (distance < 0) {
            if (-distance < turnSpeed) heading = targetHeading;
            else heading -= turnSpeed;
        }
        heading = fix32ReduceAngle0To2Pi(heading);
        if (_Z31CheckAndComputeDistance020968d0P11Obj020968d0Pi(target, 0) || !target->active)
            _Z24SetVecYFromValue02033874P11Obj02033874i((Obj02033874*)self, heading);
    }
    self->speed1 = self->speed;
    self->speed2 = self->speed;
}
