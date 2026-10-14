#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"
#include "Resource/Script.h"

struct Variant02030b0c;

struct TaggedValue02030b44 {
    int type;
    union { int i; float f; } value;
};

struct Element020de650;
struct Container020dedd0;
Element020de650* FindElementByKey020dedd0(struct Container020dedd0*, int);

struct Bits10c_021f5848 {
    unsigned short low13 : 13;
    unsigned short hi3 : 3;
};

struct Target021f5848 {
    char pad0[0xf8];
    short half0xf8;
    char pad1[2];
    unsigned short half0xfc;
    char pad2[0xe];
    struct Bits10c_021f5848 bits;
};

struct Data021fff08_021f5848 {
    char pad0[1];
    unsigned char flag;
    char pad1[2];
    struct Container020dedd0* container;
    char pad2[4];
    struct Target021f5848* ptr;
};
extern struct Data021fff08_021f5848 data_ov023_021fff08;

struct ElementHalf1a_021f5848 { char pad[0x1a]; unsigned short half1a; };

// USA: func_ov023_021f5848
extern "C" ARM int func_ov023_021f5848(struct Variant02030b0c* obj) {
    if (data_ov023_021fff08.flag != 0) return 1;
    int v = ((Script::Parameter*)obj)->ToInt();
    struct Target021f5848* ptr = data_ov023_021fff08.ptr;
    if (v == ptr->half0xf8) {
        if (data_ov023_021fff08.container == 0) {
            data_ov023_021fff08.flag = 1;
            ptr->bits.low13 |= 2;
            return 0;
        }
        struct ElementHalf1a_021f5848* found = (struct ElementHalf1a_021f5848*)FindElementByKey020dedd0(data_ov023_021fff08.container, (short)v);
        if (found == 0) {
            data_ov023_021fff08.flag = 1;
            data_ov023_021fff08.ptr->bits.low13 |= 2;
            return 0;
        }
        GetPtrField0x2a04_02010828(GameState::GetInstance());
        float a = ((Script::Parameter*)((struct TaggedValue02030b44*)((char*)obj + 8)))->ToFloat();
        float b = ((Script::Parameter*)((struct TaggedValue02030b44*)((char*)obj + 0x10)))->ToFloat();
        struct Random* rng = GetBTRandom();
        unsigned short half1a = found->half1a;
        float randVal = NextRandomFloatBetween(rng, a, b);
        int result = (int)((float)half1a * randVal);
        if (result >= data_ov023_021fff08.ptr->half0xfc || (data_ov023_021fff08.ptr->bits.low13 & 4) != 0) {
            data_ov023_021fff08.ptr->bits.low13 |= 1;
        } else {
            data_ov023_021fff08.ptr->bits.low13 |= 2;
        }
        data_ov023_021fff08.flag = 1;
    }
    return 1;
}
