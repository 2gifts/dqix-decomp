#include <globaldefs.h>
#if defined(jpn)
enum { kPrefix = 0x17e2 };
#else
enum { kPrefix = 0x19b2 };
#endif
void ForwardToTargetOrDefault0205eabc(void*, void*, int);

extern int data_02108760;
extern int data_02107820;

struct State02045688 {
    unsigned char pad[kPrefix];
    unsigned char f19b2;
    unsigned char f19b3;
};

// USA: func_02045688
ARM void ProcessPendingFlag02045688(struct State02045688* obj) {
    if (obj->f19b3 != 0 && obj->f19b2 != 0) {
        ForwardToTargetOrDefault0205eabc((void*)(&data_02108760), (void*)(&data_02107820), (int)(0));
        obj->f19b3 = 0;
    }
}
