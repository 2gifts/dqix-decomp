#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct StreamHeader;
struct List020727d8;
struct ActiveEntry02046900;

extern "C" void _Z23ResetListHeader020727d8P12List020727d8(List020727d8* list);
extern "C" void func_020728ac(void* list, void* alloc, void* buffer, int length, int a, int b, int c);
extern "C" int _Z18CountActiveEntriesP19ActiveEntry02046900(void* entry);
extern "C" void* _Z17FindRecordByIndexP11Rec020467f0iPPvPi(void* rec, int index, void** out, int* outSize);
extern "C" char* _Z26GetGlobalField0x1c020421a0v();
extern "C" void _Z24InitStreamAndRun0207f524PvS_P12StreamHeaderi(void* a, void* b, StreamHeader* c, int d);
extern "C" void _Z32LoadEntryArrayFromStream0207ef74P18EntryArray0207efdcP13SafeAllocatorP12StreamHeaderi(
    void* a, void* b, StreamHeader* c, int d);

struct Menu0207f9f4 {
    void* field0;
    char sub4[8];
    char arrC[8];
    SafeAllocator* field14;
    int field18;
    int field1c;
    int field20[3];
};

// USA: func_0207f9f4
extern "C" ARM int func_0207f9f4(Menu0207f9f4* self) {
    if (self->field1c < 0) {
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
            _Z23ResetListHeader020727d8P12List020727d8((List020727d8*)self->field0);
            if (file != 0) {
                func_020728ac(self->field0, self->field14, file, size, 0, 0, 0);
            }
            loader->GetLoadedFileByID(ids[1], &file, &size);
            if (file != 0) {
                _Z24InitStreamAndRun0207f524PvS_P12StreamHeaderi(self->sub4, self->field14, (StreamHeader*)file, size);
            }
            loader->GetLoadedFileByID(ids[2], &file, &size);
            if (file != 0) {
                _Z32LoadEntryArrayFromStream0207ef74P18EntryArray0207efdcP13SafeAllocatorP12StreamHeaderi(
                    self->arrC, self->field14, (StreamHeader*)file, size);
            }

            for (int j = 0; j < 3; j++) {
                loader->RemoveTask(*ids);
                *ids = -1;
                ids++;
            }
            self->field18 = *(int*)(_Z26GetGlobalField0x1c020421a0v() + 0x5c);
            return 0;
        }
        return 1;
    }

    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (loader->GetTaskStatus(self->field1c) != 0) {
        void* out;
        void* file;
        unsigned int size;
        loader->GetLoadedFileByID(self->field1c, &file, &size);
        int n = _Z18CountActiveEntriesP19ActiveEntry02046900(file);
        void* recs[3];
        int outs[3];
        for (int i = 0; i < n; i++) {
            recs[i] = _Z17FindRecordByIndexP11Rec020467f0iPPvPi(file, i, &out, &outs[i]);
        }
        self->field0 = self->field14->Allocate(8);
        _Z23ResetListHeader020727d8P12List020727d8((List020727d8*)self->field0);
        func_020728ac(self->field0, self->field14, recs[0], outs[0], 0, 0, 0);
        _Z24InitStreamAndRun0207f524PvS_P12StreamHeaderi(self->sub4, self->field14, (StreamHeader*)recs[1], outs[1]);
        _Z32LoadEntryArrayFromStream0207ef74P18EntryArray0207efdcP13SafeAllocatorP12StreamHeaderi(
            self->arrC, self->field14, (StreamHeader*)recs[2], outs[2]);
        loader->RemoveTask(self->field1c);
        self->field1c = -1;
        self->field18 = *(int*)(_Z26GetGlobalField0x1c020421a0v() + 0x5c);
        return 0;
    }
    return 1;
}