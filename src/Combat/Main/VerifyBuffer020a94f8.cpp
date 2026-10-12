#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

extern "C" int func_02075910(int a0, void* out, int a1, int a2);
extern "C" int func_01ff85b8(void* buf, int size);

struct Buf020a94f8 { int hdr; char pad[4]; char str[12]; };
extern char data_020f1be8;

// USA: func_020a94f8
ARM int VerifyBuffer020a94f8(struct Buf020a94f8* buf, int flag) {
#if defined(jpn)
    enum { errorOffset = 0xa68 };
#else
    enum { errorOffset = 0xcc8 };
#endif
    int id = flag ? 0x8010 : 0x10;
    if (!func_02075910(id, buf, 0x14, 0)) {
        return 0;
    }
    GameState* bs = GameState::GetInstance();
    if (strcmp(buf->str, &data_020f1be8) == 0) {
        ((unsigned char*)bs + 0x5000)[errorOffset] = flag ? 3 : 2;
        return 0;
    }
    if (func_01ff85b8((char*)buf + 4, 0x10) != buf->hdr) {
        ((unsigned char*)bs + 0x5000)[errorOffset] = flag ? 3 : 2;
        return 0;
    }
    return 1;
}
