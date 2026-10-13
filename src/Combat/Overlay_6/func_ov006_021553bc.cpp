#include <globaldefs.h>
#include "Resource/AlchemyPot.h"

struct CallIfFlag0x800_021571ccStruct;
struct Container020e0310;

#if defined(jpn)
#define SetFields_021dceac func_ov023_021dd7b0
#define func_ov023_021dced4 func_ov023_021dd7d8
int GetFieldByKey020e0434(Container020e0310*, int);
extern "C" void SetFields_021dceac(char*, int, int, unsigned char, unsigned char, unsigned char);
#else
const char** CallFunc020e52a0(void* names, int item);
extern "C" void func_020e4864(const char*, char*, int, int, int, int);
void SetFields_021dceac(char*, int, int, unsigned char, unsigned char, unsigned char);
#endif
extern "C" void func_ov023_021dced4(AlchemyItemInfoWindow*, unsigned char);
void CallIfFlag_021571cc_021571cc(CallIfFlag0x800_021571ccStruct*);

// USA: func_ov006_021553bc
// JPN: func_ov006_02156ad0
extern "C" ARM void func_ov006_021553bc(AlchemyPot* self, short* items, unsigned char* amounts) {
    const char* names[3] = {0};
    for (unsigned char i = 0; i < 3; i++) {
        if (self->itemNames_ != 0) {
#if defined(jpn)
            names[i] = (const char*)GetFieldByKey020e0434((Container020e0310*)self->itemNames_, items[i]);
#else
            const char** name = CallFunc020e52a0(self->itemNames_, items[i]);
            if (name != 0) {
                func_020e4864(*name, self->names_[i], 1, 0, 0, 0);
                names[i] = self->names_[i];
            }
#endif
            SetFields_021dceac((char*)&self->window_, i, (int)names[i], amounts[i], amounts[i], 0);
        }
    }
    func_ov023_021dced4(&self->window_, 1);
    CallIfFlag_021571cc_021571cc((CallIfFlag0x800_021571ccStruct*)self);
}
