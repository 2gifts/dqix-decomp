#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);

struct CheckField0AndGlobalHalfStruct0202c508 { int field0; };
extern "C" int func_0202c508(CheckField0AndGlobalHalfStruct0202c508* obj);

struct Entry020e3054 { unsigned char f0; unsigned char f1; unsigned char f2; unsigned char f3; };
struct Entry020e30a4 { unsigned char f0; unsigned char f1; unsigned char f2; unsigned char f3; };
Entry020e3054* FindEntryByField1(Entry020e3054* list, int key);
Entry020e30a4* FindEntryWithField2Zero(Entry020e30a4* list);

struct Bytes020e303c { unsigned char f0; unsigned char f1; unsigned char f2; unsigned char f3; };
void ClearFourBytes020e303c(Bytes020e303c* s);

void EnqueueEventTag51_021ceae4(unsigned char a, unsigned char b, unsigned char c);

// USA: func_020e321c  (semantic: ProcessCombatantTagEntry_020e321c)
extern "C" ARM void func_020e321c(Entry020e3054* a, int b, unsigned char c) {
    int* g = (int*)func_0202ae18();
    if (!CheckField0NonZero_0202b7d8(g)) return;

    if (func_0202c508((CheckField0AndGlobalHalfStruct0202c508*)g)) {
        unsigned char tag = 0;
        Entry020e3054* e = FindEntryByField1(a, b);
        if (e && e->f2 == 1 && e->f0 == c) return;

        if (!e || e->f2 == 0) {
            if (!e) {
                e = (Entry020e3054*)FindEntryWithField2Zero((Entry020e30a4*)a);
            }
            if (e) {
                ClearFourBytes020e303c((Bytes020e303c*)e);
                e->f1 = (unsigned char)b;
                tag = 1;
                e->f2 = tag;
                e->f0 = c;
            }
        }

        if (c == 0) return;
        EnqueueEventTag51_021ceae4(tag, b, c);
    } else {
        EnqueueEventTag51_021ceae4(1, b, c);
        Entry020e3054* e = FindEntryByField1(a, b);
        if (!e) {
            e = (Entry020e3054*)FindEntryWithField2Zero((Entry020e30a4*)a);
        }
        ClearFourBytes020e303c((Bytes020e303c*)e);
        e->f1 = (unsigned char)b;
        e->f2 = 2;
        e->f0 = c;
    }
}
