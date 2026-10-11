#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x218
#define REGION_OFFSET_1 0x21c
#define REGION_OFFSET_2 0x7000
#define REGION_OFFSET_3 0x2c
#define REGION_OFFSET_4 0x30
#else
#define REGION_OFFSET_0 0x29c
#define REGION_OFFSET_1 0x2a0
#define REGION_OFFSET_2 0x6000
#define REGION_OFFSET_3 0xe3c
#define REGION_OFFSET_4 0xe40
#endif

#include "Util/Random.h"

struct Params021605d0 {
	struct Random* random;
	int fieldB;
	int fieldC;
};

// USA: func_ov000_021605d0
ARM void SetParamsAndRandomState021605d0(unsigned char* obj, struct Params021605d0* params) {
	*(struct Random**)(obj + REGION_OFFSET_0) = params->random;
	*(int*)(obj + REGION_OFFSET_1) = params->fieldB;
	*(int*)(obj + 0x4) = params->fieldC;

	struct Random* random = *(struct Random**)(obj + REGION_OFFSET_0);
	if (random == NULL) return;
	*(unsigned int*)(obj + REGION_OFFSET_2 + REGION_OFFSET_3) = GetRandomStateHi(random);
	*(unsigned int*)(obj + REGION_OFFSET_2 + REGION_OFFSET_4) = GetRandomStateLo(random);
}
