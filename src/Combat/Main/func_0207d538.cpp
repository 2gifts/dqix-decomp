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

#if defined(jpn)
extern "C" void func_020de968(int, char*);
extern char data_020f1050;
extern char data_020f106e;
extern char data_020f1094;
#endif

// USA: func_0207d538
#if defined(jpn)
extern "C" ARM int func_0207d538(void* owner, int type, int value, char* output, unsigned char formatAmount) {
#else
extern "C" ARM int func_0207d538(void* owner, int type, int value, char* output) {
#endif
    if (type == 2) {
#if defined(jpn)
        int amount = (short)value;
#else
        short amount = value;
#endif
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
#if defined(jpn)
            if (formatAmount) {
                char amountText[0x30] = {};
                func_020de968(amount, amountText);
                sprintf(output, &data_020f1050, amountText);
            } else {
                sprintf(output, &data_020f1050, *(char**)((char*)owner + 0x30));
            }
#else
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
#endif
            break;
        }
        }
        if (result == -2) return 0;
        return 1;
    } else if (type == 1) {
        func_0207d2c4(owner, value);
#if defined(jpn)
        sprintf(output, &data_020f106e, value);
#else
        StoreStruct* formatter = GetGlobalField0x1c020421a0();
        func_02046380(formatter);
        StoreInArray0x8b0(formatter, 0, value);
        char* message = CallFunc020e0434With02153694(0x3f4);
        func_02046608(formatter, 12, message, output, 0xe3, 0, 1);
#endif
        return 1;
    } else {
#if defined(jpn)
        sprintf(output, &data_020f1094);
#else
        sprintf(output, CallFunc020e0434With02153694(0x2d));
#endif
        return 0;
    }
}
