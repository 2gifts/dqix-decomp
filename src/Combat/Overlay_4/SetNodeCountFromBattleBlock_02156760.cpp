#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"

extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void* func_ov023_021f6880(void** list, int key);
extern "C" unsigned int func_ov023_021f6f10(void* self);
extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_02156760  (semantic: SetNodeCountFromBattleBlock_02156760)
// KEEP-NAME
extern "C" ARM int func_ov004_02156760(void* context) {
    BattleRecordSnapshot snapshot;
    char* node = (char*)func_ov023_021f6880((void**)func_ov011_021849c8(context), 3);
    if (node == 0) {
        return 0;
    }
    if (func_ov023_021f6f10(node) != 7) {
        return 0;
    }
    LoadBattleBlock020ac4c0(&snapshot);
#if defined(jpn)
    const unsigned int entriesPerPage = 16;
#else
    const unsigned int entriesPerPage = 12;
#endif
    unsigned int pageCount;
    unsigned int entryCount = snapshot.unknown10_0;
    pageCount = entryCount / entriesPerPage;
    unsigned int remainder = entryCount % entriesPerPage;
    if (remainder != 0) {
        pageCount = pageCount + 1;
    }
    if (pageCount != 0) {
        *(unsigned short*)(node + 0x5c) = 0;
        *(unsigned short*)(node + 0x5e) = pageCount;
        return 0;
    }
    func_ov011_021848a0(context, 0x66);
    return 0;
}
