#include <globaldefs.h>

struct SlotRange {
    void* field_0;
    void* field_4;
    void* begin;
    void* field_c;
};
struct SlotStorage {
    unsigned char data[0x200];
    SlotRange first;
    SlotRange second;
    char* node;
    void* array;
};
extern SlotStorage* data_ov031_02290d28;
extern "C" void* func_ov031_0223cf4c(int, int);
extern "C" void _Z28FillSlotArrayField4_0223beeciii(int, int, int);
extern "C" char* _Z24InitSelfRefNode_0223d858v(void);
extern "C" void* _Z30GetElemPtrRow1024Col8_0223daa4ii(int, int);
extern "C" int _Z26TailCallField4Ptr_0223d918Pc(char*);
extern "C" int _Z23TailCallField8_0223d908Pc(char*);
typedef int (*TailCallWithRange)(char*, void*);
typedef void* (*SlotArrayWithResult)(int, int, int);
static inline SlotStorage* GetSlot(int offset) {
    return (SlotStorage*)((char*)data_ov031_02290d28 + offset);
}

// USA: func_ov031_0223b79c
extern "C" ARM void func_ov031_0223b79c(void) {
    data_ov031_02290d28 = (SlotStorage*)func_ov031_0223cf4c(0x450, 4);
    int index = 0;
    int offset = 0;
    do {
        void* array = reinterpret_cast<SlotArrayWithResult>(_Z28FillSlotArrayField4_0223beeciii)(32, (int)GetSlot(offset)->data, 16);
        GetSlot(offset)->array = array;
        char* node = _Z24InitSelfRefNode_0223d858v();
        GetSlot(offset)->node = node;
        void* first = _Z30GetElemPtrRow1024Col8_0223daa4ii(index, 64);
        GetSlot(offset)->first.begin = first;
        char* second = (char*)_Z30GetElemPtrRow1024Col8_0223daa4ii(index, 127) + 8;
        GetSlot(offset)->second.begin = second;
        reinterpret_cast<TailCallWithRange>(_Z26TailCallField4Ptr_0223d918Pc)(GetSlot(offset)->node, &GetSlot(offset)->first);
        reinterpret_cast<TailCallWithRange>(_Z23TailCallField8_0223d908Pc)(GetSlot(offset)->node, &GetSlot(offset)->second);
        offset += sizeof(SlotStorage);
        index++;
    } while (index < 2);
}
