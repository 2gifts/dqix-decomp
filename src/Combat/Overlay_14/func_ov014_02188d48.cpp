#include <globaldefs.h>
#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"

struct NatEntry {
    unsigned short key_;
    unsigned short groupIndex_ : 12;
    unsigned short numGroups_ : 4;
};

struct NatGroup {
    unsigned short pointerIndex_;
    unsigned short flag_ : 1;
    unsigned short firstIndex_ : 11;
    unsigned short numIndices_ : 4;
};

struct NatTable {
    unsigned short numEntries_;
    unsigned short numGroups_;
    unsigned short numIndices_;
    unsigned short numPointers_;
    unsigned int dataSize_ : 31;
    unsigned int relocated_ : 1;
    NatEntry* entries_;
    char* data_;
};

struct HabitatTable : public NatTable {
    short monsterID_;
    short state_;
    int taskID_;
    SafeAllocator* allocator_;
};

struct S02189244;
struct Obj_0201bb78;

extern "C" unsigned int func_ov014_0218934c(NatTable* table);
extern "C" bool func_ov014_02188b20(NatTable* table, bool alreadyRelocated);
extern "C" void _Z28InitEntryFromSource_02189244P9S02189244S0_Pci(S02189244* table, S02189244* file, char* alreadyRelocated, int func);
extern "C" int func_ov014_02188b18(NatEntry* entry);
extern "C" NatEntry* func_ov014_021892d4(NatTable* table, int key, int (*getKey)(NatEntry* entry));
extern "C" char* func_ov014_02188ba0(NatTable* table, char* pointer, char* defaultValue);
extern "C" char* func_0205ec34();
bool TestBitInByteArray(int, unsigned char*, int flag);
extern "C" void* func_02012fe4();
extern "C" char* _Z26AllocateStringCopy020da150P13SafeAllocatorPKc(SafeAllocator* allocator, const char* string);
extern "C" bool _Z17IsInRange0201b588i(int zoneID);
extern "C" bool _Z31LookupBitFromValueRange0201bb78P12Obj_0201bb78j(Obj_0201bb78* zoneStruct, unsigned int zoneID);

// USA: func_ov014_02188d48
extern "C" ARM bool func_ov014_02188d48(HabitatTable* self, SafeAllocator* allocator, void* file, unsigned int fileSize, short monsterID) {
    if (allocator == NULL || file == NULL || fileSize == 0)
        return false;

    if (monsterID < 0) {
        if (allocator != NULL && file != NULL) {
            unsigned int tablesSize;
            unsigned int dataSize;

            memcpy(self, file, 0xc);
            tablesSize = func_ov014_0218934c(self);
            dataSize = self->dataSize_;
            if (tablesSize != 0)
                self->entries_ = (NatEntry*)allocator->Allocate(tablesSize);
            else
                self->entries_ = NULL;
            if (dataSize != 0)
                self->data_ = (char*)allocator->Allocate(dataSize);
            else
                self->data_ = NULL;
            if (self->entries_ != NULL)
                memcpy(self->entries_, (char*)file + 0xc, tablesSize);
            if (self->data_ != NULL)
                memcpy(self->data_, (char*)file + (func_ov014_0218934c(self) + 0xc), dataSize);
            self->relocated_ = true;
        }
        func_ov014_02188b20(self, false);
    } else {
        NatTable source;
        bool alreadyRelocated;
        NatEntry* entry;

        memset(&source, 0, sizeof(source));
        _Z28InitEntryFromSource_02189244P9S02189244S0_Pci((S02189244*)&source, (S02189244*)file, (char*)&alreadyRelocated, NULL);
        entry = func_ov014_021892d4(&source, monsterID, func_ov014_02188b18);
        if (entry != NULL) {
            char* flags;
            bool grottosKnown;
            void* zoneStruct;
            NatGroup* groups;
            unsigned short* indices;
            char** pointers;
            int numGroups;
            int numIndices;
            NatGroup* entryGroups;
            NatGroup* entryGroup;
            NatTable table;
            char* buffer;

            flags = func_0205ec34();
            grottosKnown = TestBitInByteArray((int)flags, (unsigned char*)(flags + 0x8c), 0x79d) != false;
            zoneStruct = func_02012fe4();

            groups = (NatGroup*)(source.entries_ + source.numEntries_);
            indices = (unsigned short*)(groups + source.numGroups_);
            pointers = (char**)((char*)source.entries_ + (((char*)(indices + source.numIndices_) - (char*)source.entries_ + 3) & ~3));
            numGroups = entry->numGroups_;
            entryGroups = groups + entry->groupIndex_;
            numIndices = 0;
            entryGroup = entryGroups;
            for (int i = 0; i < numGroups; i++, entryGroup++)
                numIndices += entryGroup->numIndices_;

            table.numEntries_ = 1;
            table.numGroups_ = numGroups;
            table.numIndices_ = numIndices;
            table.numPointers_ = numGroups;
            table.dataSize_ = 0;
            buffer = (char*)allocator->Allocate(func_ov014_0218934c(&table));
            table.entries_ = (NatEntry*)buffer;
            table.data_ = NULL;
            if (buffer != NULL) {
                NatGroup* newGroups;
                unsigned short* newIndices;
                NatGroup* group;
                int indexTotal;
                int count;
                int pointerIndex;
                unsigned short* zoneID;
                char** newPointers;
                bool swapped;

                newGroups = (NatGroup*)(buffer + sizeof(NatEntry));
                newIndices = (unsigned short*)(newGroups + numGroups);
                newPointers = (char**)(buffer + (((char*)(newIndices + numIndices) - buffer + 3) & ~3));
                memcpy(buffer, entry, sizeof(NatEntry));
                memcpy(newGroups, entryGroups, numGroups * sizeof(NatGroup));
                group = newGroups;
                ((NatEntry*)buffer)->groupIndex_ = 0;

                indexTotal = 0;
                pointerIndex = 0;
                for (int i = 0; i < numGroups; i++) {
                    bool known;

                    count = group->numIndices_;
                    memcpy(newIndices, indices + group->firstIndex_, count * sizeof(unsigned short));
                    memcpy(newPointers, pointers + group->pointerIndex_, sizeof(char*));
                    group->pointerIndex_ = pointerIndex;
                    group->firstIndex_ = indexTotal;
                    *newPointers = _Z26AllocateStringCopy020da150P13SafeAllocatorPKc(allocator, func_ov014_02188ba0(&source, *newPointers, NULL));

                    known = count == 0;
                    zoneID = newIndices;
                    for (int j = 0; j < count; j++, zoneID++) {
                        known = (_Z17IsInRange0201b588i(*zoneID) && grottosKnown) || _Z31LookupBitFromValueRange0201bb78P12Obj_0201bb78j((Obj_0201bb78*)zoneStruct, *zoneID);
                        if (known)
                            break;
                    }
                    group->flag_ = known;

                    newIndices += count;
                    newPointers++;
                    indexTotal += count;
                    group++;
                    pointerIndex++;
                }

                do {
                    swapped = false;
                    group = newGroups;
                    for (int i = 0; i < numGroups - 1; i++, group++) {
                        if (!group[0].flag_ && group[1].flag_) {
                            NatGroup temp;
                            memcpy(&temp, &group[0], sizeof(NatGroup));
                            memcpy(&group[0], &group[1], sizeof(NatGroup));
                            memcpy(&group[1], &temp, sizeof(NatGroup));
                            swapped = true;
                        }
                    }
                } while (swapped);
            } else {
                table.numEntries_ = 0;
                table.numGroups_ = 0;
                table.numIndices_ = 0;
                table.numPointers_ = 0;
            }
            memcpy(self, &table, sizeof(NatTable));
        }
    }
    return true;
}
