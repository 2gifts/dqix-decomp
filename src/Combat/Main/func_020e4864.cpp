#include <globaldefs.h>
#include <std_library_functions.h>
int StringLength(const char*);
extern "C" int func_02001aec(const void*, const void*, unsigned int);
extern char data_020f2d2c[][11];
extern signed char data_020eeab0[][8];
extern char data_020ee9d8[][3];
// USA: func_020e4864
extern "C" ARM void func_020e4864(const char* source, char* destination, int column, int, int, int row) {
    int replacementLength;
    for (;;) {
        if (!*source) break;
        if (*source == '[') {
            int replaced = 0;
            int index = 0;
            for (;;) {
                if (!data_020f2d2c[index][0]) break;
                int length = StringLength(data_020f2d2c[index]);
                if (func_02001aec(source + 1, data_020f2d2c[index], length) == 0) {
                    if (column >= 0 && row >= 0) {
                        int replacementIndex = data_020eeab0[index][column + row * 2] * 3;
                        const char* replacementBase = (const char*)data_020ee9d8;
                        replacementLength = StringLength(replacementBase + replacementIndex);
                        memcpy(destination, replacementBase + replacementIndex, replacementLength);
                        destination += replacementLength;
                    }
                    source += length + 1;
                    replaced = true;
                    break;
                }
                index++;
            }
            if (replaced) continue;
        }
        *destination++ = *source++;
    }
    *destination = *source;
}
