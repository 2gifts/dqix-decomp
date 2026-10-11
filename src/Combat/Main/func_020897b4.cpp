#include <globaldefs.h>

#include "Combat/Main/BattleList.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct StreamHeader;
struct Ctx0209a8b4 { void* field0; };

extern char data_020f1019[];
extern char data_020f102e[];
extern unsigned char data_0211e33c[0x30000];

int GetFieldAt0x150(unsigned char* obj);
extern "C" void* _Z22Clear0x54Bytes0208247cPv(void* obj);
extern "C" int _Z24InitAndRunScript0208274cPvP12StreamHeaderii(void* ctx, StreamHeader* script, int size, int arg3);
extern "C" void func_02083cbc(void* dst, void* src, void* tail);
extern "C" void func_02083e28(void* model, int arg);
extern "C" void _Z28SetBitsFromIndexList02083b8cPhS_j(unsigned char* obj, unsigned char* list, unsigned int count);
extern "C" void _Z19ClearField00209a804Pi(int* field);
extern "C" void _Z33SetupAndRunBufferedScript0209a8b4P11Ctx0209a8b4P13SafeAllocatorP12StreamHeaderi(Ctx0209a8b4* ctx, SafeAllocator* alloc, StreamHeader* buffer, int length);
extern "C" int func_0209aa54(void* holder, unsigned char* path, unsigned char* out, int threshold);
extern "C" void _Z27EnqueueEventTag176_021ce614hhh(unsigned char a, unsigned char b, unsigned char c);

struct Entry0208 {
    unsigned int dword0;
    unsigned short low : 7;
    unsigned short high : 9;
    unsigned char pad[0x3c - 6];
    unsigned char tail[0x18];
};

// USA: func_020897b4
extern "C" ARM void func_020897b4(unsigned char a, unsigned char b, int c, unsigned char d,
                                 unsigned char e, void* f, unsigned int g, void* h, unsigned int i) {
    char path[0x50];
    Entry0208 entry;
    char heap[0x600];
    SafeAllocator alloc;
    unsigned char list[0x14];
    unsigned int size;
    Ctx0209a8b4 ctx;

    GameObject* combatant = GetCombatantWithFlag0x100(GameState::GetInstance(), a);
    if (combatant == 0) {
        return;
    }
    BackgroundLoader::AddLockGlobal();

    if (f == 0) {
        sprintf(path, data_020f1019, c);
        if (LoadFileIntoMemory(path, &data_0211e33c, &size) == 0) {
            BackgroundLoader::RemoveLockGlobal();
            return;
        }
        f = &data_0211e33c;
        g = size;
    }

    _Z22Clear0x54Bytes0208247cPv(&entry);
    _Z24InitAndRunScript0208274cPvP12StreamHeaderii(&entry, (StreamHeader*)f, g, b);

    Entry0208* ep = &entry;
    ep++;
    unsigned char* field = (unsigned char*)(int)GetFieldAt0x150((unsigned char*)combatant);
    *(unsigned short*)(field + 0x954) |= 1 << c;
    *(int*)(field + 0x950) = c;
    *(unsigned short*)(field + c * 2 + 0x16c) = b;
    *(int*)(field + c * 4 + 0x138) = (ep - 1)->dword0;
    *(unsigned short*)(field + 0x564) = (ep - 1)->high;
    func_02083cbc(field, ep - 1, &entry.tail);

    if (e != 0) {
        func_02083e28(field, 0);
        *(unsigned short*)(*(char**)((char*)combatant + 0x130) + 4) = *(unsigned short*)(*(char**)((char*)combatant + 0x134) + 0x30);
        *(unsigned short*)(*(char**)((char*)combatant + 0x130) + 6) = *(unsigned short*)(*(char**)((char*)combatant + 0x134) + 0x32);
    }

    if (h == 0) {
        if (LoadFileIntoMemory(data_020f102e, &data_0211e33c, &size) != 0) {
            h = &data_0211e33c;
            i = size;
        }
    }

    if (h != 0) {
        alloc.ResetAllocatorPointer();
        alloc.CreateTypeA(heap, 0x600);
        _Z19ClearField00209a804Pi((int*)&ctx);
        _Z33SetupAndRunBufferedScript0209a8b4P11Ctx0209a8b4P13SafeAllocatorP12StreamHeaderi(&ctx, &alloc, (StreamHeader*)h, i);
        unsigned int count = func_0209aa54(&ctx, (unsigned char*)(int)combatant, list, 0);
        _Z28SetBitsFromIndexList02083b8cPhS_j(field, list, count);
        alloc.Destroy();
    }

    if (d != 0) {
        _Z27EnqueueEventTag176_021ce614hhh(a, b, e);
    }

    BackgroundLoader::RemoveLockGlobal();
}
