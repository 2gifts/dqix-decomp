#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct List0202fe68;
struct List0202fec8;

struct ResetStruct;
extern "C" int _ZN6Script10InitializeEv(struct ResetStruct* s);
struct StreamState;
struct StreamHeader;
extern "C" int _ZN6Script4LoadEPKvj(struct StreamState* s, struct StreamHeader* buffer, int length);
struct Struct02030774;
extern "C" int _ZN6Script7ExecuteEv(struct Struct02030774* p);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(struct ResetStruct*, int*);

extern int data_ov031_02291e04;
extern int data_ov031_0224c8dc;

// USA: func_ov031_02243714
// JPN: func_ov031_02243ef4
extern "C" ARM int func_ov031_02243714(char* ctx) {
	char local[0x430];
	int out1, out2;
	int list = (int)BackgroundLoader::GetInstance();
	if (!((BackgroundLoader*)(list))->GetTaskStatus((int)(*(int*)(ctx + 0x39c))) || !((BackgroundLoader*)(list))->GetTaskStatus((int)(*(int*)(ctx + 0x3a0)))) {
		return 3;
	}
	if (((BackgroundLoader*)((struct List0202fe68*)list))->GetDetailedTaskStatus((int)(*(int*)(ctx + 0x39c))) != 2) {
		((BackgroundLoader*)((void*)list))->RemoveTask((int)(*(int*)(ctx + 0x39c)));
		return 2;
	}
	if (((BackgroundLoader*)((struct List0202fe68*)list))->GetDetailedTaskStatus((int)(*(int*)(ctx + 0x3a0))) != 2) {
		((BackgroundLoader*)((void*)list))->RemoveTask((int)(*(int*)(ctx + 0x3a0)));
		return 2;
	}
	((BackgroundLoader*)((struct List0202fec8*)list))->GetLoadedFileByID((int)(*(int*)(ctx + 0x39c)), (void**)(&out1), (unsigned int*)(&out2));
	*(int*)(ctx + 0x388) = out1;
	*(int*)(ctx + 0x38c) = out2;
	void* allocated = ((SafeAllocator*)ctx)->Allocate(0x38);
#if defined(jpn)
	*(void**)((char*)&data_ov031_02291e04 + 0x2c) = allocated;
#else
	*(void**)((char*)&data_ov031_02291e04 + 0x28) = allocated;
#endif
	if (allocated == 0) return 2;
	memset(allocated, 0, 0x38);
	((BackgroundLoader*)((struct List0202fec8*)list))->GetLoadedFileByID((int)(*(int*)(ctx + 0x3a0)), (void**)(&out1), (unsigned int*)(&out2));
	_ZN6Script10InitializeEv((struct ResetStruct*)local);
	_ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE((struct ResetStruct*)local, &data_ov031_0224c8dc);
	_ZN6Script4LoadEPKvj((struct StreamState*)local, (struct StreamHeader*)out1, out2);
	_ZN6Script7ExecuteEv((struct Struct02030774*)local);
	return 1;
}
