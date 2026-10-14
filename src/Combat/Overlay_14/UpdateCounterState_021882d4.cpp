#include <globaldefs.h>
#include "GameState/GameState.h"

int GetWord0x0(int* obj);
struct GameResources;
void SetBrightness(GameResources*, int, int);
int IsBrightnessTransitionActive(GameResources*);

struct S021882d4 {
	unsigned char pad0[0x17a];
	unsigned char byte17a;
	unsigned char byte17b;
};

// USA: func_ov014_021882d4
ARM void UpdateCounterState_021882d4(struct S021882d4* r4) {
	int val = GetWord0x0((int*)GameState::GetInstance());
	if (r4->byte17b == 0) {
		SetBrightness((GameResources*)val, -16, 8);
		r4->byte17b++;
		return;
	}
	if (r4->byte17b != 1) return;
	if (!IsBrightnessTransitionActive((GameResources*)val)) {
		r4->byte17a = 6;
		r4->byte17b = 0;
	}
}
