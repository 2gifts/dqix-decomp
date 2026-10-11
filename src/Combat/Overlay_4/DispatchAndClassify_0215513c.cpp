#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

struct Obj021f6f08;
void* DoThing_021f6590(void*);
unsigned int GetShort6_021f6f08(Obj021f6f08*);
typedef void* (*DoThingFn_0215513c)(void*, int);

// USA: func_ov004_0215513c  (semantic: DispatchAndClassify_0215513c)
#pragma optimize_for_size off
extern "C" ARM int func_ov004_0215513c(void* obj, short* pB, short* pC, short* pD) {
    *pD = -1;
    short v = *pD;
    *pC = v;
    *pB = v;
    void* result = ((DoThingFn_0215513c)DoThing_021f6590)(obj, 5);
    if (!result) return (int)result;
    unsigned int kind = GetShort6_021f6f08((Obj021f6f08*)result);
    switch (kind) {
        case 0x1a:
            *pB = 0;
            return 0;
        case 0x1b:
            *pC = 8;
            return 8;
        case 0x1c:
            kind = 9;
            *pC = 9;
            break;
    }
    return kind;
}
