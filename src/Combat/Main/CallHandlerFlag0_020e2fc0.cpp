#include <globaldefs.h>
#include "Graphics/NSBXX/RenderCommands.h"

struct Entry020e2d54;
struct Output020e2d54;
extern "C" void func_020e2d54(int, Entry020e2d54*, Output020e2d54*);
extern Output020e2d54 data_020f2c14;
// USA: func_020e2fc0
ARM void CallHandlerFlag0_020e2fc0(RenderCommandHandler* handler) {
    func_020e2d54(0, reinterpret_cast<Entry020e2d54*>(handler), &data_020f2c14);
}
