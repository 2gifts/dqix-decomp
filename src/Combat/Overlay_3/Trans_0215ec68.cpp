#include <globaldefs.h>

struct ShapeSize {
    short w;
    short h;
};

extern const ShapeSize data_ov003_0217f3b2[];
extern const ShapeSize data_ov003_0217f3b4[];

// USA: func_ov003_0215ec68  (semantic: Trans_0215ec68)
extern "C" ARM void func_ov003_0215ec68(int size, short* width, short* height) {
    *width = data_ov003_0217f3b2[size].w;
    *height = data_ov003_0217f3b4[size].w;
}
