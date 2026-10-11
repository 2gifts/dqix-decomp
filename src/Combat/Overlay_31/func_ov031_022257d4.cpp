// JPN: func_ov031_02225fb4
#include <globaldefs.h>

extern "C" void func_ov031_0223e2c0(int idx, void* obj);
extern "C" void func_ov031_0223ba20(int a);

struct Obj0223c534;
extern "C" void _Z37ProcessField28AndDispatch670_0223c534P11Obj0223c534(Obj0223c534* obj);

struct FlagObj0223da58;
extern "C" int func_ov031_0223da58(FlagObj0223da58* obj);

extern "C" unsigned int func_ov031_0223cf70(void** a);

extern void** data_ov031_02250bfc;

// USA: func_ov031_022257d4  (semantic: DispatchAllEntriesAndFree_022257d4)
extern "C" ARM void func_ov031_022257d4(void* obj) {
	func_ov031_0223e2c0(0, obj);

	int i = 0;
	do {
		int j = 0;
		do {
			_Z37ProcessField28AndDispatch670_0223c534P11Obj0223c534((Obj0223c534*)((void*(*)[4])data_ov031_02250bfc)[i][j]);
			if (i == 0) {
				func_ov031_0223ba20(*(int*)((char*)data_ov031_02250bfc + j * 4 + 0x104));
			}
			j++;
		} while (j < 4);
		i++;
	} while (i < 3);

	int j2 = 0;
	do {
		func_ov031_0223ba20(*(int*)((char*)data_ov031_02250bfc + j2 * 4 + 0xfc));
		j2++;
	} while (j2 < 2);

	int j3 = 0;
	do {
		func_ov031_0223da58(*(FlagObj0223da58**)((char*)data_ov031_02250bfc + j3 * 4 + 0xec));
		j3++;
	} while (j3 < 4);

	int j4 = 0;
	do {
		func_ov031_0223da58(*(FlagObj0223da58**)((char*)data_ov031_02250bfc + j4 * 4 + 0x30));
		j4++;
	} while (j4 < 0x2f);

#if defined(jpn)
	func_ov031_0223cf70((void**)((__typeof__(&data_ov031_02250bfc))0x022517FC));
#else
	func_ov031_0223cf70((void**)((__typeof__(&data_ov031_02250bfc))0x02250BFC));
#endif
}
