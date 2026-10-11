#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/Vector.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>

struct BattleState;
struct PartyState;
struct S0204a438;
struct Obj02033874;
struct Bytes02033b88;
struct FieldBlock63d5_12050;
struct BattleView;
#if defined(jpn)
struct BattleWork { char pad0[0x7902]; signed char animationState; };
#else
struct BattleWork { char pad0[0x7712]; signed char animationState; };
#endif

struct FormationStats {
    char pad0[0x3c];
    unsigned int low : 30;
    unsigned int group : 1;
    unsigned int high : 1;
    unsigned short GetGroup() { return group; }
};
S0204a438* GetField0x3b0Value(GameState*);
Object3D* GetField0x21c(S0204a438*);
int ClassifyField0x81fe(char*);
int TestBitAt0x34(unsigned char*, unsigned int);
extern "C" void _Z24SetVecYFromValue02033874P11Obj02033874i(Obj02033874*, int);
void SetByte0xbeShiftPrev(Bytes02033b88*, int);
void SetField0x3b0Value(GameState*, int);
extern "C" void _Z30InitCombatantPosition_0216118cPvi(void*, int);
extern "C" void _Z38RunFlaglearAndSetMode02167e6c_02167e6cPh(unsigned char*);
void ClearCombatantSlot(GameState*, int);
void ClearByte0x63d5(FieldBlock63d5_12050*);
extern "C" {
int func_ov000_0215e9fc(BattleState*, short*, int, int);
int func_ov000_02160f14(BattleWork*);
void func_ov026_021daec8(BattleState*, BattleView*, int);
void func_ov000_021626a0(BattleWork*, int, int);
void __clear(void*, int);
}
struct BoneLabels { signed char letters[2]; };
extern const BoneLabels data_ov026_021de6a0;
extern const char data_ov026_021dee57[];

// JPN: func_ov026_021dc710
// USA: func_ov026_021dc040
extern "C" ARM int func_ov026_021dc040(SafeAllocator* allocator, BattleWork* self, BattleState* battle, PartyState* party) {
    GameState* game = GameState::GetInstance();
    S0204a438* camera = GetField0x3b0Value(game);
    if (!camera) return 1;
    Object3D* animation = GetField0x21c(camera);
    if (!animation) return 1;
    GameObject* formation = game->GetGameObjectByIndex(0xcf);
    if (!formation) return 1;
    formation->obj3D_.MaybeUpdateBonePositions();
    Model3D* model = formation->obj3D_.pModel_;
    if (model) {
        short members[4];
        int count = func_ov000_0215e9fc(battle, members, 4, 0);
        if (ClassifyField0x81fe((char*)battle)) count = 1;
        if (count > 0) {
            Vector3fix center = {};
            int groupCounts[2] = {};
            for (int index = 0; index < count; ++index) {
                if (TestBitAt0x34((unsigned char*)party, (unsigned char)members[index])) {
                    GameObject* member = GetCombatantWithFlag0x100(game, members[index]);
                    if (member && member->obj3D_.pModel_) {
                        FormationStats* stats = (FormationStats*)member->baseStats_;
                        ++groupCounts[stats->GetGroup()];
                        BoneLabels labels = data_ov026_021de6a0;
                        char name[6];
                        int group = ((FormationStats*)member->baseStats_)->GetGroup();
                        sprintf(name, data_ov026_021dee57, labels.letters[group], groupCounts[group]);
                        Object3D::TrackedBoneMatrix* bone = formation->obj3D_.GetTrackedBoneMatrix(model->GetBoneIndex(name));
                        if (bone) {
                            Vector3fix position;
                            position.x = bone->matrix.translation.x;
                            position.y = bone->matrix.translation.y;
                            position.z = bone->matrix.translation.z;
                            Vector3fixMultiplyScalar(&position, 266, &position);
                            member->obj3D_.position_ = position;
                            _Z24SetVecYFromValue02033874P11Obj02033874i((Obj02033874*)member, fix32_Atan2(bone->matrix.rotation.rows[2].x, bone->matrix.rotation.rows[2].z));
                            Vector3fix_Add(&center, &position, &center);
                        }
                    }
                }
            }
            Vector3fixMultiplyScalar(&center, (int)(4096.0f * (1.0f / (float)count)), &center);
            int offset = -center.x;
            for (int index = 0; index < count; ++index) {
                if (TestBitAt0x34((unsigned char*)party, (unsigned char)members[index])) {
                    GameObject* member = GetCombatantWithFlag0x100(game, members[index]);
                    if (member) {
                        Vector3fix position = member->obj3D_.position_;
                        position.x += offset;
                        position.y = 204;
                        member->obj3D_.position_ = position;
                    }
                }
            }
        }
    }
    if (self->animationState == 0 && !animation->HasAnimationStopped()) return 0;
    if (self->animationState != 6) {
        for (int index = 0; index < 4; ++index) {
            if (TestBitAt0x34((unsigned char*)party, (unsigned char)index)) {
                GameObject* member = GetCombatantWithFlag0x100(game, index);
                if (member) {
                    member->obj3D_.RemoveAnimationPackageByID(3);
                    SetByte0xbeShiftPrev((Bytes02033b88*)member, 0);
                    _Z24SetVecYFromValue02033874P11Obj02033874i((Obj02033874*)member, 0x3244);
                }
            }
        }
        SetField0x3b0Value(game, func_ov000_02160f14(self));
        _Z30InitCombatantPosition_0216118cPvi(self, 1);
        _Z38RunFlaglearAndSetMode02167e6c_02167e6cPh((unsigned char*)self);
        func_ov026_021daec8(battle, (BattleView*)func_ov000_02160f14(self), 1);
        func_ov000_021626a0(self, 0x26, 0);
        func_ov000_021626a0(self, 0x27, 1);
        allocator->Reset();
        ClearCombatantSlot(game, 0xcf);
        ClearByte0x63d5((FieldBlock63d5_12050*)game);
    }
    return 1;
}
