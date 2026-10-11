#include <globaldefs.h>

#include "Resource/GameResources.h"

struct FlagPair_0218b5b0 {
    int a;
    int b;
};
extern FlagPair_0218b5b0 data_ov017_021d82e0;

// USA: func_ov017_0218b5b0
extern "C" ARM GameResources *func_ov017_0218b5b0(void) {
    return reinterpret_cast<GameResources *>(data_ov017_021d82e0.b);
}
