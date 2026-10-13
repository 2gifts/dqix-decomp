#include <globaldefs.h>
#include "Resource/MessageUpdate.h"

extern "C" void func_02065990(unsigned char*, int);

// USA: func_020444d4
ARM void Forward020444d4(MessageSystem* window, int ticks) {
    func_02065990(reinterpret_cast<unsigned char*>(window), ticks);
}
