#include <globaldefs.h>

int FetchHalfword0xF6_020cee18(int*);
int DispatchType0x12_020cedfc(int);

// USA: func_ov031_0223dfd0
ARM int TryFetchOrDispatch12_0223dfd0(void) {
	int local;
	int result = FetchHalfword0xF6_020cee18(&local);
	if (result != 0) {
		return result;
	}
	if (local == 0xf) {
		return local;
	}
	return DispatchType0x12_020cedfc(0xf);
}
