#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>

extern "C" void* func_ov004_02156f04(void* a, int key);
extern "C" void* func_ov004_02156f6c(void*, int);
extern "C" void func_ov023_021f8240(void*, void*);
extern "C" void func_ov011_021848a0(void*, int);

class VObj0215c1ac {
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
    virtual void v52(); virtual void v53();
    virtual void Dispatch54(int n);
};

// USA: func_ov004_0215c1ac  (semantic: ClearFlagAndDispatchAll_0215c1ac)
extern "C" ARM int func_ov004_0215c1ac(void* obj) {
    for (int i = 0; i < 8; i++) {
        void* node = func_ov004_02156f04(obj, i + 0x44c);
        *(unsigned char*)((char*)node + 0x45) &= ~1;
        ((VObj0215c1ac*)node)->Dispatch54(0xf);
    }
    void* node2 = func_ov004_02156f6c(obj, 0x17);
    if (node2) {
        func_ov023_021f8240(node2, obj);
    }
    func_ov011_021848a0(obj, 0x6b);
    return 0;
}
