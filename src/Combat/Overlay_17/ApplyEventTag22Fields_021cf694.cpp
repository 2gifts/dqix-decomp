#include <globaldefs.h>

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" int func_ov017_021b8468(void* obj);
void* GetField6b0_021b8470(void* obj);
void SetCombatWorkFlags0x55f4(void* work, int mask);

struct LocalEvt021cf694 {
	unsigned char pad0[4];
	int field4;
	int field8;
	unsigned short fieldc;
};

// JPN: func_ov017_021cfb44
// USA: func_ov017_021cf694
ARM void ApplyEventTag22Fields_021cf694(int unused0, LocalEvt021cf694* evt, int unused2, unsigned char* base) {
#if defined(jpn)
 enum {regionalOffset0=0x508, regionalOffset1=0x7000, regionalOffset2=0x2c, regionalOffset3=0x30};
#else
 enum {regionalOffset0=0x718, regionalOffset1=0x6000, regionalOffset2=0xe3c, regionalOffset3=0xe40};
#endif
	void* table = *(void**)(base + 0x3000 + regionalOffset0);
	void* a = func_ov017_021b8478(table);
	if (a == NULL) {
		return;
	}
	int b = func_ov017_021b8468(table);
	if (b == 0) {
		return;
	}
	if (GetField6b0_021b8470(table) == NULL) {
		return;
	}
	if (evt->fieldc != *(unsigned short*)((char*)a + 8)) {
		return;
	}
	int v1 = evt->field4;
	int v2 = evt->field8;
	unsigned char* buf = (unsigned char*)b + regionalOffset1;
	*(int*)(buf + regionalOffset2) = v1;
	*(int*)(buf + regionalOffset3) = v2;
	SetCombatWorkFlags0x55f4((void*)b, 0x20000);
}
