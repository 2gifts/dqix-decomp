#include <globaldefs.h>
#include "GameState/GameState.h"

int GetGlobalField0x1c020421a0();
void* GetGlobalPtr021075f4(void);
void* FindEntryPointerByKey0203df78(void* base, int key);

struct Vec3_020406f8;
struct Node020406f8;
void SelectVec3FromSources020406f8(struct Vec3_020406f8* dst, struct Node020406f8* n);

struct Vec3Local_021688d4 { unsigned int v[3]; };

int FindEntryByKey0203dfdc(void* base, int key);
struct Owner02040a90;
int GetFieldFromActiveChild(struct Owner02040a90* obj);

extern "C" int fix32_Atan2(int, int);
extern "C" short _Z22fix32ReduceAngle0To2Pii(int);
struct Obj02033834;
void SetVecYByMode02033834(struct Obj02033834* obj, int arg);

extern "C" int func_0202ae18(void);
extern "C" int func_0202c508(void);

int CheckBitsInField0x63dc(void* obj, int mask);
void SetBitsInField0x63dc(void* obj, unsigned char mask);

struct Obj0205eaa0;
extern void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern struct Obj0205eaa0 data_02108760;

// USA: func_ov004_021688d4
extern "C" ARM int func_ov004_021688d4(void) {
    char* base17 = (char*)(int)GetGlobalField0x1c020421a0();
    void* ptr = GetGlobalPtr021075f4();
    void* node = FindEntryPointerByKey0203df78(ptr, 6);
    if (node) {
        GameObject* combatant = GameState::GetInstance()->GetUnknownGameObject();
        struct Vec3Local_021688d4 v1;
        struct Vec3Local_021688d4 v2;
        struct Vec3Local_021688d4 tmp;
        SelectVec3FromSources020406f8((struct Vec3_020406f8*)&tmp, (struct Node020406f8*)node);
        v1 = tmp;
        v2 = *(struct Vec3Local_021688d4*)((char*)combatant + 0x44);

        int idx = FindEntryByKey0203dfdc(ptr, 6);
#if defined(jpn)
        *(int*)(base17 + 0x1708) = idx;
#else
        *(int*)(base17 + 0x1838) = idx;
#endif

        int fieldVal = GetFieldFromActiveChild((struct Owner02040a90*)node);
#if defined(jpn)
        *(int*)(base17 + 0x170c) = fieldVal;
#else
        *(int*)(base17 + 0x183c) = fieldVal;
#endif

        int dx = (int)v1.v[0] - (int)v2.v[0];
        int dz = (int)v1.v[2] - (int)v2.v[2];
        int mid = fix32_Atan2(dx, dz);
        short angle = _Z22fix32ReduceAngle0To2Pii(mid);
        SetVecYByMode02033834((struct Obj02033834*)combatant, angle);
    }

    func_0202ae18();
    if (func_0202c508()) {
        GameState* bs = GameState::GetInstance();
        if (CheckBitsInField0x63dc(bs, 0x10)) {
            DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        }
        SetBitsInField0x63dc(bs, 0x10);
    }
    return 0;
}
