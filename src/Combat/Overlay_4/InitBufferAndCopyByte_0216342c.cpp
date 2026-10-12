#include <globaldefs.h>
#include "System/Memory.h"

extern "C" int func_ov017_0218b5b0(void);

#if defined(jpn)
enum { BufferSize0216342c = 0x1a14, SourceByte0216342c = 0xc0, TailOffset0216342c = 0x9fa };
// USA: func_ov004_0216342c
extern "C" ARM void func_ov004_02163a20(void* a) {
#else
enum { BufferSize0216342c = 0x1914, SourceByte0216342c = 0x2e0, TailOffset0216342c = 0x8fa };
// USA: func_ov004_0216342c
ARM void InitBufferAndCopyByte_0216342c(void* a) {
#endif
	int r = func_ov017_0218b5b0();
	VectorizedMemset(a, 0, BufferSize0216342c);
	unsigned char* base = (unsigned char*)a;
	base[0x1000 + TailOffset0216342c] = *(unsigned char*)((char*)r + 0x4000 + SourceByte0216342c);
	base[0x1000 + TailOffset0216342c + 1] = 0;
	base[0x1000 + TailOffset0216342c + 2] = 0;
	base[0x1000 + TailOffset0216342c + 3] = 0;
	base[0x1000 + TailOffset0216342c + 4] = 0;
}
