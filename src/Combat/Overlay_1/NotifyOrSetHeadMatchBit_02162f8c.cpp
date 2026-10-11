#include <globaldefs.h>

struct HeadNode02046b24;

extern "C" int func_ov017_0218b5b0(void);
extern "C" void func_ov017_021d6134(void* obj, int val);
unsigned int GetBitsInField0(unsigned int* obj, unsigned int mask);
int GetHeadNodeIdOrMinusOne(struct HeadNode02046b24** obj);
void SetBitsInWord(unsigned int* obj, unsigned int mask);

// USA: func_ov001_02162f8c
ARM int NotifyOrSetHeadMatchBit_02162f8c(void* obj) {
#if defined(jpn)
    enum { headOffset = 0x4f0 };
#else
    enum { headOffset = 0x700 };
#endif
	unsigned int* p = (unsigned int*)func_ov017_0218b5b0();
	if (GetBitsInField0(p, 0x10) != 0) {
		func_ov017_021d6134(obj, 0);
		return 1;
	}
	struct HeadNode02046b24** list = *(struct HeadNode02046b24***)((char*)p + 0x3000 + headOffset);
	int id = GetHeadNodeIdOrMinusOne(list);
	int notMatch = (id != 0x13);
	func_ov017_021d6134(obj, notMatch == 0);
	if (notMatch) {
		SetBitsInWord(p, 0x10);
	}
	return 1;
}
