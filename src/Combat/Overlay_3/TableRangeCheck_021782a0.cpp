#include <globaldefs.h>

struct Obj2081;
struct Elem2081;
void SelectCoordsByFlag0x24(unsigned char* p, int* a, int* b);
struct Elem2081* FindElementByByte0xc4(struct Obj2081* obj, int id);
int IsField0x9cEqual3(unsigned char* p);
void FindTableEntryPayload_02173f08(char* a, char* b, char* c, char* d);

extern unsigned char data_02114e54[];

// USA: func_ov003_021782a0  (semantic: TableRangeCheck_021782a0)
extern "C" ARM int func_ov003_021782a0(struct Obj2081* obj) {
    if (data_02114e54[0x5f] == 0 || *(unsigned short*)(data_02114e54 + 0x24) == 0)
        return 0;

    int coordA, coordB;
    SelectCoordsByFlag0x24(data_02114e54, &coordA, &coordB);
    if (coordB < 0x5d || coordB > 0x6e)
        return 0;

#if defined(jpn)
    if (coordA >= 0x8c && coordA <= 0xb7)
        return 1;
    if (coordA >= 0xc8 && coordA <= 0xf0)
        return -1;
    return 0;
#else
    struct Obj2081* target = *(struct Obj2081**)((char*)obj + 0x89c);
    struct Elem2081* elem = FindElementByByte0xc4(target, 10);
    if (!elem)
        return 0;
    if (!IsField0x9cEqual3((unsigned char*)elem))
        return 0;

    char c0, c1, c2, c3;
    FindTableEntryPayload_02173f08(&c0, &c1, &c2, &c3);

    short h = *(short*)((char*)elem + 0xac);
    short x1 = c0 + (short)(h << 3);
    short x2 = c1 + (short)(h << 3);
    short y1 = c2 + x1;
    short y2 = c3 + x2;

    int point = coordA;
    if (point >= x1) {
        if (point <= y1)
            return 1;
    }
    if (x1 <= point && point <= y2)
        return -1;
    return 0;
#endif
}
