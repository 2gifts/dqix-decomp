#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

int GetWord0x0(int* obj);
extern "C" int func_ov000_0215eb1c(struct Random* rand, short* buf, int count, int flag);
int GetSubstructByte0x1c(unsigned char* obj);
void SetSubstructByte0x1c(unsigned char* obj, unsigned char value);
void SetSubstructFields0x10And0x18ClearFlag0x1(unsigned char* obj, int* src);
void SetSubstructField0x14ClearFlag0x1(unsigned char* obj, int* src);
extern "C" void __clear(void* dst, int count);

struct Vec2_0216f74c { int x; int y; };
extern "C" struct Vec2_0216f74c func_ov000_0216f74c(int* in);

extern unsigned char data_ov000_02183118[][8];
struct Words3_02167cd4 { unsigned int v[3]; };
extern struct Words3_02167cd4 data_ov000_021830cc;

// USA: func_ov000_02167cd4  (semantic: AssignFormationPositions_02167cd4)
extern "C" ARM void func_ov000_02167cd4(unsigned char* obj) {
    GameState* battle = GameState::GetInstance();
    GetWord0x0((int*)battle);
#if defined(jpn)
    struct Random* rand = *(struct Random**)(obj + 0x218);
#else
    struct Random* rand = *(struct Random**)(obj + 0x29c);
#endif
    short ids[8];
    int count = func_ov000_0215eb1c(rand, ids, 8, 0);
    int i = 0;
    while (i < count) {
        GameObject* c = battle->GetCombatantByIndex(ids[i]);
        if (c != 0) {
            int tmp = data_ov000_02183118[count - 1][i];
            if (GetSubstructByte0x1c((unsigned char*)c) != 0xff) {
                tmp = GetSubstructByte0x1c((unsigned char*)c);
            }
            struct Vec2_0216f74c pos = func_ov000_0216f74c(&tmp);
            struct Words3_02167cd4 fields = data_ov000_021830cc;
            fields.v[0] = pos.x;
            fields.v[2] = pos.y;
            int zeroBuf[3];
            __clear(zeroBuf, 0xc);
            SetSubstructByte0x1c((unsigned char*)c, (unsigned char)(tmp & 0xff));
            SetSubstructFields0x10And0x18ClearFlag0x1((unsigned char*)c, (int*)&fields);
            SetSubstructField0x14ClearFlag0x1((unsigned char*)c, zeroBuf);
        }
        i++;
    }
}
