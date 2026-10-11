#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
extern "C" int func_ov023_021f6f10(void* self);
#else
int ScaleStatsIfType12_021f6f10(void* self);
#endif
extern "C" int func_ov004_0215513c(void*, short*, short*, short*);
extern "C" int func_ov023_021f9bc8(char* obj);

struct ListNode02153978 { struct ListNode02153978* next; int field4; };

class VObj021551a8 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58();
    virtual void* Methodec();
};

// USA: func_ov004_021551a8  (semantic: CheckStatusHistoryEntry_021551a8)
extern "C" ARM int func_ov004_021551a8(void* a) {
    void* battler = func_ov011_021849c8(a);
    void* n1 = func_ov023_021f6880(battler, 0x2c);
    if (!n1) return 0;
#if defined(jpn)
    if (func_ov023_021f6f10(n1) != 7) return 0;
#else
    if (ScaleStatsIfType12_021f6f10(n1) != 7) return 0;
#endif

    short base = *(short*)((char*)n1 + 0x5c);
    short b, c, d;
    func_ov004_0215513c(a, &b, &c, &d);
    int target = func_ov023_021f9bc8((char*)n1) + (base << 4);

    void* n2 = func_ov023_021f6880(battler, 0x2d);
    if (!n2) return 0;
#if defined(jpn)
    if (func_ov023_021f6f10(n2) != 0x11) return 0;
#else
    if (ScaleStatsIfType12_021f6f10(n2) != 0x11) return 0;
#endif

    void* n3 = func_ov023_021f6880(battler, 0x39);
    if (!n3) return 0;
#if defined(jpn)
    if (func_ov023_021f6f10(n3) != 0x12) return 0;
#else
    if (ScaleStatsIfType12_021f6f10(n3) != 0x12) return 0;
#endif

    void* result = ((VObj021551a8*)n3)->Methodec();
    if (!result) return 0;

    struct ListNode02153978* node = *(struct ListNode02153978**)result;
    if (!node) return 0;
    short idx = 0;
    while (node != 0) {
        if (idx == target) break;
        idx++;
        node = node->next;
    }
    return node ? node->field4 : 0;
}
