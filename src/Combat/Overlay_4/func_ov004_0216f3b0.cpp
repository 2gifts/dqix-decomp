#include <globaldefs.h>


extern "C" void* func_ov017_0218b5b0(void);
extern "C" void* func_ov011_021845f8(void* ctx, int v);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void* func_ov017_021b1d44(void* p, int a, int b);
extern "C" void func_ov017_021b1e24(void* a, void* b);
struct Obj24_021b2060;
unsigned char GetSubByteField439_021b2060(Obj24_021b2060* obj);
struct Obj24_021b204c;
unsigned char GetSubByteField438_021b204c(Obj24_021b204c* obj);
extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void* func_ov023_021f6880(void* obj, int id);

struct Struct02171048_0216f3b0 { char pad[4]; unsigned char* ptr; };
extern Struct02171048_0216f3b0 data_ov004_02171048;

// USA: func_ov004_0216f3b0
// JPN: func_ov004_0216fa44
extern "C" ARM int func_ov004_0216f3b0(void* a) {
    void* actorRaw = func_ov017_0218b5b0();
#if defined(jpn)
    void* list = *(void**)((char*)actorRaw + 0x3000 + 0x4ec);
    void* five = *(void**)((char*)actorRaw + 0x3000 + 0x928);
#else
    void* list = *(void**)((char*)actorRaw + 0x3000 + 0x6fc);
    void* five = *(void**)((char*)actorRaw + 0x3000 + 0xb48);
#endif
    unsigned char flag = data_ov004_02171048.ptr[0x2e];

    if (flag == 0) {
        void* obj2 = func_ov011_021845f8(a, 1);
        if (!obj2) {
            func_ov011_021848a0(a, 0xd2);
            data_ov004_02171048.ptr[0x2e] = 0;
            return 0;
        }
        func_ov017_021b1d44(five, 2, 1);
        *(void**)((char*)five + 8) = (char*)obj2 + 4;
        data_ov004_02171048.ptr[0x2e]++;
        goto returnOne;
    }

    if (flag == 1) {
        func_ov017_021b1e24(five, list);
        if (GetSubByteField439_021b2060((Obj24_021b2060*)five)) {
            if (GetSubByteField438_021b204c((Obj24_021b204c*)five)) {
#if defined(jpn)
                if (*(int*)((char*)actorRaw + 0x4000 + 0x1e4) == 0) {
#else
                if (*(int*)((char*)actorRaw + 0x4000 + 0x494) == 0) {
#endif
                    func_ov011_021848a0(a, 0xcc);
                    return 0;
                }
            }
            if (!GetSubByteField438_021b204c((Obj24_021b204c*)five)) {
                func_ov011_021848a0(a, 0xc9);
                data_ov004_02171048.ptr[0x2e]++;

                void* battler = func_ov011_021849c8(a);
                void* node = func_ov023_021f6880(battler, 0x97);
                if (node) {
                    *(unsigned char*)((char*)node + 0xc) &= ~8;
                }
                return 0;
            }
        }
    }
returnOne:
    return 1;
}
