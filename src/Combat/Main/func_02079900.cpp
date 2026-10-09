#include <globaldefs.h>
extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
#include "Filesystem/GPC.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
struct Struct0200fb08;
extern "C" int _Z24NormalizeField5_0200fb08P14Struct0200fb08(Struct0200fb08*);
extern "C" void _Z24ResetObjectState02079a3cPv(void*);
extern "C" void __clear(void*, unsigned int);
struct Obj02079808;
extern "C" void func_02079a58(void*, int, void*, int (*)(void*, Obj02079808*), int, int);
extern "C" void func_02079bac(void*, int, void*, int, int, int);
extern "C" int _Z23RelocateOffsets02079808PvP11Obj02079808(void*, Obj02079808*);
extern char data_020f0dcc[], data_020f0de1[], data_020f0df2[];
struct Object02079900 { unsigned char field_0[0x18]; unsigned char field_18[0x18]; };
// USA: func_02079900
extern "C" ARM void func_02079900(Object02079900* obj, int arg) {
    BackgroundLoader::AddLockGlobal();
    GPCReadPair pair;
    unsigned int offset = 0;
    unsigned char* buffer = data_0211e33c;
    int capacity = 0x30000;
    _Z24ResetObjectState02079a3cPv(&pair);
    unsigned int length;
    if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine, data_020f0dcc, buffer, length, capacity, false, 0)) {
        offset = length;
        unsigned int decompressed = 0;
        capacity -= offset;
        GameState* game = GameState::GetInstance();
        char filename[0x20];
        __clear(filename, 0x20);
        StringReplaceLanguageTag(data_020f0de1, filename, _Z24NormalizeField5_0200fb08P14Struct0200fb08((Struct0200fb08*)game));
        DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buffer + offset, decompressed, capacity, filename);
        func_02079a58(obj, arg, buffer + offset, _Z23RelocateOffsets02079808PvP11Obj02079808, 0, 0);
        DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buffer + offset, decompressed, capacity, data_020f0df2);
        func_02079bac(obj->field_18, arg, buffer + offset, 0, 0, 0);
    }
    BackgroundLoader::RemoveLockGlobal();
    pair.Reset();
    ZeroDestroyGPCPointer(&pair.pGPCFile);
}
