#include <globaldefs.h>
#include "GameState/Overlay17DayCycle.h"

#pragma define_section initcode ".init" RX

// USA: func_ov017_021d6ed0  (semantic: AccumulateFloats_021d6ed0)
extern "C" __declspec(initcode) ARM void __sinit_ov017_021d6ed0(void) {
    data_ov017_021d837c.cycleLength = data_ov017_021d75b8.eveningDuration +
        (data_ov017_021d75b8.dayDuration +
        (data_ov017_021d75b8.nightDuration + data_ov017_021d75b8.morningDuration));
    float boundary = data_ov017_021d837c.nightStart + data_ov017_021d75b8.nightDuration;
    float morningDuration = data_ov017_021d75b8.morningDuration;
    data_ov017_021d837c.morningStart = boundary;
    boundary += morningDuration;
    float dayDuration = data_ov017_021d75b8.dayDuration;
    data_ov017_021d837c.dayStart = boundary;
    boundary += dayDuration;
    data_ov017_021d837c.eveningStart = boundary;
}
