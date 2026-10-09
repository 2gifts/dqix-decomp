#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

unsigned char* GetGlobal02109030(void);
extern "C" void func_ov003_021612c0(void* obj);
extern "C" int func_ov003_02161344(void* obj);
extern "C" int _Z39CountValidCombatantsMinusField_02160b84v(void* obj);
int GetFieldIfFlag4(char* obj);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, const int* src);
void ReadFields0x70To0x78(unsigned char* obj, int* a, int* b, int* c);
extern "C" void func_ov017_021c37a4(void);
struct GlobalObj0202e6a8;
void AddWrappedField0x70_0202e784(struct GlobalObj0202e6a8* obj, int value);
struct CamState0202e6c0;
void ClampField74BySign(struct CamState0202e6c0* obj, int value);
struct Obj0202e71c;
void SetField78Clamped0202e71c(struct Obj0202e71c* obj, int value);
struct Cont0207fe44;
void CallFunc0204c804OverAllElems(struct Cont0207fe44* menu);
void ClearFlag0x3c9Bit0AndCleanup(unsigned char* obj);

struct Camera0216552c {
    char unk_0[0x4];
    int position_[3];
    int target_[3];
    char unk_1c[0x204];
    int angle_;
};

struct Window0216552c {
    char unk_0[0x36];
    short messageId_;
};

struct Menu0216552c {
    char unk_0[0x324];
    Window0216552c* window_;
    char unk_328[0x13c];
    unsigned int flags_;
    char unk_468[0xc];
    short messageId_;
    char unk_476[0xe];
    short nextState_[2];
    short field_0x488;
    short windowMessageId_;
    char unk_48c[0x17];
    unsigned char code_;
    unsigned char step_;
};

// USA: func_ov003_0216552c
extern "C" ARM void func_ov003_0216552c(Menu0216552c* self) {
    unsigned char* global = GetGlobal02109030();
    Window0216552c* window = self->window_;
    short* nextState = self->nextState_;

    if (self->step_ == 0) {
        nextState[0] = 0x20;
        self->step_++;
    } else if (self->step_ == 1) {
        func_ov003_021612c0(self);
        self->step_++;
    } else if (self->step_ == 2) {
        if (BackgroundLoader::GetInstance()->GetNumQueuedTasks() > 0) {
            return;
        }
        int result = func_ov003_02161344(self);
        if (result != -1) {
            if (result != 1) {
                return;
            }
            if (_Z39CountValidCombatantsMinusField_02160b84v(self) != 0) {
                self->field_0x488 = 0x1a;
                self->messageId_ = self->windowMessageId_ = 0xa9;
                window->messageId_ = self->windowMessageId_;
                nextState[0] = 0x2e;
                nextState[1] = 1;
                self->code_ = 10;
                self->step_ = 1;
                self->flags_ |= 0x2000;
            } else {
                int distance;
                int height;
                int angle;
                int position[3];
                int target[3];
                Camera0216552c* camera = (Camera0216552c*)GetFieldIfFlag4((char*)GameState::GetInstance());
                if (camera != NULL) {
                    _ZN8Vector3iaSERKS_(position, camera->position_);
                    _ZN8Vector3iaSERKS_(target, camera->target_);
                    ReadFields0x70To0x78((unsigned char*)camera, &angle, &height, &distance);
                }
                func_ov017_021c37a4();
                if (camera != NULL) {
                    _ZN8Vector3iaSERKS_(camera->position_, position);
                    _ZN8Vector3iaSERKS_(camera->target_, target);
                    AddWrappedField0x70_0202e784((struct GlobalObj0202e6a8*)camera, angle);
                    ClampField74BySign((struct CamState0202e6c0*)camera, height);
                    SetField78Clamped0202e71c((struct Obj0202e71c*)camera, distance);
                    camera->angle_ = angle;
                }
                CallFunc0204c804OverAllElems((struct Cont0207fe44*)window);
                nextState[0] = 0x21;
                nextState[1] = 1;
                self->code_ = 10;
                self->step_ = 0;
                ClearFlag0x3c9Bit0AndCleanup(global);
            }
        } else {
            self->field_0x488 = 0x1a;
            self->messageId_ = self->windowMessageId_ = 0xa9;
            window->messageId_ = self->windowMessageId_;
            nextState[0] = 0x22;
            nextState[1] = 1;
            self->code_ = 10;
            self->step_ = 1;
            self->flags_ |= 0x2000;
        }
    }
}
