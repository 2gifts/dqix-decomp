#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"
#include "System/Graphics.h"
#include "System/VRAM.h"

extern "C" int func_ov017_021d612c(void* obj);
extern char data_ov001_02165745[];

extern "C" unsigned int _Z37LoadResourceIntoGlobalBuffer_0215a750PKcPPv(const char* path, void** outPtr);
extern "C" void _Z28SetBg3ControlFields_02162678iiii(int a, int b, int c, int d);

struct ActiveEntry02046900;
int CountActiveEntries(struct ActiveEntry02046900* entry);

struct Rec020467f0;
void* FindRecordByIndex(struct Rec020467f0* rec, int index, void** out, int* out44);

struct List0204af64;
extern "C" void _Z17ResetList0204af64P12List0204af64(struct List0204af64* obj);

void SetWord0x18ClearByte0x1f(unsigned char* obj, int value);

extern "C" void func_0204b5b4(void*, int);

struct Obj0204b5e8;
extern "C" int _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(struct Obj0204b5e8* obj, int a, int b);

void DelayThenSyncBit0();

extern "C" void _Z21DispatchByTag0204b2e0PvPc(void* obj, char* str);

struct SelfTag0204b3a0;
extern "C" void _Z27DispatchByTagLookup0204b3a0P15SelfTag0204b3a0Pc(struct SelfTag0204b3a0* self, char* str);

struct List0204b0e8;
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(struct List0204b0e8* obj, void* buf);

struct List0204afb4;
extern "C" void _Z23ResetRecordList0204afb4P12List0204afb4(struct List0204afb4* obj);

struct LocalListStruct021624cc {
    unsigned char pad0[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char pad1d[3];
};

// USA: func_ov001_021624cc
extern "C" ARM int func_ov001_021624cc(void* self) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    char* records[3];
    int sizes[3];
    LocalListStruct021624cc s;
    void* fileData;
    unsigned int size;
    void* dummyPtr;
    char path[0x50];

    sprintf(path, data_ov001_02165745, func_ov017_021d612c(self));
    int locked = 0;
    fileData = NULL;
    size = 0;
    loader->GetLoadedFileByName(path, &fileData, &size);
    if (fileData == NULL) {
        BackgroundLoader::AddLockGlobal();
        locked = 1;
        if (_Z37LoadResourceIntoGlobalBuffer_0215a750PKcPPv(path, &fileData) == 0) {
            BackgroundLoader::RemoveLockGlobal();
            return 0;
        }
    }
    int count = CountActiveEntries((struct ActiveEntry02046900*)fileData);
    for (int i = 0; i < count; i++) {
        records[i] = (char*)FindRecordByIndex((struct Rec020467f0*)fileData, i, &dummyPtr, &sizes[i]);
    }
    ReleaseMainBGVRAMBanks();
    MapVRAMBanksToMainBG(0x10);
    DISPCNT = (DISPCNT & ~0x1f00) | 0x800;
    _Z28SetBg3ControlFields_02162678iiii(0, 1, 1, 1);
    _Z17ResetList0204af64P12List0204af64((struct List0204af64*)&s);
    s.lo = 0;
    s.hi = 3;
    func_0204b5b4(&s, 0);
    SetWord0x18ClearByte0x1f((unsigned char*)&s, 0);
    _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii((struct Obj0204b5e8*)&s, 0, 0);
    DelayThenSyncBit0();
    for (int i = 0; i < count; i++) {
        char* record = records[i];
        _Z21DispatchByTag0204b2e0PvPc(&s, record);
        _Z27DispatchByTagLookup0204b3a0P15SelfTag0204b3a0Pc((struct SelfTag0204b3a0*)&s, record);
    }
    if (locked) {
        BackgroundLoader::RemoveLockGlobal();
    }
    _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv((struct List0204b0e8*)&s, 0);
    _Z23ResetRecordList0204afb4P12List0204afb4((struct List0204afb4*)&s);
    return 1;
}
