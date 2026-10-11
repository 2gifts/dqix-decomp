// JPN: func_ov017_021afcac
#if defined(jpn)
enum { RegionOffset280 = 0x210, RegionOffset284 = 0x214, RegionOffset288 = 0x218 };
#else
enum { RegionOffset280 = 0x280, RegionOffset284 = 0x284, RegionOffset288 = 0x288 };
#endif

#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct ByteHeader0204693c;
void ResetByteHeader(struct ByteHeader0204693c* p);
void InitBigStruct0205c790(char* obj);
unsigned char GetByteField0x252(void* obj);

// USA: func_ov017_021af59c  (semantic: InitStruct_021af59c)
extern "C" ARM void func_ov017_021af59c(char* obj) {
    ResetByteHeader((struct ByteHeader0204693c*)obj);
    obj[0] = 0x26;
    obj[0x9] = 0;
    obj[0xa] = 0;
    obj[0xb] = 0;
    memset(obj + 0x1b, 0, 4);
    obj[0x1f] = 0;
    obj[0x20] = 0;
    *(int*)(obj + 0x28) = 0;
    *(int*)(obj + 0x30) = 0;
    obj[0x25] = 0;
    obj[0x26] = 0;
    *(int*)(obj + 0x34) = 0;
    obj[0x27] = 0;
    obj[0x2c] = 0;
    memset(obj + 0x43, 0, 5);
    *(int*)(obj + 0x3c) = 0;
    *(int*)(obj + 0x38) = 0;
    *(short*)(obj + 0x40) = 0;
    obj[0x42] = 0;
    InitBigStruct0205c790(obj + 0x48);
    *(int*)(obj + RegionOffset280) = (*(unsigned int*)0x4000000 & 0x1f00) >> 8;
    GameObject* combatant = GameState::GetInstance()->GetUnknownGameObject();
    if (combatant != 0) {
        obj[RegionOffset284] = GetByteField0x252(combatant) != 0 ? 1 : 0;
    } else {
        obj[RegionOffset284] = 1;
    }
    *(int*)(obj + RegionOffset288) = 0;
    obj[0x8] = 0;
}
