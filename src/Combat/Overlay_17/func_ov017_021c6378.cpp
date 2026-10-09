#include <globaldefs.h>

void* GetData02100044(void);
extern "C" void* memset(void* dst, int value, unsigned int size);
extern "C" void func_0205e330(void* a, void* b, int c);
extern "C" void func_ov017_021c6254(char* self, int index);

struct Sub8e18 {
    unsigned char pad[8];
    unsigned short val;
};

struct Nibbles021c6378 {
    unsigned char lo : 4;
    unsigned char hi : 4;
};

struct Entry021c6378 {
    unsigned short id;
    unsigned char pad2[8];
    Nibbles021c6378 nibbles;
    unsigned char value;
    unsigned char padc[0xc];
};

struct Party021c6378 {
    unsigned char field0;
    unsigned char field1_lo : 4;
    unsigned char count : 2;
    unsigned char mode : 2;
    unsigned char pad2[2];
    Entry021c6378 entries[3];
};

struct Payload021c6378 {
    unsigned short val;
    unsigned short ids[3];
    unsigned char values[3];
    Nibbles021c6378 nibbles0;
    Nibbles021c6378 nibbles1;
    Nibbles021c6378 nibbles2;
    unsigned char mode;
    unsigned char padf;
};

struct Msg021c6378 {
    unsigned char tag;
    unsigned char pad1[3];
    Payload021c6378 payload;
};

// USA: func_ov017_021c6378
extern "C" ARM void func_ov017_021c6378(char* self) {
    void* data = GetData02100044();
    Msg021c6378 msg;
    msg.tag = 0x40;
    Payload021c6378* p = &msg.payload;
    memset(p, 0, sizeof(Payload021c6378));
    p->val = (*(Sub8e18**)(self + 0x8e18))->val;
    Party021c6378* party = (Party021c6378*)(self + 0x1b0 + 0x8000);
    p->mode = party->mode;
    for (int i = 0; i < party->count; i++) {
        p->ids[i] = party->entries[i].id;
        p->values[i] = party->entries[i].value;
        if (i == 0) {
            p->nibbles0.lo = party->entries[i].nibbles.lo;
            p->nibbles0.hi = party->entries[i].nibbles.hi;
        } else if (i == 1) {
            p->nibbles1.lo = party->entries[i].nibbles.lo;
            p->nibbles1.hi = party->entries[i].nibbles.hi;
        } else if (i == 2) {
            p->nibbles2.lo = party->entries[i].nibbles.lo;
            p->nibbles2.hi = party->entries[i].nibbles.hi;
        }
    }
    func_0205e330(data, &msg, 0);
    for (int j = 0; j < party->count; j++) {
        func_ov017_021c6254(self, j);
    }
}
