#include <globaldefs.h>
#include "Combat/ActorAction.h"

// USA: func_020399a8
ARM SubBlock02038508* GetFieldPtrAt0x26c_020399a8(void* obj) {
#if defined(jpn)
    return (SubBlock02038508*)((char*)obj + 0x260);
#else
    return (SubBlock02038508*)((char*)obj + 0x26c);
#endif
}
