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
extern "C" void _Z26CopyInternalFields0207df50P11Foo0207df50(Foo0207df50* p);
extern "C" void _Z25RestorePairTables0207df90Pc(char* p);
extern "C" void _Z24BackupPairTables0207dfacPc(char* p);
extern "C" void _Z40InitTenAllocatorsAndClearFields_021e4e8cPv(void* model);
extern "C" void _Z24CreateTenAndOne_021e4f64PvP13SafeAllocator(void* model, SafeAllocator* allocator);
extern "C" void _Z23InitBlockArray_021e4fd8Pv(void* model);
extern "C" void _Z18SetIntC0C_021e6198Pvi(void* model, int value);
extern "C" void _Z19SetByteC11_021e6150Pvh(void* model, unsigned char value);
extern "C" void _Z22InitWordsQuad_021e60e0Pvj(void* model, unsigned int value);
extern "C" void func_ov023_021fc71c(void* obj, int id, int flagArg);
char* GetFieldIfFlag4(char* gameState);
void SetVec3At0x4(Vec3Target0202e5c0* camera, int x, int y, int z);
void SetFields0x10To0x18(unsigned char* camera, int x, int y, int z);
int GetField0x58(void* camera);
extern "C" void _Z28SetAngleAndTrigTable0202e9a4P17AngleTrig0202e9a4i(AngleTrig0202e9a4* camera, int angle);
void SetField0x238False(void* camera);

// JPN: func_ov023_021fb810
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
    _Z26CopyInternalFields0207df50P11Foo0207df50((Foo0207df50*)pairTables);
    _Z25RestorePairTables0207df90Pc(pairTables);
    for (int i = 0; i < 2; i++) {
        _Z40InitTenAllocatorsAndClearFields_021e4e8cPv(&self->models_[i]);
        _Z24CreateTenAndOne_021e4f64PvP13SafeAllocator(&self->models_[i], &heapNode->allocator);
        _Z23InitBlockArray_021e4fd8Pv(&self->models_[i]);
        _Z18SetIntC0C_021e6198Pvi(&self->models_[i], perspective);
        _Z19SetByteC11_021e6150Pvh(&self->models_[i], 1);
    }
    _Z24BackupPairTables0207dfacPc(pairTables);

    _Z22InitWordsQuad_021e60e0Pvj(&self->models_[0], 0x1eb);
    _Z22InitWordsQuad_021e60e0Pvj(&self->models_[1], 0x1eb);
    if (character >= 0)
        func_ov023_021fc71c(self, character, 0);

    char* camera = GetFieldIfFlag4((char*)GameState::GetInstance());
    SetVec3At0x4((Vec3Target0202e5c0*)camera, 0xb666, 0xb800, 0x42ccc);
    SetFields0x10To0x18((unsigned char*)camera, 0xb666, 0xb800, 0);
    self->perspective_ = GetField0x58(camera);
    _Z28SetAngleAndTrigTable0202e9a4P17AngleTrig0202e9a4i((AngleTrig0202e9a4*)camera, 0xf000);
    SetField0x238False(camera);
    return 1;
}
