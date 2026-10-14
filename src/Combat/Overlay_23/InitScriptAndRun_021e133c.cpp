#include <globaldefs.h>
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct02030774;

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, int*);

struct Data_021ffa34 {
	short field0;
	int field4;
	int field8;
	void* fieldC;
};
extern struct Data_021ffa34 data_ov023_021ffa34;
extern int data_ov023_021fdc78;

// USA: func_ov023_021e133c
ARM void InitScriptAndRun_021e133c(void* a, void* b, int c, int d, int e, short f) {
	char local[0x430];
	if (c != 0 && d != 0) {
		data_ov023_021ffa34.fieldC = a;
		data_ov023_021ffa34.field8 = (int)b;
		data_ov023_021ffa34.field4 = e;
		data_ov023_021ffa34.field0 = f;
		((Script*)((struct ResetStruct*)local))->Initialize();
		_ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_ov023_021fdc78);
		((Script*)((struct StreamState*)local))->Load((struct StreamHeader*)c, d);
		((Script*)((struct Struct02030774*)local))->Execute();
	}
}
