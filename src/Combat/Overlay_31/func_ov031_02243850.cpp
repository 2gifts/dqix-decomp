#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

#define REG_IME (*(volatile unsigned short*)0x04000208)
struct State02243850 {
    SafeAllocator allocator;
    char pad14[0x14];
    SafeAllocator* external;
    char pad2c[0x20];
    void* buffer;
    char pad50[0x324];
    unsigned char mode;
    char pad375[0x13];
    void* data;
    char pad38c[0x10];
    int task_39c;
    int task_3a0;
};
struct Field02243850 { char pad[0x4000]; char pad4000[0x494]; int field_4494; };
struct Obj020397cc;
extern SafeAllocator data_ov031_02291e3c;
extern char data_0211e33c;
extern char data_ov031_0224c90c[];
extern char data_ov031_0224c920[];
extern "C" int* func_0202ae18(GameState*);
int CheckField0NonZero(int*);
extern "C" void _Z27CancelPendingAction020397ccP11Obj020397cci(Obj020397cc*, int);
extern "C" unsigned int* _Z27GetDataPtr02114e04_020d6c00v();
void OrBitsIntoField0(unsigned int*, unsigned int);
void MarkContextStackTopUnknownSubspace(ProcessorContext*, unsigned int);
void EnableSpecificInterrupts(unsigned int);
void EnableIRQInterrupts();

enum AllocationLength02243850 {
    ArenaLength02243850 = 0x2cd40,
    WorkLength02243850 = 0x2bc00
};

// USA: func_ov031_02243850
extern "C" ARM int func_ov031_02243850(State02243850* state) {
    GameState* game = GameState::GetInstance();
    int* field = func_0202ae18(game);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int result = 1;
    if (CheckField0NonZero(field)) return -1;
    GameObject* object = game->GetUnknownGameObject();
    if (object) _Z27CancelPendingAction020397ccP11Obj020397cci((Obj020397cc*)object, 1);
    AllocationLength02243850 length = ArenaLength02243850;
    if (!state->external) return -1;
    void* arena = state->external->Allocate(length);
    if (!arena) return -1;
    state->allocator.CreateTypeB(arena, length, 4);
    state->allocator.Reset();
    length = WorkLength02243850;
    void* buffer = state->allocator.Allocate(length);
    if (!buffer) return -1;
    data_ov031_02291e3c.CreateTypeB(buffer, length, 0x20);
    if (state->mode & 0x20) {
        BackgroundLoader::AddLockGlobal();
        state->data = &data_0211e33c;
        state->task_39c = loader->QueueLoadFile(data_ov031_0224c90c, 0);
        state->task_3a0 = loader->QueueLoadFile(data_ov031_0224c920, 0);
        result = 3;
        BackgroundLoader::RemoveLockGlobal();
    } else {
        state->buffer = state->allocator.Allocate(0x700);
        OrBitsIntoField0(_Z27GetDataPtr02114e04_020d6c00v(), 0x80);
    }
    ((Field02243850*)func_ov017_0218b5b0())->field_4494 = 1;
    MarkContextStackTopUnknownSubspace(data_02111304.activeContext, 0x100);
    EnableSpecificInterrupts(0xc78);
    unsigned short oldIme = REG_IME;
    REG_IME = 1;
    EnableIRQInterrupts();
    return result;
}
