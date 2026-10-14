#include <globaldefs.h>

int GetGlobalField0x48_0202d6b8(void);
int GetGlobalField0x10_0202d6a8(void);
void SleepCurrentContext(unsigned int);

// USA: func_0202b284
ARM int PollUntilFieldMatchesOrLimit0202b284(int unused, int threshold) {
    unsigned int i = 0;
    int cur;
    while ((cur = GetGlobalField0x10_0202d6a8()) != threshold) {
        if (GetGlobalField0x48_0202d6b8() == 8) return 3;
        if ((unsigned int)(cur - 9) <= 1) return 1;
        i++;
        if (i > 0x4e20) return 2;
        SleepCurrentContext(1);
    }
    return 0;
}
