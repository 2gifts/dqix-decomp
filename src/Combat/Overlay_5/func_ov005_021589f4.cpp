#if defined(jpn)
#define func_ov005_021589f4 func_ov005_02159fd0
#define func_ov005_02158b3c func_ov005_0215a110
#define EQUIPMENT_PANEL_OFFSET 0xee0
#define EQUIPMENT_MESSAGE_OFFSET 0x3d49
enum { kTextBytes = 0x800 };
#else
#define EQUIPMENT_PANEL_OFFSET 0xee4
#define EQUIPMENT_MESSAGE_OFFSET 0x3dd1
enum { kTextBytes = 0x960 };
#endif
#include <globaldefs.h>
#include <std_library_functions.h>

extern "C" void* __clear(void* dst, int count);
extern "C" int func_ov005_02158b3c(void* object, void* buffer);
#if defined(jpn)
extern "C" void func_0205d304(void* renderer, void* buffer, int a, int b, bool c, bool d, void* styles);
#else
extern "C" void func_0205d304(void* renderer, void* buffer, int a, int b, bool c, bool d, void* styles, bool e);
#endif

struct EquipmentTextPanel {
    unsigned char unknown0[0xa0];
    short widthTiles, heightTiles, tileX, tileY;
    short fielda8, fieldaa, fieldac, fieldae;
    unsigned char fieldb0, fieldb1, fieldb2, fieldb3, fieldb4, fieldb5, fieldb6, fieldb7;
};

struct EquipmentMessageOwner {
    char unknown0[0xe10];
    char* textBuffer;
    char unknownE14[EQUIPMENT_PANEL_OFFSET - 0xe14];
    EquipmentTextPanel panel;
    char unknownAfterPanel[EQUIPMENT_MESSAGE_OFFSET - EQUIPMENT_PANEL_OFFSET - sizeof(EquipmentTextPanel)];
    unsigned char message;
};

#if defined(jpn)
// USA: func_ov005_021589f4
extern "C" ARM void func_ov005_021589f4(EquipmentMessageOwner* object) {
    unsigned int selector = object->message;
    int mode = 1;
    EquipmentTextPanel* panel = &object->panel;
    if (selector >= 8 && selector <= 14) {
        object->panel.widthTiles = 32;
        object->panel.heightTiles = 9;
        mode = 0;
        object->panel.tileX = 0;
        object->panel.tileY = 15;
        object->panel.fieldac = 12;
        object->panel.fieldae = 20;
        object->panel.fieldb7 = 12;
        object->panel.fielda8 = 12;
        object->panel.fieldaa = 11;
    } else {
        object->panel.widthTiles = 24;
        object->panel.heightTiles = 4;

        object->panel.tileX = 4;
        object->panel.tileY = 10;
        object->panel.fieldac = 10;
        object->panel.fieldae = 14;
        object->panel.fieldb7 = 10;
        object->panel.fielda8 = 6;
        object->panel.fieldaa = 9;
    }
    object->panel.fieldb1 = 0;
    object->panel.fieldb5 = 0;
    object->panel.fieldb6 = 0;
    memset(object->textBuffer, 0, kTextBytes);
    int result = func_ov005_02158b3c(object, object->textBuffer);
    unsigned char styles[4];
    bool special = false;
    __clear(styles, 4);
    if (result != 0) {
        special = true;
        for (int i = 1; i < 4; i++) styles[i] = 2;
    }
    func_0205d304(panel, object->textBuffer, 0, mode, false, special, styles);

}
#else
// USA: func_ov005_021589f4
extern "C" ARM void func_ov005_021589f4(EquipmentMessageOwner* object) {
    unsigned int selector = object->message;
    int mode = 1;
    EquipmentTextPanel* panel = &object->panel;
    if (selector >= 8 && selector <= 14) {
        panel->widthTiles = 32;
        panel->heightTiles = 9;
        mode = 0;
        panel->tileX = 0;
        panel->tileY = 15;
        panel->fieldac = 12;
        panel->fieldae = 20;
        panel->fieldb7 = 12;
        panel->fielda8 = 12;
        panel->fieldaa = 11;
    } else {
        panel->widthTiles = 24;
        panel->heightTiles = 5;

        panel->tileX = 4;
        panel->tileY = 10;
        panel->fieldac = 10;
        panel->fieldae = 14;
        panel->fieldb7 = 10;
        panel->fielda8 = 6;
        panel->fieldaa = 9;
    }
    panel->fieldb1 = 0;
    panel->fieldb5 = 0;
    panel->fieldb6 = 0;
    memset(object->textBuffer, 0, kTextBytes);
    int result = func_ov005_02158b3c(object, object->textBuffer);
    unsigned char styles[4];
    bool special = false;
    __clear(styles, 4);
    if (result != 0) {
        special = true;
        for (int i = 1; i < 4; i++) styles[i] = 2;
    }
    func_0205d304(panel, object->textBuffer, 0, mode, false, special, styles, false);

}
#endif
