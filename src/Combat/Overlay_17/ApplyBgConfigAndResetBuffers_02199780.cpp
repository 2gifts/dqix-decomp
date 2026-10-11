#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "System/Cache.h"
#include "std_library_functions.h"


struct Struct020dfc40;
void ResetAndDetach020dfc6c(struct Struct020dfc40* p);

struct Entry_02199684 { unsigned char pad[0x14]; int val; unsigned char pad2[0x20 - 0x18]; };
void FillEntriesEncoded_02199684(Entry_02199684* arr, int count, int value);
void ClearAndEncodeEntries_021996bc(Entry_02199684* arr, int count);

struct Cont0205d1e0;
void ClearBuffers0204b010OverList0x98(Cont0205d1e0*);
struct Cont0205d274;
void CallFunc0204b04cOverList0x98(Cont0205d274*);
struct Obj0205d2bc;
void InitEntries0205d2bc(struct Obj0205d2bc*);
extern "C" void func_0205d048(void* obj);

void InitFieldArenaListsAndCounters_021996fc(unsigned char* base);

extern "C" int LoadToMainBG1CharacterData(int arg0, int arg1, unsigned int arg2);

int SetBg1ControlBits_02199964(int size, int colorMode, int mapBase, int tileBase, int wrap);
int SetBg1CntPriority_02199998(int priority);
int SetBg2CntFull_021999b4(int screenSize, int colorMode, int screenBase, int charBase);
int SetBg2CntPriority_021999e0(int priority);

struct BackgroundControlFields {
	unsigned short priority : 2;
	unsigned short tileBase : 4;
	unsigned short unused6 : 1;
	unsigned short colorMode : 1;
	unsigned short mapBase : 5;
	unsigned short wrap : 1;
	unsigned short size : 2;
};

// CancelActionIfHeadIdMatches_02199e98 invokes this on its active state.
// A nonnegative background task ID is removed before applying BG1/BG2
// configuration and resetting buffers; the broader state owner remains unnamed.
// USA: func_ov017_02199780
// JPN: func_ov017_0219a330
extern "C" ARM void func_ov017_02199780(unsigned char* self) {
#if defined(jpn)
	if (*(int*)(self + 0x3000 + 0xe60) == 0) {
#else
	if (*(int*)(self + 0x4000 + 0x80) == 0) {
#endif
		return;
	}

#if defined(jpn)
	if (*(int*)(self + 0x3000 + 0xe58) != 0) {
#else
	if (*(int*)(self + 0x4000 + 0x78) != 0) {
#endif
		*(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & ~0x1f00) | 0x100;

#if defined(jpn)
		int backgroundTaskId = *(int*)(self + 0x3000 + 0xe5c);
#else
		int backgroundTaskId = *(int*)(self + 0x4000 + 0x7c);
#endif
		if (backgroundTaskId >= 0) {
			int backgroundLoaderAddress = (int)BackgroundLoader::GetInstance();
#if defined(jpn)
			((BackgroundLoader*)(backgroundLoaderAddress))->RemoveTask((int)(*(int*)(self + 0x3000 + 0xe5c)));
#else
			((BackgroundLoader*)(backgroundLoaderAddress))->RemoveTask((int)(*(int*)(self + 0x4000 + 0x7c)));
#endif
		}

		*(volatile unsigned short*)0x4000050 = 0;
		*(volatile unsigned short*)0x4000008 = (*(volatile unsigned short*)0x4000008 & ~3) | 1;

#if defined(jpn)
		BackgroundControlFields* bg1Config = *(BackgroundControlFields**)(self + 0x3000 + 0xa88);
#else
		BackgroundControlFields* bg1Config = *(BackgroundControlFields**)(self + 0x3000 + 0xca8);
#endif
		SetBg1ControlBits_02199964(bg1Config->size, bg1Config->colorMode, bg1Config->mapBase, bg1Config->tileBase, bg1Config->wrap);
		SetBg1CntPriority_02199998(bg1Config->priority);

#if defined(jpn)
		BackgroundControlFields* bg2Config = *(BackgroundControlFields**)(self + 0x3000 + 0xa8c);
#else
		BackgroundControlFields* bg2Config = *(BackgroundControlFields**)(self + 0x3000 + 0xcac);
#endif
		SetBg2CntFull_021999b4(bg2Config->size, bg2Config->colorMode, bg2Config->mapBase, bg2Config->tileBase);
		SetBg2CntPriority_021999e0(bg2Config->priority);

#if defined(jpn)
		if (*(int*)(self + 0x3000 + 0xe64) != 0) {
			ResetAndDetach020dfc6c((Struct020dfc40*)*(int*)(self + 0x3000 + 0xe64));
			*(int*)(self + 0x3000 + 0xe64) = 0;
#else
		if (*(int*)(self + 0x4000 + 0x84) != 0) {
			ResetAndDetach020dfc6c((Struct020dfc40*)*(int*)(self + 0x4000 + 0x84));
			*(int*)(self + 0x4000 + 0x84) = 0;
#endif
		}

#if defined(jpn)
		if (*(int*)(self + 0x3000 + 0xe54) != 0) {
			FillEntriesEncoded_02199684((Entry_02199684*)(self + 0x294 + 0x3800), 2, 0x800);
			ClearBuffers0204b010OverList0x98(*(Cont0205d1e0**)(self + 0x3000 + 0xa90));
			CallFunc0204b04cOverList0x98(*(Cont0205d274**)(self + 0x3000 + 0xa90));
			InitEntries0205d2bc(*(Obj0205d2bc**)(self + 0x3000 + 0xa90));
			ClearAndEncodeEntries_021996bc((Entry_02199684*)(self + 0x294 + 0x3800), 2);
			func_0205d048(*(void**)(self + 0x3000 + 0xa90));
#else
		if (*(int*)(self + 0x4000 + 0x74) != 0) {
			FillEntriesEncoded_02199684((Entry_02199684*)(self + 0xb4 + 0x3c00), 2, 0x800);
			ClearBuffers0204b010OverList0x98(*(Cont0205d1e0**)(self + 0x3000 + 0xcb0));
			CallFunc0204b04cOverList0x98(*(Cont0205d274**)(self + 0x3000 + 0xcb0));
			InitEntries0205d2bc(*(Obj0205d2bc**)(self + 0x3000 + 0xcb0));
			ClearAndEncodeEntries_021996bc((Entry_02199684*)(self + 0xb4 + 0x3c00), 2);
			func_0205d048(*(void**)(self + 0x3000 + 0xcb0));
#endif

#if defined(jpn)
			memset(*(void**)(self + 0x3000 + 0xe54), 0, 0x20);
			CleanInvalidateCacheRange(*(void**)(self + 0x3000 + 0xe54), 0x20);
			LoadToMainBG1CharacterData(*(int*)(self + 0x3000 + 0xe54), 0, 0x20);
#else
			memset(*(void**)(self + 0x4000 + 0x74), 0, 0x20);
			CleanInvalidateCacheRange(*(void**)(self + 0x4000 + 0x74), 0x20);
			LoadToMainBG1CharacterData(*(int*)(self + 0x4000 + 0x74), 0, 0x20);
#endif
		}

		*(volatile unsigned int*)0x4000000 = (*(volatile unsigned int*)0x4000000 & ~0x1f00) | 0x1300;
	}

	InitFieldArenaListsAndCounters_021996fc(self);
}
