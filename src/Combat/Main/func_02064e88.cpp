#include <globaldefs.h>

#include "Memory/SafeAllocator.h"

#if defined(jpn)
#define func_02064e88 func_02066184
#define _Z19LookupTable020982a4ii func_02099ef4
#define data_020f0618 data_020f0680
#define data_020f061e data_020f0686
#define data_020f0624 data_020f068c
#define data_020f062a data_020f0692
#define data_020f0630 data_020f0698
#define data_020f0636 data_020f069e
#define data_020f063c data_020f06a4
#define data_020f0642 data_020f06aa
#define data_020f0648 data_020f06b0
#define data_020f064e data_020f06b6
#define data_020f0654 data_020f06bc
#define data_020f065a data_020f06c2
#define data_020f0660 data_020f06c8
#define data_020f0666 data_020f06ce
#define data_020f066c data_020f06d4
#define data_020f0672 data_020f06da
#define data_020f0678 data_020f06e0
#define data_020f067e data_020f06e6
#define data_020f0684 data_020f06ec
#define data_020f068a data_020f06f2
#define data_020f0690 data_020f06f8
#define data_020f0696 data_020f06fe
#define data_020f069c data_020f0704
#define data_020f06a2 data_020f070a
#define data_020f06a8 data_020f0710
#define data_020f06ae data_020f0716
#define data_020f06b4 data_020f071c
#define data_020f06ba data_020f0722
enum { kResourceOffset = 0x860 };
extern "C" char* strcpy(char*, const char*);
#else
enum { kResourceOffset = 0x840 };
#endif

struct Elem020984b0;

struct Entry020984dc {
    unsigned char pad0[0xc];
    unsigned int kind : 4;
    unsigned int unk4 : 20;
    unsigned int slotId : 6;
    unsigned int isRare : 1;
    unsigned int unk31 : 1;
    unsigned char pad10[0x2e - 0x10];
    unsigned char isNamed : 1;
    unsigned char pad2e : 7;
    unsigned char pad2f[0xe8 - 0x2f];
};

struct LabelNode02064e88 {
    unsigned short id;
    unsigned char rareFlag;
    unsigned char namedFlag;
#if defined(jpn)
    char firstName[0xc];
#endif
    char label[0xc];
    struct LabelNode02064e88* next;
};

extern "C" unsigned short* func_02012fe4(void);
int GetTableValueMod100(int, int);
extern "C" int _Z19LookupTable020982a4ii(int, int);
void ClearField0xcBits24To29(struct Elem020984b0*);
extern "C" int _Z28CollectEntriesByType020984dcP13Entry020984dciPS0_(struct Entry020984dc*, int, struct Entry020984dc**);
void* FindNodeByByteId(void*, int);
extern "C" void __clear(void* buf, int size);
extern "C" void func_02042764(struct Entry020984dc* entry, void* buf, int flag);
extern "C" int sprintf(char* dst, const char* fmt, ...);

extern char data_020f0618[];
extern char data_020f061e[];
extern char data_020f0624[];
extern char data_020f062a[];
extern char data_020f0630[];
extern char data_020f0636[];
extern char data_020f063c[];
extern char data_020f0642[];
extern char data_020f0648[];
extern char data_020f064e[];
extern char data_020f0654[];
extern char data_020f065a[];
extern char data_020f0660[];
extern char data_020f0666[];
extern char data_020f066c[];
extern char data_020f0672[];
extern char data_020f0678[];
extern char data_020f067e[];
extern char data_020f0684[];
extern char data_020f068a[];
extern char data_020f0690[];
extern char data_020f0696[];
extern char data_020f069c[];
extern char data_020f06a2[];
extern char data_020f06a8[];
extern char data_020f06ae[];
extern char data_020f06b4[];
extern char data_020f06ba[];

// USA: func_02064e88
extern "C" ARM int func_02064e88(struct LabelNode02064e88** head, void* nodeDb, SafeAllocator* allocator) {
    unsigned short* global;
    int zone;
    int base;
    int count;
    int i;
    int id;
    struct LabelNode02064e88* node;
    struct Entry020984dc* entries[10];
#if !defined(jpn)
    char buf[0x30];
#endif

    global = func_02012fe4();
    zone = *global;
    base = _Z19LookupTable020982a4ii((int)((char*)global + kResourceOffset),
                               GetTableValueMod100((int)((char*)global + kResourceOffset), zone));
    ClearField0xcBits24To29((struct Elem020984b0*)((char*)global + kResourceOffset));
    count = _Z28CollectEntriesByType020984dcP13Entry020984dciPS0_((struct Entry020984dc*)((char*)global + kResourceOffset),
                                         GetTableValueMod100((int)((char*)global + kResourceOffset), zone), entries);
    for (i = 0; i < count; i++) {
        id = i + 1 + base;
        if (FindNodeByByteId(nodeDb, id) == 0) {
            continue;
        }
        node = (struct LabelNode02064e88*)allocator->Allocate(sizeof(LabelNode02064e88));
        if (node == 0) {
            break;
        }
        node->id = id;
        node->rareFlag = entries[i]->isRare ? 4 : 0;
#if defined(jpn)
        strcpy(node->firstName, (const char*)entries[i]);
#else
        __clear(buf, 0x30);
        func_02042764(entries[i], buf, 1);
#endif
        if (entries[i]->isNamed == 0) {
            switch (entries[i]->kind) {
            case 0: sprintf(node->label, data_020f0618); break;
            case 1: sprintf(node->label, data_020f061e); break;
            case 2: sprintf(node->label, data_020f0624); break;
            case 3: sprintf(node->label, data_020f062a); break;
            case 4: sprintf(node->label, data_020f0630); break;
            case 5: sprintf(node->label, data_020f0636); break;
            case 6: sprintf(node->label, data_020f063c); break;
            case 7: sprintf(node->label, data_020f0642); break;
            case 8: sprintf(node->label, data_020f0648); break;
            case 9: sprintf(node->label, data_020f064e); break;
            case 10: sprintf(node->label, data_020f0654); break;
            case 11: sprintf(node->label, data_020f065a); break;
            case 12: sprintf(node->label, data_020f0660); break;
            default: sprintf(node->label, data_020f0666); break;
            }
        } else {
            switch (entries[i]->kind) {
            case 0: sprintf(node->label, data_020f066c); break;
            case 1: sprintf(node->label, data_020f0672); break;
            case 2: sprintf(node->label, data_020f0678); break;
            case 3: sprintf(node->label, data_020f067e); break;
            case 4: sprintf(node->label, data_020f0684); break;
            case 5: sprintf(node->label, data_020f068a); break;
            case 6: sprintf(node->label, data_020f0690); break;
            case 7: sprintf(node->label, data_020f0696); break;
            case 8: sprintf(node->label, data_020f069c); break;
            case 9: sprintf(node->label, data_020f06a2); break;
            case 10: sprintf(node->label, data_020f06a8); break;
            case 11: sprintf(node->label, data_020f06ae); break;
            case 12: sprintf(node->label, data_020f06b4); break;
            default: sprintf(node->label, data_020f06ba); break;
            }
        }
        node->namedFlag = entries[i]->isNamed == 0 ? 0 : 2;
        entries[i]->slotId = id;
        node->next = *head;
        *head = node;
    }
    return count;
}
