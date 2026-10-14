#include <globaldefs.h>

extern int data_ov017_021d65f4[];
extern signed char data_ov017_021d65ec[];
extern short data_ov017_021d6618[];

struct Vec3i_021a01f4 { int x; int y; int z; };
extern Vec3i_021a01f4 data_ov017_021d6600[];

void* GetGlobalPtr021075f4_0203cf4c(void);
void* FindEntryPointerByKey0203df78(void* base, int key);
int GetField0x8_02040528(int* obj);
extern "C" int func_ov017_0218dd18(void* arg0, void* entry, int flag);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

// USA: func_ov017_021a01f4
ARM int FindAndApplyEntryVec3_021a01f4(void* unused0, int id, int category, void* arg3, int* outVec) {
	int* p = data_ov017_021d65f4;
	for (int i = 0; *p != -1; p++, i++) {
		if (*p != id) continue;

		signed char cat = data_ov017_021d65ec[i];
		if (cat != category && cat != 4) continue;

		void* globalPtr = GetGlobalPtr021075f4_0203cf4c();
		short* row = data_ov017_021d6618 + i * 8;

		while (*row != -1) {
			void* entryPtr = FindEntryPointerByKey0203df78(globalPtr, *row);
			if (!entryPtr) { row++; continue; }

			int fieldVal = GetField0x8_02040528((int*)entryPtr);
			if (!fieldVal) { row++; continue; }

			if (*((unsigned char*)fieldVal + 2) == 1) { row++; continue; }

			if (func_ov017_0218dd18(arg3, entryPtr, 0)) {
				_ZN8Vector3iaSERKS_(outVec, (int*)&data_ov017_021d6600[i]);
				return 1;
			}

			row++;
		}
	}

	return 0;
}
