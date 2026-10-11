#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/GPC.h"
#include "Memory/SafeAllocator.h"

struct Table021e771c {
    unsigned char data[0xc];
};

struct Resources021e771c {
    char pad[0x678];
    Table021e771c tableA;
    Table021e771c tableB;
};

struct CombatWork021e771c {
    char pad[0x44 - sizeof(SafeAllocator)];
    SafeAllocator allocs[2];
    SafeAllocator* GetAllocator(int i) { return &allocs[i]; }
};

extern "C" Resources021e771c* func_ov017_021b8478(void* node);
CombatWork021e771c* GetActiveCombatWork(void);
extern "C" void func_ov000_02166804(CombatWork021e771c* work);
void* LoadFileIntoMemory(const char* path, void* dst, unsigned int* outSize);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);
extern "C" void* _Z19ClearStruct020709d8Pv(void* obj);
extern "C" void* _Z20Clear12Bytes0206efc4Pv(void* obj);
extern "C" void func_02070b6c(void* table, void* owner, void* data, unsigned int size, int a, int b);
#if defined(jpn)
extern "C" void func_0206f230(void* table, void* owner, void* data, unsigned int size, int a, int b);
#else
extern "C" void func_0206f230(void* table, void* owner, void* data, unsigned int size, int a, int b, int c, int d);
#endif

extern "C" unsigned int _Z19LoadGPCFile02166008PvP11GPCReadPairi(void* unused, GPCReadPair* readPair, int flag);
extern "C" void func_ov000_02166070(CombatWork021e771c* work, GPCReadPair* readPair, int index, int id, int flag, unsigned int length);
extern "C" void _Z31ResetGPCReadPairAndHalveCounterPvP11GPCReadPair(void* unused, GPCReadPair* pair, int flag);

#if defined(jpn)
extern char data_ov025_021efb1e[];
extern char data_ov025_021efb3a[];
#endif
extern char data_ov025_021ef83e[];
extern char data_0211e33c[];
extern char data_ov025_021ef857[];
extern char data_ov025_021ef86d[];

// JPN: func_ov025_021e7bcc
// USA: func_ov025_021e771c
extern "C" ARM int func_ov025_021e771c(short* ids, int count, int a, int b) {
    GameResources* resources = func_ov017_0218b5b0();
    GameState::GetInstance();
    Resources021e771c* res = func_ov017_021b8478(resources->unknown_ptr_3718);
    CombatWork021e771c* work = GetActiveCombatWork();
    func_ov000_02166804(work);
    Table021e771c* tableA = &res->tableA;
    Table021e771c* tableB = &res->tableB;
    SafeAllocator* owner = work->GetAllocator(1);
    BackgroundLoader::AddLockGlobal();
    unsigned int size;
#if defined(jpn)
    void* data = LoadFileIntoMemory(data_ov025_021efb1e, data_0211e33c, &size);
#else
    void* data = LoadFileIntoMemory(data_ov025_021ef83e, data_0211e33c, &size);
#endif

    if (data != 0) {
        _Z19ClearStruct020709d8Pv(tableB);
        func_02070b6c(tableB, owner, data, size, a, b);
#if defined(jpn)
        void* data2 = LoadFileIntoMemory(data_ov025_021efb3a, data_0211e33c, &size);
#else
        void* data2 = ExtractFileFromGP2(data_ov025_021ef857, data_ov025_021ef86d, &size);
#endif

        if (data2 != 0) {
            _Z20Clear12Bytes0206efc4Pv(tableA);
#if defined(jpn)
            func_0206f230(tableA, owner, data2, size, a, b);
#else
            func_0206f230(tableA, owner, data2, size, a, b, 0, 0);
#endif

            GPCReadPair pair;
            GPCReadPair* readPair = &pair;
            readPair++;
            ZeroInitGPCPointer(&(readPair - 1)->pGPCFile);
            (readPair - 1)->ZeroInitializeMachine();
            unsigned int length = _Z19LoadGPCFile02166008PvP11GPCReadPairi(work, &pair, 0);
            for (int i = 0; i < count; i++) {
                func_ov000_02166070(work, &pair, i, ids[i], 0, length);
            }
            _Z31ResetGPCReadPairAndHalveCounterPvP11GPCReadPair(work, &pair, 0);
            pair.Reset();
            ZeroDestroyGPCPointer(&pair.pGPCFile);
        }
    }
    BackgroundLoader::RemoveLockGlobal();
    return 1;
}
