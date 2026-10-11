#include <globaldefs.h>

struct S02053dc0 { char pad[0x19c]; void* field19c; };
void* GetField0x19cOrNull(struct S02053dc0* p);

extern "C" void func_ov024_021f9660(void* obj);
extern "C" int func_ov024_021f8628(void* obj, void* p1, void* p2, void* p3);
extern "C" int func_ov024_021f691c(void* obj, unsigned short* outB, void* outA, int key);

struct Ctx_021f83f8 { char pad[4]; short field4; };

// USA: func_ov024_021f83f8
extern "C" ARM int func_ov024_021f83f8(struct Ctx_021f83f8* obj, void* p1, struct S02053dc0* p2, unsigned short* outB) {
	void* result = GetField0x19cOrNull(p2);
	if (!result) return (int)result;
	*(float*)((char*)obj + 0x124) = 0.6f;
	func_ov024_021f9660(obj);
	int r = func_ov024_021f691c((char*)obj + 0xc8 + 0x400, outB, result, obj->field4);
	if (r) return r;
	r = func_ov024_021f691c((char*)obj + 0x98 + 0x400, outB, result, obj->field4);
	if (r) return r;
	if (*(int*)((char*)obj + 0xc) >= 2) {
		r = func_ov024_021f691c((char*)obj + 0x128 + 0x400, outB, result, obj->field4);
		if (r) return r;
		r = func_ov024_021f691c((char*)obj + 0x3d8, outB, result, obj->field4);
		if (r) return r;
	}
	r = func_ov024_021f691c((char*)obj + 0x38 + 0x400, outB, result, obj->field4);
	if (r) return r;
	return func_ov024_021f8628(obj, p1, p2, outB);
}
