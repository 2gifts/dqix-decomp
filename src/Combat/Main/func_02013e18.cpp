#include <globaldefs.h>
#include "World/Zone3D.h"
#include "Graphics/LightingManager.h"
#include "Resource/GameResources.h"
#include "GameState/GameState.h"

extern "C" {
    int _Z33ApplyAndClearPendingEntry02013fb4P11Obj02013fb4(void*);
    int _ZN6Zone3D13UnpackMapAMBLEv(void*);
    int _ZN6Zone3D14UnpackATS_AMBLEv(void*);
    int _ZN6Zone3D13UnpackMapAMDJEv(void*);
    int _Z29AccumulateHandleStats0201498cPv(void*);
    long long _s32_div_f(int, int);
    int func_02019728(void*, int, void*, void*, void*);
    int func_0201a600(void*);
    int func_02017a94(void*);
    int _Z17IsInRange0201b5b0i(int);
    int _Z22IsValueInRange0201b5d8i(int);
    void _Z15Set3DClearColoriiiii(int, int, int, int, int);
    void _Z15SetBitsInField4Pjj(unsigned int*, unsigned int);
    void _Z17ClearBitsInField4Pjj(unsigned int*, unsigned int);
    void _Z25NotifyActiveSlots02018f30Ph(unsigned char*);
    void _Z28CollectMatchingElems020181fcPv(void*);
    void _Z27UpdateEntryFlagsForNodeListPh(unsigned char*, unsigned char*, int);
    int _Z15GetFieldIfFlag4Pc(char const*);
}

// USA: func_02013e18
extern "C" ARM int func_02013e18(Zone3D* zone)
{
    if (zone->unknown_424_ == 0)
        return 1;

    if (!_Z33ApplyAndClearPendingEntry02013fb4P11Obj02013fb4(zone))
        return 0;

    if (!_ZN6Zone3D13UnpackMapAMBLEv(zone))
        return 0;

    if (!_ZN6Zone3D14UnpackATS_AMBLEv(zone))
        return 0;

    if (!_ZN6Zone3D13UnpackMapAMDJEv(zone))
        return 0;

    if (!_Z29AccumulateHandleStats0201498cPv(zone))
        return 0;

    int v = *(unsigned short*)zone->pUnknownStruct_8_;

    if (_Z17IsInRange0201b5b0i(v))
    {
        func_02019728(zone, (int)(_s32_div_f(v, 0x14) >> 32), 0, 0, 0);
        func_0201a600(zone);
    }
    else if (_Z22IsValueInRange0201b5d8i(v))
    {
        func_0201a600(zone);
    }

    LightingManager* lm = LightingManager::GetInstance();
    lm->ProcessZoneChange(zone);

    int ovr = lm->lightingIndexOverride_;
    int idx = lm->timeOfDayIndex_;
    if (ovr)
        idx = ovr;

    int color;
    if (zone->lighting_.maybeMode_ == 1)
        color = zone->lighting_.basic_.backgroundColor[idx];
    else
        color = zone->lighting_.advanced_.backgroundColor[idx];

    _Z15Set3DClearColoriiiii(color, 0x10, 0x7fff, 0, 0);

    unsigned int* res = (unsigned int*)func_ov017_0218b5b0();
    int t = (unsigned int)((unsigned char*)zone->pUnknownStruct_8_)[0xe] << 24 >> 31;
    if (!t)
        _Z15SetBitsInField4Pjj(res, 0x800);
    else
        _Z17ClearBitsInField4Pjj(res, 0x800);

    _Z25NotifyActiveSlots02018f30Ph((unsigned char*)zone);
    _Z28CollectMatchingElems020181fcPv(zone);
    (void)_Z15GetFieldIfFlag4Pc((char const*)GameState::GetInstance());

    zone->unk_830[1] = (char)lm->timeOfDayIndex_;
    zone->unk_830[2] = 0;
    zone->unknown_424_ = 0;

    unsigned char* sub = (unsigned char*)zone + 0x2000;
    sub[0x3bc] = 1;
    _Z27UpdateEntryFlagsForNodeListPh((unsigned char*)zone, sub, 1);
    func_02017a94(zone);
    return 1;
}
