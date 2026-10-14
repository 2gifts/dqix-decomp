#include <globaldefs.h>

struct Node0223d858;
struct SlotArray0223dabc;
struct SlotLink0223dabc {
    void* previous;
    void* next;
    unsigned short unknown_0x8;
    unsigned char padding[2];
};
struct Slot0223dabc {
    unsigned char entries[0x180];
    SlotLink0223dabc firstLink;
    SlotLink0223dabc secondLink;
    Node0223d858* list;
    SlotArray0223dabc* slotArray;
};
extern Slot0223dabc* data_ov031_02290d64;
extern "C" void* func_ov031_0223cf4c(unsigned int, int);
SlotArray0223dabc* FillSlotArrayField4_0223beec(int, int, int);
Node0223d858* InitSelfRefNode_0223d858();
int TailCallField4Ptr_0223d918(char*);
int TailCallField8_0223d908(char*);
typedef void (*AppendSlotLink0223dabc)(Node0223d858*, SlotLink0223dabc*);

static inline Slot0223dabc* GetSlot0223dabc(int offset) {
    return (Slot0223dabc*)((unsigned char*)data_ov031_02290d64 + offset);
}

// USA: func_ov031_0223dabc
extern "C" ARM void func_ov031_0223dabc() {
    data_ov031_02290d64 = (Slot0223dabc*)func_ov031_0223cf4c(0x340, 4);
    int index = 0;
    int offset = 0;
    do {
        SlotArray0223dabc* array = FillSlotArrayField4_0223beec(0x20, (int)GetSlot0223dabc(offset)->entries, 0xc);
        GetSlot0223dabc(offset)->slotArray = array;
        Node0223d858* list = InitSelfRefNode_0223d858();
        GetSlot0223dabc(offset)->list = list;
        GetSlot0223dabc(offset)->firstLink.unknown_0x8 = 0x300;
        GetSlot0223dabc(offset)->secondLink.unknown_0x8 = 0x400;
        ((AppendSlotLink0223dabc)TailCallField4Ptr_0223d918)(GetSlot0223dabc(offset)->list, &GetSlot0223dabc(offset)->firstLink);
        ((AppendSlotLink0223dabc)TailCallField8_0223d908)(GetSlot0223dabc(offset)->list, &GetSlot0223dabc(offset)->secondLink);
        index++;
        offset += sizeof(Slot0223dabc);
    } while (index < 2);
}
