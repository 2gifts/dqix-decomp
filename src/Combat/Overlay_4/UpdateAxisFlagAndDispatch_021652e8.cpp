#include <globaldefs.h>

struct AxisFloats0203b5f8;
int IsAxisIntZero(struct AxisFloats0203b5f8* s, int axis);
extern "C" struct AxisFloats0203b5f8* func_ov017_0218b5b0(void);
int GetGlobalField0x1c020421a0(void);
extern char* data_ov004_02171010;
struct SelectionState {
#if defined(jpn)
    unsigned char unknown[0x19f4];
#else
    unsigned char unknown[0x18f4];
#endif
    unsigned char entryCount;
    unsigned char unknownF5;
    short page;
    short pageCount;
    unsigned char unknownFA[2];
    unsigned char mode;
};
void SetByteFieldAt0x765(unsigned char* obj, unsigned char value);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern struct Obj0205eaa0 data_02108760;
int ToggleFlag8OnTwoObjs_021651c8(void* a1);

#if defined(jpn)
enum { StatusOffset021652e8 = 0x868, ObjectOffset021652e8 = 0x4c0 };
// USA: func_ov004_021652e8
extern "C" ARM int func_ov004_02165b78(void* a1) {
#else
enum { StatusOffset021652e8 = 0x998, ObjectOffset021652e8 = 0x6d0 };
// USA: func_ov004_021652e8
ARM int UpdateAxisFlagAndDispatch_021652e8(void* a1) {
#endif
    struct AxisFloats0203b5f8* axis = func_ov017_0218b5b0();
    if (!IsAxisIntZero(axis, 0) || !IsAxisIntZero(axis, 1)) return 0;
    if (*(void**)((char*)GetGlobalField0x1c020421a0() + StatusOffset021652e8) != NULL) return 0;

    {
        SelectionState* selection = (SelectionState*)data_ov004_02171010;
        unsigned char v = selection->entryCount;
        if (v == 0) return 0;

        unsigned char* mode = &selection->mode;
        v = selection->mode;
        if (v == 0) {
            *mode = 1;
        } else if (v == 1) {
            *mode = 0;
        }

        unsigned char* fieldObj = *(unsigned char**)((char*)func_ov017_0218b5b0() + 0x3000 + ObjectOffset021652e8);
        unsigned char v2 = ((SelectionState*)data_ov004_02171010)->mode;
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
