#include <globaldefs.h>
#include "Resource/GameResources.h"
#include "Combat/EntryGetterTypes.h"

struct Obj0201b600 { char pad0[6]; short angle; };
struct EntryList_203dce4;

struct HeadNode02046b24;
struct GameResources;
struct Struct_203cec4;
struct Struct_0203fc5c;
struct Node020406f8;
struct Vec3_020406f8 { int x; int y; int z; };
struct Node02040774;
struct Node020409b0;
struct Obj02040b2c;
struct EntryPositionState { char unknown0[0x10]; int x; int y; int z; short value; };
struct Vec3 { int x; int y; int z; };

extern "C" void* func_02012fe4(void);
extern "C" GameResources* func_ov017_0218b5b0(void);
extern "C" int rand(void);
extern "C" long long func_020c3260(int phase);
extern "C" long long func_020c32f8(int phase);
extern "C" float func_0200c700(long long);
extern "C" void Vector3fix_Add(struct Vec3* a, struct Vec3* b, struct Vec3* out);
struct EntryList_203dce4* GetGlobalPtr021075f4();
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24**);
struct Obj0201b600* FindElemByKeys(Obj0201b600*, int, unsigned short);
struct Entry_203dce4* GetEntryUnlessFlag0x8000(struct EntryList_203dce4*, int);
void ClearFlag0x1(unsigned int*);
int IsField0Null(void**);
int IsMainBrightnessTransitionActive(struct GameResources*);
int GetMainBrightnessTransitionState(struct GameResources*);
void SetActiveChildFields02040774(struct Node02040774*, int, int, int);
void PropagateValueToActiveSlot02040b2c(struct Obj02040b2c*, int);
void SelectVec3FromSources020406f8(struct Vec3_020406f8*, struct Node020406f8*);
void SetOrClearFlag0x8(struct Struct_203cec4*, int);
void SetField40IfPositive(struct Struct_0203fc5c*, float);
void DispatchOnActiveChild020409b0(struct Node020409b0*, int);

// USA: func_020aeb34
extern "C" ARM void func_020aeb34(void) {
    struct EntryList_203dce4* list;
    struct Entry_203dce4* arr[4];
    GameResources* base;
    struct Obj0201b600* elem;
    int i;
    struct HeadNode02046b24** head;

    elem = (struct Obj0201b600*)func_02012fe4();
    list = GetGlobalPtr021075f4();
    base = func_ov017_0218b5b0();
    head = (HeadNode02046b24**)base->unknown_ptr_array_36fc[0];
    GetHeadNodeIdOrMinusOne(head);
    elem = FindElemByKeys(elem, 0, 0x2a);

    if (elem == NULL) return;

    for (i = 0; i < 4; i++) {
        arr[i] = GetEntryUnlessFlag0x8000(list, base->orbitEntryIds[i]);
        if (arr[i] == NULL) return;
        ClearFlag0x1((unsigned int*)arr[i]);
    }

    if (IsField0Null((void**)head) == 0 && IsMainBrightnessTransitionActive((struct GameResources*)base) == 0 &&
        (GetMainBrightnessTransitionState((struct GameResources*)base) == 2 ||
         GetMainBrightnessTransitionState((struct GameResources*)base) == 3)) {
        if (elem->angle != 0) return;
        for (int j = 0; j < 4; j++) {
            EntryPositionState* s = (EntryPositionState*)GetField0xc02040538((S02040538*)arr[j]);
            SetActiveChildFields02040774((struct Node02040774*)arr[j], s->x, s->y, s->z);
            PropagateValueToActiveSlot02040b2c((struct Obj02040b2c*)arr[j], s->value);
        }
        return;
    }

    base->orbitAngularStep += 2 * (rand() % 13 - 6);
    if (base->orbitAngularStep > 0x2d) base->orbitAngularStep = 0x2d;
    if (base->orbitAngularStep < 0x20) base->orbitAngularStep = 0x20;

    int vecAx = 88006;
    if (elem->angle <= base->orbitAngularStep) {
        elem->angle += 0x6487;
    }
    elem->angle -= base->orbitAngularStep;

    int angle = elem->angle;

    for (int k = 0; k < 4; k++) {
        int phase;
        struct Vec3 vecB;
        struct Vec3 vecA;
        struct Vec3 out;
        struct Vec3_020406f8 sel;

        angle += 0x1921;
        if (angle >= 0x6487) angle -= 0x6487;
        phase = angle - 0xcc;
        if (phase <= 0) phase += 0x6487;

        vecB.x = (int)(4096.0f * (func_0200c700(func_020c3260(phase)) / 4294967296.0f)) * 2;
        vecB.y = 0;
        vecB.z = (int)(4096.0f * (func_0200c700(func_020c32f8(phase)) / 4294967296.0f)) * 2;

        vecA.x = vecAx;
        struct Entry_203dce4* entry = arr[k];
        SelectVec3FromSources020406f8(&sel, (struct Node020406f8*)entry);
        vecA.z = -0x970;
        vecA.y = sel.y;

        Vector3fix_Add(&vecA, &vecB, &out);

        if ((*(void**)((char*)entry + 0x14)) != NULL) SetOrClearFlag0x8((struct Struct_203cec4*)(*(void**)((char*)entry + 0x14)), 1);
        if ((*(void**)((char*)entry + 0x14)) != NULL) SetField40IfPositive((struct Struct_0203fc5c*)(*(void**)((char*)entry + 0x14)), 0.8f);
        DispatchOnActiveChild020409b0((struct Node020409b0*)entry, (int)&out);
        SetActiveChildFields02040774((struct Node02040774*)entry, out.x, out.y, out.z);
    }
}
