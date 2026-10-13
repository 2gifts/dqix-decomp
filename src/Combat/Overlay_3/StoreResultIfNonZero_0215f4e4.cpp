#include <globaldefs.h>

struct KeyboardKey;
struct Keyboard {
    KeyboardKey* key_;
};

extern "C" KeyboardKey* func_ov003_0215f4a4(Keyboard* keyboard, int id);

// USA: func_ov003_0215f4e4
ARM void StoreResultIfNonZero_0215f4e4(Keyboard* keyboard, int id) {
    KeyboardKey* key = func_ov003_0215f4a4(keyboard, id);
    if (key != 0) {
        keyboard->key_ = key;
    }
}
