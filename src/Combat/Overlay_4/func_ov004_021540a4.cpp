#include <globaldefs.h>


extern "C" void func_ov004_02153978(void* self, short* a, short* b, short* c);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
extern "C" int func_ov023_021f6f10(void* self);
#else
int ScaleStatsIfType12_021f6f10(void* self);
#endif
extern "C" int func_ov023_021e1de8(void* obj, int value, int id, int idx);
extern "C" void func_ov023_021f65d4(void* obj, int id, int mask);
void ClearNodeMaskById_021f6600(void* obj, int id, int mask);

class VObj021540a4 {
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

// USA: func_ov004_021540a4
// JPN: func_ov004_0215575c
extern "C" ARM int func_ov004_021540a4(void* a) {
    short e0, e1, e2;
    func_ov004_02153978(a, &e0, &e1, &e2);

    void* battler = func_ov011_021849c8(a);
    void* n = func_ov023_021f6880(battler, 0x39);
    if (!n) return 0;
#if defined(jpn)
    if (func_ov023_021f6f10(n) != 0x12) return 0;
#else
    if (ScaleStatsIfType12_021f6f10(n) != 0x12) return 0;
#endif

    void* result = ((VObj021540a4*)n)->Methodec();
    if (!n) return 0;

    int ret = func_ov023_021e1de8(result, e0, e1, e2);
    short r4val = (short)((ret + 15) / 16);

    if (ret == 0) {
        func_ov023_021f65d4(a, 0xa, 8);
        ClearNodeMaskById_021f6600(a, 3, 4);
        for (unsigned short id = 0x1a, i = 0; i < 0x10; id++, i++) {
            void* b2 = func_ov011_021849c8(a);
            void* node = func_ov023_021f6880(b2, id);
            if (node) *((unsigned char*)node + 0xc) |= 8;
        }
        void* b3 = func_ov011_021849c8(a);
        void* node2 = func_ov023_021f6880(b3, 0x3a);
        if (node2) *((unsigned char*)node2 + 0xc) &= ~8;
    } else {
        ClearNodeMaskById_021f6600(a, 0xa, 8);
        func_ov023_021f65d4(a, 0x3a, 8);
    }

    void* b4 = func_ov011_021849c8(a);
    void* n2 = func_ov023_021f6880(b4, 0x2c);
    if (!n2) return 0;
#if defined(jpn)
    if (func_ov023_021f6f10(n2) != 7) return 0;
#else
    if (ScaleStatsIfType12_021f6f10(n2) != 7) return 0;
#endif
    *(short*)((char*)n2 + 0x5c) = 0;
    *(short*)((char*)n2 + 0x5e) = r4val;
    return 0;
}
