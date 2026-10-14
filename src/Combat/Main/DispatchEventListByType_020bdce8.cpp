#include <globaldefs.h>

struct EventEntry020bdce8 {
    unsigned char type;
    unsigned char key;
    unsigned short pad;
    int val;
};

struct EventList020bdce8 {
    unsigned int count;
    EventEntry020bdce8 entries[1];
};

EventList020bdce8* GetOffsetEntry0x1c_020bd710(int id);
extern "C" int func_020bddec(int val, int key, int argB, int flag, int* out);
int ResolveEntryValue020bde70(int val, int key, int argB, int flag, int* out);
extern "C" int func_020bded0(int val, int key, int argB, int flag, int* out);
int DispatchEventEntryForIndex_020be010(int, unsigned int, int, int, int*);

// USA: func_020bdce8  (semantic: DispatchEventListByType_020bdce8)
extern "C" ARM int func_020bdce8(int id, int argB) {
    EventList020bdce8* list = GetOffsetEntry0x1c_020bd710(id);
    if (list == 0) {
        return 1;
    }

    int* a = 0;
    int* b = 0;
    int* c = 0;
    int* d = 0;
    unsigned int i = 0;
    EventEntry020bdce8* entry;

    if (i < list->count) {
        entry = list->entries;
        do {
            int ret;
            switch (entry->type) {
            case 0:
                ret = func_020bddec(entry->val, entry->key, argB, 1, a);
                if (ret != 0) return ret;
                break;
            case 3:
                ret = ResolveEntryValue020bde70(entry->val, entry->key, argB, 1, b);
                if (ret != 0) return ret;
                break;
            case 1:
                ret = func_020bded0(entry->val, entry->key, argB, 1, c);
                if (ret != 0) return ret;
                break;
            case 2:
                ret = DispatchEventEntryForIndex_020be010(entry->val, entry->key, argB, 1, d);
                if (ret != 0) return ret;
                break;
            }
            entry++;
            i++;
        } while (i < list->count);
    }
    return 0;
}
