#include <globaldefs.h>

#include "Combat/EntryGetterTypes.h"
#include "GameState/GameState.h"
#include "System/Matrix.h"

struct EntrySnapshot {
    short x;
    short y;
    short z;
    short value;
    unsigned short key : 9;
    unsigned short disabled : 1;
    unsigned short nodeCount : 5;
    unsigned short mode : 1;
};

struct SnapshotReceiverView {
    unsigned char unknown0[0xc];
    Entry_203dce4 *entries[32];
    unsigned int count;
    unsigned char unknown90[0xe];
    EntrySnapshot snapshots[32];
    unsigned short id;
    unsigned short copiedCount;
    unsigned short unknown1e2;
    unsigned int selectedMask;
};

struct SnapshotNodeView {
    unsigned char unknown0[0xc];
    unsigned int status;
    SnapshotNodeView *next;
};

struct SnapshotInfoView {
    unsigned char unknown0[0xa];
    unsigned char unknownA0 : 3;
    unsigned char mode : 3;
    unsigned char unknownA6 : 2;
    unsigned char unknownB[0x29];
    SnapshotNodeView *first;
};

struct EntryLinks {
    int flags;
    char pad4[0x10];
    char *field14;
    char *field18;
    char *field1c;
};

struct PendingPosition {
    short x;
    short y;
    short z;
    unsigned char key;
};

struct Obj02033874;
struct Obj02040b2c;
struct Child02040af0;
struct Node02040774;

void *FindEntryPointerByKey0203df78(void *receiver, int key);
void SetVecYFromValue02033874(struct Obj02033874 *obj, int value);
void PropagateValueToActiveSlot02040b2c(struct Obj02040b2c *obj, int value);
void SetValueOnActiveChild02040af0(struct Child02040af0 *child, int value);
void SetActiveChildFields02040774(struct Node02040774 *node, int x, int y, int z);

// USA: func_0203e2c4
extern "C" ARM void func_0203e2c4(void *receiver, unsigned short id) {
    SnapshotReceiverView *self = static_cast<SnapshotReceiverView *>(receiver);
    if (self->id == id) {
        EntrySnapshot *snapshot = self->snapshots;
        for (int index = 0; index < self->copiedCount; ++snapshot, ++index) {
            Entry_203dce4 **slot = self->entries;
            for (unsigned int slotIndex = 0; slotIndex < self->count; ++slot, ++slotIndex) {
                EntryLinks *entry = (EntryLinks *) *slot;
                unsigned short *key = (unsigned short *) GetField0x8((int *) entry);
                void *info = GetField0xc02040538((S02040538 *) entry);
                if (key == NULL || info == NULL) {
                    continue;
                }
                if (*key != snapshot->key) {
                    continue;
                }
                Vector3i position;
                position.x = snapshot->x << 4;
                position.y = snapshot->y << 4;
                position.z = snapshot->z << 4;
                short value = snapshot->value;
                if (entry->field14 != NULL) {
                    *(Vector3i *) (entry->field14 + 4) = position;
                } else if (entry->field18 != NULL) {
                    *(Vector3i *) (entry->field18 + 0x44) = position;
                } else if (entry->field1c != NULL) {
                    *(Vector3i *) (entry->field1c + 0x44) = position;
                    SetVecYFromValue02033874((struct Obj02033874 *) entry->field1c, value);
                }
                PropagateValueToActiveSlot02040b2c((struct Obj02040b2c *) entry, value);
                SetValueOnActiveChild02040af0((struct Child02040af0 *) entry, value);
                if (snapshot->disabled) {
                    entry->flags |= 0x8000;
                }
                SnapshotInfoView *nodes = (SnapshotInfoView *) GetField0xc02040538((S02040538 *) entry);
                if (nodes != NULL) {
                    SnapshotNodeView *node = nodes->first;
                    while (node != NULL) {
                        if (snapshot->nodeCount == 0) {
                            node->status = 1;
                        } else {
                            node->status = 0;
                        }
                        snapshot->nodeCount--;
                        node = node->next;
                        if (node == nodes->first) {
                            break;
                        }
                    }
                }
                if (snapshot->mode) {
                    nodes->mode = 3;
                }
                if (self->selectedMask & (1U << slotIndex)) {
                    entry->flags |= 0x40000;
                }
                break;
            }
        }
    }
    self->id = 0;
    self->selectedMask = 0;
    GameState *gameState = GameState::GetInstance();
    PendingPosition *pending = (PendingPosition *) ((char *) gameState + 0x7e78);
    if (pending->key != 0xff) {
        struct Node02040774 *node = (struct Node02040774 *) FindEntryPointerByKey0203df78(self, pending->key);
        if (node != NULL) {
            SetActiveChildFields02040774(node, pending->x << 4, pending->y << 4, pending->z << 4);
        }
        pending->key = 0xff;
    }
}
