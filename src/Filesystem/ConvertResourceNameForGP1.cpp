#include <globaldefs.h>
#include <std_library_functions.h>

#if defined(jpn)
extern char data_020f2cb4[];
extern char data_020f2cb9[];
extern char data_020f2cbe[];

// JPN: func_020e12ec
extern "C" ARM int func_020e12ec(char* destination, const char* source) {
    if (destination == 0 || source == 0)
        return 0;
    strcpy(destination, source);
    char* extension = strstr(destination, data_020f2cb4);
    if (extension == 0)
        extension = strstr(destination, data_020f2cb9);
    if (extension != 0)
        strcpy(extension, data_020f2cbe);
    return 1;
}
#endif
