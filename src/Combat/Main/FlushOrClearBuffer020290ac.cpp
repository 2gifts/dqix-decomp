#include <globaldefs.h>

#if defined(jpn)
#define FlushOrClearBuffer020290ac func_0202898c
#endif
extern "C" void LoadToMainBG1CharacterData(int, int, unsigned int);
extern "C" void LoadToSubBG0CharacterData(int, int, unsigned int);

#if defined(jpn)
struct GfxBufferHolder {
    char pad[4];
    void* buffer;
};
extern GfxBufferHolder data_020fe6fc;
#define data_020fe9a4 data_020fe6fc.buffer
#else
extern void* data_020fe9a4;
#endif

#if defined(jpn)
extern "C" ARM void func_0202898c(int flag);
#endif

// USA: func_020290ac
ARM void FlushOrClearBuffer020290ac(int flag) {
    if (data_020fe9a4 == NULL) return;
    if (flag == 0) {
        LoadToMainBG1CharacterData((int)(data_020fe9a4), (int)(0), (unsigned int)(0x6000));
    } else {
        LoadToSubBG0CharacterData((int)(data_020fe9a4), (int)(0), (unsigned int)(0x6000));
    }
}
