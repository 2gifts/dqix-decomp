#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/MessageSystem.h"


extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
extern "C" unsigned int func_ov023_021f6f10(void* self);
#define NODE_KIND_CALL func_ov023_021f6f10
#else
int ScaleStatsIfType12_021f6f10(void* self);
#define NODE_KIND_CALL ScaleStatsIfType12_021f6f10
#endif
extern "C" void* func_ov023_021fa598(void* p);
int GetGlobalField0x1c020421a0();
extern "C" int func_020abb64(void);
struct TableA68;
void* FindEntryByKey(struct TableA68* table, int key);
void SetByte0x4(char* obj, unsigned char value);
void SetByte0x7f70(void* obj, unsigned char value);
extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_0216d5b0
extern "C" ARM int func_ov004_0216d5b0(void* obj) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(obj), 0x192);
    if (!node) return 0;
    if (NODE_KIND_CALL(node) != 4) return 0;

    struct TableA68* table = (struct TableA68*)func_ov023_021fa598(node);
    GameState* battle = GameState::GetInstance();
    MessageSystem* message = (MessageSystem*)GetGlobalField0x1c020421a0();

    if (func_020abb64() == 0) {
        void* entry = FindEntryByKey(table, 0x5dd);
#if defined(jpn)
        func_0204500c(message, (const char*)entry, 0);
#else
        func_0204500c(message, (const char*)entry, 0, (void*)0xe3);
#endif
        message->b19ca = 0;
        message->b19af = 0;
        SetByte0x7f70(battle, 0);
        return 0;
    }

    void* entry = FindEntryByKey(table, 0x4b1);
#if defined(jpn)
    func_0204500c(message, (const char*)entry, 0);
#else
    func_0204500c(message, (const char*)entry, 0, (void*)0xe3);
#endif
    SetByte0x4((char*)battle, 7);
    SetByte0x7f70(battle, 0);
    func_ov011_021848a0(obj, 0x97);
    return 0;
}
