#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct Blob020a9ba4 {
    unsigned char first[0x200];
    unsigned char second[0x200];
    int trailer;
};

#if defined(jpn)
#define CopyBlobIntoBattleStruct020a9ba4 func_020ab7f4
extern "C" ARM int func_020ab7f4(void* src);
enum { kSecondOffset = 0x5f20, kFirstOffset = 0x5d20, kTrailerOffset = 0x5d1c };
#else
enum { kSecondOffset = 0x6180, kFirstOffset = 0x5f80, kTrailerOffset = 0x5f7c };
#endif

// USA: func_020a9ba4
ARM int CopyBlobIntoBattleStruct020a9ba4(void* src) {
    struct Blob020a9ba4 buf;
    GameState* bs = GameState::GetInstance();
    memcpy(&buf, src, sizeof(buf));
    memcpy((char*)bs + kSecondOffset, buf.second, 0x200);
    memcpy((char*)bs + kFirstOffset, buf.first, 0x200);
    *(int*)((char*)bs + kTrailerOffset) = buf.trailer;
    return 1;
}
