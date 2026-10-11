#include <globaldefs.h>

struct Vector3i { int x,y,z; Vector3i& operator=(const Vector3i&); };
struct Object3D { char pad[0x44]; Vector3i position; int GetHeight() const; };
class GameState { public: static GameState* GetInstance(); Object3D* GetGameObjectByIndex(int); };
int fix32ReduceAngle0To2Pi(int);
int fix32SignedAngleDistance(int,int);
int fix32abs(int);
void Vector3fixMultiplyScalar(const Vector3i*, int, Vector3i*);
int IsValueInRange0216f728(unsigned short*);
void ApplyVec3Tail(void*, int*);
int GetField0x7c(void*);
extern "C" void _Z33SetField0x7cClearFields0x1ec0x1eePht(unsigned char*, int);
extern "C" {
void Vector3fix_Subtract(const Vector3i*, const Vector3i*, Vector3i*);
int Vector3fix_Length(const Vector3i*);
int Vector3fix_Distance(const Vector3i*,const Vector3i*);
int fix32_Divide(int,int);
int fix32_Atan2(int,int);
void Vector3fix_Add(const Vector3i*, const Vector3i*, Vector3i*);
void func_0202e5d8(void*,int,int,int);
extern int data_ov000_02183fc8;
struct State0216ea38 { unsigned short random,kind; int value4,value8,valueC,value10,value14; };
extern State0216ea38 data_ov000_02184270;
extern const int data_ov000_02183268[];
extern const int data_ov000_02183298[];
extern const short data_ov000_0218325c[];
}
struct Root0216ea38 {
    char p0[0x10]; Vector3i position; char p1[0x70-0x1c]; Vector3i angles;
    char p2[0x260-0x7c]; unsigned char initialized,state,first,second;
    char p3[0x27c-0x264]; unsigned short* info;
};

// USA: func_ov000_0216ea38
// JPN: func_ov000_0216ea38
extern "C" ARM void func_ov000_0216ea38(Root0216ea38* obj) {
    if (!obj->initialized) return;
    GameState* gs = GameState::GetInstance();
    data_ov000_02184270.value10 += 0xcc;
    data_ov000_02184270.value14 += 0x14;
    data_ov000_02184270.value4 += 4;
    Object3D* a = gs->GetGameObjectByIndex(obj->first);
    Object3D* b = gs->GetGameObjectByIndex(obj->second);
    if (!a || !b) return;
    int ah = a->GetHeight(), bh = b->GetHeight();
    int reverse = 0;
    if (ah >= 0x2000) reverse = 1;
    if (bh >= 0x2000) reverse = 0;
    if (bh < 0x2000 && ah < 0x2000) reverse = data_ov000_02184270.random % 2;
    Vector3i pa(a->position), pb(b->position), direction, result, offset;
    Vector3fix_Subtract(&pb, &pa, &direction);
    int length = Vector3fix_Length(&direction);
    if (length) Vector3fixMultiplyScalar(&direction, fix32_Divide(0x1000,length), &direction);
    if (length / 2 > 0x3000) Vector3fixMultiplyScalar(&direction,0x2000,&offset);
    else Vector3fixMultiplyScalar(&direction,length/2,&offset);
    if (!reverse) {
        Vector3fix_Add(&pa,&offset,&result);
        int h = a->GetHeight();
        result.y = (int)((float)result.y + 0.75f*(float)h);
    } else {
        Vector3fixMultiplyScalar(&offset,-0x1000,&offset);
        Vector3fix_Add(&pb,&offset,&result);
        int h = b->GetHeight();
        result.y = (int)((float)result.y + 0.75f*(float)h);
    }
    if (result.y > 0x1000) result.y = 0x1000;
    Vector3i moved, delta, old(obj->position);
    Vector3fix_Subtract(&result,&old,&delta);
    int distance = Vector3fix_Length(&delta);
    Vector3fixMultiplyScalar(&delta,0xcc,&delta);
    int step = Vector3fix_Length(&delta);
    if (data_ov000_02184270.value10 < step)
        Vector3fixMultiplyScalar(&delta,fix32_Divide(data_ov000_02184270.value10,step),&delta);
    Vector3fix_Add(&old,&delta,&moved);
    if (data_ov000_02184270.kind == 0) {
        if (distance < 0x5000) obj->state = 1;
    } else data_ov000_02184270.kind--;
    Vector3i angles(obj->angles);
    int firstAngle,firstDistance,secondAngle,secondDistance;
    if (!reverse) {
        int angle = fix32_Atan2(direction.x,direction.z);
        firstAngle = fix32ReduceAngle0To2Pi((int)(11581.19921875f + (float)angle));
        secondAngle = fix32ReduceAngle0To2Pi((int)((float)angle - 11581.19921875f));
        firstDistance = fix32abs(fix32SignedAngleDistance(angles.x,firstAngle));
        secondDistance = fix32abs(fix32SignedAngleDistance(angles.x,secondAngle));
    } else {
        int angle = fix32_Atan2(direction.x,direction.z);
        firstAngle = fix32ReduceAngle0To2Pi((int)(12868.0f + (11581.19921875f + (float)angle)));
        secondAngle = fix32ReduceAngle0To2Pi((int)(12868.0f + ((float)angle - 11581.19921875f)));
        firstDistance = fix32abs(fix32SignedAngleDistance(angles.x,firstAngle));
        secondDistance = fix32abs(fix32SignedAngleDistance(angles.x,secondAngle));
    }
    if (firstDistance >= secondDistance) firstAngle = secondAngle;
    int desiredY = 0x1000;
    int desiredZ;
    if (data_ov000_02184270.random < 30) {
        float scaledDistance = (float)Vector3fix_Distance(&pa,&pb);
        scaledDistance *= 1.6f;
        desiredZ = (int)scaledDistance;
        if (desiredZ < 0x7000) desiredZ = 0x7000;
    } else {
        int index = (obj->first + obj->second) % 3;
        desiredZ = data_ov000_02183268[index];
        desiredY = data_ov000_02183298[index];
    }
    int inRange = IsValueInRange0216f728(obj->info);
    if (bh > 0x2800) {
        result.y = bh / 2;
        if (result.y < 0x2800) result.y = 0x2800;
        moved.y = result.y;
        desiredY = data_ov000_02184270.value8;
        if (!inRange) firstAngle = fix32ReduceAngle0To2Pi(firstAngle + data_ov000_02184270.valueC);
        if (desiredZ < 0x8000) desiredZ = 0x8000;
    }
    int desiredTail = data_ov000_0218325c[(obj->first + obj->second) % 5];
    if (data_ov000_02183fc8) {
        obj->position = result;
        func_0202e5d8(obj,firstAngle,desiredY,desiredZ);
        _Z33SetField0x7cClearFields0x1ec0x1eePht((unsigned char*)obj,desiredTail);
        data_ov000_02183fc8 = 0;
    } else {
        if (moved.y > 0x2000) moved.y = 0x2000;
        obj->position = moved;
        Vector3i next(angles);
        int difference = (int)(0.05f*(float)fix32SignedAngleDistance(angles.x,firstAngle));
        int limit = data_ov000_02184270.value14;
        if (limit < fix32abs(difference)) {
            if (difference > 0) difference = limit;
            else difference = -limit;
        }
        next.x = fix32ReduceAngle0To2Pi(angles.x+difference);
        next.y = (int)((float)angles.y + 0.02f*(float)(desiredY-angles.y));
        next.z = (int)((float)angles.z + 0.02f*(float)(desiredZ-angles.z));
        ApplyVec3Tail(obj,&next.x);
        int change, tailLimit;
        int tail = GetField0x7c(obj);
        float scaledChange = (float)fix32SignedAngleDistance(tail,desiredTail);
        scaledChange *= 0.1f;
        change = (int)scaledChange;
        tailLimit = data_ov000_02184270.value4;
        if (tailLimit < fix32abs(change)) {
            if (change > 0) change = tailLimit;
            else change = -tailLimit;
        }
        if (change) _Z33SetField0x7cClearFields0x1ec0x1eePht((unsigned char*)obj,(short)fix32ReduceAngle0To2Pi(change+tail));
    }
}
