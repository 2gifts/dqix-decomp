#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct MonsterListEntry {
    MonsterListEntry* next_;
};

struct MonsterListScreen {
    char unk_0[0xb8];
    MonsterListEntry* entries_;
};

// USA: func_ov014_02187340
extern "C" ARM MonsterListEntry* func_ov014_02187340(MonsterListScreen* self, short page)
{
    MonsterListEntry* entry = self->entries_;
    int index = 0;
    MonsterListEntry* pageEntry = entry;
    short pageIndex = 0;
    for (; entry != NULL; entry = entry->next_)
    {
        if (index == 0)
        {
            pageEntry = entry;
            if (pageIndex == page)
                break;
            pageIndex++;
        }
        index = (short)(index + 1) % 16;
    }
    return pageEntry;
}
