#include <globaldefs.h>

struct Callback_0202a91c {
    char padding0[0x4c];
    int pageSize;
    char padding50[0xc];
    short minimum, maximum, selected;
    char padding62[6];
    short repeatDelay, repeatTicks;
    unsigned char state, flags, activated, repeating, paging;
};
struct IndexList_0202a9ac;
struct IndexNode_0202a9ac { int kind; char padding4[0x34]; int busy; };
extern unsigned short data_02114e30;
int TestFlagInSecondWord_02012468(unsigned short*, unsigned int);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short*, int);
extern "C" int func_0202a9f4(Callback_0202a91c*);
extern "C" int func_0202aa94(Callback_0202a91c*);
extern "C" int func_0201248c(unsigned short*, unsigned int);
IndexNode_0202a9ac* GetNodeAtIndex(IndexList_0202a9ac*, int);
void SetState0x6cAndInvoke(Callback_0202a91c*);
void Deactivate0202a8cc(char*, int);

// USA: func_02029634
extern "C" ARM void func_02029634(Callback_0202a91c* menu, int ticks) {
    if (menu->state != 0) return;
    if (!(menu->flags & 1) && menu->minimum >= 0 && menu->minimum <= menu->maximum) {
        if (TestFlagInSecondWord_02012468(&data_02114e30, 0x40)) {
            menu->repeating = 0;
            menu->repeatDelay = 0;
            menu->repeatTicks = 0;
        }
        if (TestFlagInSecondWord_02012468(&data_02114e30, 0x80)) {
            menu->repeating = 0;
            menu->repeatDelay = 0;
            menu->repeatTicks = 0;
        }
        if (menu->repeating) menu->repeatTicks += ticks;
        if (func_0202a9f4(menu)) {
            if (menu->repeatTicks >= menu->repeatDelay) {
                menu->repeatTicks = 0;
                menu->repeatDelay -= 5;
                if (menu->repeatDelay < 0) menu->repeatDelay = 0;
                if (menu->selected != menu->minimum || !menu->repeating) {
                    --menu->selected;
                    if (menu->selected < menu->minimum) menu->selected = menu->maximum;
                }
            }
            if (!menu->repeating) {
                menu->repeatDelay = 15;
                menu->repeatTicks = 0;
            }
            menu->repeating = 1;
        } else if (func_0202aa94(menu)) {
            if (menu->repeatTicks >= menu->repeatDelay) {
                menu->repeatTicks = 0;
                menu->repeatDelay -= 5;
                if (menu->repeatDelay < 0) menu->repeatDelay = 0;
                if (menu->selected != menu->maximum || !menu->repeating) {
                    ++menu->selected;
                    if (menu->maximum < menu->selected) menu->selected = menu->minimum;
                }
            }
            if (!menu->repeating) {
                menu->repeatDelay = 15;
                menu->repeatTicks = 0;
            }
            menu->repeating = 1;
        }
        if (menu->paging) {
            if (func_0201248c(&data_02114e30, 0x20)) {
                menu->selected -= menu->pageSize;
                if (menu->selected < menu->minimum) menu->selected = menu->minimum;
            } else if (func_0201248c(&data_02114e30, 0x10)) {
                menu->selected += menu->pageSize;
                if (menu->maximum < menu->selected) menu->selected = menu->maximum;
            }
        }
    }
    IndexNode_0202a9ac* node = GetNodeAtIndex(reinterpret_cast<IndexList_0202a9ac*>(menu), menu->selected);
    if (menu->flags & 1) return;
    if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 1)) {
        int disabled = menu->flags & 2;
        if (!disabled && !node) {
            SetState0x6cAndInvoke(menu);
            menu->activated = 1;
            return;
        }
        if (!node) return;
        if (menu->selected < 0 || node->kind != 1) {
            if (disabled) return;
            SetState0x6cAndInvoke(menu);
            menu->activated = 1;
            return;
        }
        if (node->kind != 1 || node->busy != 0) return;
        Deactivate0202a8cc(reinterpret_cast<char*>(node), 1);
        menu->state = 4;
        return;
    }
    if (!(menu->flags & 4) && TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 2)) {
        menu->activated = 0;
        SetState0x6cAndInvoke(menu);
        return;
    }
    if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 4)) {
        menu->activated = 0;
        SetState0x6cAndInvoke(menu);
    }
}
