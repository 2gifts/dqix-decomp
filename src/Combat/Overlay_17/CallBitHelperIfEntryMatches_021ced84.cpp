#include <globaldefs.h>

void* GetData02153634_020e3580(void);

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);

void SetBitField0_020e36c4(unsigned char* obj, int bit);
void SetByte2IfGlobalFlagSet_020e3778(unsigned char* p);
void ClearBitField1_020e3748(unsigned char* obj, int bit);

struct LocalEvt021ced84 {
	unsigned char pad0[4];
	unsigned char mode;
	unsigned char compareVal;
};

// USA: func_ov017_021ced84
ARM void CallBitHelperIfEntryMatches_021ced84(int bit, LocalEvt021ced84* evt, int unused2, int unused3, struct SearchStruct0202c1a4* extra) {
	unsigned char* obj = (unsigned char*)GetData02153634_020e3580();
	signed char val = GetSearchStructCurrentArrEntry(extra);
	if (evt->compareVal != val) {
		return;
	}
	if (evt->mode == 0) {
		SetBitField0_020e36c4(obj, bit & 0xff);
		return;
	}
	if (evt->mode == 1) {
		SetByte2IfGlobalFlagSet_020e3778(obj);
		return;
	}
	if (evt->mode != 2) {
		return;
	}
	ClearBitField1_020e3748(obj, bit & 0xff);
}
