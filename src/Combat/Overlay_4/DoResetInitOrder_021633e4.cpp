#include <globaldefs.h>

struct Struct020A2CF0;
extern "C" void func_0202df68(void* obj);
void ResetState020a2cf0(struct Struct020A2CF0* obj);
void InitCombatController020a2010(void* obj);

// USA: func_ov004_021633e4
ARM void* DoResetInitOrder_021633e4(void* obj) {
	func_0202df68(obj);
	ResetState020a2cf0((struct Struct020A2CF0*)obj);
	InitCombatController020a2010(obj);
	return obj;
}
