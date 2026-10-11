#include <globaldefs.h>

#if defined(jpn)
#define data_020eff74 data_020eff73
#endif

extern char data_020eff74;
int StringLength(const char* s);
extern "C" int sprintf(char* dst, const char* fmt, ...);

// USA: func_02041e70
ARM int AppendPaletteTag(char* dst, int palette) {
    char* end = dst + StringLength(dst);
    return (end + sprintf(end, &data_020eff74, palette)) - dst;
}
