#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205c570;
struct Struct_0205def8;
struct Obj0205eaa0;

int GetActiveScaledSum0205d794(struct Struct_0205c570* s);
void SetElementFlag0x20ByKey0205def8(struct Struct_0205def8* s, int clear, int key);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
struct Obj_0205da38;
int IsActiveElementFlag2Set0205da38(struct Obj_0205da38* obj, int key);
int IsBitFlagSet0217c4e8(void* obj, int bit);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern "C" void func_ov000_021716d0(void* obj);
void* GetFieldAt0x150(unsigned char* obj);
int CheckFlagsOrField_0217ab48_0217ab48(void* obj);
extern "C" void func_ov000_0217629c(void* obj);
extern "C" void func_ov000_0217ab8c(void* obj, int a, int b);
extern "C" void func_ov000_02176e3c(void* ctx, void* obj, int sel, int a, int b, int c);

struct MenuCtx_0217b6d0 {
    char pad0[0x188];
#if defined(jpn)
    char list[0x1faa - 0x188];
#else
    char list[0x1d72 - 0x188];
#endif
    unsigned short flags;
};

struct MenuGlobals_0217b6d0 {
#if defined(jpn)
    MenuCtx_0217b6d0* ctx;
    int field0;
    int field4;
    MenuCtx_0217b6d0* const& GetWindow() const {
        return ctx;
    }
#else
    int field0;
    int field4;
    MenuCtx_0217b6d0* ctx;
#endif
    short cur;
};

struct MemberInfo_0217b6d0 {
#if defined(jpn)
    char pad0[0x8ca];
#else
    char pad0[0x962];
#endif
    unsigned short lastSpell;
};

struct Window_0217b6d0 {
    char pad0[0xb8];
    unsigned char state;
};

struct MenuObj_0217b6d0 {
    char pad0[0x10];
    signed char selections[8];
    signed char depth;
    char pad19[0x1e - 0x19];
    short selected;
    char pad20[0x26 - 0x20];
    unsigned short actionId;
    char pad28[0x38 - 0x28];
    Window_0217b6d0* window;
    char pad3c[0x4c - 0x3c];
    int memberIndex;
#if defined(jpn)
    char pad50[0x484 - 0x50];
#else
    char pad50[0x444 - 0x50];
#endif
    unsigned char field444;
#if defined(jpn)
    const short& GetSelection() const {
        return selected;
    }
#endif
};

extern MenuGlobals_0217b6d0 data_ov000_02184294;
extern unsigned short data_02114e30;
extern char data_02108760;

#if defined(jpn)
// USA: func_ov000_0217b6d0
extern "C" ARM int func_ov000_0217b6d0(MenuObj_0217b6d0* obj, int arg1, int arg2) {
    MenuCtx_0217b6d0* ctx;
    enum Selection { kSelectionMin = -32768, kSelectionMax = 32767 };
    Selection cur;
    data_ov000_02184294.ctx->flags |= 0x100;
    const short prev = obj->GetSelection();
    cur = (Selection)(short)GetActiveScaledSum0205d794((struct Struct_0205c570*)obj->window);
    obj->selected = cur;
    {
    ctx = data_ov000_02184294.GetWindow();
    SetElementFlag0x20ByKey0205def8((struct Struct_0205def8*)ctx->list, 1, 0x23);
    if (prev != cur) {
        return -1;
    }
    int t = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601);
    bool active = (t | IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)obj->window, 0x14)) != 0;
    if (active || obj->field444 != 0) {
        if (!IsBitFlagSet0217c4e8(obj, cur)) {
            return obj->selections[obj->depth];
        }
        SetElementFlag0x20ByKey0205def8((struct Struct_0205def8*)ctx->list, 0, 0x23);
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
        func_ov000_021716d0(obj);
        GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(obj->memberIndex);
        if (member != NULL) {
            MemberInfo_0217b6d0* info = (MemberInfo_0217b6d0*)GetFieldAt0x150((unsigned char*)member);
            if (info != NULL) {
                info->lastSpell = obj->actionId;
            }
        }
        if (obj->selections[obj->depth] != 0x64) {
            obj->window->state = 0x10;
        }
        return obj->selections[obj->depth];
    }
    if (CheckFlagsOrField_0217ab48_0217ab48(obj)) {
        func_ov000_0217629c(obj);
        obj->selections[obj->depth] = 0;
        obj->depth--;
        obj->selected = -1;
        obj->actionId = 0;
        func_ov000_0217ab8c(obj, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.ctx, obj, obj->selections[obj->depth], data_ov000_02184294.field4, data_ov000_02184294.field0, 0);
    }
    return -1;
    }
}
#else
// USA: func_ov000_0217b6d0
extern "C" ARM int func_ov000_0217b6d0(MenuObj_0217b6d0* obj, int arg1, int arg2) {
    MenuCtx_0217b6d0* ctx;
    short cur;
    data_ov000_02184294.ctx->flags |= 0x100;
    short prev = obj->selected;
    cur = GetActiveScaledSum0205d794((struct Struct_0205c570*)obj->window);
    obj->selected = cur;
    ctx = data_ov000_02184294.ctx;
    SetElementFlag0x20ByKey0205def8((struct Struct_0205def8*)ctx->list, 1, 0x23);
    if (prev != cur) {
        return -1;
    }
    int t = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x601);
    int active = (t | IsActiveElementFlag2Set0205da38((struct Obj_0205da38*)obj->window, 0x14)) != 0;
    if (active || obj->field444 != 0) {
        if (!IsBitFlagSet0217c4e8(obj, cur)) {
            return obj->selections[obj->depth];
        }
        SetElementFlag0x20ByKey0205def8((struct Struct_0205def8*)ctx->list, 0, 0x23);
        DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 1, 0);
        func_ov000_021716d0(obj);
        GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(obj->memberIndex);
        if (member != NULL) {
            MemberInfo_0217b6d0* info = (MemberInfo_0217b6d0*)GetFieldAt0x150((unsigned char*)member);
            if (info != NULL) {
                info->lastSpell = obj->actionId;
            }
        }
        if (obj->selections[obj->depth] != 0x64) {
            obj->window->state = 0x10;
        }
        return obj->selections[obj->depth];
    }
    if (CheckFlagsOrField_0217ab48_0217ab48(obj)) {
        func_ov000_0217629c(obj);
        obj->selections[obj->depth] = 0;
        obj->depth--;
        obj->selected = -1;
        obj->actionId = 0;
        func_ov000_0217ab8c(obj, arg1, arg2);
        func_ov000_02176e3c(data_ov000_02184294.ctx, obj, obj->selections[obj->depth], data_ov000_02184294.field4, data_ov000_02184294.field0, 0);
    }
    return -1;
}
#endif
