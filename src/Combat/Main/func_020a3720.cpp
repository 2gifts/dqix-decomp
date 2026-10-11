#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Filesystem/FileIO.h"
#include "System/Memory.h"
#include "std_library_functions.h"

extern "C" void func_020a395c(void);
#if defined(jpn)
extern "C" int func_020a5444(void**, unsigned int);
#define AllocateIndexedSlot020a36cc func_020a5444
#else
int AllocateIndexedSlot020a36cc(void** out, unsigned int idx);
#endif
extern "C" void func_020c9be0(void);

#if defined(jpn)
extern const char data_020f1bf4[];
#endif
extern const char data_020f1a9c[];
extern const char data_020f1ab0[];

// USA: func_020a3720  (semantic: AllocateAndReloadTreasureMapLanguageBuffers_020a3720)
extern "C" ARM int func_020a3720(void) {
    GameState* battleStruct = GameState::GetInstance();
    int base = ((int)func_ov017_0218b5b0());
    unsigned char* buf = battleStruct->GetTreasureMapLanguageData();
    if (buf != 0 || *(void**)(base + 0x4000 + (
#if defined(jpn)
0x1dc
#else
0x48c
#endif
)) != 0) {
        func_020a395c();
    }

    if (!AllocateIndexedSlot020a36cc((void**)&buf, 0x2000)) return 0;
    if (!AllocateIndexedSlot020a36cc((void**)(base + 0x4000 + (
#if defined(jpn)
0x1dc
#else
0x48c
#endif
)), 0x44)) return 0;

    unsigned int fileSize = 0;
#if defined(jpn)
    if (!LoadFileIntoMemory(data_020f1bf4, buf, &fileSize)) return 0;
#else
    BackgroundLoader::AddLockGlobal();
    void* extracted = ExtractFileFromGP2(data_020f1a9c, data_020f1ab0, &fileSize);
    memcpy(buf, extracted, fileSize);
    if (fileSize > 0x2000) {
        func_020c9be0();
    }

#endif
    unsigned int srcOff = 0;
    unsigned int count = 0;
    VectorizedInvertedMemcpy(buf, &count, 4);
    srcOff += 4;
    unsigned int i = 0;
    while (i < count) {
        VectorizedInvertedMemcpy(buf + srcOff, *(unsigned char**)((unsigned char*)base + 0x4000 + (
#if defined(jpn)
0x1dc
#else
0x48c
#endif
)) + i * 4, 4);
        srcOff += 4;
        ++i;
    }

#if !defined(jpn)
    BackgroundLoader::RemoveLockGlobal();
#endif
    battleStruct->SetTreasureMapLanguageDataPtr(buf);
    return 1;
}
