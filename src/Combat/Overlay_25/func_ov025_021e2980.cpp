#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"

struct AnimationCommand {
    unsigned char padding0[8];
    const char* animation;
    unsigned short animationFlags;
    unsigned char target;
    unsigned char flags;
};
struct AnimationTargets {
    unsigned short kind;
    unsigned char padding2[8];
    unsigned char flags;
};
struct AnimationCombatant {
    Object3D object;
    unsigned char paddingac[0x12];
    unsigned char state;
};
struct AnimationGlobals {
#if defined(jpn)
    unsigned char padding0[0xc];
#else
    unsigned char padding0[0x1c];
#endif

    unsigned int flags;
};
struct AnimationWork {
#if defined(jpn)
    unsigned char padding0[0x71c4];
#else
    unsigned char padding0[0x6fd4];
#endif

    unsigned char faded;
};
struct S0204a438;
struct AngleTrig0202e9a4;
struct Obj02048c90;
struct Bytes02033b88;
struct Obj0205eaa0;
extern AnimationGlobals data_ov025_021ef988;
extern char data_ov025_021ef7d9[];
extern char data_ov025_021ef7df[];
extern char data_ov025_021ef7e6[];
extern Obj0205eaa0 data_02108760;
int GetField0x3b0Value(GameState*);
int GetFlags(int);
Object3D* GetField0x21c(S0204a438*);
void SetAngleAndTrigTable0202e9a4(AngleTrig0202e9a4*, int);
extern "C" void func_0204a170(int);
int DispatchByIndex021820bc(void*, int, int, int);
void ResetInnerState02048c90(Obj02048c90*);
void ClearSubstructFlag0x4(unsigned char*);
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
AnimationWork* GetActiveCombatWork();
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);

// JPN: func_ov025_021e2e70
// USA: func_ov025_021e2980
extern "C" ARM int func_ov025_021e2980(AnimationCommand* command, AnimationTargets* targets, int unused, void* context) {
    GameState* game = GameState::GetInstance();
    if (command->target == 0x19) {
        int camera = GetField0x3b0Value(game);
        if (GetFlags(camera) & 0x10) {
            Object3D* object = GetField0x21c((S0204a438*)camera);
            if (object) {
                SetAngleAndTrigTable0202e9a4((AngleTrig0202e9a4*)camera, 0xf000);
                object->MaybeSetRegularAnimation(command->animation, command->animationFlags);
                func_0204a170(camera);
                data_ov025_021ef988.flags |= 8;
            }
        }
    } else {
        int ids[8];
        int count = DispatchByIndex021820bc(context, (int)targets, command->target, (int)ids);
        if (!count) return 1;
        for (int i = 0; i < count; i++) {
            AnimationCombatant* combatant = (AnimationCombatant*)game->GetGameObjectByIndex(ids[i]);
            if (!combatant) continue;
            if (combatant->object.unknown_0_ & 0x80) {
                ResetInnerState02048c90((Obj02048c90*)combatant);
                ClearSubstructFlag0x4((unsigned char*)combatant);
                int state = combatant->state;
                if (state != 0 && state != 4 && state != 6)
                    SetByte0xbeShiftPrev((Bytes02033b88*)combatant, 0);
            }
            combatant->object.SetAnimationPlaybackSpeed(0x1000, 0);
            combatant->object.SkipAnimationTransition();
            if (!combatant->object.MaybeSetRegularAnimation(command->animation, command->animationFlags) &&
                strcmp(command->animation, data_ov025_021ef7d9) == 0) {
                if (!combatant->object.MaybeSetRegularAnimation(data_ov025_021ef7df, command->animationFlags))
                    combatant->object.MaybeSetRegularAnimation(data_ov025_021ef7e6, command->animationFlags);
            }
        }
        LightingManager* lighting = LightingManager::GetInstance();
        if (!(command->flags & 2) && targets->kind != 1 && targets->kind != 2 && targets->kind != 0xdb) {
            AnimationWork* work = GetActiveCombatWork();
            if (!work->faded) {
                lighting->BeginFade(0x999, 300);
                work->faded = 1;
            }
        }
        const char* animation = command->animation;
        if (strcmp(animation, data_ov025_021ef7e6) == 0 ||
            strcmp(animation, data_ov025_021ef7d9) == 0 ||
            strcmp(animation, data_ov025_021ef7df) == 0) {
            if (!(command->flags & 1)) {
                if (targets->flags & 1) DispatchWithShortB4_0205eaa0(&data_02108760, 0x66, 0);
                else DispatchWithShortB4_0205eaa0(&data_02108760, 0x64, 0);
            }
            lighting->BeginFade(0x4cc, 1000);
            data_ov025_021ef988.flags |= 0x200;
        } else {
            data_ov025_021ef988.flags |= 1;
        }
    }
    data_ov025_021ef988.flags |= 4;
    return 1;
}
