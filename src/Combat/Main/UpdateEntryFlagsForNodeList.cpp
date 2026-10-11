#include <globaldefs.h>

#if defined(jpn)
enum { nodeListOffset = 0x8c };
#else
enum { nodeListOffset = 0x6c };
#endif

struct Owner02018b34;
struct Param02018b34;
struct Entry02018b34;

void* GetPointerFromArray0x3c(unsigned char* obj, unsigned int index);
struct Entry02018b34* FindEntryByNodeIdAndKey(struct Owner02018b34* owner, struct Param02018b34* p);

struct ListNode02018ab8 {
    char pad0[0x2e];
    unsigned short lowNibble2e : 4;
    unsigned short flags2e : 12;
    char pad30[0x40];
    struct ListNode02018ab8* next;
};

// USA: func_02018ab8
ARM void UpdateEntryFlagsForNodeList(unsigned char* obj) {
    struct ListNode02018ab8* node;
    struct Entry02018b34* entry;
    unsigned short* entryFlags;
    int hasFlag;

    node = (struct ListNode02018ab8*)GetPointerFromArray0x3c(obj + nodeListOffset, 2);
    while (node != NULL) {
        entry = FindEntryByNodeIdAndKey((struct Owner02018b34*)obj, (struct Param02018b34*)node);
        hasFlag = (node->flags2e & 0x80) != 0;
        if (entry != NULL) {
            entryFlags = (unsigned short*)((char*)entry + 2);
            *entryFlags |= 0x8;
            if (hasFlag) *entryFlags |= 0x10;
        }
        node = node->next;
    }
}
