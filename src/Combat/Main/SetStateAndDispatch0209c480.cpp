#include <globaldefs.h>

int IsMissingFromTable0209c0f4(int value, int type);
void CallField0xa00203aa44(void* obj);
int GetFromField00203aa64(void* obj);
void* CallFunc020bc594OnField0(void* obj, int);
void Forward0203aa80(void* obj, int arg2);
int TryAllocateOrAppend0203aaf8(void* obj, void* arg1, int* out);
struct Obj0203aba8;
int TryDispatchOrFallback0203aba8(struct Obj0203aba8* obj, void* key, void* target);
extern "C" void func_0209c2e0(void* obj, int a, int b);

struct Actor0209c480 {
    char pad0[0xb0];
    int state;                // 0xb0
    int field_b4;             // 0xb4
    short field_b8;           // 0xb8
    short field_ba;           // 0xba
    void* fieldBC;            // 0xbc
    void* fieldC0;            // 0xc0
    void* fieldC4;            // 0xc4
    unsigned char field_c8;   // 0xc8
    unsigned char field_c9;   // 0xc9
    short field_ca;           // 0xca
    unsigned char field_cc;   // 0xcc
    unsigned char field_cd;   // 0xcd
    short field_ce;           // 0xce
};

// USA: func_0209c480  (semantic: SetStateAndDispatch0209c480)
extern "C" ARM void func_0209c480(struct Actor0209c480* obj, int arg1) {
    if (obj->state == 2) return;
    obj->state = 2;
    if (IsMissingFromTable0209c0f4(obj->field_b8, arg1)) {
        CallField0xa00203aa44(obj);
        obj->field_b4 = GetFromField00203aa64(obj);
    } else {
        CallFunc020bc594OnField0(&obj->fieldBC, 1);
        if (obj->field_b4 > 0) {
            Forward0203aa80(obj, obj->field_b4);
        }
    }
    if (arg1 >= 0) {
        TryAllocateOrAppend0203aaf8(obj, (void*)arg1, 0);
        TryDispatchOrFallback0203aba8((struct Obj0203aba8*)obj, (void*)arg1, &obj->fieldC0);
        func_0209c2e0(obj, obj->field_cd, 0);
        obj->field_ba = (short)arg1;
    }
    obj->field_ce = -1;
}
