#pragma once

#include "Grotto/Main/ActiveGrottoClass.h"
#include "Memory/SafeAllocator.h"
#include "Graphics/Vector.h"
#include "Graphics/Model3D.h"
#include "Graphics/AtmosphericEffect.h"
#include "Graphics/LightingInfo.h"
#include "Grotto/Main/TileFeatures.h"
#include "World/ZoneLootableRecord.h"

struct Zone3D_StructPtr_8
{
    unsigned short unknown_0_;
    unsigned short unknown_2_ : 15;
    char unk_4;
     // e.g. "F02" or "B01M13", corresponding to file data/map/%s.ambl and similar
    char mapShortName_[7];
    unsigned char unknown_c_low_ : 4;
    unsigned char unknown_c_high_ : 1;
};

struct ZoneChestRenderRecord
{
    Vector3i position;
    short angleY;
    short angleX;
    char unknown10[6];
    unsigned char active;
    unsigned char secondPass;
    char unknown18[12];
};

// sizeof == 0x2824, as seen in the dynamic allocation of one
// of these in func_ov001_02163b14 (usa).
// In JPN version, sizeof == 0x2864.
// Represents a 3D zone such as a town, field or grotto floor,
// but also a battlefield.
class Zone3D
{
public:
    struct Model3DListNode
    {
        Model3D model_;
        const char* filename_;
        Model3DListNode* pNext_;
    };

    unsigned short currentZoneID_;
    unsigned short previousZoneID_;

    short unknown_4_;
    char unk_6[2];
    Zone3D_StructPtr_8* pUnknownStruct_8_;
    struct
    {
        char buffer1[10];
        char buffer2[16];
        char buffer3[16];
#if defined(jpn)
        char jpbuffer[0x20];
#endif
        short unknown_2a_;
        short unknown_2c_;
        char pad_2e[2];
        int unknown_30_;
        short unknown_34_;
        char pad_36[2];
        int unknown_38_;
        int unknown_3c_;
    } substruct_c_;
    SafeAllocator* pAllocator_4c_;
    void* unknown_ptr_50_; // referenced in the nsbtx processor, so something graphical
    SafeAllocator internalAllocator_;
    SafeAllocator* pAllocator_68_;

    // Populated from BMBL and BPOS scripts, among other things holds data
    // about warps and placement of stairs/chests in grottos
    char substruct_6c_[0x88];
    AtmosphericEffectSet atmosphericEffects_;
    // populated by BATS files.
    // If you remove it, lighting goes weird outdoors, but I don't see any 
    // change in towns / battlefields
    LightingInfo lighting_;
    Model3DListNode* firstModel_418_;
    void* firstBMDJStruct_41c_;
    void* grottoTileMapData_420_;
    int unknown_424_;
    char unk_428[4];
    unsigned char unknown_42c_;
    char unk_42d[3];
    int mapListLoadHandle_; // for loading data/map/maplist9.bin
    int unknown_434_;
    int mapAMBLLoadHandle_; // loads things like data/map/Z02M01.ambl
    int mapAMDJLoadHandle_;
    int atsAMBLLoadHandle_; // data/map/ats_%c.ambl

    char unk_444[0x474 - 0x444];

    short unknown_474_;
    char unknown_476_;
    // this seems to include blue and red chests
    unsigned char numChests_;
    ZoneLootableRecord* unknown_478_;
    ZoneChestRenderRecord* unknown_47c_;

    Foo02048004* lootableTemplates_[6];
    Model3D models_498_[2];
    int chestPaletteOffsets_5f0_[4];
    char unk_600[0x82c - 0x600];

    int unknown_82c_;

    char unk_830[4];
    char unknown_834_;
    char unk_835[3];

    int textureImageMemory_;
    int texturePaletteMemory_;

    char unk_840[0x23b8 - 0x840];


    // 0x20 extra bytes unaccounted for in JPN version
    bool isInMainGrottoFloor_23b8_;
    char unknown_23b9_;
    char currentGrottoFloor_23ba_;
    char copyOfCurrentGrottoFloor_23bb_;
    char unk_23bc[4];
    // when you change zones such that you are no longer in a main
    // grotto floor (e.g. you go to boss zone, leave at the top or cast evac)
    // this stores your character position right before you left
    Vector3i position_23c0_;
    unsigned short unknown_23cc_;
    char unk_23ce[0x23ec - 0x23ce];
    ActiveGrottoClass grotto_; // offset 23ec in USA. this is 0x20 bytes larger in JPN
    char unk_2664[0x2724 - 0x2664];
    char unknown_struct_2724_[0xc];
    char unk_2730[0x274c - 0x2730];
    int chestRenderingEnabled_274c_;
    char unk_2750[0x2754 - 0x2750];
    char unknown_struct_2754_[0x18];
    char unk_276c[0x2820 - 0x276c];
    char unknown_2820_;
    char unk_2821[3];
public:
    // usa: _ZN6Zone3D10SwitchZoneEt
    void SwitchZone(unsigned short newID);
};
