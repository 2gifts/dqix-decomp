// JPN: func_ov017_021abae0
#include <globaldefs.h>

#if defined(jpn)
enum { kGlobalByteOffset = 0x850, kResourceHeaderOffset = 0x4fc, kResourceTailOffset = 0x4ec };
#else
enum { kGlobalByteOffset = 0x830, kResourceHeaderOffset = 0x70c, kResourceTailOffset = 0x6fc };
#endif

#include "Combat/Main/CopyRecord0200fbb4.h"
#include "GameState/GameState.h"

extern "C" void* func_0202ae18(void);
extern "C" void* func_02012fe4(void);

struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);
extern "C" void _ZN8Object3D10EnableFlagEi(unsigned char* obj, unsigned int mask);
extern "C" void _ZN8Object3D11DisableFlagEi(unsigned char* obj, unsigned int mask);

extern "C" int _Z22fix32ReduceAngle0To2Pii(int angle);
extern "C" int _Z8fix32sini(int angle);
extern "C" int _Z8fix32cosi(int angle);

struct Vec3 { int x; int y; int z; };
extern "C" int fix32_Atan2(int x, int z);

struct Obj02033834;
void SetVecYByMode02033834(struct Obj02033834* obj, int arg);
struct Obj02033b68;
void SetByteIfChanged02033b68(struct Obj02033b68* obj, int newVal);
struct Foo02033b58;
void SetByteSavingPrevious(struct Foo02033b58* p, unsigned char v);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void* obj, int value, int frames);
extern "C" int _Z28IsBrightnessTransitionActiveP13GameResources(int* obj);

extern "C" unsigned char _Z19CopyOutRegion0x5718PcPv(void* src, void* dst);
#define CopyOutRegion0x5718 _Z19CopyOutRegion0x5718PcPv

void* GetField0x3f8Address(GameState* battleStruct);
int GetField0x3acValue(GameState* battleStruct);
extern "C" void VectorizedMemset(void* dst, int val, int size);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
void InitAndResetHeader_0219e310(unsigned char* obj, int flag);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(struct TailList020469b4* list, struct TailNode020469b4* node);

struct PosData_021ab280 {
    char pad0[8];
    int x, y, z;               // 0x8, 0xc, 0x10
    char pad1[0x20 - 0x14];
    short angle;                 // 0x20
    char pad2[0x30 - 0x22];
    unsigned short half30;        // 0x30
    char pad3[0x38 - 0x32];
    struct Vec3 vecArr[4];         // 0x38, 0x44, 0x50, 0x5c
    short half68;                   // 0x68
    short half6a;                    // 0x6a
};

struct Obj_021ab280 {
    char pad0[1];
    unsigned char field1;        // 0x1
    char pad1[8 - 2];
    int state;                     // 0x8
    int counter;                    // 0xc
    struct PosData_021ab280* pos;    // 0x10
    struct Vec3 vec14;                // 0x14
};

// USA: func_ov017_021ab280
extern "C" ARM int func_ov017_021ab280(struct Obj_021ab280* obj) {
    GameState* battle = GameState::GetInstance();
    func_0202ae18();
    unsigned char* mgr = (unsigned char*)func_ov017_0218b5b0();
    GameObject* combatant = battle->GetUnknownGameObject();
    void* g = func_02012fe4();

    int state = obj->state;
    if (state == 0) {
        CancelPendingAction020397cc((struct Obj020397cc*)combatant, 1);
        _ZN8Object3D10EnableFlagEi((unsigned char*)combatant, 0x01000080);

        struct Vec3 dir;
        struct Vec3 saved = *(struct Vec3*)((char*)combatant + 0x44);
        int angleY = _Z22fix32ReduceAngle0To2Pii(obj->pos->angle + (int)0xffffcdc3);
        dir.x = _Z8fix32sini(angleY);
        dir.y = 0;
        dir.z = _Z8fix32cosi(angleY);
        Vector3fix_Normalize((const Vector3fix*)&dir, (Vector3fix*)&dir);
        Vector3fix_Add((const Vector3fix*)((struct Vec3*)&obj->pos->x), (const Vector3fix*)&dir, (Vector3fix*)&obj->vec14);
        Vector3fix_Subtract((const Vector3fix*)&obj->vec14, (const Vector3fix*)&saved, (Vector3fix*)&dir);
        Vector3fix_Normalize((const Vector3fix*)&dir, (Vector3fix*)&dir);
        int angle2 = fix32_Atan2(dir.x, dir.z);

        SetVecYByMode02033834((struct Obj02033834*)combatant, angle2);
        SetByteIfChanged02033b68((struct Obj02033b68*)combatant, 1);
        _Z13SetBrightnessP13GameResourcesii(mgr, -16, 15);

        obj->state = obj->state + 1;
        obj->counter = 0;
    } else if (state == 1) {
        int gVal = *((unsigned char*)g + kGlobalByteOffset);
        if (gVal <= 4) {
            obj->state = state + 1;
            obj->counter = 0;
            SetByteSavingPrevious((struct Foo02033b58*)combatant, 1);
        }
    } else if (state == 2) {
        struct Vec3 delta;
        struct Vec3 saved = *(struct Vec3*)((char*)combatant + 0x44);
        Vector3fix_Subtract((const Vector3fix*)&obj->vec14, (const Vector3fix*)&saved, (Vector3fix*)&delta);
        Vector3fix_Length((const Vector3fix*)((int*)&delta));
        Vector3fix_Subtract((const Vector3fix*)&obj->vec14, (const Vector3fix*)&saved, (Vector3fix*)&delta);
        Vector3fix_Normalize((const Vector3fix*)&delta, (Vector3fix*)&delta);
        int angle2 = fix32_Atan2(delta.x, delta.z);

        SetVecYByMode02033834((struct Obj02033834*)combatant, angle2);
        SetByteSavingPrevious((struct Foo02033b58*)combatant, 1);
        *(unsigned short*)((char*)combatant + 0xb2) = 0xa3;

        if (_Z28IsBrightnessTransitionActiveP13GameResources((int*)mgr) == 0) {
            obj->state = 4;
            obj->counter = 0;
        }
    } else if (state == 3) {
        struct Vec3 delta;
        struct Vec3 saved = *(struct Vec3*)((char*)combatant + 0x44);
        Vector3fix_Subtract((const Vector3fix*)&obj->vec14, (const Vector3fix*)&saved, (Vector3fix*)&delta);
        Vector3fix_Normalize((const Vector3fix*)&delta, (Vector3fix*)&delta);
        int angle2 = fix32_Atan2(delta.x, delta.z);

        SetVecYByMode02033834((struct Obj02033834*)combatant, angle2);
        SetByteSavingPrevious((struct Foo02033b58*)combatant, 1);
        *(unsigned short*)((char*)combatant + 0xb2) = 0xa3;

        if (_Z28IsBrightnessTransitionActiveP13GameResources((int*)mgr) == 0) {
            obj->state = obj->state + 1;
            obj->counter = 0;
        }
    } else if (state == 4) {
        _ZN8Object3D11DisableFlagEi((unsigned char*)combatant, 0x01000080);

        unsigned char buf[4];
        unsigned char count = CopyOutRegion0x5718((void*)battle, buf);
        for (int i = 0; i < count; i++) {
            GameObject* c = battle->GetGameObjectByIndex(buf[i]);
            if (c != 0) {
                _ZN8Object3D11DisableFlagEi((unsigned char*)c, 0x1000000);
            }
        }

        void* entryV = GetField0x3f8Address(battle);
        GetField0x3acValue(battle);
        VectorizedMemset(entryV, 0, 0x70);
        unsigned char* e = (unsigned char*)entryV;
        unsigned char one = 1;
        e[4] = one;
        e[8] = one;
        e[9] = one;
        int negOneB = one - 2;
        *(signed char*)(e + 0xb) = negOneB;
        *(int*)(e + 0x20) = negOneB;
        *(int*)(e + 0x24) = negOneB;
        *(int*)(e + 0x28) = negOneB;
        *(int*)(e + 0x2c) = negOneB;
        *(short*)(e + 0x1e) = negOneB;
        e[0xc] = 0;
        *(short*)(e + 0x6c) = negOneB;

        *(unsigned short*)(e + 0) = obj->pos->half30;
        _ZN8Vector3iaSERKS_((int*)(e + 0x10), (int*)&obj->pos->vecArr[0]);
        *(short*)(e + 0x1c) = obj->pos->half68;
        e[0xb] = (unsigned char)obj->pos->half6a;
        _ZN8Vector3iaSERKS_((int*)(e + 0x30), (int*)&obj->pos->vecArr[0]);
        _ZN8Vector3iaSERKS_((int*)(e + 0x3c), (int*)&obj->pos->vecArr[1]);
        _ZN8Vector3iaSERKS_((int*)(e + 0x48), (int*)&obj->pos->vecArr[2]);
        _ZN8Vector3iaSERKS_((int*)(e + 0x54), (int*)&obj->pos->vecArr[3]);

        e[0xc] = 1;
        e[7] = 1;
        _Z28CallFunc0200fbb4AtField0x3f8Pv(battle, entryV);

        InitAndResetHeader_0219e310(*(unsigned char**)(mgr + 0x3000 + kResourceHeaderOffset), 0);
        AppendNodeToTail(*(struct TailList020469b4**)(mgr + 0x3000 + kResourceTailOffset),
                          *(struct TailNode020469b4**)(mgr + 0x3000 + kResourceHeaderOffset));

        obj->field1 = 1;
    }

    obj->counter = obj->counter + 1;
    return obj->counter;
}
