#include <globaldefs.h>
#include "GameState/GameState.h"
struct Struct0203c1c8  {
    int x;
    int y;
    int category;
    int alignment;
    int active;
    short field_0x14;
};
struct DisplayEntry02180ca8  {
    char padding0[0x14];
    int x;
    int y;
    char padding1c[6];
    unsigned char id;
    char padding23[3];
    unsigned char active;
    char padding27;
};
struct Action02180ca8  {
    int flags[3];
    short amount;
    char paddinge[2];
    signed char commands[8];
    signed char commandIndex;
    char padding19[3];
    signed char state;
    signed char displayIndex;
    char padding1e[6];
    unsigned char flags24;
    char padding25[9];
    signed char slot;
    char padding2f[0x44 - 0x2f];
    int x;
    int y;
    int actorId;
    char padding50[0x87 - 0x50];
    unsigned char busy;
    char padding88[0x443 - 0x88];
    signed char animation;
    char padding444[4];
};
struct ActionStats02180ca8  {
    char padding0[0x3b];
    unsigned char : 3;
    unsigned char special : 1;
    unsigned char : 4;
};
struct Actor02180ca8  {
    char padding0[0x138];
    ActionStats02180ca8* stats;
};
struct EntryList0204af14;
struct Obj0204b878;
struct State02180ca8  {
    char padding0[0x11c];
    char display[0x54];
    DisplayEntry02180ca8* displayEntries;
    char padding174[0x8c4 - 0x174];
    char entryList[0x930 - 0x8c4];
    char padding930[0x940 - 0x930];
    int xOffset;
    int yOffset;
    char padding948[8];
    int selected;
    unsigned char mode;
    char padding955[0x1b0c - 0x955];
    Struct0203c1c8 groups[3];
    Struct0203c1c8 actionEntry;
    Struct0203c1c8 specialEntry;
    char padding1b84[0x1c5c - 0x1b84];
    Struct0203c1c8 entries[8];
    int groupIds[16];
    unsigned char entryCount;
};
extern "C" int func_ov000_0217fe30(State02180ca8*);
extern "C" void func_0205ac40(void*, void*);
int HasAnyFlags_021719f8_021719f8(int*);
int GetHPCategory02174e34(int, int);
Struct0203c1c8* GetSlotSubField0x68_ov000_02174e1c(void*, int);
extern "C" int func_ov000_02171ffc(Action02180ca8*);
void AdjustAndDispatchEntry0203c1c8(Struct0203c1c8*);
void* GetEntryByIndexStride0x10(EntryList0204af14*, unsigned int);
void CallFunc0204b620IfField0x14_0204b878(Obj0204b878*, int, int, int, short, short, short, short, unsigned short);
extern const int data_ov000_02183674[11];
static inline int ValidSlot(int slot)  { return slot >= 0 && slot <= 3; }
// USA: func_ov000_02180ca8
extern "C" ARM void func_ov000_02180ca8(State02180ca8* self, Action02180ca8* action, Obj0204b878* list)  {
    if (!action)  {
        return;
    }
    int xOffset = 0;
    int yOffset = 0;
    if (action->flags24 & 8)  {
        yOffset = self->yOffset;
        xOffset = self->xOffset;
    }
    int x = action->x;
    int y = action->y;
    int tileX;
    int tileY;
    int category;
    int actorId = action->actorId;
    tileX = x >> 3;
    tileY = y >> 3;
    GameObject* actor = GetCombatantWithFlag0x100_0200ff1c(GameState::GetInstance(), actorId);
    if (func_ov000_0217fe30(self) && actor && action->amount && ((Actor02180ca8*)actor)->stats->special)  {
        DisplayEntry02180ca8* display = &self->displayEntries[30];
        display->x = 0;
        display->y = (y + 7) << 12;
        display->id = action->actorId + 0x44;
        display->active = 0;
        func_0205ac40(self->display, display);
    }
    signed char command = action->commands[action->commandIndex];
    if (command == 0x67)  {
        return;
    }
    if (command >= 0x64)  {
        if (command != 0x66 && func_ov000_0217fe30(self) && action->amount)  {
            DisplayEntry02180ca8* display = &self->displayEntries[6];
            display->x = 0xe0000;
            display->y = (y + 7) << 12;
            display->id = action->actorId;
            display->active = 1;
            func_0205ac40(self->display, display);
        }
        if (action->state == 6 || action->amount == 0 || HasAnyFlags_021719f8_021719f8(action->flags) || action->state == 2 || action->animation != 5)  {
            return;
        }
        int slot;
        Struct0203c1c8* entry;
        int displayIndex;
        displayIndex = action->displayIndex;
        slot = action->slot;
        category = 3;
        if (action->commands[action->commandIndex] != 0x66)  {
            category = 0;
            int value = GetHPCategory02174e34((int)self, slot);
            if (value != -1)  {
                category = value;
            }
        }
        entry = 0;
        if (displayIndex >= 0 && displayIndex < self->entryCount)  {
            entry = &self->entries[displayIndex];
        }
        if (ValidSlot(slot))  {
            entry = GetSlotSubField0x68_ov000_02174e1c(self, slot);
        }
        switch (func_ov000_02171ffc(action))  {
            case 3:
            entry = &self->specialEntry;
            break;
            case 4:             if (ValidSlot(slot))  {
                entry = &self->specialEntry;
            }
            else  {
                Struct0203c1c8* group = self->groups;
                int groupId = self->groupIds[0];
                for (int i = 1; i < displayIndex + 1; ++i)  {
                    int id = self->groupIds[i];
                    if (groupId != id)  {
                        ++group;
                    }
                    groupId = id;
                }
                int count = 0;
                for (int i = 0; i < self->entryCount; ++i)  {
                    if (groupId == self->groupIds[i])  {
                        ++count;
                    }
                }
                if (count > 1)  {
                    entry = group;
                }
            }
            break;
            case 2:
            break;
            default:
            break;
        }
        if (!entry)  {
            return;
        }
        int xs[2];
        int ys[2];
        int categories[2];
        xs[0] = x + 0xb3 + xOffset;
        xs[1] = x + 0xb4 + xOffset;
        ys[0] = y + 0x17 + yOffset;
        ys[1] = y + 0x17 + yOffset;
        categories[1] = data_ov000_02183674[8];
        categories[0] = category;
        int* categoryPointer = categories;
        for (int i = 0; i < 1; ++i)  {
            int value = categoryPointer[i];
            int positionX = xs[i];
            entry->category = value;
            entry->alignment = 2;
            entry->x = positionX;
            entry->y = ys[i];
            AdjustAndDispatchEntry0203c1c8(entry);
            entry->active = 1;
        }
        entry->category = 0;
        void* selectedEntry = GetEntryByIndexStride0x10((EntryList0204af14*)self->entryList, 3);
        CallFunc0204b620IfField0x14_0204b878(list, (int)selectedEntry, 0, 0, tileX + 15, tileY + 2, 0x20, 0x19, actorId + 2);
    }
    else  {
        Struct0203c1c8* entry = &self->actionEntry;
        if (HasAnyFlags_021719f8_021719f8(action->flags) || action->busy)  {
            return;
        }
        if (self->selected == 0 && self->mode == 2)  {
            return;
        }
        int xs[2] =  {
            x + 0xb3, x + 0xb4
        };
        int ys[2] =  {
            y + 15, y + 15
        };
        int categories[2] =  {
            data_ov000_02183674[9], data_ov000_02183674[10]
        };
        entry->alignment = 2;
        int* yPointer;
        int* xPointer;
        int* categoryPointer;
        categoryPointer = categories;
        xPointer = xs;
        yPointer = ys;
        for (int i = 1; i < 2; ++i)  {
            entry->x = xPointer[i];
            entry->y = yPointer[i];
            AdjustAndDispatchEntry0203c1c8(entry);
            entry->category = categoryPointer[i];
            entry->active = 1;
        }
    }
}
