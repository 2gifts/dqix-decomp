#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/GameResources.h"

#if defined(jpn)
enum { bufferOffset = 0x28, clearSize = 0x800, statusOffset = 0x868 };
#else
enum { bufferOffset = 0x5c, clearSize = 0x960, statusOffset = 0x998 };
#endif

int DispatchAdjustmentIfType4_02157018(void* a, int key);
int GetGlobalField0x1c020421a0(void);
ARM void ClearOrMaskNodesByState_0215781c(void* obj);
extern "C" void func_ov017_021b1e24(void* a, void* b);
ARM int GetFieldromField_021b1fd4_021b1fd4(void* obj);
extern "C" void func_ov004_021571f4(void* obj, int val);
struct Obj24_021b2024;
unsigned char GetSubByteField34_021b2024(Obj24_021b2024* obj);
struct Obj24_021b2038;
unsigned char GetSubByteField35_021b2038(Obj24_021b2038* obj);
ARM void MaskNodesForRange_02157874(void* obj);
struct Obj24_021b1fe8;
unsigned char GetSubByteField44_021b1fe8(Obj24_021b1fe8* obj);
struct EntryA68 { short key; void* value; };
struct TableA68 { struct EntryA68* entries; short count; };
void* FindEntryByKey(struct TableA68* table, int key);
struct Obj24_021b1ffc;
int GetSubWordField394_021b1ffc(Obj24_021b1ffc* obj);
struct Obj24_021b2010;
unsigned char GetSubByteField398_021b2010(Obj24_021b2010* obj);
extern "C" void func_ov004_02157374(void* obj, int key, int cat, char* dst, unsigned char flag5);
extern "C" void func_ov011_021848a0(void* obj, int val);
#if defined(jpn)
extern "C" void func_0204500c(void* field, void* buf, int p2);
#else
extern "C" void func_0204500c(void* field, void* buf, int p2, int p3);
#endif

struct Struct021707d8_0215bc9c { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_0215bc9c data_ov004_021707d8;

// USA: func_ov004_0215bc9c
extern "C" ARM int func_ov004_0215bc9c(void* obj) {
    int g;
    GameResources* resources = func_ov017_0218b5b0();
    void* list = resources->unknown_ptr_array_36fc[0];
    void* five = resources->unknown_ptr_array_3afc[19];
    void* table = (void*)DispatchAdjustmentIfType4_02157018(obj, 4);
    g = GetGlobalField0x1c020421a0();
    unsigned char flag = data_ov004_021707d8.ptr[0x13];

    if (flag == 2) {
        ClearOrMaskNodesByState_0215781c(obj);
        func_ov017_021b1e24(five, list);
        int t = GetFieldromField_021b1fd4_021b1fd4(five) >> 12;
        func_ov004_021571f4(obj, t);
        GetSubByteField34_021b2024((Obj24_021b2024*)five);
        GetSubByteField35_021b2038((Obj24_021b2038*)five);
        if (*(int*)(resources->unknown_4490 + 4) == 0) {
            data_ov004_021707d8.ptr[0x13]++;
        }
        goto returnOne;
    } else if (flag == 3) {
        MaskNodesForRange_02157874(obj);
        char* buf = *(char**)((char*)g + bufferOffset);
        memset(buf, 0, clearSize);

        if (GetSubByteField44_021b1fe8((Obj24_021b1fe8*)five) & 4) {
            data_ov004_021707d8.ptr[0x15] = 1;
            const char* name = (const char*)FindEntryByKey((struct TableA68*)table, 0x26);
            memcpy(buf, name, strlen(name));
            func_ov011_021848a0(obj, 0x3af);
        } else {
            data_ov004_021707d8.ptr[0x15] = 0;
            const char* name = (const char*)FindEntryByKey((struct TableA68*)table, 0x15);
            int len = strlen(name);
            memcpy(buf, name, len);

            int key394 = GetSubWordField394_021b1ffc((Obj24_021b1ffc*)five);
            int cat398 = GetSubByteField398_021b2010((Obj24_021b2010*)five);
            func_ov004_02157374(obj, key394, cat398, buf + len, 0);
            strlen(buf + len);
            func_ov011_021848a0(obj, 0x242d);
        }

        *((unsigned char*)five + 1) = 1;
        data_ov004_021707d8.ptr[0x13] = 0;
        unsigned char* ptr = data_ov004_021707d8.ptr;
        memset(ptr + 0x1c, 0, 0xc);
        *(int*)(ptr + 0x28) = 0;
#if defined(jpn)
        func_0204500c((void*)g, *(char**)((char*)g + bufferOffset), 0);
#else
        func_0204500c((void*)g, *(char**)((char*)g + bufferOffset), 0, 0xe3);
#endif
        *(int*)((char*)g + statusOffset) = 1;
        return 0;
    }

returnOne:
    return 1;
}
