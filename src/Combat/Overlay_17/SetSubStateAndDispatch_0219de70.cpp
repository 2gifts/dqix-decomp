#include <globaldefs.h>

void DestroyAllocatorsFromTable_021a0790(char* obj);
void DestroyAllocatorsFromTable_021a0964(char* obj);
void DestroyAllocatorsFromTable_021a0ba8(char* obj);
void DestroyAllocatorsFromTable_021a0f40(char* obj);
void DestroyAllocatorsFromTable_021a1114(char* obj);
void DestroyAllocatorsFromTable_021a0d6c(char* obj);

extern "C" void func_ov017_021a0630(char* obj);
extern "C" void func_ov017_021a07f4(char* obj);
extern "C" void func_ov017_021a09c8(char* obj);
extern "C" void func_ov017_021a0c0c(char* obj);
extern "C" void func_ov017_021a0dd0(char* obj);
extern "C" void func_ov017_021a0fa4(char* obj);

void ResetInputLogA();
void ResetInputLogB();
void PushInputLogA(int id);
void PushInputLogB(int id);

struct NibbleFieldStruct0219de70 {
	char pad[0xc];
	unsigned char val:4;
	unsigned char rest:4;
};

// USA: func_ov017_0219de70
// JPN: func_ov017_0219e960
extern "C" ARM void func_ov017_0219de70(char* obj, void* unused, NibbleFieldStruct0219de70* src) {
	int val = src->val;
	int newState;
	if ((unsigned int)(val - 2) <= 1) newState = 0;
	else if (val == 5) newState = 2;
	else if (val == 6) newState = 3;
	else if (val == 7) newState = 4;
	else if (val == 8) newState = 5;
	else newState = 1;

#if defined(jpn)
	if (*(int*)(obj + 0x2000 + 0x8f8) == newState) return;
#else
	if (*(int*)(obj + 0x2000 + 0xb08) == newState) return;
#endif

#if defined(jpn)
	switch (*(int*)(obj + 0x2000 + 0x8f8)) {
#else
	switch (*(int*)(obj + 0x2000 + 0xb08)) {
#endif
	case 0: DestroyAllocatorsFromTable_021a0790(obj); break;
	case 1: DestroyAllocatorsFromTable_021a0964(obj); break;
	case 3: DestroyAllocatorsFromTable_021a0f40(obj); break;
	case 4: DestroyAllocatorsFromTable_021a1114(obj); break;
	case 2: DestroyAllocatorsFromTable_021a0ba8(obj); break;
	case 5: DestroyAllocatorsFromTable_021a0d6c(obj); break;
	}

#if defined(jpn)
	*(int*)(obj + 0x2000 + 0x8f8) = newState;
#else
	*(int*)(obj + 0x2000 + 0xb08) = newState;
#endif

	switch (newState) {
	case 0: func_ov017_021a0630(obj); break;
	case 1: func_ov017_021a07f4(obj); break;
	case 3: func_ov017_021a0dd0(obj); break;
	case 4: func_ov017_021a0fa4(obj); break;
	case 2: func_ov017_021a09c8(obj); break;
	case 5: func_ov017_021a0c0c(obj); break;
	}

	ResetInputLogA();
	ResetInputLogB();

#if defined(jpn)
	int s = *(int*)(obj + 0x2000 + 0x8f8);
#else
	int s = *(int*)(obj + 0x2000 + 0xb08);
#endif
	if (s == 0 || s == 2 || s == 5) {
		PushInputLogA(3);
		PushInputLogB(1);
	} else if (s == 1) {
		PushInputLogA(0);
		PushInputLogB(1);
	}
}
