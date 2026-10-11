#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

extern "C" void __clear(char* buf, int len);
extern "C" int func_020426bc(int value, char* buf, int flag);
void CollectValidCombatants02010890(GameState* bs, int* outList, int* outCount);

#if defined(jpn)
typedef const char* NameValue0202c360;
#else
typedef int NameValue0202c360;
#endif
// USA: func_0202c360  (semantic: FormatAndCollectCombatants0202c360)
extern "C" ARM void func_0202c360(void* self, NameValue0202c360 value) {
    char buf[0x14];
    int list[4];
    int count;
    GameState* bs = GameState::GetInstance();
    unsigned char* lenField = (unsigned char*)self + 0x1028;
#if defined(jpn)
    strcpy((char*)self + 0x1014, value);
    *lenField = strlen(value);
#else
    __clear(buf, 0x14);
    func_020426bc(value, buf, 1);
    *lenField = strlen(buf);
    memcpy((char*)self + 0x1014, buf, *lenField + 1);
#endif
    CollectValidCombatants02010890(bs, list, &count);
    *((unsigned char*)self + 0x1027) = (unsigned char)count;
}
