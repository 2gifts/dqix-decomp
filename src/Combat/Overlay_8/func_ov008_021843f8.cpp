#include <globaldefs.h>
#include "GameState/BattleRecordSnapshot.h"
#include "GameState/GameState.h"
#include "World/Object3D.h"
#include <Memory/SafeAllocator.h>

struct ClearRecords {
    BattleRecordPlayClock times_[2];
    unsigned int unk_8_0 : 17;
    unsigned int unk_8_17 : 7;
    unsigned int unk_8_24 : 7;
    unsigned int unk_8_31 : 1;
    unsigned int unk_c_0 : 17;
    unsigned int unk_c_17 : 7;
    unsigned int unk_c_24 : 7;
    unsigned int unk_c_31 : 1;
    unsigned int unk_10_0 : 9;
    unsigned int unk_10_9 : 14;
    unsigned int title_ : 9;
    unsigned int unk_14;
};

struct PlayRecords {
    BattleRecordPlayClock playTime_;
    BattleRecordPlayClock unk_4;
    unsigned int unk_8;
    unsigned int unk_c;
    unsigned int unk_10_0 : 9;
    unsigned int unk_10_9 : 14;
    unsigned int unk_10_23 : 9;
    char pad_14[0x90 - 0x14];
    ClearRecords lastClear_;
    unsigned int unk_a8;
    unsigned int unk_ac;
};

struct GameFlags {
    unsigned int flags_[15];
};

struct SavedRecords {
    GameFlags flags_;
    PlayRecords records_;
};

static inline SavedRecords* GetSavedRecords(GameState* gameState)
{
#if defined(jpn)
    return (SavedRecords*)((char*)gameState + 0x2c4 + 0x7000);
#else
    return (SavedRecords*)((char*)gameState + 0x104 + 0x7400);
#endif
}

struct Struct020dfc40;
struct S020a13c4;
struct List0204af64;
struct InitTarget0205cfd4;
struct Struct_0205bef8;

void* GetDataPtr02114e04_020d6c00();
void OrBitsIntoField0_020466e4(unsigned int* field, unsigned int bits);
void ResetStruct020dfc40(Struct020dfc40* texts);
void ClearStruct020a13c4(S020a13c4* guides);
void ResetList0204af64(List0204af64* background);
void InitStruct0205cfd4(InitTarget0205cfd4* window);
void Init0205bef8(Struct_0205bef8* cursor);
void InitCombatController020a2010(void* camera);
extern "C" void func_0204c684(void* canvas);

struct BattleRecords {
    SafeAllocator allocator_;
    SafeAllocator backgroundAllocator_;
    SafeAllocator textAllocator_;
    SafeAllocator spriteAllocator_;
    SafeAllocator iconAllocator_;
    SafeAllocator modelAllocator_;
    SafeAllocator titleAllocator_;
    SafeAllocator guideAllocator_;
    char texts_[0x18];
    char* text_;
    char titleTable_[0x14];
    char backgrounds_[3][0x20];
    char window_[0xbc];
    char canvases_[6][0xe0];
    void* pixels_;
    void* renderer_;
    void* sprites_;
    void* animations_;
    void* iconRenderer_;
    void* iconSprite_;
    unsigned char items_[8];
    unsigned char itemCount_;
    char pad_74d[3];
    char cursor_[0x40];
    Object3D model_;
    char camera_[0x2c8];
    void* titles_;
    void* guide_;
    void* page_;
    signed char state_;
    unsigned char step_;
    unsigned char loadStep_;
    unsigned char exit_;
    short title_;
    short comment_;
    int flags_;
    int unk_b1c;
    int task_;
    int mode_;
    unsigned char kind_;
    unsigned char top_;
    unsigned char closed_;
    int titleX_;
    const void* guest_;
    void* guestRecords_;
    void* guestTexts_;
#if !defined(jpn)
    void* guestTitles_;
#endif
    BattleRecordPlayClock times_[2];
};

extern "C" void func_ov008_02186cec(BattleRecords* self);

// USA: func_ov008_021843f8
extern "C" ARM void func_ov008_021843f8(BattleRecords* self)
{
    OrBitsIntoField0_020466e4((unsigned int*)GetDataPtr02114e04_020d6c00(), 0xf);
    self->allocator_.ResetAllocatorPointer();
    self->backgroundAllocator_.ResetAllocatorPointer();
    self->textAllocator_.ResetAllocatorPointer();
    self->spriteAllocator_.ResetAllocatorPointer();
    self->iconAllocator_.ResetAllocatorPointer();
    self->modelAllocator_.ResetAllocatorPointer();
    self->titleAllocator_.ResetAllocatorPointer();
    self->guideAllocator_.ResetAllocatorPointer();
    ResetStruct020dfc40((Struct020dfc40*)self->texts_);
    self->text_ = NULL;
    ClearStruct020a13c4((S020a13c4*)self->titleTable_);
    ResetList0204af64((List0204af64*)self->backgrounds_[0]);
    ResetList0204af64((List0204af64*)self->backgrounds_[1]);
    ResetList0204af64((List0204af64*)self->backgrounds_[2]);
    InitStruct0205cfd4((InitTarget0205cfd4*)self->window_);
    for (int i = 0; i < 6; i++)
        func_0204c684(self->canvases_[i]);
    self->pixels_ = NULL;
    self->renderer_ = NULL;
    self->sprites_ = NULL;
    self->animations_ = NULL;
    self->iconRenderer_ = NULL;
    self->sprites_ = NULL;
    Init0205bef8((Struct_0205bef8*)self->cursor_);
    self->model_.Initialize();
    InitCombatController020a2010(self->camera_);
    self->titles_ = NULL;
    self->guide_ = NULL;
    self->page_ = NULL;
    self->state_ = 0;
    self->step_ = 0;
    self->loadStep_ = 0;
    self->exit_ = 0;
    self->title_ = -1;
    self->comment_ = -1;
    self->flags_ = 0;
    self->unk_b1c = 0;
    self->task_ = 0;
    self->mode_ = 0;
    self->kind_ = 0;
    self->top_ = 0;
    self->closed_ = 0;
    self->titleX_ = 0;
    self->guest_ = NULL;
    self->guestRecords_ = NULL;
    self->guestTexts_ = NULL;
#if !defined(jpn)
    self->guestTitles_ = NULL;
#endif
    ClearShortByteByte_02184598(&self->times_[0]);
    ClearShortByteByte_02184598(&self->times_[1]);
    SavedRecords* saved = GetSavedRecords(GameState::GetInstance());
    if (saved->records_.unk_10_0 != 0)
        self->flags_ |= 0x2000;
    if (saved->records_.lastClear_.title_ != 0)
        self->flags_ |= 4;
    func_ov008_02186cec(self);
}
