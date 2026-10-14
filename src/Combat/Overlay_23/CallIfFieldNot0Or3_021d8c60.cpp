#include <globaldefs.h>

struct Obj021d8c60 { char pad[0x11a]; unsigned char field11a; };

struct Cont0205d1e0;
void ClearBuffers0204b010OverList0x98(Cont0205d1e0*);
struct Cont0205d228;
void CallFunc0204c8f0OverList0x9c(Cont0205d228*);
struct Cont0205d274;
void CallFunc0204b04cOverList0x98(Cont0205d274*);

// USA: func_ov023_021d8c60
ARM void CallIfFieldNot0Or3_021d8c60(struct Obj021d8c60* obj) {
	unsigned char v = obj->field11a;
	if (v == 0 || v == 3) return;
	ClearBuffers0204b010OverList0x98((Cont0205d1e0*)((char*)obj + 0x20));
	CallFunc0204c8f0OverList0x9c((Cont0205d228*)((char*)obj + 0x20));
	CallFunc0204b04cOverList0x98((Cont0205d274*)((char*)obj + 0x20));
}
