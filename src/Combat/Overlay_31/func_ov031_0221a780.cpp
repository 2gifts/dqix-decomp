#include <globaldefs.h>
#include "System/ProcessorContext.h"

extern "C" void func_ov031_022183b4(void* p);
extern "C" int func_ov031_0221a89c(void);
void SetGlobal0224e5a4IfNotNine_ov031_02211b08(int a, int b);
bool IsContextInactive(ProcessorContext* context);

extern char* data_ov031_0224e69c;

// USA: func_ov031_0221a780
extern "C" ARM int func_ov031_0221a780(void) {
	if (data_ov031_0224e69c == NULL) return 0;
	if (*(int*)(data_ov031_0224e69c + 0x1bac) == 0) return 1;
	if (IsContextInactive((ProcessorContext*)(data_ov031_0224e69c + 0x1b40)) == 1) {
		int mode = *(int*)(data_ov031_0224e69c + 0x1028);
		switch (mode) {
		case 8:
			if (func_ov031_0221a89c() == 0) {
				func_ov031_022183b4(data_ov031_0224e69c + 8);
				return 4;
			}
			func_ov031_022183b4(data_ov031_0224e69c + 8);
			return 3;
		case 7:
			func_ov031_022183b4(data_ov031_0224e69c + 8);
			return 5;
		default:
			func_ov031_022183b4(data_ov031_0224e69c + 8);
			SetGlobal0224e5a4IfNotNine_ov031_02211b08(0x11, 0xffffa1db);
			return 4;
		}
	} else {
		return 2;
	}
}
