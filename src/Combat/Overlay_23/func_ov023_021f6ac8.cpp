#include <globaldefs.h>

extern "C" void* func_ov023_021f6880(void** list, int value);
extern "C" void func_ov011_021848a0(void* obj, int val);
extern "C" void func_ov011_02184a40(void* a, int b);

extern unsigned char data_02114e54;

struct Elem021f6ac8 {
    unsigned char count;
    char pad1;
    unsigned short vals[8];
    short f12;
    short f14;
};

struct Obj021f6ac8 {
    char pad0[0x30];
    Elem021f6ac8 array[3];
};

class VNode021f6ac8 {
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
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
#if defined(jpn)
    virtual void v60();
#else
    virtual void v60(); virtual void v61();
#endif
    virtual int MethodF8();
};

// JPN: func_ov023_021f6004
// USA: func_ov023_021f6ac8
extern "C" ARM int func_ov023_021f6ac8(void* obj, void* arg1) {
    if (*(unsigned char*)(&data_02114e54 + 0x55) != 0) {
        struct Obj021f6ac8* o = (struct Obj021f6ac8*)obj;
        int j;
        for (j = 0; j < 3; j++) {
            struct Elem021f6ac8* elem = &o->array[j];
            if (elem->count == 0) continue;

            int found = 0;
            int k;
            for (k = 0; k < elem->count && !found; k++) {
                void* node = func_ov023_021f6880((void**)obj, elem->vals[k]);
                if (node != 0) {
                    VNode021f6ac8* v = (VNode021f6ac8*)node;
                    if (v->MethodF8() != 0) {
                        found = 1;
                    }
                }
            }

            if (found) continue;

            if (elem->f12 > 0) func_ov011_021848a0(arg1, elem->f12);
            if (elem->f14 > 0) func_ov011_02184a40(arg1, elem->f14);
            return 1;
        }
    }
    return 0;
}
