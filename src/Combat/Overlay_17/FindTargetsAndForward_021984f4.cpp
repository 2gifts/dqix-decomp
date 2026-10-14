#if defined(jpn)
enum { RegionOffset6c = 0x8c };
#else
enum { RegionOffset6c = 0x6c };
#endif

#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"

extern "C" void* func_02012fe4(void);
void* GetPointerFromArray0x3c_0201e838(unsigned char* obj, unsigned int index);
int CheckSubstructByte0x7cPositive_020535c8(signed char* obj);
extern "C" int func_02094b9c(void* a, void* b);
int fix32ReduceAngle0To2Pi(int angle);
int fix32SignedAngleDistance(int a, int b);
int fix32abs(int x);
void InitObj0219a674(unsigned char* self);
void BuildAndForwardVec_0218da48(void* obj, int angle, int c, int d, unsigned char e);
extern "C" void func_ov017_0219b33c(void* obj, void* eventBuf);

struct TargetNode021984f4 {
    unsigned char pad0[0x20];
    short angle;
    unsigned char pad1[0x70 - 0x22];
    struct TargetNode021984f4* next;
};

struct FilterData021984f4 {
    int a, b, c;
};

struct EventBuf021984f4 {
    unsigned char tag;
    unsigned char pad1;
    unsigned short pad2;
    unsigned char flag;
    unsigned char pad3[3];
    void* ptr;
    int pad4;
    unsigned short pad5;
    unsigned short pad6;
};

// USA: func_ov017_021984f4  (semantic: FindTargetsAndForward_021984f4)
extern "C" ARM void func_ov017_021984f4(void* obj) {
    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetUnknownGameObject();
    if (c == NULL) {
        return;
    }
    if (CheckSubstructByte0x7cPositive_020535c8((signed char*)c) != 0) {
        return;
    }

    void* cache = func_02012fe4();
    GetField0x3b0Value_020100bc(bs);
    struct TargetNode021984f4* node = (struct TargetNode021984f4*)GetPointerFromArray0x3c_0201e838((unsigned char*)cache + RegionOffset6c, 8);

    struct FilterData021984f4 filter = *(struct FilterData021984f4*)((char*)c + 0x44);
    int best = 0x270f000;
    unsigned char flag = 1;
    unsigned char idx = 0;
    while (node != NULL) {
        if (func_02094b9c(node, &filter) != 0) {
            int angle = (short)fix32ReduceAngle0To2Pi(node->angle + 0x3244);
            BuildAndForwardVec_0218da48(obj, angle, 0xccc, -819, idx);
            int delta = fix32abs(fix32SignedAngleDistance(*(int*)((char*)c + 0x54), node->angle));
            if ((float)delta < 8364.19921875f) {
                if (delta < best) {
                    best = delta;
                    struct EventBuf021984f4 buf;
                    InitObj0219a674((unsigned char*)&buf);
                    buf.tag = 6;
                    buf.flag = flag;
                    buf.ptr = node;
                    func_ov017_0219b33c(obj, &buf);
                }
            }
        }
        node = node->next;
    }
}
