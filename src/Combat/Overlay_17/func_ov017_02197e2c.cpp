#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "World/Zone3D.h"

struct InteractionPlayer { Object3D obj; char padac[0x12]; unsigned char mode; };
struct InteractionReset {
#if defined(jpn)
    char pad[0xf0];
#else
    char pad[0x150];
#endif
    unsigned char mode : 6;
    unsigned char flags : 2;
};
struct InteractionRequest { unsigned char type; char pad1; short index; int field4; ZoneChestRenderRecord* point; int fieldc; short angle; short direction; };
struct S02046b1c;
struct Vec3;
extern "C" Zone3D* func_02012fe4();
void* GetGlobalField0x1c020421a0();
void* GetField0x3b0Value_020100bc(GameState*);
bool CheckSubstructByte0x7cPositive_020535c8(signed char*);
void* GetField0x0List02046b1c(S02046b1c*);
ZoneChestRenderRecord* GetElementStride0x24_020177a8(unsigned char*, int);
int fix32abs(int);
extern "C" int func_020c32f8(int);
extern "C" int func_020c3260(int);
extern "C" float func_0200c700(int);
int GetAbsAngleDeltaBetween_021a4754(Vec3*, int, Vec3*);
InteractionReset* GetGlobalResetObj020d7a50();
void InitObj0219a674(unsigned char*);
extern "C" void func_ov017_0219b33c(GameResources*, InteractionRequest*);

static inline int MultiplyFix(int a, int b) { return (int)(((long long)a * b + 0x800) >> 12); }

// USA: func_ov017_02197e2c
extern "C" ARM void func_ov017_02197e2c(GameResources* resources) {
    GameState* game = GameState::GetInstance();
    Zone3D* zone = func_02012fe4();
    GetGlobalField0x1c020421a0();
    GetField0x3b0Value_020100bc(game);
    InteractionPlayer* player = (InteractionPlayer*)game->GetUnknownGameObject();
    Vector3i* position = &player->obj.position_;
    if (CheckSubstructByte0x7cPositive_020535c8((signed char*)player)) return;
    if (!zone->numChests_) return;
    int direction = 0;
    int hasList = 0;
    void* list = GetField0x0List02046b1c((S02046b1c*)resources->unknown_ptr_array_36fc[0]);
    if (list) hasList = 1;
    int bestAngle = 0x3244;
    ZoneChestRenderRecord* candidate = 0;
    ZoneChestRenderRecord* selected = 0;
    int selectedIndex = -1;
    for (int i = 0; i < zone->numChests_; i++) {
        candidate = GetElementStride0x24_020177a8((unsigned char*)zone, i);
        if (!candidate) continue;
        Vector3i distance;
        Vector3i delta = *position;
        Vector3i point = candidate->position;
        if (fix32abs(delta.y - point.y) > 0x1000) continue;
        delta.y = 0;
        point.y = 0;
        Vector3fix_Subtract(&delta, &point, &delta);
        distance = delta;
        int squared = MultiplyFix(delta.x, delta.x) + MultiplyFix(delta.z, delta.z);
        if (squared > 0x1800) continue;
        Vector3i rotated = *position;
        rotated.y = 0;
        Vector3fix_Subtract(&rotated, &point, &rotated);
        int angle = -(candidate->angleY - 0x6487);
        int cosine = (int)(4096.0f * (func_0200c700(func_020c32f8(angle)) / 4294967296.0f));
        int sine = (int)(4096.0f * (func_0200c700(func_020c3260(angle)) / 4294967296.0f));
        Matrix3x3 rotation;
        Mat3x3_WriteRotationY(&rotation, sine, cosine);
        Mat3x3_ApplyToVector(&rotated, &rotation, &rotated);
        int difference = GetAbsAngleDeltaBetween_021a4754((Vec3*)position, (short)player->obj.rotation_.y, (Vec3*)&point);
        if (difference >= bestAngle) continue;
        bestAngle = difference;
        selectedIndex = i;
        selected = candidate;
        direction = fix32_Atan2(distance.x, distance.z);
    }
    if (hasList || selectedIndex < 0 || !candidate || !selected) return;
    if (player->mode != 0 && player->mode != 1) return;
    if ((selected->secondPass == 1 || selected->secondPass == 2) && selected->active != 1) return;
    InteractionReset* reset = GetGlobalResetObj020d7a50();
    int enabled = selected->active == 1 ? 1 : 0;
    if (!enabled) return;
    if (reset->mode > 1) return;
    InteractionRequest request;
    InitObj0219a674((unsigned char*)&request);
    request.type = 2;
    request.angle = GetAbsAngleDeltaBetween_021a4754((Vec3*)&player->obj.position_, (short)player->obj.rotation_.y, (Vec3*)&selected->position);
    request.point = selected;
    request.index = selectedIndex;
    request.direction = direction;
    if (request.angle >= 0xc91) return;
    func_ov017_0219b33c(resources, &request);
}
