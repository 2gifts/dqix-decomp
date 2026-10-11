#include <globaldefs.h>

extern "C" int func_ov004_0215513c(void*, short*, short*, short*);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
extern "C" int func_ov023_021f6f10(void* self);
#else
int ScaleStatsIfType12_021f6f10(void* self);
#endif
extern "C" int func_ov023_021e1f0c(int a, short b, short c, short d);
extern "C" void func_ov023_021f65d4(void* obj, int id, int mask);
void ClearNodeMaskById_021f6600(void* obj, int id, int mask);
extern "C" void _Z25SetFields5cAnd5e_021f65b4PvS_tt(void* a, void* b, short v1, short v2);

class VObj021555b0 {
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
    virtual int Methodec();
};

// USA: func_ov004_021555b0  (semantic: UpdateStatusHistoryEntry_021555b0)
extern "C" ARM int func_ov004_021555b0(void* a) {
    short b, c, d;
    func_ov004_0215513c(a, &b, &c, &d);

    void* base = func_ov011_021849c8(a);
    void* node = func_ov023_021f6880(base, 0x39);
    if (!node) return 0;
#if defined(jpn)
    if (func_ov023_021f6f10(node) != 0x12) return 0;
#else
    if (ScaleStatsIfType12_021f6f10(node) != 0x12) return 0;
#endif

    int vresult = ((VObj021555b0*)node)->Methodec();
    if (!node) return 0;

    int result = func_ov023_021e1f0c(vresult, b, c, d);
    short v = (result + 15) / 16;

    if (result == 0) {
        func_ov023_021f65d4(a, 0xa, 8);
        ClearNodeMaskById_021f6600(a, 3, 4);
        unsigned short i = 0x1a, j = 0;
        for (; j < 0x10; i++, j++) {
            func_ov023_021f65d4(a, i, 8);
        }
        ClearNodeMaskById_021f6600(a, 0x3a, 8);
    } else {
        func_ov023_021f65d4(a, 0x3a, 8);
    }

    _Z25SetFields5cAnd5e_021f65b4PvS_tt(a, (void*)0x2c, 0, v);
    return 0;
}
