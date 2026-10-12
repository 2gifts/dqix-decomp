#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern const char data_ov014_021896bc[];

struct Trans_02185c48State {
    char pad_00[0x70];
    int loadId;
    char pad_74[0x7e - 0x74];
    unsigned char loadCount;
    char pad_7f[0x81 - 0x7f];
    unsigned char flags;
};

// USA: func_ov014_02185c48  (semantic: Trans_02185c48)
extern "C" ARM void func_ov014_02185c48(Trans_02185c48State* self) {
    if (self->flags & 0x10) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (self->loadCount == 0) {
            self->loadId = loader->QueueLoadFile(data_ov014_021896bc, NULL);
            self->loadCount++;
        }
    }
}
