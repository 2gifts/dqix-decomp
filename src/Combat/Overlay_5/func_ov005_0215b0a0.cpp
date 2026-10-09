#include <globaldefs.h>
#include <GameState/GameState.h>

struct Container020dedd0;
struct Field150Holder02052e14;
struct CombatObject { char pad[0x4fc]; int index; };
struct NameSprite { char data[0x80]; };
struct CombatDisplay { char pad0[0xdf4]; Container020dedd0* container; char pad1[0x2fc0]; unsigned char state; char pad2[3]; unsigned char selected; char pad3[0xc7]; NameSprite names[8]; unsigned char raised[8]; };
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
short* GetField150Ptr0x488(Field150Holder02052e14*);
extern "C" void* _Z24FindElementByKey020dedd0P17Container020dedd0i(Container020dedd0*, int);
extern "C" CombatObject* _Z19GetField1c_021a193cPi(int*);
extern "C" void func_02045f3c(void*, NameSprite*, int, int, int, int, int, int, int, int);
extern unsigned char data_ov005_0215cbfc[];
#define REG_GEOMETRY ((volatile unsigned int*)0x04000444)
#define REG_END (*(volatile unsigned int*)0x04000504)

// USA: func_ov005_0215b0a0
extern "C" ARM void func_ov005_0215b0a0(CombatDisplay* display) {
    void* renderer = _Z26GetGlobalField0x1c020421a0v();
    GameState* game = GameState::GetInstance();
    GameObject* combatant = GetCombatantWithFlag0x100(game, _Z19GetField1c_021a193cPi((int*)func_ov017_0218b5b0()->unknown_ptr_array_36fc[3])->index);
    if (!combatant) return;
    short* effects = GetField150Ptr0x488((Field150Holder02052e14*)combatant);
    int y = 28;
    if (display->state == 0) {
        for (int i = 0; i < 8; i++) {
            int color = _Z24FindElementByKey020dedd0P17Container020dedd0i(display->container, effects[data_ov005_0215cbfc[i]]) ? 0x7fff : 0x3def;
            if (i == display->selected) color = 0xf0a;
            int row = i * 24;
            if (display->raised[i]) row -= 5;
            REG_GEOMETRY[0] = 0;
            REG_GEOMETRY[0x2f] = 1;
            REG_GEOMETRY[11] = 0;
            REG_GEOMETRY[11] = 0;
            REG_GEOMETRY[11] = 0xffc01000;
            func_02045f3c(renderer, &display->names[i], 160, row + 6, color, 10, 0, 0, 0, 9);
            REG_GEOMETRY[0x30] = 0;
            REG_GEOMETRY[1] = 1;
        }
    } else {
        int color = _Z24FindElementByKey020dedd0P17Container020dedd0i(display->container, effects[data_ov005_0215cbfc[display->selected]]) ? 0x7fff : 0x3def;
        if (display->state == 3) color = 0xf0a;
        if (display->raised[display->selected]) y -= 5;
        REG_GEOMETRY[0] = 0;
        REG_GEOMETRY[0x2f] = 1;
        REG_GEOMETRY[11] = 0;
        REG_GEOMETRY[11] = 0;
        REG_GEOMETRY[11] = 0xffc01000;
        func_02045f3c(renderer, &display->names[display->selected], 160, y, color, 10, 0, 0, 0, 9);
        REG_END = 0;
        REG_GEOMETRY[1] = 1;
    }
}
