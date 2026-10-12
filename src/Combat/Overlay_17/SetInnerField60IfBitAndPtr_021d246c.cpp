#include <globaldefs.h>

#if defined(jpn)
enum { kResourceInnerOffset = 0x38ec };
#else
enum { kResourceInnerOffset = 0x3b0c };
#endif


#if defined(jpn)
#define SetInnerField60IfBitAndPtr_021d246c func_ov017_021d28f0
#endif
#include "GameState/GameState.h"


// USA: func_ov017_021d246c
#if defined(jpn)
extern "C"
#endif
ARM void SetInnerField60IfBitAndPtr_021d246c(int unusedA, char* b, GameState* battleStruct, char* d) {
	GameObject* c = battleStruct->GetUnknownGameObject();
	int* p = *(int**)((char*)c + 0x130);
	if (*p & 1) {
		int* inner = *(int**)(d + kResourceInnerOffset);
		if (inner != 0) {
			*(int*)((char*)inner + 0x60) = *(int*)(b + 4);
		}
	}
}
