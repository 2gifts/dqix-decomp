#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov000_02161318(void* base, int id);
extern "C" void func_ov000_02174b14(void* obj);

// USA: func_ov000_02181364
ARM void Process02181364(void* obj) {
    unsigned char* base = (unsigned char*)GetPtrField0x2a04_02010828(GameState::GetInstance());
    unsigned char count = base[0xf7c];
    unsigned char j;
    for (j = 0; j < count; j++) {
        unsigned char id = (base + j)[0xf78];
        void* result = func_ov000_02161318(obj, id);
        if (result != NULL) {
            signed char off = *(signed char*)((char*)result + 0x18);
            char* ptr2 = (char*)result + off;
            *(unsigned char*)(ptr2 + 0x10) = 100;
            unsigned char flags = *(unsigned char*)((char*)result + 0x24);
            flags &= ~4;
            *(unsigned char*)((char*)result + 0x24) = flags;
        }
    }
    func_ov000_02174b14(obj);
}
