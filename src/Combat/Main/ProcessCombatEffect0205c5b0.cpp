#include <globaldefs.h>

struct Obj0205c6bc;
int CallFunc0205bea0IfFlag0x94(Obj0205c6bc*);
struct Struct_0205bd04;
int GetScaledSumIfActive0205bd04(struct Struct_0205bd04*);
struct SelfBB04;
extern "C" void func_0205bb04(struct SelfBB04*, int);
struct Struct_0205bf3c;
void ResetState0205bf3c(struct Struct_0205bf3c*);
struct Struct_0205bc10;
void ClearBytes0x4cTo0x4e(struct Struct_0205bc10*);
struct Struct_0205bc2c;
int UpdateActiveState0205bc2c(Struct_0205bc2c*, int);
struct Struct_0205bb84;
int ComputeScaledSum0205bb84(struct Struct_0205bb84*);
extern "C" int func_0205bf58(void*, void*);
struct Struct_0205bcdc;
void SetIndexIfValid0205bcdc(struct Struct_0205bcdc*, int);

struct Struct_0205c5b0 {
    char pad0[0x34];
    int field34;
    char pad38[0x94 - 0x38];
    unsigned char field94;
    unsigned char field95;
};

// USA: func_0205c5b0  (semantic: ProcessCombatEffect0205c5b0)
extern "C" ARM int func_0205c5b0(void* selfPtr, void* p1) {
    void* param1 = p1;
    struct Struct_0205c5b0* self = (struct Struct_0205c5b0*)selfPtr;
    int result = 0;
    int field34 = self->field34;

    if (self->field94 != 0) {
        if (CallFunc0205bea0IfFlag0x94((Obj0205c6bc*)selfPtr) != 0) {
            int sum = GetScaledSumIfActive0205bd04((struct Struct_0205bd04*)((char*)self + 0x4));
            func_0205bb04((struct SelfBB04*)((char*)self + 0x54), sum);
            ResetState0205bf3c((struct Struct_0205bf3c*)((char*)self + 0x54));
            ClearBytes0x4cTo0x4e((struct Struct_0205bc10*)((char*)self + 0x4));
            result = 1;
            goto done;
        }
    }

    if (self->field94 != 0) {
        typedef int (*UpdateFn)(struct Struct_0205bc2c*, void*);
        if (((UpdateFn)UpdateActiveState0205bc2c)((struct Struct_0205bc2c*)((char*)self + 0x4), param1) != 0) {
            int sum = GetScaledSumIfActive0205bd04((struct Struct_0205bd04*)((char*)self + 0x4));
            if (field34 != sum) result = 2;
            func_0205bb04((struct SelfBB04*)((char*)self + 0x54), sum);
            ResetState0205bf3c((struct Struct_0205bf3c*)((char*)self + 0x54));
            goto done;
        }
    }

    if (self->field95 != 0) {
        int before = ComputeScaledSum0205bb84((struct Struct_0205bb84*)((char*)self + 0x54));
        if (func_0205bf58((char*)self + 0x54, param1) != 0) {
            int after = ComputeScaledSum0205bb84((struct Struct_0205bb84*)((char*)self + 0x54));
            if (before != after) {
                result = 1;
                int idx = ComputeScaledSum0205bb84((struct Struct_0205bb84*)((char*)self + 0x54));
                SetIndexIfValid0205bcdc((struct Struct_0205bcdc*)((char*)self + 0x4), idx);
                self->field34 = -1;
                ClearBytes0x4cTo0x4e((struct Struct_0205bc10*)((char*)self + 0x4));
            }
        }
    }

done:
    return result;
}
