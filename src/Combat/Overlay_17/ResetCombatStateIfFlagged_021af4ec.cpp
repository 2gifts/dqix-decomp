#include <globaldefs.h>

void* GetDataPtr02114e04_020d6c00(void);
int* GetGlobal02109030(void);
struct StateFlags3c9;
int CheckFlag0x3c9Bit0OrByteNonPositive(struct StateFlags3c9* obj);
void OrBitsIntoField0(unsigned int* p, unsigned int mask);
extern "C" int func_ov017_0218b5b0(void);
extern "C" void* func_0202ae18(void);
void* GetData02100044(void);
void SetBitsInWord(unsigned int* obj, unsigned int mask);
extern "C" void func_0202b0f4(void* obj);
void ClearTwoBytesAtField_02195748(unsigned char* base);
void SetFlag1ForFlagombatants_02192594_02192594(void);
void ClearFlag0x3c9Bit0AndCleanup(unsigned char* obj);
struct BitArrayObj0205e854;
void* FillBitArray0x1524WithFF(struct BitArrayObj0205e854* obj);
void ClearBitsInWord(unsigned int* obj, unsigned int mask);

struct ObjResetCombatState_021af4ec {
	unsigned char pad0;
	unsigned char field1;
	unsigned char pad2[6];
	unsigned char field8;
	unsigned char pad3[6];
	unsigned char field15;
};

// JPN: func_ov017_021afbfc
// USA: func_ov017_021af4ec  (semantic: ResetCombatStateIfFlagged_021af4ec)
extern "C" ARM unsigned char func_ov017_021af4ec(ObjResetCombatState_021af4ec* obj) {
#if defined(jpn)
 enum {regionalOffset0=0x40c3, regionalOffset1=0x40c2};
#else
 enum {regionalOffset0=0x42e3, regionalOffset1=0x42e2};
#endif
	unsigned int* p = (unsigned int*)GetDataPtr02114e04_020d6c00();
	struct StateFlags3c9* g = (struct StateFlags3c9*)GetGlobal02109030();
	if (CheckFlag0x3c9Bit0OrByteNonPositive(g)) {
		OrBitsIntoField0(p, 0x20);
		int f = func_ov017_0218b5b0();
		void* a = func_0202ae18();
		struct BitArrayObj0205e854* d = (struct BitArrayObj0205e854*)GetData02100044();
		obj->field15 = 0;
		SetBitsInWord((unsigned int*)f, 2);
		func_0202b0f4(a);
		ClearTwoBytesAtField_02195748((unsigned char*)f);
		((void (*)(int))SetFlag1ForFlagombatants_02192594_02192594)(f);
		ClearFlag0x3c9Bit0AndCleanup((unsigned char*)g);
		FillBitArray0x1524WithFF(d);
		ClearBitsInWord((unsigned int*)f, 0x40);
		((unsigned char*)f)[regionalOffset0] = 0;
		((unsigned char*)f)[regionalOffset1] = 0;
		obj->field1 = 1;
	}
	return obj->field8;
}
