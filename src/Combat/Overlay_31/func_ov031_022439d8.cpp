#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

struct FlagWord020466f4;

struct Struct022439d8 {
	unsigned char pad0[0x28];
	SafeAllocator* f28;
	unsigned char pad1[0x30 - 0x2c];
	int f30;
	unsigned char pad2[0x44 - 0x34];
	unsigned char f44;
	unsigned char pad3[0x374 - 0x45];
	unsigned char f374;
	unsigned char pad4[0x37c - 0x375];
	void* f37c;
	unsigned char pad5[0x39c - 0x380];
	int f39c;
	int f3a0;
};

extern SafeAllocator data_ov031_02291e3c;
extern "C" void func_ov023_021f5b9c(void* a, void* b, int c, void* d);
void SetByteField0x253_020397c0(void* p);
FlagWord020466f4* GetDataPtr02114e04_020d6c00(void);
void ClearFlags020466f4(FlagWord020466f4* p, unsigned int flags);

// USA: func_ov031_022439d8
extern "C" ARM int func_ov031_022439d8(Struct022439d8* ctx) {
	void* base = func_ov017_0218b5b0();
	BackgroundLoader* loader = BackgroundLoader::GetInstance();
	GameObject* obj = GameState::GetInstance()->GetUnknownGameObject();
	if (obj != 0) {
		SetByteField0x253_020397c0(obj);
	}
#if defined(jpn)
	*(int*)((char*)base + 0x41e4) = 0;
#else
	*(int*)((char*)base + 0x4494) = 0;
#endif
	if (ctx->f39c >= 0) {
		loader->RemoveTask(ctx->f39c);
		ctx->f39c = -1;
	}
	if (ctx->f3a0 >= 0) {
		loader = BackgroundLoader::GetInstance();
		loader->RemoveTask(ctx->f3a0);
		ctx->f3a0 = -1;
	}
	SignedAllocatorHeader* p = data_ov031_02291e3c.GetSignedAllocator();
	if (p != 0) {
		data_ov031_02291e3c.Destroy();
		((SafeAllocator*)ctx)->Free(p);
	}
	p = ((SafeAllocator*)ctx)->GetSignedAllocator();
	if (p != 0) {
		((SafeAllocator*)ctx)->Destroy();
		ctx->f28->Free(p);
	}
	if (ctx->f44 & 1) {
		((SafeAllocator*)ctx)->ResetAllocatorPointer();
		void* buf = ctx->f28->Allocate(0xf000);
		if (buf != 0) {
			((SafeAllocator*)ctx)->CreateTypeA(buf, 0xf000);
			((SafeAllocator*)ctx)->Reset();
			func_ov023_021f5b9c(ctx->f37c, (char*)ctx + 0x50, 4, ctx);
		}
		p = ((SafeAllocator*)ctx)->GetSignedAllocator();
		if (p != 0) {
			((SafeAllocator*)ctx)->Destroy();
			ctx->f28->Free(p);
		}
	}
	if ((ctx->f374 & 0x20) == 0) {
		ClearFlags020466f4(GetDataPtr02114e04_020d6c00(), 0x80);
	}
	ctx->f30 = 1;
	return 2;
}
