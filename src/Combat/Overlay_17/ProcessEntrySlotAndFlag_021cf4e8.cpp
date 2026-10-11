#include <globaldefs.h>

struct Entry_02028bd0;
extern "C" unsigned short* func_02012fe4(void);
struct Entry_02028bd0* GetEntryTableBase(void);
struct Entry_02028bd0* FindInlineEntryById(struct Entry_02028bd0* base, int key);

struct Bits021cf4e8 { unsigned short low4:4; unsigned short high12:12; };

// JPN: func_ov017_021cf998
// USA: func_ov017_021cf4e8  (semantic: ProcessEntrySlotAndFlag_021cf4e8)
extern "C" ARM void func_ov017_021cf4e8(void* unusedArg0, unsigned char* entry, unsigned char* table, unsigned char* ctx) {
#if defined(jpn)
 enum {regionalOffset0=0xca2, regionalOffset1=0xca6, regionalOffset2=0x204, regionalOffset3=0x4000};
#else
 enum {regionalOffset0=0xf76, regionalOffset1=0xf7a, regionalOffset2=0xb4, regionalOffset3=0x4400};
#endif
    int inRange = entry[4] <= 3;
    if (inRange) {
        unsigned char* p = table + entry[4] + 0x7000;
        p[regionalOffset0] = entry[5];
        if (entry[5] == 2) {
            unsigned char* dst = ctx + regionalOffset2 + regionalOffset3;
            unsigned short* zone = func_02012fe4();
            struct Entry_02028bd0* found = FindInlineEntryById(GetEntryTableBase(), *zone);
            if (found != 0) {
                *(unsigned short*)dst = *zone;
                *(unsigned short*)(dst + 2) = ((struct Bits021cf4e8*)((char*)found + 2))->high12;
            }
        }
    } else {
        unsigned char* p = table + entry[4] + 0x7000;
        p[regionalOffset0] = 5;
    }
    table[0x7000 + regionalOffset1] = table[0x7000 + regionalOffset1] | (1 << entry[4]);
}
