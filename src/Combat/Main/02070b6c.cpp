#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

union ListEntry02070b6c {
    struct Header {
        unsigned short id : 15;
        unsigned short flag : 1;
    } header;
    unsigned int data[33];
};

struct List02070b6c {
    unsigned int count : 12;
    unsigned int size : 19;
    unsigned int resolved : 1;
    ListEntry02070b6c* elements;
    void* extra;
};

struct Struct02070af4;
struct Container02070b0c;
struct Element02070b0c;
struct Container02070e60;
struct Element02070e60;
struct Element02070ee0;
struct Struct020709c8;
int GetListDataSize(Struct02070af4*);
int ForEachElement02070b0c(Container02070b0c*, void (*)(Container02070b0c*, Element02070b0c*));
Element02070e60* BinarySearch02070e60(Container02070e60*, int, int (*)(Element02070e60*));
Element02070ee0* CopyElement02070ee0(Element02070ee0*, Element02070ee0*);
int GetLow15BitField020709c8(Struct020709c8*);

// USA: func_02070b6c
extern "C" ARM void func_02070b6c(List02070b6c* self, SafeAllocator* allocator, List02070b6c* source, unsigned int sourceSize, short* ids, short countArg) {
    if (!allocator || !source || !sourceSize || !ids) return;
    if (countArg <= 0) return;
    memset(self, 0, sizeof(*self));
    List02070b6c list;
    memset(&list, 0, sizeof(list));
    if (source) {
        memcpy(&list, source, 4);
        list.elements = (ListEntry02070b6c*)((char*)source + 4);
        list.extra = (char*)source + (GetListDataSize((Struct02070af4*)&list) + 4);
        if (!list.resolved) {
            ForEachElement02070b0c((Container02070b0c*)&list, 0);
            list.resolved = 1;
            source->resolved = 1;
        }
    }
    short* id = ids;
    int foundCount = 0;
    for (int idCount = countArg, i = 0; i < idCount; i++, id++) {
        if (BinarySearch02070e60((Container02070e60*)&list, *id, (int (*)(Element02070e60*))GetLow15BitField020709c8)) foundCount++;
    }
    self->elements = (ListEntry02070b6c*)allocator->Allocate(foundCount * sizeof(ListEntry02070b6c));
    if (self->elements) {
        self->count = foundCount;
        ListEntry02070b6c* out;
        id = ids;
        out = self->elements;
        for (int copyIndex = 0; copyIndex < countArg; copyIndex++, id++) {
            ListEntry02070b6c* entry = (ListEntry02070b6c*)BinarySearch02070e60((Container02070e60*)&list, *id, (int (*)(Element02070e60*))GetLow15BitField020709c8);
            if (entry) {
                memcpy(out, entry, sizeof(*out));
                out++;
            }
        }
    }
    if (foundCount < 2) return;
    if (!self) return;
    int count = self->count;
    if (!self->elements || !count) return;
    int last = count - 1;
    ListEntry02070b6c* prev;
    int backSwap;
    int swapped;
    int first = 0;
    ListEntry02070b6c reverseTemp;
    ListEntry02070b6c forwardTemp;
    do {
        int pos = first;
        swapped = -1;
        ListEntry02070b6c* entry = &self->elements[first];
        for (; pos < last; entry++, pos++) {
            if (entry->header.id > entry[1].header.id) {
                swapped = pos;
                forwardTemp = *entry;
                CopyElement02070ee0((Element02070ee0*)entry, (Element02070ee0*)(entry + 1));
                CopyElement02070ee0((Element02070ee0*)(entry + 1), (Element02070ee0*)&forwardTemp);
            }
        }
        if (swapped == -1) break;
        ListEntry02070b6c* reverseEntry = &self->elements[swapped];
        last = swapped;
        backSwap = -1;
        for (; swapped > first; swapped--) {
            prev = reverseEntry - 1;
            if (prev->header.id > reverseEntry->header.id) {
                backSwap = swapped;
                reverseTemp = *reverseEntry;
                CopyElement02070ee0((Element02070ee0*)reverseEntry, (Element02070ee0*)prev);
                CopyElement02070ee0((Element02070ee0*)prev, (Element02070ee0*)&reverseTemp);
            }
            reverseEntry = prev;
        }
        if (backSwap != -1) first = backSwap;
        else break;
    } while (1);
}
