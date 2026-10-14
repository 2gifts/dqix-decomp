#include <globaldefs.h>
#include "std_library_functions.h"

struct Obj02069d08 { void* dest; };

extern "C" void func_020696bc(int value, int *out, int flag);
int* GetGlobal02109418_02094d6c(void);
struct FindTableIndexOrFFData;
unsigned char FindTableIndexOrFF_020965c0(struct FindTableIndexOrFFData *s, unsigned int val);
int GetGlobalField0x1c020421a0(void);

// USA: func_02069d08
ARM int StoreHalfword0xff1002069d08(struct Obj02069d08 *obj, int value) {
    int local;
    func_020696bc(value, &local, 1);
    unsigned char idx = FindTableIndexOrFF_020965c0((struct FindTableIndexOrFFData*)GetGlobal02109418_02094d6c(), local & 0xff);
    *(unsigned short*)(GetGlobalField0x1c020421a0() + 0x1948) = idx;
    void* d = obj->dest;
    unsigned short v = 0xff10;
    memcpy(d, &v, 2);
    return 2;
}
