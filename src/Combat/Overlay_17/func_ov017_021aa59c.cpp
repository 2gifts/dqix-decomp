#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "Resource/Brightness.h"
#include "System/Graphics.h"
#include "System/ColorEffects.h"

struct AllocatorUnion;
struct Obj02086b98;
struct CountHead;
struct Actor0209c678;
struct Actor0209c20c;
struct Obj02081ee4;
struct Sub02081ee4;
struct List0204af64;
struct AllocTarget0204b12c;
struct Obj0204b5e8;
struct Obj0204c7a8;
struct ActiveEntry02046900;
struct Rec020467f0;
struct Obj0207f914;
struct Manager0207f7f0;
struct Node0207f7f0;
struct Obj0207fcb8;
struct Cont0207fd44;
struct Cont0207fd88;
struct Obj0208203c;
struct Obj021ab060;
struct Obj2081;
struct Obj0207fc6c;
struct Ctx021ab0c0;
struct Ctx021ab1a4;
struct Obj0205eaa0;
struct Cont0207fe44;
struct FlagWord020466f4;
struct ListHead02046b60;

extern "C" void* func_0202ae18(void);
extern "C" void* func_02012fe4(void);
void* GetDataPtr02114e04_020d6c00(void);
int GetGlobalField0x1c020421a0(void);
extern "C" int func_ov017_021959b4(void);
extern "C" void func_ov017_021aaf08(void* p);
void* GetPtrField0x2a04_02010828(GameState* gs);
int AreListedCombatantsBit0Set(struct Obj02086b98* o);
void SetFlagAndMaybeNotify_021ab010(void* p, int flag);
int CountListNodes_02046c78(struct CountHead* head);
void DispatchContextByState0209c678(struct Actor0209c678* actor, int arg);
extern "C" void func_020a0cc4(unsigned int size);
void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
extern "C" void func_020a0c0c(void);
void InitWithSub02081ee4(struct Obj02081ee4* obj, struct Sub02081ee4* sub);
void ResetList0204af64(struct List0204af64* obj);
void SetWord0x18ClearByte0x1f_0204b11c(unsigned char* obj, int value);
extern "C" void func_0204b5b4(void* obj, int value);
void AllocateAndClearBuffer0204b12c(struct AllocTarget0204b12c* obj, SafeAllocator* alloc);
int DispatchViaTable0204b5e8(struct Obj0204b5e8* obj, int a, int b);
extern "C" void func_0204c684(void* obj);
void AllocateBuffer0204c7a8(struct Obj0204c7a8* obj, SafeAllocator* alloc, int buffer, unsigned int len);
int CountActiveEntries(struct ActiveEntry02046900* entry);
void* FindRecordByIndex(struct Rec020467f0* rec, int index, void** out, int* outSize);
extern "C" void func_0204b174(void* graphics, void* file, SafeAllocator* allocator, unsigned int size);
extern "C" void func_0207f84c(void* obj);
#if defined(jpn)
extern "C" void func_02080654(struct Obj0207f914* obj, int alloc, int filename);
#else
void SetFieldsFromFormattedValue0207f914(struct Obj0207f914* obj, int alloc, int a, int b);
#endif
extern "C" int func_0207f9f4(void* obj);
void InitNodeChain0207f7f0(struct Manager0207f7f0* mgr, struct Node0207f7f0* node, int count);
void ClearAllBuffers0207fcb8(struct Obj0207fcb8* obj);
void CallFunc0204b04cOverList0x2c(struct Cont0207fd44* obj);
void CallFunc0204b088OverList0x2c(struct Cont0207fd88* obj);
void ResetWithSub0208203c(struct Obj0208203c* obj);
extern "C" void func_020813ec(void* obj, int key);
void SetThreeEntryFlags_021ab060(struct Obj021ab060* obj);
void* FindElementByByte0xc4_02081da8(struct Obj2081* obj, int key);
void CallFunc0204c87cOverEntries0207fc6c(struct Obj0207fc6c* obj, int arg);
extern "C" void func_02081f20(void* repeat, int ticks);
extern "C" int func_020800fc(void* menu, short* cursor, short prevCursor, unsigned short buttons, unsigned char columns, bool wrap);
void ClearSublistEntriesFlag4_020804fc(void* obj, int key);
int UpdateElementCoordFlag_021ab0c0(struct Ctx021ab0c0* ctx);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
void CallFunc0204c804OverAllElems(struct Cont0207fe44* obj);
void OrBitsIntoField0_020466e4(unsigned int* p, unsigned int mask);
int CheckCoordsInsideElement_021ab1a4(struct Ctx021ab1a4* ctx);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);
void ClearFlags020466f4(struct FlagWord020466f4* word, unsigned int mask);
unsigned char GetField0x5729Value_02010750(char* gs);
extern "C" void func_ov017_021d1a18(int a, int b, int c, int d);
int ListContainsId(struct ListHead02046b60* list, int id);
extern "C" void func_02046a8c(struct ListHead02046b60* list, void* node);
void ResetMpForFlaggedCombatants02010604(GameState* gs, int a, int b, int c);
void SetField0x5729Value_0201075c(char* gs, unsigned char value);
void InitActorContext0209c20c(struct Actor0209c20c* actor);

extern AllocatorUnion data_02114e20;
extern unsigned short data_02114e30;
extern struct Obj0205eaa0 data_02108760;
#if defined(jpn)
extern char data_ov017_021d7ddc[];
extern char data_ov017_021d7def[];
#else
extern char data_ov017_021d7870[];
extern char data_ov017_021d7883[];
extern char data_ov017_021d789c[];
#endif

struct ActorData02109bf4 {
    char unknown[0xd0];
};
extern ActorData02109bf4 data_02109bf4;

struct Settings02114e54 {
    char unknown_0[0x55];
    unsigned char flag55;
};
extern Settings02114e54 data_02114e54;

struct Layer021aa59c {
    char unknown_0[0x1c];
    unsigned char priority : 4;
    unsigned char index : 4;
    char unknown_1d[3];
};

struct Panel021aa59c {
    char unknown_0[4];
    Layer021aa59c* layers;
    char unknown_8[0xd8];
};

struct Menu021aa59c {
#if defined(jpn)
    char unknown_0[0x20];
#else
    char unknown_0[0x2c];
#endif
    Layer021aa59c* layers;
    char unknown_30[6];
    short cursor;
    unsigned char panelCount;
    char unknown_39;
    unsigned char active;
};

struct Input021aa59c {
    unsigned short buttons;
    unsigned char columns;
};

struct Scene021aa59c {
    unsigned short id;
#if defined(jpn)
    char unknown_2[0x27c2];
#else
    char unknown_2[0x2782];
#endif
    short y;
    short x;
    unsigned char layer;
};

struct Self021aa59c {
    unsigned char type;
    unsigned char done;
    char unknown_2[6];
    void* tileBuffer;
    int savedBgMode;
    char unknown_10[4];
    int state;
    Menu021aa59c* menu;
    Layer021aa59c* layers;
    Panel021aa59c* panels;
    SafeAllocator alloc;
    int result;
    void* repeat;
    Input021aa59c* input;
    short* cursorPtr;
    short key;
    short unknown_4a;
    short cursor;
    short prevCursor;
    int loadTask;
    char unknown_54[0x10];
    int finished;
};

// USA: func_ov017_021aa59c
extern "C" ARM void func_ov017_021aa59c(Self021aa59c* self, ListHead02046b60* list) {
    GameResources* res;
    Scene021aa59c* scene;
    GameState* gs = GameState::GetInstance();
    func_0202ae18();
    res = func_ov017_0218b5b0();
    GetGlobalField0x1c020421a0();
    CountHead* nodes = (CountHead*)res->unknown_ptr_array_36fc[0];
    scene = (Scene021aa59c*)func_02012fe4();
    unsigned int* flags = (unsigned int*)GetDataPtr02114e04_020d6c00();

    if (self->state < 6 && (func_ov017_021959b4() != 0 || res->unknown_flag_42e2 != 0)) {
        func_ov017_021aaf08(self);
        self->done = 1;
        return;
    }
    if (!AreListedCombatantsBit0Set((Obj02086b98*)GetPtrField0x2a04_02010828(gs))) {
        SetFlagAndMaybeNotify_021ab010(self, 1);
        return;
    }
    if (CountListNodes_02046c78(nodes) > 1) {
        func_ov017_021aaf08(self);
        self->done = 1;
        return;
    }

    DispatchContextByState0209c678((Actor0209c678*)&data_02109bf4, 0);
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int state = self->state;
    if (state == 0) {
        func_020a0cc4(0x7800);
        void* buffer = AllocateAligned4_02012d88(&data_02114e20, 0x7800);
        if (buffer == NULL) {
            func_020a0c0c();
            func_ov017_021aaf08(self);
            self->done = 1;
            return;
        }
        self->alloc.CreateTypeA(buffer, 0x7800);
        self->alloc.Reset();
        self->tileBuffer = self->alloc.Allocate(0x1400);
        self->panels = (Panel021aa59c*)self->alloc.Allocate(0x1c0);
        self->layers = (Layer021aa59c*)self->alloc.Allocate(0x40);
#if defined(jpn)
        self->menu = (Menu021aa59c*)self->alloc.Allocate(0x34);
#else
        self->menu = (Menu021aa59c*)self->alloc.Allocate(0x40);
#endif
        self->repeat = self->alloc.Allocate(0xc);
        self->input = (Input021aa59c*)self->alloc.Allocate(4);
        InitWithSub02081ee4((Obj02081ee4*)self->repeat, (Sub02081ee4*)self->input);

        Layer021aa59c* layer = self->layers;
        for (int i = 0; i < 2; i++) {
            ResetList0204af64((List0204af64*)layer);
            SetWord0x18ClearByte0x1f_0204b11c((unsigned char*)layer, 0);
            layer->priority = 0;
            layer->index = i + 1;
            func_0204b5b4(layer, i);
            AllocateAndClearBuffer0204b12c((AllocTarget0204b12c*)layer, &self->alloc);
            DispatchViaTable0204b5e8((Obj0204b5e8*)layer, 0, 0);
            layer++;
        }

        Panel021aa59c* panel = self->panels;
        for (unsigned char j = 0; j < 2; j++) {
            func_0204c684(panel);
            AllocateBuffer0204c7a8((Obj0204c7a8*)panel, &self->alloc, (int)self->tileBuffer, 0x800);
            panel->layers = self->layers;
            panel++;
        }

        BG1CNT = (BG1CNT & 0x43) | 0x1e00;
        BG2CNT = (BG2CNT & 0x43) | 0x1f00;
        ColorEffect_ConfigureAlphaBlend(0x04000050, 4, 1, 10, 6);
#if defined(jpn)
        self->loadTask = loader->QueueLoadFile(data_ov017_021d7ddc, NULL);
#else
        self->loadTask = loader->QueueLoadFile(data_ov017_021d7870, NULL);
#endif
        self->state = 1;
    } else if (state == 1) {
        if (loader->GetTaskStatus(self->loadTask) != 0) {
            void* record;
            void* file;
            unsigned int fileSize;
            loader->GetLoadedFileByID(self->loadTask, &file, &fileSize);
            int count = CountActiveEntries((ActiveEntry02046900*)file);
            Layer021aa59c* layers = self->layers;
            for (int i = 0; i < count; i++) {
                int recordSize;
                void* data = FindRecordByIndex((Rec020467f0*)file, i, &record, &recordSize);
                func_0204b174(layers, data, NULL, recordSize);
            }
            loader->RemoveTask(self->loadTask);
            self->loadTask = -1;
            func_0207f84c(self->menu);
#if defined(jpn)
            func_02080654((Obj0207f914*)self->menu, (int)&self->alloc, (int)data_ov017_021d7def);
#else
            SetFieldsFromFormattedValue0207f914((Obj0207f914*)self->menu, (int)&self->alloc, (int)data_ov017_021d7883, (int)data_ov017_021d789c);
#endif
            self->state = 2;
        }
    } else if (state == 2) {
        int status = func_0207f9f4(self->menu);
        if (status == 0) {
            self->state = 3;
        }
        if (status < 0) {
            self->state = 8;
        }
    } else if (state == 3) {
        Menu021aa59c* menu = self->menu;
        menu->layers = self->layers;
        menu->panelCount = 2;
        InitNodeChain0207f7f0((Manager0207f7f0*)menu, (Node0207f7f0*)self->panels, 2);
        menu->active = 1;
        ClearAllBuffers0207fcb8((Obj0207fcb8*)menu);
        CallFunc0204b04cOverList0x2c((Cont0207fd44*)menu);
        CallFunc0204b088OverList0x2c((Cont0207fd88*)menu);
        BG0CNT = (BG0CNT & ~3) | 2;
        BG1CNT = BG1CNT & ~3;
        BG2CNT = (BG2CNT & ~3) | 1;
        BG3CNT = (BG3CNT & ~3) | 3;
        DISPCNT = (DISPCNT & ~0x1f00) | 0x1700;
        self->state = 4;
    } else if (state == 4) {
        self->key = 0;
        self->cursor = 0;
        self->prevCursor = 0;
        ResetWithSub0208203c((Obj0208203c*)self->repeat);
        self->cursorPtr = NULL;
        func_020813ec(self->menu, self->key);
        SetThreeEntryFlags_021ab060((Obj021ab060*)self);
        self->state = 5;
    } else if (state == 5) {
        bool cancelled = false;
        bool redraw = false;
        void* element;
        Menu021aa59c* menu = self->menu;
        element = FindElementByByte0xc4_02081da8((Obj2081*)menu, self->key);
        if (menu != NULL) {
            if (element != NULL) {
                int ticks = gs->GetTickCount();
                CallFunc0204c87cOverEntries0207fc6c((Obj0207fc6c*)menu, ticks);
                self->cursorPtr = &self->cursor;
                if (self->cursorPtr != NULL) {
                    func_02081f20(self->repeat, ticks);
                    self->prevCursor = *self->cursorPtr;
                    self->result = func_020800fc(menu, self->cursorPtr, self->prevCursor, self->input->buttons, self->input->columns, false);
                    menu->cursor = *self->cursorPtr;
                    if (self->result != 0) {
                        ClearSublistEntriesFlag4_020804fc(menu, self->key);
                    }
                    if (self->prevCursor != *self->cursorPtr || data_02114e54.flag55 != 0) {
                        func_020813ec(menu, self->key);
                        SetThreeEntryFlags_021ab060((Obj021ab060*)self);
                    }
                }
                if (UpdateElementCoordFlag_021ab0c0((Ctx021ab0c0*)self) != 0) {
                    if (self->prevCursor != *self->cursorPtr) {
                        return;
                    }
                    DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
                    ResetWithSub0208203c((Obj0208203c*)self->repeat);
                    self->cursorPtr = NULL;
                    if (self->cursor == 0) {
                        CallFunc0204c804OverAllElems((Cont0207fe44*)self->menu);
                        OrBitsIntoField0_020466e4(flags, 0x200);
                    } else if (self->cursor == 1) {
                        cancelled = true;
                    }
                } else if (CheckCoordsInsideElement_021ab1a4((Ctx021ab1a4*)self) != 0) {
                    redraw = true;
                }
            } else if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x401) != 0 || data_02114e54.flag55 != 0) {
                func_020813ec(menu, self->key);
                SetThreeEntryFlags_021ab060((Obj021ab060*)self);
                ClearFlags020466f4((FlagWord020466f4*)flags, 0x200);
            }
        }
        if (GetField0x5729Value_02010750((char*)gs) != 0 || cancelled) {
            self->state = 6;
            redraw = true;
            self->finished = true;
        }
        if (redraw && menu != NULL && element != NULL) {
            CallFunc0204c804OverAllElems((Cont0207fe44*)self->menu);
            OrBitsIntoField0_020466e4(flags, 0x200);
        }
    } else if (state == 6) {
        if (scene->id == 10000) {
            func_ov017_021d1a18(scene->x, scene->y, scene->layer, 1);
        }
        OrBitsIntoField0_020466e4((unsigned int*)GetDataPtr02114e04_020d6c00(), 0x200000);
        SetBrightness(res, -16, 120);
        self->state = 7;
    } else if (state == 7) {
        if (IsBrightnessTransitionActive(res) != 0) {
            self->state = 8;
        }
    } else if (state == 8) {
        if (IsBrightnessTransitionActive(res) == 0) {
            if (ListContainsId(list, 0x40) != 0) {
                func_02046a8c(list, res->unknown_ptr_array_3afc[39]);
            }
            ResetMpForFlaggedCombatants02010604(gs, 0, GetField0x5729Value_02010750((char*)gs), 0);
            SetField0x5729Value_0201075c((char*)gs, 0);
            DISPCNT = (DISPCNT & ~0x1f00) | (self->savedBgMode << 8);
            func_020a0c0c();
            InitActorContext0209c20c((Actor0209c20c*)&data_02109bf4);
            func_ov017_021aaf08(self);
            self->done = 1;
        }
    }
}
