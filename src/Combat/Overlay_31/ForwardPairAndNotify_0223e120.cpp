#include <globaldefs.h>

extern "C" ARM void _Z32ForwardFourArgsAsStruct_0223d88412Args0223d884(int args);
extern "C" ARM void _Z32ForwardFourArgsAsStruct_0223bf2c12Args0223bf2c(int args);
#define _Z32ForwardFourArgsAsStruct_0223d88412Args0223d884 _Z32ForwardFourArgsAsStruct_0223d88412Args0223d884
#define _Z32ForwardFourArgsAsStruct_0223bf2c12Args0223bf2c _Z32ForwardFourArgsAsStruct_0223bf2c12Args0223bf2c
extern "C" void func_ov031_0223cf70(void** slot);
#if defined(jpn)
extern "C" char* data_ov031_02290d9c;
namespace DuplicatePool {
    extern "C" char* data_ov031_02290d9c;
}
#else
extern char* data_ov031_02290d9c;
#endif

// USA: func_ov031_0223e120
extern "C" ARM void func_ov031_0223e120(void) {
	int i = 0;
	do {
		_Z32ForwardFourArgsAsStruct_0223d88412Args0223d884(*(int*)(data_ov031_02290d9c + (i << 6) + 8));
		_Z32ForwardFourArgsAsStruct_0223bf2c12Args0223bf2c(*(int*)(data_ov031_02290d9c + (i << 6)));
		i++;
	} while (i < 2);
	{
		extern char* data_ov031_02290d9c;
#if defined(jpn)
		func_ov031_0223cf70((void**)&DuplicatePool::data_ov031_02290d9c);
#else
		func_ov031_0223cf70((void**)((__typeof__(&data_ov031_02290d9c))0x02290D9C));
#endif
	}
}
