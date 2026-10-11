#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>

struct GameResources;
struct ArrayContainsByteStruct;
struct Entry_0205d6a0;
struct TableA68;
struct Container02186e74;
struct Reset_021eefac;

struct GameState {
    static GameState* GetInstance();
    unsigned int GetTickCount() const;
};

struct MessageSystem_021f1234 {
#if defined(jpn)
    char unk_0[0x868];
#else
    char unk_0[0x998];
#endif

    int busy_;
    char unk_99c[4];
    int unk_9a0;
#if defined(jpn)
    char unk_9a4[0x17df - 0x874];
#else
    char unk_9a4[0x19af - 0x9a4];
#endif

    unsigned char unk_19af;
#if defined(jpn)
    char unk_19b0[0x17e2 - 0x17e0];
#else
    char unk_19b0[0x19b2 - 0x19b0];
#endif

    unsigned char unk_19b2;
};

struct SkillPointMenu_021f1234 {
    char unk_0[0x18];
    void* spriteRenderer_;
    short cursorAnimation_;
#if defined(jpn)
    char unk_1e[0x5e4 - 0x1e];
#else
    char unk_1e[0x65c - 0x1e];
#endif

    int selection_;
};

struct SkillAbilityList_021f1234 {
#if defined(jpn)
    char unk_0[0x53];
#else
    char unk_0[0x67];
#endif

    unsigned char member_;
};

struct BattleEnd_021f1234 {
    int step_;
    char unk_4[0x18 - 4];
    int current_;
    char unk_1c[0x74 - 0x1c];
    unsigned short newSkills_[55];
    unsigned char newSkillCount_;
    unsigned char newSkill_;
    char unk_e4[0xe8 - 0xe4];
    char skillTable_[8];
};

struct BattleScene_021f1234 {
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
    char menu_[0x52e4 - 0x371c];
#else
    char menu_[0x5228 - 0x3760];
#endif

    SafeAllocator menuAllocator_;
#if defined(jpn)
    char unk_523c[0x5768 - 0x52f8];
#else
    char unk_523c[0x5574 - 0x523c];
#endif

    SkillPointMenu_021f1234* skillMenu_;
    SkillAbilityList_021f1234* abilities_;
#if defined(jpn)
    char unk_557c[0x5774 - 0x5770];
#else
    char unk_557c[0x5584 - 0x557c];
#endif

    unsigned char unk_5584;
    char unk_5585[3];
    void* resultWindow_;
#if defined(jpn)
    char unk_558c[0x5af4 - 0x577c];
#else
    char unk_558c[0x5904 - 0x558c];
#endif

    char texts_[4];
};

extern "C" BattleEnd_021f1234* _ZZ17GetGlobal021ffefcvE1s;
extern char data_02108760[];

extern "C" MessageSystem_021f1234* _Z26GetGlobalField0x1c020421a0v();
ArrayContainsByteStruct* GetPtrField0x2a04(GameState* gameState);
int ArrayContainsByte(ArrayContainsByteStruct* array, int id);
extern "C" void _Z24InitCombatEntry_021d8b6cPv(void* window);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(Entry_0205d6a0* window, int value);
int TestBitInByteArray(int a, unsigned char* b, int flag);
void SetOrClearBitInArray(void* a, unsigned char* b, int flag, int value);
const char* FindEntryByKey(TableA68* texts, int id);
extern "C" void _Z24ReinitController02043204Pc(char* messages);
void SetMainBrightness(GameResources* resources, int brightness, int duration);
int IsMainBrightnessTransitionActive(GameResources* resources);
extern "C" void _Z16ZeroInit020de868Pv(void* icons);
extern "C" void _Z26InitAllocatorArray02186e74P17Container02186e74P13SafeAllocator(Container02186e74* abilities, SafeAllocator* allocator);
void* GetCombatantWithFlag0x100(GameState* gameState, int member);
extern "C" void _Z27SetupContextForMode0205ea20Pvi(void* sound, int mode);
unsigned char* GetFieldAt0x150(unsigned char* member);
extern "C" void _Z20ResetFields_021eefacP14Reset_021eefac(Reset_021eefac* end);
void* GetGlobal02109400();

extern "C" {
GameResources* func_ov017_0218b5b0();
void* func_0205ec34();
void func_ov023_021f1818(void* menu, int hidden);
void func_ov023_021d8af8(void* window);
void func_ov013_02184360(SkillPointMenu_021f1234* menu, void* parent);
void func_ov013_02184cf0(SkillPointMenu_021f1234* menu, SafeAllocator* allocator);
void func_0204500c(MessageSystem_021f1234* messages, const char* text, int a, int b);
#if defined(jpn)
void func_02045d88(MessageSystem_021f1234*,const char*,int);
unsigned char func_ov013_021847c4(void*,int);
#endif
int func_ov023_021f4fc8();
void func_ov013_02186eec(SkillAbilityList_021f1234* abilities, int a);
void func_ov013_02184b4c(SkillPointMenu_021f1234* menu, void* member);
int func_ov013_021870f0(SkillAbilityList_021f1234* abilities);
extern "C" unsigned char _Z19ResetFields021847c4P14Struct021847c4(void* menu, int ticks);
void func_ov013_0218782c(SkillAbilityList_021f1234* abilities, int member, int skill);
void func_ov013_02186fa0(SkillAbilityList_021f1234* abilities);
void func_ov013_02184c8c(SkillPointMenu_021f1234* menu, void* member);
unsigned char func_0209a678(char* table, void* member, unsigned short* skills);
void func_02083e28(unsigned char* data, int a);
void func_ov017_021cc730(int id, int a, int b, int c);
void func_ov017_021ccc34(int id);
void func_ov017_021c9e00(int id, int a, int b, int c);
void func_ov017_021cd0d8(int id, unsigned short* skills, int count);
void _Z21BlankFunction02094b40v(void* music);
void _Z21BlankFunction02094b34v(void* music, int a, int b, int c, int d);
int _Z18AlwaysTrue02094b4cv(void* music);
}

// JPN: func_ov023_021f0db4
// USA: func_ov023_021f1234
extern "C" ARM int func_ov023_021f1234(BattleScene_021f1234* self)
{
    GameState* gameState = GameState::GetInstance();
    BattleEnd_021f1234* end = _ZZ17GetGlobal021ffefcvE1s;
    GameResources* resources = func_ov017_0218b5b0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    void* unk = func_0205ec34();
    MessageSystem_021f1234* messages = _Z26GetGlobalField0x1c020421a0v();
    int id = end->current_;
    int inParty = ArrayContainsByte(GetPtrField0x2a04(gameState), id);
    if (self->skillMenu_ == NULL)
    {
        if (self->resultWindow_ != NULL)
        {
            func_ov023_021f1818(self->menu_, 1);
            _Z24InitCombatEntry_021d8b6cPv(self->resultWindow_);
            func_ov023_021d8af8(self->resultWindow_);
            self->resultWindow_ = NULL;
        }
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((Entry_0205d6a0*)&self->menu_[0x188], 1);
        self->allocator_.Reset();
#if defined(jpn)
        self->skillMenu_ = (SkillPointMenu_021f1234*)self->allocator_.Allocate(0x654);
#else
        self->skillMenu_ = (SkillPointMenu_021f1234*)self->allocator_.Allocate(0x6cc);
#endif
        func_ov013_02184360(self->skillMenu_, self->menu_);
        func_ov013_02184cf0(self->skillMenu_, &self->allocator_);
        SkillPointMenu_021f1234* menu = self->skillMenu_;
        menu->spriteRenderer_ = &self->menu_[0x11c];
        menu->cursorAnimation_ = 0;
        self->unk_5584 = 0;
    }
    else if (self->skillMenu_ != NULL)
    {
        if (end->step_ == 0)
        {
            if (!TestBitInByteArray((int)unk, (unsigned char*)unk + 0x8c, 0x119c))
            {
                SetOrClearBitInArray(unk, (unsigned char*)unk + 0x8c, 0x119c, 1);
                if (inParty)
                {
#if defined(jpn)
                    func_02045d88(messages, FindEntryByKey((TableA68*)self->texts_, 0x24), 1);
#else
                    func_0204500c(messages, FindEntryByKey((TableA68*)self->texts_, 0x24), 1, 0xe3);
#endif

                    messages->unk_19b2 = 0;
                    messages->busy_ = 1;
                }
                end->step_ = 100;
            }
            else
            {
                _Z24ReinitController02043204Pc((char*)messages);
                SetMainBrightness(resources, -0x10, 0x10);
                end->step_++;
            }
        }
        else if (end->step_ == 100)
        {
            if (messages->unk_9a0 == 3)
                messages->unk_19af = 0;
            if (func_ov023_021f4fc8())
            {
                _Z24ReinitController02043204Pc((char*)messages);
                SetMainBrightness(resources, -0x10, 0x10);
                end->step_ = 1;
            }
        }
        else if (end->step_ == 1)
        {
            if (!IsMainBrightnessTransitionActive(resources))
            {
                end->step_++;
                _Z24ReinitController02043204Pc((char*)messages);
                _Z16ZeroInit020de868Pv(&self->menu_[0xd0]);
                SafeAllocator* allocator = &self->menuAllocator_;
                allocator->Reset();
#if defined(jpn)
                self->abilities_ = (SkillAbilityList_021f1234*)allocator->Allocate(0x58);
#else
                self->abilities_ = (SkillAbilityList_021f1234*)allocator->Allocate(0x6c);
#endif

                func_ov013_02186eec(self->abilities_, 0);
                _Z26InitAllocatorArray02186e74P17Container02186e74P13SafeAllocator((Container02186e74*)self->abilities_, allocator);
                void* member = GetCombatantWithFlag0x100(gameState, id);
                if (member != NULL)
                {
                    func_ov013_02184b4c(self->skillMenu_, member);
                    self->abilities_->member_ = *(short*)((char*)member + 4);
                }
            }
        }
        else if (end->step_ == 2)
        {
            if (func_ov013_021870f0(self->abilities_))
                end->step_++;
        }
        else if (end->step_ == 3)
        {
            SetMainBrightness(resources, 0, 0x10);
            end->step_++;
        }
        else if (end->step_ == 4)
        {
            if (!IsMainBrightnessTransitionActive(resources))
            {
                _Z27SetupContextForMode0205ea20Pvi(data_02108760, 100);
                end->step_++;
            }
        }
        else if (end->step_ == 5)
        {
            void* member = GetCombatantWithFlag0x100(gameState, id);
#if defined(jpn)
            if (func_ov013_021847c4(self->skillMenu_, gameState->GetTickCount()) == 6)
#else
            if (_Z19ResetFields021847c4P14Struct021847c4(self->skillMenu_, gameState->GetTickCount()) == 6)
#endif

            {
                if (loader->GetNumQueuedTasks() > 0)
                    return self->endState_;
                end->step_++;
                return self->endState_;
            }
            int skill = self->skillMenu_->selection_;
            if (member != NULL)
                func_ov013_0218782c(self->abilities_, (signed char)*(short*)((char*)member + 4), (unsigned char)skill);
        }
        else if (end->step_ == 6)
        {
            SetMainBrightness(resources, -0x10, 0);
            end->step_++;
        }
        else if (end->step_ == 7)
        {
            if (!IsMainBrightnessTransitionActive(resources))
                end->step_++;
        }
        else if (end->step_ == 8)
        {
            func_ov013_02186fa0(self->abilities_);
            self->abilities_ = NULL;
            end->step_++;
        }
        else if (end->step_ == 9)
        {
            SetMainBrightness(resources, 0, 0x10);
            end->step_++;
        }
        else if (end->step_ == 10)
        {
            if (!IsMainBrightnessTransitionActive(resources))
            {
                _Z27SetupContextForMode0205ea20Pvi(data_02108760, 0x65);
                GetCombatantWithFlag0x100(gameState, id);
                void* member = GetCombatantWithFlag0x100(gameState, id);
                if (member != NULL)
                {
                    func_ov013_02184c8c(self->skillMenu_, member);
                    end->newSkillCount_ = func_0209a678(end->skillTable_, member, end->newSkills_);
                    func_02083e28(GetFieldAt0x150((unsigned char*)member), 0);
                }
                func_ov017_021cc730(id, 0, 0, 1);
                func_ov017_021ccc34(id);
                func_ov017_021c9e00(id, 0, 0, 0);
                if (end->newSkillCount_ != 0)
                {
                    self->skillMenu_ = NULL;
                    _Z20ResetFields_021eefacP14Reset_021eefac((Reset_021eefac*)end);
                    end->newSkill_ = 0;
                    func_ov017_021cd0d8(id, end->newSkills_, end->newSkillCount_);
                    return 9;
                }
                end->step_++;
            }
        }
        else if (end->step_ == 11)
        {
            void* music = GetGlobal02109400();
            _Z21BlankFunction02094b40v(music);
            _Z21BlankFunction02094b34v(music, 0x65, 500, 0, 0);
            end->step_++;
        }
        else if (end->step_ == 12)
        {
            if (_Z18AlwaysTrue02094b4cv(GetGlobal02109400()))
            {
                self->skillMenu_ = NULL;
                _Z20ResetFields_021eefacP14Reset_021eefac((Reset_021eefac*)end);
                return 7;
            }
        }
    }
    return self->endState_;
}
