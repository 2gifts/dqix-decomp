#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Graphics/LightingManager.h>
#include <World/Zone3D.h>
#include <std_library_functions.h>

struct StreamHeader;
struct SetFlagStruct;
struct ColorHolder0204bd7c;
struct AxisFloats0203b57c;
struct Obj02071488 {
    unsigned char chapter, entry;
    char pad_2[2];
    unsigned char kind, moved, request, field_7, skip;
    char pad_9[3];
    unsigned short parameter, zone;
    char pad_10[0x34];
};
struct Template021bbfc4 { char pad_0[0x1c]; Vector3i position; short rotation; unsigned short zone; };
struct LoadEvent021bbfc4 {
    unsigned char kind, inactive;
    char pad_2[6];
    unsigned short parameter, next;
    Obj02071488 script;
    unsigned short flags;
    short key;
    Vector3i position;
    short rotation;
    char pad_62[0x12];
    int task;
    char pad_78[0x1c];
    int status;
    unsigned char reset;
    char pad_99[3];
    unsigned char useTemplate;
    char pad_9d[3];
    Template021bbfc4 source;
    char pad_cc[0x31];
    unsigned char restart;
    char pad_fe[3];
    unsigned char ready, done;
    char pad_103[3];
    unsigned char refresh;
    char pad_107[0xf];
    signed char searchIndex;
    char pad_117;
    unsigned short copiedParameter;
    char pad_11a[0x5e];
    unsigned char hasTime : 1;
    unsigned char reserved : 7;
    unsigned char chapter, entry, slot;
    float dayTimer;
};
struct Flags021bbfc4 { char pad_0[0x8c]; unsigned char bits[0x2a6]; unsigned char index; };
struct Ticket021bbfc4 {
    unsigned short zone;
    unsigned char pending;
    char pad_3[4];
    unsigned char positioned;
    char pad_8[8];
    Vector3i position;
    short rotation;
    char pad_1e[2];
    int parameter;
    char pad_24[0x3c];
    unsigned char restart;
    char pad_61[0xd];
    unsigned char flags;
};
struct GameView021bbfc4 { char pad_0[0x5cac]; unsigned char restart; char pad_5cad[0x1547]; int pending; };
int IsSubBrightnessTransitionActive(GameResources*);
extern "C" int* func_0202ae18();
unsigned char* GetFieldIfFlag4(char*);
extern "C" Zone3D* func_02012fe4();
extern "C" void func_020531f0(GameObject*);
extern "C" void func_ov017_021bb27c(LoadEvent021bbfc4*);
extern "C" void* GetMainBG1CharacterBase();
extern "C" void* GetMainBG1ScreenBase();
int InitStreamAndRun0208dc00(StreamHeader*, int, int);
void SetBrightness(GameResources*, int, int);
Ticket021bbfc4* GetField0x3f8Address(GameState*);
void SetFlag0x9c6(SetFlagStruct*, int);
void InitStruct02070378(char*);
int RunScriptAndAdjustObj02071488(StreamHeader*, int, int, Obj02071488*);
unsigned int* GetDataPtr02114e04_020d6c00();
void OrBitsIntoField0(unsigned int*, unsigned int);
extern "C" void* func_0205ec34();
void SetOrClearBitInArray(void*, unsigned char*, int, int);
int TestBitInByteArray(int, unsigned char*, int);
ColorHolder0204bd7c* GetPtrField0x114(void*);
int ConvertColorToDecimalOffset30000(ColorHolder0204bd7c*);
extern "C" int func_0202c540(int*);
int GetField5cb0Value(char*);
int GetField5cb4Value(char*);
int GetField5cb8Value(char*);
TimeOfDay ConvertToTimeOfDay(float);
void SetField5cb0AndRecordByte0(char*, int);
void SetField5cb4AndRecordByte1(char*, int);
void SetSlotByte020107dc(char*, int);
int CheckField0NonZero(int*);
extern "C" int func_0202c508(int*);
extern "C" void func_ov017_021d0924(int, int, int, unsigned short);
int GetBitsInField0(unsigned int*, unsigned int);
extern "C" void func_ov017_021bc6e0(LoadEvent021bbfc4*, int, int);
int GetField0xcd0209c3ac(char*);
extern "C" void func_0209c2e0(void*, int, int);
int GetAxisIntValue(AxisFloats0203b57c*, int);
void SetMainBrightness(GameResources*, int, int);
extern char data_02109bf4[];

// USA: func_ov017_021bbfc4
extern "C" ARM int func_ov017_021bbfc4(LoadEvent021bbfc4* self) {
    GameState* game = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    GameResources* resources = func_ov017_0218b5b0();
    int* search = func_0202ae18();
    GameObject* original = game->GetUnknownGameObject();
    GetFieldIfFlag4((char*)game);
    Zone3D* zone = func_02012fe4();
    if (IsSubBrightnessTransitionActive(resources)) return self->next;
    for (int i = 0; i < 4; ++i) {
        GameObject* member = game->GetPartyMemberByIndex(i);
        if (member) func_020531f0(member);
    }
    if (!loader->GetTaskStatus(self->task)) return self->next;
    if (loader->GetDetailedTaskStatus(self->task) != BackgroundLoader::TaskStatus_Complete) {
        loader->RemoveTask(self->task);
        func_ov017_021bb27c(self);
        self->inactive = 1;
        return self->next;
    }
    for (int i = 0; i < 4; ++i) {
        GameObject* member = game->GetPartyMemberByIndex(i);
        if (member) func_020531f0(member);
    }
    void* character = GetMainBG1CharacterBase();
    if (character) memset(character, 0, 0x20);
    void* screen = GetMainBG1ScreenBase();
    if (screen) memset(screen, 0, 0x600);
    void* file;
    unsigned int length;
    loader->GetLoadedFileByID(self->task, &file, &length);
    if (self->useTemplate) {
        if (!InitStreamAndRun0208dc00((StreamHeader*)file, length, (int)&self->source)) {
            SetBrightness(resources, 0, 0x28);
            loader->RemoveTask(self->task);
            func_ov017_021bb27c(self);
            self->inactive = 1;
            return self->next;
        }
        memcpy(&self->position, &self->source.position, 12);
        self->rotation = self->source.rotation;
        self->script.moved = 1;
        if (self->source.zone != zone->currentZoneID_) {
            loader->RemoveTask(self->task);
            Ticket021bbfc4* ticket = GetField0x3f8Address(game);
            SetFlag0x9c6((SetFlagStruct*)resources->unknown_ptr_36d0, 1);
            InitStruct02070378((char*)ticket);
            ticket->zone = self->source.zone;
            ticket->pending = 1;
            func_ov017_021bb27c(self);
            self->inactive = 1;
            return self->next;
        }
    } else if (!RunScriptAndAdjustObj02071488((StreamHeader*)file, length, self->parameter, &self->script)) {
        SetBrightness(resources, 0, 0x28);
        loader->RemoveTask(self->task);
        func_ov017_021bb27c(self);
        self->inactive = 1;
        return self->next;
    }
    loader->RemoveTask(self->task);
    if (self->flags & 0x100) OrBitsIntoField0(GetDataPtr02114e04_020d6c00(), 1);
    self->copiedParameter = self->script.parameter;
    int transition;
    int restart;
    int reposition;
    int exists;
    Flags021bbfc4* flags = (Flags021bbfc4*)func_0205ec34();
    if (self->reset) SetOrClearBitInArray(flags, flags->bits, self->key + 0x38e, 0);
    exists = 0;
    if (TestBitInByteArray((int)flags, flags->bits, self->key + 0x38e)) exists = 1;
    if (exists) {
        SetBrightness(resources, 0, 0x28);
        ((GameView021bbfc4*)game)->pending = 0;
        func_ov017_021bb27c(self);
        self->inactive = 1;
        SetFlag0x9c6((SetFlagStruct*)resources->unknown_ptr_36d0, 0);
        return self->next;
    }
    transition = 0;
    restart = 0;
    reposition = 0;
    if (self->reset) transition = 1;
    if (self->flags & 0x80) self->script.zone = ConvertColorToDecimalOffset30000(GetPtrField0x114(original));
    if (self->script.zone != zone->currentZoneID_) transition = 1;
    if (func_0202c540(search) && self->hasTime) {
        if (self->chapter != GetField5cb0Value((char*)game) || self->entry != GetField5cb4Value((char*)game) || self->slot != GetField5cb8Value((char*)game) || ConvertToTimeOfDay(self->dayTimer) != game->GetTimeOfDay()) {
            SetField5cb0AndRecordByte0((char*)game, self->chapter);
            SetField5cb4AndRecordByte1((char*)game, self->entry);
            SetSlotByte020107dc((char*)game, self->slot);
            game->SetDayTimer(self->dayTimer);
            LightingManager* lighting = LightingManager::GetInstance();
            lighting->dayNightTimer_ = game->GetDayTimer();
            lighting->timeOfDayIndex_ = game->GetTimeOfDay();
            if (!transition) reposition = 1;
            transition = 1;
            restart = 1;
        }
    }
    int entry = GetField5cb4Value((char*)game);
    int chapter = GetField5cb0Value((char*)game);
    int current = chapter * 1000 + entry;
    unsigned int nextChapter = self->script.chapter;
    unsigned int nextEntry = self->script.entry;
    int next = nextChapter * 1000 + nextEntry;
    if (!transition && !self->script.skip && nextChapter <= 19 && (nextChapter && nextEntry) && current < next) {
        SetField5cb0AndRecordByte0((char*)game, nextChapter);
        SetField5cb4AndRecordByte1((char*)game, self->script.entry);
        if (CheckField0NonZero(search)) {
            if (func_0202c540(search)) { reposition = restart = 1; }
        }
        if (func_0202c508(search)) {
            int chapter = GetField5cb0Value((char*)game);
            int entry = GetField5cb4Value((char*)game);
            int slot = GetField5cb8Value((char*)game);
            func_ov017_021d0924(2, flags->index, 0, (unsigned short)((chapter << 10) | (entry << 5) | slot));
        }
        transition = 1;
    }
    if (self->restart || ((GameView021bbfc4*)game)->restart) restart = 1;
    if (transition) {
        Ticket021bbfc4* ticket = GetField0x3f8Address(game);
        InitStruct02070378((char*)ticket);
        ticket->zone = self->script.zone;
        ticket->parameter = self->parameter;
        ticket->pending = 1;
        if (reposition) {
            GameObject* player = game->GetUnknownGameObject();
            ticket->position = player->obj3D_.position_;
            ticket->rotation = player->obj3D_.rotation_.y;
            ticket->positioned = 1;
        }
        if (GetBitsInField0((unsigned int*)resources, 0x1000)) ticket->flags |= 9;
        ticket->restart = restart;
        SetFlag0x9c6((SetFlagStruct*)resources->unknown_ptr_36d0, 1);
        func_ov017_021bb27c(self);
        self->inactive = 1;
        return self->next;
    }
    if (CheckField0NonZero(search) && self->script.request && self->searchIndex < 0 && func_0202c508(search)) func_ov017_021bc6e0(self, -1, self->flags);
    self->status = GetField0xcd0209c3ac(data_02109bf4);
    if (self->script.kind == 3) func_0209c2e0(data_02109bf4, 0, 0);
    if (((self->flags & 1) || (self->flags & 4)) && !self->restart) {
        int brightness = GetAxisIntValue((AxisFloats0203b57c*)resources, 0);
        if (brightness > 0) SetMainBrightness(resources, 16, 30);
        else SetMainBrightness(resources, -16, 30);
        self->ready = 1;
        self->done = 1;
    }
    if (self->restart && self->refresh) self->refresh = 0;
    self->restart = 0;
    return GetBitsInField0((unsigned int*)resources, 0x1000) ? 13 : 12;
}
