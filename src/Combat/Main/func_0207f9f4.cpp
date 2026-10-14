#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct StreamHeader;
struct List020727d8;
struct ActiveEntry02046900;

void ResetListHeader020727d8(List020727d8* list);
extern "C" void func_020728ac(void* list, void* alloc, void* buffer, int length, int a, int b, int c);
int CountActiveEntries(ActiveEntry02046900*);
struct Rec020467f0;
void* FindRecordByIndex(Rec020467f0*, int, void**, int*);
char* GetGlobalField0x1c020421a0();
void InitStreamAndRun0207f524(void* a, void* b, StreamHeader* c, int d);
struct EntryArray0207efdc;
void LoadEntryArrayFromStream0207ef74(EntryArray0207efdc*, SafeAllocator*, StreamHeader*, int);

struct Menu0207f9f4 {
    void* field0;
    char sub4[8];
    char arrC[8];
    SafeAllocator* field14;
    int field18;
    int field1c;
#ifndef jpn
    int field20[3];
#endif
};

// USA: func_0207f9f4
extern "C" ARM int func_0207f9f4(Menu0207f9f4* self) {
    if (self->field1c < 0) {
#ifdef jpn
        return -1;
#else
        int* ids = self->field20;
        if (ids[0] < 0) {
            if (ids[1] < 0) {
                if (ids[2] < 0) {
                    return -1;
                }
            }
        }

        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        int allDone = 1;
        for (int i = 0; i < 3; i++) {
            if (loader->GetTaskStatus(ids[i]) == 0) {
                allDone = 0;
            }
        }

        if (allDone != 0) {
            void* file;
            unsigned int size;
            loader->GetLoadedFileByID(ids[0], &file, &size);
            self->field0 = self->field14->Allocate(8);
            ResetListHeader020727d8((List020727d8*)self->field0);
            if (file != 0) {
                func_020728ac(self->field0, self->field14, file, size, 0, 0, 0);
            }
            loader->GetLoadedFileByID(ids[1], &file, &size);
            if (file != 0) {
                InitStreamAndRun0207f524(self->sub4, self->field14, (StreamHeader*)file, size);
            }
            loader->GetLoadedFileByID(ids[2], &file, &size);
            if (file != 0) {
                LoadEntryArrayFromStream0207ef74((EntryArray0207efdc*)self->arrC, (SafeAllocator*)self->field14, (StreamHeader*)file, size);
            }

            for (int j = 0; j < 3; j++) {
                loader->RemoveTask(*ids);
                *ids = -1;
                ids++;
            }
    #ifdef jpn
        self->field18 = *(int*)(GetGlobalField0x1c020421a0() + 0x28);
#else
        self->field18 = *(int*)(GetGlobalField0x1c020421a0() + 0x5c);
#endif
            return 0;
        }
        return 1;
#endif
    }

    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (loader->GetTaskStatus(self->field1c) != 0) {
        void* out;
        void* file;
        unsigned int size;
        loader->GetLoadedFileByID(self->field1c, &file, &size);
        int n = CountActiveEntries((ActiveEntry02046900*)file);
        void* recs[3];
        int outs[3];
        for (int i = 0; i < n; i++) {
            recs[i] = FindRecordByIndex((Rec020467f0*)file, i, &out, &outs[i]);
        }
        self->field0 = self->field14->Allocate(8);
        ResetListHeader020727d8((List020727d8*)self->field0);
        func_020728ac(self->field0, self->field14, recs[0], outs[0], 0, 0, 0);
        InitStreamAndRun0207f524(self->sub4, self->field14, (StreamHeader*)recs[1], outs[1]);
        LoadEntryArrayFromStream0207ef74((EntryArray0207efdc*)self->arrC, (SafeAllocator*)self->field14, (StreamHeader*)recs[2], outs[2]);
        loader->RemoveTask(self->field1c);
        self->field1c = -1;
#ifdef jpn
        self->field18 = *(int*)(GetGlobalField0x1c020421a0() + 0x28);
#else
        self->field18 = *(int*)(GetGlobalField0x1c020421a0() + 0x5c);
#endif
        return 0;
    }
    return 1;
}
