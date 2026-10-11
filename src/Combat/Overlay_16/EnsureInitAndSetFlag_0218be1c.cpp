#include <globaldefs.h>

extern "C" void func_ov016_0218be7c(void);
extern int data_ov016_0219d0c0;
extern char data_027e0000;

#if defined(jpn)
#define INIT_FLAG_OFFSET 0x8
#else
#define INIT_FLAG_OFFSET 0x14
#endif

// USA: func_ov016_0218be1c
ARM void EnsureInitAndSetFlag_0218be1c(void) {
	if (*(int*)((char*)&data_ov016_0219d0c0 + INIT_FLAG_OFFSET) == 0) {
		*(int*)((char*)&data_ov016_0219d0c0 + INIT_FLAG_OFFSET) = 1;
		func_ov016_0218be7c();
	}
	*(unsigned int*)((char*)&data_027e0000 + 0x3000 + 0xff8) |= 1;
}
