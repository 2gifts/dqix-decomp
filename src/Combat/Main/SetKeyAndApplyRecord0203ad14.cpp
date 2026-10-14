#include <globaldefs.h>

void* SetGlobalContext02110370(void*);
int TryApplyRecordAndSetFlag020bec30(void* a, int key, int arg2);
extern "C" void func_020bbd9c(void);

// USA: func_0203ad14
ARM int SetKeyAndApplyRecord0203ad14(void* obj, int key, void* target, int arg3) {
    char* p = (char*)obj;
    int result;
    if (*(void**)p == NULL) return 0;
    SetGlobalContext02110370(p + 0x4);
    *(unsigned short*)(p + 0xa4) = key;
    *(int*)(p + 0xa8) = 0;
    if (target != NULL) {
        result = TryApplyRecordAndSetFlag020bec30(target, key, arg3);
    } else {
        result = TryApplyRecordAndSetFlag020bec30(p + 0x9c, key, arg3);
    }
    func_020bbd9c();
    return result;
}
