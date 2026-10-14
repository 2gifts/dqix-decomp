#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"

int GetGlobalField0x1c020421a0(void);

struct StoreStruct;
void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);
void SetByteAtIndex_020465d8(unsigned char* base, int index, unsigned char value);
void SetByteInRange_020465f0(unsigned char* base, int index, unsigned char value);

struct Container020e0310;
int GetFieldByKey020e0434(struct Container020e0310* c, int key);

extern "C" ARM void func_02046608(void* a, int b, void* c, void* d, int e, int f, int g);

struct Struct0200fb08;
ARM unsigned char NormalizeField5_0200fb08(Struct0200fb08* obj);

extern int data_ov023_021fd75c;
extern char data_ov023_021fddb0;
extern char data_ov023_021fddb4;

struct EntryTagData021e83c8 { char pad[0x38]; int a; int b; };

// USA: func_ov023_021e83c8  (semantic: FormatAndStoreEntryTags_021e83c8)
extern "C" ARM void func_ov023_021e83c8(void* obj) {
    int field = GetGlobalField0x1c020421a0();

    int* p_arr1;
    int i;
    int arr2[2];
    int arr1[2];
    arr2[0] = *(unsigned short*)((char*)obj + 0x60e);
    arr2[1] = *(unsigned char*)((char*)obj + 0x610);
    arr1[0] = *(int*)((char*)&data_ov023_021fd75c + 0x38);
    arr1[1] = *(int*)((char*)&data_ov023_021fd75c + 0x3c);

    p_arr1 = arr1;
    i = 0;
    for (; i < 2; i++) {
        StoreInArray0x8b0_020465c0((struct StoreStruct*)field, i, arr2[i]);
        SetByteAtIndex_020465d8((unsigned char*)field, i, 1);
        SetByteInRange_020465f0((unsigned char*)field, i, p_arr1[i] & 0xff);
    }

    int key = GetFieldByKey020e0434((struct Container020e0310*)((char*)obj + 0x4c), 0);
    func_02046608((void*)field, 0xa, (void*)key, *(void**)((char*)obj + 0x5d8), 0x100, 0, 0);

    int a, b;
    char* p1 = strstr(*(char**)((char*)obj + 0x5d8), &data_ov023_021fddb0);
    char* p2 = strstr(p1 + 1, &data_ov023_021fddb0);
    a = 0x82; b = 0xb4;
    int norm = NormalizeField5_0200fb08((struct Struct0200fb08*)GameState::GetInstance());
    switch (norm) {
    case 2:
    case 5:
        a = 0xa5; b = 0xc1;
        break;
    case 3:
        a = 0x92; b = 0xb6;
        break;
    }

    char buf1[4];
    char buf2[4];
    sprintf(buf1, &data_ov023_021fddb4, a);
    sprintf(buf2, &data_ov023_021fddb4, b);
    memcpy(p1 + 3, buf1, 3);
    memcpy(p2 + 3, buf2, 3);
}
