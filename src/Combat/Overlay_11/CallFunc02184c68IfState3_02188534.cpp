#include <globaldefs.h>
#include "Resource/MessageSystem.h"

void* GetGlobalField0x1c020421a0();
extern "C" unsigned int func_ov011_02184c68(unsigned int, unsigned int);

// USA: func_ov011_02188534
extern "C" ARM int func_ov011_02188534(unsigned int obj) {
    MessageSystem* messages = (MessageSystem*)GetGlobalField0x1c020421a0();
    int enabled = 0;
    if (messages->mode == 3) enabled = 1;
    func_ov011_02184c68(obj, enabled);
    return 1;
}
