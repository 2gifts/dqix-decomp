#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>
struct Struct0200fb08;
extern "C" int _Z24NormalizeField5_0200fb08P14Struct0200fb08(Struct0200fb08*);
int StringLength(const char*);
extern "C" int func_02001aec(const void*, const void*, unsigned int);
extern char data_020e7e35[7];
extern char data_020e7e30[5];
// USA: func_020680cc
extern "C" ARM int func_020680cc(const char* text) {
    if (_Z24NormalizeField5_0200fb08P14Struct0200fb08((Struct0200fb08*)GameState::GetInstance()) == 3) {
        char endings[7];
        char suffix[5];
        INLINE_MEMCPY(endings, data_020e7e35, 7);
        INLINE_MEMCPY(suffix, data_020e7e30, 5);
        int length = StringLength(text);
        if (length) {
            char last = text[length - 1];
            for (char* ending = endings; *ending; ending++) {
                if (!*ending) break;
                if (*ending == last) return 1;
            }
            if (length >= 4 && func_02001aec(text + (length - 4), suffix, 4) == 0) return 1;
        }
    }
    return 0;
}
