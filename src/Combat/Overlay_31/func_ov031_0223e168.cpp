#include <globaldefs.h>

struct ListNode0223e168 {
	int field0;
	ListNode0223e168* next;
	void (*fn)(ListNode0223e168*, int);
	int arg;
};

struct Elem0223e168 {
	int field0;
	void* field4;
	char pad0[8];
	ListNode0223e168* head;
	char pad1[0x20 - 0x14];
	ListNode0223e168 sentinelNode;
	char pad2[0x34 - 0x30];
	int count;
	unsigned char flag38;
	char pad3[0x40 - 0x39];
};

extern Elem0223e168* data_ov031_02290d9c;

struct Struct0223bfa0;
extern "C" int func_ov031_0223bfa0(Struct0223bfa0* p);
extern "C" void func_ov031_0223e2ec(int index, void* obj);

// USA: func_ov031_0223e168
extern "C" ARM void func_ov031_0223e168(int idx) {
	Elem0223e168* base = data_ov031_02290d9c;
	Elem0223e168* elem = &base[idx];
	if (elem->flag38 == 0) return;

	ListNode0223e168* node = elem->head;
	ListNode0223e168* sentinel = &elem->sentinelNode;
	if (node != sentinel) {
		do {
			node->fn(node, node->arg);
			base = data_ov031_02290d9c;
			sentinel = &base[idx].sentinelNode;
			node = node->next;
		} while (node != sentinel);
	}

	Elem0223e168* elem2 = &base[idx];
	int count = elem2->count;
	int byteOff = idx << 6;
	int i = 0;
	if (count <= 0) return;

	do {
		Elem0223e168* cur = (Elem0223e168*)(byteOff + (int)base);
		void* obj = (void*)func_ov031_0223bfa0((Struct0223bfa0*)cur->field4);
		if (obj == 0) return;
		func_ov031_0223e2ec(idx, obj);
		base = data_ov031_02290d9c;
		cur = (Elem0223e168*)(byteOff + (int)base);
		count = cur->count;
		i++;
	} while (i < count);
}
