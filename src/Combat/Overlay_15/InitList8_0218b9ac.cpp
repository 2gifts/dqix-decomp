#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"

struct Entry8_0218b9ac { int a; int b; };
struct List8_0218b9ac { void* f0; Entry8_0218b9ac* arr; void* f8; int count; };

void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion data_02114e20;

// USA: func_ov015_0218b9ac
ARM void InitList8_0218b9ac(struct List8_0218b9ac* obj, int n) {
	obj->arr = (Entry8_0218b9ac*)AllocateAligned4_02012d88(&data_02114e20, n * 8);
	obj->count = 0;
}
