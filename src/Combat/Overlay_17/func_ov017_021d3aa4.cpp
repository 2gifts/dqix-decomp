// JPN: func_ov017_021d3ef4
#if defined(jpn)
enum { RegionOffsetb28 = 0x908 };
#else
enum { RegionOffsetb28 = 0xb28 };
#endif

#include <globaldefs.h>

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
extern "C" void func_0208e0a8(void);
extern "C" int func_0202c508(void* obj);
ARM int* GetNegativeEntry(char* obj, int index);
extern "C" void _Z27EnqueueEventTag183_021d38f8hhhhPi(unsigned char a0, signed char a1, unsigned char a2, unsigned char a3, int* p);
extern "C" int func_ov017_021d3950(void* p);

struct Evt021d3aa4 {
    unsigned char pad0[4];
    unsigned char mode;
    signed char idx;
    unsigned char field6;
    unsigned char field7;
    int field8;
};

// USA: func_ov017_021d3aa4
extern "C" ARM void func_ov017_021d3aa4(int p0, struct Evt021d3aa4* evt, char* buf, int table, struct SearchStruct0202c1a4* search) {
    func_0208e0a8();
    unsigned char* entryObj = *(unsigned char**)((char*)table + 0x3000 + RegionOffsetb28);

    if (func_0202c508(search)) {
        if (evt->mode != 1) return;

        if (func_ov017_021d3950(&evt->mode) != 0) {
            _Z27EnqueueEventTag183_021d38f8hhhhPi(1, p0, evt->field6, evt->field7, &evt->field8);
        } else {
            _Z27EnqueueEventTag183_021d38f8hhhhPi(2, p0, evt->field6, evt->field7, &evt->field8);
        }
        return;
    }

    if (p0 != 0) return;

    if (evt->mode == 0) {
        int* e = GetNegativeEntry(buf, evt->field7);
        if (e) *e = evt->field8;
    } else if (evt->mode == 1) {
        signed char cur = GetSearchStructCurrentArrEntry(search);
        if (evt->idx == cur) {
            if (entryObj[2] != 0) entryObj[9] = 1;
        }
        func_ov017_021d3950(&evt->mode);
    } else if (evt->mode == 2) {
        signed char cur = GetSearchStructCurrentArrEntry(search);
        if (evt->idx == cur) {
            entryObj[9] = 2;
        }
    }
}
