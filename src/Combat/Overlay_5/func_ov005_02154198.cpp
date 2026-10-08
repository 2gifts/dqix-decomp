#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <System/Cache.h>
#include <System/LoadToVRAM.h>
#include <std_library_functions.h>

#define REG_DISPCNT (*(volatile unsigned int*)0x04000000)

struct Entry_0205d6a0;
struct Struct02074bd0;
struct Obj0204b010;
struct List0204afb4;

extern "C" void func_ov023_021dc354(void* window);
void Set3DClearColor(int a, int b, int c, int d, int e);
unsigned int* GetWord0x0(int* gameState);
void ClearBitsInField4(unsigned int* p, unsigned int bits);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(Entry_0205d6a0* window, int a);
extern "C" void func_0205d048(void* window);
void ClearFlag0x10IfSet(Struct02074bd0* state);
extern "C" void _Z19ClearBuffer0204b010P11Obj0204b010Pv(Obj0204b010* bg, void* p);
extern "C" void func_0204b04c(void* bg, int a);
extern "C" void func_0204b088(void* bg, int a);
extern "C" void _Z23ResetRecordList0204afb4P12List0204afb4(List0204afb4* bg);

struct EquipmentMenu {
    SafeAllocator allocator_;
    SafeAllocator modelAllocator_;
    SafeAllocator equippedAllocators_[8];
    SafeAllocator itemAllocators_[16];
    SafeAllocator dragAllocator_;
    SafeAllocator textAllocator_;
    SafeAllocator unk_230;
    SafeAllocator infoAllocator_;
    SafeAllocator sortAllocator_;
    SafeAllocator modelTableAllocator_;
    SafeAllocator unk_280;
    char unk_294[0xe10 - 0x294];
    unsigned short* text_;
    char unk_e14[0xe6c - 0xe14];
    char screenState_[0x10];
    char unk_e7c[4];
    int layers_;
    char backgrounds_[0xee4 - 0xe84];
    char window_[0x1244 - 0xee4];
    char infoWindow_[0x3d88 - 0x1244];
    char* pageFiles_;
    char* dragFile_;
    char* equippedFiles_;
    char* itemFile_;
    char unk_3d98[0x3dc2 - 0x3d98];
    unsigned short unk_3dc2;
    char unk_3dc4[4];
    int task_;
};

// USA: func_ov005_02154198
extern "C" ARM void func_ov005_02154198(EquipmentMenu* self) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->task_ >= 0) {
        loader->RemoveTask(self->task_);
        self->task_ = -1;
    }
    func_ov023_021dc354(self->infoWindow_);
    Set3DClearColor(self->unk_3dc2, 0x10, 0x7fff, 0, 0);
    GameState* gameState = GameState::GetInstance();
    ClearBitsInField4(GetWord0x0((int*)gameState), 0x800);
    REG_DISPCNT = (REG_DISPCNT & ~0x1f00) | (self->layers_ << 8);
    _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((Entry_0205d6a0*)self->window_, 1);
    func_0205d048(self->window_);
    ClearFlag0x10IfSet((Struct02074bd0*)self->screenState_);
    _Z19ClearBuffer0204b010P11Obj0204b010Pv((Obj0204b010*)self->backgrounds_, 0);
    func_0204b04c(self->backgrounds_, 0);
    func_0204b088(self->backgrounds_, 0);
    _Z23ResetRecordList0204afb4P12List0204afb4((List0204afb4*)self->backgrounds_);
    if (self->pageFiles_ != NULL) {
        memset(self->pageFiles_, 0, 0x20);
        CleanInvalidateCacheRange(self->pageFiles_, 0x20);
        LoadToMainBG1CharacterData(self->pageFiles_, 0, 0x20);
    }
    self->modelAllocator_.Destroy();
    for (int i = 0; i < 8; i++)
        self->equippedAllocators_[i].Destroy();
    for (int i = 0; i < 16; i++)
        self->itemAllocators_[i].Destroy();
    self->dragAllocator_.Destroy();
    self->textAllocator_.Destroy();
    self->allocator_.Destroy();
    self->unk_230.Destroy();
    self->infoAllocator_.Destroy();
    self->sortAllocator_.Destroy();
    self->modelTableAllocator_.Destroy();
    self->unk_280.Destroy();
    self->pageFiles_ = NULL;
    self->dragFile_ = NULL;
    self->equippedFiles_ = NULL;
    self->itemFile_ = NULL;
    self->text_ = NULL;
}
