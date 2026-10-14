#include <globaldefs.h>

struct MainStruct020e455c;
void ProcessBattleTick020e455c(struct MainStruct020e455c* obj);
void PopStack0AndTrigger_020a1e54(int flag);

// USA: func_ov004_0216fa48  (semantic: ProcessTickAndPopStack_0216fa48)
extern "C" ARM void func_ov004_0216fa48(struct MainStruct020e455c* obj) {
	ProcessBattleTick020e455c(obj);
	if (*((unsigned char*)obj + 0xf) != 0) {
		PopStack0AndTrigger_020a1e54(1);
		*((unsigned char*)obj + 0xf) = 0;
	}
}
