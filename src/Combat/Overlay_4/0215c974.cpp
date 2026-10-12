#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Resource/GameResources.h"

extern "C" void _Z26ClearNodeMaskById_021f6600Pvii(void* obj, int id, int mask);
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v(void);
void OrBitsIntoField0(unsigned int* p, unsigned int mask);
extern "C" void _Z18ClearFlags020466f4P16FlagWord020466f4j(struct FlagWord020466f4* word, unsigned int mask);
extern "C" void func_ov023_021f65d4(void* obj, int a, int b);
extern "C" int _Z26GetGlobalField0x1c020421a0v(void);
extern "C" int _Z34DispatchAdjustmentIfType4_02157018Pvi(void* a, int key);
extern "C" int func_020aad1c(void* loader, void* name, int a, int b);
extern "C" int func_ov004_0215b1d4(void* obj);
extern "C" void* func_02012fe4(void);
struct Actor0209c3b4;
extern "C" void _Z27SetStateAndDispatch0209c3b4P13Actor0209c3b4i(struct Actor0209c3b4* actor, int val);
extern "C" void _Z22SetModeClamped0209ca70Pvi(void* obj, int val);
extern "C" void* _Z38GetOffsetPtrromField_021b1fc0_021b1fc0Pv(void* obj);
struct Obj_02184534;
extern "C" void _Z22SetFieldsB0B4_02184534P12Obj_02184534ii(struct Obj_02184534* obj, int b0, int b4);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void func_0204500c(void* field, void* buf, int p2, int p3);

struct EntryA68 { short key; void* value; };
struct TableA68 { struct EntryA68* entries; short count; };
void* FindEntryByKey(struct TableA68* table, int key);

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

    _Z26ClearNodeMaskById_021f6600Pvii(obj, 0x36, 8);

    data = _Z27GetDataPtr02114e04_020d6c00v();
    OrBitsIntoField0((unsigned int*)data, 0x80);

    BackgroundLoader::AddLockGlobal();
    BackgroundLoader::FreeAllocationsGlobal();
    queued = func_020aad1c(data_ov004_021707d8.ptr + 0x84, &data_0211e33c, 0xa, 0) != 0;
    BackgroundLoader::RemoveLockGlobal();
    if (!queued) return 1;

    _Z18ClearFlags020466f4P16FlagWord020466f4j((struct FlagWord020466f4*)data, 0x80);

    func_ov023_021f65d4(obj, 0x36, 8);

    g = _Z26GetGlobalField0x1c020421a0v();
    cur = *(char**)((char*)g + 0x5c);
    memset(cur, 0, 0x960);

    gs = (char*)GameState::GetInstance() + 0x26c;
    table = (struct TableA68*)_Z34DispatchAdjustmentIfType4_02157018Pvi(obj, 4);

    head = (const char*)FindEntryByKey(table, 0x21);
    len = strlen(head);
    memcpy(cur, head, len);
    cur += len;

    if (data_ov004_021707d8.ptr[0x15] != 0) {
        func_ov004_0215b1d4(obj);
        void* q = func_02012fe4();
        Bits7_0215c974* b = (Bits7_0215c974*)((char*)(*(void**)((char*)q + 8)) + 0xd);
        _Z27SetStateAndDispatch0209c3b4P13Actor0209c3b4i((struct Actor0209c3b4*)&data_02109bf4, b->low7);
        _Z22SetModeClamped0209ca70Pvi(&data_02109bf4, data_ov004_021707d8.ptr[0x2d]);
    } else if (data_ov004_021707d8.ptr[0x14] != 0) {
        void* raw = func_ov017_0218b5b0();
        void* five = *(void**)((char*)raw + 0x3000 + 0xb48);
        rec = (char*)_Z38GetOffsetPtrromField_021b1fc0_021b1fc0Pv(five);
        base = *(char**)((char*)five + 0x34);

        for (i = 0; i < 4; i++) {
            if (strstr((char*)rec + 0x88, &data_ov004_0217043e)) {
                _Z22SetFieldsB0B4_02184534P12Obj_02184534ii((struct Obj_02184534*)obj, (int)base, *(int*)((char*)rec + 0xac));
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
            const char* s = (const char*)FindEntryByKey(table, 0x1c);
            int l = strlen(s);
            memcpy(cur, s, l);
            cur += l;
        }
        flags = *(unsigned short*)(gs + 0x5d00 + 0xc);
        flags = flags << 0x13;
        flags = (unsigned)flags >> 0x13;
        if (flags & 0x200) {
            const char* s = (const char*)FindEntryByKey(table, 0x1f);
            memcpy(cur, s, strlen(s));
        }
    }

    func_0204500c((void*)g, *(char**)((char*)g + 0x5c), 0, 0xe3);
    *(int*)((char*)g + 0x998) = 1;
    return 0;
}
