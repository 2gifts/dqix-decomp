#include <globaldefs.h>
#include "GameState/GameState.h"

struct ScaleEntry_021f8bd8 {
    int field_0x0;
    unsigned int field_0x4_lo : 12;
    unsigned int statMin : 10;
    unsigned int statMax : 10;
    char pad_8[8];
    unsigned int flags;
    unsigned int field_0x14_lo : 7;
    unsigned int valueMin : 7;
    unsigned int valueMax : 7;
    unsigned int field_0x14_hi : 11;
    unsigned int field_0x18_lo : 16;
    unsigned int kind : 2;
    unsigned int field_0x18_hi : 14;
};

// USA: func_ov024_021f8bd8
extern "C" ARM void func_ov024_021f8bd8(void* unused, float* out, GameObject* obj, ScaleEntry_021f8bd8* entry) {
    unsigned short might = obj->currentStats_->primaryStats.magicalMight;
    unsigned short mending = obj->currentStats_->primaryStats.magicalMending;
    float result = 100.0f;
    if (entry->kind == 1) {
        if (entry->flags & 0x4000) {
            if (might <= entry->statMin) {
                result = entry->valueMin;
            } else if (might >= entry->statMax) {
                result = entry->valueMax;
            } else {
                result = (unsigned int)(int)((float)(might - entry->statMin) * ((float)(entry->valueMax - entry->valueMin) / (float)(entry->statMax - entry->statMin))) + entry->valueMin;
            }
        } else if (entry->flags & 0x8000) {
            if (mending <= entry->statMin) {
                result = entry->valueMin;
            } else if (mending >= entry->statMax) {
                result = entry->valueMax;
            } else {
                result = (unsigned int)(int)((float)(mending - entry->statMin) * ((float)(entry->valueMax - entry->valueMin) / (float)(entry->statMax - entry->statMin))) + entry->valueMin;
            }
        }
    }
    *out = result;
}
