#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Resource/GameResources.h"

struct CharacterModel_021fc518 {
    char unk_0[0xc20];
};

class MenuCharacter_021fc518 {
public:
    unsigned short type_;
    unsigned short id_;
    unsigned short heap_;
    unsigned short vramState_;
    unsigned char flags_;
    char unk_d[3];
    const char* file_;
    void* prev_;
    void* next_;
    int state_;
    CharacterModel_021fc518 models_[2];
    int perspective_;
    unsigned char current_ : 1;
    unsigned char turnBack_ : 1;
    unsigned char unk_1864_2 : 1;
    unsigned char swap_ : 1;
    void (**leftCallback_)(void* script);
    void (**rightCallback_)(void* script);

    virtual void Update(void* script);
};

class MenuNode_021fc518 {
public:
    virtual void unk_00();
    virtual void unk_04();
    virtual void unk_08();
    virtual void unk_0c();
    virtual void unk_10();
    virtual void unk_14();
    virtual void unk_18();
    virtual void unk_1c();
    virtual void unk_20();
    virtual void unk_24();
    virtual void unk_28();
    virtual void unk_2c();
    virtual void unk_30();
    virtual void unk_34();
    virtual void unk_38();
    virtual void unk_3c();
    virtual void unk_40();
    virtual void unk_44();
    virtual void unk_48();
    virtual void unk_4c();
    virtual void unk_50();
    virtual void unk_54();
    virtual void unk_58();
    virtual void unk_5c();
    virtual void unk_60();
    virtual void unk_64();
    virtual void unk_68();
    virtual void unk_6c();
    virtual void unk_70();
    virtual void unk_74();
    virtual void unk_78();
    virtual void unk_7c();
    virtual void unk_80();
    virtual void unk_84();
    virtual void unk_88();
    virtual void unk_8c();
    virtual void unk_90();
    virtual void unk_94();
    virtual void unk_98();
    virtual void unk_9c();
    virtual void unk_a0();
    virtual void unk_a4();
    virtual void unk_a8();
    virtual void unk_ac();
    virtual void unk_b0();
    virtual void unk_b4();
    virtual void unk_b8();
    virtual void unk_bc();
    virtual void unk_c0();
    virtual void unk_c4();
    virtual void unk_c8();
    virtual void unk_cc();
    virtual void unk_d0();
    virtual void unk_d4();
    virtual void unk_d8();
    virtual void unk_dc();
    virtual void unk_e0();
    virtual void unk_e4();
    virtual int GetPerspective();
};

struct HeapNode_021fc518 {
    int unk_0;
    SafeAllocator allocator;
};

struct ObjBase021f6ed8;
struct Foo0207df50;
struct Vec3Target0202e5c0;
struct AngleTrig0202e9a4;

extern "C" void func_ov023_021f6ed8(ObjBase021f6ed8* obj);
extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" MenuNode_021fc518* func_ov023_021f6880(void* list, int tag);
extern "C" HeapNode_021fc518* func_ov011_021845f8(void* ctx, int heap);
void CopyInternalFields0207df50(Foo0207df50* p);
void RestorePairTables0207df90(char* p);
void BackupPairTables0207dfac(char* p);
void InitTenAllocatorsAndClearFields_021e4e8c(void* model);
void CreateTenAndOne_021e4f64(void* model, SafeAllocator* allocator);
void InitBlockArray_021e4fd8(void* model);
void SetIntC0C_021e6198(void* model, int value);
void SetByteC11_021e6150(void* model, unsigned char value);
void InitWordsQuad_021e60e0(void* model, unsigned int value);
extern "C" void func_ov023_021fc71c(void* obj, int id, int flagArg);
char* GetFieldIfFlag4_020100f8(char* gameState);
void SetVec3At0x4(Vec3Target0202e5c0* camera, int x, int y, int z);
void SetFields0x10To0x18_0202e5c8(unsigned char* camera, int x, int y, int z);
int GetField0x58_0202e9ec(void* camera);
void SetAngleAndTrigTable0202e9a4(AngleTrig0202e9a4* camera, int angle);
void SetField0x238False_020a27a0(void* camera);

// USA: func_ov023_021fc518
extern "C" ARM int func_ov023_021fc518(MenuCharacter_021fc518* self, void* ctx, int id, int heap, int parentTag, int character) {
    func_ov023_021f6ed8((ObjBase021f6ed8*)self);
    self->type_ = 5;
    self->id_ = id;
    self->heap_ = heap;
    self->vramState_ = 0;
    self->file_ = NULL;
    self->current_ = 0;
    self->perspective_ = 0;
    self->swap_ = 0;
    self->turnBack_ = 0;
    self->unk_1864_2 = 0;
    self->leftCallback_ = NULL;
    self->rightCallback_ = NULL;

    MenuNode_021fc518* parent = func_ov023_021f6880(func_ov011_021849c8(ctx), parentTag);
    HeapNode_021fc518* heapNode = func_ov011_021845f8(ctx, heap);
    int perspective = parent->GetPerspective();

#if defined(jpn)
    char* pairTables = (char*)func_ov017_0218b5b0() + 0x27c;
#else
    char* pairTables = func_ov017_0218b5b0()->unknown_2cc;
#endif
    CopyInternalFields0207df50((Foo0207df50*)pairTables);
    RestorePairTables0207df90(pairTables);
    for (int i = 0; i < 2; i++) {
        InitTenAllocatorsAndClearFields_021e4e8c(&self->models_[i]);
        CreateTenAndOne_021e4f64(&self->models_[i], &heapNode->allocator);
        InitBlockArray_021e4fd8(&self->models_[i]);
        SetIntC0C_021e6198(&self->models_[i], perspective);
        SetByteC11_021e6150(&self->models_[i], 1);
    }
    BackupPairTables0207dfac(pairTables);

    InitWordsQuad_021e60e0(&self->models_[0], 0x1eb);
    InitWordsQuad_021e60e0(&self->models_[1], 0x1eb);
    if (character >= 0)
        func_ov023_021fc71c(self, character, 0);

    char* camera = GetFieldIfFlag4_020100f8((char*)GameState::GetInstance());
    SetVec3At0x4((Vec3Target0202e5c0*)camera, 0xb666, 0xb800, 0x42ccc);
    SetFields0x10To0x18_0202e5c8((unsigned char*)camera, 0xb666, 0xb800, 0);
    self->perspective_ = GetField0x58_0202e9ec(camera);
    SetAngleAndTrigTable0202e9a4((AngleTrig0202e9a4*)camera, 0xf000);
    SetField0x238False_020a27a0(camera);
    return 1;
}
