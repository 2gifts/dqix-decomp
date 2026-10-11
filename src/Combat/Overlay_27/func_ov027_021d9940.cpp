#if defined(jpn)
#define R(j,u) (j)
#define _Z24IssueBattleCommandSlot25ii func_020d84e0
#define data_ov001_02164ca4 data_ov001_02166270
#define data_ov028_021d9aa0 data_ov028_021da400
#define func_ov014_02188330 func_ov014_02189234
#define func_ov014_0218854c func_ov014_0218942c
#define func_ov014_021885bc func_ov014_0218948c
#define func_ov015_02191f04 func_ov015_02192a48
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "System/Interrupts.h"

extern char* data_ov027_021e33ec;

extern "C" ARM void func_ov027_021d9d5c(int index);
extern "C" ARM int func_ov027_021da8d4(void* out, void* table, unsigned int key, void* rawElems);
extern "C" void* func_ov027_021dd638(void* in, void* out);
extern "C" ARM int func_ov027_021dd180(void* obj, unsigned int addr, void* buf, unsigned int size);
extern "C" ARM int func_ov027_021dd3e0(void* p);
extern "C" ARM void func_ov027_021dd3f8(void* a0, unsigned int a1, unsigned int a2, unsigned int a3);
extern "C" ARM void func_020c9be0(void);
extern "C" int func_ov027_021dab00(int a, int b, void* c);

struct Base_021d989c;
ARM void DoReadRequest_021d989c(Base_021d989c* p);

struct InputDD638_021d9940 {
    unsigned char type;
    unsigned short field2;
    unsigned short field4;
};

struct Out_021da8d4_021d9940 {
    int f0;
    int f4;
    int f8;
    unsigned char fc;
};

struct RegionEntry_021d9940 {
    unsigned int base;
    unsigned int limit;
    unsigned int target;
    unsigned int status;
};

#pragma optimize_for_size off
// USA: func_ov027_021d9940
extern "C" ARM int func_ov027_021d9940(void) {
    if (*(unsigned char*)(data_ov027_021e33ec + 0x1524) == 0) {
        return 0x15;
    }

    unsigned char attempts = 0;
    unsigned char cursor;
    for (;;) {
        *(unsigned char*)(data_ov027_021e33ec + 0x1525) =
            (unsigned char)((*(unsigned char*)(data_ov027_021e33ec + 0x1525) + 1) % 0x10);
        cursor = *(unsigned char*)(data_ov027_021e33ec + 0x1525);
        char* entry = data_ov027_021e33ec + cursor * 0x5d4;
        if (*(unsigned char*)(entry + 0x1d52) != 0 && *(unsigned short*)(entry + 0x1d4c) != 0) {
            break;
        }
        attempts = (attempts + 1) & 0xff;
        if (attempts >= 0x10) break;
    }
    if (attempts == 0x10) {
        return 0x15;
    }
    func_ov027_021d9d5c(cursor);

    char* base = data_ov027_021e33ec;
    unsigned char cursor2 = *(unsigned char*)(base + 0x1525);
    int off2 = cursor2 * 0x5d4;
    Out_021da8d4_021d9940 out;
    unsigned short key = *(unsigned short*)(base + off2 + 0x1d48);
    if (!func_ov027_021da8d4(&out, base + 0x1d2c + off2, key, base + 0x1788 + off2)) {
        return 0x15;
    }

    InputDD638_021d9940 in;
    in.type = 4;
    unsigned char cursor3 = *(unsigned char*)(data_ov027_021e33ec + 0x1525);
    in.field2 = cursor3;
    cursor3 = *(unsigned char*)(data_ov027_021e33ec + 0x1525);
    in.field4 = *(unsigned short*)(data_ov027_021e33ec + cursor3 * 0x5d4 + 0x1d48);
    void* res = func_ov027_021dd638(&in, data_ov027_021e33ec);

    unsigned char idx = out.fc;
    unsigned char cursor4 = *(unsigned char*)(data_ov027_021e33ec + 0x1525);
    int f8v = out.f8;
    int f4v = out.f4;
    char* entry2 = data_ov027_021e33ec + cursor4 * 0x5d4;
    void** d58 = *(void***)(entry2 + 0x1000 + 0xd58);
    int wordArrIdx = *(int*)(entry2 + idx * 4 + 0x1000 + 0xd2c);
    int addr = (f8v - wordArrIdx) + (int)d58[idx];
    void* obj = *(void**)(entry2 + 0x1000 + 0xd54);
    if (!func_ov027_021dd180(obj, addr, res, f4v)) {
        char* c7ce0 = data_ov027_021e33ec + 0x7ce0;
        if (func_ov027_021dd3e0(c7ce0)) {
            goto fail;
        }
        if (*(int*)obj != 0) {
            *(int*)obj -= 1;
            goto fail;
        }
        RegionEntry_021d9940* arr = (RegionEntry_021d9940*)((char*)obj + 0x30);
        RegionEntry_021d9940* best = 0;
        int i = 0;
        RegionEntry_021d9940* p = arr;
        do {
            if (arr[i].status == 2) {
                if (best == 0 || best->base > arr[i].base) {
                    best = p;
                }
            }
            p++;
            i++;
        } while (i < 4);
        if (best == 0) {
            func_020c9be0();
        }
        *(int*)obj = 2;
        best->status = 1;
        best->base = addr & ~0x1f;
        *(void**)(c7ce0 + 0x10) = best;
        *(void**)(c7ce0 + 0x14) = obj;
        func_ov027_021dd3f8(c7ce0, (unsigned int)&DoReadRequest_021d989c, 0, 4);
        goto fail;
    fail:
        return 0x15;
    }

    unsigned short counter = *(unsigned short*)(data_ov027_021e33ec +
        (*(unsigned char*)(data_ov027_021e33ec + 0x1525)) * 0x5d4 + 0x1d4c);
    return func_ov027_021dab00(out.f4 + 6, counter, data_ov027_021e33ec);
}
