#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "System/Graphics.h"
#include "Resource/Brightness.h"

int GetWord0x0(int* obj);
void* GetDataPtr02114e04_020d6c00(void);
void OrBitsIntoField0(unsigned int* field, unsigned int bits);
void OrGlobalFlag0x40(void);
void SetWord0x18ClearByte0x1f(unsigned char* obj, int value);
extern "C" void func_0204b5b4(void* obj, int value);
struct Obj0204b5e8;
void DispatchViaTable0204b5e8(struct Obj0204b5e8* obj, int a, int b);
struct Foo0204af38;
void AllocateArray0204af38(struct Foo0204af38* obj, int count, SafeAllocator* alloc);
struct AllocTarget0204b12c;
void AllocateAndClearBuffer0204b12c(struct AllocTarget0204b12c* obj, SafeAllocator* alloc);
struct Obj0204b010;
void ClearBuffer0204b010(struct Obj0204b010* obj, void* p);
struct Obj0204b988;
void DispatchIndexedEntry0204b988(struct Obj0204b988* obj, unsigned int a, int b, int c, unsigned short d);
struct List0204b0e8;
void FlushAndDispatchList0204b0e8(struct List0204b0e8* list, void* p);
struct ActiveEntry02046900;
int CountActiveEntries(struct ActiveEntry02046900* entries);
struct Rec020467f0;
void* FindRecordByIndex(struct Rec020467f0* table, int index, void** outPtr, int* outCount);
extern "C" void func_0204b174(void* obj, void* rec, SafeAllocator* alloc, int count);

extern char data_ov003_0217fcb5[];
extern char data_ov003_0217fcc7[];

struct SubScreenBackground {
    SafeAllocator* allocator;
    char pad0[0x18 - 0x04];
    char backgrounds[0x34 - 0x18];
    unsigned char bits34Lo : 4;
    unsigned char bits34Hi : 4;
    char pad1[0x50 - 0x35];
    int taskId;
    int pad2;
    unsigned char requested;
    signed char selectedMember;
    unsigned char ready;
    unsigned char loadState;
    unsigned char f5c;
    unsigned char flags;

    bool HasSelectedMember() const { return selectedMember >= 0 && selectedMember <= 3; }
};

// USA: func_ov003_021541b0
extern "C" ARM void func_ov003_021541b0(struct SubScreenBackground* self) {
    GameResources* resources = (GameResources*)GetWord0x0((int*)GameState::GetInstance());
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    if (self->loadState == 0) {
        if (self->HasSelectedMember()) {
            self->requested = 1;
            SetSubBrightness(resources, -16, 1);
            self->loadState++;
        }
    } else if (self->loadState == 1) {
        if (IsSubBrightnessTransitionActive(resources) == 0) {
            OrBitsIntoField0((unsigned int*)GetDataPtr02114e04_020d6c00(), 1);
            OrGlobalFlag0x40();
            self->loadState++;
        }
    } else if (self->loadState == 2) {
        BG0CNTSUB = (BG0CNTSUB & 0x43) | 0xf00;
        BG0CNTSUB &= ~3;
        BG1CNTSUB = (BG1CNTSUB & ~3) | 1;
        BG2CNTSUB = (BG2CNTSUB & ~3) | 2;
        BG3CNTSUB = (BG3CNTSUB & ~3) | 3;
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x1100;

        SafeAllocator* alloc = self->allocator;
        alloc->Reset();
        self->bits34Lo = 1;
        self->bits34Hi = 0;
        SetWord0x18ClearByte0x1f((unsigned char*)self->backgrounds, 0);
        func_0204b5b4(self->backgrounds, 0);
        DispatchViaTable0204b5e8((struct Obj0204b5e8*)self->backgrounds, 0, 0);
        AllocateArray0204af38((struct Foo0204af38*)self->backgrounds, 14, alloc);
        AllocateAndClearBuffer0204b12c((struct AllocTarget0204b12c*)self->backgrounds, alloc);
#if defined(jpn)
        self->taskId = loader->QueueLoadFile(data_ov003_0217fcb5, 0);
#else
        self->taskId = loader->QueueLoadFileInGP2(data_ov003_0217fcb5, data_ov003_0217fcc7, 0);
#endif
        self->loadState++;
    } else if (self->loadState == 3) {
        if (loader->GetTaskStatus(self->taskId) != 0) {
            SafeAllocator* alloc = self->allocator;
            void* ent;
            void* file;
            unsigned int len;
            loader->GetLoadedFileByID(self->taskId, &file, &len);
            int count = CountActiveEntries((struct ActiveEntry02046900*)file);
            for (int i = 0; i < count; i++) {
                int n;
                void* rec = FindRecordByIndex((struct Rec020467f0*)file, i, &ent, &n);
                func_0204b174(self->backgrounds, rec, alloc, n);
            }
            loader->RemoveTask(self->taskId);
            self->taskId = -1;
            ClearBuffer0204b010((struct Obj0204b010*)self->backgrounds, 0);
            DispatchIndexedEntry0204b988((struct Obj0204b988*)self->backgrounds, 0, 0, 0, 0xffff);
            FlushAndDispatchList0204b0e8((struct List0204b0e8*)self->backgrounds, 0);
            self->ready = 1;
            self->loadState = 0;
            self->flags |= 2;
        }
    }
}
