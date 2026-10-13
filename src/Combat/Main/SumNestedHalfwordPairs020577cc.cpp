#include <globaldefs.h>

struct Node020577cc {
    unsigned char pad[0x2c];
    unsigned char byte2c;
    unsigned char pad2[0x148 - 0x2c - 1];
    struct Node020577cc* next148;
};

struct Obj020577cc {
    unsigned char pad[0x34];
    struct Node020577cc* head34;
};

struct Outer02059c90;
void GetNestedHalfwordPair(struct Outer02059c90* obj, unsigned short* out0, unsigned short* out1);

// USA: func_020577cc
ARM void SumNestedHalfwordPairs020577cc(struct Obj020577cc* obj, unsigned short* out1, unsigned short* out2) {
    unsigned short sum1 = 0, sum2 = 0;
    struct Node020577cc* cur = obj->head34;
    while (cur != NULL) {
        if (cur->byte2c == 0) {
            cur = cur->next148;
            continue;
        }
        unsigned short local1 = 0, local2 = 0;
        GetNestedHalfwordPair((struct Outer02059c90*)cur, &local1, &local2);
        cur = cur->next148;
        sum1 = sum1 + local1;
        sum2 = sum2 + local2;
    }
    *out1 = sum1;
    *out2 = sum2;
}
