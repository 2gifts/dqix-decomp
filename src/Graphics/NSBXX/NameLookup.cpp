#include "Graphics/NSBXX/NSBXX.h"

static inline unsigned int GetNameListEntryCount(const NSBXXNameList *list) {
    return list->numEntries_;
}

// Keys occupy 16 bytes, including zero padding; callers must supply the full
// buffer rather than only a terminated string. The tree path selects a candidate,
// so its name still needs the same four-word comparison as the linear path.
// USA: func_020b736c
extern "C" ARM void *NSBXXNameList_Search(NSBXXNameList *nameList, const char *paddedName) {
    const uint32_t *targetWords = (const uint32_t *) paddedName;
    if (paddedName == NULL) return NULL;

    unsigned int numEntries = nameList->numEntries_;
    if (numEntries < 16)
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
                    nameAddress = dataStart + *(uint16_t *) (dataStart + 2);
                    nameAddress += nameByteOffset;
                } else
                    nameAddress = 0;

                const uint32_t *entryNameWords = (const uint32_t *) nameAddress;
                if (entryNameWords[0] == target0 && entryNameWords[1] == target1 && entryNameWords[2] == target2 && entryNameWords[3] == target3) {
                    if (nameList != NULL && searchIndex < nameList->numEntries_) {
                        intptr_t dataStart = (intptr_t) nameList + nameList->offsetToDataStart_;
                        int entryStride         = *(uint16_t *) dataStart;
                        return (void *) (dataStart + 4 + entryStride * searchIndex);
                    }
                    return NULL;
                }

                searchIndex++;
                nameByteOffset += 16;
            } while (searchIndex < GetNameListEntryCount(nameList));
        }
    } else
    {
        NSBXXNameList::SearchTreeEntry *treeEntries = (NSBXXNameList::SearchTreeEntry *) &nameList->treeRoot_8_;
        int firstChildIndex                              = treeEntries[0].children_[0];

        if (firstChildIndex != 0) {
            NSBXXNameList::SearchTreeEntry *node = &treeEntries[firstChildIndex];
            int bitIndex                         = treeEntries[firstChildIndex].bitIndex_;
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
                nameAddress = dataStart + *(uint16_t *) (dataStart + 2) + (candidateIndex * 16);
            } else
                nameAddress = 0;

            const uint32_t *candidateWords = (const uint32_t *) nameAddress;
            if (candidateWords[0] == targetWords[0] && candidateWords[1] == targetWords[1] &&
                candidateWords[2] == targetWords[2] && candidateWords[3] == targetWords[3])
            {
                if (nameList != NULL && candidateIndex < numEntries) {
                    intptr_t dataStart = (intptr_t) nameList + nameList->offsetToDataStart_;
                    int entryStride         = *(uint16_t *) dataStart;
                    return (void *) (dataStart + 4 + entryStride * candidateIndex);
                }
                return NULL;
            }
        }
    }

    return NULL;
}

// Uses the same 16-byte, zero-padded key representation as the pointer lookup.
// Model3D::GetBoneIndex builds that buffer explicitly; material animation callers
// use the returned index to associate dictionary entries with their tracks.
// USA: func_020b752c
ARM int NSBXXNameList_SearchIndex(NSBXXNameList *nameList, const char *paddedName) {
    const uint32_t *targetWords = (const uint32_t *) paddedName;
    if (paddedName == NULL) return -1;

    unsigned int numEntries = nameList->numEntries_;
    if (numEntries < 16)
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
                    nameAddress = dataStart + *(uint16_t *) (dataStart + 2);
                    nameAddress += nameByteOffset;
                } else
                    nameAddress = 0;

                const uint32_t *entryNameWords = (const uint32_t *) nameAddress;
                if (entryNameWords[0] == target0 && entryNameWords[1] == target1 && entryNameWords[2] == target2 && entryNameWords[3] == target3)
                    return searchIndex;

                searchIndex++;
                nameByteOffset += 16;
            } while (searchIndex < GetNameListEntryCount(nameList));
        }
    } else
    {
        NSBXXNameList::SearchTreeEntry *treeEntries = &nameList->treeRoot_8_;
        int firstChildIndex                             = treeEntries[0].children_[0];
        if (firstChildIndex != 0) {
            NSBXXNameList::SearchTreeEntry *node = &treeEntries[firstChildIndex];
            int bitIndex                                 = treeEntries[firstChildIndex].bitIndex_;
            unsigned int prevBitIndex                    = treeEntries[0].bitIndex_;
            if (prevBitIndex > bitIndex) {
                do {
                    int wordIndex = bitIndex >> 5;
                    int bitInWord     = bitIndex & 0x1f;
                    int bitValue       = (targetWords[wordIndex] >> bitInWord) & 1;
                    int childIndex        = node->children_[bitValue];
                    prevBitIndex       = node->bitIndex_;
                    node       = &treeEntries[childIndex];
                    bitIndex           = treeEntries[childIndex].bitIndex_;

                } while (prevBitIndex > bitIndex);
            }

            unsigned int candidateIndex = node->resourceIndex_;
            intptr_t nameAddress;
            if (nameList != NULL && candidateIndex < nameList->numEntries_) {
                intptr_t dataStart = (intptr_t) nameList + nameList->offsetToDataStart_;
                nameAddress = dataStart + *(uint16_t *) (dataStart + 2) + (candidateIndex * 16);
            } else
                nameAddress = 0;

            const uint32_t *candidateWords = (const uint32_t *) nameAddress;
            if (candidateWords[0] == targetWords[0] && candidateWords[1] == targetWords[1] &&
                candidateWords[2] == targetWords[2] && candidateWords[3] == targetWords[3])
                return node->resourceIndex_;
        }
    }

    return -1;
}
