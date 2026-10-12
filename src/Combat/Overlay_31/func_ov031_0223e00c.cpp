#include <globaldefs.h>

struct Node0223e00c { unsigned int field0; void* field4; void* field8; unsigned int fieldC; };
struct Slot0223e00c { void* slots; void* entries; Node0223e00c* node; char bufferC[16]; unsigned char field1C; char pad1D[3]; char buffer20[16]; unsigned char field30; char pad31[3]; unsigned int count; unsigned char active; char pad39[3]; void* storage; };
extern Slot0223e00c* data_ov031_02290d9c;
extern unsigned char data_ov031_022493c0[];
extern "C" void* func_ov031_0223cf4c(int, int);
extern "C" void _Z28FillSlotArrayField4_0223beeciii(int, int, int);
typedef void* (*FillSlotArrayWithResult0223e00c)(int, int, int);
extern "C" void* func_ov031_0223beb8(int);
extern "C" Node0223e00c* _Z24InitSelfRefNode_0223d858v();
extern "C" int _Z26TailCallField4Ptr_0223d918Pc(char*);
extern "C" int _Z23TailCallField8_0223d908Pc(char*);
typedef int (*AttachBuffer0223e00c)(Node0223e00c*, void*);
static inline Slot0223e00c* SlotByOffset0223e00c(int offset) {
    return (Slot0223e00c*)((char*)data_ov031_02290d9c + offset);
}

// USA: func_ov031_0223e00c
extern "C" ARM void func_ov031_0223e00c() {
    data_ov031_02290d9c = (Slot0223e00c*)func_ov031_0223cf4c(128, 4);
    int index = 0;
    unsigned char* count = data_ov031_022493c0;
    int offset = 0;
    do {
        data_ov031_02290d9c[index].count = *count;
        data_ov031_02290d9c[index].storage = func_ov031_0223cf4c(*count * 20, 4);
        data_ov031_02290d9c[index].slots = reinterpret_cast<FillSlotArrayWithResult0223e00c>(_Z28FillSlotArrayField4_0223beeciii)(*count, (int)data_ov031_02290d9c[index].storage, 20);
        data_ov031_02290d9c[index].entries = func_ov031_0223beb8(*count);
        count++;
        data_ov031_02290d9c[index].node = _Z24InitSelfRefNode_0223d858v();
        data_ov031_02290d9c[index].field1C = 0;
        data_ov031_02290d9c[index].field30 = 255;
        reinterpret_cast<AttachBuffer0223e00c>(_Z26TailCallField4Ptr_0223d918Pc)(data_ov031_02290d9c[index].node, SlotByOffset0223e00c(offset)->bufferC);
        reinterpret_cast<AttachBuffer0223e00c>(_Z23TailCallField8_0223d908Pc)(data_ov031_02290d9c[index].node, SlotByOffset0223e00c(offset)->buffer20);
        data_ov031_02290d9c[index].active = 1;
        index++;
        offset += sizeof(Slot0223e00c);
    } while (index < 2);
}
