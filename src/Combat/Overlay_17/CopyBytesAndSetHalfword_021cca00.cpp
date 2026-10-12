#include <globaldefs.h>

#if defined(jpn)
enum { kWorkHalfwordOffset = 0x8bc };
#else
enum { kWorkHalfwordOffset = 0x954 };
#endif


#if defined(jpn)
#define CopyBytesAndSetHalfword_021cca00 func_ov017_021ccea8
#endif
#include "GameState/GameState.h"

int GetFieldAt0x150(unsigned char* obj);

struct Src021cca00 {
	unsigned short field0;
	unsigned short field2;
	unsigned char bytes[12];
};

// USA: func_ov017_021cca00
#if defined(jpn)
extern "C"
#endif
ARM void CopyBytesAndSetHalfword_021cca00(int unused0, unsigned char* src, GameState* battleStruct, int unused3) {
	Src021cca00* s = (Src021cca00*)(src + 4);
	GameObject* c = GetCombatantWithFlag0x100(battleStruct, *(unsigned short*)(src + 4));
	if (!c) return;
	unsigned char* work = (unsigned char*)GetFieldAt0x150((unsigned char*)c);
	if (!work) return;
	*(unsigned short*)(work + kWorkHalfwordOffset) = s->field2;
	int i = 0;
	while (i < 12) {
		unsigned char v = s->bytes[i];
		i++;
		unsigned char* dst = work + i;
		dst[0x186] = v;
	}
}
