#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
#include <Resource/Brightness.h>

struct Container020e0310 { char data[0x18]; };
struct List0204af64 {
    char pad0[0x1c];
    unsigned char format : 4;
    unsigned char layer : 4;
    char pad1[3];
};
struct Entry_0205d6a0;
struct Obj0204b5e8;
struct AllocTarget0204b12c;
struct Foo0204af38;
struct ActiveEntry02046900;
struct Rec020467f0;
struct Obj0204b8d0;
struct List0204b0e8;
struct Obj0204c7a8;
struct Struct_0205cf78;
struct Elem_0205cf78;
struct TextWindow {
    char pad0[0x98];
    List0204af64* backgrounds;
    char pad1[0xb2 - 0x9c];
    unsigned char enabled;
    char pad2[0xbc - 0xb3];
};
struct Canvas {
    Canvas* previous;
    List0204af64* backgrounds;
    char pad0[0xe0 - 8];
};
struct BattleRecords {
    char pad0[0x14];
    SafeAllocator backgroundAllocator;
    char pad1[0xa0 - 0x28];
    Container020e0310 texts;
    char pad2[0xf0 - 0xb8];
    List0204af64 background;
    List0204af64 textBackground;
    TextWindow window;
    Canvas canvases[6];
    int pixels;
    char pad3[0xb12 - 0x730];
    unsigned char loadStep;
    char pad4[0xb20 - 0xb13];
    int task;
};

extern "C" GameResources* func_ov017_0218b5b0();
extern "C" const char* _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310*, int);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(Entry_0205d6a0*, int);
extern "C" void _Z17ResetList0204af64P12List0204af64(List0204af64*);
void SetWord0x18ClearByte0x1f(unsigned char*, int);
extern "C" void func_0204b5b4(List0204af64*, int);
extern "C" void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(Obj0204b5e8*, int, int);
extern "C" void _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator(AllocTarget0204b12c*, SafeAllocator*);
extern "C" void _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator(Foo0204af38*, int, SafeAllocator*);
int CountActiveEntries(ActiveEntry02046900*);
void* FindRecordByIndex(Rec020467f0*, int, void**, int*);
extern "C" void func_0204b174(List0204af64*, void*, SafeAllocator*, int);
extern "C" void _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst(Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(List0204b0e8*, void*);
extern "C" void func_0204bc74(List0204af64*, int, int, int, int, int, int);
extern "C" void _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(Obj0204c7a8*, SafeAllocator*, int, unsigned int);
extern "C" void _Z29LinkArrayPrevPointers0205cf78P15Struct_0205cf78P13Elem_0205cf78h(Struct_0205cf78*, Elem_0205cf78*, unsigned char);

// USA: func_ov008_02188a54
extern "C" ARM int func_ov008_02188a54(BattleRecords* self, int lastClear) {
    GameResources* resources = func_ov017_0218b5b0();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    int step = self->loadStep;
    if (step == 0) {
#if defined(jpn)
        int fileKey = 1;
        if (lastClear) fileKey = 2;
        const char* file = _Z21GetFieldByKey020e0434P17Container020e0310i(&self->texts, fileKey);
        self->task = loader->QueueLoadFile(file, 0);
#else
        int archiveKey = 1;
        int fileKey = 2;
        if (lastClear) {
            archiveKey = 3;
            fileKey = 4;
        }
        const char* file = _Z21GetFieldByKey020e0434P17Container020e0310i(&self->texts, fileKey);
        const char* archive = _Z21GetFieldByKey020e0434P17Container020e0310i(&self->texts, archiveKey);
        self->task = loader->QueueLoadFileInGP2(archive, file, 0);
#endif
        ++self->loadStep;
    }
    if (step == 1) {
        if (IsBrightnessTransitionActive(resources)) return 0;
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((Entry_0205d6a0*)&self->window, 1);
        ++self->loadStep;
    }
    if (step == 2) {
        if (loader->GetTaskStatus(self->task)) {
            self->backgroundAllocator.Reset();
            _Z17ResetList0204af64P12List0204af64(&self->background);
            SetWord0x18ClearByte0x1f((unsigned char*)&self->background, 0);
            self->background.format = 1;
            self->background.layer = 0;
            func_0204b5b4(&self->background, 1);
            _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii((Obj0204b5e8*)&self->background, 0, 0);
            _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator((AllocTarget0204b12c*)&self->background, &self->backgroundAllocator);
            _Z21AllocateArray0204af38P11Foo0204af38iP13SafeAllocator((Foo0204af38*)&self->background, 1, &self->backgroundAllocator);
            _Z17ResetList0204af64P12List0204af64(&self->textBackground);
            SetWord0x18ClearByte0x1f((unsigned char*)&self->textBackground, 0);
            self->textBackground.format = 1;
            self->textBackground.layer = 1;
            func_0204b5b4(&self->textBackground, 0);
            _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii((Obj0204b5e8*)&self->textBackground, 0, 0);
            _Z30AllocateAndClearBuffer0204b12cP19AllocTarget0204b12cP13SafeAllocator((AllocTarget0204b12c*)&self->textBackground, &self->backgroundAllocator);
            void* recordData;
            void* data;
            unsigned int size;
            loader->GetLoadedFileByID(self->task, &data, &size);
            int count = CountActiveEntries((ActiveEntry02046900*)data);
            int recordSize;
            for (int index = 0; index < count; ++index) {
                void* record = FindRecordByIndex((Rec020467f0*)data, index, &recordData, &recordSize);
                if (record) {
                    if (index == count - 1) func_0204b174(&self->textBackground, record, &self->backgroundAllocator, recordSize);
                    else func_0204b174(&self->background, record, &self->backgroundAllocator, recordSize);
                }
            }
            loader->RemoveTask(self->task);
            self->task = -1;
            _Z21DispatchEntry0204b8d0P11Obj0204b8d0jiisssst((Obj0204b8d0*)&self->background, 0, 0, 0, 0, 0, 32, 24, 0xffff);
            _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv((List0204b0e8*)&self->background, 0);
            func_0204bc74(&self->textBackground, 0, 0, 0, 32, 25, 0);
            _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv((List0204b0e8*)&self->textBackground, 0);
            Canvas* canvas;
            for (int index = 0; index < 6; ++index) {
                canvas = &self->canvases[index];
                _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij((Obj0204c7a8*)canvas, &self->backgroundAllocator, self->pixels, 512);
                canvas->backgrounds = &self->textBackground;
            }
            self->window.backgrounds = &self->textBackground;
            self->window.enabled = 1;
            _Z29LinkArrayPrevPointers0205cf78P15Struct_0205cf78P13Elem_0205cf78h((Struct_0205cf78*)&self->window, (Elem_0205cf78*)self->canvases, 6);
            self->loadStep = 0;
            return 1;
        }
    }
    return 0;
}
