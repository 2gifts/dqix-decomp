#include <globaldefs.h>

struct Struct0219313c { char pad[0x5c]; short f5c; short f5e; short f60; };

// USA: func_ov015_0219313c
ARM void SetShortFields0219313c(Struct0219313c* s, int a, int b) {
	s->f5c = a;
	s->f60 = s->f5c;
	s->f5e = b;
}
