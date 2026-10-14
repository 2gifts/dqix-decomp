#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"
#include "System/Graphics.h"
#include "System/VRAM.h"

extern "C" int func_ov017_021d612c(void* obj);
extern char data_ov001_02165745[];

unsigned int LoadResourceIntoGlobalBuffer_0215a750(const char* path, void** outPtr);
void SetBg3ControlFields_02162678(int a, int b, int c, int d);

struct ActiveEntry02046900;
int CountActiveEntries(struct ActiveEntry02046900* entry);

struct Rec020467f0;
void* FindRecordByIndex(struct Rec020467f0* rec, int index, void** out, int* out44);

struct List0204af64;
void ResetList0204af64(struct List0204af64* obj);

void SetWord0x18ClearByte0x1f_0204b11c(unsigned char* obj, int value);

extern "C" void func_0204b5b4(void*, int);

struct Obj0204b5e8;
int DispatchViaTable0204b5e8(struct Obj0204b5e8* obj, int a, int b);

void DelayThenSyncBit0_020c9820();

void DispatchByTag0204b2e0(void* obj, char* str);

struct SelfTag0204b3a0;
void DispatchByTagLookup0204b3a0(struct SelfTag0204b3a0* self, char* str);

struct List0204b0e8;
void FlushAndDispatchList0204b0e8(struct List0204b0e8* obj, void* buf);

struct List0204afb4;
void ResetRecordList0204afb4(struct List0204afb4* obj);

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
        if (LoadResourceIntoGlobalBuffer_0215a750(path, &fileData) == 0) {
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
    SetBg3ControlFields_02162678(0, 1, 1, 1);
    ResetList0204af64((struct List0204af64*)&s);
    s.lo = 0;
    s.hi = 3;
    func_0204b5b4(&s, 0);
    SetWord0x18ClearByte0x1f_0204b11c((unsigned char*)&s, 0);
    DispatchViaTable0204b5e8((struct Obj0204b5e8*)&s, 0, 0);
    DelayThenSyncBit0_020c9820();
    for (int i = 0; i < count; i++) {
        char* record = records[i];
        DispatchByTag0204b2e0(&s, record);
        DispatchByTagLookup0204b3a0((struct SelfTag0204b3a0*)&s, record);
    }
    if (locked) {
        BackgroundLoader::RemoveLockGlobal();
    }
    FlushAndDispatchList0204b0e8((struct List0204b0e8*)&s, 0);
    ResetRecordList0204afb4((struct List0204afb4*)&s);
    return 1;
}
