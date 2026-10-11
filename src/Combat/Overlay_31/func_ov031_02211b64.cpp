#include <globaldefs.h>

struct Header02211b28;
struct GlobalStruct0224e5ac {
    void* field0;
    void* field4;
};

extern GlobalStruct0224e5ac data_ov031_0224e5ac;
void* InitHeaderMagic_02211b28(Header02211b28*, int);
typedef Header02211b28* (*AllocateCallback_02211b64)(void*, int, int);

// USA: func_ov031_02211b64
extern "C" ARM void* func_ov031_02211b64(void* tag, void* size, int alignment) {
    AllocateCallback_02211b64 allocate = (AllocateCallback_02211b64)data_ov031_0224e5ac.field4;
    Header02211b28* header = allocate(tag, (int)size + 0x20, alignment);
    if (header == NULL) return NULL;
    return InitHeaderMagic_02211b28(header, (int)size);
}
