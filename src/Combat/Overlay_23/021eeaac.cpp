#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"
#include "System/OverlayId.h"

struct List020727d8;
struct SearchStruct;
struct Pair0209a338;
struct Ctx0209a470;
struct Ctx0209a8b4;
struct StreamHeader;
struct Reset_021eefac;

extern "C" void func_020a1940(unsigned int id);
void ResetListHeader020727d8(List020727d8* list);
extern "C" void func_020728ac(void* a, void* b, int c, int d, int e, int f, int g);
void CopyShortTriple0x8e4a(void* obj, short* a, short* b, short* c);
int AreAllListedCombatantsFlagged_021ed92c();
void ZeroInit020de848(void* obj);
extern "C" int func_020de9a4(void* list, void* alloc, void* data, unsigned int size, void* entries, unsigned short count);
void* ZeroInitReturn020de824(void* obj);
void InitStruct0207cbe8(char* obj);
extern "C" int func_0207d300(void* buf, int a, int b, int c);
extern "C" int func_0207ccf0(void* buf, int a, int b, int c, int d, int e, int f);

int GetField0x3acValue(GameState* gs);
extern "C" SearchStruct* func_0202ae18(void);
int TestBitBySignedByteIndex(SearchStruct* search, int index);
void ClearFirstTwoWords0209a338(Pair0209a338* pair);
void SetupAndRunBufferedScript0209a470(Ctx0209a470* ctx, SafeAllocator* alloc, StreamHeader* data, int length);
void ClearField00209a804(int* field);
void SetupAndRunBufferedScript0209a8b4(Ctx0209a8b4* ctx, SafeAllocator* alloc, StreamHeader* data, int length);
void ResetFields_021eefac(Reset_021eefac* s);

extern "C" int* _ZZ17GetGlobal021ffefcvE1s;
extern const char* data_020f2a38;
extern const char* data_020f2a30;
extern char data_ov023_021fe1d8;
extern char data_ov023_021fe1ee;
extern char data_ov023_021fe200;
extern char data_ov023_021fe218;
#if defined(jpn)
extern char data_ov023_021fd49e[];
#endif

struct Entry021eeaac {
    short id;
    unsigned short flags;
    char pad;
    signed char slot;
};

static inline SafeAllocator* GetAllocator(GameResources* res, int index) {
    return &res->allocator_array_38[index];
}

// USA: func_ov023_021eeaac
extern "C" ARM int func_ov023_021eeaac(char* self) {
#if defined(jpn)
 enum {regionalOffset0=0xe28, regionalOffset1=0x5af4, regionalOffset2=0x5af0, regionalOffset3=0x5ac0, regionalOffset4=0x218, regionalOffset5=0x5afc, regionalOffset6=0x5af1};
#else
 enum {regionalOffset0=0xeac, regionalOffset1=0x5904, regionalOffset2=0x5900, regionalOffset3=0x58d0, regionalOffset4=0x29c, regionalOffset5=0x590c, regionalOffset6=0x5901};
#endif
    GameResources* res = func_ov017_0218b5b0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int* g = _ZZ17GetGlobal021ffefcvE1s;
    SafeAllocator* alloc = GetAllocator(res, 5);
    if (g[0] == 0) {
        func_020a1940(OVERLAY_ID(13));
#if defined(jpn)
        g[1] = loader->QueueLoadFile(data_ov023_021fd49e, NULL);
#else
        g[1] = loader->QueueLoadFileInGP2(&data_ov023_021fe1d8, &data_ov023_021fe1ee, NULL);
#endif

        g[0]++;
    } else if (g[0] == 1) {
        if (loader->GetTaskStatus(g[1]) == 0) {
            return *(int*)(self + regionalOffset0);
        }
        unsigned int length;
        void* data;
        loader->GetLoadedFileByID(g[1], &data, &length);
        ResetListHeader020727d8((List020727d8*)(self + regionalOffset1));
        func_020728ac(self + regionalOffset1, alloc, (int)data, length, 0, 0, 0);
        loader->RemoveTask(g[1]);
#if defined(jpn)
        g[1] = loader->QueueLoadGP1(data_020f2a38, NULL);
#else
        g[1] = loader->QueueLoadFileInGP2(data_020f2a38, data_020f2a30, NULL);
#endif

        g[0]++;
    } else if (g[0] == 2) {
        int slot;
        unsigned int length;
        void* data;
        int count;
        short ids[10];
        short* dst;
        unsigned short* src;
        int i;
        int k;
        short kind;
        short c;
        short b;
        char buf[0x38];
        void* list;
        Entry021eeaac* entry;
        int present;
        GameState* gs;
        char* party;
        int found;
        char obj[0x38];
        int result;
        int j;
        int current;
        if (loader->GetTaskStatus(g[1]) == 0) {
            return *(int*)(self + regionalOffset0);
        }
        loader->GetLoadedFileByID(g[1], &data, &length);
        count = *(unsigned char*)(self + regionalOffset2);
        if (count > 8) {
            count = 8;
        }
        dst = ids;
        src = (unsigned short*)(self + regionalOffset3);
        for (i = 0; i < count; i++) {
            *dst = *src;
            dst++;
            src += 3;
        }
        if (*(short*)(*(char**)(self + regionalOffset4) + 0x8e4a) > 0) {
            CopyShortTriple0x8e4a(*(void**)(self + regionalOffset4), &kind, &b, &c);
            ids[count] = c;
            count++;
            if (kind == 0x18 && AreAllListedCombatantsFlagged_021ed92c()) {
                *(unsigned char*)(*(char**)(self + regionalOffset4) + 0x8e97) = 1;
            }
        }
        *(void**)(self + regionalOffset5) = alloc->Allocate(0x18);
        ZeroInit020de848(*(void**)(self + regionalOffset5));
        func_020de9a4(*(void**)(self + regionalOffset5), alloc, data, length, ids, count);
        loader->RemoveTask(g[1]);
        if (*(short*)(*(char**)(self + regionalOffset4) + 0x8e4a) > 0) {
            count--;
            ((SafeAllocator*)buf)->ResetAllocatorPointer();
            ZeroInitReturn020de824(buf + 0x14);
            InitStruct0207cbe8(buf);
            InitStruct0207cbe8(buf);
            *(void**)(buf + 0x2c) = *(void**)(self + regionalOffset5);
            func_0207d300(buf, ids[count], 1, 0);
        }
        list = *(void**)(self + regionalOffset5);
        entry = (Entry021eeaac*)(self + regionalOffset3);
        present = *(signed char*)(self + regionalOffset6);
        gs = GameState::GetInstance();
        party = (char*)GetPtrField0x2a04(gs);
        found = 0;
        for (k = 0; k < *(unsigned char*)(party + 0xf7c); k++) {
            if (present & (1 << *(unsigned char*)(party + k + 0xf78))) {
                found = 1;
                break;
            }
        }
        if (found) {
            current = GetField0x3acValue(gs);
            for (j = 0; j < count; j++, entry++) {
                ((SafeAllocator*)obj)->ResetAllocatorPointer();
                ZeroInitReturn020de824(obj + 0x14);
                InitStruct0207cbe8(obj);
                InitStruct0207cbe8(obj);
                *(void**)(obj + 0x2c) = list;
                slot = entry->slot;
                if (slot < 0) {
                    result = func_0207d300(obj, entry->id, 1, 1);
                } else {
                    if (current != slot && (TestBitBySignedByteIndex(func_0202ae18(), slot) != 0 || current != 0)) {
                        if (present & (1 << current)) {
                            slot = current;
                        }
                    }
                    result = func_0207ccf0(obj, entry->id, 1, slot, 1, 0, 1);
                }
                entry->flags &= ~0x8000;
                if (result == 2) {
                    entry->flags |= 0x8000;
                }
            }
        }
        g[1] = loader->QueueLoadFile(&data_ov023_021fe200, NULL);
        g[0]++;
    } else if (g[0] == 3) {
        if (loader->GetTaskStatus(g[1]) == 0) {
            return *(int*)(self + regionalOffset0);
        }
        unsigned int length;
        void* data;
        loader->GetLoadedFileByID(g[1], &data, &length);
        ClearFirstTwoWords0209a338((Pair0209a338*)(g + 0xe8 / 4));
        SetupAndRunBufferedScript0209a470((Ctx0209a470*)(g + 0xe8 / 4), alloc, (StreamHeader*)data, length);
        loader->RemoveTask(g[1]);
        g[1] = loader->QueueLoadFile(&data_ov023_021fe218, NULL);
        g[0]++;
    } else if (g[0] == 4) {
        if (loader->GetTaskStatus(g[1]) == 0) {
            return *(int*)(self + regionalOffset0);
        }
        unsigned int length;
        void* data;
        loader->GetLoadedFileByID(g[1], &data, &length);
        ClearField00209a804(g + 0xf0 / 4);
        SetupAndRunBufferedScript0209a8b4((Ctx0209a8b4*)(g + 0xf0 / 4), alloc, (StreamHeader*)data, length);
        loader->RemoveTask(g[1]);
        ResetFields_021eefac((Reset_021eefac*)g);
        return 3;
    }
    return *(int*)(self + regionalOffset0);
}
