#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#include <GameState/GameState.h>

struct AlchemyRecipeQuantityView {
    short unknown00[2];
    short firstIngredient;
    short secondIngredient;
    short thirdIngredient;
    unsigned short firstQuantity : 4;
    unsigned short secondQuantity : 4;
    unsigned short thirdQuantity : 4;
    unsigned short unknownQuantity : 4;
};
struct AlchemyConsumptionStateView { char unknown00[0x18]; short item; };
struct AlchemyConsumptionContext { SafeAllocator allocator; char operation[0x24]; };
extern "C" {
void* _Z17GetPtrField0x2a04P9GameState(GameState*);
void _Z22ZeroInitReturn020de824Pv(void*);
void _Z18InitStruct0207cbe8Pc(void*);
void func_0207d300(void*, short, signed char, int);
void _Z18InitStruct0207cc0cPc(void*);
void _Z30DecrementKeyEverywhere02086d88Phi(void*, short);
}
extern "C" ARM void func_ov006_0215759c(AlchemyConsumptionStateView* state, AlchemyRecipeQuantityView* recipe, unsigned int count)
{
    GameState* game = GameState::GetInstance();
    void* inventory = _Z17GetPtrField0x2a04P9GameState(game);
    AlchemyConsumptionContext context;
    context.allocator.ResetAllocatorPointer();
    _Z22ZeroInitReturn020de824Pv(context.operation);
    _Z18InitStruct0207cbe8Pc(&context);
    _Z18InitStruct0207cbe8Pc(&context);
    func_0207d300(&context, state->item, (signed char)count, 0);
    _Z18InitStruct0207cc0cPc(&context);
    for (unsigned char iteration = 0; iteration < count; iteration++) {
        for (unsigned char ingredient = 0; ingredient < recipe->firstQuantity; ingredient++) _Z30DecrementKeyEverywhere02086d88Phi(inventory, recipe->firstIngredient);
        for (unsigned char ingredient = 0; ingredient < recipe->secondQuantity; ingredient++) _Z30DecrementKeyEverywhere02086d88Phi(inventory, recipe->secondIngredient);
        for (unsigned char ingredient = 0; ingredient < recipe->thirdQuantity; ingredient++) _Z30DecrementKeyEverywhere02086d88Phi(inventory, recipe->thirdIngredient);
    }
}
