#include <globaldefs.h>
#include <Graphics/Vector.h>
#include <std_library_functions.h>

struct MenuNode021561b0 {
    virtual void slot_0();
    virtual void slot_1();
    virtual void slot_2();
    virtual void slot_3();
    virtual void slot_4();
    virtual void slot_5();
    virtual void slot_6();
    virtual void setPosition(const Vector3fix*);
    virtual Vector3fix getPosition();
    virtual void slot_9();
    virtual void slot_10();
    virtual void slot_11();
    virtual void slot_12();
    virtual void slot_13();
    virtual void slot_14();
    virtual void slot_15();
    virtual void slot_16();
    virtual void slot_17();
    virtual void slot_18();
    virtual void slot_19();
    virtual void slot_20();
    virtual void slot_21();
    virtual void slot_22();
    virtual void slot_23();
    virtual void slot_24();
    virtual void slot_25();
    virtual void slot_26();
    virtual void slot_27();
    virtual void slot_28();
    virtual void slot_29();
    virtual void slot_30();
    virtual void slot_31();
    virtual void slot_32();
    virtual void slot_33();
    virtual void slot_34();
    virtual void slot_35();
    virtual void slot_36();
    virtual void slot_37();
    virtual void slot_38();
    virtual void slot_39();
    virtual void slot_40();
    virtual void slot_41();
    virtual void slot_42();
    virtual void slot_43();
    virtual void slot_44();
    virtual void slot_45();
    virtual void slot_46();
    virtual void slot_47();
    virtual void slot_48();
    virtual void slot_49();
    virtual void setOffset(const Vector3fix*);
    virtual Vector3fix getOffset();
    char unknown_4[8];
    unsigned char flags;
    char unknown_d[0x20 - 0xd];
    char* text;
    char unknown_24[0x104 - 0x24];
    short page, column;
};
struct Grid021f9b30 {
    char unknown_0[0x5c];
    short page, column;
    unsigned char unknown_60;
    unsigned char field_61;
};
struct TextPage021561b0 { char bytes[0x100]; };
struct TextBuffers021561b0 {
    TextPage021561b0 pages[15];
    TextPage021561b0 scratch;
};
struct Data021707c8 {
    TextBuffers021561b0* buffers;
    void* field_4;
    short* keys;
    void* entries;
};
struct TableA68;
extern Data021707c8 data_ov004_021707c8;
extern char data_ov004_02170398[];
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void*);
extern "C" TableA68* func_ov023_021fa598(void*);
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
void* FindEntryByKey(TableA68*, int);
extern "C" void func_02046608(void*, int, void*, char*, int, int, int);
char* FindSubstring(char*, char*);
extern "C" void _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(Grid021f9b30*, short, unsigned int, unsigned int);
typedef void (*UnsignedGridCellSetter)(Grid021f9b30*, unsigned short, unsigned int, unsigned int);
typedef void (*UnsignedOffsetSetter)(char*, unsigned short, unsigned short);
extern "C" void func_ov023_021f9d14(Grid021f9b30*, void*);
extern "C" void _Z27SetOffset100Fields_021f8960Pcss(char*, short, short);
extern "C" void func_ov023_021f809c(void*, void*);
extern "C" int _Z25NotifyByBitfield_021560e8Pv(void*);

// USA: func_ov004_021561b0
extern "C" ARM int func_ov004_021561b0(void* object) {
    void* base = func_ov011_021849c8(object);
    short page;
    Grid021f9b30* grid = (Grid021f9b30*)func_ov023_021f6880(base, 3);
    if (!grid) return 0;
    if (func_ov023_021f6f10(grid) != 7) return 0;
    page = grid->page;
    short column = grid->column;
    void* tableNode = func_ov023_021f6880(base, 11);
    if (!tableNode) return 0;
    if (func_ov023_021f6f10(tableNode) != 4) return 0;
    TableA68* table = func_ov023_021fa598(tableNode);
    memset(data_ov004_021707c8.buffers, 0, 0x1000);
    short pageStart = page * 12;
    int count = 0;
    TextBuffers021561b0* buffers = data_ov004_021707c8.buffers;
    int padding;
    for (short i = 0; i < 12; i++) {
        int id = i + 0x6e;
        MenuNode021561b0* node = (MenuNode021561b0*)func_ov023_021f6880(base, id);
        if (!node || func_ov023_021f6f10(node) != 8) continue;
        node->text = NULL;
        node->flags &= ~8;
        int index = i + pageStart;
        if (data_ov004_021707c8.keys[index] > 0) {
            void* context = _Z26GetGlobalField0x1c020421a0v();
            memset(buffers->scratch.bytes, 0, 0x100);
            void* entry = FindEntryByKey(table, data_ov004_021707c8.keys[index]);
            func_02046608(context, 0, entry, buffers->scratch.bytes, 0x60, 0, 0);
            Vector3fix position = node->getPosition();
            Vector3fix offset = node->getOffset();
            int y = (i / 2 * 20) << 12;
            padding = 0;
            if (FindSubstring(buffers->scratch.bytes, data_ov004_02170398)) {
                y -= 0x5000;
                padding = 0x5000;
            }
            position.y = y + 0x8000;
            node->setPosition(&position);
            offset.y = padding - 0x3000;
            node->setOffset(&offset);
            char* text = data_ov004_021707c8.buffers->pages[i].bytes;
            memcpy(text, buffers->scratch.bytes, 0x100);
            ((UnsignedGridCellSetter)_Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj)(grid, (unsigned short)id, (unsigned short)(i >> 1), i & 1);
            node->text = text;
            count++;
        } else {
            _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(grid, 0, (unsigned short)(i >> 1), i & 1);
            node->flags |= 8;
        }
    }
    if (count == 0) _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(grid, 0x6e, 0, 0);
    func_ov023_021f9d14(grid, object);
    grid->field_61 = 0;
    MenuNode021561b0* node = (MenuNode021561b0*)func_ov023_021f6880(base, 0x33);
    if (!node) return 0;
    if (func_ov023_021f6f10(node) != 6) return 0;
    ((UnsignedOffsetSetter)_Z27SetOffset100Fields_021f8960Pcss)((char*)node, 0, 0xffff);
    node->page = page;
    node->column = column;
    func_ov023_021f809c(node, object);
    _Z25NotifyByBitfield_021560e8Pv(object);
    return 0;
}
