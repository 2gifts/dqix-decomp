#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "Resource/Brightness.h"
struct Obj020397cc;
struct TailList020469b4;
struct TailNode020469b4;
struct ZoneState021bec00 { char padding[0x23ec]; ActiveGrottoClass grotto; };
union PopupOffset021bec00 { struct { int x, y; }; long long packed; };
struct PopupController021bec00 {
    char padding0[0x918];
    short width;
    char padding91a[0x998-0x91a];
    int field998;
    char padding99c[4];
    int field9a0, field9a4;
    char padding9a8[0x1858-0x9a8];
    PopupOffset021bec00 offset;
    char padding1860[0x19ae - 0x1860];
    unsigned char flag19ae, flag19af;
    char padding19b0[8];
    unsigned char flag19b8;
};
struct GrottoTransitionData {
    unsigned short id;
    char padding2[2];
    unsigned char flag4;
    char padding5[2];
    unsigned char flag7, flag8, flag9;
    char paddinga;
    signed char fieldb;
    unsigned char flagc;
    char paddingd[3];
    int x, y, z;
    short field1c, field1e;
    int fields20[4];
    char padding30[0x6c-0x30];
    short field6c;
    char padding6e[2];
};
struct PopupState021bec00 {
    unsigned char type, complete;
    char padding2[0x38-2];
    int state;
    char padding3c[4];
    int task;
    SafeAllocator allocator;
    char script[0xa4];
};
extern "C" void func_0202ae18();
extern "C" ZoneState021bec00* func_02012fe4();
extern "C" void VectorizedMemset(void*, int, unsigned int);
extern "C" int sprintf(char*, const char*, ...);
extern "C" void func_020dfec0(void*, SafeAllocator*, void*, unsigned int);
extern "C" void func_0204500c(PopupController021bec00*, char*, int, int);
extern "C" void func_02042b98(PopupController021bec00*, int, int, int, int);
extern "C" void func_ov017_021bef84(PopupState021bec00*);
PopupController021bec00* GetGlobalField0x1c020421a0();
void CancelPendingAction020397cc(Obj020397cc*, int);
void SetBitsInField4(unsigned int*, unsigned int);
void* AllocateAligned4(AllocatorUnion*, unsigned int);
GrottoTransitionData* GetField0x3f8Address(GameState*);
void InitAndResetHeader_0219e310(unsigned char*, int);
void AppendNodeToTail(TailList020469b4*, TailNode020469b4*);
void ReinitController02043204(char*);
void SetByteField0x253(void*);
extern AllocatorUnion data_02114e20;
extern char data_ov017_021d7e98[], data_ov017_021d7eb2[];
// USA: func_ov017_021bec00
extern "C" ARM void func_ov017_021bec00(PopupState021bec00* self) {
    GameState* game = GameState::GetInstance();
    func_0202ae18();
    GameResources* resources = func_ov017_0218b5b0();
    PopupController021bec00* controller = GetGlobalField0x1c020421a0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    ActiveGrottoClass* grotto = &func_02012fe4()->grotto;
    game->GetGrottoStruct();
    char text[0x100] = {};
    controller->flag19ae = 0;
    if (self->state == 0) {
        CancelPendingAction020397cc((Obj020397cc*)game->GetUnknownGameObject(), 1);
        SetBitsInField4(&resources->brightnessFlags_0, 0xc0);
        FontBankLoader* music = GetGlobal02109400();
        BlankFunction02094b30(music, 0x203, 0);
        if (AlwaysTrue02094b4c(music)) {
            self->state = 1;
            self->allocator.CreateTypeA(AllocateAligned4(&data_02114e20, 0xc00), 0xc00);
            self->task = loader->QueueLoadFile(data_ov017_021d7e98, 0);
        }
    } else if (self->state == 1) {
        if (loader->GetTaskStatus(self->task)) {
            void* data;
            unsigned int length;
            loader->GetLoadedFileByID(self->task, &data, &length);
            self->allocator.Reset();
            func_020dfec0(&self->script, &self->allocator, data, length);
            loader->RemoveTask(self->task);
            self->task = -1;
            self->state = 2;
        }
    } else if (self->state == 2) {
        if (!IsBrightnessTransitionActive(resources)) {
            if ((unsigned char&)grotto->unknown_260_[2]) {
                GrottoTransitionData* transition = GetField0x3f8Address(game);
                VectorizedMemset(transition, 0, 0x70);
                transition->flag4 = 1;
                transition->flag8 = 1;
                transition->flag9 = 1;
                transition->fieldb = -1;
                transition->fields20[0] = -1;
                transition->fields20[1] = -1;
                transition->fields20[2] = -1;
                transition->fields20[3] = -1;
                transition->field1e = -1;
                transition->flagc = 0;
                transition->field6c = -1;
                transition->id = (unsigned short&)grotto->unknown_274_;
                Vector3fix position = *(Vector3fix*)&grotto->unknown_264_[1];
                transition->x = position.x;
                transition->y = position.y;
                transition->z = position.z;
                transition->field1c = 0x3244;
                transition->flag7 = 1;
                TailList020469b4* list;
                unsigned char* node = (unsigned char*)resources->unknown_ptr_array_36fc[4];
                list = (TailList020469b4*)resources->unknown_ptr_array_36fc[0];
                InitAndResetHeader_0219e310(node, 0);
                AppendNodeToTail(list, (TailNode020469b4*)node);
                grotto->unknown_260_[2] = 0;
                func_ov017_021bef84(self);
                self->complete = 1;
            } else {
                sprintf(text, data_ov017_021d7eb2, grotto->GetPopupName());
                func_0204500c(controller, text, 0, 256);
                controller->flag19b8 = 1;
                controller->flag19af = 0;
                func_02042b98(controller, (256-controller->width)/2, 64, controller->width, 30);
                long long offset = controller->offset.packed;
                int value = (int)offset;
                int count = (int)(offset >> 32) + 3;
                controller->offset.x = value;
                controller->offset.y = count;
                controller->field9a4 = 1;
                controller->field998 = 1;
                self->state = 3;
            }
        }
    } else if (self->state == 3 && controller->field9a0 == 0) {
        ReinitController02043204((char*)controller);
        SetByteField0x253(game->GetUnknownGameObject());
        FontBankLoader* music = GetGlobal02109400();
        BlankFunction02094b38(music, 0x1f9);
        func_02094ab0(music);
        func_ov017_021bef84(self);
        self->complete = 1;
    }
}
