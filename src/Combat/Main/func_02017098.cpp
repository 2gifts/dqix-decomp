#include <globaldefs.h>
#include "Graphics/Vector.h"
#include "World/LootableContainer.h"

struct ActorListManager;
struct SelfObj792c;
struct Struct020478bc;
struct Obj0205eaa0;

struct Entry02017098* GetActorEntryByIndex(struct ActorListManager* manager, int index);
extern "C" void func_0204792c(struct SelfObj792c* self, char* name);
void RecomputeField0x7c(struct Struct020478bc* o, int newIndex);
extern "C" void _ZN8Vector3iaSERKS_(void* dst, const void* src);
extern "C" float _fflt(int value);
extern "C" float _fmul(float a, float b);
extern "C" int _ffix(float value);
extern "C" void _Z28StoreThreeWordsAt0x0020130a8Piiii(int* obj, int a, int b, int c);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);

extern char data_020ef222[];
extern int data_02108760;

struct Segment02017098 {
    char pad0[0x1c];
    Vector3i pos;
    char pad1[0x88 - 0x1c - 0xc];
};

struct Entry02017098 {
    unsigned short id;
    short field2;
    short field4;
    char pad6[0x24 - 0x06];
    Vector3i position;
    char pad30[0x118 - 0x30];
    struct Segment02017098 segments[4];
    Vector3i offsets[4];
};

// USA: func_02017098
extern "C" ARM void func_02017098(struct ActorListManager* manager, int index) {
    struct Entry02017098* e = GetActorEntryByIndex(manager, index);
    if (e == NULL) return;

    e->field2 = 3;
    func_0204792c((struct SelfObj792c*)((char*)e + 8), data_020ef222);
    RecomputeField0x7c((struct Struct020478bc*)((char*)e + 0x90), 1);

    fix32_t angle = 0x4b5c;
    for (int i = 0; i < 4; i++) {
        struct Segment02017098* seg = &e->segments[i];
        _ZN8Vector3iaSERKS_(&seg->pos, &e->position);
        int sine = FIX32_MULTIPLY(fix32sin(angle), 0x80);
        int height = _ffix(_fmul(4.0f, _fflt(0x80)));
        int cosine = FIX32_MULTIPLY(fix32cos(angle), 0x80);
        _Z28StoreThreeWordsAt0x0020130a8Piiii((int*)&e->offsets[i], sine, height, cosine);
        angle = fix32ReduceAngle0To2Pi(angle + 0x1922);
    }

    LootableContainerManager::Container* container =
        LootableContainerManager::GetMainInstance()->GetContainerByID(e->id, NULL);
    if (container != NULL) {
        if (container->containerType == 1) {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0*)&data_02108760, 0x10, 0);
        } else if (container->containerType == 2) {
            _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii((struct Obj0205eaa0*)&data_02108760, 0x11, 0);
        }
    }

    e->field4 = 0;
}
