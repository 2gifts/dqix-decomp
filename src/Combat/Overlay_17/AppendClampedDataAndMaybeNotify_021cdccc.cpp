#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void* func_0205ec34(void* obj);
void ClassifyPriceCategoryAndNotifyBattle_02064b98(unsigned char* table, int price);

// USA: func_ov017_021cdccc  (semantic: AppendClampedDataAndMaybeNotify_021cdccc)
extern "C" ARM void func_ov017_021cdccc(void* obj, int pos, void* data) {
    unsigned char* buf = (unsigned char*)func_0205ec34(obj);
    int end = pos + 0xe;
    int len = 0xe;
    int truncated = 0;
    if ((unsigned int)end > 0xfd) {
        len = 0xfd - pos;
        truncated = 1;
    } else if (end == 0xfd) {
        truncated = 1;
    }
    if (len < 0) return;

    void* dst = memcpy(buf + pos, data, len);
    if (!truncated) return;

    ClassifyPriceCategoryAndNotifyBattle_02064b98((unsigned char*)func_0205ec34(dst), 0xc3b5);
}
