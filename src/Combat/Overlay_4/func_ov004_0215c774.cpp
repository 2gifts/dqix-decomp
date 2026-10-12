#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

struct NodeAllocator0215c774 {
    unsigned int field_0x00;
    SafeAllocator allocator;
};

struct ListNode_021f67ac {
    char padding_0x00[6];
    unsigned short flag;
    char padding_0x08[12];
    ListNode_021f67ac* previous;
    ListNode_021f67ac* next;
};

struct MessageNode0215c774 {
    ListNode_021f67ac listNode;
    char payload[0x90];
};

struct PairTableNode0215c774 {
    unsigned int field_0x00;
    char tables[0x70];
};

struct ArchiveVariant0215c774 {
    char padding_0x00[0x18];
    unsigned int unusedLow : 12;
    unsigned int variant : 4;
    unsigned int unusedHigh : 16;
};

struct ArchiveState0215c774 {
    char padding_0x00[8];
    ArchiveVariant0215c774* current;
};

struct ListHead_021f67ac;
extern "C" NodeAllocator0215c774* func_ov011_021845f8(void*, int);
extern "C" void* func_ov004_0215c448(void*);
extern "C" void* func_ov004_0215c474(void*);
extern "C" int _Z24InitObjWithMisc_021f6f20Pviiiij(void*, int, int, int, int, unsigned int);
extern "C" void __clear(void*, unsigned int);
extern "C" void* ExtractFileFromGP2(const char*, const char*, unsigned int*);
extern "C" void* _Z20AddOffset20_021f7318Pv(void*);
extern "C" PairTableNode0215c774* _Z20FindNodeById0218466cPvt(void*, unsigned short);
extern "C" void _Z25RestorePairTables0207df90Pc(char*);
extern "C" void func_0204719c(void*);
extern "C" void _Z15Forward02047b30Pviii(void*, int, int, int);
extern "C" void _Z24BackupPairTables0207dfacPc(char*);
extern "C" void _Z22SetField1cTo2_021f7320Pv(void*);
extern "C" ListHead_021f67ac* func_ov011_021849c8(void*);
extern "C" void _Z25AppendNodeToList_021f67acP17ListHead_021f67acP17ListNode_021f67ac(ListHead_021f67ac*, ListNode_021f67ac*);
extern ArchiveState0215c774 data_ov004_021707d8;
extern char data_ov004_02170415[];
extern char data_ov004_0217042c[];

// USA: func_ov004_0215c774
extern "C" ARM int func_ov004_0215c774(void* context) {
    NodeAllocator0215c774* owner = func_ov011_021845f8(context, 10);
    if (owner == 0) return 0;
    owner->allocator.GetSizeWithLargestBlockRemoved();
    MessageNode0215c774* node = (MessageNode0215c774*)owner->allocator.Allocate(sizeof(MessageNode0215c774));
    if (node == 0) return 0;
    MessageNode0215c774 temporary;
    func_ov004_0215c448(&temporary);
    memcpy(node, &temporary, sizeof(temporary));
    if (_Z24InitObjWithMisc_021f6f20Pviiiij(node, (int)context, 0x640, 10, 0, 0) == 0) {
        func_ov004_0215c474(&temporary);
        return 0;
    }
    char archivePath[32];
    char innerPath[32];
    __clear(archivePath, sizeof(archivePath));
    __clear(innerPath, sizeof(innerPath));
    sprintf(archivePath, data_ov004_02170415, data_ov004_021707d8.current->variant);
    sprintf(innerPath, data_ov004_0217042c, data_ov004_021707d8.current->variant);
    BackgroundLoader::AddLockGlobal();
    unsigned int size;
    void* file = ExtractFileFromGP2(archivePath, innerPath, &size);
    void* model = _Z20AddOffset20_021f7318Pv(node);
    PairTableNode0215c774* pairs = _Z20FindNodeById0218466cPvt(context, 0);
    char* tables = pairs->tables;
    _Z25RestorePairTables0207df90Pc(tables);
    func_0204719c(model);
    if (file != 0) {
        _Z15Forward02047b30Pviii(model, (int)file, size, (int)&owner->allocator);
    }
    _Z24BackupPairTables0207dfacPc(tables);
    BackgroundLoader::RemoveLockGlobal();
    _Z22SetField1cTo2_021f7320Pv(node);
    _Z25AppendNodeToList_021f67acP17ListHead_021f67acP17ListNode_021f67ac(func_ov011_021849c8(context), &node->listNode);
    func_ov004_0215c474(&temporary);
    return 0;
}
