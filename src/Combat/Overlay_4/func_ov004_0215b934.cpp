#include <globaldefs.h>
#if defined(jpn)
enum{regionalAreaOffset=0xc};
#else
enum{regionalAreaOffset=0x26c};
#endif
#include "Memory/SafeAllocator.h"
#include "GameState/GameState.h"

struct BattleMenuState0215b934 {
    char pad00[0x14];
    unsigned char active;
    char pad15[0x77];
    unsigned char table[1];
};

struct StateHolder0215b934 { char pad[8]; BattleMenuState0215b934* ptr; };
extern StateHolder0215b934 data_ov004_021707d8;

struct Reward0215b934 {
    short itemId;
    unsigned short count;
    unsigned short unitValue;
    char pad6[0xe];
    unsigned short kind : 13;
};

struct RewardArea0215b934 {
    char pad[0xf8];
    Reward0215b934 reward;
};

struct Wallet0215b934 {
    char pad[0xf6c];
    unsigned int gold;
};

struct Element0215b934 {
    char pad[0x18];
    short nameId;
};

struct Message0215b934 {
    char pad[0x18];
    int name;
};

struct Container020dedd0;
struct TableA68;
struct Obj02046574;
struct StoreStruct;

extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" struct Container020dedd0* func_ov004_02156fd4(void* obj, int key);
Element0215b934* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
Message0215b934* GetGlobalField0x1c020421a0(void);
extern "C" void func_02046380(void* global);
struct TableA68* DispatchAdjustmentIfType4_02157018(void* a, int key);
#if defined(jpn)
extern "C" void func_020e207c(void*, char*, int);
#else
int CallFunc020e52a0(void* p, int key);
#endif
extern "C" int rand(void);
char* FindEntryByKey(struct TableA68* table, int key);
void SetIndexedName02046574(struct Obj02046574* obj, int index, char* str);
void StoreInArray0x8b0(struct StoreStruct* base, int index, int value);
void* ZeroInitReturn020de824(void* obj);
void InitStruct0207cbe8(char* obj);
extern "C" void func_0207d300(void* buf, int a, int b, int c);
extern "C" void func_ov004_0215b7c8(void* obj);

// USA: func_ov004_0215b934
extern "C" ARM int func_ov004_0215b934(void* obj) {
    if (data_ov004_021707d8.ptr->active) {
        GameState* gs = GameState::GetInstance();
        Wallet0215b934* wallet = (Wallet0215b934*)GetPtrField0x2a04(gs);
        Element0215b934* elem;
        Message0215b934* msg;
        unsigned int amount;
        RewardArea0215b934* area = (RewardArea0215b934*)((char*)gs + regionalAreaOffset + 0x5c00);
        if (area->reward.itemId <= 0 || area->reward.count == 0) {
            func_ov011_021848a0(obj, 0x387);
            return 0;
        }
        struct Container020dedd0* items = func_ov004_02156fd4(obj, 5);
        elem = FindElementByKey020dedd0(items, area->reward.itemId);
        if (!elem) return 0;
        msg = GetGlobalField0x1c020421a0();
        func_02046380(msg);
        unsigned int kind = area->reward.kind;
        if (kind & 1) {
            amount = area->reward.count * area->reward.unitValue;
            if (9999999 - wallet->gold < amount) {
                amount = 9999999 - wallet->gold;
            }
            wallet->gold += amount;
            struct TableA68* names = DispatchAdjustmentIfType4_02157018(obj, 9);
#if defined(jpn)
            char name[80];
            func_020e207c(data_ov004_021707d8.ptr->table, name, elem->nameId);
            SetIndexedName02046574((Obj02046574*)msg, 1, name);
#else
            msg->name = CallFunc020e52a0(data_ov004_021707d8.ptr->table, elem->nameId);
#endif
            SetIndexedName02046574((struct Obj02046574*)msg, 2, FindEntryByKey(names, (short)(rand() % 0x3a)));
            SetIndexedName02046574((struct Obj02046574*)msg, 3, FindEntryByKey(names, (short)(rand() % 6 + 1000)));
            StoreInArray0x8b0((struct StoreStruct*)msg, 0, amount);
            func_ov011_021848a0(obj, 0x3a8);
        } else if (kind & 2) {
            char buf[0x38];
            ((SafeAllocator*)buf)->ResetAllocatorPointer();
            ZeroInitReturn020de824(buf + 0x14);
            InitStruct0207cbe8(buf);
            InitStruct0207cbe8(buf);
            func_0207d300(buf, area->reward.itemId, (signed char)area->reward.count, 0);
#if defined(jpn)
            char name[80];
            func_020e207c(data_ov004_021707d8.ptr->table, name, elem->nameId);
            SetIndexedName02046574((Obj02046574*)msg, 1, name);
#else
            msg->name = CallFunc020e52a0(data_ov004_021707d8.ptr->table, elem->nameId);
#endif
            func_ov011_021848a0(obj, 0x3a9);
        } else {
            func_ov011_021848a0(obj, 0x387);
        }
        func_ov004_0215b7c8(&area->reward);
    } else {
        func_ov011_021848a0(obj, 0x387);
    }
    return 0;
}
