#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
enum { listOffset = 0x4ec, stateOffset = 0x928, countOffset = 0x1e4, bufferOffset = 0x28, clearSize = 0x800, statusOffset = 0x868 };
#else
enum { listOffset = 0x6fc, stateOffset = 0xb48, countOffset = 0x494, bufferOffset = 0x5c, clearSize = 0x960, statusOffset = 0x998 };
#endif

extern "C" void* func_ov017_0218b5b0(void);
extern "C" int _Z34DispatchAdjustmentIfType4_02157018Pvi(void* a, int key);
extern "C" int _Z26GetGlobalField0x1c020421a0v(void);
extern "C" ARM void _Z32ClearOrMaskNodesByState_0215781cPv(void* obj);
extern "C" void func_ov017_021b1e24(void* a, void* b);
extern "C" ARM int _Z34GetFieldromField_021b1fd4_021b1fd4Pv(void* obj);
extern "C" void func_ov004_021571f4(void* obj, int val);
struct Obj24_021b2024;
extern "C" unsigned char _Z26GetSubByteField34_021b2024P14Obj24_021b2024(Obj24_021b2024* obj);
struct Obj24_021b2038;
extern "C" unsigned char _Z26GetSubByteField35_021b2038P14Obj24_021b2038(Obj24_021b2038* obj);
extern "C" ARM void _Z26MaskNodesForRange_02157874Pv(void* obj);
struct Obj24_021b1fe8;
extern "C" unsigned char _Z26GetSubByteField44_021b1fe8P14Obj24_021b1fe8(Obj24_021b1fe8* obj);
struct EntryA68 { short key; void* value; };
struct TableA68 { struct EntryA68* entries; short count; };
void* FindEntryByKey(struct TableA68* table, int key);
struct Obj24_021b1ffc;
extern "C" int _Z27GetSubWordField394_021b1ffcP14Obj24_021b1ffc(Obj24_021b1ffc* obj);
struct Obj24_021b2010;
extern "C" unsigned char _Z27GetSubByteField398_021b2010P14Obj24_021b2010(Obj24_021b2010* obj);
extern "C" void func_ov004_02157374(void* obj, int key, int cat, char* dst, unsigned char flag5);
extern "C" void func_ov011_021848a0(void* obj, int val);
#if defined(jpn)
extern "C" void func_02045d88(void* field, void* buf, int p2);
#else
extern "C" void func_0204500c(void* field, void* buf, int p2, int p3);
#endif

struct Struct021707d8_0215bc9c { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_0215bc9c data_ov004_021707d8;

// USA: func_ov004_0215bc9c
extern "C" ARM int func_ov004_0215bc9c(void* obj) {
    int g;
    void* actorRaw = func_ov017_0218b5b0();
    void* list = *(void**)((char*)actorRaw + 0x3000 + listOffset);
    void* five = *(void**)((char*)actorRaw + 0x3000 + stateOffset);
    void* table = (void*)_Z34DispatchAdjustmentIfType4_02157018Pvi(obj, 4);
    g = _Z26GetGlobalField0x1c020421a0v();
    unsigned char flag = data_ov004_021707d8.ptr[0x13];

    if (flag == 2) {
        _Z32ClearOrMaskNodesByState_0215781cPv(obj);
        func_ov017_021b1e24(five, list);
        int t = _Z34GetFieldromField_021b1fd4_021b1fd4Pv(five) >> 12;
        func_ov004_021571f4(obj, t);
        _Z26GetSubByteField34_021b2024P14Obj24_021b2024((Obj24_021b2024*)five);
        _Z26GetSubByteField35_021b2038P14Obj24_021b2038((Obj24_021b2038*)five);
        if (*(int*)((char*)actorRaw + 0x4000 + countOffset) == 0) {
            data_ov004_021707d8.ptr[0x13]++;
        }
        goto returnOne;
    } else if (flag == 3) {
        _Z26MaskNodesForRange_02157874Pv(obj);
        char* buf = *(char**)((char*)g + bufferOffset);
        memset(buf, 0, clearSize);

        if (_Z26GetSubByteField44_021b1fe8P14Obj24_021b1fe8((Obj24_021b1fe8*)five) & 4) {
            data_ov004_021707d8.ptr[0x15] = 1;
            const char* name = (const char*)FindEntryByKey((struct TableA68*)table, 0x26);
            memcpy(buf, name, strlen(name));
            func_ov011_021848a0(obj, 0x3af);
        } else {
            data_ov004_021707d8.ptr[0x15] = 0;
            const char* name = (const char*)FindEntryByKey((struct TableA68*)table, 0x15);
            int len = strlen(name);
            memcpy(buf, name, len);

            int key394 = _Z27GetSubWordField394_021b1ffcP14Obj24_021b1ffc((Obj24_021b1ffc*)five);
            int cat398 = _Z27GetSubByteField398_021b2010P14Obj24_021b2010((Obj24_021b2010*)five);
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
        func_02045d88((void*)g, *(char**)((char*)g + bufferOffset), 0);
#else
        func_0204500c((void*)g, *(char**)((char*)g + bufferOffset), 0, 0xe3);
#endif
        *(int*)((char*)g + statusOffset) = 1;
        return 0;
    }

returnOne:
    return 1;
}
