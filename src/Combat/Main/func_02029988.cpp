#include <globaldefs.h>
#include "std_library_functions.h"

struct DebugMenuItem {
    int type;
    char text[0x30];
    DebugMenuItem* next;
    int disabled;
    char padding_3c[4];
    int value;
    char padding_44[8];
    unsigned short flags;
};

struct DebugMenu {
    int type;
    char text[0x40];
    DebugMenuItem* items;
    char padding_48[8];
    short x;
    short y;
    short width;
    short height;
    short shownHeight;
    unsigned short count;
    short first;
    short last;
    short selected;
    unsigned short visibleCount;
    unsigned short visibleFirst;
    unsigned short visibleLast;
    char padding_68[4];
    unsigned char state;
    unsigned char flags;
    unsigned char activated;
    unsigned char repeating;
    unsigned char paging;
    unsigned char touching;
    unsigned char touchEnabled;
    unsigned char touchList;
    unsigned char touchBar;
};

struct TouchInput {
    char padding_0[0x24];
    unsigned short held;
    char padding_26[0x12];
    int x;
    int y;
    char padding_40[0x14];
    unsigned char released;
    unsigned char pressed;
    char padding_56[9];
    unsigned char down;
};

struct Metrics020ef74c {
    int field_0;
    int rowHeight;
    int columnWidth;
    int font;
};

struct TextColor020fe9a4 {
    void* buffer;
    int highlight;
};

struct IndexList_0202a9ac;
struct Callback_0202a91c;
struct WrapField_0202a678;

extern "C" void func_02029634(DebugMenu* menu, int ticks);
DebugMenuItem* GetNodeAtIndex(IndexList_0202a9ac*, int);
void SelectCoordsByFlag0x24_02012a84(unsigned char*, int*, int*);
void SetState0x6cAndInvoke(Callback_0202a91c*);
void Deactivate0202a8cc(char*, int);
void FormatAndDispatch0202ad98(int a, int b, int c, const char* fmt, ...);
void FormatAndDispatch020290e8(int a, int b, const char* fmt, ...);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short*, int);
int TestFlagMask_02012430(unsigned short*, int);
extern "C" int func_0201248c(unsigned short*, unsigned int);
void AdjustValueWrapOrClamp(WrapField_0202a678*, int);
extern "C" void func_0202a6c4(DebugMenu* menu);
extern "C" void* __clear(void*, int);
int SetupViewport02029384(int, int, int, int);
void PackRegister02029470(int, int, int, int, int, int);
extern "C" void func_020292ec(int a0, int a1, int a2, int a3, int a4);

extern TouchInput data_02114e54;
extern Metrics020ef74c data_020ef74c;
extern TextColor020fe9a4 data_020fe9a4;
extern unsigned short data_02114e30;
extern const char data_020ef75c[];
extern const char data_020ef75f[];
extern const char data_020ef763[];
extern const char data_020ef767[];
extern const char data_020ef76b[];
extern const char data_020ef76f[];
extern const char data_020ef772[];
extern const char data_020ef775[];
extern const char data_020ef778[];
extern const char data_020ef77d[];
extern const char data_020ef782[];

static inline DebugMenuItem* GetItem(DebugMenu* menu, int index) {
    return GetNodeAtIndex((IndexList_0202a9ac*)menu, index);
}

// USA: func_02029988
extern "C" ARM void func_02029988(DebugMenu* menu, int ticks) {
    int barH;
    float scale;
    int barX;
    DebugMenu* cur;
    int barY;

    func_02029634(menu, ticks);
    if (menu->flags & 8) return;
    barH = 0;
    barX = 0;
    barY = 0;

    if (menu->state == 0) {
        cur = (DebugMenu*)GetItem(menu, menu->selected);
        int row;
        int len;
        DebugMenuItem* item;
        int first = menu->first;
        int span = menu->last - first;
        int extra = menu->visibleCount - (menu->count - (menu->last - first));
        scale = (float)menu->height / (float)span;
        barH = scale * extra;
        barX = menu->x + menu->width - 9;
        barY = menu->y + scale * (menu->visibleFirst - first);

        if (menu->touchEnabled) {
            if (data_02114e54.pressed) {
                int tx, ty;
                menu->touching = 1;
                SelectCoordsByFlag0x24_02012a84((unsigned char*)&data_02114e54, &tx, &ty);
                if (menu->x < tx && tx < menu->x + menu->width - 12 &&
                    menu->y < ty && ty < menu->y + menu->height) {
                    menu->touchList = 1;
                } else if (menu->x + menu->width - 12 < tx && tx < menu->x + menu->width + 4 &&
                           menu->y < ty && ty < menu->y + menu->height) {
                    menu->touchBar = 1;
                }
            } else if (menu->touching && menu->touchList && data_02114e54.down && data_02114e54.held) {
                int tx, ty;
                SelectCoordsByFlag0x24_02012a84((unsigned char*)&data_02114e54, &tx, &ty);
                if (menu->x < tx && tx < menu->x + menu->width - 12 &&
                    menu->y < ty && ty < menu->y + menu->height) {
                    int row = (ty - menu->y) / data_020ef74c.rowHeight - 1;
                    if (first <= row && row <= first + extra) {
                        int sel = menu->visibleFirst + (row - first);
                        if (menu->first <= sel && sel <= menu->last) {
                            menu->selected = sel;
                        }
                    }
                }
            } else if (menu->touching && menu->touchBar && data_02114e54.down && data_02114e54.held) {
                int tx, ty;
                SelectCoordsByFlag0x24_02012a84((unsigned char*)&data_02114e54, &tx, &ty);
                barY = ty - barH / 2;
                if (barY < menu->y) {
                    barY = menu->y;
                } else if (menu->y + menu->width < barY + barH) {
                    barY = menu->y + menu->height - barH;
                }
                menu->visibleFirst = first + (barY - menu->y) / scale;
                menu->visibleLast = menu->visibleFirst + extra;
                if (menu->selected < menu->visibleFirst) menu->selected = menu->visibleFirst;
                if (menu->visibleLast < menu->selected) menu->selected = menu->visibleLast;
            } else if (menu->touching && data_02114e54.released) {
                int tx = data_02114e54.x;
                int ty = data_02114e54.y;
                if (menu->touchList &&
                    menu->x < tx && tx < menu->x + menu->width - 12 &&
                    menu->y < ty && ty < menu->y + menu->height) {
                    int row = (ty - menu->y) / data_020ef74c.rowHeight - 1;
                    if (first <= row && row <= first + extra) {
                        int sel = menu->visibleFirst + (row - first);
                        if (menu->first <= sel && sel <= menu->last) {
                            menu->selected = sel;
                            if (menu->selected < 0 || cur->type != 1) {
                                if (menu->flags & 2) return;
                                SetState0x6cAndInvoke((Callback_0202a91c*)menu);
                                menu->activated = 1;
                                return;
                            }
                            if (cur->type != 1) return;
                            Deactivate0202a8cc((char*)cur, 1);
                            menu->state = 4;
                            return;
                        }
                    }
                }
                menu->touching = 0;
                menu->touchList = 0;
                menu->touchBar = 0;
            }
        }

        if (menu->visibleLast < menu->selected) {
            menu->visibleFirst = menu->selected - extra;
            menu->visibleLast = menu->selected;
        } else if (menu->selected < menu->visibleFirst) {
            menu->visibleFirst = menu->selected;
            menu->visibleLast = menu->selected + extra;
        }

        if (data_020ef74c.font == 0) {
            FormatAndDispatch0202ad98(menu->x / 8 + 1, menu->y / 8 + 1, 7, menu->text);
        } else if (data_020ef74c.font >= 3 && data_020ef74c.font <= 6) {
            data_020fe9a4.highlight = 0;
            FormatAndDispatch020290e8(menu->x + data_020ef74c.columnWidth, menu->y + data_020ef74c.rowHeight, menu->text);
        }

        {
            char buf[0x80];
            item = GetItem(menu, 0);
            for (row = 0; row < first; row++) {
                if (item == NULL) break;
                sprintf(buf, data_020ef75c, item->text);
                data_020fe9a4.highlight = 0;
                if (item->disabled) data_020fe9a4.highlight = 1;
                if (data_020ef74c.font == 0) {
                    FormatAndDispatch0202ad98(menu->x / 8 + 1, menu->y / 8 + 2 + row, 7, buf);
                } else if (data_020ef74c.font >= 3 && data_020ef74c.font <= 6) {
                    int px = menu->x + data_020ef74c.columnWidth;
                    int py = data_020ef74c.rowHeight * (row + 2);
                    FormatAndDispatch020290e8(px, py + menu->y, buf);
                }
                item = item->next;
            }
        }

        {
            char buf[0x80];
            item = GetItem(menu, menu->last + 1);
            for (row = menu->last + 1; row < menu->count; row++) {
                if (item == NULL) break;
                sprintf(buf, data_020ef75c, item->text);
                data_020fe9a4.highlight = 0;
                if (item->disabled) data_020fe9a4.highlight = 1;
                if (data_020ef74c.font == 0) {
                    FormatAndDispatch0202ad98(menu->x / 8 + 1, menu->y / 8 + 2 + row, 7, buf);
                } else if (data_020ef74c.font >= 3 && data_020ef74c.font <= 6) {
                    int px = menu->x + data_020ef74c.columnWidth;
                    int py = data_020ef74c.rowHeight * (row + 2);
                    FormatAndDispatch020290e8(px, py + menu->y, buf);
                }
                item = item->next;
            }
        }

        {
            char line[0x80];
            char number[0x10];
            item = GetItem(menu, menu->visibleFirst);
            for (row = menu->visibleFirst; row <= menu->visibleLast; row++) {
                if (item == NULL) break;
                data_020fe9a4.highlight = 0;
                len = 0;
                if (item->disabled) data_020fe9a4.highlight = 1;
                if (menu->first <= row && row <= menu->last) {
                    if (menu->selected == row) {
                        sprintf(line, data_020ef75f);
                    } else {
                        sprintf(line, data_020ef763);
                    }
                    len += 3;
                }
                {
                    int suffix;
                    if (item->type == 2) {
                        if (menu->selected == row && item->disabled == 0 &&
                            TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x30)) {
                            item->value = item->value == 0;
                        }
                        if (item->value) {
                            sprintf(line + len, data_020ef767);
                        } else {
                            sprintf(line + len, data_020ef76b);
                        }
                        len += 3;
                    }
                    __clear(number, sizeof(number));
                    suffix = 0;
                    if (item->type == 3) {
                        item->flags &= ~2;
                        item->flags &= ~0xc;
                        if (menu->selected == row && item->disabled == 0) {
                            int adjusted = 0;
                            int savedFirst;
                            int savedLast;
                            int old = item->value;
                            int step = 1;
                            if (TestFlagMask_02012430(&data_02114e30, 8)) step = 100;
                            if (func_0201248c(&data_02114e30, 0x10)) {
                                AdjustValueWrapOrClamp((WrapField_0202a678*)item, step);
                                adjusted = 1;
                            }
                            if (func_0201248c(&data_02114e30, 0x20)) {
                                AdjustValueWrapOrClamp((WrapField_0202a678*)item, -step);
                                adjusted = 1;
                            }
                            if (func_0201248c(&data_02114e30, 0x100)) {
                                AdjustValueWrapOrClamp((WrapField_0202a678*)item, step * 10);
                                adjusted = 1;
                            }
                            if (func_0201248c(&data_02114e30, 0x200)) {
                                AdjustValueWrapOrClamp((WrapField_0202a678*)item, step * -10);
                                adjusted = 1;
                            }
                            if (adjusted) {
                                savedFirst = menu->visibleFirst;
                                savedLast = menu->visibleLast;
                                func_0202a6c4(menu);
                                menu->visibleFirst = savedFirst;
                                menu->visibleLast = savedLast;
                                item->flags |= 2;
                                if (old < item->value) item->flags |= 4;
                                if (old > item->value) item->flags |= 8;
                            }
                        }
                        if (!(item->flags & 0x40)) {
                            if (item->flags & 0x20) {
                                if (item->flags & 1) {
                                    sprintf(number, data_020ef76f, item->value);
                                } else if (item->flags & 0x80) {
                                    sprintf(number, data_020ef772, item->value + 0x40);
                                } else {
                                    sprintf(number, data_020ef775, item->value);
                                }
                            } else {
                                if (item->flags & 1) {
                                    sprintf(number, data_020ef778, item->value);
                                } else if (item->flags & 0x80) {
                                    sprintf(number, data_020ef77d, item->value + 0x40);
                                } else {
                                    sprintf(number, data_020ef782, item->value);
                                }
                            }
                            suffix = 1;
                            if (item->flags & 0x10) suffix = 2;
                        }
                    }
                    if (suffix == 1) {
                        sprintf(line + len, data_020ef75c, number);
                        len += strlen(number);
                    }
                    sprintf(line + len, data_020ef75c, item->text);
                    len += strlen(item->text);
                    if (suffix == 2) {
                        sprintf(line + len, data_020ef75c, number);
                        len += strlen(number);
                    }
                    if (data_020ef74c.font == 0) {
                        FormatAndDispatch0202ad98(menu->x / 8 + 1, menu->y / 8 + 2 + (first + (row - menu->visibleFirst)), 7, line);
                    } else if (data_020ef74c.font >= 3 && data_020ef74c.font <= 6) {
                        int px = menu->x + data_020ef74c.columnWidth;
                        int py = data_020ef74c.rowHeight * (first + (row - menu->visibleFirst) + 2);
                        FormatAndDispatch020290e8(px, py + menu->y, line);
                    }
                }
                item = item->next;
            }
        }
    }

    if (menu->state == 4) {
        cur = (DebugMenu*)GetItem(menu, menu->selected);
        if (cur != NULL && cur->type == 1) {
            func_02029988(cur, ticks);
            if (cur->state == 1 ? 1 : 0) {
                Deactivate0202a8cc((char*)menu, 0);
            }
        }
    }

    switch (menu->state) {
    case 0:
        if (SetupViewport02029384(menu->x, menu->y, menu->width, menu->height)) {
            if (menu->visibleLast - menu->visibleFirst + 1 < menu->count) {
                PackRegister02029470(0, 1, 3, 0, 0, 0);
                func_020292ec(menu->x + menu->width - 9, menu->y + 1, 8, menu->height - 2, 0x7fff);
                PackRegister02029470(0, 1, 3, 0, 0x1f, 0);
                if (barH < 0 || barH >= 0x100) {
                    barY = menu->y + 1;
                    barH = menu->height - 2;
                }
                func_020292ec(barX, barY, 8, barH, 0x7fff);
            }
        }
        break;
    case 1:
        break;
    case 2:
        menu->shownHeight = menu->height;
        menu->state = 0;
        SetupViewport02029384(menu->x, menu->y, menu->width, menu->shownHeight);
        break;
    case 3:
        menu->shownHeight = 0;
        menu->state = 1;
        SetupViewport02029384(menu->x, menu->y, menu->width, menu->shownHeight);
        break;
    }
}
