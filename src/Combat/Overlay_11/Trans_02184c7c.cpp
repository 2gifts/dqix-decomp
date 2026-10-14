#include <globaldefs.h>

struct TaggedNumber02184c30 {
    int type;
    union { int i; float f; } value;
};

struct GameResources;

void SetBrightness(struct GameResources* resources, int brightness, int duration);
int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);
extern "C" struct GameResources* func_ov017_0218b5b0(void);

// USA: func_ov011_02184c7c  (semantic: Trans_02184c7c)
extern "C" ARM int func_ov011_02184c7c(struct TaggedNumber02184c30* params, int count) {
    struct GameResources* resources = func_ov017_0218b5b0();
    int brightness = GetTaggedValueAsInt_02184c30(&params[0]);
    SetBrightness(resources, brightness, GetTaggedValueAsInt_02184c30(&params[1]) / 34);
    return 1;
}
