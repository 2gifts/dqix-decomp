#include <globaldefs.h>
#include "std_library_functions.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "World/ZoneObjectResourceLoading.h"
#include "GameState/GameState.h"

struct Struct0200fb08;
struct NodeList02057de0;
struct Obj021e8bac;
struct RemoveList021eb084;

struct Node021e8bac {
    unsigned char byte0;
    unsigned char byte1;
    unsigned short half2;
    unsigned short half4;
    struct Node021e8bac* next;
};

struct BattleUi021e27c8 {
    char pad0[8];
    int loadedCount;
    char* ui;
};

SafeAllocator* GetArrayEntry_021e8a54_021e8a54(char* obj);
char* GetArrayEntry_021e8a64_021e8a64(char* obj);
extern "C" NodeList02057de0* func_02057924(void);
unsigned char NormalizeField5_0200fb08(Struct0200fb08* obj);
int FindTagAndCopy_021e24d0(char* s, char* out2, char* out1);
void PushLogNode021e8bac(Obj021e8bac* obj, Node021e8bac* node);
int CreateAndRegisterNode02057de0(NodeList02057de0* list, int id, SafeAllocator* alloc, int data, int size);
void RemoveMatchingShort_021eb084(RemoveList021eb084* obj, int val);
extern "C" void __clear(void* p, int n);

extern BattleUi021e27c8 data_ov025_021ef988;

// USA: func_ov025_021e27c8
extern "C" ARM void func_ov025_021e27c8(char* name, int id) {
    char archive[0x50];
    char inner[0x50];
    char path[0x50];
    void* data;
    unsigned int size;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GetArrayEntry_021e8a54_021e8a54(data_ov025_021ef988.ui);
    GetArrayEntry_021e8a64_021e8a64(data_ov025_021ef988.ui);
    func_02057924();
    int language = NormalizeField5_0200fb08((Struct0200fb08*)GameState::GetInstance());
    data = 0;
    __clear(path, 0x50);
    StringReplaceLanguageTag(name, path, language);
    int task;
    if (FindTagAndCopy_021e24d0(name, archive, inner)) {
        task = loader->GetLoadedFileInArchive(archive, inner, &data, &size);
    } else {
        task = loader->GetLoadedFileByName(path, &data, &size);
    }
    void* src = data;
    if (src != 0) {
        unsigned int len = size;
        BackgroundLoader::GetInstance();
        char* tables;
        SafeAllocator* alloc;
        void* copy;
        NodeList02057de0* list;
        alloc = GetArrayEntry_021e8a54_021e8a54(data_ov025_021ef988.ui);
        tables = GetArrayEntry_021e8a64_021e8a64(data_ov025_021ef988.ui);
        list = func_02057924();
        copy = alloc->Allocate(len);
        if (copy != 0) {
            memcpy(copy, src, len);
            if (id < 0) id = data_ov025_021ef988.loadedCount + 0x64;
            Node021e8bac* node = (Node021e8bac*)alloc->Allocate(0xc);
            if (node != 0) {
                node->byte0 = 1;
                node->half4 = id;
                PushLogNode021e8bac((Obj021e8bac*)data_ov025_021ef988.ui, node);
                RestorePairTables0207df90(tables);
                CreateAndRegisterNode02057de0(list, id, alloc, (int)copy, len);
                BackupPairTables0207dfac(tables);
                data_ov025_021ef988.loadedCount++;
            }
        }
    }
    if (task >= 0) {
        loader->RemoveTask(task);
        RemoveMatchingShort_021eb084((RemoveList021eb084*)data_ov025_021ef988.ui, task);
    }
}
