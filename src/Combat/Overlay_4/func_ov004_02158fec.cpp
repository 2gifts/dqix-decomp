#include <globaldefs.h>
#include "Graphics/Vector.h"

#if defined(jpn)
#define data_ov004_0216fb28 data_ov004_021702b0
#define data_ov004_0216fb34 data_ov004_021702bc
#endif

struct Icons02158fec { unsigned char entries[9]; };
extern Icons02158fec data_ov004_0216fb28;
extern Vector3i data_ov004_0216fb34;
struct State02158fec { char pad[0x31]; unsigned char flag; };
struct Holder02158fec { char pad[8]; State02158fec* data; };
extern Holder02158fec data_ov004_021707d8;
struct Container020dedd0;
struct Grid021f9b30;
struct Node02158fec {
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
    virtual void v52(); virtual void v53();
    virtual void SetStyle(int value);
    virtual void v55();
    virtual void SetNumber(int value);
    char pad4[8];
    unsigned char flags;
    char padd[0x13];
    char* text;
};
struct Page02158fec {
    char pad0[0x2c];
    Vector3i position;
    char pad38[0x24];
    short current;
    short maximum;
};
struct Entry02158fec {
    short id;
    unsigned short pad2;
    unsigned int quantity:7;
    unsigned int price:25;
};
struct Element02158fec {
    int id;
    char* text;
    unsigned int kind:4;
    unsigned int detail:5;
};
extern "C" Page02158fec* func_ov004_02156ed0(void*, int);
extern "C" Container020dedd0* func_ov004_02156fd4(void*, int);
Entry02158fec* GetEntryFor_021570a4(void*, int);
extern "C" Node02158fec* func_ov004_02156f04(void*, int);
Element02158fec* FindElementByKey020dedd0(Container020dedd0*, int);
extern "C" Node02158fec* func_ov004_02156fa0(void*, int);
extern "C" void func_ov023_021fb27c(void*, unsigned short);
extern "C" Node02158fec* func_ov004_02156f38(void*, int);
extern "C" int _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj(Grid021f9b30*, unsigned short, unsigned int, unsigned int);
extern "C" void func_ov004_02158bd4(void*);

// USA: func_ov004_02158fec
extern "C" ARM int func_ov004_02158fec(void* self) {
    int nameId = 0x12c;
    int subId = nameId + 6;
    int labelId = 0x138;
    int countId = labelId + 6;
    int priceId = 0x144;
    Page02158fec* page = func_ov004_02156ed0(self, 0x5b);
    if (page->maximum <= 1) {
        page->current = 0;
        page->maximum = 1;
    }
    Container020dedd0* container = func_ov004_02156fd4(self, 5);
    if (!container) return 0;
    Icons02158fec icons = data_ov004_0216fb28;
    unsigned int i;
    Entry02158fec* entry;
    for (i = 0; i < 6; i = (unsigned char)(i + 1), ++nameId, ++subId, ++labelId, ++countId, ++priceId) {
        entry = GetEntryFor_021570a4(self, i);
        if (entry) {
            int style = 15;
            if (!entry->quantity) style = 3;
            if (entry->id > 0) {
                Node02158fec* name = func_ov004_02156f04(self, nameId);
                if (name) {
                    Element02158fec* element = FindElementByKey020dedd0(container, entry->id);
                    if (element) {
                        name->text = element->text;
                        Node02158fec* icon = func_ov004_02156fa0(self, i + 0x14a);
                        if (!element->kind) {
                            if (icon) func_ov023_021fb27c(icon, (unsigned short)(element->detail + 0x26));
                        } else {
                            if (icon) func_ov023_021fb27c(icon, (unsigned short)(icons.entries[element->kind] + 9));
                        }
                    }
                    name->SetStyle(style);
                }
                Node02158fec* sub = func_ov004_02156f04(self, subId);
                if (sub) sub->SetStyle(style);
                Node02158fec* label = func_ov004_02156f04(self, labelId);
                if (label) label->SetStyle(style);
                Node02158fec* count = func_ov004_02156f38(self, countId);
                if (count) {
                    count->SetNumber(entry->quantity);
                    count->SetStyle(style);
                }
                Node02158fec* price = func_ov004_02156f38(self, priceId);
                if (price) {
                    price->SetNumber(entry->price);
                    price->SetStyle(style);
                }
            } else {
                Node02158fec* name = func_ov004_02156f04(self, nameId);
                if (name) name->flags |= 8;
                Node02158fec* sub = func_ov004_02156f04(self, subId);
                if (sub) sub->flags |= 8;
                Node02158fec* label = func_ov004_02156f04(self, labelId);
                if (label) label->flags |= 8;
                Node02158fec* count = func_ov004_02156f38(self, countId);
                if (count) count->flags |= 8;
                Node02158fec* price = func_ov004_02156f38(self, priceId);
                if (price) price->flags |= 8;
                _Z26SetCellIfInBounds_021f9b30P12Grid021f9b30sjj((Grid021f9b30*)page, 0, i, 0);
                Node02158fec* icon = func_ov004_02156fa0(self, i + 0x14a);
                if (icon) icon->flags |= 8;
            }
        }
    }
    func_ov004_02158bd4(self);
    if (!data_ov004_021707d8.data->flag) {
        Vector3i position = data_ov004_0216fb34;
        page->position = position;
        data_ov004_021707d8.data->flag = 0;
    }
    return 0;
}
