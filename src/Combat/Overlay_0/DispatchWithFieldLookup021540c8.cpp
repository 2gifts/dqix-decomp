#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"


extern "C" void func_ov000_021540fc(void*, int, int, int);

// USA: func_ov000_021540c8
ARM void DispatchWithFieldLookup021540c8(void* obj1, void* obj2, int val) {
    unsigned char* p = (unsigned char*)obj2;
    GameState::GetInstance();
    GetData02108e10();
    int* q = *(int**)(p + 0x10);
    unsigned short a = *(unsigned short*)((char*)q + 0x20);
    unsigned short b = *(unsigned short*)(p + 0x0);
    func_ov000_021540fc(obj1, a, b, val);
}
