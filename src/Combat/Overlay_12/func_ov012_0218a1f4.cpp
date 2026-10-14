#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_0218a1f4 func_ov012_0218ae20
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

// USA: func_ov012_0218a1f4
extern "C" ARM void func_ov012_0218a1f4(unsigned char* self, char* dst) {
    if (dst == 0) return;

    struct StoreStruct* base = (struct StoreStruct*)GetGlobalField0x1c020421a0();
#if defined(jpn)
    StoreInArray0x8b0_020465c0(base, 0, self[0x1457]);
    SetByteInRange_020465f0((unsigned char*)base, 0, 2);
    SetByteAtIndex_020465d8((unsigned char*)base, 0, 1);
    func_02042428(dst, 0xc);
    if (self[0x1341] == 9) {
        void* name = FindEntryByKey_02072a68((struct TableA68*)(self + 0x1314), 0x69);
        AppendNameTag_02041b70(dst, 0, (const char*)name);
    } else {
        void* name = FindEntryByKey_02072a68((struct TableA68*)(self + 0x1314), 0x66);
        AppendNameTag_02041b70(dst, 0, (const char*)name);
    }
#else
    StoreInArray0x8b0_020465c0(base, 0, *(unsigned short*)(self + 0x13fc));
    SetByteInRange_020465f0((unsigned char*)base, 0, 4);
    SetByteAtIndex_020465d8((unsigned char*)base, 0, 1);

    AppendSizeTag_02041d9c(dst, 0xc);

    int key = 0x64;
    if (self[0x1371] == 7) key = 0x67;
    void* name = FindEntryByKey_02072a68((struct TableA68*)(self + 0x133c), key);
    AppendNameTag_02041b70(dst, 0, (const char*)name);

    void* str = FindEntryByKey_02072a68((struct TableA68*)(self + 0x133c), 0x2a);
    int len = func_020420e8((char*)str, 0);
    AppendXYTag_02041a90(dst, (0x60 - len) >> 1, 1);
    AppendString02042058(dst, (const char*)str);
#endif
}
