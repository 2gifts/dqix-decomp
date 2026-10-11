#include <globaldefs.h>

struct Entry0207d9bc { unsigned short id; unsigned short pad; unsigned int a; unsigned int b; };
extern "C" int _Z23CheckEntryBytes0207d978P13Entry0207d9bct(struct Entry0207d9bc* arr, unsigned short key);
struct Entry0207d9bc* FindEntryByHalfword(struct Entry0207d9bc* arr, unsigned short key);
extern "C" void* func_ov017_0218b5b0(void);
extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* _Z20GetField6b0_021b8470Pv(void* obj);
extern "C" void func_ov017_021b848c(unsigned char* obj, signed char* actionFlags, int idx, int val, unsigned short arg4, signed char arg5, int arg6, int arg7);

struct Source021c60a4 {
    unsigned short field0;
    unsigned short field2;
    unsigned char flags[4];
    unsigned char field8;
    unsigned char field9;
    short fieldA;
};
extern "C" void func_ov017_021c60a4(struct Source021c60a4* obj);

extern int data_02108ea8;


#if defined(jpn)
enum { ActionContextOffset = 0x3508 };
#else
enum { ActionContextOffset = 0x3718 };
#endif

// JPN: func_0207ea70
// USA: func_0207dcf0
extern "C" ARM void func_0207dcf0(unsigned short id) {
    struct Entry0207d9bc* table = (struct Entry0207d9bc*)&data_02108ea8;
    if (!_Z23CheckEntryBytes0207d978P13Entry0207d9bct(table, id)) return;

    struct Entry0207d9bc* entry = FindEntryByHalfword(table, id);
    if (!entry) return;

    unsigned char* obj = *(unsigned char**)((char*)func_ov017_0218b5b0() + ActionContextOffset);
    void* actionArr = func_ov017_021b8478(obj);
    _Z20GetField6b0_021b8470Pv(obj);

    if (((signed char*)entry)[8] != 0) {
        func_ov017_021b848c(
            obj,
            (signed char*)entry + 8,
            ((signed char*)entry)[4],
            0,
            entry->pad,
            ((signed char*)entry)[5],
            1,
            *(int*)((char*)actionArr + 0xc)
        );
    }

    struct Source021c60a4 msg;
    msg.field0 = id;
    msg.field8 = ((signed char*)entry)[4];
    msg.flags[0] = ((signed char*)entry)[8];
    msg.flags[1] = ((signed char*)entry)[9];
    msg.flags[2] = ((signed char*)entry)[0xa];
    msg.flags[3] = ((signed char*)entry)[0xb];
    msg.field2 = entry->pad;
    msg.field9 = ((unsigned char*)entry)[5];
    msg.fieldA = -1;
    if (((signed char*)entry)[4] == 0) {
        msg.fieldA = (short)*(int*)((char*)actionArr + 0xc);
    }
    func_ov017_021c60a4(&msg);
}
