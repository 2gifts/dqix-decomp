#include <globaldefs.h>

class VNode021f6a1c {
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
    virtual void v40(); virtual void v41();
    virtual int MethodA8();
    virtual void v43(); virtual void v44(); virtual void v45();
    virtual int MethodB8();

    char pad4[0x18 - 4];
    VNode021f6a1c* next;
};

struct ListHead021f6a1c {
    VNode021f6a1c* head;
};

extern unsigned char data_02114e54;
void SelectCoordsByFlag0x24_02012a84(unsigned char* obj, int* out1, int* out2);
extern "C" void func_ov011_02184a40(void* a, int b);

// USA: func_ov023_021f6a1c  (semantic: IterateNodesAndDispatch_021f6a1c)
extern "C" ARM void func_ov023_021f6a1c(struct ListHead021f6a1c* obj, void* arg1) {
    if (*(unsigned char*)(&data_02114e54 + 0x55) == 0) {
        return;
    }

    int a, b;
    SelectCoordsByFlag0x24_02012a84(&data_02114e54, &a, &b);

    VNode021f6a1c* node = obj->head;
    while (node != NULL) {
        if (node->MethodB8() != 0) {
            int v = node->MethodA8();
            if (v > 0) {
                v = node->MethodA8();
                func_ov011_02184a40(arg1, v);
                return;
            }
        }
        node = node->next;
    }
}
