#if defined(jpn)
#define R(j,u) (j)
#define _Z27ScaleStatsIfType12_021f6f10Pv func_ov023_021f6f10
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
#if defined(jpn)
#define ScaleStatsIfType12_021f6f10 func_ov023_021f6f10
extern "C" int ScaleStatsIfType12_021f6f10(void* self);
#else
int ScaleStatsIfType12_021f6f10(void* self);
#endif
extern "C" int func_ov004_021537a8(void* self, int key, int arg);
extern "C" int func_ov023_021e1de8(void* obj, int value, int id, int idx);

class VObj02154e64 {
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
    virtual void* MethodEC();
};
extern "C" VObj02154e64* func_ov023_021f6880(void*, int);

// USA: func_ov004_02154e64  (semantic: DispatchSevenBuffEntries_02154e64)
extern "C" ARM int func_ov004_02154e64(void* a1) {
    VObj02154e64* obj = func_ov023_021f6880(func_ov011_021849c8(a1), 0x39);
    if (!obj) return 0;
    if (ScaleStatsIfType12_021f6f10(obj) != 0x12) return 0;
    void* r = obj->MethodEC();
    if (!obj) return 0;
    unsigned short key = 0x1a;
    short j = 1;
    for (; j <= 7; key++, j++) {
        if (func_ov023_021e1de8(r, -1, j, -1) == 0) {
            func_ov004_021537a8(a1, key, 0);
        }
    }
    return 0;
}
