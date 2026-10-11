#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_0218a374 func_ov012_0218acd8
#endif

struct EntryA68 {
    short key;
    void* value;
};

struct TableA68 {
    struct EntryA68* entries;
    short count;
};

struct StoreStruct {
    char pad[0x8b0];
    int arr[0x10];
};

int GetGlobalField0x1c020421a0();
void StoreInArray0x8b0(struct StoreStruct* base, int index, int value);
void SetByteInRange(unsigned char* base, int index, unsigned char value);
void SetByteAtIndex(unsigned char* base, int index, unsigned char value);
int AppendSizeTag(char* dst, int size);
void* FindEntryByKey(struct TableA68* table, int key);
int AppendNameTag(char* dst, int n, const char* name);
extern "C" int func_020420e8(char* str, int id);
int AppendXYTag(char* dst, int x, int y);
int AppendString02042058(char* dst, const char* src);

// USA: func_ov012_0218a374
extern "C" ARM void func_ov012_0218a374(unsigned char* self, char* dst) {
    if (dst == 0) return;

    struct StoreStruct* base = (struct StoreStruct*)GetGlobalField0x1c020421a0();
    StoreInArray0x8b0(base, 0, self[0x13ff]);
    SetByteInRange((unsigned char*)base, 0, 2);
    SetByteAtIndex((unsigned char*)base, 0, 1);

    AppendSizeTag(dst, 0xc);

    int key = 0x66;
    if (self[0x1371] == 9) key = 0x69;
    void* name = FindEntryByKey((struct TableA68*)(self + 0x133c), key);
    AppendNameTag(dst, 0, (const char*)name);

    void* str = FindEntryByKey((struct TableA68*)(self + 0x133c), 0x28);
    int len = func_020420e8((char*)str, 0);
    AppendXYTag(dst, (0x48 - len) >> 1, 1);
    AppendString02042058(dst, (const char*)str);
}
