#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct TaggedNumber02184c30;
extern int GetTaggedValueAsInt_02184c30(struct TaggedNumber02184c30* v);

extern "C" void* func_ov017_021b2164(void);
extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" void* func_ov023_021f6880(void* list, int value);
extern "C" unsigned int func_ov023_021f6f10(void* obj);
extern "C" void _Z23SetByteField39_021fb284P6S_b284h(void* a, int v);

// USA: func_ov011_02187da8  (semantic: SetByteField39IfNodeTypeIsOne_02187da8)
extern "C" ARM int func_ov011_02187da8(struct TaggedNumber02184c30* tagged) {
    int key = GetTaggedValueAsInt_02184c30(tagged);
    int val = GetTaggedValueAsInt_02184c30((struct TaggedNumber02184c30*)((char*)tagged + 8));
    void* node = func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()), key);
    if (!node) return 0;
    if (func_ov023_021f6f10(node) != 1) return 0;
    _Z23SetByteField39_021fb284P6S_b284h(node, (char)val);
    return 1;
}
