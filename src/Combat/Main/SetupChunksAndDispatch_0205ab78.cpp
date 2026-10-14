#include <globaldefs.h>

struct FieldArray {
    char pad[8];
    int arr[3];
};
void InitFieldArray_020b033c(struct FieldArray* obj);

struct Hdr02b0288 {
    unsigned char pad[0xc];
    unsigned short dataOffset;
    unsigned short count;
};
int FindPcmpChunk_020b022c(struct Hdr02b0288* h, void** out);
int FindPlttChunkAndRelocate_020b01f0(struct Hdr02b0288* h, void** out);

extern "C" void func_020b08b8(void* plttChunk, void* pcmpChunk, int zero, int mode, void* fieldArr);
extern "C" void func_020b07c0(void* plttChunk, int zero, int mode, void* fieldArr);

struct Obj0205ab78 {
    char pad0[0x24];
    struct FieldArray fieldArr;
    char pad1[0x50 - 0x38];
    unsigned char byte50;
};

// USA: func_0205ab78  (semantic: SetupChunksAndDispatch_0205ab78)
extern "C" ARM int func_0205ab78(struct Obj0205ab78* obj, struct Hdr02b0288* h, void* other) {
    int fail;
    int mode;

    InitFieldArray_020b033c(&obj->fieldArr);
    void* plttChunk = 0;
    void* pcmpChunk = 0;
    int pcmpFound = FindPcmpChunk_020b022c(h, &pcmpChunk);

    if (h == 0) {
        fail = 1;
    } else if (other == 0) {
        fail = 1;
    } else {
        if (FindPlttChunkAndRelocate_020b01f0(h, &plttChunk)) {
            fail = 0;
        } else {
            fail = 1;
        }
    }
    if (fail) {
        return 1;
    }

    mode = (obj->byte50 == 0) ? 1 : 2;
    if (pcmpFound) {
        func_020b08b8(plttChunk, pcmpChunk, 0, mode, &obj->fieldArr);
    } else {
        func_020b07c0(plttChunk, 0, mode, &obj->fieldArr);
    }
    return 0;
}
