#include <globaldefs.h>

struct Vector3i { int x,y,z; Vector3i& operator=(const Vector3i&); };
struct Object3D { char pad[0x44]; Vector3i position; int GetHeight() const; };
class GameState { public: static GameState* GetInstance(); Object3D* GetGameObjectByIndex(int); };
struct Random;
int NextRandomMax(Random*, int);
float NextRandomFloat01(Random*);
int fix32ReduceAngle0To2Pi(int);
void Vector3fixMultiplyScalar(const Vector3i*, int, Vector3i*);
int IsValueInRange0216f728(unsigned short*);
void ApplyVec3Tail(void*, int*);
extern "C" {
void Vector3fix_Subtract(const Vector3i*, const Vector3i*, Vector3i*);
int Vector3fix_Length(const Vector3i*);
int fix32_Divide(int,int);
void Vector3fix_Add(const Vector3i*, const Vector3i*, Vector3i*);
void func_ov000_0216d370(void*,int,int,int);
int func_ov000_0216f210(void*,int*);
extern int data_ov000_02183fc8;
struct State0216e678 { unsigned short random,kind; int value4,value8,valueC,value10,value14; };
extern State0216e678 data_ov000_02184270;
struct Options0216e678 { Vector3i v[4]; };
extern const Options0216e678 data_ov000_021832c4;
}
struct Root0216e678 {
    char p0[0x10]; Vector3i position; char p1[0x21c-0x1c]; Random* random;
    char p2[0x258-0x220]; int value258, count;
    unsigned char initialized, state, first, second;
    char p3[0x27c-0x264]; unsigned short* info;
};

// USA: func_ov000_0216e678
// JPN: func_ov000_0216e678
extern "C" ARM void func_ov000_0216e678(Root0216e678* obj, int first, int second, int suppress, int active) {
    GameState* gs = GameState::GetInstance();
    if (!obj->initialized) data_ov000_02183fc8 = 1;
    else data_ov000_02183fc8 = 0;
    if (suppress) data_ov000_02183fc8 = 0;
    func_ov000_0216d370(obj, 0, 1, 1);
    obj->initialized = 1;
    obj->state = 0;
    obj->first = first;
    obj->second = second;
    data_ov000_02184270.value10 = 0;
    data_ov000_02184270.value14 = 0;
    data_ov000_02184270.value4 = 0;
    data_ov000_02184270.kind = 0;
    Random* random = obj->random;
    data_ov000_02184270.random = NextRandomMax(random, 100);
    if (obj->count >= 1 && (obj->count == 5 || NextRandomMax(random, 5 - obj->count) == 0)) active = 1;
    if (active) {
        Object3D* a = gs->GetGameObjectByIndex(obj->first);
        Object3D* b = gs->GetGameObjectByIndex(obj->second);
        if (!a || !b) return;
        Vector3i pa(a->position), pb(b->position), direction, result, offset;
        int height = b->GetHeight();
        Vector3fix_Subtract(&pb, &pa, &direction);
        int length = Vector3fix_Length(&direction);
        if (length != 0) Vector3fixMultiplyScalar(&direction, fix32_Divide(0x1000, length), &direction);
        if (length / 2 > 0x3000) Vector3fixMultiplyScalar(&direction, 0x2000, &offset);
        else Vector3fixMultiplyScalar(&direction, length / 2, &offset);
        Vector3fix_Add(&pa, &offset, &result);
        int ownHeight = a->GetHeight();
        result.y = (int)((float)result.y + 0.75f * (float)ownHeight);
        obj->position = result;
        Options0216e678 options(data_ov000_021832c4);
        options.v[0].x = fix32ReduceAngle0To2Pi(0x2d3c);
        options.v[1].x = fix32ReduceAngle0To2Pi(-0x2d3c);
        options.v[2].x = fix32ReduceAngle0To2Pi(0x505);
        options.v[3].x = fix32ReduceAngle0To2Pi(-0x505);
        int inRange;
        Random* rng = obj->random;
        int index = NextRandomMax(rng, 4);
        inRange = IsValueInRange0216f728(obj->info);
        Vector3i selected(options.v[index]);
        if (height > 0x2800) {
            result.y = height / 2;
            if (result.y < 0x2800) result.y = 0x2800;
            selected.y = (int)(4096.0f * (-1.8f + (0.6f - 0.8f * NextRandomFloat01(rng))));
            data_ov000_02184270.value8 = selected.y;
            if (!inRange) data_ov000_02184270.valueC = (int)(4096.0f * (1.0995574f - 0.7f * (3.1415927f * NextRandomFloat01(rng))));
            if (selected.z < 0x8000) selected.z = 0x8000;
        }
        ApplyVec3Tail(obj, &selected.x);
        obj->count = 0;
        data_ov000_02184270.kind = 5;
        int out;
        obj->value258 = func_ov000_0216f210(obj, &out);
    } else obj->count++;
}
