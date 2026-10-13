// KEEP-NAME
// USA: func_ov006_02156b80
// JPN: func_ov006_0215818c
#include <globaldefs.h>
#include "Resource/AlchemyPot.h"

#if defined(jpn)
extern "C" void func_ov006_02156ea4(void*);
#else
extern "C" void func_ov006_021557c0(void*);
#endif
extern "C" void func_ov023_021dc488(void*);

ARM void Something02156b80(void* object) {
    AlchemyPot* pot = (AlchemyPot*)object;
    if (!(pot->flags_ & 8)) {
        pot->protagonist_.AdvanceEffects();
        pot->pot_.AdvanceEffects();
        pot->lid_.AdvanceEffects();
        pot->effect_.SetNormalizedAnimationTime(pot->pot_.normalizedAnimationTime_);
    }
#if defined(jpn)
    func_ov006_02156ea4(pot);
#else
    func_ov006_021557c0(pot);
#endif
    func_ov023_021dc488(&pot->window_);
}
