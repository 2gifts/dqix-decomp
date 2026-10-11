#include <globaldefs.h>

extern void* data_ov031_0224e588;
extern "C" void VectorizedMemset(void* dst, int value, unsigned int size);
extern "C" int _Z29CallWithZeroZeroZero_0220728ciii(int a, int b, int c);
extern "C" void func_ov031_02210358(int a, int b);

// USA: func_ov031_022104e4
extern "C" ARM int func_ov031_022104e4(unsigned char* buf) {
    int n = 0;
    unsigned int processed = n;
    unsigned char* header = buf;
    unsigned char* cur = buf;
    if (data_ov031_0224e588 == NULL) {
        return n - 0x1c;
    }
    VectorizedMemset(buf, 0, 0x414);
    do {
        int handle = *(int*)((char*)data_ov031_0224e588 + 0x1b8);
        n = _Z29CallWithZeroZeroZero_0220728ciii(handle, (int)cur, 4 - processed);
        if (n > 0) {
            processed += n;
            cur += n;
        } else {
            if ((int)processed > 0 || n != 0) {
                func_ov031_02210358(6, -0x32);
            }
            return processed;
        }
    } while (processed < 4);
    unsigned int total = *(unsigned int*)header;
    if (total > 0x414) {
        func_ov031_02210358(6, -0x32);
        return ~0x22;
    }
    if (processed < total) {
        do {
            int handle = *(int*)((char*)data_ov031_0224e588 + 0x1b8);
            n = _Z29CallWithZeroZeroZero_0220728ciii(handle, (int)cur, total - processed);
            if (n > 0) {
                processed += n;
                cur += n;
            } else {
                func_ov031_02210358(6, -0x32);
                return processed;
            }
        } while (processed < total);
    }
    if (processed < 0xc || *(unsigned int*)(header + 4) != 0x44535359) {
        func_ov031_02210358(6, -0x28);
        return 0;
    }
    return processed;
}
