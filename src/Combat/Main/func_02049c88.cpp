#include <globaldefs.h>
#include "Graphics/AlphaTween.h"
#include "GameState/GameState.h"
#include "std_library_functions.h"
struct Vector02049c88 { int x; int y; int z; };
struct StructFields02049550 { unsigned char field0; unsigned char field1; unsigned short field2; unsigned short field4; unsigned char field6; };
struct State02049c88 {
    int field0;
    Vector02049c88 position;
    Vector02049c88 direction;
    unsigned char indexes[4];
    int flags;
    char unknown24[0x1c];
    Vector02049c88 vector40;
    unsigned char byte4c;
    unsigned char byte4d;
    StructFields02049550 fields;
    unsigned char byte56;
    char unknown57;
    char bytes58[6];
    char unknown5e[2];
    AlphaTween alpha;
    int field68;
    unsigned char byte6c;
    char unknown6d[3];
};
struct Object02049c88 { GameObject base; State02049c88* state; };
extern "C" void _Z25ClearStructFields02049550P20StructFields02049550(StructFields02049550*);

// USA: func_02049c88
extern "C" ARM void func_02049c88(Object02049c88* object, State02049c88* state) {
    object->state = state;
    if (!object->state) return;
    memset(object->state, 0, 0x70);
    object->state->field0 = 0;
    Vector02049c88* position = &object->state->position;
    position->x = 0;
    position->y = 0;
    position->z = 0;
    Vector02049c88* direction = &object->state->direction;
    direction->x = 0;
    direction->y = 0;
    direction->z = 0;
    Vector02049c88* vector = &object->state->vector40;
    vector->x = 0;
    vector->y = 0;
    vector->z = 0;
    object->state->flags = 0;
    object->state->byte4c = 0;
    object->state->indexes[0] = 0xff;
    object->state->indexes[1] = 0xff;
    object->state->indexes[2] = 0xff;
    object->state->indexes[3] = 0xff;
    object->state->byte56 = 1;
    _Z25ClearStructFields02049550P20StructFields02049550(&object->state->fields);
    object->state->alpha.Reset();
    memset(object->state->bytes58, 0, 6);
    object->state->field68 = 0;
    object->state->byte6c = 0xff;
}
