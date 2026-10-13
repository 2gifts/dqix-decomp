#include <globaldefs.h>
#include "Resource/MessageSystem.h"
#include "Resource/MessageUpdate.h"

// USA: func_020656d0
ARM unsigned short GetIndexedHalfword(MessageSystem* window) {
    return window->firstLineBuffer[window->tokenIndex];
}
