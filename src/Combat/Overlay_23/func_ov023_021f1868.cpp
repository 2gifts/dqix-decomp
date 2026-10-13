#include <globaldefs.h>
#include <std_library_functions.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>

struct GameResources;
struct ArrayContainsByteStruct;
struct TableA68 { char storage[4]; };
struct Pair0209a338;
struct Ctx0209a470;
struct StreamHeader;
struct List020727d8;
struct Obj02046574;
struct StoreStruct;
struct Obj0209fee4;
struct IntField0x60_0209ff64;
struct TaskState0209ff6c;
struct Fields60_021f21f4;
struct S020a13c4;
struct Array020a15bc;
struct Struct020dfc40;
struct Container020e0310;
struct Obj_021f222c;
struct Reset_021eefac;

struct Appearance_021f1868 {
    unsigned char female_ : 1;
};

struct PartyData_021f1868 {
    char unk_0[0x49c];
    Appearance_021f1868 appearance_;
};

struct GameObject_021f1868 {
    char unk_0[0x150];
    PartyData_021f1868* partyData_;
};

struct GameState {
    static GameState* GetInstance();
    GameObject_021f1868* GetProtagonist();
};

struct Member_021f1868 {
    char unk_0[0x134];
    char* name_;
};

struct Skill_021f1868 {
    unsigned short lo_ : 11;
    unsigned short suffix_ : 5;
    short item_;
    unsigned int prefix_ : 5;
    unsigned int pad_ : 7;
    unsigned int value_ : 8;
    unsigned int type_ : 5;
    unsigned int rest_ : 7;
};

struct MessageSystem_021f1868 {
    char* actor_;
    char unk_4[4];
    void* item_;
    char unk_c[0x998 - 0xc];
    int busy_;
    char unk_99c[0x19b2 - 0x99c];
    unsigned char unk_19b2;
    char unk_19b3[0x19ca - 0x19b3];
    unsigned char unk_19ca;
};

struct TitleScript_021f1868 {
    char unk_0[0x68];
    short count_;
    short ids_[1];
};

struct GuidePage_021f1868 {
    char unk_0[0x244];
};

struct GuideWindow_021f1868 {
    char unk_0[0x438];
    unsigned short flags_;
};

struct TextTable_021f1868 {
    char unk_0[0x18];
};

struct BattleEnd_021f1868 {
    int step_;
    int task_;
    char unk_8[0x18 - 0x8];
    int current_;
    char unk_1c[0x74 - 0x1c];
    unsigned short newSkills_[55];
    unsigned char newSkillCount_;
    unsigned char newSkill_;
};

struct BattleScene_021f1868 {
    char unk_0[0x30];
    SafeAllocator allocator_;
    char unk_44[0xe98 - 0x44];
    char script_[0xeac - 0xe98];
    int endState_;
    char unk_eb0[0x3760 - 0xeb0];
    char menu_[0x1af8];
    SafeAllocator menuAllocator_;
    char unk_526c[0x557c - 0x526c];
    TableA68* skillTable_;
    void* items_;
    char unk_5584[0x55c4 - 0x5584];
    TitleScript_021f1868* titles_;
    void* titleTable_;
    GuideWindow_021f1868* guide_;
    GuidePage_021f1868* pages_;
    unsigned char pageCount_;
    unsigned char firstGuide_;
    char unk_55d6[0x5904 - 0x55d6];
    TableA68 texts_;
    char unk_5908[0x77d1 - 0x5908];
    unsigned char busy_;
};

extern "C" BattleEnd_021f1868* _ZZ17GetGlobal021ffefcvE1s;
extern const char data_ov023_021fe200[];
extern const char data_ov023_021fe25e[];
extern const char data_ov023_021fe273[];
extern const char data_ov023_021fe284[];
extern const char data_ov023_021fe2a0[];
extern const char data_ov023_021fe2b7[];
extern unsigned char data_0211e33c[0x30000] __attribute__((aligned(4)));

extern "C" MessageSystem_021f1868* _Z26GetGlobalField0x1c020421a0v();
extern "C" ArrayContainsByteStruct* _Z17GetPtrField0x2a04P9GameState(GameState* gameState);
int ArrayContainsByte(ArrayContainsByteStruct* array, int id);
void* LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);
void ClearFirstTwoWords0209a338(Pair0209a338* p);
void SetupAndRunBufferedScript0209a470(Ctx0209a470* ctx, SafeAllocator* allocator, StreamHeader* file, int size);
char* FindEntryByKey(TableA68* table, int key);
void ResetListHeader020727d8(List020727d8* list);
void Zero4Bytes(void* p);
void Reset0209fe9c(char* titles);
void InitManagerAndAllocateBuffers0209fee4(Obj0209fee4* titles, SafeAllocator* allocator, int file, int size);
void SetIntAt0x60(IntField0x60_0209ff64* titles, int value);
void PollOv017Task0209ff6c(TaskState0209ff6c* titles);
int AreFields60And64AllOnes_021f21f4(Fields60_021f21f4* titles);
extern "C" Member_021f1868* _Z25GetCombatantWithFlag0x100P9GameStatei(GameState* gameState, int id);
int AppendString02042058(char* dst, const char* src);
void SetIndexedName02046574(Obj02046574* obj, int index, char* str);
void InitObjFromCombatantId020e4bf4(void* obj, int id);
void** CallFunc020e52a0(void* p, int key);
void StoreInArray0x8b0(StoreStruct* base, int index, int value);
extern "C" void _Z24ReinitController02043204Pc(char* messages);
void ClearStruct020a13c4(S020a13c4* table);
void SetupGlobalAndRunScript020a13e4(void* table, void* allocator, int ids, unsigned short count, unsigned char mode);
void* ResetAndReturnSelf020dfc2c(void* texts);
void ResetStruct020dfc40(Struct020dfc40* texts);
void* FindElementByField020a15bc(Array020a15bc* table, int id);
const char* GetFieldByKey020e0434(Container020e0310* texts, int id);
void InitObj_021f222c(Obj_021f222c* page);
void FormatLabelIntoBufC_021f2304(void* page, char* title);
void* GetGlobal02109400();
void BlankFunction02094b40();
extern "C" void _Z21BlankFunction02094b34v(void* music, int a, int b, int c, int d);
extern "C" int _Z18AlwaysTrue02094b4cv(void* music);
void SetOrClearBit10At400_38_021f2348(void* guide, int value);
GameResources* GetWord0x0(int* gameState);
void SetMainBrightness(GameResources* resources, int brightness, int duration);
int IsBrightnessTransitionActive(GameResources* resources);
void ResetFields_021eefac(Reset_021eefac* end);

extern "C" {
void __clear(void* buffer, unsigned long size);
void* ExtractFileFromGP2(const char* gp2, const char* inner, unsigned int* size);
void func_020728ac(void* list, void* allocator, void* file, int size, int a, int b, int c);
void func_020e5604(void* items, SafeAllocator* allocator, void* file, int size);
Skill_021f1868* func_0209a594(void* script, int id);
void func_02046380(MessageSystem_021f1868* messages);
void func_020e4864(void* src, char* dst, int a, int b, int c, int d);
void func_0204500c(MessageSystem_021f1868* messages, char* text, int a, int b);
int func_ov023_021f4fc8();
int func_ov023_021ed724(void* table, short* ids, int count);
void func_020e0028(TextTable_021f1868* texts, SafeAllocator* allocator, void* file, unsigned int size, short* ids, unsigned short count);
void func_ov023_021f229c(GuidePage_021f1868* page, void* entry);
void func_ov023_021eb138(GuideWindow_021f1868* guide, int type);
void func_ov023_021eb080(GuideWindow_021f1868* guide, SafeAllocator* allocator);
void func_ov023_021eb564(GuideWindow_021f1868* guide, GuidePage_021f1868* pages, int count);
void func_ov023_021eb26c(GuideWindow_021f1868* guide);
}

static inline int IsMessageWindow(GuideWindow_021f1868* guide) { return (guide->flags_ & 4) ? 1 : 0; }

// USA: func_ov023_021f1868
extern "C" ARM int func_ov023_021f1868(BattleScene_021f1868* self)
{
    GameState* gameState = GameState::GetInstance();
    BattleEnd_021f1868* end = _ZZ17GetGlobal021ffefcvE1s;
    MessageSystem_021f1868* messages = _Z26GetGlobalField0x1c020421a0v();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int id = end->current_;
    int inParty = ArrayContainsByte(_Z17GetPtrField0x2a04P9GameState(gameState), id);
    if (end->step_ == 0)
    {
        self->busy_ = 1;
        BackgroundLoader::AddLockGlobal();
        BackgroundLoader::FreeAllocationsGlobal();
        self->allocator_.Reset();
        unsigned int size;
        void* file = LoadFileIntoMemory(data_ov023_021fe200, data_0211e33c, &size);
        ClearFirstTwoWords0209a338((Pair0209a338*)self->script_);
        if (file != NULL)
            SetupAndRunBufferedScript0209a470((Ctx0209a470*)self->script_, &self->allocator_, (StreamHeader*)file, size);
        file = ExtractFileFromGP2(FindEntryByKey(&self->texts_, 0x2b), FindEntryByKey(&self->texts_, 0x21), &size);
        self->skillTable_ = (TableA68*)self->allocator_.Allocate(8);
        ResetListHeader020727d8((List020727d8*)self->skillTable_);
        if (file != NULL)
            func_020728ac(self->skillTable_, &self->allocator_, file, size, 0, 0, 0);
        file = ExtractFileFromGP2(data_ov023_021fe25e, data_ov023_021fe273, &size);
        self->items_ = self->allocator_.Allocate(0xc);
        Zero4Bytes(self->items_);
        if (file != NULL)
            func_020e5604(self->items_, &self->allocator_, file, size);
        BackgroundLoader::RemoveLockGlobal();
        self->titles_ = NULL;
        end->task_ = loader->QueueLoadFile(data_ov023_021fe284, NULL);
        end->step_++;
    }
    if (end->step_ == 1)
    {
        if (loader->GetTaskStatus(end->task_))
        {
            unsigned int size;
            void* file;
            loader->GetLoadedFileByID(end->task_, &file, &size);
            self->titles_ = (TitleScript_021f1868*)self->allocator_.Allocate(0xd0);
            Reset0209fe9c((char*)self->titles_);
            InitManagerAndAllocateBuffers0209fee4((Obj0209fee4*)self->titles_, &self->allocator_, (int)file, size);
            SetIntAt0x60((IntField0x60_0209ff64*)self->titles_, 100);
            do
            {
                PollOv017Task0209ff6c((TaskState0209ff6c*)self->titles_);
            } while (!AreFields60And64AllOnes_021f21f4((Fields60_021f21f4*)self->titles_));
            loader->RemoveTask(end->task_);
            end->task_ = -1;
            end->step_++;
        }
    }
    else if (end->step_ == 2)
    {
        while (end->newSkill_ < end->newSkillCount_)
        {
            Skill_021f1868* skill = func_0209a594(self->script_, end->newSkills_[end->newSkill_]);
            char* name = NULL;
            if (skill != NULL)
                name = FindEntryByKey(self->skillTable_, skill->type_);
            if (name != NULL)
            {
                Member_021f1868* member = _Z25GetCombatantWithFlag0x100P9GameStatei(GameState::GetInstance(), id);
                if (member != NULL)
                {
                    char text[0x200];
                    char actorName[12];
                    char item[0x80];
                    __clear(text, sizeof(text));
                    AppendString02042058(text, name);
                    AppendString02042058(text, FindEntryByKey(&self->texts_, 0x22));
                    func_02046380(messages);
                    SetIndexedName02046574((Obj02046574*)messages, 0, member->name_);
                    InitObjFromCombatantId020e4bf4(actorName, id);
                    messages->actor_ = actorName;
                    if (skill->type_ == 1)
                    {
                        void** entry = CallFunc020e52a0(self->items_, skill->item_);
                        messages->item_ = entry;
                        __clear(item, sizeof(item));
                        func_020e4864(*entry, item, 1, 0, 0, 0);
                        SetIndexedName02046574((Obj02046574*)messages, 1, item);
                    }
                    else
                    {
                        SetIndexedName02046574((Obj02046574*)messages, 1, FindEntryByKey(self->skillTable_, (short)(skill->prefix_ + 100)));
                    }
                    int slot = 2;
                    if (skill->type_ == 4 || skill->type_ == 0x10)
                        slot = 1;
                    SetIndexedName02046574((Obj02046574*)messages, slot, FindEntryByKey(self->skillTable_, (short)(skill->suffix_ + 200)));
                    StoreInArray0x8b0((StoreStruct*)messages, 0, skill->value_);
                    if (inParty)
                    {
                        func_0204500c(messages, text, 1, 0xe3);
                        messages->unk_19b2 = 0;
                        messages->busy_ = 1;
                    }
                    end->newSkill_++;
                    end->step_++;
                    return self->endState_;
                }
            }
            end->newSkill_++;
        }
        end->step_ = 4;
    }
    else if (end->step_ == 3)
    {
        if (end->newSkillCount_ <= end->newSkill_)
        {
            if (self->titles_->count_ > 0)
                messages->unk_19ca = 0;
        }
        if (func_ov023_021f4fc8())
        {
            if (end->newSkillCount_ <= end->newSkill_)
                end->step_++;
            else
                end->step_ = 2;
        }
    }
    else if (end->step_ == 4)
    {
        int count = self->titles_->count_;
        if (count > 0)
        {
            _Z24ReinitController02043204Pc((char*)messages);
            char* menu = self->menu_; SafeAllocator* idAllocator = (SafeAllocator*)(menu + 0x1af8);
            idAllocator->Reset();
            count = self->titles_->count_;
            short* ids = (short*)idAllocator->Allocate(count * 2);
            for (int k = 0; k < count; k++)
                ids[k] = self->titles_->ids_[k];
            self->allocator_.Reset();
            self->skillTable_ = NULL;
            self->items_ = NULL;
            self->titles_ = NULL;
            self->titleTable_ = self->allocator_.Allocate(0x14);
            ClearStruct020a13c4((S020a13c4*)self->titleTable_);
            SetupGlobalAndRunScript020a13e4(self->titleTable_, &self->allocator_, (int)ids, (unsigned short)count, 4);
            self->firstGuide_ = func_ov023_021ed724(self->titleTable_, ids, count) & 1 ? 1 : 0;
            GameObject_021f1868* hero = gameState->GetProtagonist();
            TextTable_021f1868 names;
            ResetAndReturnSelf020dfc2c(&names);
            ResetStruct020dfc40((Struct020dfc40*)&names);
            BackgroundLoader::AddLockGlobal();
            unsigned int size = 0;
            char gp2[0x40];
            __clear(gp2, sizeof(gp2));
            char inner[0x20];
            __clear(inner, sizeof(inner));
            PartyData_021f1868* pd = hero->partyData_;
            sprintf(gp2, data_ov023_021fe2a0, pd->appearance_.female_);
            sprintf(inner, data_ov023_021fe2b7, hero->partyData_->appearance_.female_);
            void* file = ExtractFileFromGP2(gp2, inner, &size);
            if (file != NULL)
                func_020e0028(&names, &self->allocator_, file, size, ids, (unsigned short)count);
            BackgroundLoader::RemoveLockGlobal();
            self->pages_ = (GuidePage_021f1868*)self->allocator_.Allocate(count * sizeof(GuidePage_021f1868));
            for (int i = 0; i < count; i++)
            {
                void* entry = FindElementByField020a15bc((Array020a15bc*)self->titleTable_, ids[i]);
                if (entry == NULL)
                    continue;
                const char* title = GetFieldByKey020e0434((Container020e0310*)&names, ids[i]);
                if (title == NULL)
                    continue;
                InitObj_021f222c((Obj_021f222c*)&self->pages_[i]);
                func_ov023_021f229c(&self->pages_[i], entry);
                FormatLabelIntoBufC_021f2304(&self->pages_[i], (char*)title);
            }
            self->titleTable_ = NULL;
            self->pageCount_ = count;
            idAllocator->Reset();
            end->step_++;
        }
        else if (count == 0)
        {
            self->allocator_.Reset();
            self->skillTable_ = NULL;
            self->items_ = NULL;
            self->titles_ = NULL;
            self->busy_ = 0;
            void* music = GetGlobal02109400();
            BlankFunction02094b40();
            _Z21BlankFunction02094b34v(music, 0x65, 500, 0, 0);
            end->step_ = 8;
        }
    }
    else if (end->step_ == 5)
    {
        self->guide_ = (GuideWindow_021f1868*)self->allocator_.Allocate(0x44c);
        func_ov023_021eb138(self->guide_, 7);
        self->guide_->flags_ |= 8;
        func_ov023_021eb080(self->guide_, &self->allocator_);
        func_ov023_021eb564(self->guide_, self->pages_, self->pageCount_);
        SetOrClearBit10At400_38_021f2348(self->guide_, self->firstGuide_);
        end->step_++;
    }
    else if (end->step_ == 6)
    {
        if (IsMessageWindow(self->guide_))
            end->step_++;
    }
    else if (end->step_ == 7)
    {
        func_ov023_021eb26c(self->guide_);
        self->allocator_.Reset();
        self->guide_ = NULL;
        self->pages_ = NULL;
        self->pageCount_ = 0;
        self->firstGuide_ = 0;
        self->busy_ = 0;
        SetMainBrightness(GetWord0x0((int*)gameState), 0, 0xf);
        void* music = GetGlobal02109400();
        BlankFunction02094b40();
        _Z21BlankFunction02094b34v(music, 0x65, 500, 0, 0);
        end->step_++;
    }
    else if (end->step_ == 8)
    {
        if (_Z18AlwaysTrue02094b4cv(GetGlobal02109400()))
            end->step_++;
    }
    else if (end->step_ == 9)
    {
        if (!IsBrightnessTransitionActive(GetWord0x0((int*)gameState)))
        {
            ResetFields_021eefac((Reset_021eefac*)end);
            return 7;
        }
    }
    return self->endState_;
}
