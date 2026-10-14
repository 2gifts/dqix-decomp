#include <globaldefs.h>
#include "Graphics/VRAMStaging.h"
#include "Graphics/Model3D.h"
#include "World/Object3D.h"

#if defined(jpn)
#define data_ov023_021fd68a data_ov023_021fc952
#endif

struct Appearance021e540c {
    short models[10];
    unsigned char female : 1;
    unsigned char eyeColor : 3;
    unsigned char skinColor : 4;
    unsigned char hairColor : 4;
    unsigned char unused : 4;
};

struct Member021e540c {
    char pad[0x488];
    Appearance021e540c appearance;
};

struct VRAMState021e540c {
    char pad[0x68];
    unsigned int palette : 16;
    unsigned int unused : 16;
    unsigned int tail;
};

struct Container020dedd0;
struct Obj020de2a4;
struct Element020de650 { void* model; };

struct Character021e540c {
    Object3D parts[10];
    SafeAllocator allocators[10];
    SafeAllocator animationAllocator;
    VRAMState021e540c vramStates[10];
    short tasks[12];
    Container020dedd0* names;
    char pad_c10[5];
    unsigned char vocation;
    char pad_c16[2];
    Member021e540c* member;
};

struct PaletteTable021e540c {
    unsigned short hair[10][2];
    unsigned short eyes2[8][2];
    unsigned short eyes4[8][4];
    unsigned short eyes8[8][8];
    unsigned short skin[16][2];
};

unsigned short (*GetVariantShortTable02109928_02099cac())[2];
void CopyAndClampShorts_021e5fdc(void* unused, short* dst, short* src);
Element020de650* FindElementByKey020dedd0(Container020dedd0* names, int key);
int GetNibbleField020de2a4(Obj020de2a4* entry, int which, int female);
extern short data_ov023_021fd68a[];

// USA: func_ov023_021e540c
extern "C" ARM void func_ov023_021e540c(Character021e540c* self) {
    Appearance021e540c* appearance = &self->member->appearance;
    PaletteTable021e540c* colors = (PaletteTable021e540c*)GetVariantShortTable02109928_02099cac();
    unsigned int eye = appearance->eyeColor;
    unsigned int skin = appearance->skinColor;
    unsigned int paletteOffset = self->vramStates[2].palette << 3;
    StageMemoryToVRAM(VRAMSubregion_TexturePalette, colors->hair[appearance->hairColor], paletteOffset + 0x24, 4, false, true);
    StageMemoryToVRAM(VRAMSubregion_TexturePalette, colors->skin[skin], paletteOffset + 0x28, 4, false, true);
    StageMemoryToVRAM(VRAMSubregion_TexturePalette, colors->eyes8[eye], paletteOffset + 0x30, 0x10, false, true);

    short models[10];
    CopyAndClampShorts_021e5fdc((void*)self->vocation, models, appearance->models);
    int i = 0;
    int part;
    for (; (part = data_ov023_021fd68a[i]) >= 0; i++) {
        Container020dedd0* names = self->names;
        int modelID = models[part];
        int female = appearance->female;
        if (names != NULL) {
          VRAMState021e540c* state = &self->vramStates[part];
          if (state != NULL) {
            Element020de650* entry = FindElementByKey020dedd0(names, (short)modelID);
            if (entry != NULL && entry->model != NULL) {
                int count = GetNibbleField020de2a4((Obj020de2a4*)entry, 0, female);
                if (count != 0) {
                    count *= 2;
                    Model3D* model = self->parts[part].pModel_;
                    if (model != NULL) {
                        NSBXXTex* texture = model->GetTEX0();
                        if (texture != NULL) {
                            int offset = 0x30;
                            unsigned short size = texture->block4NumEightBytes_ << 3;
                            size = (size + 0x1f) & ~0x1f;
                            int reserved = 0x20;
                            if (part == 0) reserved = 0x200;
                            offset -= size - reserved;
                            PaletteTable021e540c* table = (PaletteTable021e540c*)GetVariantShortTable02109928_02099cac();
                            if (table != NULL) {
                                const void* data = NULL;
                                unsigned int bytes = count * 2;
                                switch (count) {
                                case 2: data = table->eyes2[eye]; break;
                                case 4: data = table->eyes4[eye]; break;
                                case 8: data = table->eyes8[eye]; break;
                                }
                                if (data != NULL) {
                                    unsigned int destination = self->vramStates[part].palette << 3;
                                    destination += offset;
                                    StageMemoryToVRAM(VRAMSubregion_TexturePalette, data, destination, bytes, false, true);
                                }
                            }
                        }
                    }
                }
            }
          }
        }
    }
}
