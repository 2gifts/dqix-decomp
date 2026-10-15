#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Combat/ScriptElementList.h"
#include "Resource/CharacterCreationUI.h"
#include "std_library_functions.h"

struct StreamHeader0208d82c;
struct StreamHeader;
struct ActiveEntry02046900;
struct Rec020467f0;
struct List0208d994;
struct PackedNibbleArray0206e120;
struct PackedNibbleArray0206e260;
struct FindEntryById02096134Table;
struct HeadNode02046b24;
struct List0204af64;
struct Obj0204b5e8;
struct SelfTag0204b3a0;

struct SaveDate0208bf78 {
    unsigned int year : 7;
    unsigned int month : 4;
    unsigned int day : 5;
    unsigned int hour : 5;
    unsigned int minute : 6;
};

struct GetTableByteOrFFData {
    unsigned char pad_0[0x178];
    SaveDate0208bf78 dates[204];
    unsigned char defeated[0x20];
};

struct StatEntry0208bf78 {
    unsigned int pad_0 : 16;
    unsigned int hasResists : 1;
    unsigned int pad_17 : 15;
    unsigned short resists[2];
    unsigned short pad_8;
    unsigned short stats[3];
};

struct StoreStruct {
    unsigned char pad_0[0x60];
    char* buffer;
};

struct TextLayout0208bf78 {
    unsigned char pad_0[0x1c];
    short width;
    short height;
    unsigned char pad_20[8];
    short firstFont;
    short lastFont;
    unsigned char pad_2c[0x28];
};

struct TextWindow0208bf78 {
    unsigned char pad_0[8];
    char* text;
    unsigned char pad_c[0x80];
    TextLayout0208bf78 layout;
};

struct RecordList0208bf78 {
    unsigned char pad_0[0x1c];
    unsigned char mode : 4;
    unsigned char layer : 4;
    unsigned char pad_1d[3];
};

struct Arena0208bf78 {
    unsigned char otherAllocators[0x28];
    SafeAllocator scriptAllocator;
    SafeAllocator* GetScriptAllocator() { return &scriptAllocator; }
};

struct RecordView0208bf78 {
    Arena0208bf78* arena;
    Container020e0310 strings;
    unsigned char pad_c[0x10];
    StreamHeader0208d860 elements;
    unsigned char pad_2c[0x90];
    int taskId;
    unsigned char pad_c0[0x12];
    short target;
    unsigned char complete;
    unsigned char state;
    unsigned char loadState;
    unsigned char pad_d7[3];
    unsigned short flags;
    unsigned char hasScript;
    unsigned char revealed;
    unsigned char pad_de;
    unsigned char showDefeated;
};

void ForwardInitStreamHeader0208d854(StreamHeader0208d82c*);
GetTableByteOrFFData* GetGlobal02109418_02094d6c();
unsigned char GetTableByteOrFF_020965ac(GetTableByteOrFFData*, unsigned char);
int RunBufferedScript02095870(void*, StreamHeader*, int, int, unsigned char*);
int CountActiveEntries(ActiveEntry02046900*);
void* FindRecordByIndex(Rec020467f0*, int, void**, int*);
int GetElementField4ByKey0208d9e8(List0208d994*, int);
int TestBitInByteArrayAt0x84_02096088(void*, int);
int TestBitInByteArray02096100(int, unsigned char*, int);
int GetFieldByKey020e0434(Container020e0310*, int);
int GetPackedNibbleField(PackedNibbleArray0206e120*, int);
unsigned char GetEntryField0209618c(FindEntryById02096134Table*, int);
int LookupArrayFieldByCase0208da18(List0208d994*, int, int);
int GetElementField0x10ByKey_0208dac4(List0208d994*, int);
int GetElementField8ByKey0208da00(List0208d994*, int);
int GetWord0x0_0200fb8c(int*);
int GetHeadNodeIdOrMinusOne(HeadNode02046b24**);
int GetElementField0x14ByKey_0208dadc(List0208d994*, int);
int GetPackedNibbleFlag0x4(PackedNibbleArray0206e260*, int);
StoreStruct* GetGlobalField0x1c020421a0();
StatEntry0208bf78* FindEntryById02096134(FindEntryById02096134Table*, int);
void StoreInArray0x8b0_020465c0(StoreStruct*, int, int);
void ResetList0204af64(List0204af64*);
void SetWord0x18ClearByte0x1f_0204b11c(unsigned char*, int);
void DispatchViaTable0204b5e8(Obj0204b5e8*, int, int);
void SetSubBg0Control0208c9cc(int, int, int, int, int);
void DispatchByTag0204b2e0(void*, char*);
void DispatchByTagLookup0204b3a0(SelfTag0204b3a0*, char*);
extern "C" void func_0204c684(TextWindow0208bf78*);
extern "C" PackedNibbleArray0206e120* func_0205ec34();
extern "C" void func_0204f41c(TextWindow0208bf78*, short, short, const char*, int, unsigned char, short*, short*, int);
extern "C" void func_02046380(StoreStruct*);
extern "C" void func_02046608(StoreStruct*, int, const char*, char*, int, int, int);
extern "C" int func_020420e8(char*, int);
extern "C" void func_0208d42c(void*, TextWindow0208bf78*, short, short, int, unsigned char, unsigned char, unsigned char, unsigned char);
extern "C" void func_0204b5b4(void*, int);

extern char data_020f1120[], data_020f113b[], data_020f114d[], data_020f116b[], data_020f117f[];
extern char data_020f1192[], data_020f1197[];

static inline unsigned char GetMonsterIndex0208bf78(GetTableByteOrFFData* table, int target) {
    return GetTableByteOrFF_020965ac(table, target);
}

static inline SaveDate0208bf78 GetSaveDate0208bf78(GetTableByteOrFFData* table, unsigned char id) {
    return table->dates[id];
}

static inline bool HasStatus0208bf78(unsigned char id, int status) {
    return GetPackedNibbleField(func_0205ec34(), id) == status;
}

static inline bool IsStatus0208bf78(PackedNibbleArray0206e120* table, unsigned char id, int status) {
    return GetPackedNibbleField(table, id) == status;
}

// USA: func_0208bf78
extern "C" ARM void func_0208bf78(RecordView0208bf78* view) {
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    if (view->loadState == 0) {
        ForwardInitStreamHeader0208d854((StreamHeader0208d82c*)&view->elements);
        view->taskId = loader->QueueLoadFileInGP2(data_020f1120, data_020f113b, 0);
        view->loadState++;
    } else if (view->loadState == 1) {
        if (!loader->GetTaskStatus(view->taskId)) return;
        SafeAllocator* allocator = view->arena->GetScriptAllocator();
        allocator->Reset();
        void* file = 0;
        unsigned int length = 0;
        loader->GetLoadedFileByID(view->taskId, &file, &length);
        if (allocator && file && length) {
            SetupHeaderAndRunBufferedScript0208d860(&view->elements, allocator, file, length, &view->target, 1, 0xfff);
        }
        loader->RemoveTask(view->taskId);
        view->taskId = -1;
        view->loadState++;
        if (!view->hasScript) view->loadState = 4;
    } else if (view->loadState == 2) {
        view->taskId = loader->QueueLoadFile(data_020f114d, 0);
        view->loadState++;
    } else if (view->loadState == 3) {
        if (!loader->GetTaskStatus(view->taskId)) return;
        void* file;
        unsigned int length;
        loader->GetLoadedFileByID(view->taskId, &file, &length);
        if (file) {
            GetTableByteOrFFData* table = GetGlobal02109418_02094d6c();
            unsigned char revealed = 0;
            RunBufferedScript02095870(table, (StreamHeader*)file, length, GetMonsterIndex0208bf78(table, view->target), &revealed);
            view->revealed = revealed;
        }
        loader->RemoveTask(view->taskId);
        view->taskId = -1;
        view->loadState++;
    } else if (view->loadState == 4) {
        if (view->target == 9999) {
            view->taskId = loader->QueueLoadFile(data_020f116b, 0);
        } else {
            view->taskId = loader->QueueLoadFile(data_020f117f, 0);
        }
        view->loadState++;
    } else if (view->loadState == 5) {
        if (!loader->GetTaskStatus(view->taskId)) return;
        void* records[4] = {0};
        void* record;
        void* file;
        unsigned int length;
        loader->GetLoadedFileByID(view->taskId, &file, &length);
        int count = CountActiveEntries((ActiveEntry02046900*)file);
        int sizes[4];
        for (int i = 0; i < count; i++) {
            records[i] = FindRecordByIndex((Rec020467f0*)file, i, &record, &sizes[i]);
        }
        TextWindow0208bf78 window;
        short width;
        short height;
        char* data = (char*)records[0];
        func_0204c684(&window);
        window.text = data + 0x10;
        window.layout.width = 0x20;
        window.layout.height = 0x18;
        window.layout.firstFont = 0xc;
        window.layout.lastFont = 0x10;
        view->flags &= ~8;
        if (view->target != 9999) {
            func_0205ec34();
            GetTableByteOrFFData* table = GetGlobal02109418_02094d6c();
            short target = view->target;
            char number[8] = {0};
            sprintf(number, data_020f1192, target);
            func_0204f41c(&window, 0x18, 0x14, number, 0xc, 0xf, &width, &height, 0);
            int text = GetElementField4ByKey0208d9e8((List0208d994*)&view->elements, target);
            bool unknown = 0;
            if (view->revealed && !TestBitInByteArrayAt0x84_02096088(table, GetMonsterIndex0208bf78(table, target))) {
                if (!TestBitInByteArray02096100((int)table, table->defeated, GetMonsterIndex0208bf78(table, target))) unknown = 1;
            }
            if (unknown) text = GetFieldByKey020e0434(&view->strings, 3);
            int kind = 0;
            func_0204f41c(&window, 0x30, 0x14, (const char*)text, 0xc, 0xf, &width, &height, kind);
            if (HasStatus0208bf78(GetMonsterIndex0208bf78(table, target), 2)) {
                text = LookupArrayFieldByCase0208da18((List0208d994*)&view->elements, target,
                                                      GetEntryField0209618c((FindEntryById02096134Table*)table, GetMonsterIndex0208bf78(table, target)));
                kind = 1;
                if (TestBitInByteArrayAt0x84_02096088(table, GetMonsterIndex0208bf78(table, target))) view->flags |= 8;
            } else if (HasStatus0208bf78(GetMonsterIndex0208bf78(table, target), 3)) {
                view->flags |= 8;
                text = GetElementField0x10ByKey_0208dac4((List0208d994*)&view->elements, target);
                kind = 2;
            } else if (view->showDefeated && TestBitInByteArrayAt0x84_02096088(table, GetMonsterIndex0208bf78(table, target))) {
                view->flags |= 8;
                text = GetElementField0x10ByKey_0208dac4((List0208d994*)&view->elements, target);
                kind = 2;
            } else {
                unsigned char id = GetMonsterIndex0208bf78(table, target);
                PackedNibbleArray0206e120* status = func_0205ec34();
                bool seen = IsStatus0208bf78(status, id, 0) || IsStatus0208bf78(status, id, 1);
                if (seen) {
                    text = GetElementField8ByKey0208da00((List0208d994*)&view->elements, target);
                    if (view->flags & 0x40) kind = 1;
                    if (view->revealed) {
                        if (HasStatus0208bf78(GetMonsterIndex0208bf78(table, target), 0)) {
                            text = GetFieldByKey020e0434(&view->strings, 4);
                        } else if (HasStatus0208bf78(GetMonsterIndex0208bf78(table, target), 1)) {
                            GameResources* resources = (GameResources*)GetWord0x0_0200fb8c((int*)GameState::GetInstance());
                            if (GetHeadNodeIdOrMinusOne((HeadNode02046b24**)resources->unknown_ptr_array_36fc[0]) == 0x2d) {
                                text = GetElementField0x14ByKey_0208dadc((List0208d994*)&view->elements, target);
                            }
                        }
                    }
                } else {
                    PackedNibbleArray0206e260* flags = (PackedNibbleArray0206e260*)func_0205ec34();
                    if (GetPackedNibbleFlag0x4(flags, GetMonsterIndex0208bf78(table, target))) {
                        text = GetElementField8ByKey0208da00((List0208d994*)&view->elements, target);
                    }
                }
            }
            StoreStruct* formatter = GetGlobalField0x1c020421a0();
            char* buffer = formatter->buffer;
            memset(buffer, 0, 0x960);
            StatEntry0208bf78* entry = FindEntryById02096134((FindEntryById02096134Table*)table, GetMonsterIndex0208bf78(table, target));
            if (entry) {
                func_02046380(formatter);
                if (entry->hasResists) {
                    for (int i = 0; i < 3; i++) {
                        int value = entry->stats[i];
                        if (value > 99) value = 99;
                        StoreInArray0x8b0_020465c0(formatter, i, value);
                    }
                }
                for (int i = 0; i < 2; i++) {
                    int value = entry->resists[i];
                    if (value > 99) value = 99;
                    StoreInArray0x8b0_020465c0(formatter, i + 3, value);
                }
            }
            func_02046608(formatter, 0xc, (const char*)text, buffer, 0xe0, 0, 1);
            func_0204f41c(&window, 0x10, 0x28, buffer, 0xc, 0xf, &width, &height, 0);
            window.layout.firstFont = 0xa;
            window.layout.lastFont = 0x10;
            func_0204f41c(&window, 0, 0, (const char*)GetFieldByKey020e0434(&view->strings, kind), 0xa, 0xe, &width, &height, 0);
            window.layout.firstFont = 8;
            window.layout.lastFont = 0x10;
            if (kind) {
                SaveDate0208bf78 date = GetSaveDate0208bf78(table, GetMonsterIndex0208bf78(table, target));
                char text2[0x100] = {0};
                sprintf(text2, data_020f1197, date.day, GetFieldByKey020e0434(&view->strings, (short)(date.month + 4)), date.year + 2000);
                func_0204f41c(&window, 0xc6 - func_020420e8(text2, 0), 0xa8, text2, 8, 0xf, &width, &height, 0);
                func_0208d42c(view, &window, 0xd7, 0xa8, date.hour, 0xf, 2, 1, 1);
                func_0208d42c(view, &window, 0xda, 0xa8, date.minute, 0xf, 2, 0, 1);
            }
        }
        RecordList0208bf78 list;
        ResetList0204af64((List0204af64*)&list);
        SetWord0x18ClearByte0x1f_0204b11c((unsigned char*)&list, 0);
        list.mode = 1;
        list.layer = 0;
        func_0204b5b4(&list, 0);
        DispatchViaTable0204b5e8((Obj0204b5e8*)&list, 0, 0);
        SetSubBg0Control0208c9cc(0, 0, 15, 0, 0);
        for (int i = 0; i < count; i++) {
            DispatchByTag0204b2e0(&list, (char*)records[i]);
            DispatchByTagLookup0204b3a0((SelfTag0204b3a0*)&list, (char*)records[i]);
        }
        loader->RemoveTask(view->taskId);
        view->taskId = -1;
        view->flags &= ~0x20;
        view->loadState = 0;
    }
}
