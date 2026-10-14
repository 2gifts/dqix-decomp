#include <globaldefs.h>
#include "Resource/Script.h"

struct ResetStruct;

struct StreamState;
struct StreamHeader;

struct Struct02030774;

extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, int*);

struct Data_ov017_021d83cc {
	void* field0;
	int field4;
};
extern struct Data_ov017_021d83cc data_ov017_021d83cc;
extern int data_ov017_021d7900;

// USA: func_ov017_021acc8c
ARM void InitAndRunScript_021acc8c(void* param0, struct StreamHeader* param1, int param2, int param3) {
	char local[0x430];
	data_ov017_021d83cc.field0 = param0;
	data_ov017_021d83cc.field4 = param3;
	((Script*)((struct ResetStruct*)local))->Initialize();
	_ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_ov017_021d7900);
	((Script*)((struct StreamState*)local))->Load(param1, param2);
	((Script*)((struct Struct02030774*)local))->Execute();
}
