#include <globaldefs.h>
#include "System/Memory.h"

typedef void* (*ResourceAllocator02217c00)(const char*, unsigned int);
union ResourceConfig02217c00 {
    struct {
        const char* name;
        int field_4;
        int capacity;
        ResourceAllocator02217c00 allocate;
        int field_10;
        int field_14;
        int field_18;
    } fields;
    unsigned int words[7];
};
struct ResourceWork02217c00 {
    char pad_0[0x1000];
    struct Header {
        unsigned char state;
        char pad_1001[3];
        ResourceConfig02217c00 config;
        int result;
    } header;
    char pad_1024[0x9a8];
    void* firstResource;
    void* secondResource;
    char pad_19d4[0x34];
    struct {
        char pad_0[0x28];
        int field_1a30;
        int field_1a34;
        char pad_30[0x1dc];
    } storage;
};
int Setup_022187a4(char*, void*, int);
extern "C" int func_ov031_022188e4(ResourceWork02217c00*, const char*);
extern "C" int func_ov031_02218468(ResourceWork02217c00*);
extern const char data_ov031_02249db4[];
extern const char data_ov031_02249dcc[];

static inline ResourceWork02217c00::Header* ResourceHeader02217c00(ResourceWork02217c00* work) {
    return &work->header;
}

// USA: func_ov031_02217c00
extern "C" ARM int func_ov031_02217c00(ResourceWork02217c00* work, ResourceConfig02217c00* config) {
    ResourceAllocator02217c00 allocate = config->fields.allocate;
    VectorizedMemset(work, 0, 0x1c14);
    work->storage.field_1a30 = -1;
    work->storage.field_1a34 = -1;
    work->header.config = *config;
    work->firstResource = allocate(data_ov031_02249db4, 0xb68);
    if (!work->firstResource) {
        work->header.result = 1;
        return 1;
    }
    work->secondResource = allocate(data_ov031_02249dcc, 0x5ea);
    if (!work->secondResource) {
        work->header.result = 1;
        return 1;
    }
    switch (Setup_022187a4((char*)work, &work->storage, work->header.config.fields.capacity)) {
    case 0: {
        ResourceWork02217c00::Header* header = ResourceHeader02217c00(work);
        int result = 1;
        header->result = result;
        return result;
    }
    default:
        break;
    }
    switch (func_ov031_022188e4(work, config->fields.name)) {
    case 0: {
        ResourceWork02217c00::Header* header = ResourceHeader02217c00(work);
        int result = 1;
        header->result = result;
        return result;
    }
    default:
        break;
    }
    work->header.result = func_ov031_02218468(work);
    if (work->header.result == 0) work->header.state = 0xff;
    return work->header.result;
}
