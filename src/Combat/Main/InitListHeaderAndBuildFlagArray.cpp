#include <globaldefs.h>

#if defined(jpn)
#define data_020f1c74 data_020f1de0
#endif

extern int data_020f1c74;

extern "C" void func_020ca390(int val, void* dst, unsigned int nBytes);

struct AnimationData;
struct NSBXXInternalModel;

// USA: func_020b7840
ARM void InitializeModelAnimationFromJAC(AnimationData* p0, void* p1, NSBXXInternalModel* p2) {
    unsigned char byteVal;
    unsigned int i;
    unsigned short* arr;

    *(void**)((char*)p0 + 0x8) = p1;
    *(int*)((char*)p0 + 0xc) = data_020f1c74;
    byteVal = ((unsigned char*)p2)[0x17];
    *(unsigned char*)((char*)p0 + 0x19) = byteVal;
    func_020ca390(0, (char*)p0 + 0x1a, byteVal << 1);

    i = 0;
    arr = (unsigned short*)((char*)p1 + 0x14);
    if (i < *(unsigned short*)((char*)p1 + 0x6)) {
        do {
            unsigned short idx = arr[i];
            unsigned int val = *(unsigned int*)((char*)p1 + idx);
            *(unsigned short*)((char*)p0 + 0x1a + i * 2) = (unsigned short)((val >> 0x18) | 0x100);
            i++;
        } while (i < *(unsigned short*)((char*)p1 + 0x6));
    }
}
