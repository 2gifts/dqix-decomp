#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" int func_02075910(int a0, void* out, int a1, int a2);
extern "C" int func_01ff85b8(void* buf, int size);

struct SaveHeaderPayload {
    unsigned char metadata[4];
    char version[12];
};
struct Buf020a94f8 {
    int checksum;
    SaveHeaderPayload payload;
};
struct SaveErrorState {
#if defined(jpn)
    unsigned char unknown0[0x5a68];
#else
    unsigned char unknown0[0x5cc8];
#endif
    unsigned char status;
};
extern char data_020f1be8;

// USA: func_020a94f8
ARM int VerifyBuffer020a94f8(struct Buf020a94f8* header, int alternateBank) {
    int offset = alternateBank ? 0x8010 : 0x10;
    if (!func_02075910(offset, header, sizeof(*header), 0)) {
        return 0;
    }
    SaveErrorState* save = reinterpret_cast<SaveErrorState*>(GameState::GetInstance());
    if (strcmp(header->payload.version, &data_020f1be8) == 0) {
        save->status = alternateBank ? 3 : 2;
        return 0;
    }
    if (func_01ff85b8(&header->payload, sizeof(header->payload)) != header->checksum) {
        save->status = alternateBank ? 3 : 2;
        return 0;
    }
    return 1;
}
