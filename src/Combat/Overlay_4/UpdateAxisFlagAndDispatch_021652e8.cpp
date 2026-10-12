#include <globaldefs.h>

struct AxisFloats0203b5f8;
int IsAxisIntZero(struct AxisFloats0203b5f8* s, int axis);
extern "C" struct AxisFloats0203b5f8* func_ov017_0218b5b0(void);
int GetGlobalField0x1c020421a0(void);
extern char* data_ov004_02171010;
#if defined(jpn)
extern "C" void func_02025df4(unsigned char* obj, unsigned char value);
#define SetByteFieldAt0x765 func_02025df4
#else
void SetByteFieldAt0x765(unsigned char* obj, unsigned char value);
#endif
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern struct Obj0205eaa0 data_02108760;
int ToggleFlag8OnTwoObjs_021651c8(void* a1);

#if defined(jpn)
enum { StatusOffset021652e8 = 0x868, CountOffset021652e8 = 0x9f4, FlagOffset021652e8 = 0x9fc, FlagPrefix021652e8 = 0x1fc, ObjectOffset021652e8 = 0x4c0 };
// USA: func_ov004_021652e8
extern "C" ARM int func_ov004_02165b78(void* a1) {
#else
enum { StatusOffset021652e8 = 0x998, CountOffset021652e8 = 0x8f4, FlagOffset021652e8 = 0x8fc, FlagPrefix021652e8 = 0xfc, ObjectOffset021652e8 = 0x6d0 };
// USA: func_ov004_021652e8
ARM int UpdateAxisFlagAndDispatch_021652e8(void* a1) {
#endif
    struct AxisFloats0203b5f8* axis = func_ov017_0218b5b0();
    if (IsAxisIntZero(axis, 0) == 0) goto ret0;
    if (IsAxisIntZero(axis, 1) != 0) goto mainlogic;
ret0:
    return 0;

mainlogic:
    if (*(void**)((char*)GetGlobalField0x1c020421a0() + StatusOffset021652e8) != NULL) return 0;

    {
        char* base = data_ov004_02171010;
        unsigned char v = *(unsigned char*)(base + 0x1000 + CountOffset021652e8);
        if (v == 0) return 0;

        unsigned char* target = (unsigned char*)(base + FlagPrefix021652e8 + 0x1800);
        v = *(unsigned char*)(base + 0x1000 + FlagOffset021652e8);
        if (v == 0) {
            *target = 1;
        } else if (v == 1) {
            *target = 0;
        }

        unsigned char* fieldObj = *(unsigned char**)((char*)func_ov017_0218b5b0() + 0x3000 + ObjectOffset021652e8);
        unsigned char v2 = *(unsigned char*)(data_ov004_02171010 + 0x1000 + FlagOffset021652e8);
        if (v2 == 1) {
            SetByteFieldAt0x765(fieldObj, 0);
        } else if (v2 == 0) {
            SetByteFieldAt0x765(fieldObj, 1);
        }

        ToggleFlag8OnTwoObjs_021651c8(a1);
        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
        return 0;
    }
}
