#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
extern "C" void* func_ov011_021845f8(void* ctx, int v);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void func_ov017_021b1d44(void* p, int a, int b);
void ResetCombatantFields_0215a2f8(void* p);
int DispatchAdjustmentIfType4_02157018(void* a, int key);
int GetGlobalField0x1c020421a0(void);
extern "C" void func_0204500c(void*, const char*, int, int);

struct Obj_02184548 { char pad[0xb4]; int fieldB4; };
int GetFieldB4_02184548(struct Obj_02184548* obj);
struct Obj_02184540 { char pad[0xb0]; int fieldB0; };
int GetFieldB0_02184540(struct Obj_02184540* obj);

struct EntryA68 { short key; void* value; };
struct TableA68 { struct EntryA68* entries; short count; };
void* FindEntryByKey_02072a68(struct TableA68* table, int key);

struct Struct021707d8_0215bb54 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_0215bb54 data_ov004_021707d8;

// USA: func_ov004_0215bb54
#pragma optimize_for_size off
extern "C" ARM int func_ov004_0215bb54(void* obj) {
    void* five = *(void**)((unsigned char*)func_ov017_0218b5b0() + 0x3000 + 0xb48);
    unsigned char flag = data_ov004_021707d8.ptr[0x13];
    if (flag == 0) {
        void* obj2 = func_ov011_021845f8(obj, 1);
        if (obj2 == 0) {
            ResetCombatantFields_0215a2f8(data_ov004_021707d8.ptr);
            func_ov011_021848a0(obj, 0x39e);
            data_ov004_021707d8.ptr[0x13] = 0;
            return 0;
        }
        func_ov017_021b1d44(five, 4, 1);
        *(void**)((char*)five + 8) = (char*)obj2 + 4;
        int fieldB4 = GetFieldB4_02184548((struct Obj_02184548*)obj);
        int fieldB0 = GetFieldB0_02184540((struct Obj_02184540*)obj);
        *(int*)((char*)five + 0x34) = fieldB0;
        *(int*)((char*)five + 0x38) = fieldB4;
        data_ov004_021707d8.ptr[0x13]++;
        func_ov011_021848a0(obj, 0x3aa);
        void* node = (void*)DispatchAdjustmentIfType4_02157018(obj, 4);
        int g = GetGlobalField0x1c020421a0();
        void* found = FindEntryByKey_02072a68((struct TableA68*)node, 0x13);
        func_0204500c((void*)g, (const char*)found, 0, 0xe3);
        *(int*)((char*)g + 0x998) = 1;
    } else if (flag == 1) {
        func_ov011_021848a0(obj, 0x3ab);
        data_ov004_021707d8.ptr[0x13]++;
        return 0;
    }
    return 1;
}
