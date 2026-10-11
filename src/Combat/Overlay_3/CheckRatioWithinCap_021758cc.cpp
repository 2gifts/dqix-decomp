#include <globaldefs.h>
#if defined(jpn)
enum { kRegion103a = 0xfb6 };
enum { kRegion874 = 0x7f0 };
#else
enum { kRegion103a = 0x103a };
enum { kRegion874 = 0x874 };
#endif

#include "GameState/GameState.h"

struct Container020dedd0;
struct Element020de650;
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
unsigned int ComputeRatio_02175898(char* obj, void* s);
void* GetPtrField0x2a04(GameState* battleStruct);

// JPN: func_ov003_02174914
// USA: func_ov003_021758cc
ARM int CheckRatioWithinCap_021758cc(char* self, int count) {
	short key = *(short*)(self + kRegion103a);
	struct Element020de650* elem = FindElementByKey020dedd0((struct Container020dedd0*)(self + kRegion874), key);
	if (elem == NULL)
		return 0;
	unsigned int total = count * ComputeRatio_02175898(self, elem);
	int result = 0;
	if (total <= *(unsigned int*)((char*)GetPtrField0x2a04(GameState::GetInstance()) + 0xf6c))
		result = 1;
	return result;
}
