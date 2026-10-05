// External entry names follow the fork's symbols.txt at b399f53.
// Local argument views remain provisional; see contribution interface notes.
#include "globaldefs.h"
#include "World/Object3D.h"
#include "GameState/GameState.h"
#include "std_library_functions.h"

// Partial bestiary state and descriptor views; input and rotation behavior are clear.
struct BestiaryUpdateMonster { char unknown[0xc]; short id; };
struct BestiaryUpdateDescriptor { char unknown[0x1c]; float rotationY; };
struct BestiaryUpdateState {
    char unknown0[0xc];
    char descriptors[0x10];
    char unknown1c[0x24];
    Object3D* model;
    void* modelResource;
    BestiaryUpdateMonster* monster;
    char unknown4c[0x30];
    unsigned char phase;
    char unknown7d[5];
    union {
        struct { unsigned char returning : 1; unsigned char remainingFlags : 7; } mode;
        unsigned char flags;
    } rotationState;
    char unknown83[0xd];
    unsigned char rotateLeft, rotateRight, unknown92;
};
typedef void (BestiaryUpdateState::*BestiaryUpdateHandler)();
extern "C" {
void func_ov014_02185c48(void*);
void* _Z29BinarySearchByField4_02097224P29BinarySearch020971a8Containeri(void*, short);
int _Z12TestFlagMaskPti(void*, int);
int _Z20TestFlagInSecondWordPtj(void*, int);
extern char data_02114e30[];
extern void* data_ov014_02189800[4];
extern BestiaryUpdateHandler data_020e6d5c;
extern BestiaryUpdateHandler data_ov014_021895a0[];
extern BestiaryUpdateHandler data_ov014_021895b0[];
extern const char data_ov014_021895c8[];
extern const char data_ov014_021895ce[];
}

extern "C" ARM void func_ov014_02184700(BestiaryUpdateState* state) {
    func_ov014_02185c48(state);
    if (state->model) {
        state->model->AdvanceEffects();
        int target = 0;
        if (state->monster) {
            BestiaryUpdateDescriptor* descriptor = (BestiaryUpdateDescriptor*)_Z29BinarySearchByField4_02097224P29BinarySearch020971a8Containeri(state->descriptors, state->monster->id);
            if (descriptor) target = (int)(4096.0f * descriptor->rotationY);
        }
        Object3D* model = state->model;
        int returning = state->rotationState.mode.returning;
        int speed;
        int nextReturning;
        Vector3fix newRotation;
        Vector3fix oldRotation;
        if (!model) nextReturning = 0;
        else {
            int manual = 0;
            state->rotateLeft = 0;
            state->rotateRight = 0;
            nextReturning = returning;
            speed = 0;
            if (_Z12TestFlagMaskPti(data_02114e30, 0x200) && _Z12TestFlagMaskPti(data_02114e30, 0x100)) {
                if (!returning) {
                    nextReturning = 1;
                    state->rotateLeft = 1;
                    state->rotateRight = 1;
                }
            } else if (_Z12TestFlagMaskPti(data_02114e30, 0x200) && !_Z20TestFlagInSecondWordPtj(data_02114e30, 0x100)) {
                manual = 1;
                state->rotateLeft = 1;
                speed = 0xcc;
            } else if (_Z12TestFlagMaskPti(data_02114e30, 0x100) && !_Z20TestFlagInSecondWordPtj(data_02114e30, 0x200)) {
                manual = 1;
                state->rotateRight = 1;
                speed = -0xcc;
            }
            if (returning) {
                oldRotation = model->rotation_;
                int difference = target - oldRotation.y;
                if (oldRotation.y >= target + 0x3243) difference = target + 0x6487 - oldRotation.y;
                speed = difference / 5;
                if (!_Z12TestFlagMaskPti(data_02114e30, 0x100) && !_Z12TestFlagMaskPti(data_02114e30, 0x200) && oldRotation.y == target) nextReturning = 0;
            }
            if (manual || returning) {
                speed *= GameState::GetInstance()->GetTickCount();
                newRotation = model->rotation_;
                newRotation.y += speed;
                if (returning) {
                    if (newRotation.y < target + 0xcc || newRotation.y > target + 0x63bb) newRotation.y = target;
                    if (!(state->rotateLeft && state->rotateRight && newRotation.y != target)) {
                        state->rotateLeft = 0;
                        state->rotateRight = 0;
                    }
                }
                if (newRotation.y < 0) newRotation.y += 0x6487;
                if (newRotation.y >= 0x6487) newRotation.y -= 0x6487;
                model->rotation_ = newRotation;
            }
        }
        state->rotationState.flags = (state->rotationState.flags & ~1) | (nextReturning & 1);
        if (state->model->HasAnimationStopped() || state->model->HasAnimationReachedEnd()) {
            model = state->model;
            const char* animation = (const char*)model->activeAnimationRecord_;
            if (animation && strcmp(data_ov014_021895c8, animation) && strcmp(data_ov014_021895ce, animation)) model->MaybeSetRegularAnimation(data_ov014_021895c8, 0);
        }
    }
    state->unknown92 = 0;
    unsigned int initialized = (unsigned int)data_ov014_02189800[1];
    if (!(initialized & 1)) {
        data_ov014_021895a0[4] = data_020e6d5c;
        data_ov014_02189800[1] = (void*)(initialized | 1);
    }
    if (data_ov014_021895b0[state->phase]) (state->*data_ov014_021895b0[state->phase])();
}
