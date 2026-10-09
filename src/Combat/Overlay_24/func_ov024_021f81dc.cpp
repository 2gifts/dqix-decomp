#include <globaldefs.h>

struct S02053dc0 { char pad[0x19c]; void* field19c; };
void* GetField0x19cOrNull(struct S02053dc0* p);

struct TargetLock_021f81dc { char data[0x30]; };

struct Ctx_021f81dc {
	char pad0[4];
	short field4;
	char pad6[6];
	int count;
	char pad10[0x114];
	float scale;
	char pad128[0x280];
	struct TargetLock_021f81dc locks[9];
};

extern "C" void func_ov024_021f9660(void* obj);
extern "C" int func_ov024_021f8628(void* obj, void* p1, void* p2, void* p3);
extern "C" int func_ov024_021f691c(void* obj, unsigned short* outB, void* outA, int key);

// USA: func_ov024_021f81dc
extern "C" ARM int func_ov024_021f81dc(struct Ctx_021f81dc* obj, void* p1, struct S02053dc0* p2, unsigned short* outB) {
	void* result = GetField0x19cOrNull(p2);
	if (!result) return (int)result;
	obj->scale = 0.4f;
	func_ov024_021f9660(obj);
	int r = func_ov024_021f691c(&obj->locks[6], outB, result, obj->field4);
	if (r) return r;
	r = func_ov024_021f691c(&obj->locks[5], outB, result, obj->field4);
	if (r) return r;
	if (obj->count >= 4) {
		r = func_ov024_021f691c(&obj->locks[8], outB, result, obj->field4);
		if (r) return r;
	}
	if (obj->count >= 4) {
		r = func_ov024_021f691c(&obj->locks[0], outB, result, obj->field4);
		if (r) return r;
		r = func_ov024_021f691c(&obj->locks[2], outB, result, obj->field4);
		if (r) return r;
	} else {
		r = func_ov024_021f691c(&obj->locks[3], outB, result, obj->field4);
		if (r) return r;
	}
	return func_ov024_021f8628(obj, p1, p2, outB);
}
