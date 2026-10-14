#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"

struct Variant02030b0c {
    int tag;
    union {
        int i;
        float f;
    } u;
};

extern "C" void* func_0205ec34(void);

struct PackedNibbleArray0206e120 {
    unsigned char pad[0x2CC];
    unsigned char bits[1];
};
int GetPackedNibbleField(struct PackedNibbleArray0206e120* obj, int index);

extern "C" void func_0205ec70(SafeAllocator* alloc, int limit, struct Variant02030b0c* arr, void* dst8, void* dstc);

struct Owner020958fc { unsigned char pad[0xa0]; void* slot; };
struct Node020958fc {
    unsigned short f0;
    unsigned short bits2 : 9;
    unsigned short bit9  : 1;
    unsigned short bit10 : 1;
    unsigned short bit11 : 1;
    unsigned short bit12 : 1;
    unsigned short bit13 : 1;
    unsigned short pad2  : 2;
    unsigned int   bits4a : 8;
    unsigned int   bits4b : 6;
    unsigned int   bits4c : 5;
    unsigned int   pad4   : 13;
    int f8;
    void* link;
};
void SetSlotA0(struct Owner020958fc* owner, struct Node020958fc* node);

struct Manager02109404 { unsigned char pad[0xc]; SafeAllocator* alloc; };
extern Manager02109404 data_02109404;
extern Owner020958fc data_02109418;

// USA: func_02094fe4
extern "C" ARM int func_02094fe4(struct Variant02030b0c* arr, int b) {
    int p0 = ((Script::Parameter*)&arr[0])->ToInt();
    int p1 = ((Script::Parameter*)&arr[1])->ToInt();
    int p2 = ((Script::Parameter*)&arr[2])->ToInt();
    int p3 = ((Script::Parameter*)&arr[3])->ToInt();
    int p4 = ((Script::Parameter*)&arr[4])->ToInt();
    int p5 = ((Script::Parameter*)&arr[5])->ToInt();
    void* nibbles = func_0205ec34();
    int p6 = ((Script::Parameter*)&arr[6])->ToInt();
    if (p6 >= 0) {
        int ok = (GetPackedNibbleField((struct PackedNibbleArray0206e120*)nibbles, p6) == 3);
        if (ok == 0) {
            return 0;
        }
    }

    struct Node020958fc* node = (struct Node020958fc*)data_02109404.alloc->Allocate(0x10);
    node->f0 = p1;
    node->bits2 = p0;
    node->bits4a = p2;
    node->bits4b = p3;
    node->bits4c = p4;
    node->bit9 = p5;

    int p7 = ((Script::Parameter*)&arr[7])->ToInt();
    node->bit11 = p7;
    int p8 = ((Script::Parameter*)&arr[8])->ToInt();
    node->bit10 = p8;
    int p9 = ((Script::Parameter*)&arr[9])->ToInt();
    node->bit12 = p9;
    int p10 = ((Script::Parameter*)&arr[10])->ToInt();
    node->bit13 = p10;

    node->f8 = 0;
    node->link = 0;

    int local8 = 0;
    func_0205ec70(data_02109404.alloc, b - 0xb, &arr[11], &node->f8, &local8);

    SetSlotA0(&data_02109418, node);
    return 1;
}
