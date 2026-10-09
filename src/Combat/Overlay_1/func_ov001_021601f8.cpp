#include <globaldefs.h>
#include "Graphics/LightingManager.h"

extern "C" void* func_02012fe4(void);

struct Entry_1f170 {
    short id;
    unsigned char flags;
    char pad3[0x8 - 0x3];
    struct Entry_1f170* next;
};

struct EntryList_1f170 {
    struct Entry_1f170* entries;
    int count;
};

struct Element_1f2cc {
    short key;
    short entryId;
    char pad4[0x20 - 0x4];
};

struct Manager_1f2cc {
    struct EntryList_1f170 entryList;
    char pad8[0xc - 0x8];
    struct Element_1f2cc* elements;
    int count;
};

struct Element_1f2cc* FindElementByHalfwordKey(struct Manager_1f2cc* manager, int key);
struct Entry_1f170* FindEntryBySignedId(struct EntryList_1f170* list, int id);

struct ModelHolder_021601f8 {
    char pad0[0x54];
    NSBXXInternalModel* model;
};

struct ModelHolderRef_021601f8 {
    char pad0[0x8];
    struct ModelHolder_021601f8* holder;
};

struct RenderObj_021601f8 {
    short type;
    unsigned short flags;
    union {
        struct ModelHolder_021601f8* holder;
        struct ModelHolderRef_021601f8* ref;
    };
};

struct SceneNode_021601f8 {
    unsigned short key;
    char pad2[0x24 - 0x2];
    struct RenderObj_021601f8* obj;
    char pad28[0x2c - 0x28];
    struct SceneNode_021601f8* child;
    struct SceneNode_021601f8* sibling;
};

struct LightingView_021601f8 {
    char pad0[0x98];
    int timeOfDay;
};

// USA: func_ov001_021601f8
extern "C" ARM void func_ov001_021601f8(struct SceneNode_021601f8* node, struct Manager_1f2cc* manager) {
    func_02012fe4();
    LightingManager* lighting = LightingManager::GetInstance();
    struct RenderObj_021601f8* obj = node->obj;
    int timeOfDay = ((struct LightingView_021601f8*)lighting)->timeOfDay;
    struct Element_1f2cc* element = FindElementByHalfwordKey(manager, node->key);
    struct Entry_1f170* entry = FindEntryBySignedId(&manager->entryList, element->entryId);
    struct Entry_1f170* variant = entry->next;
    while (variant != NULL) {
        if (variant->id == timeOfDay) {
            entry = variant;
            break;
        }
        variant = variant->next;
    }

    if (obj != NULL) {
        if (obj->type == 0 && obj->holder != NULL && obj->holder->model != NULL && !(obj->flags & 1)) {
            if (entry != NULL && !(entry->flags & 0x20)) {
                lighting->ModelTransformTintBrightnessContrast(obj->holder->model);
                obj->flags |= 1;
            }
        } else if (obj->type == 2 && obj->ref != NULL && obj->ref->holder != NULL && obj->ref->holder->model != NULL &&
                   !(obj->flags & 1)) {
            if (entry != NULL && !(entry->flags & 0x20)) {
                lighting->ModelTransformTintBrightnessContrast(obj->ref->holder->model);
                obj->flags |= 1;
            }
        }
    }

    if (node->child != NULL) {
        func_ov001_021601f8(node->child, manager);
    }
    if (node->sibling != NULL) {
        func_ov001_021601f8(node->sibling, manager);
    }
}
