#include <globaldefs.h>

void Clear0x28Bytes_020a0d58(void* p);
void ApplyVec3Tail_0202e694(void* obj, int* vec);

// USA: func_020a2744
ARM void ApplyVecFromField0x21e_020a2744(char* actor) {
    Clear0x28Bytes_020a0d58(actor + 0x248);
    *(int*)(actor + 0x220) = *(short*)(actor + 0x21e);
    ApplyVec3Tail_0202e694(actor, (int*)(actor + 0x220));
}
