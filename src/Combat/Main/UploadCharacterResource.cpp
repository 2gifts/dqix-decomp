#include <globaldefs.h>

#include "System/Cache.h"
#include "System/Graphics.h"
#include "System/LoadToVRAM.h"

extern "C" void _Z26SetIntArrayElement020b0334Piii(int *array, int index, int value);

struct CharacterResourceData020b0594 {
    unsigned short height;
    unsigned short width;
    int format;
    unsigned int mappingMode;
    unsigned int unknownc;
    unsigned int dataSize;
    void *data;
};

struct CharacterUploadState020b0594 {
    int offsets[3];
    int widthCode;
    int heightCode;
    int format;
    int unknown18;
    int enabled;
    unsigned int mappingMode;
};

// USA: func_020b0594
extern "C" ARM void func_020b0594(int resource, int offset, int tier, void *object) {
    CharacterResourceData020b0594 *character = (CharacterResourceData020b0594 *) resource;
    CharacterUploadState020b0594 *state      = (CharacterUploadState020b0594 *) object;
    unsigned int mappingMode                 = character->mappingMode;

    if (tier != 0) {
        switch (tier) {
            case 1: DISPCNT = (DISPCNT & 0xffcfffef) | mappingMode; break;
            case 2: DISPCNTSUB = (DISPCNTSUB & 0xffcfffef) | mappingMode; break;
        }
    }

    CleanInvalidateCacheRange(character->data, character->dataSize);
    switch (tier) {
        case 0:
            MemoryMapTextureImage();
            LoadToTextureImage(character->data, offset, character->dataSize);
            MemoryUnmapTextureImage();
            break;
        case 1: LoadToMainObjVRAM(character->data, offset, character->dataSize); break;
        case 2: LoadToSubObjVRAM(character->data, offset, character->dataSize); break;
    }

    if (character->mappingMode == 0) {
        int widthCode;
        switch (character->width) {
            case 1: widthCode = 0; break;
            case 2: widthCode = 1; break;
            case 4: widthCode = 2; break;
            case 8: widthCode = 3; break;
            case 16: widthCode = 4; break;
            case 32: widthCode = 5; break;
            default: widthCode = 0; break;
        }
        state->widthCode = widthCode;

        int heightCode;
        switch (character->height) {
            case 1: heightCode = 0; break;
            case 2: heightCode = 1; break;
            case 4: heightCode = 2; break;
            case 8: heightCode = 3; break;
            case 16: heightCode = 4; break;
            case 32: heightCode = 5; break;
            default: heightCode = 0; break;
        }
        state->heightCode = heightCode;
    } else {
        state->widthCode  = character->width;
        state->heightCode = character->height;
    }

    state->format      = character->format;
    state->unknown18   = 0;
    state->enabled     = 1;
    state->mappingMode = character->mappingMode;
    _Z26SetIntArrayElement020b0334Piii(state->offsets, tier, offset);
}
