#include <globaldefs.h>
#include "std_library_functions.h"

void ClearFields0to5_0218d7fc(unsigned char* obj);
void* GetData02153637(void);
void StoreInFirstEmptySlot(unsigned char* base, unsigned char val);

#if defined(jpn)
static const int kName=0x4136, kFlag=0x413b;
#else
static const int kName=0x4356, kFlag=0x435b;
#endif

// USA: func_ov017_0218d7b0
ARM void SetName56AndFlag_0218d7b0(unsigned char* obj, char* name) {
	if (!name) return;
	ClearFields0to5_0218d7fc(obj + kName);
	memcpy(obj + kName, name, 6);
	obj[kFlag] = 1;
	StoreInFirstEmptySlot((unsigned char*)GetData02153637(), 1);
}
