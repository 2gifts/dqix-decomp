#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" int func_020bb7cc(unsigned int size, int a, int b);

extern unsigned short data_020e7a0c[];

struct ResItem {
    unsigned short a;
    unsigned short b;
    unsigned short width;
    unsigned short height;
    int size;
    char* data;
};

struct ResGroup {
    unsigned short a;
    unsigned short b;
    unsigned short itemCount;
    ResItem* items;
    unsigned int totalSize;
    char* data;
};

struct ResEntry {
    char* name;
    unsigned int count;
    void* listA;
    void* listB;
    void* listC;
};

struct ResHeader {
    int loaded;
    unsigned short type;
    unsigned short groupCount;
    ResGroup* groups;
    int tableCount;
    unsigned short* table;
    unsigned int tableShift;
    unsigned int entryCount;
    ResEntry* entries;
    unsigned int maxItems;
    unsigned int maxGroupSize;
};

// USA: func_0203fd5c
extern "C" ARM void func_0203fd5c(ResHeader* hdr, char* path, SafeAllocator* alloc, char* src) {
    char* end = path + strlen(path);
    if (end[-1] == 'r') {
        int off = 0;
        ResGroup* group;
        ResItem* item;
        unsigned int j;
        int i;
        unsigned int k;
        unsigned int count;
        int tableCount;
        unsigned int pos;
        char name[0x1e];

        memcpy(&hdr->groupCount, src + off, 2);
        memcpy(&hdr->type, src + (off + 2), 2);
        off += 4;
        hdr->groups = (ResGroup*)alloc->Allocate(hdr->groupCount * sizeof(ResGroup));
        i = 0;
        hdr->maxItems = 0;
        hdr->maxGroupSize = 0;
        group = hdr->groups;
        for (; i < hdr->groupCount; i++, group++) {
            memcpy(&group->a, src + off, 2);
            memcpy(&group->b, src + (off + 2), 2);
            memcpy(&count, src + (off + 4), 4);
            off += 8;
            group->itemCount = count;
            if (hdr->maxItems < count)
                hdr->maxItems = count;
            group->items = (ResItem*)alloc->Allocate(count * sizeof(ResItem));
            j = 0;
            group->totalSize = 0;
            item = group->items;
            for (; j < count; j++, item++) {
                memcpy(&item->a, src + off, 2);
                memcpy(&item->b, src + (off + 2), 2);
                memcpy(&item->width, src + (off + 4), 2);
                memcpy(&item->height, src + (off + 6), 2);
                off += 8;
                int size = data_020e7a0c[item->width] * data_020e7a0c[item->height];
                if (hdr->type == 3)
                    item->size = size / 2;
                else
                    item->size = size;
                item->data = src + off;
                off += item->size;
                group->totalSize += item->size;
            }
            if (hdr->maxGroupSize < group->totalSize)
                hdr->maxGroupSize = group->totalSize;
            group->data = (char*)alloc->Allocate(group->totalSize);
            j = 0;
            pos = 0;
            item = group->items;
            for (; j < count; j++, item++) {
                char* old = item->data;
                item->data = group->data + pos;
                memcpy(item->data, old, item->size);
                pos += item->size;
            }
        }

        memcpy(&tableCount, src + off, 4);
        off += 4;
        hdr->tableCount = tableCount;
        if (hdr->tableCount <= 0x10)
            hdr->tableCount = 0x10;
        else if (hdr->tableCount <= 0x100)
            hdr->tableCount = 0x100;
        hdr->tableShift = (unsigned short)func_020bb7cc(hdr->tableCount * 2, 0, 0) << 3;
        hdr->table = (unsigned short*)alloc->Allocate(hdr->tableCount * 2);
        memcpy(hdr->table, src + off, hdr->tableCount * 2);
        off += tableCount * 2;
        memcpy(&hdr->entryCount, src + (off + 0x1e), 4);
        off += 0x22;
        hdr->entries = (ResEntry*)alloc->Allocate(hdr->entryCount * sizeof(ResEntry));
        for (j = 0; j < hdr->entryCount; j++) {
            ResEntry* entry = &hdr->entries[j];
            memcpy(name, src + off, 0x1e);
            off += 0x1e;
            int len = strlen(name) + 1;
            if (len % 4 != 0)
                len = (len / 4 + 1) * 4;
            char* str = (char*)alloc->Allocate(len);
            entry->name = str;
            strcpy(str, name);
        }
        for (k = 0; k < hdr->entryCount; k++) {
            ResEntry* entry = &hdr->entries[k];
            memcpy(&entry->count, src + off, 4);
            unsigned int n = entry->count;
            unsigned int bytes = n * 4;
            off += 4;
            entry->listA = alloc->Allocate(bytes);
            entry->listB = alloc->Allocate(bytes);
            entry->listC = alloc->Allocate(bytes);
            memcpy(entry->listA, src + off, bytes);
            off += n * 4;
            memcpy(entry->listB, src + off, bytes);
            off += n * 4;
            memcpy(entry->listC, src + off, bytes);
            off += n * 4;
        }
        hdr->loaded = 1;
    }
}
