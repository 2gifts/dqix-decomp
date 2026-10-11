#include <globaldefs.h>
#if defined(jpn)
enum { kEntryPrefix = 0x14 };
#else
enum { kEntryPrefix = 0x18 };
#endif
#include "World/Object3D.h"

struct ListEntry_02028430 {
    unsigned char id_, field1_, adjacentCount_, field3_;
    Vector3s position_; unsigned short fieldA_;
    ListEntry_02028430** adjacent_;
};
struct List_02028430 { unsigned char header_[4]; ListEntry_02028430* entries_; };
struct List_020283fc;
struct Entry_02028bd0 {
    unsigned short id_; char pad2[kEntryPrefix - 2];
    List_02028430 list_; char pad20[0x34 - 0x20];
    int active_; char pad38[0x318 - 0x38];
};
struct RoutedObject : Object3D {
    char padAC[0xb8 - 0xac]; unsigned short routeIndex_;
    char padBA[8]; unsigned char fieldC2_ : 6; unsigned char routeEnabled_ : 1;
};
Entry_02028bd0* GetEntryTableBase();
Entry_02028bd0* FindInlineEntryById(Entry_02028bd0*, int);
ListEntry_02028430* GetListEntryChecked(List_02028430*, int);
int FindListIndexById(List_020283fc*, int);
extern "C" Vector3fix func_02034104(void*);
extern "C" int func_02028524(List_02028430*, const Vector3fix&);

// USA: func_020339c8
extern "C" ARM void func_020339c8(RoutedObject* self) {
    if (!self->routeEnabled_) return;
    Entry_02028bd0* table = GetEntryTableBase();
    Entry_02028bd0* entry = FindInlineEntryById(table, self->GetField06());
    if (!entry || !entry->active_) return;
    ListEntry_02028430* node = GetListEntryChecked(&entry->list_, self->routeIndex_);
    if (!node) return;
    if (self->unknown_0_ & 0x1200) {
        int index = func_02028524(&entry->list_, func_02034104(self));
        if (index > -1) self->routeIndex_ = index;
    } else if (node->adjacentCount_) {
        Vector3fix position = func_02034104(self);
        Vector3fix nodePosition;
        nodePosition.x = node->position_.x << 12;
        nodePosition.y = node->position_.y << 12;
        nodePosition.z = node->position_.z << 12;
        int distance = Vector3fix_Distance(&position, &nodePosition);
        int selected = -1;
        for (int i = 0; i < node->adjacentCount_; ++i) {
            Vector3fix adjacentPosition;
            adjacentPosition.x = node->adjacent_[i]->position_.x << 12;
            adjacentPosition.y = node->adjacent_[i]->position_.y << 12;
            adjacentPosition.z = node->adjacent_[i]->position_.z << 12;
            if (Vector3fix_Distance(&adjacentPosition, &position) < distance) selected = node->adjacent_[i]->id_;
        }
        if (selected >= 0) {
            int index = FindListIndexById((List_020283fc*)&entry->list_, selected);
            if (index > -1) self->routeIndex_ = index;
        }
    }
}
