#include <globaldefs.h>

extern "C" char* func_ov031_022133f8(int);
extern int data_ov031_0224e5c4;

typedef void (*Callback_022132d4)(int, void*, int);

// USA: func_ov031_022132d4
extern "C" ARM void* func_ov031_022132d4(void) {
	char* obj = func_ov031_022133f8(1);
	if (obj == 0) return obj;

	if ((*(unsigned char*)(obj+8)) & 0x10) {
		void* val = func_ov031_022133f8(0x10);
		(*(unsigned char*)(obj+8)) = (*(unsigned char*)(obj+8)) & ~0x10;
		(*(Callback_022132d4*)(obj + 4))(0x10, val, 0xd18);
	}

	if ((*(unsigned char*)(obj+8)) & 0x8) {
		void* val = func_ov031_022133f8(0x8);
		(*(unsigned char*)(obj+8)) = (*(unsigned char*)(obj+8)) & ~0x8;
		(*(Callback_022132d4*)(obj + 4))(0x8, val, 0xc);
	}

	if ((*(unsigned char*)(obj+8)) & 0x4) {
		void* val = func_ov031_022133f8(0x4);
		(*(unsigned char*)(obj+8)) = (*(unsigned char*)(obj+8)) & ~0x4;
		(*(Callback_022132d4*)(obj + 4))(0x4, val, 0x58);
	}

	if ((*(unsigned char*)(obj+8)) & 0x2) {
		void* val = func_ov031_022133f8(0x2);
		(*(unsigned char*)(obj+8)) = (*(unsigned char*)(obj+8)) & ~0x2;
		(*(Callback_022132d4*)(obj + 4))(0x2, val, 0x2300);
	}

	if (!((*(unsigned char*)(obj+8)) & 0x1)) return (void*)(int)(*(unsigned char*)(obj+8));
	(*(unsigned char*)(obj+8)) = (*(unsigned char*)(obj+8)) & ~0x1;
	(*(Callback_022132d4*)(obj + 4))(0x1, obj, 0x24);
	*(int*)((char*)&data_ov031_0224e5c4 + 0xc) = 0;
	return &data_ov031_0224e5c4;
}
