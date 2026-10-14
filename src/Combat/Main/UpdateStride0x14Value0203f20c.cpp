#include <globaldefs.h>

struct List02040468;
struct Element02040468;
extern struct Element02040468* GetValidElement02040468(struct List02040468*, int);
extern void* GetElementStride0x14_0203f1c8(unsigned char*, unsigned int);

extern int data_02114e50;

struct StrideEntry0203f20c {
    char pad0[0x8];
    int* field8;
    unsigned int* fieldc;
};

struct State0203f20c {
    struct List02040468* field0;
    char pad4[0x28 - 4];
    short field28;
    char pad2a[0x30 - 0x2a];
    int field30;
    int field34;
    int field38;
    unsigned int field3c;
    float field40;
    int field44;
    int field48;
};

// USA: func_0203f20c
ARM void UpdateStride0x14Value(struct State0203f20c* obj) {
    int index;
    struct Element02040468* elem;
    struct StrideEntry0203f20c* stride;

    index = obj->field28;
    if (index < 0) {
        return;
    }
    elem = GetValidElement02040468(obj->field0, index);
    if (elem == 0) {
        return;
    }
    stride = (struct StrideEntry0203f20c*)GetElementStride0x14_0203f1c8((unsigned char*)elem + 0x10, obj->field30);
    if (stride == 0) {
        return;
    }
    if ((unsigned int)(data_02114e50 - obj->field38) <= (unsigned int)obj->field3c) {
        return;
    }
    obj->field44 = obj->field30;
    obj->field48 = obj->field34;
    obj->field34 = stride->field8[obj->field34];
    obj->field38 = data_02114e50;
    obj->field3c = (unsigned int)((float)stride->fieldc[obj->field34] / obj->field40);
}
