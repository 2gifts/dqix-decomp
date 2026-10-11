#include <globaldefs.h>
#include "std_library_functions.h"

struct Parse022188e4 {
	unsigned char pad0[0x1024];
	char buf[0x100];
	char* cursor;
	char* cursor2;
	unsigned char pad1[4];
	int flag;
	unsigned short value;
};

extern int data_ov031_02249f24;
extern int data_ov031_02249f2c;
extern int data_ov031_02249f38;
extern int data_ov031_02249f3c;

extern "C" int func_02005a94(char* s);

// USA: func_ov031_022188e4
extern "C" ARM int func_ov031_022188e4(void* self, const char* s) {
	Parse022188e4* p = (Parse022188e4*)self;
	char* tail = NULL;
	if (strlen(s) >= 0x100) {
		return 0;
	}
	strncpy(p->buf, s, 0x100);
	if (strlen(s) != strlen(p->buf)) {
		return 0;
	}
	if (strstr(p->buf, (const char*)&data_ov031_02249f24) != NULL) {
		p->cursor = p->buf + 7;
		p->flag = 0;
		p->value = 0x50;
	} else {
		char* found = strstr(p->buf, (const char*)&data_ov031_02249f2c);
		if (found == NULL) {
			return 0;
		}
		p->cursor = found + 8;
		p->flag = 1;
		p->value = 0x1bc - p->flag;
	}
	char* d1 = strstr(p->cursor, (const char*)&data_ov031_02249f38);
	if (d1 != NULL) {
		*d1 = 0;
		tail = d1 + 1;
	}
	char* d2 = strstr(p->cursor, (const char*)&data_ov031_02249f3c);
	if (d2 == NULL) {
		p->cursor2 = NULL;
	} else {
		*d2 = 0;
		p->cursor2 = d2 + 1;
	}
	if (tail != NULL) {
		p->value = func_02005a94(tail);
	}
	return 1;
}
