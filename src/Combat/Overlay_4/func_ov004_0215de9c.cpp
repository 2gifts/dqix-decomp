#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
int ScaleStatsIfType12_021f6f10(void* self);
struct Struct0200fb08;
unsigned char NormalizeField5_0200fb08(struct Struct0200fb08* obj);
struct Obj021fb25c;
void SetShorts_021fb25c(Obj021fb25c* obj, unsigned int a, unsigned int b, unsigned int c, int d);

struct ParamsDE9C { int type; int x; int y; };

class VObjDE9C {
public:
	virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
	virtual void v04(); virtual void v05(); virtual void v06();
	virtual void SetParams(ParamsDE9C* p);
};

// USA: func_ov004_0215de9c
extern "C" ARM int func_ov004_0215de9c(void* a) {
	GameState* battle = GameState::GetInstance();
	void* base = func_ov011_021849c8(a);
	VObjDE9C* node = (VObjDE9C*)func_ov023_021f6880(base, 0x2be);
	if (!node) return 0;
	if (ScaleStatsIfType12_021f6f10(node) != 1) return 0;
	ParamsDE9C p;
	p.x = 0x5a000;
	p.y = 0;
	switch (NormalizeField5_0200fb08((struct Struct0200fb08*)battle)) {
	case 1:
		p.type = 0x90000;
		node->SetParams(&p);
		SetShorts_021fb25c((struct Obj021fb25c*)node, 0, 0, 0x2c, 0xc);
		break;
	case 2:
		p.type = 0x90000;
		node->SetParams(&p);
		SetShorts_021fb25c((struct Obj021fb25c*)node, 0, 0, 0x2c, 0xc);
		break;
	case 3:
		p.type = 0x98000;
		node->SetParams(&p);
		SetShorts_021fb25c((struct Obj021fb25c*)node, 0, 0, 0x20, 0xc);
		break;
	case 4:
		p.type = 0x8c000;
		node->SetParams(&p);
		SetShorts_021fb25c((struct Obj021fb25c*)node, 0, 0, 0x32, 0xc);
		break;
	case 5:
		p.type = 0x8c000;
		node->SetParams(&p);
		SetShorts_021fb25c((struct Obj021fb25c*)node, 0, 0, 0x32, 0xc);
		break;
	}
	void* node2 = func_ov023_021f6880(base, 0x2bf);
	if (!node2) return 0;
	if (ScaleStatsIfType12_021f6f10(node2) != 1) return 0;
	switch (NormalizeField5_0200fb08((struct Struct0200fb08*)battle)) {
	case 1: SetShorts_021fb25c((struct Obj021fb25c*)node2, 0, 0, 0x2c, 0xc); break;
	case 2: SetShorts_021fb25c((struct Obj021fb25c*)node2, 0, 0, 0x2c, 0xc); break;
	case 3: SetShorts_021fb25c((struct Obj021fb25c*)node2, 0, 0, 0x24, 0xc); break;
	case 4: SetShorts_021fb25c((struct Obj021fb25c*)node2, 0, 0, 0x30, 0xc); break;
	case 5: SetShorts_021fb25c((struct Obj021fb25c*)node2, 0, 0, 0x30, 0xc); break;
	}
	return 0;
}
