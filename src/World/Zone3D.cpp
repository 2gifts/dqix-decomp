#include "World/ZoneResourceInitialization.h"
#include "World/Zone3D.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/NarcHandle.h"
#include "Filesystem/FileAccessor.h"
#include "Filesystem/LowNitroHandle.h"
#include "Filesystem/FileIO.h"
#include "Resource/GameResources.h"
#include "Graphics/NSBXX/NSBXX.h"

#if defined(jpn)
#define _Z13Reset02013490Pc func_02013258

#define data_020ef0f0 data_020ef02c
#endif

extern "C"
{
    void* _Z16GetPtrField0x468Pv(GameState*);
    void _Z18InitStruct02013454Pc(void*);

    void* _Z15GetFieldAt0x150Ph(void*);
    void _Z25RunBufferedStream0205e104iiP12StreamHeaderi(const char*, SafeAllocator*, const void*, unsigned int);

    // Texture functions
    void* _Z26CopyInternalFields0207df50P11Foo0207df50(void*);
    void _Z25RestorePairTables0207df90Pc(void*);
    void _Z24BackupPairTables0207dfacPc(void*);

    void* _Z15GetData02108f0cv();
    void _Z23ClearThreeWords02094d00P29ClearThreeWords02094d00Struct(void*);
    Zone3D_StructPtr_8* _Z22FindEntryByHalfwordKeyP11SearchTablei(void*, unsigned short id);

    void func_020c9be0(); // abort() or similar
    void _Z16ZeroInit020de848Pv(void*);

    void _Z13Reset02013490Pc(void*);
    void _Z22ResetBigStruct02013750Pvi(Zone3D*, bool);
    void _ZN6Zone3D15ProcessBATSFileEPKvj(Zone3D*, const void*, unsigned);

    // checks if zone id corresponds to a main floor of a grotto
    bool _Z17IsInRange0201b5b0i(int id);
    // checks if zone id corresponds to boss floor of a grotto
    bool _Z22IsValueInRange0201b5d8i(int id);

    void _ZN12ZoneFeatures5ResetEv(void*);
}

extern char data_020ef0f0[]; // "data/map/maplist9.bin"
extern char data_020ef106[]; // "%s/Z0%dM01.ambl"
extern char data_020ef116[]; // "data/map"
extern char data_020ef11f[]; // "%s/Z0%dM99.ambl"
extern char data_020ef12f[]; // "%s/%s.ambl"
extern char data_020ef13a[]; // "ARC"
extern char data_020ef13e[]; // ".nsbtx"
extern char data_020ef145[]; // ".bmbl"
extern char data_020ef14b[]; // ".dat"
extern char data_020ef150[]; // ".bpos"
extern char data_020ef156[]; // "%s/Z0%dM01.amdj"
extern char data_020ef166[]; // "%s/Z0%dM99.amdj"
extern char data_020ef176[]; // "%s/%sb.amdj"
extern char data_020ef182[]; // "%s/%sa.amdj"
extern char data_020ef18e[]; // "%s/%s.amdj"
extern char data_020ef199[]; // ".bmdj"
extern char data_020ef19f[]; // "Z0%dM0100"
extern char data_020ef1a9[]; // "Z0%dM0101"
extern char data_020ef1b3[]; // "Z0%dM0102"
extern char data_020ef1bd[]; // "Z0%dM0103"
extern char data_020ef1c7[]; // "%s/ats_%c.ambl"
extern char data_020ef1d6[]; // "%s.bats"
extern char data_020ef1de[]; // "ARC:/%s"
extern char data_020ef1e6[]; // "."
extern char data_020ef1e8[]; // "nsbmd"
extern char data_020ef1ee[]; // "col2"
extern char data_020ef1f3[]; // "open"
extern char data_020ef1f8[]; // "open2"
extern char data_020ef1fe[]; // "close"
extern char data_020ef204[]; // "close2"
extern char data_020ef20b[]; // "/data/ani/d_%c%03d.spr"
extern char data_020ef222[]; // "tsuboware"
extern char data_020ef22c[]; // "ARC:%s"

void Zone3D::SwitchZone(unsigned short newID)
{
    GameState* gameState = GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();

    void* uVar3 = _Z16GetPtrField0x468Pv(gameState);
    (void)func_ov017_0218b5b0();
    GameObject* iVar4 = gameState->GetUnknownGameObject();

    pAllocator_68_ = pAllocator_4c_;
    pAllocator_68_->Reset();

    _Z26CopyInternalFields0207df50P11Foo0207df50(unknown_ptr_50_);
    _Z22ResetBigStruct02013750Pvi(this, true);

    previousZoneID_ = currentZoneID_;
    currentZoneID_ = newID;

    textureImageMemory_ = 0;
    texturePaletteMemory_ = 0;
    unknown_424_ = 1;
    firstBMDJStruct_41c_ = 0;
    firstModel_418_ = NULL;
    unknown_476_ = 0;
    numChests_ = 0;
    unknown_82c_ = 0;
    unknown_474_ = 0;
    unknown_82c_ = 0; // why zero it twice?
    unknown_42c_ = 0;

    mapListLoadHandle_ = -1;
    unknown_434_ = -1;
    mapAMBLLoadHandle_ = -1;
    mapAMDJLoadHandle_ = -1;
    atsAMBLLoadHandle_ = -1;

    unknown_478_ = 0;
    unknown_47c_ = 0;
    unknown_834_ = 0;
    unknown_2820_ = 0;

    _ZN12ZoneFeatures5ResetEv(substruct_6c_);

    substruct_c_.buffer1[0] = 0;
    substruct_c_.buffer2[0] = 0;
    substruct_c_.buffer3[0] = 0;
    substruct_c_.unknown_2a_ = 0x7fff;
    substruct_c_.unknown_2c_ = 0;
    substruct_c_.unknown_30_ = 10;
    substruct_c_.unknown_34_ = 0;
    substruct_c_.unknown_38_ = 0;
    substruct_c_.unknown_3c_ = 0;

    atmosphericEffects_.Reset();
    lighting_.Reset();
    _Z16ZeroInit020de848Pv(&unknown_struct_2754_[0]);

    pUnknownStruct_8_ = _Z22FindEntryByHalfwordKeyP11SearchTablei(uVar3, newID);
    unknown_4_ = pUnknownStruct_8_->unknown_2_;
    if (pUnknownStruct_8_->unknown_c_low_ == 0)
    {
        GameObject* iVar5 = gameState->GetProtagonist();
        if (iVar5 != NULL)
        {
            void* iVar6 = _Z15GetFieldAt0x150Ph(iVar5);
            if (iVar6 != NULL)
                *(unsigned short*)((int)iVar6 + 0x566) = pUnknownStruct_8_->unknown_0_;
        }
    }

    *(bool*)((int)_Z15GetData02108f0cv() + 0x9c) = pUnknownStruct_8_->unknown_c_high_ != 0;
    _Z23ClearThreeWords02094d00P29ClearThreeWords02094d00Struct(&unknown_struct_2724_[0]);

    grottoTileMapData_420_ = NULL;

    if (_Z17IsInRange0201b5b0i(previousZoneID_))
    {
        grotto_.floorMap_.Clear();
    }

    if (_Z17IsInRange0201b5b0i(newID))
    {
        isInMainGrottoFloor_23b8_ = true;
        currentGrottoFloor_23ba_ = newID % 20;
        copyOfCurrentGrottoFloor_23bb_ = currentGrottoFloor_23ba_;
        int width = grotto_.CalculateAndStoreFloorWidth(currentGrottoFloor_23ba_);
        int height = grotto_.CalculateAndStoreFloorHeight(currentGrottoFloor_23ba_);

        grottoTileMapData_420_ = pAllocator_68_->Allocate(0x48 * 256);
        for (int i = 0; i < 256; i++)
        {
            _Z13Reset02013490Pc((char*)grottoTileMapData_420_ + i * 0x48);
        }
        grotto_.ClearGenerator(false);
        grotto_.AllocateGenerator(pAllocator_68_, false);
        grotto_.CalculateFloorMap(currentGrottoFloor_23ba_, width, height, NULL);
    }
    else
    {
        if (currentGrottoFloor_23ba_ != -1)
        {
            copyOfCurrentGrottoFloor_23bb_ = currentGrottoFloor_23ba_;
            position_23c0_ = iVar4->obj3D_.position_;
            unknown_23cc_ = *(short*)((int)iVar4 + 0xae);
        }
        isInMainGrottoFloor_23b8_ = false;
        currentGrottoFloor_23ba_ = -1;
    }

    mapListLoadHandle_ = loader->QueueLoadFile(data_020ef0f0, NULL);
}

// USA: func_02013b54
Vector3i &Vector3i::operator=(const Vector3i &other) {
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}
