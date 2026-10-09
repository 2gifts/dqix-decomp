#include <globaldefs.h>

#include "World/Object3D.h"
#include "Filesystem/NarcHandle.h"
#include "Filesystem/FileAccessor.h"
#include "Filesystem/LowNitroHandle.h"
#include "Resource/ResourceMutex.h"
#include "std_library_functions.h"

struct Obj020553ac {
    int field0;
    int field4;
    int field8;
    int fieldc;
    int field10;
    Object3D object3d;
    char subc0[0x1e8 - 0xc0];
    int field1e8;
    int field1ec;
};

extern "C" void func_02054f80(void* obj);
extern "C" ARM int func_02055180(void* obj, void* a1, void* a2, void* a3);

extern const char data_020f04b4[];
extern const char data_020f04b8[];

// USA: func_020553ec
extern "C" ARM int func_020553ec(void* objp, int a1, void* alloc, void* fileData, unsigned int fileSize) {
    Obj020553ac* obj = (Obj020553ac*)objp;

    ObjectArchiveLoadInfo li;
    NarcHandle narc;
    NitroVM machine;
    char filename[0x50];

    obj->field0 = a1;
    obj->field1e8 = 0;
    obj->object3d.Initialize();
    func_02054f80(&obj->subc0);
    if (alloc != 0) {
        obj->field4 = (int)alloc;
    }

    li.unk_0 = 0;
    li.unk_10 = 0;
    li.unk_14 = 0;
    li.unk_18 = 0;
    li.packageID = 0;
    li.fileData = fileData;
    li.unk_8 = (int)fileSize;
    li.allocator = (SafeAllocator*)alloc;
    obj->object3d.LoadFromCHRArchive(&li);

    LockResourceMutex();
    if (narc.Initialize(data_020f04b4, (const unsigned char*)fileData)) {
        NitroVM_Initialize(&machine);
        unsigned int fileID;
        for (fileID = 0; PrepareReadFileInNARCByID(&machine, &narc, fileID); fileID++) {
            NitroVM_WriteOutFilePath(&machine, filename, sizeof(filename));
            if (strstr(filename, data_020f04b8)) {
                const void* fileBytes = narc.GetFileByIndex(fileID);
                unsigned int fileLength = machine.fileInfo.endOffset - machine.fileInfo.startOffset;
                unsigned int len2 = fileLength;
                func_02055180((void*)&obj->subc0, alloc, (void*)fileBytes, (void*)len2);
                obj->field1e8 = 1;
                NitroVM_FinishRead(&machine);
                break;
            }
            NitroVM_FinishRead(&machine);
        }
        narc.Destroy();
    }
    UnlockResourceMutex();
    if (obj->field1e8 == 0) {
        obj->object3d.MaybeSetBCFGAnimation(0, 0);
    }
    return 1;
}