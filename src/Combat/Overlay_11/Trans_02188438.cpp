#include <globaldefs.h>

extern int data_02109bf4;
extern "C" unsigned int _Z25IsAnimationActive0209ca2cPv(unsigned int);
extern "C" unsigned int func_ov011_02184c68(unsigned int, unsigned int);

// USA: func_ov011_02188438  (semantic: Trans_02188438)
extern "C" ARM unsigned int func_ov011_02188438(unsigned int arg0) {
    func_ov011_02184c68(arg0, _Z25IsAnimationActive0209ca2cPv((unsigned int)&data_02109bf4));
    return 1;
}
