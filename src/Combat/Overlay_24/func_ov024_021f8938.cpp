#include <globaldefs.h>
#include <GameState/GameState.h>

struct Element02079f20 {
    unsigned int key_ : 8;
    unsigned int baseline_ : 10;
    unsigned int unused0 : 14;
    unsigned int unused4 : 10;
    unsigned int minimum_ : 10;
    unsigned int maximum_ : 10;
    unsigned int unused7 : 2;
};
struct ActionScaling {
    unsigned int field0;
    unsigned int unused4 : 12;
    unsigned int lower_ : 10;
    unsigned int upper_ : 10;
    unsigned int unused8 : 14;
    unsigned int key_ : 8;
    unsigned int unusedA : 10;
    unsigned int fieldC;
    unsigned int flags_;
    unsigned int field14;
    unsigned int unused18 : 16;
    unsigned int mode_ : 2;
    unsigned int unused1A : 14;
};
void* GetData02108e10();
extern "C" Element02079f20* _Z26LookupElementByKey02079ee0Pvi(void*, int);

// USA: func_ov024_021f8938
extern "C" ARM void func_ov024_021f8938(void* unused, float* value, float* spread, int unused2, ActionScaling* action, GameObject* actor) {
    void* data = GetData02108e10();
    *value = 0;
    *spread = 0;
    Element02079f20* element = _Z26LookupElementByKey02079ee0Pvi(data, action->key_);
    if (element) {
        if (action->mode_ == 2) {
            int lower = action->lower_;
            int upper = action->upper_;
            float minimum;
            float maximum;
            int scale = 0;
            minimum = (float)element->minimum_;
            maximum = (float)element->maximum_;
            float stat;
            if (action->flags_ & 0x4000) {
                stat = (float)(unsigned short)actor->currentStats_->primaryStats.magicalMight;
                scale = 1;
            } else if (action->flags_ & 0x8000) {
                stat = (float)(unsigned short)actor->currentStats_->primaryStats.magicalMending;
                scale = 1;
            } else stat = 0.5f * (minimum + maximum);
            if (scale) {
                if (stat <= lower) *value = minimum;
                else if (stat >= upper) *value = maximum;
                else {
                    *value = (stat - lower) * ((maximum - minimum) / (upper - lower));
                    *value += minimum;
                }
                *spread = *value - (float)element->baseline_;
            } else {
                *value = 0.5f * (maximum + minimum);
                *spread = minimum;
            }
        } else {
            *value = 0.5f * (element->minimum_ + element->maximum_);
            *spread = (float)element->minimum_;
        }
    } else {
        *value = 0;
        *spread = 0;
    }
    if (*value < 0) *value = 0;
    else if (*value >= 32767.0f) *value = 32767.0f;
    if (*spread < 0) *spread = 0;
    else if (*spread >= 32767.0f) *spread = 32767.0f;
}
