#include <globaldefs.h>


extern "C" int func_ov004_02153c74(void* a);
extern "C" int func_ov004_02154984(void* a);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void*);
extern "C" int func_ov023_021f98e0(void*, void*);
unsigned int GetShort28_021f9bb0(struct Obj021f9bb0* obj);
unsigned short GetField2a_021f9bc0(struct Obj021f9bc0* o);
unsigned int GetTableEntry_021f9b6c(struct Obj9b6c* obj, unsigned int a, unsigned int b);
void* GetLinkedNodeIfKind6_021f9cb8(void* unused, void* other, void* node);
extern "C" void func_ov023_021f88b8(void* obj, void* param1, int id);
extern "C" void func_ov004_02153e20(void*);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern struct Obj0205eaa0 data_02108760;

struct S7c021707c0 { char pad[0x7c]; unsigned char toggle; };
extern struct S7c021707c0* data_ov004_021707c0;

class VObj021549e4 {
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

struct ListHead_021e1da4 { void* first; };
short FindIndexByField8_021e1da4(struct ListHead_021e1da4* head, int val);

struct Obj021f9bdc;
void DivModField26_021f9bdc(struct Obj021f9bdc* o, int divisor);

struct Entry5c021549e4 {
    char pad[0x5c];
    short field5c;
    short field5e;
};

// USA: func_ov004_021549e4
// JPN: func_ov004_0215606c
extern "C" ARM int func_ov004_021549e4(void* a1) {
    void* r4 = (void*)func_ov004_02153c74(a1);
    if (!r4) return 0;

    data_ov004_021707c0->toggle++;
    data_ov004_021707c0->toggle &= 1;

    func_ov004_02154984(a1);

    void* base = func_ov011_021849c8(a1);
    void* node = func_ov023_021f6880(base, 0x39);
    if (!node) return 0;

    void* listHead = ((VObj021549e4*)node)->Methodec();
    if (!listHead) return 0;

    short idx = FindIndexByField8_021e1da4((struct ListHead_021e1da4*)listHead, *(short*)((char*)r4 + 0x18));
    if (idx < 0) return 0;

    void* base2 = func_ov011_021849c8(a1);
    void* node2 = func_ov023_021f6880(base2, 0x2c);
    if (!node2) return 0;
    if (func_ov023_021f6f10(node2) != 7) return 0;

    struct Entry5c021549e4* e = (struct Entry5c021549e4*)node2;
    short savedHi = e->field5e;
    e->field5c = (short)(idx / 16);
    e->field5e = savedHi;
    short remSigned = (short)(idx % 16);
    unsigned short remUnsigned = (unsigned short)remSigned;
    DivModField26_021f9bdc((struct Obj021f9bdc*)node2, remUnsigned);

    func_ov023_021f98e0(node2, a1);

    unsigned int v1 = GetShort28_021f9bb0((struct Obj021f9bb0*)node2);
    unsigned short v2 = GetField2a_021f9bc0((struct Obj021f9bc0*)node2);
    unsigned int entry = GetTableEntry_021f9b6c((struct Obj9b6c*)node2, v1, v2);

    void* base3 = func_ov011_021849c8(a1);
    void* node3 = func_ov023_021f6880(base3, entry);
    if (node3) {
        if (func_ov023_021f6f10(node3) == 8) {
            void* res = GetLinkedNodeIfKind6_021f9cb8(node2, a1, node3);
            if (res) {
                func_ov023_021f88b8(res, a1, 0x8000);
            }
        }
    }

    func_ov004_02153e20(a1);
    DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
    return 0;
}
