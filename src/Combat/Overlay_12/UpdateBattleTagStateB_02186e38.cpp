#if defined(jpn)
#define func_ov023_021e6de4 func_ov023_021e7148
#define func_ov012_0218432c func_ov012_021853a0
#define func_ov012_0218930c func_ov012_02189be8
#define func_ov012_0218adac func_ov012_0218bba0
enum {
    kStepOffset = 0x1340,
    kActiveOffset = 0x1368,
    kWindowOffset = 0x90,
    kChoiceBOffset = 0x1434,
    kStringsOffset = 0x1314,
    kProfileOffset = 0x543c,
    kTitleTextOffset = 0x1498,
    kNameKeyBase = 0x2774,
    kNameIdBase = 100
};
#else
enum {
    kStepOffset = 0x1370,
    kActiveOffset = 0x13a0,
    kWindowOffset = 0xac,
    kChoiceBOffset = 0x13dc,
    kStringsOffset = 0x133c,
    kProfileOffset = 0x569c,
    kTitleTextOffset = 0x1440,
    kNameKeyBase = 0x2846,
    kNameIdBase = 310
};
#endif

#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

struct ProfileNameSelection {
    unsigned int header;
    unsigned int unknown : 9;
    int title : 10;
    int accolade : 11;
    unsigned int edited : 1;
    unsigned int unknownHigh : 1;
};

static inline ProfileNameSelection* GetProfileNameSelection(GameState* state) {
    return (ProfileNameSelection*)((char*)state + kProfileOffset);
}


struct Struct0205de24;
void FindAndLinkMatchingEntry0205de24(struct Struct0205de24* obj, unsigned char keyLow, unsigned char keyHigh);

struct Struct_0205c570;
int GetActiveScaledSum0205d794(struct Struct_0205c570* s);

void SetupBattleTag02189a78(char* base);

struct TableA68;
void* FindEntryByKey(struct TableA68* table, int key);

struct Obj0205eaa0;
extern struct Obj0205eaa0 data_02108760;
extern "C" int _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);

struct Obj021e6e20;
int TestFlagsAndActiveElement2_021e6e20(struct Obj021e6e20* obj);

extern "C" void func_ov023_021e6e60(void* self);
extern "C" int func_ov023_021e6de4(char* obj);
extern "C" int func_ov012_0218432c(int a);
extern "C" int func_ov023_021e6448(void* self);
#if defined(jpn)
extern "C" void func_ov012_0218adac(void*, int, int);
#else
extern "C" void func_ov012_0218adac(void* self, int a, int b, int c);
#endif
extern "C" void func_ov012_0218930c(void* self, int flag);

// JPN: func_ov012_02187560
// USA: func_ov012_02186e38  (semantic: UpdateBattleTagStateB_02186e38)
extern "C" ARM void func_ov012_02186e38(char* self) {
	unsigned char state = *(unsigned char*)(self + kStepOffset);
	if (state == 0) {
		*(unsigned char*)(self + kActiveOffset) = 0;
		int v = func_ov012_0218432c(0);
		*(int*)(self + kChoiceBOffset) = v;
		if (v < 0) *(int*)(self + kChoiceBOffset) = 0;

		FindAndLinkMatchingEntry0205de24((struct Struct0205de24*)(self + kWindowOffset), 0, 3);
		func_ov023_021e6e60(self);
		SetupBattleTag02189a78(self);
		(*(unsigned char*)(self + kStepOffset))++;
		return;
	}
	if (state != 1) return;

	*(unsigned char*)(self + kActiveOffset) = 1;
	*(int*)(self + kChoiceBOffset) = GetActiveScaledSum0205d794((struct Struct_0205c570*)(self + kWindowOffset));
	if (func_ov023_021e6448(self) != 0) {
		*(int*)(self + kChoiceBOffset) = GetActiveScaledSum0205d794((struct Struct_0205c570*)(self + kWindowOffset));
	}

	if (func_ov023_021e6de4(self) != 0) {
		_Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
		void* battleStruct = GameState::GetInstance();
		int val = *(int*)(self + kChoiceBOffset);
		void* name = FindEntryByKey((struct TableA68*)(self + kStringsOffset), (short)(val + kNameKeyBase));
		ProfileNameSelection* profile = GetProfileNameSelection((GameState*)battleStruct);

		memset(self + kTitleTextOffset, 0, 0x40);
		int len = strlen((char*)name);
		memcpy(self + kTitleTextOffset, name, len);

		profile->title = *(unsigned int*)(self + kChoiceBOffset) + kNameIdBase;

#if defined(jpn)
		func_ov012_0218adac(self, 0, -1);
#else
		func_ov012_0218adac(self, 0, -1, 0);
#endif
		func_ov012_0218930c(self, 0);
		return;
	}

	if (TestFlagsAndActiveElement2_021e6e20((struct Obj021e6e20*)self) == 0) return;
	func_ov012_0218930c(self, 1);
}
