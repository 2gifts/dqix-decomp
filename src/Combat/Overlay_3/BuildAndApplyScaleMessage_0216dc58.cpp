#include <globaldefs.h>
#if defined(jpn)
enum { kRegion12c0 = 0x1150 };
enum { kRegion1324 = 0x11b4 };
#else
enum { kRegion12c0 = 0x12c0 };
enum { kRegion1324 = 0x1324 };
#endif


extern "C" void __clear(void* buf, int len);

struct Struct_0205c570;
int GetActiveScaledSum0205d794(struct Struct_0205c570* s);

int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);

int AppendString02042058(char* dst, const char* src);

struct StructA0205d5d0;
#if defined(jpn)
extern "C" int _Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih(StructA0205d5d0*, int, int, int);
#endif
int TryApplyElemFields0205d5d0(struct StructA0205d5d0* a, int b, int c, int d, unsigned char e);

// JPN: func_ov003_0216d5f4
// USA: func_ov003_0216dc58  (semantic: BuildAndApplyScaleMessage_0216dc58)
extern "C" ARM void func_ov003_0216dc58(char* obj) {
	char buf1[0x100];
	char buf2[0x40];
	int field;
	__clear(buf1, 0x100);
	__clear(buf2, 0x40);
	if (*(int*)(obj + 0x10) == 2) {
		int sum = GetActiveScaledSum0205d794(*(struct Struct_0205c570**)(obj + kRegion12c0));
		AppendFrameTag02041c08(buf1, sum, 8, 5, 5, 5);
	}
	field = GetFieldByKey020e0434((struct Container020e0310*)(obj + kRegion1324), 0x5c);
	AppendString02042058(buf1, (const char*)field);
#if defined(jpn)
	_Z26TryApplyElemFields0205d5d0P15StructA0205d5d0iiih((struct StructA0205d5d0*)(*(void**)(obj + kRegion12c0)), 0, (int)buf1, 1);
#else
	TryApplyElemFields0205d5d0((struct StructA0205d5d0*)(*(void**)(obj + kRegion12c0)), 0, (int)buf1, 1, 0);
#endif
}
