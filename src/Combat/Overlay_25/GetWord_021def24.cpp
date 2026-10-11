#include <globaldefs.h>

#if defined(jpn)
enum { WordOffset = 0x8fc };
#else
enum { WordOffset = 0x70c };
#endif

// USA: func_ov025_021def24
ARM int GetWord_021def24(void* obj) {
	unsigned char* base = (unsigned char*)obj;
	return *(int*)(base + 0x7000 + WordOffset);
}
