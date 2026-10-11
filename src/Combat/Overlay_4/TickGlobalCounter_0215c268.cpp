#if defined(jpn)
#define R(j,u) (j)
#define _Z32DispatchEventAndSetFlag_021589e8Pv func_ov004_02159a94
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

int GetGlobal02109400(void);
int AlwaysTrue02094b4c(void);
extern "C" void _Z21BlankFunction02094b34v(int, int, int, int, int);
#if defined(jpn)
#define DispatchEventAndSetFlag_021589e8 func_ov004_02159a94
extern "C" int DispatchEventAndSetFlag_021589e8(void*);
#else
int DispatchEventAndSetFlag_021589e8(void*);
#endif

struct Struct021707d8_0215c268 { char pad[8]; char* p; };
extern Struct021707d8_0215c268 data_ov004_021707d8;

// USA: func_ov004_0215c268
ARM int TickGlobalCounter_0215c268(void* obj) {
	int result;
	unsigned char* p = (unsigned char*)data_ov004_021707d8.p;
	if (p[0x30] == 0) goto skip;
	{
		int g = GetGlobal02109400();
		unsigned char* p2 = (unsigned char*)data_ov004_021707d8.p;
		if (p2[0x2c] != 0) goto elseBranch;
		_Z21BlankFunction02094b34v(g, 0x72, 0x202, 0, 0);
		{
			unsigned char* p3 = (unsigned char*)data_ov004_021707d8.p;
			p3[0x2c] = p3[0x2c] + 1;
		}
		result = 1;
		goto done;
	elseBranch:
		if (AlwaysTrue02094b4c()) {
			unsigned char* p4 = (unsigned char*)data_ov004_021707d8.p;
			p4[0x2c] = 0;
			goto skip;
		}
		result = 1;
		goto done;
	}
skip:
	DispatchEventAndSetFlag_021589e8(obj);
	result = 0;
done:
	return result;
}
