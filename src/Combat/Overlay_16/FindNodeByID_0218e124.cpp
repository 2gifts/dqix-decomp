#include <globaldefs.h>

struct Node0218e124 {
	unsigned short id;
	char pad[0x18 - 2];
	Node0218e124* next;
};

// USA: func_ov016_0218e124
ARM void* FindNodeByID_0218e124(Node0218e124** list, int id) {
	Node0218e124* node = *list;
	while (node) {
		if (node->id == id) return node;
		node = node->next;
	}
	return NULL;
}
