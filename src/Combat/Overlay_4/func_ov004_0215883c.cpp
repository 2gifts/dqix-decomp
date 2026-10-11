#include <globaldefs.h>

#if defined(jpn)
enum { listOffset = 0x4ec, stateOffset = 0x928, countOffset = 0x1e4 };
#else
enum { listOffset = 0x6fc, stateOffset = 0xb48, countOffset = 0x494 };
#endif

extern "C" void* func_ov017_0218b5b0(void);
extern "C" void* func_ov011_021845f8(void* ctx, int v);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void* func_ov017_021b1d44(void* p, int a, int b);
extern "C" void func_ov017_021b1e24(void* a, void* b);
struct Obj24_021b2060;
unsigned char GetSubByteField439_021b2060(Obj24_021b2060* obj);
struct Obj24_021b204c;
unsigned char GetSubByteField438_021b204c(Obj24_021b204c* obj);
struct Actor0209c678;
void DispatchContextByState0209c678(struct Actor0209c678* actor, int arg);
extern struct Actor0209c678 data_02109bf4;
struct Obj_02184548 { char pad[0xb4]; int fieldB4; };
int GetFieldB4_02184548(struct Obj_02184548* obj);
struct Obj_02184540 { char pad[0xb0]; int fieldB0; };
int GetFieldB0_02184540(struct Obj_02184540* obj);

struct Struct021707d8_0215883c { char pad[8]; unsigned char* ptr; int counterC; };
extern Struct021707d8_0215883c data_ov004_021707d8;

// USA: func_ov004_0215883c
#pragma optimize_for_size off
extern "C" ARM int func_ov004_0215883c(void* a) {
    void* actorRaw = func_ov017_0218b5b0();
    void* list = *(void**)((char*)actorRaw + 0x3000 + listOffset);
    unsigned char flag = data_ov004_021707d8.ptr[0x13];
    void* five = *(void**)((char*)actorRaw + 0x3000 + stateOffset);

    if (flag != 0) goto notZero;
    {
        void* obj2 = func_ov011_021845f8(a, 1);
        if (!obj2) {
            func_ov011_021848a0(a, 0x395);
            data_ov004_021707d8.ptr[0x13] = 0;
            return 0;
        }
        if (!func_ov017_021b1d44(five, 1, 1)) {
            func_ov011_021848a0(a, 0x3ac);
            data_ov004_021707d8.ptr[0x13] = 0;
            return 0;
        }
        int state = 0x12;
        data_ov004_021707d8.counterC = state;
        DispatchContextByState0209c678(&data_02109bf4, state);
        *(void**)((char*)five + 8) = (char*)obj2 + 4;
        int fieldB4 = GetFieldB4_02184548((struct Obj_02184548*)a);
        int fieldB0 = GetFieldB0_02184540((struct Obj_02184540*)a);
        *(int*)((char*)five + 0x34) = fieldB0;
        *(int*)((char*)five + 0x38) = fieldB4;
        data_ov004_021707d8.ptr[0x13]++;
        goto retTrue;
    }
notZero:
    if (flag == 1) {
        int counter = data_ov004_021707d8.counterC - 1;
        data_ov004_021707d8.counterC = counter;
        if (counter > 0) return 1;

        func_ov017_021b1e24(five, list);
        if (!GetSubByteField439_021b2060((Obj24_021b2060*)five)) goto retTrue;
        if (GetSubByteField438_021b204c((Obj24_021b204c*)five)) {
            if (*(int*)((char*)actorRaw + 0x4000 + countOffset) == 0) {
                func_ov011_021848a0(a, 0x233d);
                return 0;
            }
        }
        if (GetSubByteField438_021b204c((Obj24_021b204c*)five)) goto retTrue;
        data_ov004_021707d8.ptr[0x13]++;
        func_ov011_021848a0(a, 0x385);
        return 0;
    }
retTrue:
    return 1;
}
