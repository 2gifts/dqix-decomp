#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Resource/Brightness.h"
#include <globaldefs.h>

#if defined(jpn)
#endif

extern "C"
{
    void _Z34EncodeSignFlaggedHalfword_020c39a0Psi(volatile unsigned short *reg, int brightness);
    int _Z22GetSignedField020c39c8PVt(volatile unsigned short *reg);

    void *_Z24GetGlobalContext020daf90v();
    int _Z35ProcessCombatantAnimRequest020db9ccPviii(void *unk, int screen, int brightness, unsigned int duration);
}
#define REG_MASTER_BRIGHT ((volatile unsigned short *) 0x0400006C)
#define REG_MASTER_BRIGHT_SUB ((volatile unsigned short *) 0x0400106C)

static inline int IsTransitioningMain(GameResources* res) { return res->mainBrightnessTimeRemaining > 0; }
static inline int IsTransitioningSub(GameResources* res) { return res->subBrightnessTimeRemaining > 0; }

void InitializeBrightnessState(GameResources* resources)
{
    resources->brightnessFlags_0 = 0;
    resources->brightnessFlags_4 = 0;
    resources->brightnessFlags_8 = 0;

    resources->mainBrightnessTimeRemaining = 0;
    resources->subBrightnessTimeRemaining  = 0;

    resources->mainBrightnessLocked = false;
    resources->subBrightnessLocked  = false;
    resources->mainBrightnessDirty  = false;
    resources->subBrightnessDirty   = false;

    resources->allowBrightnessApply = true;

    resources->mainBrightness = (float) _Z22GetSignedField020c39c8PVt(REG_MASTER_BRIGHT);
    resources->subBrightness = (float) _Z22GetSignedField020c39c8PVt(REG_MASTER_BRIGHT_SUB);
}

void Stub(GameResources*) {}

void UpdateBrightnessTransitions(GameResources* resources)
{
    int delta = GameState::GetInstance()->GetEffectiveDeltaTime();

    if (IsTransitioningMain(resources))
    {
        resources->mainBrightness += (float)delta * (((float)resources->mainBrightnessTarget - resources->mainBrightness) /
                                                    (float)resources->mainBrightnessTimeRemaining);
        resources->mainBrightnessTimeRemaining -= delta;

        if (resources->mainBrightnessTimeRemaining <= 0)
            resources->mainBrightness = (float)resources->mainBrightnessTarget;

        resources->mainBrightnessDirty = true;
    }

    if (IsTransitioningSub(resources))
    {
        resources->subBrightness += (float)delta * (((float)resources->subBrightnessTarget - resources->subBrightness) /
                                                   (float)resources->subBrightnessTimeRemaining);
        resources->subBrightnessTimeRemaining -= delta;

        if (resources->subBrightnessTimeRemaining <= 0)
            resources->subBrightness = (float)resources->subBrightnessTarget;

        resources->subBrightnessDirty = true;
    }
}

void ApplyBrightness(GameResources* resources)
{
    if (resources->allowBrightnessApply == 0) return;

    resources->allowBrightnessApply = 0;

    if (resources->mainBrightnessDirty)
        _Z34EncodeSignFlaggedHalfword_020c39a0Psi(REG_MASTER_BRIGHT, (int) resources->mainBrightness);

    resources->mainBrightnessDirty = false;

    if (resources->subBrightnessDirty)
        _Z34EncodeSignFlaggedHalfword_020c39a0Psi(REG_MASTER_BRIGHT_SUB, (int) resources->subBrightness);

    resources->subBrightnessDirty = false;
}

void UpdateAndApplyBrightness(GameResources* resources)
{
    UpdateBrightnessTransitions(resources);
    ApplyBrightness(resources);
}

void SetMainBrightness(GameResources* resources, int brightness, int duration)
{
    if (resources->mainBrightnessLocked)
        return;

    void *unk = _Z24GetGlobalContext020daf90v();

    if (_Z35ProcessCombatantAnimRequest020db9ccPviii(unk, 0, brightness, duration) == 0)
        return;

    if (duration == 0)
    {
        resources->mainBrightness              = (float)brightness;
        resources->mainBrightnessTarget        = brightness;
        resources->mainBrightnessTimeRemaining = 0;
        resources->mainBrightnessDirty         = true;
    }
    else
    {
        resources->mainBrightnessTarget        = brightness;
        resources->mainBrightnessTimeRemaining = (int)((float)duration * 16.667f);
    }
}

void SetSubBrightness(GameResources* resources, int brightness, int duration)
{
    if (resources->subBrightnessLocked)
        return;

    void *unk = _Z24GetGlobalContext020daf90v();

    if (_Z35ProcessCombatantAnimRequest020db9ccPviii(unk, 1, brightness, duration) == 0)
        return;

    if (duration == 0)
    {
        resources->subBrightness              = (float)brightness;
        resources->subBrightnessTarget        = brightness;
        resources->subBrightnessTimeRemaining = 0;
        resources->subBrightnessDirty         = true;
    }
    else
    {
        resources->subBrightnessTarget        = brightness;
        resources->subBrightnessTimeRemaining = (int)((float)duration * 16.667f);
    }
}

void SetBrightness(GameResources* resources, int brightness, int duration)
{
    SetMainBrightness(resources, brightness, duration);
    SetSubBrightness(resources, brightness, duration);
}

void SetAndLockMainBrightness(GameResources* resources, int brightness, int duration)
{
    SetMainBrightness(resources, brightness, duration);
    resources->mainBrightnessLocked = true;
}

void SetAndLockSubBrightness(GameResources* resources, int brightness, int duration)
{
    SetSubBrightness(resources, brightness, duration);
    resources->subBrightnessLocked = true;
}

void SetAndLockBrightness(GameResources* resources, int brightness, int duration)
{
    SetMainBrightness(resources, brightness, duration);
    resources->mainBrightnessLocked = true;

    SetSubBrightness(resources, brightness, duration);
    resources->subBrightnessLocked = true;
}

void UnlockAndSetMainBrightness(GameResources* resources, int brightness, int duration)
{
    resources->mainBrightnessLocked = false;
    SetMainBrightness(resources, brightness, duration);
}

void UnlockAndSetSubBrightness(GameResources* resources, int brightness, int duration)
{
    resources->subBrightnessLocked = false;
    SetSubBrightness(resources, brightness, duration);
}

void UnlockAndSetBrightness(GameResources* resources, int brightness, int duration)
{
    resources->mainBrightnessLocked = false;
    SetMainBrightness(resources, brightness, duration);

    resources->subBrightnessLocked = false;
    SetSubBrightness(resources, brightness, duration);
}

void SetMainBrightnessWithDurationMs(GameResources* resources, int brightness, unsigned int durationMs)
{
    if (resources->mainBrightnessLocked)
        return;

    void *unk = _Z24GetGlobalContext020daf90v();
    unsigned int numFrames = (durationMs * 3) / 100;

    if (_Z35ProcessCombatantAnimRequest020db9ccPviii(unk, 0, brightness, numFrames) == 0)
        return;

    if (durationMs != 0)
    {
        resources->mainBrightnessTarget        = brightness;
        resources->mainBrightnessTimeRemaining = durationMs;
    }
    else
    {
        resources->mainBrightness              = (float) brightness;
        resources->mainBrightnessTarget        = brightness;
        resources->mainBrightnessTimeRemaining = 0;
        resources->mainBrightnessDirty         = true;
    }
}

int IsMainBrightnessTransitionActive(GameResources* resources)
{
    return resources->mainBrightnessTimeRemaining > 0;
}

int IsSubBrightnessTransitionActive(GameResources* resources)
{
    return resources->subBrightnessTimeRemaining > 0;
}

int IsBrightnessTransitionActive(GameResources* resources)
{
    return IsTransitioningMain(resources) || IsTransitioningSub(resources);
}

int GetMainBrightnessTransitionState(GameResources* resources)
{
    if (!IsTransitioningMain(resources))
        return 0;

    int state = 1;

    if (resources->mainBrightnessTarget < 0)
        state = 2;
    if (resources->mainBrightnessTarget > 0)
        state = 3;

    return state;
}

int GetSubBrightnessTransitionState(GameResources* resources)
{
    if (!IsTransitioningSub(resources))
        return 0;

    int state = 1;

    if (resources->subBrightnessTarget < 0)
        state = 2;
    if (resources->subBrightnessTarget > 0)
        state = 3;

    return state;
}

unsigned short GetBrightnessTransitionStates(GameResources* resources)
{
    int mainState = GetMainBrightnessTransitionState(resources);
    int subState  = GetSubBrightnessTransitionState(resources);

    return mainState | (subState << 8);
}
