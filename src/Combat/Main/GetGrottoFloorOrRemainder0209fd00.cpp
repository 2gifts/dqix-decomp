#include <globaldefs.h>
#if defined(jpn)
enum { kGrottoOffset = 0x240c };
#else
enum { kGrottoOffset = 0x23ec };
#endif

#include "Grotto/Main/ActiveGrottoClass.h"

extern "C" void* func_02012fe4(void);
int IsValueInRange0201b5d8(int x);

struct S0209fd00 {
    char pad0[4];
    char* field4;
};

struct Rec0209fd00 {
    unsigned short h0;
};

// USA: func_0209fd00
extern "C" ARM int func_0209fd00(struct S0209fd00* self) {
    struct Rec0209fd00* rec = *(struct Rec0209fd00**)(self->field4 + 0x8e18);
    if (rec == 0) return -1;
    int result = rec->h0 % 20;
    ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)func_02012fe4() + kGrottoOffset);
    if (grotto == 0) {
        result = 0;
    } else if (IsValueInRange0201b5d8(rec->h0)) {
        result = grotto->GetFloorCount() + 1;
    }
    return result;
}
