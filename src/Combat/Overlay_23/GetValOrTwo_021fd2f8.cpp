#include <globaldefs.h>

#if defined(jpn)
#define GetValOrTwo_021fd2f8 func_ov023_021fc5f0
#endif

int GetGlobal02109400(void);
int AlwaysTrue02094b4c(void);

struct S_021fd2f8 { char pad[0x1c]; int val; };

// USA: func_ov023_021fd2f8
#if defined(jpn)
extern "C"
#endif
ARM int GetValOrTwo_021fd2f8(struct S_021fd2f8* s) {
	GetGlobal02109400();
	if (AlwaysTrue02094b4c() != 0) return 2;
	return s->val;
}
