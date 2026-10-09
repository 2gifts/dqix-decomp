#include <globaldefs.h>

extern "C" int _Z34ReplaceBinExtensionWithNat020e05f8PcPKc(char* dst, const char* fmt);
typedef int (*ReplaceBin3)(char*, const char*, int);
void* LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void* ExtractFileFromGP2(const char* gp2Path, const char* innerFilePath, unsigned int* outSize);

extern char data_0211e33c[];

// USA: func_020e0574
extern "C" ARM int func_020e0574(void* a, int* b, int c, int d) {
    char buf[0x40];
    if (a == 0) {
        return 0;
    }
    *b = 0;
    ((ReplaceBin3)_Z34ReplaceBinExtensionWithNat020e05f8PcPKc)(buf, (char*)a, c);
    if (d == 0) {
        LoadFileIntoMemory(buf, data_0211e33c, (unsigned int*)b);
        if (*b != 0) {
            return (int)data_0211e33c;
        }
    } else {
        void* res = ExtractFileFromGP2((const char*)d, buf, (unsigned int*)b);
        if (res != 0) {
            return (int)res;
        }
    }
    return 0;
}