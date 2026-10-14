#if defined(jpn)
#define func_02045f3c func_02046c78
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

#if defined(jpn)
#define func_ov005_0215b0a0 func_ov005_0215c4b4
#endif
#include <GameState/GameState.h>

struct Container020dedd0;
struct Field150Holder02052e14;
struct CombatObject { char pad[LOW_REGION(0x4f8, 0x4fc)]; int index; };
struct NameSprite {
#if defined(jpn)
    unsigned short data[10];
#else
    char data[0x80];
#endif
};
struct CombatDisplay { char pad0[0xdf4]; Container020dedd0* container; char pad1[LOW_REGION(0x2f38, 0x2fc0)]; unsigned char state; char pad2[3]; unsigned char selected; char pad3[0xc7]; NameSprite names[8]; unsigned char raised[8]; };
void* GetGlobalField0x1c020421a0();
short* GetField150Ptr0x488(Field150Holder02052e14*);
void* FindElementByKey020dedd0(Container020dedd0*, int);
CombatObject* GetField1c_021a193c(int*);
#if defined(jpn)
extern "C" void func_02045f3c(void*, unsigned short*, int, int, int, int, int, int);
#else
extern "C" void func_02045f3c(void*, NameSprite*, int, int, int, int, int, int, int, int);
#endif
extern unsigned char data_ov005_0215cbfc[];
#define REG_GEOMETRY ((volatile unsigned int*)0x04000444)
#define REG_END (*(volatile unsigned int*)0x04000504)

// USA: func_ov005_0215b0a0
extern "C" ARM void func_ov005_0215b0a0(CombatDisplay* display) {
    void* renderer = GetGlobalField0x1c020421a0();
    GameState* game = GameState::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100(game, GetField1c_021a193c((int*)func_ov017_0218b5b0()->unknown_ptr_array_36fc[3])->index);
    if (!combatant) return;
    short* effects = GetField150Ptr0x488((Field150Holder02052e14*)combatant);
    int y = LOW_REGION(29, 28);
#if defined(jpn)
    int color;
#endif
    if (display->state == 0) {
        for (int i = 0; i < 8; i++) {
#if defined(jpn)
            if (FindElementByKey020dedd0(display->container, effects[data_ov005_0215cbfc[i]])) color = 0x7fff;
            else color = 0x3def;
#else
            int color = FindElementByKey020dedd0(display->container, effects[data_ov005_0215cbfc[i]]) ? 0x7fff : 0x3def;
#endif
            if (i == display->selected) color = 0xf0a;
            int row = i * 24;
#if !defined(jpn)
            if (display->raised[i]) row -= 5;
#endif
            REG_GEOMETRY[0] = 0;
            REG_GEOMETRY[0x2f] = 1;
            REG_GEOMETRY[11] = 0;
            REG_GEOMETRY[11] = 0;
            REG_GEOMETRY[11] = 0xffc01000;
#if defined(jpn)
            func_02045f3c(renderer, display->names[i].data, 160, row + 7, color, 10, 0, 0);
#else
            func_02045f3c(renderer, &display->names[i], 160, row + 6, color, 10, 0, 0, 0, 9);
#endif
            REG_GEOMETRY[0x30] = 0;
            REG_GEOMETRY[1] = 1;
        }
    } else {
#if defined(jpn)
        if (FindElementByKey020dedd0(display->container, effects[data_ov005_0215cbfc[display->selected]])) color = 0x7fff;
        else color = 0x3def;
#else
        int color = FindElementByKey020dedd0(display->container, effects[data_ov005_0215cbfc[display->selected]]) ? 0x7fff : 0x3def;
#endif
        if (display->state == 3) color = 0xf0a;
#if !defined(jpn)
        if (display->raised[display->selected]) y -= 5;
#endif
        REG_GEOMETRY[0] = 0;
        REG_GEOMETRY[0x2f] = 1;
        REG_GEOMETRY[11] = 0;
        REG_GEOMETRY[11] = 0;
        REG_GEOMETRY[11] = 0xffc01000;
#if defined(jpn)
        func_02045f3c(renderer, display->names[display->selected].data, 160, y, color, 10, 0, 0);
#else
        func_02045f3c(renderer, &display->names[display->selected], 160, y, color, 10, 0, 0, 0, 9);
#endif
        REG_END = 0;
        REG_GEOMETRY[1] = 1;
    }
}
