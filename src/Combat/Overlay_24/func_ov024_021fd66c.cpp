#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_021fa76c;
extern "C" int _Z27CheckAllFlagsClear_021fa76cP15Struct_021fa76c(struct Struct_021fa76c* combatant);
extern "C" int _Z32CheckField0x14FlagsClear0208824cPh(unsigned char* obj);
struct FlagObj_021da9b0;
extern "C" int _Z22IsFlagBit8Set_021da9b0P16FlagObj_021da9b0(struct FlagObj_021da9b0* obj);
extern "C" int func_ov000_02156068(void* obj, int id, int a2, int a3);
extern "C" void func_ov024_021fd088(void* obj, float pct, int a2);
struct IndexedObj_021fe6b4;
extern "C" void _Z28SetFieldFromIndexed_021fe6b4P19IndexedObj_021fe6b4i(struct IndexedObj_021fe6b4* obj, int val);

struct Field4Bits_021fd66c { unsigned int code : 12; };
struct Field14Bits_021fd66c { unsigned int lo : 7; unsigned int val : 7; };
struct State64c_021fd66c {
	char pad0[4];
	struct Field4Bits_021fd66c bits4;
	char pad8[0x14 - 8];
	struct Field14Bits_021fd66c bits14;
};

struct Inner144_021fd66c {
	char pad[0xa];
	unsigned short lowBits : 7;
	unsigned short nibble : 4;
	unsigned short bit11 : 1;
	unsigned short bit12 : 1;
	unsigned short rest : 3;
};

struct Obj_021fd66c {
	void* field0;
	char pad4[0x2c - 4];
	unsigned char flag2c;
	char pad2d[0x64c - 0x2d];
	struct State64c_021fd66c* state64c;
	char pad650[0x668 - 0x650];
	GameObject* ptr668;
};

// USA: func_ov024_021fd66c
extern "C" ARM void func_ov024_021fd66c(struct Obj_021fd66c* obj) {
	GameObject* c = obj->ptr668;
	if (!_Z27CheckAllFlagsClear_021fa76cP15Struct_021fa76c((struct Struct_021fa76c*)c)) return;
	if (!_Z32CheckField0x14FlagsClear0208824cPh((unsigned char*)c->currentStats_)) return;
	if (_Z22IsFlagBit8Set_021da9b0P16FlagObj_021da9b0((struct FlagObj_021da9b0*)c)) return;
	struct State64c_021fd66c* state = obj->state64c;
	float valF = (float)state->bits14.val;
	unsigned char pctBase = *(unsigned char*)((char*)c->currentStats_ + 0x4e);
	float scaled = valF * ((float)pctBase / 100.0f);
	unsigned int code = state->bits4.code;
	if (code == 0x58) {
		if (*(unsigned short*)c & 0x400) {
			struct Inner144_021fd66c* inner = *(struct Inner144_021fd66c**)((char*)c + 0x144);
			if (inner != NULL && inner->bit12) {
				obj->flag2c = 1;
				scaled = 50.0f;
			}
		}
	} else if (code == 0x52) {
		if (!func_ov000_02156068(obj->field0, *(short*)((char*)c + 4), 9, 0)) return;
	}
	if (scaled > 100.0f) scaled = 100.0f;
	_Z28SetFieldFromIndexed_021fe6b4P19IndexedObj_021fe6b4i((struct IndexedObj_021fe6b4*)obj, 1);
	func_ov024_021fd088(obj, scaled, 3);
}
