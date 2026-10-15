#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Filesystem/BackgroundLoader.h>
#include <Combat/MapDisplay.h>

struct Pair021a5cbc { unsigned char values[2]; };
struct Node0x20_021a5ad0 {
    char pad_0[0x18];
    int field_18;
    unsigned char low : 4;
    unsigned char high : 4;
    char pad_1d[3];
};
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
#if defined(jpn)
enum { WindowAllocationSize = 0x400 };
#define data_ov017_021d76e8 data_ov017_021d7b28
#define data_ov017_021d7719 data_ov017_021d7b54
extern const char data_ov017_021d7b3b[];
#else
enum { WindowAllocationSize = 0x500 };
#endif
void SetWord0x18ClearByte0x1f_0204b11c(unsigned char*, int);
extern "C" void func_0204b5b4(Node0x20_021a5ad0*, unsigned char);
void DispatchViaTable0204b5e8(Obj0204b5e8*, int, int);
extern "C" void ColorEffect_ConfigureAlphaBlend(void*, int, int, int, int);
int CountActiveEntries(ActiveEntry02046900*);
void* FindRecordByIndex(Rec020467f0*, int, void**, int*);
extern "C" void func_0204b174(Node0x20_021a5ad0*, void*, SafeAllocator*, int);
void Init0205a198(Struct0205a198*);
void InitStruct0205a444(char*);
extern "C" int func_0205a528(MapEntryList*, void*, int, SafeAllocator*);
void FillFieldWithEncoded_021a5ad0(Node0x20_021a5ad0*, int, int);
extern "C" void func_0204bc74(Node0x20_021a5ad0*, int, int, int, int, int, int);
void FlushAndDispatchList0204b0e8(List0204b0e8*, void*);
void ClearAndEncodeField14_021a5b08(Node0x20_021a5ad0*, int);
void AllocateBuffer0204c7a8(Obj0204c7a8*, SafeAllocator*, int, unsigned int);
void LinkArrayPrevPointers0205cf78(Struct_0205cf78*, Elem_0205cf78*, unsigned char);
int NormalizeField5_0200fb08(Struct0200fb08*);
extern "C" void func_0205d304(Config021a5cbc*, const char*, int, unsigned char, unsigned char, unsigned char, void*
#if !defined(jpn)
    , unsigned char
#endif
);
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
extern "C" ARM void func_ov017_021a5cbc(GameResources* self) {
    if ((*reinterpret_cast<void**>(self->unknown_4094 + 0x120)) || !(*reinterpret_cast<int*>(self->unknown_4094 + 0x12c))) return;
    if ((*reinterpret_cast<int*>(self->unknown_4094 + 0x124)) == 0) {
        self->allocator_array_38[16].Reset();
        Pair021a5cbc priorities = *(const Pair021a5cbc*)(data_ov017_021d6a8c + 2);
        Pair021a5cbc styles = *(const Pair021a5cbc*)data_ov017_021d6a8c;
        for (int i = 0; i < 2; ++i) {
            Node0x20_021a5ad0* node = &reinterpret_cast<Node0x20_021a5ad0*>(self->unknown_4094)[i];
            SetWord0x18ClearByte0x1f_0204b11c((unsigned char*)node, 0);
            node->low = 0;
            node->high = priorities.values[i];
            func_0204b5b4(node, styles.values[i]);
            DispatchViaTable0204b5e8((Obj0204b5e8*)node, 0, 0);
        }
        REG_DISPLAY_CONTROL = (REG_DISPLAY_CONTROL & ~0x1f00) | 0x100;
        REG_BACKGROUND_1 = (REG_BACKGROUND_1 & 0x43) | 0x1d00;
        REG_BACKGROUND_2 = (REG_BACKGROUND_2 & 0x43) | 0x1e00;
        ColorEffect_ConfigureAlphaBlend((void*)0x04000050, 2, 1, 9, 7);
        (*reinterpret_cast<int*>(self->unknown_4094 + 0x128)) = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov017_021d76e8, 0);
        ++(*reinterpret_cast<int*>(self->unknown_4094 + 0x124));
    } else if ((*reinterpret_cast<int*>(self->unknown_4094 + 0x124)) == 1) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (!loader->GetTaskStatus((*reinterpret_cast<int*>(self->unknown_4094 + 0x128)))) return;
        void* record;
        void* file;
        unsigned int length;
        loader->GetLoadedFileByID((*reinterpret_cast<int*>(self->unknown_4094 + 0x128)), &file, &length);
        int count = CountActiveEntries((ActiveEntry02046900*)file);
        void* entries[4];
        int sizes[4];
        for (int i = 0; i < count; ++i) entries[i] = FindRecordByIndex((Rec020467f0*)file, i, &record, &sizes[i]);
        for (int i = 0; i < count; ++i) {
            if (entries[i]) func_0204b174(reinterpret_cast<Node0x20_021a5ad0*>(self->unknown_4094 + sizeof(Node0x20_021a5ad0)), entries[i], &self->allocator_array_38[16], sizes[i]);
        }
        loader->RemoveTask((*reinterpret_cast<int*>(self->unknown_4094 + 0x128)));
        (*reinterpret_cast<int*>(self->unknown_4094 + 0x128)) = -1;
        for (int i = 0; i < 7; ++i) Init0205a198(&reinterpret_cast<Struct0205a198*>(self->unknown_41c8)[i]);
        InitStruct0205a444((char*)static_cast<MapEntryList*>(self->unknown_ptr_41c4));
        static_cast<MapEntryList*>(self->unknown_ptr_41c4)->active = 0;
        MapEntryList* script = static_cast<MapEntryList*>(self->unknown_ptr_41c4);
        script->records = reinterpret_cast<Struct0205a198*>(self->unknown_41c8);
        script->count = 7;
        #if defined(jpn)
        (*reinterpret_cast<int*>(self->unknown_4094 + 0x128)) = BackgroundLoader::GetInstance()->QueueLoadFile(data_ov017_021d7b3b, 0);
#else
        (*reinterpret_cast<int*>(self->unknown_4094 + 0x128)) = BackgroundLoader::GetInstance()->QueueLoadFileInGP2(data_ov017_021d76fb, data_ov017_021d770c, 0);
#endif
        ++(*reinterpret_cast<int*>(self->unknown_4094 + 0x124));
    } else if ((*reinterpret_cast<int*>(self->unknown_4094 + 0x124)) == 2) {
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        if (!loader->GetTaskStatus((*reinterpret_cast<int*>(self->unknown_4094 + 0x128)))) return;
        void* record;
        void* file;
        unsigned int length;
        loader->GetLoadedFileByID((*reinterpret_cast<int*>(self->unknown_4094 + 0x128)), &file, &length);
        int count = CountActiveEntries((ActiveEntry02046900*)file);
        int size;
        for (int i = 0; i < count; ++i) {
            void* entry = FindRecordByIndex((Rec020467f0*)file, i, &record, &size);
            func_0205a528(static_cast<MapEntryList*>(self->unknown_ptr_41c4), entry, size, &self->allocator_array_38[16]);
        }
        loader->RemoveTask((*reinterpret_cast<int*>(self->unknown_4094 + 0x128)));
        (*reinterpret_cast<int*>(self->unknown_4094 + 0x128)) = -1;
        FillFieldWithEncoded_021a5ad0(reinterpret_cast<Node0x20_021a5ad0*>(self->unknown_4094), 2, 0x800);
        for (int i = 0; i < 2; ++i) {
            Node0x20_021a5ad0* node = &reinterpret_cast<Node0x20_021a5ad0*>(self->unknown_4094)[i];
            func_0204bc74(node, 0, 0, 0, 0x20, 0x19, 0);
            FlushAndDispatchList0204b0e8((List0204b0e8*)node, 0);
        }
        ClearAndEncodeField14_021a5b08(reinterpret_cast<Node0x20_021a5ad0*>(self->unknown_4094), 2);
        (*reinterpret_cast<void**>(self->unknown_4094 + 0x120)) = self->allocator_array_38[16].Allocate(WindowAllocationSize);
        AllocateBuffer0204c7a8(&(*reinterpret_cast<Obj0204c7a8*>(self->unknown_4094 + 0x40)), &self->allocator_array_38[16], (int)(*reinterpret_cast<void**>(self->unknown_4094 + 0x120)), 0x40);
        (*reinterpret_cast<Obj0204c7a8*>(self->unknown_4094 + 0x40)).head = reinterpret_cast<Node0x20_021a5ad0*>(self->unknown_4094 + sizeof(Node0x20_021a5ad0));
        Config021a5cbc* nodeConfig = static_cast<Config021a5cbc*>(self->unknown_ptr_array_4088[2]);
        nodeConfig->nodes = reinterpret_cast<Node0x20_021a5ad0*>(self->unknown_4094);
        nodeConfig->count = 2;
        LinkArrayPrevPointers0205cf78((Struct_0205cf78*)static_cast<Config021a5cbc*>(self->unknown_ptr_array_4088[2]), (Elem_0205cf78*)&(*reinterpret_cast<Obj0204c7a8*>(self->unknown_4094 + 0x40)), 1);
        REG_BACKGROUND_0 = (REG_BACKGROUND_0 & ~3) | 2;
        REG_BACKGROUND_1 = (REG_BACKGROUND_1 & ~3) | 1;
        REG_BACKGROUND_2 = REG_BACKGROUND_2 & ~3;
        REG_BACKGROUND_3 = (REG_BACKGROUND_3 & ~3) | 3;
        REG_DISPLAY_CONTROL = (REG_DISPLAY_CONTROL & ~0x1f00) | 0x1700;
        Config021a5cbc* config = static_cast<Config021a5cbc*>(self->unknown_ptr_array_4088[2]);
        #if defined(jpn)
        int left = 9;
#else
        Widths021a5cbc widths = *(const Widths021a5cbc*)data_ov017_021d6a94;
        int index = NormalizeField5_0200fb08((Struct0200fb08*)GameState::GetInstance());
        int left = widths.values[index - 1];
#endif
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
        func_0205d304(config, data_ov017_021d7719, 0, 0, 0, 1, 0
#if !defined(jpn)
            , 0
#endif
        );
        func_0205d0e0(config, GameState::GetInstance()->GetTickCount());
        (*reinterpret_cast<Obj0204c7a8*>(self->unknown_4094 + 0x40)).field_c2 = 0;
        ++(*reinterpret_cast<int*>(self->unknown_4094 + 0x124));
    }
}
