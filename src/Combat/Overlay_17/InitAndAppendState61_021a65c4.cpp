#include <globaldefs.h>
#include "Resource/GameResources.h"

struct TailList020469b4;
struct TailNode020469b4;
struct Obj021a6608;

void InitState61_021a6608(Obj021a6608* p);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);

#if defined(jpn)
static const int kList=0x4ec, kNode=0x96c;
#else
static const int kList=0x6fc, kNode=0xb8c;
#endif

// USA: func_ov017_021a65c4
ARM void InitAndAppendState61_021a65c4(void* unused, unsigned char b, int flag) {
	GameResources* ov = func_ov017_0218b5b0();
	char* base = (char*)ov + 0x3000;
	TailList020469b4* list = *(TailList020469b4**)(base + kList);
	Obj021a6608* node = *(Obj021a6608**)(base + kNode);
	InitState61_021a6608(node);
	*((unsigned char*)node + 0xc) = b;
	if (flag != 0) {
		*((unsigned char*)node + 0xb) = 1;
	}
	AppendNodeToTail(list, (TailNode020469b4*)node);
}
