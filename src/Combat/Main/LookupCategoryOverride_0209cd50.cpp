#include <globaldefs.h>

#if defined(jpn)
enum { kFlagOffset = 0x27c8, kIdOffset = 0x27c6 };
#else
enum { kFlagOffset = 0x2788, kIdOffset = 0x2786 };
#endif

#include "GameState/GameState.h"

extern "C" void* func_02012fe4(void);
void* GetPtrField0x468(void* obj);
extern "C" int _s32_div_f(int a, int b);
struct SearchTable;
struct SearchEntry;
struct SearchEntry* FindEntryByHalfwordKey(struct SearchTable* table, int key);
int GetElementOverride0209caf0(int id);
extern "C" int func_0209cc3c(void* obj, int id);

extern int data_02109be0;

struct Entry0209cd50Layout {
    char pad[0xd];
    unsigned char idx7 : 7;
    unsigned char : 1;
};

// USA: func_0209cd50  (semantic: LookupCategoryOverride_0209cd50)
extern "C" ARM int func_0209cd50(int value) {
    int result = 0;
    GameState* battle = GameState::GetInstance();
    struct SearchTable* table = (struct SearchTable*)GetPtrField0x468(battle);
    void* base = func_02012fe4();
    if ((_s32_div_f(value, 100) * 100) == 0x170c) {
        if (*(unsigned char*)((char*)base + kFlagOffset) == 0) {
            if (*(unsigned short*)((char*)base + kIdOffset) == 0x76c) {
                value = 0x76c;
            }
        }
    }
    struct SearchEntry* entry = FindEntryByHalfwordKey(table, value);
    if (entry != 0) {
        unsigned int idx = ((struct Entry0209cd50Layout*)entry)->idx7;
        result = GetElementOverride0209caf0(idx);
    }
    int r = func_0209cc3c(&data_02109be0, value);
    if (r >= 0) {
        result = r;
    }
    return result;
}
