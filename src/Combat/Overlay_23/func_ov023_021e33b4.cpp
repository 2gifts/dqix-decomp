#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/Field3b0.h"
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
#include "GameState/GameState.h"

struct GameResources;
struct Pair020deb08;
struct EntryList020deb24;
struct Obj02159c24;
struct Foo0207df50;
struct Vec3Target0202e5c0;
struct Struct0205a198;
struct ActiveEntry02046900;
struct Rec020467f0;
struct Container020e0310;

struct Model021e33b4 {
    char unk_0[0xc20];
};

struct SpriteList021e33b4 {
    char unk_0[0x3c];
    void* ptr_3c;
    void* entries_40;
    char unk_44[0x4c - 0x44];
    unsigned short count_4c;
    char unk_4e[0x50 - 0x4e];
    unsigned char flag_50;

    void SetEntries(void* entries, int count)
    {
        entries_40 = entries;
        count_4c = count;
    }
};

struct TextArg021e33b4 {
    int unk_0;
    int unk_4;
    unsigned int lo_8 : 24;
    unsigned int index_8 : 2;
    unsigned int hi_8 : 6;
};

struct BattleSetup021e33b4 {
    void* battle_0;
    SafeAllocator* allocator_4;
    char* pairTables_8;
    void* unk_c;
    SafeAllocator* allocator_10;
    SafeAllocator* allocator_14;
    char unk_18[0x2c - 0x18];
    SafeAllocator bufferAllocator_2c;
    SafeAllocator allocator_40;
    char unk_54[0x68 - 0x54];
    SafeAllocator spriteAllocator_68;
    SafeAllocator tableAllocator_7c;
    SafeAllocator dataAllocator_90;
    char descriptor_a4[0xbc - 0xa4];
    unsigned short entryCount_bc;
    unsigned short maxEntry_be;
    void* data_c0;
    unsigned int dataSize_c4;
    SpriteList021e33b4* sprites_c8;
    char* spriteEntries_cc;
    void* spriteExtra_d0;
    char table_d4[0x120 - 0xd4];
    Model021e33b4* models_120[2];
    Model021e33b4* current_128[2];
    char unk_130[0x138 - 0x130];
    void* camera_138;
    char camera_13c[0x404 - 0x13c];
    char pairTables_404[0x474 - 0x404];
    char pairTables_474[0x4e4 - 0x474];
    unsigned char step_4e4;
    signed char mode_4e5;
    char unk_4e6[0x4fc - 0x4e6];
    int combatant_4fc;
    char unk_500[0x630 - 0x500];
    int task_630;
    unsigned short flags_634;
    void* buffer_638;
    void* buffer_63c;
    void* buffers_640[2];
};

extern const char* data_020f2a38;
extern const char* data_020f2a30;
extern const char* data_020f2a40;
extern const char data_ov023_021fd66c[];
extern const char data_ov023_021fdca4[];
extern const char data_ov023_021fdcb6[];
extern const char data_ov023_021fdcc4[];
extern const char data_ov023_021fdc94[];

extern "C" void* memset(void* dst, int value, unsigned int length);
extern "C" void* memcpy(void* dst, const void* src, unsigned int length);

int IsMainBrightnessTransitionActive(GameResources* resources);
void SetBitsInField4_0203b4d8(unsigned int* field, unsigned int bits);
void RestorePairTables0207df90(char* tables);
void BackupPairTables0207dfac(char* tables);
void CopyInternalFields0207df50(Foo0207df50* tables);
void ZeroInit020de848(void* descriptor);
void BuildDescriptorFlag1_020dea40(void* descriptor, void* allocator, void* data, int size, int flag);
int GetMaxOfHalfwords0And4(Pair020deb08* descriptor);
void GetEntryByIndex020deb24(EntryList020deb24* descriptor, int index);
void InitTenAllocatorsAndClearFields_021e4e8c(void* model);
void CreateTenAndOne_021e4f64(void* model, SafeAllocator* allocator);
void InitBlockArray_021e4fd8(void* model);
void SetIntC0C_021e6198(void* model, int value);
void SetByteC11_021e6150(void* model, unsigned char value);
void InitWordsQuad_021e60e0(void* model, unsigned int value);
void* GetGlobalField0x1c020421a0();
void SetField0x1e28_02042b30(void* messages, void* tables);
void SetField0x3b0Value_020100c4(GameState* gameState, int camera);
int GetField0x3acValue_020100a8(GameState* gameState);
void InitCombatController020a2010(void* camera);
void SetVec3At0x4(Vec3Target0202e5c0* camera, int x, int y, int z);
void SetFields0x10To0x18_0202e5c8(unsigned char* camera, int x, int y, int z);
void SetField0x238False_020a27a0(void* camera);
void SetFogState_020c54a4(int a, unsigned int b, unsigned int c, unsigned short d);
void InitStruct0205a444(char* list);
void Init0205a198(Struct0205a198* entry);
int CountActiveEntries(ActiveEntry02046900* file);
void* FindRecordByIndex(Rec020467f0* file, int index, void** record, int* size);
void Clear12Bytes020e46c4(void* arg);
void InitObjFromCombatantId020e4bf4(void* arg, int combatant);
void* GetFieldByKey020e0434(Container020e0310* container, int key);
void ClearFields_021e20c0(void* table);
void* GetFieldAt0x150_02053c6c(unsigned char* combatant);
void CallWithAddr4000330_020c555c(int addr);
void CopyByteFieldToNextAndSet_021e33a0_021e33a0(char* self, signed char mode);
void InitEntryManagerAndAllocator02159c24(Obj02159c24*, int, int);

extern "C" {
GameResources* func_ov017_0218b5b0();
void func_ov017_0219ba0c(GameResources* resources, int value);
void func_ov005_02153ba4(void* battle);
void func_ov005_02153954(void* battle, SafeAllocator* allocator, void* unk);
void func_ov004_02154da8(void* battle, void* data, unsigned int size);
void func_ov005_02153b20(void* battle);
int func_ov005_0215436c(void* battle);
void func_ov005_0215a960(void* battle);
void func_ov005_0215ae7c(void* battle);
void func_020dea64(void* descriptor, SafeAllocator* allocator, void* data, unsigned int size, const void* entries, int count);
void func_0207de48(void* tables, int a, int b);
void func_020432c4(void* messages);
void func_0205a528(void* sprites, void* record, int size, SafeAllocator* allocator);
void func_02046380(void* messages);
void func_02046608(void* messages, int a, void* format, void* output, int size, int b, int c);
void func_ov023_021e20f0(void* table, void* allocator, void* data, unsigned int size);
void func_ov023_021e3d3c(void* table, int id, int value);
int func_ov023_021e5974(void* model, void* a, int combatant, int b, int c);
void func_ov023_021e49a4(BattleSetup021e33b4* self);
void func_ov023_021e2ce8(int combatant, void* sprites);
}

// USA: func_ov023_021e33b4
extern "C" ARM void func_ov023_021e33b4(BattleSetup021e33b4* self)
{
    GameState* gameState = GameState::GetInstance();
    GameResources* resources = func_ov017_0218b5b0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (self->step_4e4 == 0)
        self->step_4e4++;

    if (IsMainBrightnessTransitionActive(resources))
        return;

    if (self->step_4e4 == 1)
    {
        FontBankLoader* music = GetGlobal02109400_02094a00();
        BlankFunction02094b40(music);
        BlankFunction02094b34(music, 0x79, 0x1fa, 0, 0);
        self->step_4e4++;
    }
    else if (self->step_4e4 == 2)
    {
        if (AlwaysTrue02094b4c(GetGlobal02109400_02094a00()))
        {
            func_ov017_0219ba0c(resources, 1);
            self->task_630 = loader->QueueLoadFileInGP2(data_020f2a38, data_020f2a30, NULL);
            self->step_4e4++;
        }
    }
    else if (self->step_4e4 == 3)
    {
        if (loader->GetTaskStatus(self->task_630))
        {
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_630, &data, &size);
            SetBitsInField4_0203b4d8((unsigned int*)resources, 0x601fe);
            RestorePairTables0207df90(self->pairTables_8);
            self->allocator_14->Reset();
            ZeroInit020de848(self->descriptor_a4);
            BuildDescriptorFlag1_020dea40(self->descriptor_a4, self->allocator_14, data, size, 0xb);
            self->maxEntry_be = GetMaxOfHalfwords0And4((Pair020deb08*)self->descriptor_a4);
            self->entryCount_bc = self->maxEntry_be + 0x31;
            for (int i = 0; i < self->entryCount_bc; i++)
                GetEntryByIndex020deb24((EntryList020deb24*)self->descriptor_a4, (short)i);
            self->allocator_14->Reset();

            if (self->mode_4e5 == 3)
            {
                self->battle_0 = self->allocator_10->Allocate(0x428c);
                func_ov005_02153ba4(self->battle_0);
                func_ov005_02153954(self->battle_0, self->allocator_10, self->unk_c);
                func_ov004_02154da8(self->battle_0, data, size);
            }

            self->bufferAllocator_2c.CreateTypeA(self->allocator_10->Allocate(0x800), 0x800);
            self->allocator_40.CreateTypeA(self->allocator_10->Allocate(0x100), 0x100);
            for (int i = 0; i < 2; i++)
            {
                self->buffers_640[i] = self->bufferAllocator_2c.Allocate(0x40);
                memset(self->buffers_640[i], 0, 0x40);
            }

            self->spriteAllocator_68.CreateTypeA(self->allocator_4->Allocate(0x100), 0x100);
            self->sprites_c8 = (SpriteList021e33b4*)self->allocator_4->Allocate(0x54);
            self->spriteEntries_cc = (char*)self->allocator_4->Allocate(0x280);
            self->spriteExtra_d0 = self->allocator_4->Allocate(8);
            if (self->battle_0 != NULL && self->spriteExtra_d0 != NULL && self->sprites_c8 != NULL)
                InitEntryManagerAndAllocator02159c24((Obj02159c24*)self->battle_0, (int)self->spriteExtra_d0, (int)self->sprites_c8);

            self->tableAllocator_7c.CreateTypeA(self->allocator_4->Allocate(0x300), 0x300);
            self->dataAllocator_90.CreateTypeA(self->allocator_4->Allocate(0x200), 0x200);

            self->models_120[0] = (Model021e33b4*)self->allocator_4->Allocate(0xc20);
            InitTenAllocatorsAndClearFields_021e4e8c(self->models_120[0]);
            CreateTenAndOne_021e4f64(self->models_120[0], self->allocator_4);
            InitBlockArray_021e4fd8(self->models_120[0]);
            SetIntC0C_021e6198(self->models_120[0], (int)self->descriptor_a4);
            SetByteC11_021e6150(self->models_120[0], 1);

            self->models_120[1] = (Model021e33b4*)self->allocator_4->Allocate(0xc20);
            InitTenAllocatorsAndClearFields_021e4e8c(self->models_120[1]);
            CreateTenAndOne_021e4f64(self->models_120[1], self->allocator_4);
            InitBlockArray_021e4fd8(self->models_120[1]);
            SetIntC0C_021e6198(self->models_120[1], (int)self->descriptor_a4);
            SetByteC11_021e6150(self->models_120[1], 1);

            self->allocator_14->Reset();
            ZeroInit020de848(self->descriptor_a4);
            func_020dea64(self->descriptor_a4, self->allocator_14, data, size, data_ov023_021fd66c, 9);

            self->buffer_638 = self->bufferAllocator_2c.Allocate(0x2a0);
            memset(self->buffer_638, 0, 0x2a0);
            self->buffer_63c = self->bufferAllocator_2c.Allocate(0x400);
            memset(self->buffer_63c, 0, 0x400);

            if (self->battle_0 != NULL)
                *(void**)((char*)self->battle_0 + 0xdf4) = self->descriptor_a4;

            func_0207de48(self->pairTables_474, 0x4000, 0x40);
            CopyInternalFields0207df50((Foo0207df50*)self->pairTables_474);
            if (self->mode_4e5 == 3 && self->battle_0 != NULL)
                func_ov005_02153b20(self->battle_0);

            func_0207de48(self->pairTables_404, 0, 0);
            CopyInternalFields0207df50((Foo0207df50*)self->pairTables_404);

            void* messages = GetGlobalField0x1c020421a0();
            SetField0x1e28_02042b30(messages, self->pairTables_474);
            RestorePairTables0207df90(self->pairTables_474);
            func_020432c4(messages);
            BackupPairTables0207dfac(self->pairTables_474);

            self->camera_138 = GetField0x3b0Value_020100bc(gameState);
            InitCombatController020a2010(self->camera_13c);
            SetVec3At0x4((Vec3Target0202e5c0*)self->camera_13c, 0xb666, 0xa800, 0x42ccc);
            SetFields0x10To0x18_0202e5c8((unsigned char*)self->camera_13c, 0xb666, 0xa800, 0);
            SetField0x238False_020a27a0(self->camera_13c);
            SetField0x3b0Value_020100c4(gameState, (int)self->camera_13c);
            SetFogState_020c54a4(0, 0, 0, 0);

            loader->RemoveTask(self->task_630);
            self->task_630 = -1;
            self->task_630 = loader->QueueLoadFile(data_020f2a40, NULL);
            self->step_4e4++;
        }
    }
    else if (self->step_4e4 == 4)
    {
        if (loader->GetTaskStatus(self->task_630))
        {
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_630, &data, &size);
            self->data_c0 = self->dataAllocator_90.Allocate(size);
            memcpy(self->data_c0, data, size);
            self->dataSize_c4 = size;
            loader->RemoveTask(self->task_630);
            self->task_630 = -1;

            InitStruct0205a444((char*)self->sprites_c8);
            self->sprites_c8->flag_50 = 0;
            self->sprites_c8->SetEntries(self->spriteEntries_cc, 0x10);
            self->sprites_c8->ptr_3c = self->spriteExtra_d0;
            for (int i = 0; i < 0x10; i++)
                Init0205a198((Struct0205a198*)(self->spriteEntries_cc + i * 0x28));

            self->task_630 = loader->QueueLoadFileInGP2(data_ov023_021fdca4, data_ov023_021fdcb6, NULL);
            self->step_4e4++;
        }
    }
    else if (self->step_4e4 == 5)
    {
        if (loader->GetTaskStatus(self->task_630))
        {
            self->spriteAllocator_68.Reset();
            void* record;
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_630, &data, &size);
            int count = CountActiveEntries((ActiveEntry02046900*)data);
            for (int i = 0; i < count; i++)
            {
                int recordSize;
                void* found = FindRecordByIndex((Rec020467f0*)data, i, &record, &recordSize);
                if (found != NULL)
                    func_0205a528(self->sprites_c8, found, recordSize, &self->spriteAllocator_68);
            }
            loader->RemoveTask(self->task_630);
            self->task_630 = -1;
            self->step_4e4++;
        }
    }
    else if (self->step_4e4 == 6)
    {
        if (self->battle_0 != NULL)
        {
            if (func_ov005_0215436c(self->battle_0))
                self->step_4e4++;
        }
    }
    else if (self->step_4e4 == 7)
    {
        TextArg021e33b4 arg;
        Clear12Bytes020e46c4(&arg);
        InitObjFromCombatantId020e4bf4(&arg, GetField0x3acValue_020100a8(gameState));
        void* messages = GetGlobalField0x1c020421a0();
        Container020e0310* texts = (Container020e0310*)((char*)self->battle_0 + 0xdf8);
        for (int i = 0; i < 2; i++)
        {
            arg.index_8 = i;
            func_02046380(messages);
            *(TextArg021e33b4**)messages = &arg;
            func_02046608(messages, 8, GetFieldByKey020e0434(texts, 0x226), self->buffers_640[i], 0x100, 0, 0);
        }
        self->task_630 = loader->QueueLoadFile(data_ov023_021fdcc4, NULL);
        self->step_4e4++;
    }
    else if (self->step_4e4 == 8)
    {
        if (loader->GetTaskStatus(self->task_630))
        {
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_630, &data, &size);
            if (data != NULL)
            {
                self->tableAllocator_7c.Reset();
                ClearFields_021e20c0(self->table_d4);
                func_ov023_021e20f0(self->table_d4, &self->tableAllocator_7c, data, size);
                func_ov023_021e3d3c(self->table_d4, 1, 1);
            }
            loader->RemoveTask(self->task_630);
            self->task_630 = -1;
            self->step_4e4++;
        }
    }
    else
    {
        void* combatant = GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), self->combatant_4fc);
        if (combatant != NULL)
        {
            InitWordsQuad_021e60e0(self->models_120[0], 0x1eb);
            func_ov023_021e5974(self->models_120[0], GetFieldAt0x150_02053c6c((unsigned char*)combatant), self->combatant_4fc, 0, 0);
        }
        self->current_128[0] = self->models_120[0];
        self->current_128[1] = self->models_120[1];
        self->flags_634 |= 0xa1;
        func_ov023_021e49a4(self);
        if (self->mode_4e5 == 3 && self->battle_0 != NULL)
        {
            func_ov005_0215a960(self->battle_0);
            func_ov005_0215ae7c(self->battle_0);
        }
        CallWithAddr4000330_020c555c((int)data_ov023_021fdc94);
        func_ov023_021e3d3c(self->table_d4, 0x11, 1);
        func_ov023_021e3d3c(self->table_d4, 0x12, 1);
        func_ov023_021e3d3c(self->table_d4, 0x1b, 1);
        func_ov023_021e3d3c(self->table_d4, 0x20, 1);
        func_ov023_021e2ce8(self->combatant_4fc, self->sprites_c8);
        CopyByteFieldToNextAndSet_021e33a0_021e33a0((char*)self, self->mode_4e5);
        self->step_4e4 = 0;
        self->flags_634 &= ~0x2000;
    }
}
