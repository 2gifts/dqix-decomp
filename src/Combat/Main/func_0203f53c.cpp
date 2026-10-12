#include <globaldefs.h>
#include "Graphics/NSBXX/RenderConfig.h"

#define REG_BOX_0203f53c (*(volatile unsigned int*)0x040005c0)
#define REG_MATRIX_MODE_0203f53c (*(volatile int*)0x04000444)
#define REG_TRANSLATE_0203f53c (*(volatile int*)0x04000470)
#define REG_SCALE_0203f53c (*(volatile int*)0x0400046c)
#define REG_MATRIX_POP_0203f53c (*(volatile int*)0x04000448)

struct List02040468;
struct List_0203f354 {
    unsigned int field_0x0;
    unsigned short material, field_0x6;
    unsigned char padding[0xc];
    unsigned int flags;
};
struct Element_0203f53c {
    unsigned char padding[0x10];
    List_0203f354 list;
};
struct Stride_0203f53c {
    unsigned char padding[0x10];
    unsigned int* indices;
};
struct Record_0203f53c {
    unsigned int field_0x0, field_0x4;
    int size;
    unsigned int field_0xc;
};
struct Entry_0203f53c {
    unsigned short width, height, count, field_0x6;
    Record_0203f53c* records;
};
struct Object_0203f53c {
    List02040468* list;
    Vector3i position;
    unsigned char padding_0x10[0xc];
    Vector3i scale;
    short elementIndex;
    unsigned char padding_0x2a[0x44 - 0x2a];
    unsigned int row, column;
    int offset;
    unsigned int flags;
    int angle;
};
union Box_0203f53c {
    struct { short x, y, z, width, height, depth; } bounds;
    unsigned int words[3];
};
extern "C" Element_0203f53c* _Z23GetValidElement02040468P12List02040468i(List02040468*, int);
void* GetElementStride0x14(unsigned char*, unsigned int);
Entry_0203f53c* GetListElementByIndex(List_0203f354*, unsigned int);
void* GetPtrField0x144(void*);
int GetBoxTestResult(int*);
int GetField0x70(void*);
void IssueCommand0x1A(int);
extern "C" void func_020ca528(const void*, void*);
extern "C" void func_02031278(void*);
extern "C" void func_02031234(int);
extern "C" void func_0203f98c(Object_0203f53c*, Record_0203f53c*, int, unsigned int,
    unsigned short, unsigned short, unsigned short);
extern Matrix3x3 data_020e79e8, data_0210a0cc;
extern Vector3i data_020e79c0;
extern Box_0203f53c data_020e79cc;

static inline int MultiplyFix32_0203f53c(int a, int b) {
    int result = FIX32_MULTIPLY(a, b);
    return result;
}

// USA: func_0203f53c
extern "C" ARM int func_0203f53c(Object_0203f53c* object, void* camera, int scale) {
    if (object->flags & 1) return 0;
    if (object->elementIndex < 0) return 0;
    Element_0203f53c* element = _Z23GetValidElement02040468P12List02040468i(object->list, object->elementIndex);
    if (!element) return 0;
    Stride_0203f53c* stride = (Stride_0203f53c*)GetElementStride0x14((unsigned char*)&element->list, object->row);
    if (!stride) return 0;
    Entry_0203f53c* entry = GetListElementByIndex(&element->list, stride->indices[object->column]);
    if (!entry) return 0;
    if (!entry->records) return 0;
    Matrix3x3* view = (Matrix3x3*)GetPtrField0x144(camera);
    int scaleX = MultiplyFix32_0203f53c(object->scale.x, scale);
    int scaleY = MultiplyFix32_0203f53c(object->scale.y, scale);
    int scaleZ = MultiplyFix32_0203f53c(object->scale.z, scale);
    int height = entry->height * scaleY;
    Vector3i position;
    position.x = object->position.x;
    position.y = object->position.y + height;
    position.z = object->position.z;
    RenderConfig::SetObjectPosition(&position);
    Matrix3x3 identity = data_020e79e8;
    func_020ca528(&identity, &data_0210a0cc);
    data_0210a010.flags &= ~0xa4;
    Vector3i unity = data_020e79c0;
    RenderConfig::SetObjectScale(&unity);
    RenderConfig::SubmitToFifo();
    Box_0203f53c box = data_020e79cc;
    box.bounds.y = -height;
    box.bounds.height = height;
    REG_BOX_0203f53c = box.words[0];
    REG_BOX_0203f53c = box.words[1];
    REG_BOX_0203f53c = box.words[2];
    int visible;
    while (GetBoxTestResult(&visible) != 0) {}
    if (!visible) return 0;
    REG_MATRIX_MODE_0203f53c = 0;
    if (object->flags & 8) {
        int angle = 0x6488 - object->angle;
        if (angle >= 0x6488) angle -= 0x6488;
        int rotationAngle = -(fix32abs(fix32cos(angle)) >> 1);
        if (angle < 0) {
            while (angle * 8 < -0x3244) angle += 0xc91;
            if (angle < 0) angle += 0x6488;
        } else {
            while (angle * 8 >= 0x3244) angle -= 0xc91;
            if (angle < 0) angle += 0x6488;
        }
        int cosine = fix32cos(rotationAngle + 0x6488);
        int sine = fix32sin(rotationAngle + 0x6488);
        Matrix3x3 rotation, transformed;
        Mat3x3_WriteRotationX(&rotation, sine, cosine);
        Mat3x3_Multiply(&rotation, view, &transformed);
        int translation = MultiplyFix32_0203f53c(entry->height * (scale == 0x1000 ? 0x800 : 0xc00), scaleX);
        REG_TRANSLATE_0203f53c = 0;
        REG_TRANSLATE_0203f53c = -translation;
        REG_TRANSLATE_0203f53c = 0;
        IssueCommand0x1A((int)&transformed);
        func_02031278((void*)angle);
        REG_TRANSLATE_0203f53c = 0;
        REG_TRANSLATE_0203f53c = translation;
        REG_TRANSLATE_0203f53c = 0;
    } else {
        int translation = MultiplyFix32_0203f53c(entry->height * (scale == 0x1000 ? 0x800 : 0xc00), scaleX);
        REG_TRANSLATE_0203f53c = 0;
        REG_TRANSLATE_0203f53c = -translation;
        REG_TRANSLATE_0203f53c = 0;
        if (!(object->flags & 0x10)) IssueCommand0x1A((int)view);
        else func_02031234(GetField0x70(camera));
        REG_TRANSLATE_0203f53c = 0;
        REG_TRANSLATE_0203f53c = translation;
        REG_TRANSLATE_0203f53c = 0;
    }
    REG_TRANSLATE_0203f53c = ((-entry->width) * scaleX) >> 1;
    REG_TRANSLATE_0203f53c = 0;
    REG_TRANSLATE_0203f53c = 0;
    REG_SCALE_0203f53c = scaleX;
    REG_SCALE_0203f53c = -scaleY;
    REG_SCALE_0203f53c = scaleZ;
    int index = 0;
    int offset = object->offset;
    Record_0203f53c* record = entry->records;
    for (; index < entry->count;) {
        func_0203f98c(object, record, offset, element->list.flags,
            element->list.material, entry->width, entry->height);
        ++index;
        offset += record->size;
        ++record;
    }
    REG_MATRIX_POP_0203f53c = 1;
    return 1;
}
