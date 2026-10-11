#include <globaldefs.h>

struct Entry02201c84 {
	int flag0;
	unsigned char pad0[0x8 - 4];
	unsigned char flag8;
	unsigned char pad1;
	unsigned short f0a;
	unsigned char pad2[0x18 - 0xc];
	unsigned short f18;
	unsigned char pad3[0x1c - 0x1a];
	int f1c;
};

struct Node02201c84 {
	unsigned char pad0[0x68];
	Node02201c84* next;
	unsigned char pad1[0xa4 - 0x68 - 4];
	Entry02201c84* field;
};

struct RootStruct02111304 { unsigned char pad[0x8]; void* head; };

extern RootStruct02111304 data_02111304;

struct ArgA02201c84 { unsigned char pad0[0xc]; unsigned short f0c; unsigned short f0e; };
struct ArgB02201c84 { unsigned short f00; unsigned short f02; };

// USA: func_ov031_02201c84
#pragma optimize_for_size off
extern "C" ARM void* func_ov031_02201c84(ArgA02201c84* a, ArgB02201c84* b) {
	Entry02201c84* field;
	Node02201c84* node = (Node02201c84*)data_02111304.head;
	if (node) {
	do {
		field = node->field;
		if (field && field->flag0 != 0) {
			if (field->flag8 == 1) {
				unsigned short v = b->f02;
				unsigned short sw = (unsigned short)((v >> 8) | (v << 8));
				if (field->f0a == sw) {
					if (field->f18 != 0) {
						unsigned short v2 = b->f00;
						unsigned short sw2 = (unsigned short)((v2 >> 8) | (v2 << 8));
						if (field->f18 != sw2) goto next;
					}
					if (field->f1c != 0) {
						unsigned short ve = a->f0e;
						unsigned short vc = a->f0c;
						unsigned short swc = (unsigned short)((vc >> 8) | (vc << 8));
						unsigned short swe = (unsigned short)((ve >> 8) | (ve << 8));
						unsigned int combined = ((unsigned int)swc << 0x10) | swe;
						if (field->f1c != (int)combined) goto next;
					}
					return field;
				}
			}
		}
	next:
		node = node->next;
	} while (node);
	}
	return NULL;
}
