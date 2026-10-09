#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "System/Graphics.h"
#include "System/VRAM.h"

struct Background021626e4 {
    char unk_0[0x1c];
    unsigned char screen : 4;
    unsigned char layer : 4;
    char unk_1d[3];
};

extern "C" int func_ov017_021d612c(void* args);
extern "C" int func_ov017_021d60f4(void* args);
extern "C" unsigned int _Z37LoadResourceIntoGlobalBuffer_0215a750PKcPPv(const char* path, void** outPtr);
extern "C" int _Z18CountActiveEntriesP19ActiveEntry02046900(void* archive);
extern "C" void* _Z17FindRecordByIndexP11Rec020467f0iPPvPi(void* archive, int index, void** name, int* size);
extern "C" void _Z28SetBg3ControlFields_02162678iiii(int a, int b, int c, int d);
void SetSubBgMode(unsigned int mode);
extern "C" void _Z31SetSubBg3ControlFields_021628d4iiii(int a, int b, int c, int d);
extern "C" void _Z17ResetList0204af64P12List0204af64(Background021626e4* background);
extern "C" void func_0204b5b4(Background021626e4* background, int a);
extern "C" void _Z24SetWord0x18ClearByte0x1fPhi(Background021626e4* background, int a);
extern "C" void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(Background021626e4* background, int a, int b);
void DelayThenSyncBit0();
extern "C" void _Z21DispatchByTag0204b2e0PvPc(Background021626e4* background, void* record);
extern "C" void _Z27DispatchByTagLookup0204b3a0P15SelfTag0204b3a0Pc(Background021626e4* background, void* record);
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(Background021626e4* background, void* a);
extern "C" void _Z23ResetRecordList0204afb4P12List0204afb4(Background021626e4* background);

extern char data_ov001_02165745[];

// USA: func_ov001_021626e4
extern "C" ARM int func_ov001_021626e4(void* args) {
    char path[0x50];
    void* records[3];
    int recordSizes[3];
    Background021626e4 background;
    void* file;
    unsigned int fileSize;
    void* name;
    BackgroundLoader* loader;
    int fileId;
    int locked;
    int count;
    int subScreen;

    loader = BackgroundLoader::GetInstance();
    fileId = func_ov017_021d612c(args);
    subScreen = func_ov017_021d60f4((char*)args + 8);
    sprintf(path, data_ov001_02165745, fileId);

    locked = 0;
    file = NULL;
    fileSize = 0;
    loader->GetLoadedFileByName(path, &file, &fileSize);
    if (file == NULL) {
        BackgroundLoader::AddLockGlobal();
        locked = 1;
        if (_Z37LoadResourceIntoGlobalBuffer_0215a750PKcPPv(path, &file) == 0) {
            BackgroundLoader::RemoveLockGlobal();
            return 0;
        }
    }

    count = _Z18CountActiveEntriesP19ActiveEntry02046900(file);
    for (int i = 0; i < count; i++) {
        records[i] = _Z17FindRecordByIndexP11Rec020467f0iPPvPi(file, i, &name, &recordSizes[i]);
    }

    DISPCNT = (DISPCNT & ~0x1f00) | 0x800;
    if (subScreen == 0) {
        _Z28SetBg3ControlFields_02162678iiii(0, 0, 1, 1);
    } else {
        DisableSubBGVRAMBanks();
        SetSubBgMode(0);
        MapVRAMBanksToSubBG(VRAM_BANK_H);
        _Z31SetSubBg3ControlFields_021628d4iiii(0, 0, 0xe, 0);
    }

    _Z17ResetList0204af64P12List0204af64(&background);
    background.screen = subScreen;
    background.layer = 3;
    func_0204b5b4(&background, 0);
    _Z24SetWord0x18ClearByte0x1fPhi(&background, 0);
    _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(&background, 0, 0);
    DelayThenSyncBit0();
    for (int i = 0; i < count; i++) {
        _Z21DispatchByTag0204b2e0PvPc(&background, records[i]);
        _Z27DispatchByTagLookup0204b3a0P15SelfTag0204b3a0Pc(&background, records[i]);
    }
    _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(&background, NULL);
    _Z23ResetRecordList0204afb4P12List0204afb4(&background);

    if (locked) {
        BackgroundLoader::RemoveLockGlobal();
    }
    return 1;
}
