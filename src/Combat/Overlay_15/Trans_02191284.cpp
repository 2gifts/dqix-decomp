#include <globaldefs.h>

struct DebugMenu
{
    char unk_0[0x5c];
    short first_;
    short last_;
    short cursor_;
    char unk_62[0x80 - 0x62];
};

// USA: func_ov015_02191284  (semantic: Trans_02191284)
extern "C" ARM int func_ov015_02191284(DebugMenu* menu) {
    return menu->cursor_ - menu->first_;
}
