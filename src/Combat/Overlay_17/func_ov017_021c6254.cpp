#include <globaldefs.h>

void* GetData02100044(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Sub8e18_021c6254 {
    unsigned char pad0[8];
    unsigned short id;
};

struct Slot021c6254 {
    unsigned char pad0[2];
    unsigned char values[8];
    unsigned char count : 4;
    unsigned char flags : 4;
    unsigned char pad0b[0xd];
};

struct Holder021c6254 {
    unsigned char pad0[4];
    Slot021c6254 slots[1];
};

struct Payload021c6254 {
    unsigned short id;
    unsigned short slotIndex;
    unsigned char values[8];
    unsigned char pad0c[4];
};

struct Evt021c6254 {
    unsigned char tag;
    unsigned char pad1[3];
    Payload021c6254 payload;
};

// USA: func_ov017_021c6254
extern "C" ARM void func_ov017_021c6254(char* self, int slotIndex) {
    void* data = GetData02100044();
    Evt021c6254 evt;
    Payload021c6254* p = &evt.payload;
    evt.tag = 0x62;
    p->id = (*(Sub8e18_021c6254**)(self + 0x8e18))->id;
    Slot021c6254* slot = &((Holder021c6254*)(self + 0x1b0 + 0x8000))->slots[slotIndex];
    p->slotIndex = slotIndex;
    for (int i = 0; i < slot->count; i++) {
        p->values[i] = 0;
        p->values[i] = slot->values[i];
    }
    func_0205e330(data, &evt, 0);
}
