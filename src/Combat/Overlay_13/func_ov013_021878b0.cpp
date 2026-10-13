#include <globaldefs.h>

#if defined(jpn)
#define func_ov013_021878b0 func_ov013_021888c0
#define func_ov013_02187a58 func_ov013_02188a24
#define data_ov013_02187eaf data_ov013_02188e11
#endif
#include "Filesystem/BackgroundLoader.h"



struct List0202fec8;
struct ActiveEntry02046900;
int CountActiveEntries(struct ActiveEntry02046900* entry);
struct Rec020467f0;
void* FindRecordByIndex(struct Rec020467f0* rec, int index, void** out, int* out44);

extern "C" void func_0204c684(void* obj);
extern "C" void func_ov013_02187a58(void* obj, void* buf);
extern "C" void func_0204b174(void* list, void* payload, int a3, int a4);

struct EntryList0204af14;
void* GetEntryByIndexStride0x10(struct EntryList0204af14* list, unsigned int index);
struct Tilemap0204ae44;
void FillTilemapPalette0204ae44(struct Tilemap0204ae44* obj, int palette);
struct Obj0204b988;
#if defined(jpn)
#define DispatchIndexedEntry0204b988 func_0204c7a8
extern "C" void DispatchIndexedEntry0204b988(struct Obj0204b988* obj, unsigned int index, int a3, int a4, unsigned short a5);
#else
void DispatchIndexedEntry0204b988(struct Obj0204b988* obj, unsigned int index, int a3, int a4, unsigned short a5);
#endif
struct List0204b0e8;
void FlushAndDispatchList0204b0e8(struct List0204b0e8* obj, void* buf);

extern const char data_ov013_02187eaf[];

struct SkillDetailWindow {
    char unknown0[0x28];
#if defined(jpn)
    char entryList[0x20];
#else
    char entryList[0x28];
    short* iconX;
    short* iconY;
    unsigned char* iconPalettes;
#endif
    int loadTask;
    char unknownAfterTask[6];
    unsigned char loadState;
    signed char partyIndex;
    unsigned char skillIndex;
    unsigned char flags;
#if !defined(jpn)
    signed char iconType;
#endif
};

struct LocalBuf021878b0 {
    char pad0[0x8];
    void* field8;
    char pad10[0xa8 - 0xc];
    unsigned short halfA8;
    unsigned short halfAA;
    char padAC[0xb4 - 0xac];
    unsigned short halfB4;
    unsigned short halfB6;
    char padB8[0xe0 - 0xb8];
};

// USA: func_ov013_021878b0  (semantic: HandleQueuedListEntry021878b0)
extern "C" ARM void func_ov013_021878b0(SkillDetailWindow* window) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    unsigned char loadState = window->loadState;

    if (loadState == 0) {
#if !defined(jpn)
        for (int i = 0; i < 10; i++) {
            window->iconX[i] = -1;
            window->iconY[i] = -1;
            window->iconPalettes[i] = 2;
        }
        window->iconType = -1;
#endif
        loader->MaybeFreeAllocations();
        window->loadTask = loader->QueueLoadFile(data_ov013_02187eaf, NULL);
        window->loadState++;
    } else if (loadState == 1) {
        if (loader->GetTaskStatus(window->loadTask) != 0) {
            void* recOut;
            void* file;
            unsigned int fileSize;
            int field44;
            loader->GetLoadedFileByID(window->loadTask, &file, &fileSize);
            CountActiveEntries((struct ActiveEntry02046900*)file);
            void* end = FindRecordByIndex((struct Rec020467f0*)file, 0, &recOut, &field44);
            if (end != 0) {
                LocalBuf021878b0 buf;
                func_0204c684(&buf);
                buf.field8 = (char*)end + 0x10;
                buf.halfB4 = 0xa;
                buf.halfB6 = 0xb;
                buf.halfA8 = 0x20;
                buf.halfAA = 0x18;
                func_ov013_02187a58(window, &buf);
                func_0204b174(window->entryList, end, 0, field44);
            }
            loader->RemoveTask(window->loadTask);
            window->loadTask = -1;
            void* e = GetEntryByIndexStride0x10((struct EntryList0204af14*)window->entryList, 0);
            if (e != 0) {
                FillTilemapPalette0204ae44((struct Tilemap0204ae44*)e, window->partyIndex);
            }
            DispatchIndexedEntry0204b988((struct Obj0204b988*)window->entryList, 0, 0, 0, 0xffff);
            FlushAndDispatchList0204b0e8((struct List0204b0e8*)window->entryList, 0);
            window->loadState = 0;
            window->flags &= ~1;
        }
    }
}
