#include <globaldefs.h>

struct Src021bd35c { unsigned short h0, h2, h4, h6, h8; };
struct S021bd35c { unsigned char pad[
#if defined(jpn)
0x14c
#else
0x150
#endif
]; unsigned short d0, d2, d4, d6, d8; };

// USA: func_ov017_021bd35c
ARM void CopyFiveHalfwords_021bd35c(S021bd35c* obj, Src021bd35c* src) {
	obj->d0 = src->h0;
	obj->d2 = src->h2;
	obj->d4 = src->h4;
	obj->d6 = src->h6;
	obj->d8 = src->h8;
}
