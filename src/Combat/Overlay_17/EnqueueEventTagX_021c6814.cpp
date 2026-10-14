#include <globaldefs.h>
#include "GameState/GameState.h"

void* GetData02100044_0202ae24(void);
int GetField0x3acValue_020100a8(GameState* battleStruct);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Src021c6814 {
	unsigned char field0;
	unsigned char field1;
	unsigned char field2;
	unsigned char field3;
	signed char field4;
	unsigned char pad5;
	unsigned short field6;
	unsigned short field8;
};

struct Body021c6814 {
	unsigned short field4;
	unsigned short field6;
	unsigned short field8;
	unsigned short fielda;
	signed char fieldc;
	unsigned char fieldd;
	unsigned char fielde;
	unsigned char fieldf;
	unsigned char field10;
	unsigned char flag1:1;
	unsigned char flag2:1;
	unsigned char val:6;
	signed char field12;
	unsigned char pad1;
};

struct LocalEvt021c6814 {
	unsigned char tag;
	unsigned char pad0[3];
	Body021c6814 body;
};

// USA: func_ov017_021c6814  (semantic: EnqueueEventTagX_021c6814)
extern "C" ARM void func_ov017_021c6814(unsigned short a, unsigned short b, Src021c6814* src, unsigned char flags, signed char arg5, unsigned char arg6) {
	void* p = GetData02100044_0202ae24();
	LocalEvt021c6814 buf;
	Body021c6814* body = &buf.body;
	GameState* bs = GameState::GetInstance();

	buf.tag = 0x42;
	body->field4 = a;
	body->field6 = b;
	body->fieldd = src->field0;
	body->fielde = src->field1;
	body->fieldf = src->field2;
	body->field10 = src->field3;
	body->field8 = src->field6;
	body->fieldc = src->field4;
	body->fielda = src->field8;
	body->flag1 = flags;

	body->val = GetField0x3acValue_020100a8(bs);
	body->field12 = arg5;
	body->flag2 = arg6;

	func_0205e330(p, &buf, 0);
}
