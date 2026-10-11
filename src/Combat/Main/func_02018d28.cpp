#include <globaldefs.h>
#include "Graphics/Model3D.h"
#include "Memory/SafeAllocator.h"

extern char data_020ef22c[];
extern char data_020ef233[];
extern char data_020ef242[];
extern char data_020ef251[];
extern char data_020ef260[];

extern "C" void _Z23BackupPairTableToBufferPi(int*);
extern "C" void _Z26RestorePairTableFromBufferPi(int*);
extern "C" void __clear(void* buf, int len);
extern "C" void _ZN7Model3DC1Ev(Model3D*);
extern "C" void _ZN7Model3DD1Ev(Model3D*);
extern "C" void* _Z25LoadFileIntoNewAllocationPKcR13SafeAllocatorPj(const char*, SafeAllocator*, unsigned int*);
extern "C" void _Z25NotifyActiveSlots02018f30Ph(unsigned char*);

struct Obj02018d28 {
    unsigned char pad0[0x498];
    Model3D model0;
    Model3D model1;
    int texOffsets[4];
};

// USA: func_02018d28
extern "C" ARM void func_02018d28(Obj02018d28* self, SafeAllocator* alloc) {
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

    _Z23BackupPairTableToBufferPi(backup);
    _ZN7Model3DC1Ev(&localB);
    localB.Clear();
    sprintf(path, data_020ef22c, data_020ef233);
    if ((data = _Z25LoadFileIntoNewAllocationPKcR13SafeAllocatorPj(path, alloc, &size)) != 0) {
        localB.SetAndProcessRawFile(data, size, Model3D::TextureStagingMode_Normal);
    }
    _ZN7Model3DC1Ev(&localA);
    localA.Clear();
    sprintf(path, data_020ef22c, data_020ef242);
    if ((data = _Z25LoadFileIntoNewAllocationPKcR13SafeAllocatorPj(path, alloc, &size)) != 0) {
        localA.SetAndProcessRawFile(data, size, Model3D::TextureStagingMode_Normal);
    }

    __clear(localList, 0xc);
    localList[0] = &localB;
    localList[1] = &localA;
    dst1 = &self->texOffsets[2];
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
    _Z26RestorePairTableFromBufferPi(backup);
    sprintf(path, data_020ef22c, data_020ef251);
    if ((data = _Z25LoadFileIntoNewAllocationPKcR13SafeAllocatorPj(path, alloc, &size)) != 0) {
        self->model0.SetAndProcessRawFile(data, size, Model3D::TextureStagingMode_Normal);
    }
    sprintf(path, data_020ef22c, data_020ef260);
    if ((data = _Z25LoadFileIntoNewAllocationPKcR13SafeAllocatorPj(path, alloc, &size)) != 0) {
        self->model1.SetAndProcessRawFile(data, size, Model3D::TextureStagingMode_Normal);
    }

    __clear(globalList, 0xc);
    globalList[0] = &self->model0;
    globalList[1] = &self->model1;
    dst2 = self->texOffsets;
    p2 = globalList;
    while (*p2 != 0) {
        NSBXXTex* tex = (*p2)->GetTEX0();
        if (tex != 0) {
            *dst2 = tex->block4VRAMLoadOffset_;
        }
        p2++;
        dst2++;
    }

    _Z25NotifyActiveSlots02018f30Ph((unsigned char*)self);
    _ZN7Model3DD1Ev(&localA);
    _ZN7Model3DD1Ev(&localB);
}
