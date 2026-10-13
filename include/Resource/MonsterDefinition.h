#pragma once

class SafeAllocator;



struct MonsterDefinition {
    union { char* name; unsigned int nameOffset; };
    union { char* modelName; unsigned int modelNameOffset; };
    short monsterId;
    unsigned short unknownA;
    short radius;
    short height;
    unsigned int unknown10;
#if !defined(jpn)
    union { char* localizedText; unsigned int localizedTextOffset; };
    int unknown18;
#endif
};

struct Header0206f0f8 {
    unsigned int count : 12;
    unsigned int stringBytes : 19;
    unsigned int relocated : 1;
};


struct BinarySearchByComparatorStruct {
    Header0206f0f8 header;
    MonsterDefinition* arr;
};

struct List0206f170 {
    BinarySearchByComparatorStruct table;
    char* strings;
};

struct Src0206f170 {
    Header0206f0f8 header;

};

typedef char MonsterDefinitionSize[(sizeof(MonsterDefinition) ==
#if defined(jpn)
    20
#else
    28
#endif
) ? 1 : -1];
typedef char MonsterTableSize[(sizeof(List0206f170) == 12) ? 1 : -1];

typedef int (*MonsterDefinitionVisitor)(List0206f170*, MonsterDefinition*);
typedef int (*BinarySearchByComparatorFn)(void*);

#if defined(jpn)
#define GetEntryArrayByteSize func_02070248
#define InvokeCallbackForEachEntry func_02070260
#define InitEntryListFromSource0206f170 func_020702c0
#define BinarySearchByComparator func_02070530
#define RelocateThreeFields func_020700ac
#define func_0206ef94 func_020700e4
extern "C" {
#endif
int GetEntryArrayByteSize(Header0206f0f8*);
int InvokeCallbackForEachEntry(List0206f170*, MonsterDefinitionVisitor);
int InitEntryListFromSource0206f170(List0206f170*, Src0206f170*, unsigned char*, MonsterDefinitionVisitor);
void* BinarySearchByComparator(BinarySearchByComparatorStruct*, int, BinarySearchByComparatorFn);
int RelocateThreeFields(List0206f170*, MonsterDefinition*);
#if defined(jpn)
}
#endif




extern "C" char* func_0206ef94(List0206f170*, char*, char*);
extern "C" void func_0206f01c(List0206f170*, SafeAllocator*, Src0206f170*, unsigned int);
int GetShortAt0x8(void*);
