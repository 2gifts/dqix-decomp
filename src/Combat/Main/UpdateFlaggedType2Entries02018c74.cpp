#include <globaldefs.h>

#if defined(jpn)
enum { kFlagOffset = 0x285e };
#else
enum { kFlagOffset = 0x281e };
#endif


extern "C" void* func_0205ec34(void);
void* FindNthType2Entry02018c20(unsigned char* obj, int n);
extern "C" void func_02018300(void*, void*, int, int, int);

struct Flags2eRec02018c74 {
    unsigned short field0 : 4;
    unsigned short field1 : 12;
};

// USA: func_02018c74
ARM void UpdateFlaggedType2Entries02018c74(unsigned char* obj, unsigned int flags)
{
    func_0205ec34();
    int i;
    for (i = 0; i < 16; i++) {
        if (flags & (1 << i)) {
            unsigned char* record = (unsigned char*)FindNthType2Entry02018c20(obj, i);
            if (record) {
                struct Flags2eRec02018c74* f = (struct Flags2eRec02018c74*)(record + 0x2e);
                if (!(f->field1 & 8)) {
                    f->field1 = f->field1 | 0x101;
                }
                func_02018300(obj, record, 0, 0, 0);
            }
        }
    }
    obj[kFlagOffset] = 0;
}
