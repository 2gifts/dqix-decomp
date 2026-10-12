#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/Vector.h>
#include <Resource/GameResources.h>

struct Trajectory020ad61c {
    unsigned char field0[0x44];
    Vector3i position;
    unsigned char field50[0x5e];
    short angle;
    unsigned char fieldb0[0x80];
    int wrapFlags;
    unsigned char field134[8];
    int state;
    int field140;
    int saved144;
    int saved148;
    unsigned short phase;
    unsigned short field14e;
    int bobHeight;
    unsigned char field154[16];
    Vector3i firstPosition;
    int firstAngle;
    Vector3i secondPosition;
    int secondAngle;
};
struct World020ad61c {
    unsigned short tag;
    unsigned char field2[0x27b6];
    Vector3i position;
    int angle;
};
struct HeadNode02046b24;
struct Touch020ad61c {
    unsigned char field0[0x38];
    int x;
    int y;
    unsigned char field40[4];
    unsigned int count;
    unsigned char field48[12];
    unsigned char active;
};
struct Flag020ad61c {
    unsigned char field0[13];
    unsigned char flags;
};
struct Vec3copy0202ec84 {
    unsigned int v[3];
};
struct Entity020AE398;
struct Obj020ae3f4;
extern "C" World020ad61c* func_02012fe4(void);
extern "C" void func_020332ac(Trajectory020ad61c*);
extern "C" void func_020adda4(Trajectory020ad61c*);
extern "C" void func_020adaac(Trajectory020ad61c*);
void SubtractHeightOffset020ae398(Entity020AE398*);
void UpdateFallMotion020ae3f4(Obj020ae3f4*);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
void SetByteField0x253(void*);
int GetField0x3b0Value(GameState*);
int ComputeTwoFromVec3_0202ec84(void*, Vec3copy0202ec84*, int*, int*);
extern "C" int func_02018fbc(World020ad61c*, Vec3copy0202ec84*);
int IsField0Null(void**);
int TestFlag0SetAndFlag1Clear(unsigned short*, int);
extern "C" void func_ov017_021a72f4(GameResources*, int);
extern short data_020e9450[];
extern Touch020ad61c data_02114e54;
extern unsigned short data_02114e30;
extern Flag020ad61c data_ov017_021d82fc;

// USA: func_020ad61c
extern "C" ARM void func_020ad61c(Trajectory020ad61c* object) {
    World020ad61c* world;
    int touchX;
    int touchY;
    GameState* game = GameState::GetInstance();
    world = func_02012fe4();
    int saved144 = object->saved144;
    int saved148 = object->saved148;
    func_020332ac(object);
    func_020adda4(object);
    switch (object->state) {
    case 0:
        func_020adaac(object);
        world->position = object->position;
        world->angle = object->angle;
        object->field140 = 0;
        break;
    case 1:
        SubtractHeightOffset020ae398((Entity020AE398*)object);
        break;
    case 2:
        UpdateFallMotion020ae3f4((Obj020ae3f4*)object);
        break;
    }
    object->saved144 = saved144;
    object->saved148 = saved148;
    object->phase += game->GetTickCount() * 364;
    object->bobHeight = data_020e9450[(object->phase >> 4) * 2 + 1] >> 4;
    if (world->tag != 0x2774) return;
    Vector3i position;
    position = object->position;
    object->wrapFlags = 0;
    if (position.x >= 0x90000) {
        object->wrapFlags |= 1;
        position.x -= 0x120000;
        object->firstPosition.x -= 0x120000;
        object->secondPosition.x -= 0x120000;
    } else if (position.x < -0x90000) {
        object->wrapFlags |= 2;
        position.x += 0x120000;
        object->firstPosition.x += 0x120000;
        object->secondPosition.x += 0x120000;
    }
    if (position.z >= 0x70000) {
        object->wrapFlags |= 4;
        position.z -= 0xe0000;
        object->firstPosition.z -= 0xe0000;
        object->secondPosition.z -= 0xe0000;
    } else if (position.z < -0x70000) {
        object->wrapFlags |= 8;
        position.z += 0xe0000;
        object->firstPosition.z += 0xe0000;
        object->secondPosition.z += 0xe0000;
    }
    object->position = position;
    GameResources* scene = func_ov017_0218b5b0();
    void* camera;
    int groundedHit;
    HeadNode02046b24** head = (HeadNode02046b24**)scene->unknown_ptr_array_36fc[0];
    GameObject* actor = game->GetUnknownGameObject();
    if (actor && GetHeadNodeIdOrMinusOne(head) != 3) {
        actor->obj3D_.position_ = object->position;
        SetByteField0x253(actor);
    }
    camera = (void*)GetField0x3b0Value(game);
    int directHit = 0;
    groundedHit = 0;
    int screenX[3];
    int screenY[3];
    Vec3copy0202ec84 points[3] = {};
    points[0] = *(Vec3copy0202ec84*)&object->position;
    points[1] = *(Vec3copy0202ec84*)&object->firstPosition;
    points[2] = *(Vec3copy0202ec84*)&object->secondPosition;
    for (int i = 0; i < 3; i++) ComputeTwoFromVec3_0202ec84(camera, &points[i], &screenX[i], &screenY[i]);
    if (data_02114e54.active && data_02114e54.count < 10) {
        touchX = data_02114e54.x;
        touchY = data_02114e54.y;
    }
    for (int i = 0; i < 3; i++) {
        if (screenX[i] - 16 < touchX && touchX < screenX[i] + 16 &&
            screenY[i] - 24 < touchY && touchY < screenY[i] + 8) {
            directHit = 1;
            break;
        }
    }
    if (!directHit) {
        for (int i = 0; i < 3; i++) {
            points[i].v[1] = func_02018fbc(world, &points[i]);
            ComputeTwoFromVec3_0202ec84(camera, &points[i], &screenX[i], &screenY[i]);
            if (screenX[i] - 16 < touchX && touchX < screenX[i] + 16 &&
                screenY[i] - 24 < touchY && touchY < screenY[i] + 8) {
                groundedHit = 1;
                break;
            }
        }
    }
    if (IsField0Null((void**)head) && object->state == 0) {
        if (TestFlag0SetAndFlag1Clear(&data_02114e30, 1) || groundedHit) {
            func_ov017_021a72f4(scene, 1);
        } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2) || directHit) {
            func_ov017_021a72f4(scene, 0);
        } else if (TestFlag0SetAndFlag1Clear(&data_02114e30, 256)) {
            if (!(data_ov017_021d82fc.flags & 16)) data_ov017_021d82fc.flags |= 16;
        }
    }
}
