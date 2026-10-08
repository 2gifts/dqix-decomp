#include "Graphics/NSBXX/NSBXX.h"

static inline unsigned int GetNameListEntryCount(const NSBXXNameList *list) {
    return list->numEntries_;
}

// USA: func_020b736c
extern "C" ARM void *NSBXXNameList_Search(NSBXXNameList *nameList, const char *name) {
    const uint32_t *targetWords = (const uint32_t *) name;
    if (name == NULL) return NULL;

    unsigned int numEntries = nameList->numEntries_;
    if (numEntries < 16) // Small dictionaries use a linear name scan.
    {
        unsigned int searchIndex = 0;
        uint32_t target0         = targetWords[0];
        uint32_t target1         = targetWords[1];
        uint32_t target2         = targetWords[2];
        uint32_t target3         = targetWords[3];

        if (numEntries > searchIndex) {
            int nameByteOffset = 0;
            do {
                intptr_t nameAddress;
                if (nameList != NULL && searchIndex < GetNameListEntryCount(nameList)) {
                    intptr_t dataStart = (intptr_t) nameList + nameList->offsetToDataStart_;
                    // The data subheader stores the byte offset to the name table.
                    nameAddress = dataStart + *(uint16_t *) (dataStart + 2);
                    nameAddress += nameByteOffset;
                } else
                    nameAddress = 0;

                // Resource names are fixed 16-byte buffers, compared as four words.
                const uint32_t *source = (const uint32_t *) nameAddress;
                if (source[0] == target0 && source[1] == target1 && source[2] == target2 && source[3] == target3) {
                    if (nameList != NULL && searchIndex < nameList->numEntries_) {
                        intptr_t dataStart = (intptr_t) nameList + nameList->offsetToDataStart_;
                        int stride         = *(uint16_t *) dataStart;
                        return (void *) (dataStart + 4 + stride * searchIndex);
                    }
                    return NULL;
                }

                searchIndex++;
                nameByteOffset += 16;
            } while (searchIndex < GetNameListEntryCount(nameList));
        }
    } else // Larger dictionaries use their Patricia search tree.
    {
        NSBXXNameList::SearchTreeEntry *treeEntries = (NSBXXNameList::SearchTreeEntry *) &nameList->treeRoot_8_;
        int firstChild                              = treeEntries[0].children_[0];

        if (firstChild != 0) {
            NSBXXNameList::SearchTreeEntry *node = &treeEntries[firstChild];
            int bitIndex                         = treeEntries[firstChild].bitIndex_;
            unsigned int prevBitIndex            = treeEntries[0].bitIndex_;
            if (prevBitIndex > bitIndex) {
                do {

                    int wordIndex  = bitIndex >> 5;
                    int bitInWord  = bitIndex & 0x1f;
                    int bitValue   = (targetWords[wordIndex] >> bitInWord) & 1;
                    int childIndex = node->children_[bitValue];
                    prevBitIndex   = node->bitIndex_;
                    node           = &treeEntries[childIndex];
                    bitIndex       = treeEntries[childIndex].bitIndex_;

                } while (prevBitIndex > bitIndex);
            }

            unsigned int candidateIndex = node->resourceIndex_;
            intptr_t nameAddress;
            if (nameList != NULL && candidateIndex < numEntries) {
                intptr_t dataStart = (intptr_t) nameList + nameList->offsetToDataStart_;
                // The data subheader stores the byte offset to the name table.
                nameAddress = dataStart + *(uint16_t *) (dataStart + 2) + (candidateIndex * 16);
            } else
                nameAddress = 0;

            const uint32_t *candidateWords = (const uint32_t *) nameAddress;
            if (candidateWords[0] == targetWords[0] && candidateWords[1] == targetWords[1] &&
                candidateWords[2] == targetWords[2] && candidateWords[3] == targetWords[3])
            {
                if (nameList != NULL && candidateIndex < numEntries) {
                    intptr_t dataStart = (intptr_t) nameList + nameList->offsetToDataStart_;
                    int stride         = *(uint16_t *) dataStart;
                    return (void *) (dataStart + 4 + stride * candidateIndex);
                }
                return NULL;
            }
        }
    }

    return NULL;
}

// USA: func_020b752c
ARM int NSBXXNameList_SearchIndex(NSBXXNameList *nameList, const char *name) {
    const uint32_t *targetIntArray = (const uint32_t *) name;
    if (name == NULL) return -1;

    unsigned int numEntries = nameList->numEntries_;
    if (numEntries < 16) // Small dictionaries use a linear name scan.
    {
        unsigned int searchIndex = 0;
        uint32_t target0         = targetIntArray[0];
        uint32_t target1         = targetIntArray[1];
        uint32_t target2         = targetIntArray[2];
        uint32_t target3         = targetIntArray[3];
        if (numEntries > searchIndex) {
            int offsetWithinNameData = 0;
            do {
                intptr_t sourcePtr;
                if (nameList != NULL && searchIndex < GetNameListEntryCount(nameList)) {
                    intptr_t dataStart = (intptr_t) nameList + nameList->offsetToDataStart_;
                    // The data subheader stores the byte offset to the name table.
                    sourcePtr = dataStart + *(uint16_t *) (dataStart + 2);
                    sourcePtr += offsetWithinNameData;
                } else
                    sourcePtr = 0;

                // Resource names are fixed 16-byte buffers, compared as four words.
                const uint32_t *source = (const uint32_t *) sourcePtr;
                if (source[0] == target0 && source[1] == target1 && source[2] == target2 && source[3] == target3)
                    return searchIndex;

                searchIndex++;
                offsetWithinNameData += 16;
            } while (searchIndex < GetNameListEntryCount(nameList));
        }
    } else // Larger dictionaries use their Patricia search tree.
    {
        NSBXXNameList::SearchTreeEntry *entryArray = &nameList->treeRoot_8_;
        int firstChild                             = entryArray[0].children_[0];
        if (firstChild != 0) {
            NSBXXNameList::SearchTreeEntry *searchCursor = &entryArray[firstChild];
            int bitIndex                                 = entryArray[firstChild].bitIndex_;
            unsigned int prevBitIndex                    = entryArray[0].bitIndex_;
            if (prevBitIndex > bitIndex) {
                do {
                    int integerToQuery = bitIndex >> 5;
                    int bitToQuery     = bitIndex & 0x1f;
                    int bitValue       = (targetIntArray[integerToQuery] >> bitToQuery) & 1;
                    int childID        = searchCursor->children_[bitValue];
                    prevBitIndex       = searchCursor->bitIndex_;
                    searchCursor       = &entryArray[childID];
                    bitIndex           = entryArray[childID].bitIndex_;

                } while (prevBitIndex > bitIndex);
            }

            unsigned int candidateIndex = searchCursor->resourceIndex_;
            intptr_t sourcePtr;
            if (nameList != NULL && candidateIndex < nameList->numEntries_) {
                intptr_t dataStart = (intptr_t) nameList + nameList->offsetToDataStart_;
                // The data subheader stores the byte offset to the name table.
                sourcePtr = dataStart + *(uint16_t *) (dataStart + 2) + (candidateIndex * 16);
            } else
                sourcePtr = 0;

            const uint32_t *sourceIntArray = (const uint32_t *) sourcePtr;
            if (sourceIntArray[0] == targetIntArray[0] && sourceIntArray[1] == targetIntArray[1] &&
                sourceIntArray[2] == targetIntArray[2] && sourceIntArray[3] == targetIntArray[3])
                return searchCursor->resourceIndex_;
        }
    }

    return -1;
}
