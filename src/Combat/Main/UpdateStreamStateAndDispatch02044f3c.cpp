#include <globaldefs.h>

void RunStageSequence02067e98(unsigned char* obj, int b);
extern "C" void func_02044d0c(unsigned char* p);

struct Struct0204394c;
void PrepareEncodeStreamBuffer0204394c(struct Struct0204394c* obj);

// USA: func_02044f3c  (semantic: UpdateStreamStateAndDispatch02044f3c)
extern "C" ARM void func_02044f3c(unsigned char* obj, int b, int flag3) {
    (obj + 0x1000)[0x9bd] = 1;
    RunStageSequence02067e98(obj, b);
    if ((obj + 0x1000)[0x9cc] == 0 && flag3 == 1) {
        (obj + 0x1000)[0x9ae] = 0;
        (obj + 0x1000)[0x9af] = 0;
        (obj + 0x1000)[0x9cd] = 1;
        *(int*)(obj + 0x40) = 0;
        func_02044d0c(obj + 0x1000);
    }
    (obj + 0x1000)[0x9cc] = 0;
    (obj + 0x1000)[0x9ce] = 0;
    if (flag3 == 1) {
        (obj + 0x1000)[0x9cc] = 1;
    } else if (flag3 == 1) {
        (obj + 0x1000)[0x9ce] = 1;
    }
    if ((obj + 0x1000)[0x9cc] != 0) {
        (obj + 0x1000)[0x9cc] = 1;
        (obj + 0x1000)[0x9ae] = 0;
        (obj + 0x1000)[0x9af] = 0;
        (obj + 0x1000)[0x9cd] = 1;
        *(int*)(obj + 0x40) = 0;
    }
    if ((obj + 0x1000)[0x9ce] != 0) {
        *(int*)(obj + 0x44) = 0;
        PrepareEncodeStreamBuffer0204394c(*(struct Struct0204394c**)(obj + 0x1000 + 0xe28));
    }
    ((char*)obj)[0x30] = -1;
    ((char*)obj)[0x31] = -1;
}
