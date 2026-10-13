#include <globaldefs.h>

#if defined(jpn)
#define func_ov002_0215b6c0 func_ov002_0215c914
#endif

struct BattleCommandMenu {
#if defined(jpn)
    char unknown0[0x1a94];
#else
    char unknown0[0x1bcc];
#endif
    int refreshLinkedPage;
};

extern "C" void func_ov002_0215b9a4(BattleCommandMenu* menu, unsigned char key, int flag);

// USA: func_ov002_0215b6c0  (semantic: SetDefaultElementFlags_0215b6c0)
extern "C" ARM void func_ov002_0215b6c0(BattleCommandMenu* obj) {
    obj->refreshLinkedPage = 1;
#if defined(jpn)
    func_ov002_0215b9a4(obj, 0x11, 1);
    func_ov002_0215b9a4(obj, 0x14, 0);
    func_ov002_0215b9a4(obj, 8, 1);
    func_ov002_0215b9a4(obj, 9, 0);
#else
    func_ov002_0215b9a4(obj, 0x10, 1);
    func_ov002_0215b9a4(obj, 0x13, 0);
    func_ov002_0215b9a4(obj, 7, 1);
    func_ov002_0215b9a4(obj, 8, 0);
#endif
    func_ov002_0215b9a4(obj, 4, 1);
}
