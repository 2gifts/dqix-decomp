#include <globaldefs.h>
#include <std_library_functions.h>
#include "Memory/SafeAllocator.h"

struct Struct020dfc40 {
    char unk_0[0x18];
};

struct List0204af64 {
    char unk_0[0x20];
};

struct InitTarget0205cfd4 {
    char unk_0[0xbc];
};

struct Canvas {
    char unk_0[0xe0];
};

struct Struct_0205bef8 {
    int words_[0x10];
};

struct Struct021847c4 {
    int x_;
    int y_;
    int width_;
    int height_;
    int stepX_;
    int stepY_;
    int columns_;
    int rows_;
};

struct Object3D {
    char unk_0[0xac];
    void Initialize();
};

extern "C" unsigned int* _Z27GetDataPtr02114e04_020d6c00v();
void OrBitsIntoField0(unsigned int* field, unsigned int bits);
extern "C" void _Z16ZeroInit020de848Pv(void* table);
extern "C" void _Z19ResetStruct020dfc40P14Struct020dfc40(Struct020dfc40* table);
extern "C" void func_ov009_021847ec(void* checker);
extern "C" void _Z17ResetList0204af64P12List0204af64(List0204af64* background);
extern "C" void _Z18InitStruct0205cfd4P18InitTarget0205cfd4(InitTarget0205cfd4* window);
extern "C" void func_0204c684(Canvas* canvas);
extern "C" void _Z12Init0205bef8P15Struct_0205bef8(Struct_0205bef8* cursor);
extern "C" void _Z19ResetFields021847c4P14Struct021847c4(Struct021847c4* grid);
extern "C" int _Z27FindEntryIndexByKey020424e4ii(int text, int mode);

extern char data_ov009_0218aca4[];

struct CharacterCreation {
    SafeAllocator allocators_[9];
    SafeAllocator* modelAllocator_;
    SafeAllocator* previewAllocators_;
    void* savedKey_;
    void* keyboard_;
    void* layout_;
    char partNames_[0x18];
    Struct020dfc40 texts_;
    void* unk_f8;
    char checker_[0x3c];
    List0204af64 backgrounds_[6];
    InitTarget0205cfd4 windows_[2];
    Canvas canvases_[1];
    Canvas canvases2_[4];
    void* pixels_;
    void* pixels2_;
    void* renderer_;
    void* sprites_;
    void* unk_7e0;
    void* renderer2_;
    void* sprites2_;
    void* unk_7ec;
    void* characters_[2];
    void* character_;
    void* nextCharacter_;
    int unk_800;
    int targetAngle_;
    char unk_808[0x70];
    Object3D object_;
    char camera_[0x2c8];
    Struct_0205bef8 cursor_;
    Struct021847c4 grid_;
    short cursorX_;
    short cursorY_;
    short cursorWidth_;
    short cursorHeight_;
    short lastX_;
    short lastY_;
    signed char state_;
    unsigned char step_;
    char unk_c5a[2];
    int modelTasks_[3];
    char unk_c68[0x70];
    Object3D object2_;
    unsigned char selection_;
    unsigned char unk_d85;
    char unk_d86[2];
    void* member_;
    int touchedChoice_;
    int task_;
    unsigned char loadStep_;
    unsigned char mode_;
    short timer_;
    short unk_d98;
    char unk_d9a[2];
    unsigned int flags_;
    signed char lastStates_[2];
    unsigned char vocation_;
    unsigned char sex_;
    unsigned char bodyType_[2];
    unsigned char hairStyle_[2];
    unsigned char skinColor_[2];
    unsigned char eyeColor_[2];
    unsigned char face_[2];
    unsigned char hairColor_[2];
    char** names_;
    unsigned char unk_db4;
    unsigned char keyboardResult_;
    unsigned char unk_db6;
    char unk_db7;
};

// USA: func_ov009_0218454c
extern "C" ARM void func_ov009_0218454c(CharacterCreation* self, int vocation, int mode)
{
    self->mode_ = mode;
    if (self->mode_ == 1)
        OrBitsIntoField0(_Z27GetDataPtr02114e04_020d6c00v(), 0xf);
    self->allocators_[0].ResetAllocatorPointer();
    self->allocators_[1].ResetAllocatorPointer();
    self->allocators_[2].ResetAllocatorPointer();
    self->allocators_[3].ResetAllocatorPointer();
    self->allocators_[4].ResetAllocatorPointer();
    self->allocators_[5].ResetAllocatorPointer();
    self->allocators_[6].ResetAllocatorPointer();
    self->allocators_[7].ResetAllocatorPointer();
    self->allocators_[8].ResetAllocatorPointer();
    self->modelAllocator_ = NULL;
    self->previewAllocators_ = NULL;
    self->keyboard_ = NULL;
    self->layout_ = NULL;
    _Z16ZeroInit020de848Pv(&self->partNames_);
    _Z19ResetStruct020dfc40P14Struct020dfc40(&self->texts_);
    self->unk_f8 = NULL;
    func_ov009_021847ec(&self->checker_);
    _Z17ResetList0204af64P12List0204af64(&self->backgrounds_[0]);
    _Z17ResetList0204af64P12List0204af64(&self->backgrounds_[1]);
    _Z17ResetList0204af64P12List0204af64(&self->backgrounds_[2]);
    _Z17ResetList0204af64P12List0204af64(&self->backgrounds_[3]);
    _Z17ResetList0204af64P12List0204af64(&self->backgrounds_[4]);
    _Z17ResetList0204af64P12List0204af64(&self->backgrounds_[5]);
    _Z18InitStruct0205cfd4P18InitTarget0205cfd4(&self->windows_[0]);
    _Z18InitStruct0205cfd4P18InitTarget0205cfd4(&self->windows_[1]);
    for (int i = 0; i < 1; i++)
        func_0204c684(&self->canvases_[i]);
    for (int i = 0; i < 4; i++)
        func_0204c684(&self->canvases2_[i]);
    self->pixels_ = NULL;
    self->pixels2_ = NULL;
    self->renderer_ = NULL;
    self->sprites_ = NULL;
    self->unk_7e0 = NULL;
    self->renderer2_ = NULL;
    self->sprites2_ = NULL;
    self->unk_7ec = NULL;
    self->characters_[0] = NULL;
    self->characters_[1] = NULL;
    self->character_ = NULL;
    self->nextCharacter_ = NULL;
    self->unk_800 = 0;
    self->targetAngle_ = 0;
    self->object_.Initialize();
    self->object2_.Initialize();
    _Z12Init0205bef8P15Struct_0205bef8(&self->cursor_);
    _Z19ResetFields021847c4P14Struct021847c4(&self->grid_);
    self->cursorX_ = -1;
    self->cursorY_ = -1;
    self->cursorWidth_ = -1;
    self->cursorHeight_ = -1;
    self->lastX_ = -1;
    self->lastY_ = -1;
    self->state_ = 0;
    self->step_ = 0;
    self->selection_ = 0;
    self->unk_d85 = 0;
    self->member_ = NULL;
    self->touchedChoice_ = -1;
    self->task_ = 0;
    self->loadStep_ = 0;
    self->timer_ = 0;
    self->unk_d98 = 0;
    memset(&self->flags_, 0, sizeof(self->flags_));
    for (int i = 0; i < 2; i++)
        self->lastStates_[i] = 1;
    self->vocation_ = vocation;
    self->sex_ = 0;
    for (int i = 0; i < 2; i++)
    {
        self->bodyType_[i] = 0;
        self->hairStyle_[i] = 0;
        self->skinColor_[i] = 0;
        self->eyeColor_[i] = 0;
        self->face_[i] = 0;
        self->hairColor_[i] = 0;
    }
    self->names_ = NULL;
    self->unk_db4 = _Z27FindEntryIndexByKey020424e4ii((int)data_ov009_0218aca4, 0);
    self->unk_db6 = 0;
}
