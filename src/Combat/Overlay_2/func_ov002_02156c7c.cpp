#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include <globaldefs.h>

struct Pair0209a338;
struct Ctx0209a470;
struct Ctx0209a8b4;
struct StreamHeader;
extern "C" void _Z16ZeroInit020de848Pv(void *p);
extern "C" void _Z19ClearField00209a804Pi(int *p);
extern "C" void _Z26ClearFirstTwoWords0209a338P12Pair0209a338(struct Pair0209a338 *p);
extern "C" void _Z33SetupAndRunBufferedScript0209a470P11Ctx0209a470P13SafeAllocatorP12StreamHeaderi(struct Ctx0209a470 *ctx,
                                                                                                    SafeAllocator *alloc,
                                                                                                    struct StreamHeader *hdr,
                                                                                                    int len);
extern "C" void _Z33SetupAndRunBufferedScript0209a8b4P11Ctx0209a8b4P13SafeAllocatorP12StreamHeaderi(struct Ctx0209a8b4 *ctx,
                                                                                                    SafeAllocator *alloc,
                                                                                                    struct StreamHeader *hdr,
                                                                                                    int len);
extern "C" void func_020dea64(void *list, void *alloc, void *data, unsigned int size, const void *entries, int count);
extern "C" char data_ov002_0216c96e[];

// USA: func_ov002_02156c7c
extern "C" ARM void func_ov002_02156c7c(char *base) {
    void *file0;
    unsigned int len0;
    void *file1;
    unsigned int len1;
    void *file2;
    unsigned int len2;

    if (!(*(unsigned int *) (base + 0x2000 + 0x47c) & 0x10)) return;

    BackgroundLoader *loader = BackgroundLoader::GetInstance();
    unsigned char n          = 0;
    for (unsigned char i = 0; i < 3; i++) {
        if (loader->GetTaskStatus(*(int *) (base + i * 4 + 0x1000 + 0xba4))) {
            n++;
        }
    }
    if (n != 3) return;

    int *h = (int *) (base + 0x3a4 + 0x1800);
    if (loader->GetTaskStatus(*(int *) (base + 0x1000 + 0xba4))) {
        loader->GetLoadedFileByID(*h, &file0, &len0);
        ((SafeAllocator *) (base + 0x810))->Reset();
        _Z16ZeroInit020de848Pv(base + 0x3ec + 0x400);
        func_020dea64(base + 0x3ec + 0x400, base + 0x810, file0, len0, data_ov002_0216c96e, 2);
        loader->RemoveTask(*h);
        *h = -1;
    }
    h = (int *) (base + 0x3a8 + 0x1800);
    if (loader->GetTaskStatus(*(int *) (base + 0x1000 + 0xba8))) {
        loader->GetLoadedFileByID(*h, &file1, &len1);
        _Z19ClearField00209a804Pi((int *) (base + 0x44 + 0x2400));
        if (file1 != NULL && len1 != 0) {
            _Z33SetupAndRunBufferedScript0209a8b4P11Ctx0209a8b4P13SafeAllocatorP12StreamHeaderi(
                (struct Ctx0209a8b4 *) (base + 0x44 + 0x2400), (SafeAllocator *) (base + 0x8c + 0x800),
                (struct StreamHeader *) file1, len1);
        }
        loader->RemoveTask(*h);
        *h = -1;
    }
    h = (int *) (base + 0x3ac + 0x1800);
    if (loader->GetTaskStatus(*(int *) (base + 0x1000 + 0xbac))) {
        if (*(unsigned char *) (base + 0x2000 + 0x485) == 0) {
            loader->GetLoadedFileByID(*h, &file2, &len2);
            ((SafeAllocator *) (base + 0x850))->Reset();
            _Z26ClearFirstTwoWords0209a338P12Pair0209a338((struct Pair0209a338 *) (base + 0x3c + 0x2400));
            if (file2 != NULL && len2 != 0) {
                _Z33SetupAndRunBufferedScript0209a470P11Ctx0209a470P13SafeAllocatorP12StreamHeaderi(
                    (struct Ctx0209a470 *) (base + 0x3c + 0x2400), (SafeAllocator *) (base + 0x850),
                    (struct StreamHeader *) file2, len2);
            }
        }
        loader->RemoveTask(*h);
        *h = -1;
    }
    *(unsigned int *) (base + 0x2000 + 0x47c) |= 0x20;
}
