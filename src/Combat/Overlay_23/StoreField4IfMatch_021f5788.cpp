#include <globaldefs.h>

#if defined(jpn)
#define StoreField4IfMatch_021f5788 func_ov023_021f4d60
#endif
#include "GameState/GameState.h"

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
struct Struct0200fb08;
unsigned char NormalizeField5_0200fb08(struct Struct0200fb08* obj);
struct Struct02030b7c;
extern "C" void* _ZNK6Script9Parameter8ToStringEv(struct Struct02030b7c* s);

struct Global021fff08 { char pad[0x10]; void* field10; };
extern struct Global021fff08 data_ov023_021fff08;

// USA: func_ov023_021f5788
#if defined(jpn)
extern "C"
#endif
ARM int StoreField4IfMatch_021f5788(void* obj) {
#if defined(jpn)
    data_ov023_021fff08.field10 = _ZNK6Script9Parameter8ToStringEv((struct Struct02030b7c*)obj);
#else
    int a = _ZNK6Script9Parameter5ToIntEv((struct Variant02030b0c*)obj);
    int b = NormalizeField5_0200fb08((struct Struct0200fb08*)GameState::GetInstance());
    if (a == b) {
        data_ov023_021fff08.field10 = _ZNK6Script9Parameter8ToStringEv((struct Struct02030b7c*)((char*)obj + 0x8));
    }
#endif
    return 1;
}
