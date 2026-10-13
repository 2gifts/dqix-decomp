#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct State02243518 {
    SafeAllocator primary;
    SafeAllocator secondary;
    SafeAllocator* external;
    unsigned char field_2c;
    char pad2d[3];
    int field_30;
    unsigned char field_34, field_35, field_36, field_37;
    int field_38, field_3c, field_40;
    unsigned char field_44;
    char pad45[3];
    int field_48;
    void* buffer;
    char data_50[0x2c0];
    char pad310[0x64];
    unsigned char mode;
    char pad375[7];
    int field_37c, field_380, field_384, field_388, field_38c;
    unsigned char field_390, field_391;
    char pad392[2];
    int field_394;
    unsigned char field_398, field_399, field_39a, field_39b;
    int field_39c, field_3a0;
    int fields_3a4[11];
    unsigned char field_3d0;
    char pad3d1[3];
    char data_3d4[0x58];
    int field_42c, field_430, field_434;
    unsigned char field_438, field_439;
    char pad43a[2];
    char data_43c[0x600];
};
extern SafeAllocator data_ov031_02291e3c;
extern "C" void VectorizedMemset(void*, int, unsigned int);

// USA: func_ov031_02243518
extern "C" ARM int func_ov031_02243518(State02243518* state, int flags) {
    GameState::GetInstance();
    state->field_2c = 0;
    state->field_34 = 1;
    state->field_35 = 0;
    state->field_37 = 0;
    state->field_36 = 0;
    state->mode = flags;
    unsigned char mode = state->mode;
    if (mode & 2) {
        state->mode = 2;
        state->field_2c = 0;
    } else if (mode & 0x20) {
        state->mode = 0x20;
        state->field_2c = 0;
        state->field_34 = 7;
    } else if (mode & 1) {
        state->field_2c = 0;
    } else if (mode & 4) {
        state->field_2c = 0;
    }
    state->field_44 = 0;
    state->field_38 = 0;
    state->field_3c = 0;
    state->field_40 = 0;
    state->field_48 = 0;
    state->buffer = 0;
    VectorizedMemset(state->data_50, 0, 0x2c0);
    data_ov031_02291e3c.ResetAllocatorPointer();
    state->primary.ResetAllocatorPointer();
    state->secondary.ResetAllocatorPointer();
    state->external = 0;
    state->field_37c = 0;
    state->field_380 = 0;
    state->field_384 = 0;
    state->field_388 = 0;
    state->field_38c = 0;
    state->field_390 = 0;
    state->field_391 = 0;
    state->field_394 = 0;
    state->field_398 = 0;
    state->field_399 = 0;
    state->field_39a = 0;
    state->field_39b = 0;
    state->field_30 = 0;
    state->field_39c = -1;
    state->field_3a0 = -1;
    state->fields_3a4[0] = 0;
    state->fields_3a4[1] = 0;
    state->fields_3a4[2] = 0;
    state->fields_3a4[3] = 0;
    state->fields_3a4[4] = 0;
    state->fields_3a4[5] = 0;
    state->fields_3a4[6] = 0;
    state->fields_3a4[7] = 0;
    state->fields_3a4[8] = 0;
    state->fields_3a4[9] = 0;
    state->fields_3a4[10] = 0;
    state->field_3d0 = 0;
    VectorizedMemset(state->data_3d4, 0, 0x58);
    state->field_42c = -1;
    state->field_430 = 0;
    state->field_434 = 0;
    state->field_438 = 0;
    state->field_439 = 0;
    memset(state->data_43c, 0, 0x600);
    return 1;
}
