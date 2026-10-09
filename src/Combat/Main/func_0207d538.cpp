#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct CombatantText { int data[3]; };
struct NumberText { char* first; char* second; int flags; };
struct StoreStruct {
    CombatantText* combatant;
    char pad4[0x18 - 4];
    NumberText* number;
};
extern "C" int func_0207d300(void*, int, int, int);
extern "C" void func_0207d2c4(void*, int);
extern "C" void func_02046380(StoreStruct*);
extern "C" void func_02046608(StoreStruct*, int, const char*, char*, int, int, int);
StoreStruct* GetGlobalField0x1c020421a0();
unsigned char GetField0x397cValue(GameState*);
void InitObjFromCombatantId020e4bf4(void*, int);
void* Clear12Bytes020e46c4(void*);
void DispatchIfCountPositive020dcf7c(int, void*);
char* CallFunc020e0434With02153694(int);
void StoreInArray0x8b0(StoreStruct*, int, int);

// USA: func_0207d538
extern "C" ARM int func_0207d538(void* owner, int type, int value, char* output) {
    if (type == 2) {
        short amount = value;
        int result = func_0207d300(owner, amount, 1, 0);
        switch (result) {
        case -1:
            return 0;
        case 0:
        case 1:
        case 2:
        case 3:
        case 5:
        {
            StoreStruct* formatter = GetGlobalField0x1c020421a0();
            func_02046380(formatter);
            CombatantText combatant;
            InitObjFromCombatantId020e4bf4(&combatant, GetField0x397cValue(GameState::GetInstance()));
            formatter->combatant = &combatant;
            char first[0x80] = {};
            char second[0x80] = {};
            NumberText number;
            Clear12Bytes020e46c4(&number);
            number.first = first;
            number.second = second;
            DispatchIfCountPositive020dcf7c(amount, &number);
            formatter->number = &number;
            char* message = CallFunc020e0434With02153694(0x54);
            func_02046608(formatter, 12, message, output, 0xe3, 0, 1);
            break;
        }
        }
        if (result == -2) return 0;
        return 1;
    } else if (type == 1) {
        func_0207d2c4(owner, value);
        StoreStruct* formatter = GetGlobalField0x1c020421a0();
        func_02046380(formatter);
        StoreInArray0x8b0(formatter, 0, value);
        char* message = CallFunc020e0434With02153694(0x3f4);
        func_02046608(formatter, 12, message, output, 0xe3, 0, 1);
        return 1;
    } else {
        sprintf(output, CallFunc020e0434With02153694(0x2d));
        return 0;
    }
}
