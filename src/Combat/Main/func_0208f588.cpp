#include <globaldefs.h>
#include "World/Object3D.h"
#if defined(jpn)
#define data_020e8d54 data_020e8e70
#endif

struct Object3DState0208f588 {
    unsigned char storage[0xac];
};

struct ObjectArchiveLoadInfo0208f588 {
    int unused0;
    void* data;
    unsigned int size;
    void* allocator;
    int flag;
    int pad14;
    int pad18;
    int pad1c;
};

struct ModeFlags02012fe4 {
    unsigned char pad0[0xc];
    unsigned char mode : 4;
    unsigned char high : 4;
};

struct Context02012fe4 {
    unsigned char pad0[8];
    struct ModeFlags02012fe4* flags;
};

struct ArchiveHolder0208f588 {
    void* data;
    unsigned int size;
    struct Object3DState0208f588 object;
    unsigned char loaded;
    unsigned char ready;
};

struct ArchivePath0208f588 {
    char text[0x28];
};

extern const struct ArchivePath0208f588 data_020e8d54;

extern "C" struct Context02012fe4* func_02012fe4(void);
extern "C" void* _Z25LoadFileIntoNewAllocationPKcR13SafeAllocatorPj(const char* path, void* allocator, unsigned int* outSize);
struct ObjectArchiveLoadInfo;

void RestorePairTables0207df90(char* obj);
void BackupPairTables0207dfac(char* obj);

// USA: func_0208f588
extern "C" ARM int func_0208f588(struct ArchiveHolder0208f588* self, void* allocator, char* pairObj) {
    unsigned int size;
    struct ArchivePath0208f588 path;
    struct ObjectArchiveLoadInfo0208f588 info;
    void* data;

    self->loaded = 0;
    ((Object3D*)&self->object)->Destroy();
    ((Object3D*)&self->object)->Initialize();
    if (func_02012fe4()->flags->mode != 0) {
        return 0;
    }

    path = data_020e8d54;
    data = _Z25LoadFileIntoNewAllocationPKcR13SafeAllocatorPj(path.text, allocator, &size);
    if (data == 0) {
        return 0;
    }
    unsigned int length = size;
    self->data = data;
    self->size = length;
    self->loaded = 1;
    self->ready = 1;

    info.unused0 = 0;
    info.data = 0;
    info.size = 0;
    info.flag = 0;
    info.pad14 = 0;
    info.pad18 = 0;
    info.pad1c = 0;
    info.allocator = allocator;
    info.data = self->data;
    info.size = self->size;

    RestorePairTables0207df90(pairObj);
    ((Object3D*)&self->object)->Initialize();
    ((Object3D*)&self->object)->LoadFromCHRArchive((ObjectArchiveLoadInfo*)&info);
    ((Object3D*)&self->object)->MakeHidden();
    BackupPairTables0207dfac(pairObj);
    return 1;
}
