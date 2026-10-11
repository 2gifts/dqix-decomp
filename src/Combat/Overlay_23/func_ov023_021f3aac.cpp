#include <globaldefs.h>
#include <std_library_functions.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>

#define GUIDE_WINDOW_MESSAGE_WINDOW 4

struct Obj0209fee4;
struct IntField0x60_0209ff64;
struct TaskState0209ff6c;
struct Fields60_021f21f4;
struct S020a13c4;
struct Array020a15bc;
struct Struct020dfc40;
struct Container020e0310;
struct Obj_021f222c;

struct Appearance_021f3aac {
    unsigned char female_ : 1;
};

struct PartyData_021f3aac {
    char unk_0[0x49c];
    Appearance_021f3aac appearance_;
};

struct GameObject_021f3aac {
#if defined(jpn)
    char unk_0[0x144];
#else
    char unk_0[0x150];
#endif

    PartyData_021f3aac* partyData_;
};

struct GameState {
    static GameState* GetInstance();
    GameObject_021f3aac* GetProtagonist();
};

struct TitleScript_021f3aac {
    char unk_0[0x68];
    short count_;
    short ids_[1];
};

struct GuidePage_021f3aac {
#if defined(jpn)
    char unk_0[0x15c];
#else
    char unk_0[0x244];
#endif

};

struct GuideWindow_021f3aac {
    char unk_0[0x438];
    unsigned short flags_;
};

struct TextTable_021f3aac {
    char unk_0[0x18];
};

struct BattleEnd_021f3aac {
    int step_;
    int task_;
};

struct BattleScene_021f3aac {
    char unk_0[0x30];
    SafeAllocator allocator_;
#if defined(jpn)
    char unk_44[0xe28 - 0x44];
#else
    char unk_44[0xeac - 0x44];
#endif

    int endState_;
#if defined(jpn)
    char unk_eb0[0x371c - 0xe2c];
#else
    char unk_eb0[0x3760 - 0xeb0];
#endif

#if defined(jpn)
    char menu_[0x1bf8];
#else
    char menu_[0x1af8];
#endif

    SafeAllocator menuAllocator_;
#if defined(jpn)
    char unk_526c[0x5778 - 0x5328];
#else
    char unk_526c[0x5588 - 0x526c];
#endif

    void* resultWindow_;
    char unk_558c[0x55c4 - 0x558c];
    TitleScript_021f3aac* titles_;
    void* titleTable_;
    GuideWindow_021f3aac* guide_;
    GuidePage_021f3aac* pages_;
    unsigned char pageCount_;
    unsigned char firstGuide_;
    char unk_55d6[0x77d1 - 0x55d6];
    unsigned char busy_;
};

extern "C" BattleEnd_021f3aac* _ZZ17GetGlobal021ffefcvE1s;
#if defined(jpn)
extern const char data_ov023_021fd533[];
extern "C" void func_020e1fc4(TextTable_021f3aac*, SafeAllocator*, const char*, short*, unsigned short, int, int);
#endif
extern const char data_ov023_021fe316[];
extern const char data_ov023_021fe2a0[];
extern const char data_ov023_021fe2b7[];

extern "C" char* _Z26GetGlobalField0x1c020421a0v();
extern "C" void _Z24ReinitController02043204Pc(char* messages);
extern "C" void _Z24InitCombatEntry_021d8b6cPv(void* window);
extern "C" void _Z13Reset0209fe9cPc(char* titles);
extern "C" void _Z37InitManagerAndAllocateBuffers0209fee4P11Obj0209fee4P13SafeAllocatorii(Obj0209fee4* titles, SafeAllocator* allocator, int file, int size);
void SetIntAt0x60(IntField0x60_0209ff64* titles, int value);
extern "C" void _Z21PollOv017Task0209ff6cP17TaskState0209ff6c(TaskState0209ff6c* titles);
extern "C" int _Z32AreFields60And64AllOnes_021f21f4P17Fields60_021f21f4(Fields60_021f21f4* titles);
extern "C" void _Z19ClearStruct020a13c4P9S020a13c4(S020a13c4* table);
extern "C" void _Z31SetupGlobalAndRunScript020a13e4PvS_ith(void* table, void* allocator, int a, unsigned short b, unsigned char c);
extern "C" void* _Z26ResetAndReturnSelf020dfc2cPv(void* texts);
extern "C" void _Z19ResetStruct020dfc40P14Struct020dfc40(Struct020dfc40* texts);
extern "C" void* _Z26FindElementByField020a15bcP13Array020a15bci(Array020a15bc* table, int id);
extern "C" const char* _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310* texts, int id);
extern "C" void _Z16InitObj_021f222cP12Obj_021f222c(Obj_021f222c* page);
extern "C" void _Z28FormatLabelIntoBufC_021f2304PvPc(void* page, char* title);
extern "C" void _Z32SetOrClearBit10At400_38_021f2348Pvi(void* guide, int value);

extern "C" {
void __clear(void* buffer, unsigned long size);
void func_ov023_021f1818(void* menu, int hidden);
void func_ov023_021d8af8(void* window);
int func_ov023_021ed724(void* guide, short* ids, int count);
void* ExtractFileFromGP2(const char* gp2, const char* inner, unsigned int* size);
void func_020e0028(TextTable_021f3aac* texts, SafeAllocator* allocator, void* file, unsigned int size, short* ids, unsigned short count);
void func_ov023_021f229c(GuidePage_021f3aac* page, void* entry);
void func_ov023_021eb138(GuideWindow_021f3aac* guide, int type);
void func_ov023_021eb080(GuideWindow_021f3aac* guide, SafeAllocator* allocator);
void func_ov023_021eb564(GuideWindow_021f3aac* guide, GuidePage_021f3aac* pages, int count);
void func_ov023_021eb26c(GuideWindow_021f3aac* guide);
}

// JPN: func_ov023_021f312c
// USA: func_ov023_021f3aac
extern "C" ARM int func_ov023_021f3aac(BattleScene_021f3aac* self)
{
    BattleEnd_021f3aac* end = _ZZ17GetGlobal021ffefcvE1s;
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int step = end->step_;
    if (step == 0)
    {
        _Z24ReinitController02043204Pc(_Z26GetGlobalField0x1c020421a0v());
        if (self->resultWindow_ != NULL)
        {
            func_ov023_021f1818(self->menu_, 1);
            _Z24InitCombatEntry_021d8b6cPv(self->resultWindow_);
            func_ov023_021d8af8(self->resultWindow_);
            self->resultWindow_ = NULL;
        }
        self->busy_ = 1;
        self->titles_ = NULL;
        end->task_ = loader->QueueLoadFile(data_ov023_021fe316, NULL);
        end->step_++;
    }
    else if (step == 1)
    {
        BackgroundLoader* loader2 = BackgroundLoader::GetInstance();
        if (loader2->GetTaskStatus(end->task_))
        {
            unsigned int size;
            void* file;
            loader2->GetLoadedFileByID(end->task_, &file, &size);
            self->allocator_.Reset();
            void* copy = self->allocator_.Allocate(size);
            memcpy(copy, file, size);
            self->titles_ = (TitleScript_021f3aac*)self->allocator_.Allocate(0xd0);
            _Z13Reset0209fe9cPc((char*)self->titles_);
            _Z37InitManagerAndAllocateBuffers0209fee4P11Obj0209fee4P13SafeAllocatorii((Obj0209fee4*)self->titles_, &self->allocator_, (int)copy, size);
            loader2->RemoveTask(end->task_);
            end->task_ = -1;
            SetIntAt0x60((IntField0x60_0209ff64*)self->titles_, 100);
            end->step_++;
        }
    }
    else if (step == 2)
    {
        _Z21PollOv017Task0209ff6cP17TaskState0209ff6c((TaskState0209ff6c*)self->titles_);
        if (_Z32AreFields60And64AllOnes_021f21f4P17Fields60_021f21f4((Fields60_021f21f4*)self->titles_))
            end->step_++;
    }
    else if (step == 3)
    {
        short* ids;
#if defined(jpn)
        GuidePage_021f3aac* temporary;
#endif
        int i;
        int count = self->titles_->count_;
        if (count > 0)
        {
            SafeAllocator* idAllocator = &self->menuAllocator_;
            idAllocator->Reset();
            count = self->titles_->count_;
            ids = (short*)idAllocator->Allocate(count * 2);
            for (int k = 0; k < count; k++)
                ids[k] = self->titles_->ids_[k];
            self->allocator_.Reset();
            self->titles_ = NULL;
            self->titleTable_ = self->allocator_.Allocate(0x14);
            _Z19ClearStruct020a13c4P9S020a13c4((S020a13c4*)self->titleTable_);
            _Z31SetupGlobalAndRunScript020a13e4PvS_ith(self->titleTable_, &self->allocator_, 0, 0, 2);
            self->firstGuide_ = func_ov023_021ed724(self->titleTable_, ids, count) & 1 ? 1 : 0;
            GameObject_021f3aac* hero = GameState::GetInstance()->GetProtagonist();
            TextTable_021f3aac names;
            _Z26ResetAndReturnSelf020dfc2cPv(&names);
            _Z19ResetStruct020dfc40P14Struct020dfc40((Struct020dfc40*)&names);
#if defined(jpn)
            func_020e1fc4(&names, &self->allocator_, data_ov023_021fd533, ids, (unsigned short)count, hero->partyData_->appearance_.female_, 1);
            temporary = (GuidePage_021f3aac*)idAllocator->Allocate(count * sizeof(void*));
            for (i = 0; i < count; i++)
            {
                void* entry = _Z26FindElementByField020a15bcP13Array020a15bci((Array020a15bc*)self->titleTable_, ids[i]);
                if (entry == NULL)
                    continue;
                const char* title = _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)&names, ids[i]);
                if (title == NULL)
                    continue;
                _Z16InitObj_021f222cP12Obj_021f222c((Obj_021f222c*)&temporary[i]);
                func_ov023_021f229c(&temporary[i], entry);
                _Z28FormatLabelIntoBufC_021f2304PvPc(&temporary[i], (char*)title);
            }
            self->allocator_.Reset();
            self->titleTable_ = NULL;
            self->pages_ = (GuidePage_021f3aac*)self->allocator_.Allocate(count * sizeof(GuidePage_021f3aac));
            for (i = 0; i < count; i++)
            {
                _Z16InitObj_021f222cP12Obj_021f222c((Obj_021f222c*)&self->pages_[i]);
                func_ov023_021f229c(&self->pages_[i], &temporary[i]);
                _Z28FormatLabelIntoBufC_021f2304PvPc(&self->pages_[i], (char*)&temporary[i] + 0xc);
            }

#else
            BackgroundLoader::AddLockGlobal();
            unsigned int size = 0;
            char gp2[0x40];
            __clear(gp2, sizeof(gp2));
            char inner[0x20];
            __clear(inner, sizeof(inner));
            sprintf(gp2, data_ov023_021fe2a0, hero->partyData_->appearance_.female_);
            sprintf(inner, data_ov023_021fe2b7, hero->partyData_->appearance_.female_);
            void* file = ExtractFileFromGP2(gp2, inner, &size);
            if (file != NULL)
                func_020e0028(&names, &self->allocator_, file, size, ids, (unsigned short)count);
            BackgroundLoader::RemoveLockGlobal();
            self->pages_ = (GuidePage_021f3aac*)self->allocator_.Allocate(count * sizeof(GuidePage_021f3aac));
            for (i = 0; i < count; i++)
            {
                void* entry = _Z26FindElementByField020a15bcP13Array020a15bci((Array020a15bc*)self->titleTable_, ids[i]);
                if (entry == NULL)
                    continue;
                const char* title = _Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)&names, ids[i]);
                if (title == NULL)
                    continue;
                _Z16InitObj_021f222cP12Obj_021f222c((Obj_021f222c*)&self->pages_[i]);
                func_ov023_021f229c(&self->pages_[i], entry);
                _Z28FormatLabelIntoBufC_021f2304PvPc(&self->pages_[i], (char*)title);
            }
            self->titleTable_ = NULL;

#endif
            self->pageCount_ = count;
            idAllocator->Reset();
            end->step_++;
        }
        else if (count == 0)
        {
            self->allocator_.Reset();
            self->titles_ = NULL;
            self->busy_ = 0;
            return 0x10;
        }
    }
    else if (step == 4)
    {
        self->guide_ = (GuideWindow_021f3aac*)self->allocator_.Allocate(0x44c);
        func_ov023_021eb138(self->guide_, 2);
        func_ov023_021eb080(self->guide_, &self->allocator_);
        func_ov023_021eb564(self->guide_, self->pages_, self->pageCount_);
        _Z32SetOrClearBit10At400_38_021f2348Pvi(self->guide_, self->firstGuide_);
        end->step_++;
    }
    else if (step == 5)
    {
        if (self->guide_->flags_ & GUIDE_WINDOW_MESSAGE_WINDOW)
            end->step_ = step + 1;
    }
    else if (step == 6)
    {
        func_ov023_021eb26c(self->guide_);
        self->allocator_.Reset();
        self->guide_ = NULL;
        self->pages_ = NULL;
        self->pageCount_ = 0;
        self->firstGuide_ = 0;
        self->busy_ = 0;
        return 0x10;
    }
    return self->endState_;
}
