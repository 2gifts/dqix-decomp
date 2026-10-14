#include <globaldefs.h>

void LockStagedTextureVRAMCopying();
extern "C" void MapVRAMBanksToTextureImage(int handle);
extern "C" void MapVRAMBanksToTexturePalette(int value);
extern "C" void MapVRAMBanksToMainBG(int v);
extern "C" void MapVRAMBanksToMainObj(int mode);
ARM void ConfigurePairMode020bb48c(unsigned int mode, int installHandlers);
extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void MapVRAMBanksToSubObj(int value);
void UpdateVRAMStagingVRAMBanks(void);
void UnlockStagedTextureVRAMCopying(void);

struct Obj02097c18 {
    char pad[0x1e];
    unsigned char field1e;
};

// USA: func_02097c18  (semantic: ConfigureVramFlags02097c18)
extern "C" ARM void func_02097c18(struct Obj02097c18* obj, unsigned char flags, unsigned int field0Val, int field4Val, int field8Val, int fieldcVal, int field10Val, int field14Val) {
    LockStagedTextureVRAMCopying();
    obj->field1e = flags;
    if (flags & 1) {
        unsigned int mask;
        unsigned short count;

        MapVRAMBanksToTextureImage(field0Val);
        MapVRAMBanksToTexturePalette(field4Val);
        MapVRAMBanksToMainBG(field8Val);
        MapVRAMBanksToMainObj(fieldcVal);

        mask = field0Val;
        count = 0;
        while (mask != 0) {
            count = count + 1;
            mask &= mask - 1;
        }
        ConfigurePairMode020bb48c(count, 1);
    }
    if (flags & 2) {
        MapVRAMBanksToSubBG(field10Val);
        MapVRAMBanksToSubObj(field14Val);
    }
    UpdateVRAMStagingVRAMBanks();
    UnlockStagedTextureVRAMCopying();
}
