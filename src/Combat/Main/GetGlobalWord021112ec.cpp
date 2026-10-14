#include <globaldefs.h>

#if defined(jpn)
extern char data_02110f8c;
#else
extern char data_021112ec;
#endif

// USA: _Z30GetGlobalWord021112ec_020c75a4v
ARM int GetGlobalWord021112ec_020c75a4(void) {
#if defined(jpn)
    return *(int*)(&data_02110f8c);
#else
    return *(int*)(&data_021112ec);
#endif
}
