#include <globaldefs.h>

#if defined(jpn)
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v(void);
extern "C" int _Z17TestFlags02046708P16FlagWord02046708j(void*, unsigned int);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv(void);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*, int);

struct RegionalState02094b4c {
    char pad00[0x14];
    int taskIds[8];
    int pendingFirst;
    char pad38[0x1e];
    unsigned char firstFlag;
    unsigned char secondFlag;
};
typedef void (RegionalState02094b4c::*RegionalHandler02094b4c)(void);
extern unsigned int data_02109400;
extern RegionalHandler02094b4c data_020e6d5c;
extern RegionalHandler02094b4c data_020f148c[2];
extern RegionalHandler02094b4c data_020f148c_dup[2];
#endif

// USA: func_02094b4c
// JPN: func_02095b94
extern "C" ARM int _Z18AlwaysTrue02094b4cv(
#if defined(jpn)
    RegionalState02094b4c* self
#else
    void
#endif
) {
#if defined(jpn)
    if (self->pendingFirst < 0) return 1;
    if (_Z17TestFlags02046708P16FlagWord02046708j(_Z27GetDataPtr02114e04_020d6c00v(), 0x10)) {
        void* loader = _ZN16BackgroundLoader11GetInstanceEv();
        for (unsigned char i = 0; i < 8; ++i) {
            if (self->taskIds[i] >= 0) {
                _ZN16BackgroundLoader10RemoveTaskEi(loader, self->taskIds[i]);
                self->taskIds[i] = -1;
            }
        }
        self->firstFlag = 0;
        self->secondFlag = 0;
        return 0;
    }
    if (!(data_02109400 & 1)) {
        data_020f148c[1] = data_020e6d5c;
        data_02109400 |= 1;
    }
    if (!data_020f148c_dup[self->firstFlag]) return 1;
    (self->*data_020f148c_dup[self->firstFlag])();
    return 0;
#else
    return 1;
#endif
}
