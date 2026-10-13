#include <globaldefs.h>

struct GameData02250ba8 {
	void* item[2];
	void* item8;
	unsigned int pad0xc;
	void* item10;
};

extern "C" ARM void func_ov031_0223e2c0(int a, int b);
extern "C" ARM void func_ov031_0223ba20(void* p);
extern "C" ARM void func_ov031_0223cf70(GameData02250ba8** p);

#if defined(jpn)
extern "C" GameData02250ba8* data_ov031_02250ba8;
namespace DuplicatePool {
    extern "C" GameData02250ba8* data_ov031_02250ba8;
}
#else
extern GameData02250ba8* data_ov031_02250ba8;
#endif

// USA: func_ov031_022231f0
extern "C" ARM void func_ov031_022231f0(int param) {
	func_ov031_0223e2c0(0, param);

	if (data_ov031_02250ba8->item10) {
		func_ov031_0223e2c0(0, (int)data_ov031_02250ba8->item10);
	}

	int i = 0;
	do {
		if (data_ov031_02250ba8->item[i]) {
			func_ov031_0223ba20(data_ov031_02250ba8->item[i]);
		}
		i++;
	} while (i < 2);

	func_ov031_0223ba20(data_ov031_02250ba8->item8);

#if defined(jpn)
	func_ov031_0223cf70(&DuplicatePool::data_ov031_02250ba8);
#else
	func_ov031_0223cf70((GameData02250ba8**)0x02250BA8);
#endif
}
