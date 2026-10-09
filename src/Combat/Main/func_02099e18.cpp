#include <globaldefs.h>
#include "Graphics/Model3D.h"
#include "Graphics/VRAMStaging.h"
#include "System/Cache.h"
struct PaletteBlock02099e18 { unsigned int values[3]; };
extern unsigned short data_02109928[][2] __attribute__((aligned(4)));
extern unsigned short data_021099b0[][8] __attribute__((aligned(4)));
extern unsigned short data_02109a30[][2] __attribute__((aligned(4)));
extern PaletteBlock02099e18 data_020e8e14, data_020e8e20;
// USA: func_02099e18
extern "C" ARM void func_02099e18(Model3D* model, int color, int hair, int skin) {
    NSBXXTex* tex;
    void* entries[3];
    PaletteBlock02099e18 sizes;
    PaletteBlock02099e18 offsets;
    unsigned char* base;
    unsigned int length;
    int i;
    if (model) {
        tex = model->GetTEX0();
        if (tex) {
            base = (unsigned char*)tex + tex->block4Offset_;
            length = tex->block4NumEightBytes_ << 3;
            entries[0] = data_02109928[hair];
            entries[1] = data_02109a30[skin];
            entries[2] = data_021099b0[color];
            sizes = data_020e8e14;
            offsets = data_020e8e20;
            for (i = 0; i < 3; i++) memcpy(base + offsets.values[i], entries[i], sizes.values[i]);
            CleanInvalidateCacheRange(base, length);
            StageTexFilePaletteData(tex, true);
        }
    }
}
