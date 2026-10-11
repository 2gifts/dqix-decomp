#include <globaldefs.h>

struct Element020de650;
struct Container020dedd0;
Element020de650* FindElementByKey020dedd0(Container020dedd0*, int);

extern "C" void func_ov023_021dcba4(void*);

struct Obj021dcae0 {
    char pad0[0x48];
    Container020dedd0* field48;
    Element020de650* field4c;
#if defined(jpn)
    char pad50[0x680];
#else
    char pad50[0x704];
#endif
    int field754;
    char pad758[0x18];
    short field770;
    unsigned short field772;
    unsigned short field774;
    unsigned char field776;
};

// JPN: 021dd3ec
// USA: func_ov023_021dcae0  (semantic: UpdateFieldOrDispatch_021dcae0)
extern "C" ARM void func_ov023_021dcae0(struct Obj021dcae0* obj, int val) {
    if (obj->field776 == 0 || (obj->field774 & 4) == 0) {
        obj->field772 = val;
        if (obj->field754 <= 0 || obj->field776 == 0) {
            obj->field770 = val;
            return;
        }
    }
    short v = obj->field770;
    if (v == val) {
        if (obj->field48 != NULL) {
            Element020de650* found = FindElementByKey020dedd0(obj->field48, v);
            if (obj->field4c != found) obj->field4c = found;
        }
    } else {
        func_ov023_021dcba4(obj);
    }
}
