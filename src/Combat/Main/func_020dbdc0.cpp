#include <globaldefs.h>
#include <std_library_functions.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct Node02057de0 {
    unsigned char pad[0x1ec];
    struct Node02057de0* next;
};

struct NodeList02057de0 {
    struct Node02057de0* head;
    int count;
};

extern "C" int _Z29CreateAndRegisterNode02057de0P16NodeList02057de0iP13SafeAllocatorii(NodeList02057de0* list, int a1, SafeAllocator* alloc, int a2, int a3);
extern "C" int _Z39CollectEntriesMatchingField0xd802058680PciPPvi(char* base, int value, void** out, int limit);
extern "C" void _Z25RestorePairTables0207df90Pc(char* obj);
extern "C" void _Z24BackupPairTables0207dfacPc(char* obj);

struct Obj020dbf70;
extern "C" void _Z21ReleaseHandle020dbf70P11Obj020dbf70(struct Obj020dbf70* o);

extern "C" int func_02057924(void);

struct Struct020dbd9c {
    SafeAllocator* f0;
    char* f4;
    int f8;
    int fc;
    int f10;
    unsigned char f14;
};

// USA: func_020dbdc0
extern "C" ARM void func_020dbdc0(Struct020dbd9c* self) {
    if (self->fc >= 0) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (loader->GetTaskStatus(self->fc) != 0) {
            NodeList02057de0* list = (NodeList02057de0*)func_02057924();
            void* fileData = NULL;
            unsigned int fileLen = 0;
            loader->GetLoadedFileByID(self->fc, &fileData, &fileLen);
            void* buf = self->f0->Allocate(fileLen);
            if (buf == NULL) {
                _Z21ReleaseHandle020dbf70P11Obj020dbf70((struct Obj020dbf70*)self);
                return;
            }
            memcpy(buf, fileData, fileLen);
            _Z25RestorePairTables0207df90Pc(self->f4);
            _Z29CreateAndRegisterNode02057de0P16NodeList02057de0iP13SafeAllocatorii(list, self->f8, self->f0, (int)buf, (int)fileLen);
            _Z24BackupPairTables0207dfacPc(self->f4);
            _Z21ReleaseHandle020dbf70P11Obj020dbf70((struct Obj020dbf70*)self);
            self->f10 = 2;
        }
    }
    if (self->f14 != 0) {
        char* base = (char*)func_02057924();
        if (base != NULL) {
            int count = _Z39CollectEntriesMatchingField0xd802058680PciPPvi(base, self->f8, NULL, 0);
            if (count <= 0) {
                self->f14 = 0;
            }
        }
    }
}