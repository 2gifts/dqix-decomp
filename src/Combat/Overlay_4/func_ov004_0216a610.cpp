#include <globaldefs.h>

struct Grid021f9b30 {
    char pad[0x20];
    short* cells;
    unsigned short width;
    unsigned short height;
    char pad28[0x34];
    short page;
    short field_0x5e;
};

class Widget0216a610 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void SetValue(int value);

    char pad4[8];
    unsigned char flags;
    char padd[0x13];
    char* text;
};

struct SaveEntry0216a610 {
    char pad0[6];
    char name[0xb];
    unsigned char level;
    unsigned short id : 14;
    unsigned short used : 1;
    unsigned short highBit : 1;
    char pad14[0x18];
};

struct SaveTable0216a610 {
    unsigned char count;
    char pad1[3];
    struct SaveEntry0216a610 entries[1];
};

struct Data0216a610 {
    char names[8][0x30];
    char pad180[0x10];
    struct SaveTable0216a610* table;
};

extern "C" struct Grid021f9b30* func_ov023_021f6524(void* ctx, int value);
extern "C" Widget0216a610* _Z23GetNodeIfType8_02168a6cPvi(void* a, int id);
extern "C" Widget0216a610* _Z24GetNodeIfType15_02168a38Pvi(void* a, int id);
extern "C" void func_02042764(void* src, void* dst, int flag);
extern "C" int _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(struct Grid021f9b30* self, unsigned short val, unsigned int x, unsigned int y);
extern "C" void _Z21DispatchNode_021f6630iiss(int a, int b, short c, short d);

extern struct Data0216a610* data_ov004_02171030;

// USA: func_ov004_0216a610
extern "C" ARM int func_ov004_0216a610(void* a) {
    struct SaveTable0216a610* table = data_ov004_02171030->table;
    if (table == 0) {
        return 0;
    }
    struct Grid021f9b30* grid = func_ov023_021f6524(a, 0x64);
    short page = grid->page;
    short field5e = grid->field_0x5e;
    int i;
    for (i = 0; i < 8; i++) {
        Widget0216a610* label = _Z23GetNodeIfType8_02168a6cPvi(a, i + 0xc8);
        Widget0216a610* label2 = _Z23GetNodeIfType8_02168a6cPvi(a, i + 0xd8);
        Widget0216a610* num1 = _Z24GetNodeIfType15_02168a38Pvi(a, i + 0xd0);
        Widget0216a610* num2 = _Z24GetNodeIfType15_02168a38Pvi(a, i + 0xe0);
        struct SaveEntry0216a610* e = &table->entries[i + page * 8];
        if (e->used) {
            char* name = data_ov004_02171030->names[i];
            func_02042764(e->name, name, 1);
            label->text = name;
            num1->SetValue(e->id);
            num2->SetValue(e->level);
            label->flags &= ~8;
            label2->flags &= ~8;
            num1->flags &= ~8;
            num2->flags &= ~8;
            _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(grid, i + 0xc8, (unsigned short)i, 0);
        } else {
            label->flags |= 8;
            label2->flags |= 8;
            num1->flags |= 8;
            num2->flags |= 8;
            _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(grid, 0, (unsigned short)i, 0);
        }
    }
    _Z21DispatchNode_021f6630iiss((int)a, 0x14, page, field5e);
    return 0;
}
