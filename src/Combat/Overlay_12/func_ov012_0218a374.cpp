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
void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);
void SetByteInRange_020465f0(unsigned char* base, int index, unsigned char value);
void SetByteAtIndex_020465d8(unsigned char* base, int index, unsigned char value);
int AppendSizeTag_02041d9c(char* dst, int size);
void* FindEntryByKey_02072a68(struct TableA68* table, int key);
int AppendNameTag_02041b70(char* dst, int n, const char* name);
extern "C" int func_020420e8(char* str, int id);
int AppendXYTag_02041a90(char* dst, int x, int y);
int AppendString02042058(char* dst, const char* src);
#if defined(jpn)
extern "C" void func_02042428(char* dst, int size);
#endif

// USA: func_ov012_0218a374
extern "C" ARM void func_ov012_0218a374(unsigned char* self, char* dst) {
    if (dst == 0) return;

    struct StoreStruct* base = (struct StoreStruct*)GetGlobalField0x1c020421a0();
#if defined(jpn)
    StoreInArray0x8b0_020465c0(base, 0, *(unsigned short*)(self + 0x1454));
    SetByteInRange_020465f0((unsigned char*)base, 0, 4);
    SetByteAtIndex_020465d8((unsigned char*)base, 0, 1);
    func_02042428(dst, 0xc);
    if (self[0x1341] == 7) {
        void* name = FindEntryByKey_02072a68((struct TableA68*)(self + 0x1314), 0x67);
        AppendNameTag_02041b70(dst, 0, (const char*)name);
    } else {
        void* name = FindEntryByKey_02072a68((struct TableA68*)(self + 0x1314), 0x64);
        AppendNameTag_02041b70(dst, 0, (const char*)name);
    }
#else
    StoreInArray0x8b0_020465c0(base, 0, self[0x13ff]);
    SetByteInRange_020465f0((unsigned char*)base, 0, 2);
    SetByteAtIndex_020465d8((unsigned char*)base, 0, 1);

    AppendSizeTag_02041d9c(dst, 0xc);

    int key = 0x66;
    if (self[0x1371] == 9) key = 0x69;
    void* name = FindEntryByKey_02072a68((struct TableA68*)(self + 0x133c), key);
    AppendNameTag_02041b70(dst, 0, (const char*)name);

    void* str = FindEntryByKey_02072a68((struct TableA68*)(self + 0x133c), 0x28);
    int len = func_020420e8((char*)str, 0);
    AppendXYTag_02041a90(dst, (0x48 - len) >> 1, 1);
    AppendString02042058(dst, (const char*)str);
#endif
}
