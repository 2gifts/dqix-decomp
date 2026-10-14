#include <globaldefs.h>
#include "GameState/GameState.h"

int GetFieldIfFlag2_020100cc(char* obj);
struct Struct020A2CF0;
void ResetState020a2cf0(struct Struct020A2CF0* obj);
struct S020a3568;
void SetField0x218(struct S020a3568* p, int v);
void ReadFields0x70To0x78_0202e7d4(unsigned char* obj, int* a, int* b, int* c);
extern "C" void func_0202e5d8(void* obj, int a, int b, int c);

// USA: func_ov015_02192544  (semantic: ResetAndReadCombatFields_02192544)
extern "C" ARM void func_ov015_02192544(void) {
    GameState* battle = GameState::GetInstance();
    if (battle == 0) {
        return;
    }
    int obj = GetFieldIfFlag2_020100cc((char*)battle);
    if (obj == 0) {
        return;
    }
    ResetState020a2cf0((struct Struct020A2CF0*)obj);
    SetField0x218((struct S020a3568*)obj, 2);
    int a, b, c;
    ReadFields0x70To0x78_0202e7d4((unsigned char*)obj, &a, &b, &c);
    func_0202e5d8((void*)obj, a, 0x13d7, c);
}
