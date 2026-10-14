#include <globaldefs.h>
extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Filesystem/GPC.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "World/Object3D.h"

struct BackgroundGraphics {
    char unk_0[0x1c];
    unsigned char unk_1c_0_ : 4;
    unsigned char unk_1c_4_ : 4;
    unsigned char unk_1d;
    char unk_1e[2];
};

struct Canvas {
    char unk_0[4];
    BackgroundGraphics* background_;
    char unk_8[0xe0 - 8];
};

struct CanvasList {
    char unk_0[0x98];
    BackgroundGraphics* background_;
    char unk_9c[0xb2 - 0x9c];
    unsigned char unk_b2;
    char unk_b3[0xbc - 0xb3];
};

struct Entry0205a198 { char unk_0[0x28]; };

struct Table0205a444 {
    char unk_0[0x3c];
    void* tail_;
    Entry0205a198* entries_;
    char unk_44[0x4c - 0x44];
    short entryCount_;
    char unk_4e[2];
    unsigned char unk_50;
};

struct Look {
    short unk_0;
    short unk_2;
    short unk_4;
    short unk_6;
    short unk_8;
    short unk_a;
    short unk_c;
    short unk_e;
    short unk_10;
    short unk_12;
    unsigned char sex_ : 1;
    unsigned char unk_14_1_ : 3;
    unsigned char unk_14_4_ : 4;
    unsigned char unk_15_0_ : 4;
    unsigned char unk_15_4_ : 4;
    short unk_16;
    short unk_18;
    short unk_1a;
};

struct Hero {
    char unk_0[0x488];
    Look look_;
    char unk_4a4[0x568 - 0x4a4];
    short unk_568;
};

struct LookDefaults { short unk[10]; };
struct Scene {
    char unk_0[0x800];
    char camera_[0xc58 - 0x924];
};

struct Ov3Obj {
    char unk_0[4];
    void* unk_4;
};

struct CharacterCreation {
    SafeAllocator allocators_[9];
    SafeAllocator* modelAllocator_;
    char unk_b8[0xc0 - 0xb8];
    Ov3Obj* unk_c0;
    void* unk_c4;
    char unk_c8[0xe0 - 0xc8];
    char strings_[0xf8 - 0xe0];
    int unk_f8;
    char unk_fc[0x138 - 0xfc];
    BackgroundGraphics backgrounds_[6];
    CanvasList canvasListA_;
    CanvasList canvasListB_;
    Canvas canvasA_[1];
    Canvas canvasB_[4];
    void* canvasBufA_;
    void* canvasBufB_;
    Table0205a444* tableA_;
    Entry0205a198* entriesA_;
    void* tailA_;
    Table0205a444* tableB_;
    Entry0205a198* entriesB_;
    void* tailB_;
    void* models_[2];
    void* current_;
    void* next_;
    char unk_800[0x808 - 0x800];
    char pairs_[0x878 - 0x808];
    char object_[0x924 - 0x878];
    char camera_[0xc58 - 0x924];
    signed char state_;
    unsigned char step_;
    char unk_c5a[0xc68 - 0xc5a];
    char unk_c68[0xd88 - 0xc68];
    Hero* hero_;
    char unk_d8c[0xd90 - 0xd8c];
    int task_;
    unsigned char loadStep_;
    unsigned char mode_;
    char unk_d96[0xd9c - 0xd96];
    unsigned int flags_;
    char unk_da0[0xda2 - 0xda0];
    unsigned char unk_da2;
    unsigned char sex_;
    unsigned char unk_da4[2];
    unsigned char unk_da6[2];
    unsigned char unk_da8[2];
    unsigned char unk_daa[2];
    unsigned char unk_dac[2];
    unsigned char unk_dae[2];
};

struct List0204af64;
struct Obj0204b5e8;
struct AllocTarget0204b12c;
struct Foo0204af38;
struct Rec020467f0;
struct ActiveEntry02046900;
struct Obj0204b8d0;
struct List0204b0e8;
struct Obj0204c7a8;
struct Struct_0205cf78;
struct Elem_0205cf78;
struct Struct_0205d81c;
struct Container020e0310;
struct Foo0207df50;

struct GameResources;
GameResources* GetWord0x0(int* gameState);
char* GetGlobalField0x1c020421a0();
void ZeroInit020de848(void* obj);
extern "C" void func_020de9a4(void* list, SafeAllocator* alloc, void* data, unsigned int size, const void* entries, int count);
extern "C" void func_020dfec0(void* container, SafeAllocator* alloc, void* data, unsigned int size);
void InitTenAllocatorsAndClearFields_021e4e8c(void* model);
void CreateTenAndOne_021e4f64(void* model, SafeAllocator* alloc);
void InitBlockArray_021e4fd8(void* model);
void SetIntC0C_021e6198(void* model, int value);
const char* GetFieldByKey020e0434(Container020e0310* c, int key);
extern "C" void func_0207de48(void* p, int a, int b);
void CopyInternalFields0207df50(Foo0207df50* p);
void RestorePairTables0207df90(char* p);
void BackupPairTables0207dfac(char* p);
void InitCombatController020a2010(void* camera);
struct Vec3Target0202e5c0;
void SetVec3At0x4(Vec3Target0202e5c0* camera, int x, int y, int z);
void SetFields0x10To0x18(unsigned char* camera, int a, int b, int c);
extern "C" void func_0202e0a4(void* camera);
void SetField0x238False(void* camera);
void SetField0x3b0Value(GameState* gs, int camera);
void GetEntryPair02188bf8(unsigned char* base, int idx, short* out0, short* out1);
extern "C" int func_ov009_02188b14(void* self, int type, int idx);
extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
extern "C" void func_ov023_021e5e68(void* model, short a, short b);
void SetByteC11_021e6150(void* model, unsigned char value);
void ResetList0204af64(List0204af64* background);
void SetWord0x18ClearByte0x1f(unsigned char* background, int value);
extern "C" void func_0204b5b4(BackgroundGraphics* background, int screen);
void DispatchViaTable0204b5e8(Obj0204b5e8* background, int a, int b);
void AllocateAndClearBuffer0204b12c(AllocTarget0204b12c* background, SafeAllocator* allocator);
void AllocateArray0204af38(Foo0204af38* background, int count, SafeAllocator* allocator);
int CountActiveEntries(ActiveEntry02046900* archive);
void* FindRecordByIndex(Rec020467f0* archive, int index, void** name, int* size);
extern "C" void func_0204b174(BackgroundGraphics* background, void* file, SafeAllocator* allocator, unsigned int size);
void DispatchEntry0204b8d0(Obj0204b8d0* background, unsigned int a, int b, int c, short d, short e, short f, short g,
                           unsigned short h);
void FlushAndDispatchList0204b0e8(List0204b0e8* background, void* a);
extern "C" void func_0204bc74(BackgroundGraphics* background, int a, int b, int c, int d, int e, int f);
extern "C" void func_ov023_021da274(void* self);
void AllocateBuffer0204c7a8(Obj0204c7a8* obj, SafeAllocator* alloc, int buffer, unsigned int len);
void LinkArrayPrevPointers0205cf78(Struct_0205cf78* list, Elem_0205cf78* elems, unsigned char count);
void InitStruct0205a444(char* table);
struct Struct0205a198;
void Init0205a198(Struct0205a198* entry);
struct ClearTarget0205a234;
void ClearField0And40205a234(ClearTarget0205a234* tail);
extern "C" void func_0205a528(Table0205a444* table, void* file, int size, SafeAllocator* alloc);
extern "C" void func_ov003_0215e6f8(void* obj, SafeAllocator* alloc, void* data, unsigned int size);
extern "C" void func_ov003_0215f41c(Ov3Obj* obj, const char* name);
extern "C" unsigned char* func_ov003_0215f4fc(Ov3Obj* obj, const char* name);
void InitWordsQuad_021e60e0(void* model, unsigned int angle);
extern "C" void func_ov023_021e5974(void* model, Hero* hero, short a, int b, int c);
extern "C" void func_ov023_021d99a4(void* self);
void SetupTag021d9c7c(void* self);
void SetupTag021d9da4(void* self);
void SetElementFieldC2(Struct_0205d81c* s, int key, int value);
void SetStatValue021855dc(unsigned char* self, int val);

extern const char data_ov009_0218acb0[];
extern const char data_ov009_0218acc9[];
extern const char* data_020f2a38;
extern const char* data_020f2a30;
extern const char data_ov009_0218ab48[];

extern const char data_ov009_0218acd9[];
extern signed char data_ov009_0218a9bc[10];
extern const LookDefaults data_ov009_0218aa40;
extern const unsigned char data_ov009_0218a96c[];
extern const unsigned char data_ov009_0218a994[];
extern const signed char data_ov009_0218a998[];
extern const signed char data_ov009_0218a99c[];
extern const unsigned short data_ov009_0218a9a4[];
extern const char data_ov009_0218acf4[];
extern const char data_ov009_0218ad0d[];
extern const char data_ov009_0218ad26[];
extern const char data_ov009_0218ad28[];

enum PairTableSize { kPairTableSize = 0xc00 };
enum PairTableAlign { kPairTableAlign = 0x30 };

// USA: func_ov009_02185634
extern "C" ARM void func_ov009_02185634(CharacterCreation* self)
{
    unsigned int offset;
    GameState* gs = GameState::GetInstance();
    GetWord0x0((int*)gs);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    unsigned char step = self->step_;
    if (step == 0)
    {
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        unsigned int size;
        void* data = ExtractFileFromGP2(data_ov009_0218acb0, data_ov009_0218acc9, &size);
        self->allocators_[5].Reset();
        func_020dfec0(self->strings_, &self->allocators_[5], data, size);
        BackgroundLoader::RemoveLockGlobal();
        self->unk_f8 = *(int*)(GetGlobalField0x1c020421a0() + 0x5c);
        ZeroInit020de848(self->unk_c8);
        BackgroundLoader::AddLockGlobal();
        unsigned int listSize;
        void* list = ExtractFileFromGP2(data_020f2a38, data_020f2a30, &listSize);
        if (list != NULL)
            func_020de9a4(self->unk_c8, &self->allocators_[4], list, listSize, data_ov009_0218ab48, 0x29);
        BackgroundLoader::RemoveLockGlobal();

        self->models_[0] = self->allocators_[3].Allocate(0xc20);
        void* model0 = self->models_[0];
        InitTenAllocatorsAndClearFields_021e4e8c(model0);
        CreateTenAndOne_021e4f64(model0, &self->allocators_[3]);
        InitBlockArray_021e4fd8(model0);
        SetIntC0C_021e6198(model0, (int)self->unk_c8);
        self->models_[1] = self->allocators_[3].Allocate(0xc20);
        void* model1 = self->models_[1];
        InitTenAllocatorsAndClearFields_021e4e8c(model1);
        CreateTenAndOne_021e4f64(model1, &self->allocators_[3]);
        InitBlockArray_021e4fd8(model1);
        SetIntC0C_021e6198(model1, (int)self->unk_c8);

        if (self->mode_ == 0)
        {
            BackgroundLoader::AddLockGlobal();
            BackgroundLoader::FreeAllocationsGlobal();
            GPCReadPair pair;
            GPCReadPair* rp = &pair;
            unsigned int length = 0;
            unsigned char* buf = data_0211e33c;
            int room = 0x30000;
            ZeroInitGPCPointer(&rp->pGPCFile);
            rp->ZeroInitializeMachine();
            if (LoadAndDecompressGPCHeaderAndInnerFileInfo(&pair.pGPCFile, pair.machine, data_ov009_0218acd9, buf,
                                                           length, room, false, 0))
            {
                offset = length;
                room -= offset;
                PairTableSize pairSize = kPairTableSize;
                PairTableAlign pairAlign = kPairTableAlign;
                if (DecompressFileFromGPCByName(pair.pGPCFile, pair.machine, buf + offset, length, room,
                                                GetFieldByKey020e0434((Container020e0310*)self->strings_, 0x7d0)))
                {
                    func_0207de48(self->pairs_, pairSize, pairAlign);
                    CopyInternalFields0207df50((Foo0207df50*)self->pairs_);
                    RestorePairTables0207df90(self->pairs_);
                    ((Object3D*)self->object_)->SetModelFromFileCopy(self->modelAllocator_, buf + offset, length,
                                                       Model3D::TextureStagingMode_Normal);
                    BackupPairTables0207dfac(self->pairs_);
                }
            }
            BackgroundLoader::RemoveLockGlobal();
            func_0207de48(self->unk_c68, 0x1a00, 0x20);
            pair.Reset();
            ZeroDestroyGPCPointer(&pair.pGPCFile);
        }

        Scene* scene = (Scene*)((char*)self + 0x124);
        InitCombatController020a2010(scene->camera_);
        SetVec3At0x4((Vec3Target0202e5c0*)scene->camera_, 0xd000, 0xf800, 0x42ccc);
        SetFields0x10To0x18((unsigned char*)scene->camera_, 0xd000, 0xf800, 0);
        func_0202e0a4(scene->camera_);
        SetField0x238False(scene->camera_);
        SetField0x3b0Value(gs, (int)scene->camera_);

        self->sex_ = 0;
        self->unk_da4[0] = 2;
        self->unk_da4[1] = 2;
        self->unk_da6[0] = 0;
        self->unk_da6[1] = 0;
        self->unk_da8[0] = 0;
        self->unk_da8[1] = 5;
        self->unk_daa[0] = 3;
        self->unk_daa[1] = 3;
        self->unk_dac[0] = 0;
        self->unk_dac[1] = 0;
        self->unk_dae[0] = 0;
        self->unk_dae[1] = 3;
        if (self->mode_ == 1)
        {
            self->unk_da6[0] = 1;
            self->unk_da6[1] = 1;
            self->unk_dac[1] = 1;
            self->unk_da8[1] = 0;
            self->unk_dae[1] = 0;
        }

        LookDefaults defaults;
        BackgroundGraphics* backgrounds[4];
        Look* look = &self->hero_->look_;
        look->sex_ = self->sex_;
        look->unk_14_1_ = self->unk_daa[self->sex_];
        int hair = self->unk_da8[self->sex_];
        {
            signed char ids[10];
            int n;
            unsigned char* d;
            unsigned char* s = (unsigned char*)data_ov009_0218a9bc;
            d = (unsigned char*)ids;
            n = 10;
            do {
                unsigned char v = *s;
                s++;
                *d = v;
                d++;
            } while (--n);
        }
        look->unk_14_4_ = hair;
        {
            signed char ids[10];
            int n;
            unsigned char* d;
            unsigned char* s;
            int eyes = self->unk_dae[self->sex_];
            s = (unsigned char*)data_ov009_0218a9bc;
            d = (unsigned char*)ids;
            n = 10;
            do {
                unsigned char v = *s;
                s++;
                *d = v;
                d++;
            } while (--n);
            look->unk_15_0_ = eyes;
        }
        GetEntryPair02188bf8((unsigned char*)self, self->unk_da4[self->sex_], &look->unk_18, &look->unk_1a);
        short top = func_ov009_02188b14(self, 5, self->unk_da6[self->sex_]) + 0x233c;
        short bottom = func_ov009_02188b14(self, 3, self->unk_dac[self->sex_]) + 0x2328;
        defaults = data_ov009_0218aa40;
        defaults.unk[2] = top;
        defaults.unk[3] = bottom;
        memcpy(look, &defaults, 0x14);
        look->unk_16 = -1;
        func_ov023_021e5e68(model0, look->unk_18, look->unk_1a);
        func_ov023_021e5e68(model1, look->unk_18, look->unk_1a);

        if (self->unk_da2 != 0)
        {
            SetByteC11_021e6150(model0, 1);
            SetByteC11_021e6150(model1, 1);
            switch (self->unk_da2)
            {
            case 1:
            case 7:
            case 8:
                look->unk_e = 0x4e24;
                break;
            case 2:
            case 9:
                look->unk_e = 0x5014;
                break;
            case 3:
            case 10:
                look->unk_e = 0x4fb3;
                break;
            case 4:
                look->unk_e = 0x5078;
                break;
            case 6:
            case 11:
                look->unk_e = 0x4e84;
                break;
            case 5:
                look->unk_e = 0x4a6a;
                break;
            case 12:
                look->unk_e = 0x50dc;
                break;
            }
            look->unk_0 = 0x32cd;
            look->unk_16 = 0x36b5;
            look->unk_2 = 0x3f55;
            look->unk_a = 0x43fe;
        }
        if (self->mode_ == 0)
        {
            look->unk_0 = 0x32cf;
            look->unk_16 = 0x36b7;
            look->unk_2 = 0x3f57;
            look->unk_a = 0x42e0;
        }

        backgrounds[0] = &self->backgrounds_[0];
        backgrounds[1] = &self->backgrounds_[1];
        backgrounds[2] = &self->backgrounds_[2];
        backgrounds[3] = &self->backgrounds_[5];
        for (int i = 0; i < 4; i++)
        {
            BackgroundGraphics* background = backgrounds[i];
            SafeAllocator* allocator = &self->allocators_[0];
            if (i == 3)
                allocator = &self->allocators_[2];
            ResetList0204af64((List0204af64*)background);
            SetWord0x18ClearByte0x1f((unsigned char*)background, 0);
            unsigned char lo = data_ov009_0218a96c[i];
            background->unk_1c_0_ = lo;
            background->unk_1c_4_ = data_ov009_0218a994[i];
            func_0204b5b4(background, data_ov009_0218a998[i]);
            DispatchViaTable0204b5e8((Obj0204b5e8*)background, 0, 0);
            AllocateAndClearBuffer0204b12c((AllocTarget0204b12c*)background, allocator);
            if (data_ov009_0218a99c[i] > 0)
                AllocateArray0204af38((Foo0204af38*)background, (unsigned char)data_ov009_0218a99c[i], allocator);
        }

        signed char state = self->state_;
        const char* inner = GetFieldByKey020e0434((Container020e0310*)self->strings_, (short)(state + 0x32));
        self->task_ = loader->QueueLoadFileInGP2(GetFieldByKey020e0434((Container020e0310*)self->strings_, state),
                                                 inner, NULL);
        self->step_++;
    }
    else if (step == 1)
    {
        if (loader->GetTaskStatus(self->task_) != 0)
        {
            char name[4];
            void* archive;
            unsigned int archiveSize;
            int size;
            loader->GetLoadedFileByID(self->task_, &archive, &archiveSize);
            int count = CountActiveEntries((ActiveEntry02046900*)archive);
            if (self->mode_ == 1)
                count--;
            for (int i = 0; i < count; i++)
            {
                void* file = FindRecordByIndex((Rec020467f0*)archive, i, (void**)name, &size);
                if (file != NULL)
                {
                    if (i == 0)
                    {
                        func_0204b174(&self->backgrounds_[2], file, &self->allocators_[0], size);
                        func_0204b174(&self->backgrounds_[5], file, &self->allocators_[2], size);
                    }
                    else if (i <= 3)
                    {
                        func_0204b174(&self->backgrounds_[0], file, &self->allocators_[0], size);
                    }
                    else
                    {
                        func_0204b174(&self->backgrounds_[1], file, &self->allocators_[0], size);
                    }
                }
            }
            loader->RemoveTask(self->task_);
            self->task_ = -1;
            int visible = 1;
            if (self->mode_ == 1)
                visible = 0;
            DispatchEntry0204b8d0((Obj0204b8d0*)&self->backgrounds_[0], visible, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
            FlushAndDispatchList0204b0e8((List0204b0e8*)&self->backgrounds_[0], 0);
            func_0204bc74(&self->backgrounds_[1], 0, 0, 0, 0x20, 0x19, 0);
            FlushAndDispatchList0204b0e8((List0204b0e8*)&self->backgrounds_[1], 0);
            func_0204bc74(&self->backgrounds_[2], 0, 0, 0, 0x20, 0x19, 0);
            FlushAndDispatchList0204b0e8((List0204b0e8*)&self->backgrounds_[2], 0);
            func_0204bc74(&self->backgrounds_[5], 0, 0, 0, 0x20, 0x19, 0);
            FlushAndDispatchList0204b0e8((List0204b0e8*)&self->backgrounds_[5], 0);
            self->flags_ |= 0x1000;
            func_ov023_021da274(self);
            FlushAndDispatchList0204b0e8((List0204b0e8*)&self->backgrounds_[1], 0);
            self->flags_ &= ~0x1000;

            self->canvasBufA_ = self->allocators_[0].Allocate(0x1000);
            Canvas* canvas;
            unsigned int bufferSize = 0x200;
            for (int i = 0; i < 1; i++)
            {
                canvas = &self->canvasA_[i];
                AllocateBuffer0204c7a8((Obj0204c7a8*)canvas, &self->allocators_[0], (int)self->canvasBufA_, bufferSize);
                canvas->background_ = &self->backgrounds_[2];
            }
            self->canvasListA_.background_ = &self->backgrounds_[2];
            self->canvasListA_.unk_b2 = 1;
            LinkArrayPrevPointers0205cf78((Struct_0205cf78*)&self->canvasListA_, (Elem_0205cf78*)self->canvasA_, 1);

            self->canvasBufB_ = self->allocators_[2].Allocate(0x400);
            for (int i = 0; i < 4; i++)
            {
                canvas = &self->canvasB_[i];
                AllocateBuffer0204c7a8((Obj0204c7a8*)canvas, &self->allocators_[2], (int)self->canvasBufB_,
                                       data_ov009_0218a9a4[i]);
                canvas->background_ = &self->backgrounds_[5];
            }
            self->canvasListB_.background_ = &self->backgrounds_[5];
            self->canvasListB_.unk_b2 = 1;
            LinkArrayPrevPointers0205cf78((Struct_0205cf78*)&self->canvasListB_, (Elem_0205cf78*)self->canvasB_, 4);

            int i;
            Table0205a444* table = self->tableA_;
            InitStruct0205a444((char*)table);
            table->unk_50 = 0;
            table->entries_ = self->entriesA_;
            table->entryCount_ = 6;
            table->tail_ = self->tailA_;
            for (i = 0; i < 6; i++)
                Init0205a198((Struct0205a198*)&self->entriesA_[i]);
            ClearField0And40205a234((ClearTarget0205a234*)self->tailA_);

            Table0205a444* tableB = self->tableB_;
            InitStruct0205a444((char*)tableB);
            tableB->unk_50 = 1;
            tableB->entries_ = self->entriesB_;
            tableB->entryCount_ = 0x19;
            tableB->tail_ = self->tailB_;
            for (int j = 0; j < 0x19; j++)
                Init0205a198((Struct0205a198*)&self->entriesB_[j]);
            ClearField0And40205a234((ClearTarget0205a234*)self->tailB_);

            const char* inner = GetFieldByKey020e0434((Container020e0310*)self->strings_, 0x41a);
            self->task_ = loader->QueueLoadFileInGP2(GetFieldByKey020e0434((Container020e0310*)self->strings_, 1000),
                                                     inner, NULL);
            self->step_++;
        }
    }
    else if (step == 2)
    {
        if (loader->GetTaskStatus(self->task_) != 0)
        {
            char name[4];
            void* archive;
            unsigned int archiveSize;
            int size;
            loader->GetLoadedFileByID(self->task_, &archive, &archiveSize);
            int count = CountActiveEntries((ActiveEntry02046900*)archive);
            self->allocators_[6].Reset();
            for (int i = 0; i < count; i++)
            {
                void* file = FindRecordByIndex((Rec020467f0*)archive, i, (void**)name, &size);
                if (file != NULL)
                {
                    if (i < 4)
                        func_0205a528(self->tableA_, file, size, &self->allocators_[6]);
                    else
                        func_0205a528(self->tableB_, file, size, &self->allocators_[6]);
                }
            }
            loader->RemoveTask(self->task_);
            self->task_ = -1;
            self->step_++;
        }
    }
    else if (step == 3)
    {
        if (self->mode_ == 0)
            self->task_ = loader->QueueLoadFile(data_ov009_0218acf4, NULL);
        else
            self->task_ = loader->QueueLoadFile(data_ov009_0218ad0d, NULL);
        self->step_++;
    }
    else if (step == 4)
    {
        if (loader->GetTaskStatus(self->task_) != 0)
        {
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(self->task_, &data, &size);
            if (data != NULL && size != 0)
            {
                self->allocators_[8].Reset();
                func_ov003_0215e6f8(self->unk_c4, &self->allocators_[8], data, size);
                self->unk_c0->unk_4 = self->unk_c4;
                func_ov003_0215f41c(self->unk_c0, data_ov009_0218ad26);
                unsigned char* node = func_ov003_0215f4fc(self->unk_c0, data_ov009_0218ad28);
                if (node != NULL)
                    node[0xf] = 1;
            }
            loader->RemoveTask(self->task_);
            self->task_ = -1;
            self->step_++;
        }
    }
    else
    {
        InitWordsQuad_021e60e0(self->models_[0], 0x1eb);
        InitWordsQuad_021e60e0(self->models_[1], 0x1eb);
        func_ov023_021e5974(self->models_[0], self->hero_, self->hero_->unk_568, 0, 0);
        func_ov023_021e5974(self->models_[1], self->hero_, self->hero_->unk_568, 0, 0);
        self->current_ = self->models_[0];
        self->next_ = self->models_[1];
        func_ov023_021d99a4(self);
        SetupTag021d9c7c(self);
        SetupTag021d9da4(self);
        SetElementFieldC2((Struct_0205d81c*)&self->canvasListB_, 2, 0);
        SetElementFieldC2((Struct_0205d81c*)&self->canvasListB_, 3, 0);
        SetStatValue021855dc((unsigned char*)self, 1);
    }
}
