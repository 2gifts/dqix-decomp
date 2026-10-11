#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

extern "C" int _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(struct TaggedNumber02184c30* v);
extern "C" ARM void* func_ov017_021b2164(void);
extern "C" ARM void* func_ov011_021849c8(void* ctx);
extern "C" ARM void* func_ov023_021f6880(void* list, int id);
extern "C" ARM int func_ov023_021f6f10(void* obj);

struct Grid021f9b30;
extern "C" int _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(struct Grid021f9b30* self, short val, unsigned int x, unsigned int y);

// USA: func_ov011_02185848
extern "C" ARM int func_ov011_02185848(struct TaggedNumber02184c30* params, int count) {
    int id = _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(&params[0]);
    int id2 = _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(&params[1]);
    int unk2 = _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(&params[2]);
    int unk3 = _Z28GetTaggedValueAsInt_02184c30P20TaggedNumber02184c30(&params[3]);
    void* objects = func_ov011_021849c8(func_ov017_021b2164());
    void* object = func_ov023_021f6880(objects, id);
    void* object2 = func_ov023_021f6880(objects, id2);
    if (object == 0 || object2 == 0)
        return 0;
    if (func_ov023_021f6f10(object) != 7)
        return 0;

    return ((int (*)(void*, unsigned short, unsigned short, unsigned short))_Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj)(object, id2, unk3, unk2) ? 1 : 0;
}
