#include <globaldefs.h>

int LookupAndForEachNode020649b0(void*, int, void*);

// USA: func_02064a24
ARM void ClearField0x498Dispatch10_02064a24(void* obj, int arg) {
    *(int*)((char*)obj + 0x498) = 0;
    LookupAndForEachNode020649b0(obj, 0x10, (void*)arg);
}
