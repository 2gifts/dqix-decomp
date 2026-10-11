// JPN: func_ov017_0219a128
#if defined(jpn)
enum { RegionOffset4448 = 0x4198, RegionOffset4444 = 0x4194, RegionOffset4449 = 0x4199, RegionOffset4445 = 0x4195 };
#else
enum { RegionOffset4448 = 0x4448, RegionOffset4444 = 0x4444, RegionOffset4449 = 0x4449, RegionOffset4445 = 0x4445 };
#endif

#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
extern "C" void func_0202c288(void* obj);
extern "C" void* func_0205ec34(void);
int LookupAndForEachNode020649b0(void* a, int mode, void* c);
extern "C" void func_0206f81c(void* p);
void ResetFieldGroup4444_0218b664(char* base);

struct SearchStruct0202c1a4 {
    char pad[0x100d];
    unsigned char entryLimit;
};

struct LocalBuf02199578 { char pad[0x34]; };

// USA: func_ov017_02199578  (semantic: TrackSearchLimitAndDispatch_02199578)
#pragma opt_common_subs off
extern "C" ARM void func_ov017_02199578(void* obj, int unused1, int matchType, int unused2, signed char flag) {
    struct SearchStruct0202c1a4* search = (struct SearchStruct0202c1a4*)func_0202ae18();
    signed char arrEntry = GetSearchStructCurrentArrEntry(search);
    if (matchType != arrEntry && matchType != 4) return;

    if (!*((unsigned char*)obj + RegionOffset4448)) return;

    func_0202c288(search);

    int cnt = *((unsigned char*)obj + RegionOffset4444) + 1;
    *((unsigned char*)obj + RegionOffset4444) = (unsigned char)cnt;
    if ((cnt & 0xff) >= search->entryLimit - 1) *((unsigned char*)obj + RegionOffset4448) = 0;

    if (!flag) {
        *((unsigned char*)obj + RegionOffset4449) = 0;
        void* list = func_0205ec34();
        LocalBuf02199578 c;
        if (LookupAndForEachNode020649b0(list, 0x1d, &c)) {
            func_0206f81c(&c);
        }
        ResetFieldGroup4444_0218b664((char*)obj);
        return;
    }

    int cnt2 = *((unsigned char*)obj + RegionOffset4445) + 1;
    *((unsigned char*)obj + RegionOffset4445) = (unsigned char)cnt2;
    if ((cnt2 & 0xff) < search->entryLimit - 1) return;

    *((unsigned char*)obj + RegionOffset4449) = 1;
    void* list2 = func_0205ec34();
    LocalBuf02199578 c2;
    if (LookupAndForEachNode020649b0(list2, 0x1d, &c2)) {
        func_0206f81c(&c2);
    }
    ResetFieldGroup4444_0218b664((char*)obj);
}
