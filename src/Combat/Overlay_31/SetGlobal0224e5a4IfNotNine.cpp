#include <globaldefs.h>

struct GlobalPair02211b08 {
	int field0;
	int field4;
};

extern GlobalPair02211b08 data_ov031_0224e5a4;

// USA: func_ov031_02211b08
ARM void SetGlobal0224e5a4IfNotNine_ov031_02211b08(int a, int b) {
	if (data_ov031_0224e5a4.field0 != 9) {
		data_ov031_0224e5a4.field0 = a;
		data_ov031_0224e5a4.field4 = b;
	}
}
