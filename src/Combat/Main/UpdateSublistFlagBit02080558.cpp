#include <globaldefs.h>

void ClearSublistEntriesFlag4_020804fc(void* obj, int p1);
extern "C" void func_020813ec(void* obj, int p1);

struct List0207f0ac;
struct SubEntry0207f0ac {
    short* shortArray;
    char pad[0x13 - 4];
    unsigned char count;
};
SubEntry0207f0ac* FindEntryByShortId0207f0ac(List0207f0ac* list, int id);

struct List0207f6ac;
struct SubEntry0207f6ac {
    char pad[4];
    short id;
    char pad2[0x2a - 6];
    unsigned char flags;
};
SubEntry0207f6ac* FindEntryByShortId0207f6ac(List0207f6ac* list, int id);

// USA: func_02080558  (semantic: UpdateSublistFlagBit02080558)
extern "C" ARM void func_02080558(void* obj, int p1, int result, int flag, unsigned char extra) {
    if (flag) {
        ClearSublistEntriesFlag4_020804fc(obj, p1);
    }
    SubEntry0207f0ac* e = FindEntryByShortId0207f0ac((List0207f0ac*)((char*)obj + 0xc), p1);
    if (e != 0) {
        for (unsigned char i = 0; i < e->count; i++) {
            short shortId = e->shortArray[i];
            SubEntry0207f6ac* e2 = FindEntryByShortId0207f6ac((List0207f6ac*)((char*)obj + 4), shortId);
            if (e2 != 0) {
                if (e2->id == result) {
                    e2->flags = e2->flags | 4;
                    goto end;
                }
            }
        }
    }
end:
    if (extra == 0) return;
    func_020813ec(obj, p1);
}
