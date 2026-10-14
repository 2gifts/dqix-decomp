#include <globaldefs.h>
#include "Filesystem/GPC.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"
#include "Resource/ActionDataTables.h"

extern "C" {
    void __clear(void*, unsigned int);
    extern "C" int _Z24NormalizeField5_0200fb08P14Struct0200fb08(GameState*);
}

struct Obj02079808;
extern "C" void* _Z24ResetObjectState02079a3cPv(void* obj);

extern unsigned char data_0211e33c[0x30000];
extern const char data_020f0e02[];
extern const char data_020f0e17[];
extern const char data_020f0e28[];

#if !defined(jpn)
// USA: func_02079cf8
#pragma opt_propagation off
extern "C" ARM void func_02079cf8(ActionDataTables* obj, SafeAllocator* a1, SafeAllocator* a2) {
    unsigned int len;
    unsigned char* base;
    base = data_0211e33c;
    unsigned int capacity = sizeof(data_0211e33c);
    GPCReadPair pair;
    _Z24ResetObjectState02079a3cPv(&pair);

    unsigned int sizeOut;

    const char* name = data_020f0e02;
    bool ok = LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine,
        name, base, sizeOut, capacity, false, NULL);
    if (ok) {
        unsigned int outSize2 = 0;
        len = sizeOut;
        capacity -= len;
        GameState* battle = GameState::GetInstance();
        char buf[0x20];
        __clear(buf, sizeof(buf));

        int language = _Z24NormalizeField5_0200fb08P14Struct0200fb08(battle);
        StringReplaceLanguageTag(data_020f0e17, buf, language);

        DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, base + len,
            outSize2, capacity, buf);

        func_02079a58(&obj->alternateActions, a1, base + len,
            RelocateOffsets02079808, 0, a2);

        DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, base + len,
            outSize2, capacity, data_020f0e28);

        func_02079bac(&obj->alternateDamage, a1, base + len, NULL, 0, 0);
    }

    pair.Reset();
    ZeroDestroyGPCPointer(&pair.pGPCFile);
}

#endif
