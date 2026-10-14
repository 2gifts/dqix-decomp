#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/GameResources.h"

void ClearNodeMaskById_021f6600(void* obj, int id, int mask);
void* GetDataPtr02114e04_020d6c00(void);
void OrBitsIntoField0_020466e4(unsigned int* p, unsigned int mask);
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);
extern "C" void func_ov023_021f65d4(void* obj, int a, int b);
int GetGlobalField0x1c020421a0(void);
int DispatchAdjustmentIfType4_02157018(void* a, int key);
extern "C" int func_020aad1c(void* loader, void* name, int a, int b);
extern "C" int func_ov004_0215b1d4(void* obj);
extern "C" void* func_02012fe4(void);
struct Actor0209c3b4;
void SetStateAndDispatch0209c3b4(struct Actor0209c3b4* actor, int val);
void SetModeClamped0209ca70(void* obj, int val);
void* GetOffsetPtrromField_021b1fc0_021b1fc0(void* obj);
struct Obj_02184534;
void SetFieldsB0B4_02184534(struct Obj_02184534* obj, int b0, int b4);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void func_0204500c(void* field, void* buf, int p2, int p3);

struct EntryA68 { short key; void* value; };
struct TableA68 { struct EntryA68* entries; short count; };
void* FindEntryByKey_02072a68(struct TableA68* table, int key);

struct Struct021707d8_0215c974 { char pad[8]; unsigned char* ptr; };
extern Struct021707d8_0215c974 data_ov004_021707d8;
extern char data_ov004_0217043e;
extern int data_0211e33c;
extern int data_02109bf4;

struct Bits7_0215c974 { unsigned char low7 : 7; unsigned char hi1 : 1; };

// USA: func_ov004_0215c974
extern "C" ARM int func_ov004_0215c974(void* obj) {
    void* data;
    bool queued;
    char* gs;
    int g;
    char* cur;
    struct TableA68* table;
    const char* head;
    int len;
    char* rec;
    char* base;
    int i;

    ClearNodeMaskById_021f6600(obj, 0x36, 8);

    data = GetDataPtr02114e04_020d6c00();
    OrBitsIntoField0_020466e4((unsigned int*)data, 0x80);

    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    queued = func_020aad1c(data_ov004_021707d8.ptr + 0x84, &data_0211e33c, 0xa, 0) != 0;
    BackgroundLoader::RemoveLockGlobal();
    if (!queued) return 1;

    ClearFlags020466f4((struct FlagWord020466f4*)data, 0x80);

    func_ov023_021f65d4(obj, 0x36, 8);

    g = GetGlobalField0x1c020421a0();
    cur = *(char**)((char*)g + 0x5c);
    memset(cur, 0, 0x960);

    gs = (char*)GameState::GetInstance() + 0x26c;
    table = (struct TableA68*)DispatchAdjustmentIfType4_02157018(obj, 4);

    head = (const char*)FindEntryByKey_02072a68(table, 0x21);
    len = strlen(head);
    memcpy(cur, head, len);
    cur += len;

    if (data_ov004_021707d8.ptr[0x15] != 0) {
        func_ov004_0215b1d4(obj);
        void* q = func_02012fe4();
        Bits7_0215c974* b = (Bits7_0215c974*)((char*)(*(void**)((char*)q + 8)) + 0xd);
        SetStateAndDispatch0209c3b4((struct Actor0209c3b4*)&data_02109bf4, b->low7);
        SetModeClamped0209ca70(&data_02109bf4, data_ov004_021707d8.ptr[0x2d]);
    } else if (data_ov004_021707d8.ptr[0x14] != 0) {
        void* raw = func_ov017_0218b5b0();
        void* five = *(void**)((char*)raw + 0x3000 + 0xb48);
        rec = (char*)GetOffsetPtrromField_021b1fc0_021b1fc0(five);
        base = *(char**)((char*)five + 0x34);

        for (i = 0; i < 4; i++) {
            if (strstr((char*)rec + 0x88, &data_ov004_0217043e)) {
                SetFieldsB0B4_02184534((struct Obj_02184534*)obj, (int)base, *(int*)((char*)rec + 0xac));
                break;
            }
            base += *(int*)((char*)rec + 0xac);
            rec += 0xb0;
        }

        if (i != 4) {
            func_ov011_021848a0(obj, 0x394);
        } else {
            func_ov011_021848a0(obj, 0x3ad);
        }

        int flags = *(unsigned short*)(gs + 0x5d00 + 0xc);
        flags = flags << 0x13;
        flags = (unsigned)flags >> 0x13;
        if (flags & 0x40) {
            const char* s = (const char*)FindEntryByKey_02072a68(table, 0x1c);
            int l = strlen(s);
            memcpy(cur, s, l);
            cur += l;
        }
        flags = *(unsigned short*)(gs + 0x5d00 + 0xc);
        flags = flags << 0x13;
        flags = (unsigned)flags >> 0x13;
        if (flags & 0x200) {
            const char* s = (const char*)FindEntryByKey_02072a68(table, 0x1f);
            memcpy(cur, s, strlen(s));
        }
    }

    func_0204500c((void*)g, *(char**)((char*)g + 0x5c), 0, 0xe3);
    *(int*)((char*)g + 0x998) = 1;
    return 0;
}
