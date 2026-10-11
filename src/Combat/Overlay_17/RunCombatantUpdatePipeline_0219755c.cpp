#include <globaldefs.h>

extern "C" void* func_02012fe4(void);
extern "C" void func_ov017_02197e2c(void* obj);
struct S02046b1c;
int GetField0x0List02046b1c(struct S02046b1c* p);
extern "C" void func_ov017_021975e4(void* obj);
extern "C" void func_ov017_02197a64(void* obj);
extern "C" void func_ov017_0219814c(void* obj);
extern "C" void func_ov017_021982ac(void* obj);
extern "C" void func_ov017_021983e0(void* obj);
extern "C" void func_ov017_021984f4(void* obj);
extern "C" void func_ov017_02198618(void* obj);
extern "C" void func_ov017_021986fc(void* obj);
extern "C" void func_ov017_02198aa0(void* obj);
extern "C" void func_ov017_02198e30(void* obj);

#if defined(jpn)
struct S0219755c { unsigned char pad[0x444]; int field0x424; };
#else
struct S0219755c { unsigned char pad[0x424]; int field0x424; };
#endif

// JPN: func_ov017_0219810c
// USA: func_ov017_0219755c
ARM void RunCombatantUpdatePipeline_0219755c(unsigned char* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x4ec};
#else
 enum {regionalOffset0=0x6fc};
#endif
	if (((S0219755c*)func_02012fe4())->field0x424 != 0) return;

	func_ov017_02197e2c(obj);
	if (GetField0x0List02046b1c((struct S02046b1c*)*(void**)(obj + 0x3000 + regionalOffset0)) != 0) return;

	func_ov017_021975e4(obj);
	func_ov017_02197a64(obj);
	func_ov017_0219814c(obj);
	func_ov017_021982ac(obj);
	func_ov017_021983e0(obj);
	func_ov017_021984f4(obj);
	func_ov017_02198618(obj);
	func_ov017_021986fc(obj);
	func_ov017_02198aa0(obj);
	func_ov017_02198e30(obj);
}
