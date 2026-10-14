#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
unsigned int GetBitsInField0_0203b4c4(unsigned int* obj, unsigned int mask);
void* GetGlobalPtr021075f4_0203cf4c(void);

struct Entry_203dce4;
struct EntryList_203dce4;
struct Entry_203dce4* GetEntryUnlessFlag0x8000_0203dce4(struct EntryList_203dce4* list, int id);
int GetField0x8_02040528(int* obj);

extern "C" int func_ov017_0218dd18(void* a, struct Entry_203dce4* entry, void* b);

#pragma optimize_for_size off
// USA: func_ov017_0218df50
ARM int NotifyEntriesFlag256_0218df50(void* a, void* b) {
	int result = 0;
	int ctx = func_ov017_0218b5b0();
	if (GetBitsInField0_0203b4c4((unsigned int*)ctx, 0x100) == 0) {
		void* list = GetGlobalPtr021075f4_0203cf4c();
		for (int i = 0; i < 0x20; i++) {
			struct Entry_203dce4* entry = GetEntryUnlessFlag0x8000_0203dce4((struct EntryList_203dce4*)list, i);
			if (!entry) continue;
			int field = GetField0x8_02040528((int*)entry);
			if (*((unsigned char*)field + 2) == 1) continue;
			if (func_ov017_0218dd18(a, entry, b) != 0) {
				result = 1;
			}
		}
	}
	return result;
}
