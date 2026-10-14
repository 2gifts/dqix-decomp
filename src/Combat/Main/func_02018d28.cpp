#include <globaldefs.h>
#include "Graphics/Model3D.h"
#include "Memory/SafeAllocator.h"
#include "World/Zone3D.h"
#include "Filesystem/FileIO.h"

#if defined(jpn)
#define data_020ef22c data_020ef168
#define data_020ef233 data_020ef16f
#define data_020ef242 data_020ef17e
#define data_020ef251 data_020ef18d
#define data_020ef260 data_020ef19c
#endif

extern char data_020ef22c[];
extern char data_020ef233[];
extern char data_020ef242[];
extern char data_020ef251[];
extern char data_020ef260[];

void BackupPairTableToBuffer(int*);
void RestorePairTableFromBuffer(int*);
extern "C" void __clear(void* buf, int len);
extern "C" void* _ZN7Model3DC1Ev(void*);
extern "C" void* _ZN7Model3DD1Ev(void*);
void NotifyActiveSlots02018f30(unsigned char*);

// USA: func_02018d28
extern "C" ARM void func_02018d28(Zone3D* self, SafeAllocator* alloc, void* archive, unsigned int archiveLength) {
    unsigned int size;
    int backup[10];
    Model3D* localList[3];
    Model3D* globalList[3];
    char path[0x50];
    Model3D localB;
    Model3D localA;
    void* data;
    int* dst1;
    Model3D** p1;
    int* dst2;
    Model3D** p2;

    BackupPairTableToBuffer(backup);
    _ZN7Model3DC1Ev(&localB);
    localB.Clear();
    sprintf(path, data_020ef22c, data_020ef233);
    if ((data = LoadFileIntoNewAllocation(path, *alloc, &size)) != 0) {
        localB.SetAndProcessRawFile(data, size, Model3D::TextureStagingMode_Normal);
    }
    _ZN7Model3DC1Ev(&localA);
    localA.Clear();
    sprintf(path, data_020ef22c, data_020ef242);
    if ((data = LoadFileIntoNewAllocation(path, *alloc, &size)) != 0) {
        localA.SetAndProcessRawFile(data, size, Model3D::TextureStagingMode_Normal);
    }

    __clear(localList, 0xc);
    localList[0] = &localB;
    localList[1] = &localA;
    dst1 = &self->chestPaletteOffsets_5f0_[2];
    p1 = localList;
    while (*p1 != 0) {
        NSBXXTex* tex = (*p1)->GetTEX0();
        if (tex != 0) {
            *dst1 = tex->block4VRAMLoadOffset_;
        }
        p1++;
        dst1++;
    }

    alloc->Reset();
    RestorePairTableFromBuffer(backup);
    sprintf(path, data_020ef22c, data_020ef251);
    if ((data = LoadFileIntoNewAllocation(path, *alloc, &size)) != 0) {
        self->models_498_[0].SetAndProcessRawFile(data, size, Model3D::TextureStagingMode_Normal);
    }
    sprintf(path, data_020ef22c, data_020ef260);
    if ((data = LoadFileIntoNewAllocation(path, *alloc, &size)) != 0) {
        self->models_498_[1].SetAndProcessRawFile(data, size, Model3D::TextureStagingMode_Normal);
    }

    __clear(globalList, 0xc);
    globalList[0] = &self->models_498_[0];
    globalList[1] = &self->models_498_[1];
    dst2 = self->chestPaletteOffsets_5f0_;
    p2 = globalList;
    while (*p2 != 0) {
        NSBXXTex* tex = (*p2)->GetTEX0();
        if (tex != 0) {
            *dst2 = tex->block4VRAMLoadOffset_;
        }
        p2++;
        dst2++;
    }

    NotifyActiveSlots02018f30((unsigned char*)self);
    _ZN7Model3DD1Ev(&localA);
    _ZN7Model3DD1Ev(&localB);
}
