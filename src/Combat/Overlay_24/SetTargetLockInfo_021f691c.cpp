#include <globaldefs.h>

void* GetActiveCombatWork_ov000_02160130(void);
void* GetOffsetPtr02160f08(void* obj);
void* FindByKeyIndexed_021f69b4(char* base, int key);
void* GetPointerField_02171b9c_02171b9c(void* obj, int idx);

struct Obj_021f691c {
	unsigned short field0;
	signed char field2;
	char pad3;
	float field4;
	char pad8[2];
	unsigned char field0xa;
	unsigned char field0xb;
};

struct Out_021f691c { unsigned short v0; unsigned char v2; unsigned char v3; };

struct Found_021f691c {
	char pad0[0x18];
	short field0x18;
	char pad1[8];
	signed char field0x22;
	char pad2[9];
	short field0x2c;
};

// USA: func_ov024_021f691c  (semantic: SetTargetLockInfo_021f691c)
extern "C" ARM int func_ov024_021f691c(struct Obj_021f691c* obj, unsigned short* outB, struct Out_021f691c* outA, int key) {
	if (obj->field4 > 0.0f) {
		unsigned short field0 = obj->field0;
		if (obj->field2 >= 0) {
			void* work = GetActiveCombatWork_ov000_02160130();
			void* base = GetOffsetPtr02160f08(work);
			struct Found_021f691c* found = (struct Found_021f691c*)FindByKeyIndexed_021f69b4((char*)base, key);
			if (found) {
				found->field0x22 = obj->field2;
				struct Found_021f691c* p = (struct Found_021f691c*)GetPointerField_02171b9c_02171b9c(found, obj->field2);
				if (p) {
					found->field0x2c = p->field0x18;
				}
			}
		}
		outA->v0 = field0;
		*outB = field0;
		if (obj->field0xa != 0xff) outA->v3 = obj->field0xa;
		if (obj->field0xb != 0xff) outA->v2 = obj->field0xb;
		return 1;
	}
	return 0;
}
