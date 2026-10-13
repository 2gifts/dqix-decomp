#include <globaldefs.h>

#include "Combat/BufferedScriptResult.h"

struct Out021b8abc {
    short vals[3];
    unsigned char pad[2];
    unsigned char bytes[3];
};

// USA: func_ov017_021b8abc
ARM int DecodeEntry_021b8abc(int id, Out021b8abc* out) {
    BufferedScriptResult buf;
    if (id <= -1) {
        goto fail;
    }
    if (!TryDecodeGlobalBitstreamEntry(&buf, id)) {
        goto fail;
    }
    for (int i = 0; i < 3; i++) {
        out->vals[i] = buf.values[i];
        out->bytes[i] = (unsigned char)buf.attributes[i];
    }
    return 1;
fail:
    return 0;
}
