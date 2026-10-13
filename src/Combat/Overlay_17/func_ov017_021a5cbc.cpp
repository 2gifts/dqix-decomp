#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>

struct Pair021a5cbc { unsigned char values[2]; };
struct Node0x20_021a5ad0 {
    char pad_0[0x18];
    int field_18;
    unsigned char low : 4;
    unsigned char high : 4;
    char pad_1d[3];
};
struct Struct0205a198 { char data[0x28]; };
struct Script021a5cbc { char pad_0[0x40]; Struct0205a198* records; char pad_44[8]; unsigned short count; char pad_4e[2]; unsigned char active; };
struct Widths021a5cbc { short values[5]; };
struct Config021a5cbc {
    char pad_0[0x98];
    Node0x20_021a5ad0* nodes;
    char pad_9c[4];
    short left;
    short top;
    short width;
    short height;
    short field_a8;
    short field_aa;
    short field_ac;
    short field_ae;
    char pad_b0;
    unsigned char flag_b1;
    unsigned char count;
    char pad_b3[2];
    unsigned char flag_b5;
};
struct Obj0204c7a8 {
    char pad_0[4];
    Node0x20_021a5ad0* head;
    char pad_8[0xba];
    unsigned short field_c2;
};
struct Obj0204b5e8;
struct ActiveEntry02046900;
struct Rec020467f0;
struct List0204b0e8;
struct Struct_0205cf78;
struct Elem_0205cf78;
struct Struct0200fb08;
struct ResourceLoader021a5cbc {
    char pad_0[0x178];
    SafeAllocator allocator;
    char pad_18c[0x3f04];
    Config021a5cbc* config;
    Node0x20_021a5ad0 nodes[2];
    Obj0204c7a8 buffer;
    char pad_4198[0x1c];
    void* allocation;
    int stage;
    int task;
    int enabled;
    Script021a5cbc* script;
    Struct0205a198 records[7];
};
void SetWord0x18ClearByte0x1f(unsigned char*, int);
extern "C" void func_0204b5b4(Node0x20_021a5ad0*, unsigned char);
extern "C" void _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii(Obj0204b5e8*, int, int);
extern "C" void ColorEffect_ConfigureAlphaBlend(void*, int, int, int, int);
int CountActiveEntries(ActiveEntry02046900*);
void* FindRecordByIndex(Rec020467f0*, int, void**, int*);
extern "C" void func_0204b174(Node0x20_021a5ad0*, void*, SafeAllocator*, int);
extern "C" void _Z12Init0205a198P14Struct0205a198(Struct0205a198*);
extern "C" void _Z18InitStruct0205a444Pc(char*);
extern "C" void func_0205a528(Script021a5cbc*, void*, int, SafeAllocator*);
extern "C" void _Z29FillFieldWithEncoded_021a5ad0P17Node0x20_021a5ad0ii(Node0x20_021a5ad0*, int, int);
extern "C" void func_0204bc74(Node0x20_021a5ad0*, int, int, int, int, int, int);
extern "C" void _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv(List0204b0e8*, void*);
extern "C" void _Z30ClearAndEncodeField14_021a5b08P17Node0x20_021a5ad0i(Node0x20_021a5ad0*, int);
extern "C" void _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(Obj0204c7a8*, SafeAllocator*, int, unsigned int);
extern "C" void _Z29LinkArrayPrevPointers0205cf78P15Struct_0205cf78P13Elem_0205cf78h(Struct_0205cf78*, Elem_0205cf78*, unsigned char);
extern "C" int _Z24NormalizeField5_0200fb08P14Struct0200fb08(Struct0200fb08*);
extern "C" void func_0205d304(Config021a5cbc*, const char*, int, int, int, int, int, int);
extern "C" void func_0205d0e0(Config021a5cbc*, unsigned int);
extern const unsigned char data_ov017_021d6a8c[];
extern const char data_ov017_021d76e8[];
extern const char data_ov017_021d76fb[];
extern const char data_ov017_021d770c[];
extern const short data_ov017_021d6a94[];
extern const char data_ov017_021d7719[];
#define REG_DISPLAY_CONTROL (*(volatile unsigned int*)0x04000000)
#define REG_BACKGROUND_1 (*(volatile unsigned short*)0x0400000a)
#define REG_BACKGROUND_2 (*(volatile unsigned short*)0x0400000c)
#define REG_BACKGROUND_0 (*(volatile unsigned short*)0x04000008)
#define REG_BACKGROUND_3 (*(volatile unsigned short*)0x0400000e)

// USA: func_ov017_021a5cbc
extern "C" ARM void func_ov017_021a5cbc(ResourceLoader021a5cbc* self) {
    if (self->allocation || !self->enabled) return;
    if (self->stage == 0) {
        self->allocator.Reset();
        Pair021a5cbc priorities = *(const Pair021a5cbc*)(data_ov017_021d6a8c + 2);
        Pair021a5cbc styles = *(const Pair021a5cbc*)data_ov017_021d6a8c;
        for (int i = 0; i < 2; ++i) {
            Node0x20_021a5ad0* node = &self->nodes[i];
            SetWord0x18ClearByte0x1f((unsigned char*)node, 0);
            node->low = 0;
            node->high = priorities.values[i];
            func_0204b5b4(node, styles.values[i]);
            _Z24DispatchViaTable0204b5e8P11Obj0204b5e8ii((Obj0204b5e8*)node, 0, 0);
        }
        REG_DISPLAY_CONTROL = (REG_DISPLAY_CONTROL & ~0x1f00) | 0x100;
        REG_BACKGROUND_1 = (REG_BACKGROUND_1 & 0x43) | 0x1d00;
        REG_BACKGROUND_2 = (REG_BACKGROUND_2 & 0x43) | 0x1e00;
        ColorEffect_ConfigureAlphaBlend((void*)0x04000050, 2, 1, 9, 7);
        self->task = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov017_021d76e8, 0);
        ++self->stage;
    } else if (self->stage == 1) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (!loader->GetTaskStatus(self->task)) return;
        void* record;
        void* file;
        unsigned int length;
        loader->GetLoadedFileByID(self->task, &file, &length);
        int count = CountActiveEntries((ActiveEntry02046900*)file);
        void* entries[4];
        int sizes[4];
        for (int i = 0; i < count; ++i) entries[i] = FindRecordByIndex((Rec020467f0*)file, i, &record, &sizes[i]);
        for (int i = 0; i < count; ++i) {
            if (entries[i]) func_0204b174(&self->nodes[1], entries[i], &self->allocator, sizes[i]);
        }
        loader->RemoveTask(self->task);
        self->task = -1;
        for (int i = 0; i < 7; ++i) _Z12Init0205a198P14Struct0205a198(&self->records[i]);
        _Z18InitStruct0205a444Pc((char*)self->script);
        self->script->active = 0;
        Script021a5cbc* script = self->script;
        script->records = self->records;
        script->count = 7;
        self->task = BackgroundLoader::GetInstance()->QueueLoadFileInGP2(data_ov017_021d76fb, data_ov017_021d770c, 0);
        ++self->stage;
    } else if (self->stage == 2) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (!loader->GetTaskStatus(self->task)) return;
        void* record;
        void* file;
        unsigned int length;
        loader->GetLoadedFileByID(self->task, &file, &length);
        int count = CountActiveEntries((ActiveEntry02046900*)file);
        int size;
        for (int i = 0; i < count; ++i) {
            void* entry = FindRecordByIndex((Rec020467f0*)file, i, &record, &size);
            func_0205a528(self->script, entry, size, &self->allocator);
        }
        loader->RemoveTask(self->task);
        self->task = -1;
        _Z29FillFieldWithEncoded_021a5ad0P17Node0x20_021a5ad0ii(&self->nodes[0], 2, 0x800);
        for (int i = 0; i < 2; ++i) {
            Node0x20_021a5ad0* node = &self->nodes[i];
            func_0204bc74(node, 0, 0, 0, 0x20, 0x19, 0);
            _Z28FlushAndDispatchList0204b0e8P12List0204b0e8Pv((List0204b0e8*)node, 0);
        }
        _Z30ClearAndEncodeField14_021a5b08P17Node0x20_021a5ad0i(&self->nodes[0], 2);
        self->allocation = self->allocator.Allocate(0x500);
        _Z22AllocateBuffer0204c7a8P11Obj0204c7a8P13SafeAllocatorij(&self->buffer, &self->allocator, (int)self->allocation, 0x40);
        self->buffer.head = &self->nodes[1];
        Config021a5cbc* nodeConfig = self->config;
        nodeConfig->nodes = &self->nodes[0];
        nodeConfig->count = 2;
        _Z29LinkArrayPrevPointers0205cf78P15Struct_0205cf78P13Elem_0205cf78h((Struct_0205cf78*)self->config, (Elem_0205cf78*)&self->buffer, 1);
        REG_BACKGROUND_0 = (REG_BACKGROUND_0 & ~3) | 2;
        REG_BACKGROUND_1 = (REG_BACKGROUND_1 & ~3) | 1;
        REG_BACKGROUND_2 = REG_BACKGROUND_2 & ~3;
        REG_BACKGROUND_3 = (REG_BACKGROUND_3 & ~3) | 3;
        REG_DISPLAY_CONTROL = (REG_DISPLAY_CONTROL & ~0x1f00) | 0x1700;
        Config021a5cbc* config = self->config;
        Widths021a5cbc widths = *(const Widths021a5cbc*)data_ov017_021d6a94;
        int index = _Z24NormalizeField5_0200fb08P14Struct0200fb08((Struct0200fb08*)GameState::GetInstance());
        int left = widths.values[index - 1];
        config->left = left;
        config->top = 2;
        config->width = 0x20 - (left + 1);
        config->height = 0x15;
        config->field_a8 = 3;
        config->field_aa = 3;
        config->field_ac = 10;
        config->field_ae = 11;
        config->flag_b1 = 0;
        config->flag_b5 = 1;
        func_0205d304(config, data_ov017_021d7719, 0, 0, 0, 1, 0, 0);
        func_0205d0e0(config, GameState::GetInstance()->GetTickCount());
        self->buffer.field_c2 = 0;
        ++self->stage;
    }
}
