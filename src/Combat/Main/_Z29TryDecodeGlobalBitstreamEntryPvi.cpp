#include <globaldefs.h>

extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv(void);
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv(void);
extern "C" void* _Z18LoadFileIntoMemoryPKcPvPj(const char* path, void* dst, unsigned int* outSize);
extern "C" void _Z25RunBufferedStream0207416ciiP12StreamHeaderi(int a0, int a1, int a2, int a3);

extern int data_020f0d40;
extern int data_0211e33c;

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_02074114
extern "C" ARM int _Z29TryDecodeGlobalBitstreamEntryPvi(int param0, int param1) {
    unsigned int size;

    _ZN16BackgroundLoader13AddLockGlobalEv();
    void* handle = (void*)_Z18LoadFileIntoMemoryPKcPvPj((const char*)&data_020f0d40, (void*)&data_0211e33c, &size);
    if (handle != 0) {
        _Z25RunBufferedStream0207416ciiP12StreamHeaderi(param0, param1, (int)handle, (int)size);
        _ZN16BackgroundLoader16RemoveLockGlobalEv();
        return 1;
    }
    _ZN16BackgroundLoader16RemoveLockGlobalEv();
    return 0;
}
