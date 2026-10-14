#include <globaldefs.h>
#include "std_library_functions.h"

struct EntryA68 { short key; void* value; };
struct TableA68 { struct EntryA68* entries; short count; };
ARM void* FindEntryByKey_02072a68(struct TableA68* table, int key);

struct Flags0208166c {
    unsigned char loNibble : 4;
    unsigned char hiNibble : 4;
};
struct Flags14_0208166c {
    unsigned char f14lo : 2;
    unsigned char f14pad : 6;
};

ARM int IsValueEqual12_02042190(int x);
ARM int GetGlobalField0x1c020421a0(void);

extern "C" int func_020420e8(void* p, int flag);
extern "C" int func_02046608(int a, int b, void* c, void* d, int e, int f, int g);
extern "C" int func_0204f41c(void* target, int a, int b, void* c, int d, int e, void* f, void* g, int h);

#define F13(e) ((struct Flags0208166c*)((e) + 0x13))
#define F14(e) ((struct Flags14_0208166c*)((e) + 0x14))

// USA: func_0208166c
ARM void ApplyEntryToTarget0208166c(void* holderRaw, void* targetRaw, void* entryRaw) {
    char* holder = (char*)holderRaw;
    char* target = (char*)targetRaw;
    char* entry = (char*)entryRaw;

    int hiNibbleOrFive = F13(entry)->hiNibble;
    if (*(unsigned char*)(entry + 0x2a) & 0x4) {
        hiNibbleOrFive = 5;
    }

    int boolResult = IsValueEqual12_02042190(F13(entry)->loNibble);

    void* found = FindEntryByKey_02072a68((struct TableA68*)*(void**)(holder + 0x0), *(short*)(entry + 0xe));
    if (found) {
        if (*(unsigned char*)(entry + 0x2a) & 0x8) {
            int scaled = *(short*)(target + 0xa8) << 0x13;
            int adj = func_020420e8(found, boolResult);
            int val = (int)((unsigned int)((scaled >> 0x10) - adj) << 0x10) >> 0x11;
            *(short*)(entry + 0x6) = (short)val;
        }
    }

    int loNibble = F13(entry)->loNibble;
    *(short*)(target + 0xb4) = (short)loNibble;
    *(short*)(target + 0xb6) = (short)(loNibble + 1);

    if (*(unsigned char*)(entry + 0x2a) & 0x10) {
        int loNibble2 = F13(entry)->loNibble;
        if (loNibble2 == 0xc) {
            *(short*)(target + 0xb4) = (short)loNibble2;
            *(short*)(target + 0xb6) = 0x14;
        }
    }

    int r4 = 0;
    if (F14(entry)->f14lo) {
        r4 = func_020420e8(found, 0);
    }

    void* dataPtr = found;
    if (*(unsigned char*)(entry + 0x2a) & 0x20) {
        int g = GetGlobalField0x1c020421a0();
        memset(*(void**)(holder + 0x18), 0, 0x960);
        func_02046608(g, F13(entry)->loNibble, found, *(void**)(holder + 0x18), *(unsigned char*)(entry + 0x2b), 0, 0);
        dataPtr = *(void**)(holder + 0x18);
        unsigned char f2c = *(unsigned char*)(entry + 0x2c);
        *(short*)(target + 0xb4) = (short)F13(entry)->loNibble;
        *(short*)(target + 0xb6) = f2c;
    }

    short v6 = *(short*)(entry + 0x6);
    short v28 = *(short*)(entry + 0x28);
    short v8 = *(short*)(entry + 0x8);
    int arg1 = (short)(v6 + v28 - r4);
    func_0204f41c(target, arg1, v8, dataPtr, F13(entry)->loNibble, hiNibbleOrFive, entry + 0xa, entry + 0xc, 0);
}
