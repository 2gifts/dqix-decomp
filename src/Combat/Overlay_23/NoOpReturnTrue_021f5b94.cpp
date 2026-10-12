#include <globaldefs.h>

#if defined(jpn)
#include "Resource/Script.h"
struct OpcodeState021fff08 { char pad[8]; char* object; };
extern struct OpcodeState021fff08 data_ov023_021fff08;
#endif

#if defined(jpn)
#define NoOpReturnTrue_021f5b94 func_ov023_021f514c
#endif

// USA: func_ov023_021f5b94
#if defined(jpn)
extern "C"
#endif
ARM int NoOpReturnTrue_021f5b94(
#if defined(jpn)
    Script::Parameter* params, int numParams
#else
    void
#endif
) {
#if defined(jpn)
    if (params->ToInt() != 0) {
        *(int*)(data_ov023_021fff08.object + 0x50) |= 1;
    } else {
        *(int*)(data_ov023_021fff08.object + 0x50) &= 1;
    }
#endif
	return 1;
}
