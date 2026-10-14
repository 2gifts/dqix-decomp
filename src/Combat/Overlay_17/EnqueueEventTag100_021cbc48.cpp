#include <globaldefs.h>

extern "C" void func_ov017_021cbdcc(void* obj);
void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Src021cbc48 {
	unsigned short field0;
	unsigned short field2;
	int field4;
	unsigned char field8;
	signed char field9;
	unsigned char fielda;
	unsigned char fieldb;
	unsigned char fieldc;
	short fielde;
};

struct LocalEvt021cbc48 {
	unsigned char tag;
	unsigned char pad0[3];
	unsigned short field4;
	unsigned short field6;
	int field8;
	unsigned char fieldc;
	signed char fieldd;
	unsigned char fielde;
	unsigned char fieldf;
	unsigned char field10;
	unsigned char pad1;
	short field12;
};

// USA: func_ov017_021cbc48
ARM void EnqueueEventTag100_021cbc48(Src021cbc48* src) {
	func_ov017_021cbdcc(src);
	void* p = GetData02100044_0202ae24();

	LocalEvt021cbc48 buf;
	buf.tag = 0x64;
	buf.field4 = src->field0;
	buf.field6 = src->field2;
	buf.field8 = src->field4;
	buf.fieldc = src->field8;
	buf.fieldd = src->field9;
	buf.fielde = src->fielda;
	buf.fieldf = src->fieldb;
	buf.field10 = src->fieldc;
	buf.field12 = src->fielde;
	func_0205e330(p, &buf, 0);
}
