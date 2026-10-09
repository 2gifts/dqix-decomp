#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>

#define REG_DISPCNT (*(volatile unsigned int*)0x04000000)

struct S_e830;
struct Struct020dfc40;
struct List0204af64;
struct InitTarget0205cfd4;
struct Obj021e1318;
struct Struct_0205bef8;
struct Field150Holder02052df8;

struct MenuModel {
    char unk_0[0x88];
};

struct EquipmentSlot {
    short item_;
    signed char count_;
    unsigned char equipped_;
    void* vramState_;
    MenuModel* model_;
    int x_;
    int y_;
    int offset_;
    short loadedItem_;
};

struct MemberScreen {
    char unk_0[0x4e8];
    int memberCount_;
    int members_[4];
};

struct EquipmentMenu {
    SafeAllocator allocator_;
    SafeAllocator modelAllocator_;
    SafeAllocator equippedAllocators_[8];
    SafeAllocator itemAllocators_[16];
    SafeAllocator dragAllocator_;
    SafeAllocator textAllocator_;
    SafeAllocator unk_230;
    SafeAllocator infoAllocator_;
    SafeAllocator sortAllocator_;
    SafeAllocator modelTableAllocator_;
    SafeAllocator unk_280;
    char vramStates_[0xdf4 - 0x294];
    void* items_;
    char texts_[0x18];
    unsigned short* text_;
    char unk_e14[4];
    char layout_[0x4c];
    void* unk_e64;
    int unk_e68;
    char screenState_[0x10];
    unsigned char unk_e7c;
    unsigned char unk_e7d;
    char unk_e7e[2];
    int layers_;
    char backgrounds_[3][0x20];
    char window_[0xfa0 - 0xee4];
    char canvases_[3][0xe0];
    void* pixels_;
    char infoWindow_[0x19e0 - 0x1244];
    char sortList_[0x19ec - 0x19e0];
    char modelTable_[0x19f4 - 0x19ec];
    char cursor_[0x1a34 - 0x19f4];
    char frame_[0x1a70 - 0x1a34];
    MenuModel models_[36];
    EquipmentSlot slots_[24];
    MenuModel slotModels_[24];
    MenuModel dragModel_;
    short dragged_;
    char unk_3d7a[2];
    int unk_3d7c;
    int unk_3d80;
    int unk_3d84;
    char* pageFiles_;
    char* dragFile_;
    char* equippedFiles_;
    char* itemFile_;
    short itemCounts_[8];
    unsigned char unk_3da8;
    unsigned char equippedStep_;
    unsigned char pageStep_;
    unsigned char dragStep_;
    unsigned short unk_3dac;
    unsigned short equippedStart_;
    unsigned short equippedEnd_;
    unsigned short pageStart_;
    unsigned short pageEnd_;
    char unk_3db6;
    unsigned char loading_;
    unsigned char state_;
    unsigned char lastState_;
    unsigned char step_;
    signed char slot_;
    unsigned char kind_;
    signed char page_;
    unsigned char unk_3dbe;
    signed char lastPage_;
    signed char unk_3dc0;
    char unk_3dc1;
    unsigned short unk_3dc2;
    unsigned char loadStep_;
    char unk_3dc5[3];
    int task_;
    unsigned int flags_;
    unsigned char unk_3dd0;
    unsigned char unk_3dd1;
    unsigned char unk_3dd2;
    unsigned char unk_3dd3;
    unsigned char sortOrders_[8];
    unsigned char menuStep_;
    unsigned char menuResult_;
    signed char menuChoice_;
    unsigned char menuState_;
    short swapped_;
    short animationX_;
    int ticks_;
    int animationTime_;
    int animationPhase_;
    signed char blinks_;
    signed char blinkTimer_;
    signed char blinkTimer2_;
    unsigned char fadeStep_;
    unsigned char pageCounts_[8];
    unsigned char pages_[8];
    signed char unk_3e04;
    signed char touchTime_;
    signed char tapTimer_;
    signed char tappedSlot_;
    short touchX_;
    short touchY_;
    unsigned short digits_[20][3];
    unsigned short names_[8][0x40];
    unsigned char longNames_[8];
};

extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void func_02074af4(void* state);
extern "C" char* func_02012fe4();
short GetFieldAt0x7e(S_e830* p);
extern "C" void _Z19ResetStruct020dfc40P14Struct020dfc40(Struct020dfc40* texts);
extern "C" void _Z20ClearFields_021e20c0Pv(void* layout);
extern "C" void _Z17ResetList0204af64P12List0204af64(List0204af64* bg);
extern "C" void _Z18InitStruct0205cfd4P18InitTarget0205cfd4(InitTarget0205cfd4* window);
extern "C" void func_0204c684(void* canvas);
extern "C" void func_ov023_021dc134(void* window, int a, int b);
extern "C" void _Z17ClearObj_021e1318P11Obj021e1318(Obj021e1318* list);
extern "C" void func_ov023_021dad78(void* table);
extern "C" void func_ov005_021536e0(void* frame);
void* GetPtrField0x2a04(GameState* gameState);
extern "C" unsigned char _Z20GetTableByte0215a948Pvi(void* unused, int index);
extern "C" unsigned char _Z20GetTableByte0215a918Pvi(void* unused, int index);
short GetShortFromArray0xc10(unsigned char* p, unsigned int list);
extern "C" void _Z12Init0205bef8P15Struct_0205bef8(Struct_0205bef8* cursor);
extern "C" MemberScreen* _Z19GetField1c_021a193cPi(int* p);
extern "C" int _Z28CountPositiveEntries0207c638Pvj(void* p, unsigned int list);
short GetHalfwordEntryFromField150(Field150Holder02052df8* member, int part);
extern "C" int func_0207c7a0(void* p, int item, int a);
short* GetPointerFromArray0xbd0(unsigned char* p, unsigned int list);

// USA: func_ov005_02153ba4
extern "C" ARM void func_ov005_02153ba4(EquipmentMenu* self) {
    self->unk_e7c = 0;
    self->unk_e7d = 0;
    func_02074af4(self->screenState_);
    self->layers_ = (REG_DISPCNT & 0x1f00) >> 8;
    self->unk_3dc2 = GetFieldAt0x7e((S_e830*)(func_02012fe4() + 0x6c));
    self->allocator_.ResetAllocatorPointer();
    self->modelAllocator_.ResetAllocatorPointer();
    for (int i = 0; i < 8; i++)
        self->equippedAllocators_[i].ResetAllocatorPointer();
    for (int i = 0; i < 16; i++)
        self->itemAllocators_[i].ResetAllocatorPointer();
    self->dragAllocator_.ResetAllocatorPointer();
    self->textAllocator_.ResetAllocatorPointer();
    self->unk_230.ResetAllocatorPointer();
    self->infoAllocator_.ResetAllocatorPointer();
    self->sortAllocator_.ResetAllocatorPointer();
    self->modelTableAllocator_.ResetAllocatorPointer();
    self->unk_280.ResetAllocatorPointer();
    self->items_ = NULL;
    _Z19ResetStruct020dfc40P14Struct020dfc40((Struct020dfc40*)self->texts_);
    self->text_ = NULL;
    _Z20ClearFields_021e20c0Pv(self->layout_);
    self->unk_e64 = NULL;
    self->unk_e68 = 0;
    _Z17ResetList0204af64P12List0204af64((List0204af64*)self->backgrounds_[0]);
    _Z17ResetList0204af64P12List0204af64((List0204af64*)self->backgrounds_[1]);
    _Z17ResetList0204af64P12List0204af64((List0204af64*)self->backgrounds_[2]);
    _Z18InitStruct0205cfd4P18InitTarget0205cfd4((InitTarget0205cfd4*)self->window_);
    for (int i = 0; i < 3; i++)
        func_0204c684(self->canvases_[i]);
    self->pixels_ = NULL;
    func_ov023_021dc134(self->infoWindow_, -1, 0);
    _Z17ClearObj_021e1318P11Obj021e1318((Obj021e1318*)self->sortList_);
    func_ov023_021dad78(self->modelTable_);
    func_ov005_021536e0(self->frame_);
    for (int i = 0; i < 36; i++)
        func_0204719c(&self->models_[i]);
    for (int i = 0; i < 24; i++)
        func_0204719c(&self->slotModels_[i]);
    func_0204719c(&self->dragModel_);
    self->dragged_ = -1;
    self->unk_3d7c = 0;
    self->unk_3d80 = 0;
    self->unk_3d84 = 0;
    self->pageFiles_ = NULL;
    self->dragFile_ = NULL;
    self->equippedFiles_ = NULL;
    self->itemFile_ = NULL;
    for (int i = 0; i < 24; i++) {
        self->slots_[i].item_ = -1;
        self->slots_[i].count_ = 0;
        self->slots_[i].equipped_ = 0;
        self->slots_[i].vramState_ = NULL;
        self->slots_[i].model_ = NULL;
        self->slots_[i].x_ = 0;
        self->slots_[i].y_ = 0;
        self->slots_[i].offset_ = -1;
        self->slots_[i].loadedItem_ = -1;
    }
    GameState* gameState = GameState::GetInstance();
    char* party = (char*)GetPtrField0x2a04(gameState);
    for (int i = 0; i < 8; i++)
        self->itemCounts_[i] = GetShortFromArray0xc10((unsigned char*)(party + 0x1d4), _Z20GetTableByte0215a948Pvi(self, i));
    self->unk_3da8 = 0;
    self->equippedStep_ = 0;
    self->pageStep_ = 0;
    self->dragStep_ = 0;
    self->unk_3dac = 0;
    self->equippedStart_ = 0;
    self->equippedEnd_ = 0;
    self->pageStart_ = 0;
    self->pageEnd_ = 0;
    self->loading_ = 0;
    self->state_ = 2;
    self->lastState_ = 2;
    self->step_ = 0;
    self->slot_ = 0;
    self->kind_ = 0;
    self->unk_3dbe = 0;
    self->page_ = 0;
    self->lastPage_ = 0;
    self->loadStep_ = 0;
    self->task_ = 0;
    memset(&self->flags_, 0, sizeof(self->flags_));
    self->unk_3dc0 = -1;
    _Z12Init0205bef8P15Struct_0205bef8((Struct_0205bef8*)self->cursor_);
    self->cursor_[0x3d] = 0;
    self->unk_3dd0 = 0;
    self->unk_3dd1 = 0;
    self->unk_3dd2 = 0;
    self->unk_3dd3 = 0;
    for (int i = 0; i < 8; i++)
        self->sortOrders_[i] = 0;
    self->menuStep_ = 0;
    self->menuResult_ = 0;
    self->menuChoice_ = 0;
    self->menuState_ = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 0x40; j++)
            self->names_[i][j] = 0xffff;
        self->longNames_[i] = 0;
    }
    self->animationX_ = 0;
    self->ticks_ = 0;
    self->animationTime_ = 0;
    self->animationPhase_ = 0;
    self->blinks_ = 3;
    self->blinkTimer_ = 30;
    self->blinkTimer2_ = 30;
    self->fadeStep_ = 0;
    MemberScreen* screen = _Z19GetField1c_021a193cPi((int*)func_ov017_0218b5b0()->unknown_ptr_array_36fc[3]);
    int* members = screen->members_;
    int memberCount = screen->memberCount_;
    for (int kind = 0; kind < 8; kind++) {
        unsigned char list = _Z20GetTableByte0215a948Pvi(self, kind);
        int part = _Z20GetTableByte0215a918Pvi(self, kind);
        int count = _Z28CountPositiveEntries0207c638Pvj(party + 0x1d4, list);
        short equipped[4];
        __clear(equipped, sizeof(equipped));
        for (int i = 0; i < memberCount; i++) {
            void* member = GetCombatantWithFlag0x100(gameState, members[i]);
            if (member == NULL)
                continue;
            equipped[i] = GetHalfwordEntryFromField150((Field150Holder02052df8*)member, part);
            if (equipped[i] <= 0)
                continue;
            int j;
            for (j = 0; j < i; j++)
                ;
            if (!func_0207c7a0(party + 0x1d4, equipped[i], 9))
                count++;
        }
        if (count > 0)
            self->pageCounts_[kind] = (count - 1) / 16 + 1;
        else
            self->pageCounts_[kind] = 1;
        short* items = GetPointerFromArray0xbd0((unsigned char*)(party + 0x1d4), list);
        short itemCount = GetShortFromArray0xc10((unsigned char*)(party + 0x1d4), list);
        int last = 0;
        for (int i = 0; i < itemCount; i++) {
            if (items[i] > 0 && last < i)
                last = i;
        }
        unsigned char pages = last / 16 + 1;
        if (pages > self->pageCounts_[kind])
            self->pageCounts_[kind] = pages;
        self->pages_[kind] = 0;
    }
    self->unk_3e04 = 0;
    self->touchTime_ = 0;
    self->tappedSlot_ = -2;
    self->tapTimer_ = 0;
    self->touchX_ = -1;
    self->touchY_ = -1;
}
