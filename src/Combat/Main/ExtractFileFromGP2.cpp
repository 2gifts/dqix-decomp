#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/GPC.h"
#include "GameState/GameState.h"
extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
#include "Filesystem/FileIO.h"

struct Struct0200fb08;
struct FlagWord02046708;
extern "C" int _Z24NormalizeField5_0200fb08P14Struct0200fb08(Struct0200fb08*);
extern "C" FlagWord02046708* _Z27GetDataPtr02114e04_020d6c00v();
extern "C" int _Z17TestFlags02046708P16FlagWord02046708j(FlagWord02046708*, unsigned int);
extern "C" void __clear(void*, unsigned int);

struct ScopedGPCReader : GPCReadPair {
    ScopedGPCReader() {
        GPCReadPair* pair = this;
        ZeroInitGPCPointer(&pair->pGPCFile);
        pair->ZeroInitializeMachine();
    }
};

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_0207568c
extern "C" ARM void* ExtractFileFromGP2(const char* archive, const char* filename, unsigned int* length) {
    if (length != NULL) *length = 0;
    BackgroundLoader::FreeAllocationsGlobal();
    GameState* state = GameState::GetInstance();
    char localized[0x80];
    __clear(localized, sizeof(localized));
    StringReplaceLanguageTag(filename, localized, _Z24NormalizeField5_0200fb08P14Struct0200fb08((Struct0200fb08*)state));
    void* result;
    unsigned int offset;
    unsigned int headerLength = 0;
    unsigned char* buffer = data_0211e33c;
    unsigned int capacity = 0x30000;
    if (_Z17TestFlags02046708P16FlagWord02046708j(_Z27GetDataPtr02114e04_020d6c00v(), 0x02000000)) capacity -= 0x8000;
    ScopedGPCReader pair;
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine, archive, buffer, headerLength, capacity, false, NULL)) {
        offset = headerLength;
        unsigned int decompressed = 0;
        DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buffer + offset, decompressed, capacity - offset, localized);
        *length = decompressed;
        pair.Reset();
        ZeroDestroyGPCPointer(&pair.pGPCFile);
        return buffer + offset;
    } else {
        result = NULL;
        pair.Reset();
        ZeroDestroyGPCPointer(&pair.pGPCFile);
    }
    return result;
}
