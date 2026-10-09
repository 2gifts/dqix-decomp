#include <globaldefs.h>

int GetSubstructByte0x1e(unsigned char* obj);
int GetSubstructByte0x1c(unsigned char* obj);
void SetSubstructByte0x1e(unsigned char* obj, unsigned char value);

struct Actor_021e1ff4 {
    char pad0[4];
    short id;
};

struct Entry_021e1ff4 {
    unsigned char id;
    char pad1[3];
    int matched;
    unsigned char* obj;
};

// USA: func_ov025_021e1ff4
extern "C" ARM void func_ov025_021e1ff4(unsigned char* ids, int idCount, unsigned char* out, Actor_021e1ff4* a,
                                        Actor_021e1ff4* b, Entry_021e1ff4* entries, int entryCount) {
    if (a == 0 || b == 0) {
        return;
    }
    for (int i = 0; i < idCount; i++) {
        if (ids[i] >= 0x51) {
            continue;
        }
        if (ids[i] < 0x51) {
            out[ids[i]] = 0xff;
        }
        for (int j = 0; j < entryCount; j++) {
            unsigned char* obj = entries[j].obj;
            int id = entries[j].id;
            if (id == a->id || id == b->id) {
                continue;
            }
            int v = GetSubstructByte0x1e(obj);
            if (v >= 0x51) {
                v = GetSubstructByte0x1c(obj);
            }
            if (v == ids[i]) {
                entries[j].matched = 1;
                SetSubstructByte0x1e(obj, 0xff);
            }
        }
    }
}
