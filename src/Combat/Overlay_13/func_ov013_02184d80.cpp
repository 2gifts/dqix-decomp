#include <globaldefs.h>
#include "Resource/FontBankLoader.h"

#if defined(jpn)
#define func_ov013_02184d80 func_ov013_02185db4
extern char data_ov013_02188d20[];
#endif
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "System/ColorEffects.h"
#include "System/Graphics.h"

extern "C" void func_020dfec0(void* texts, SafeAllocator* allocator, void* file, unsigned int size);
void* GetGlobalField0x1c020421a0(void);
void SetChannelAFlag0205cef8(void* window);
void SetChannelBFlag0205cf04(void* window);
void InitTag02185310(unsigned char* self);
extern "C" void func_ov013_02185cc0(void* self);
void SetWord0x18ClearByte0x1f_0204b11c(unsigned char* graphics, int value);
extern "C" void func_0204b5b4(void* graphics, int priority);
struct AllocTarget0204b12c;
void AllocateAndClearBuffer0204b12c(AllocTarget0204b12c* graphics, SafeAllocator* allocator);
struct Obj0204b5e8;
void DispatchViaTable0204b5e8(Obj0204b5e8* graphics, int a, int b);
struct ActiveEntry02046900;
int CountActiveEntries(ActiveEntry02046900* pac);
struct Rec020467f0;
void* FindRecordByIndex(Rec020467f0* pac, int index, void** outName, int* outSize);
extern "C" void func_0204b174(void* graphics, void* file, SafeAllocator* allocator, unsigned int size);
extern "C" void func_0204bc74(void* graphics, int a, int b, int c, int d, int e, int f);
struct List0204b0e8;
void FlushAndDispatchList0204b0e8(List0204b0e8* graphics, void* characters);
struct Obj0204c7a8;
void AllocateBuffer0204c7a8(Obj0204c7a8* canvas, SafeAllocator* allocator, int pixels, unsigned int size);
struct Struct_0205cf78;
struct Elem_0205cf78;
void LinkArrayPrevPointers0205cf78(Struct_0205cf78* window, Elem_0205cf78* canvases, unsigned char count);

extern char data_ov013_02187e00[];
extern char data_ov013_02187e19[];
extern char data_ov013_02187e29[];
extern const unsigned char data_ov013_02187d88[2];
extern const unsigned char data_ov013_02187d8a[2];

struct BackgroundGraphics02184d80 {
    char unk_0[0x1c];
    unsigned char unk_1c_0_ : 4;
    unsigned char unk_1c_4_ : 4;
    unsigned char unk_1d;
    char unk_1e[2];
};

struct Canvas02184d80 {
    void* unk_0;
    BackgroundGraphics02184d80* background_;
    char unk_8[0xe0 - 8];
};

struct TextWindow02184d80 {
    char unk_0[0x98];
    BackgroundGraphics02184d80* background_;
    char unk_9c[0xb2 - 0x9c];
    unsigned char unk_b2;
    char unk_b3[0xbc - 0xb3];
};

struct SkillPointMenu02184d80 {
    SafeAllocator allocator_;
#if defined(jpn)
    char unk_14[0x34 - 0x14];
#else
    char unk_14[0x38 - 0x14];
#endif
    TextWindow02184d80 window_;
    BackgroundGraphics02184d80 backgrounds_[2];
    Canvas02184d80 canvases_[3];
#if defined(jpn)
    char unk_3d4[0x598 - 0x3d0];
#else
    char unk_3d4[0x60c - 0x3d4];
#endif
    SafeAllocator textAllocator_;
    char texts_[0x18];
    unsigned char unk_638[4];
    unsigned char state_;
    unsigned char previousState_;
    unsigned char step_;
    bool stateChanged_;
    bool subScreen_;
    unsigned int ticks_;
    int windowInput_;
#if !defined(jpn)
    int previousWindowInput_;
#endif
    int task_;
    void* canvasPixels_;
    char* text_;
};

// USA: func_ov013_02184d80
extern "C" ARM void func_ov013_02184d80(SkillPointMenu02184d80* self) {
    if (self->state_ != 0)
        return;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (self->subScreen_)
    {
        if (self->step_ == 0)
        {
#if defined(jpn)
            self->task_ = loader->QueueLoadFile(data_ov013_02188d20, NULL);
#else
            self->task_ = loader->QueueLoadFileInGP2(data_ov013_02187e00, data_ov013_02187e19, NULL);
#endif
            self->step_++;
        }
        else if (self->step_ == 1)
        {
            if (loader->GetTaskStatus(self->task_))
            {
                void* file;
                unsigned int size;
                loader->GetLoadedFileByID(self->task_, &file, &size);
                self->textAllocator_.Reset();
                func_020dfec0(self->texts_, &self->textAllocator_, file, size);
                loader->RemoveTask(self->task_);
                self->task_ = -1;
                self->step_++;
            }
        }
        else if (self->step_ == 2)
        {
            self->text_ = *(char**)((char*)GetGlobalField0x1c020421a0()
#if defined(jpn)
                + 0x28);
#else
                + 0x5c);
#endif
            BG2CNTSUB = (BG2CNTSUB & ~3) | 1;
            BG0CNTSUB = (BG0CNTSUB & ~3) | 2;
            BG1CNTSUB = (BG1CNTSUB & ~3) | 3;
            DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x1700;
            SetChannelAFlag0205cef8(&self->window_);
            SetChannelBFlag0205cf04(&self->window_);
            InitTag02185310((unsigned char*)self);
            func_ov013_02185cc0(self);
            self->step_ = 0;
            self->state_ = 1;
        }
    }
    else
    {
        if (self->step_ == 0)
        {
            FontBankLoader* music = GetGlobal02109400_02094a00();
            BlankFunction02094b3c(music, 0xc);
            BlankFunction02094b30(music, 0x1f7, 0);
            self->step_++;
        }
        else if (self->step_ == 1)
        {
            if (AlwaysTrue02094b4c(GetGlobal02109400_02094a00()))
            {
                self->text_ = *(char**)((char*)GetGlobalField0x1c020421a0()
#if defined(jpn)
                + 0x28);
#else
                + 0x5c);
#endif
#if defined(jpn)
                SetWord0x18ClearByte0x1f_0204b11c((unsigned char*)&self->backgrounds_[0], 0);
                self->backgrounds_[0].unk_1c_0_ = 0;
                self->backgrounds_[0].unk_1c_4_ = 1;
                func_0204b5b4(&self->backgrounds_[0], 1);
                AllocateAndClearBuffer0204b12c((AllocTarget0204b12c*)&self->backgrounds_[0], &self->allocator_);
                DispatchViaTable0204b5e8((Obj0204b5e8*)&self->backgrounds_[0], 0, 0);
                BG1CNT = (BG1CNT & (3 | 0x40)) | (0x1d << 8);
                SetWord0x18ClearByte0x1f_0204b11c((unsigned char*)&self->backgrounds_[1], 0);
                self->backgrounds_[1].unk_1c_0_ = 0;
                self->backgrounds_[1].unk_1c_4_ = 2;
                func_0204b5b4(&self->backgrounds_[1], 0);
                AllocateAndClearBuffer0204b12c((AllocTarget0204b12c*)&self->backgrounds_[1], &self->allocator_);
                DispatchViaTable0204b5e8((Obj0204b5e8*)&self->backgrounds_[1], 0, 0);
                BG2CNT = (BG2CNT & (3 | 0x40)) | (0x1e << 8);
#else
                BackgroundGraphics02184d80* background = self->backgrounds_;
                for (int i = 0; i < 2; background++, i++)
                {
                    SetWord0x18ClearByte0x1f_0204b11c((unsigned char*)background, 0);
                    background->unk_1c_0_ = 0;
                    background->unk_1c_4_ = data_ov013_02187d8a[i];
                    func_0204b5b4(background, data_ov013_02187d88[i]);
                    AllocateAndClearBuffer0204b12c((AllocTarget0204b12c*)background, &self->allocator_);
                    DispatchViaTable0204b5e8((Obj0204b5e8*)background, 0, 0);
                }
                BG1CNT = (BG1CNT & (3 | 0x40)) | (0x1d << 8);
                BG2CNT = (BG2CNT & (3 | 0x40)) | (0x1e << 8);
#endif
                ColorEffect_ConfigureAlphaBlend(0x04000050, 2, 1, 0xa, 6);
                self->task_ = loader->QueueLoadFile(data_ov013_02187e29, NULL);
                self->step_++;
            }
        }
        else if (self->step_ == 2)
        {
            if (loader->GetTaskStatus(self->task_))
            {
                void* name = NULL;
                void* file;
                unsigned int size;
                void* files[2];
                unsigned int sizes[2];
                loader->GetLoadedFileByID(self->task_, &file, &size);
                int numFiles = CountActiveEntries((ActiveEntry02046900*)file);
                for (int i = 0; i < numFiles; i++)
                {
                    files[i] = FindRecordByIndex((Rec020467f0*)file, i, &name, (int*)&sizes[i]);
                }
                for (int i = 0; i < numFiles; i++)
                {
                    if (files[i] != NULL)
                        func_0204b174(&self->backgrounds_[1], files[i], &self->allocator_, sizes[i]);
                }
                loader->RemoveTask(self->task_);
                self->task_ = -1;
                func_0204bc74(&self->backgrounds_[0], 0, 0, 0, 0x20, 0x19, 0);
                FlushAndDispatchList0204b0e8((List0204b0e8*)&self->backgrounds_[0], NULL);
                func_0204bc74(&self->backgrounds_[1], 0, 0, 0, 0x20, 0x19, 0);
                FlushAndDispatchList0204b0e8((List0204b0e8*)&self->backgrounds_[1], NULL);
                self->canvasPixels_ = self->allocator_.Allocate(0x3c00);
                for (int i = 0; i < 3; i++)
                {
                    AllocateBuffer0204c7a8((Obj0204c7a8*)&self->canvases_[i], &self->allocator_, (int)self->canvasPixels_, 0x380);
                    self->canvases_[i].background_ = &self->backgrounds_[1];
                }
                self->window_.background_ = &self->backgrounds_[0];
                self->window_.unk_b2 = 2;
                LinkArrayPrevPointers0205cf78((Struct_0205cf78*)&self->window_, (Elem_0205cf78*)self->canvases_, 3);
    #if defined(jpn)
            self->task_ = loader->QueueLoadFile(data_ov013_02188d20, NULL);
#else
            self->task_ = loader->QueueLoadFileInGP2(data_ov013_02187e00, data_ov013_02187e19, NULL);
#endif
                self->step_++;
            }
        }
        else if (self->step_ == 3)
        {
            if (loader->GetTaskStatus(self->task_))
            {
                void* file;
                unsigned int size;
                loader->GetLoadedFileByID(self->task_, &file, &size);
                self->textAllocator_.Reset();
                func_020dfec0(self->texts_, &self->textAllocator_, file, size);
                loader->RemoveTask(self->task_);
                self->task_ = -1;
                self->step_++;
            }
        }
        else if (self->step_ == 4)
        {
            BG0CNT = (BG0CNT & ~3) | 2;
            BG1CNT = (BG1CNT & ~3) | 1;
            BG2CNT = BG2CNT & ~3;
            DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
            SetChannelAFlag0205cef8(&self->window_);
            SetChannelBFlag0205cf04(&self->window_);
            InitTag02185310((unsigned char*)self);
            func_ov013_02185cc0(self);
            self->step_ = 0;
            self->state_ = 1;
        }
    }
}
