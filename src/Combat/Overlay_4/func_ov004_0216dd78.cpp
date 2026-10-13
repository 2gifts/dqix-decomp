#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/MessageSystem.h"


extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" unsigned short func_ov023_021f6f10(void*);
extern "C" void* func_ov023_021fa598(void*);
int GetGlobalField0x1c020421a0(void);
void* GetDataPtr02114e04_020d6c00(void);
extern "C" int func_020ab7a8(void* obj, int flag);
struct FlagWord020466f4;
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);
extern "C" void func_ov011_021848a0(void* obj, int val);
void* FindEntryByKey(struct TableA68* table, int key);
void SetByte0x7f70(void* obj, unsigned char value);

struct FieldGroup02171034 {
    #if defined(jpn)
    unsigned char pad0[0xc];
#else
    unsigned char pad0[0x10];
#endif
    unsigned char* ptr10;
};
extern struct FieldGroup02171034 data_ov004_02171034;

// USA: func_ov004_0216dd78
extern "C" ARM int func_ov004_0216dd78(void* a) {
    void* battler = func_ov011_021849c8(a);
    void* node1 = func_ov023_021f6880(battler, 0x192);
    if (!node1) return 0;
    if (func_ov023_021f6f10(node1) != 4) return 0;

    void* table = func_ov023_021fa598(node1);
    void* battle = GameState::GetInstance();
    MessageSystem* message = (MessageSystem*)GetGlobalField0x1c020421a0();
    struct FlagWord020466f4* flagWord = (struct FlagWord020466f4*)GetDataPtr02114e04_020d6c00();
    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();

    int ret = 1;
    void* node2 = func_ov023_021f6880(battler, 2);
    if (!node2) return 0;
    if (func_ov023_021f6f10(node2) != 0xb) return 0;

    *(unsigned char*)((char*)node2 + 0xc) &= ~8;
    message->b19ca = 0;
    message->b19af = 0;

    int state = func_020ab7a8((void*)data_ov004_02171034.ptr10, ret);
    if (state == 5) {
        ClearFlags020466f4(flagWord, 0x80);
        data_ov004_02171034.ptr10[1] = 0;
        func_ov011_021848a0(a, 0x194);
        ret = 0;
    } else if (state == 1) {
        ClearFlags020466f4(flagWord, 0x80);
        data_ov004_02171034.ptr10[1] = 0;
        void* entry = FindEntryByKey((struct TableA68*)table, 0x5dc);
#if defined(jpn)
        func_0204500c(message, (const char*)entry, 0);
#else
        func_0204500c(message, (const char*)entry, 0, (void*)0xe3);
#endif
        SetByte0x7f70(battle, 0);
        ret = 0;
    } else if (state == 2) {
        ClearFlags020466f4(flagWord, 0x80);
        data_ov004_02171034.ptr10[1] = 0;
        void* entry = FindEntryByKey((struct TableA68*)table, 0x5dd);
#if defined(jpn)
        func_0204500c(message, (const char*)entry, 0);
#else
        func_0204500c(message, (const char*)entry, 0, (void*)0xe3);
#endif
        SetByte0x7f70(battle, 0);
        ret = 0;
    } else if (state == 3) {
        ClearFlags020466f4(flagWord, 0x80);
        data_ov004_02171034.ptr10[1] = 0;
        func_ov011_021848a0(a, 0x195);
        ret = 0;
    }

    if (ret == 0) {
        *(unsigned char*)((char*)node2 + 0xc) |= 8;
    }
    BackgroundLoader::RemoveLockGlobal();
    return ret;
}
