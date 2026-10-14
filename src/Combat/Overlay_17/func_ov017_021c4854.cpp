#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);
void DispatchWithZeroExtras_02193428(void* a, void* b);

struct Obj021c4854 {
	unsigned short field0;
};

struct Arr3_021c4854 {
	int a;
	int b;
	int c;
};

struct Src021c4854 {
	unsigned short f0;
	unsigned char f2;
	unsigned char f3;
	unsigned short f4;
	short f6;
	short f8;
	short fa;
	short fc;
};

// USA: func_ov017_021c4854
extern "C" ARM void func_ov017_021c4854(struct Obj021c4854* obj, unsigned char byteArg, unsigned short shortArg, struct Arr3_021c4854* arr, short arg5, unsigned char arg6) {
	unsigned short v0 = obj->field0;
	void* p = GetData02100044_0202ae24();
	unsigned char buf[0x14];
	buf[0] = 0x37;
	Src021c4854* s = (Src021c4854*)(buf + 4);
	s->f0 = v0;
	s->f2 = byteArg;
	s->f4 = shortArg;
	s->f6 = arr->a >> 5;
	s->f8 = arr->b >> 5;
	s->fa = arr->c >> 5;
	s->fc = arg5;
	s->f3 = arg6;
	func_0205e330(p, buf, 0);

	GameState* battle = GameState::GetInstance();
	GameObject* c = battle->GetUnknownGameObject();
	((Object3D*)((unsigned char*)c))->EnableFlag(0x4000000);
	DispatchWithZeroExtras_02193428(c, 0);
}
