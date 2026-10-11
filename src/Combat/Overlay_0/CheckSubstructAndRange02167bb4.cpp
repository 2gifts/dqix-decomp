#include <globaldefs.h>
#include "GameState/GameState.h"

int GetSubstructByte0x56(unsigned char* obj);

#if defined(jpn)
enum { nodeTableOffset = 0x218 };
#else
enum { nodeTableOffset = 0x29c };
#endif

// USA: func_ov000_02167bb4
ARM int CheckSubstructAndRange02167bb4(unsigned char* obj, int id) {
    GameState* battle = GameState::GetInstance();
    void* base = *(void**)(obj + nodeTableOffset);
    int key = *(int*)((char*)base + id * 4 + 0x8000 + 0xde0) & 0xff;
    GameObject* c = battle->GetCombatantByIndex(key);
    int val = c ? (GetSubstructByte0x56((unsigned char*)c) != 0) : 0;
    if (val) return 0;
    if (id < 0 || id >= 8) return 0;
    return 0x7fffffff;
}
