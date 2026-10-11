#include <globaldefs.h>

struct Vec3 {
    int x;
    int y;
    int z;
};
extern "C" void Vector3fix_Add(struct Vec3* a, struct Vec3* b, struct Vec3* out);

struct Obj_02184a18;
unsigned short GetShortField1b2_02184a18(struct Obj_02184a18* obj);

extern "C" void* func_ov011_021849c8(void* obj);
extern "C" void func_ov011_02184a40(void* a, int b);

extern "C" void* func_ov023_021f6880(void* base, int key);
extern "C" int func_ov023_021f9bc8(void* obj);
extern "C" unsigned short func_ov023_021f6f10(void* obj);
extern "C" struct Vec3 func_ov023_021f8b78(void* src, void* arg2);

class NodeY98e0 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual struct Vec3 GetVecA();
    virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12();
    virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16();
    virtual void v17(); virtual void v18(); virtual void v19();
    virtual int GetCount();
    virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28();
    virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32();
    virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36();
    virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40();
    virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44();
    virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48();
    virtual void v49(); virtual void v50();
    virtual struct Vec3 GetVecB();
};

class NodeX98e0 {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06();
    virtual void SetVec(struct Vec3* v);
};

// USA: func_ov023_021f98e0  (semantic: AccumulateNodeVecByMode_021f98e0)
extern "C" ARM void func_ov023_021f98e0(void* a, void* b) {
    unsigned short call1 = GetShortField1b2_02184a18((struct Obj_02184a18*)b);
    void* call2 = func_ov011_021849c8(b);
    NodeX98e0* nodeX = (NodeX98e0*)func_ov023_021f6880(call2, call1);

    unsigned short arrVal = (*(unsigned short**)((char*)a + 0x20))[func_ov023_021f9bc8(a)];
    NodeY98e0* nodeY = (NodeY98e0*)func_ov023_021f6880(call2, arrVal);

    if (nodeX != 0 && nodeY != 0) {
        if (func_ov023_021f6f10(nodeY) == 0) {
            struct Vec3 acc = nodeY->GetVecA();
            struct Vec3 vecB = nodeY->GetVecB();
            Vector3fix_Add(&acc, (struct Vec3*)((char*)a + 0x2c), &acc);
            Vector3fix_Add(&acc, &vecB, &acc);
            nodeX->SetVec(&acc);
        } else if (func_ov023_021f6f10(nodeY) == 8) {
            struct Vec3 acc = func_ov023_021f8b78(nodeY, b);
            struct Vec3 vecB = nodeY->GetVecB();
            Vector3fix_Add(&acc, (struct Vec3*)((char*)a + 0x2c), &acc);
            Vector3fix_Add(&acc, &vecB, &acc);
            nodeX->SetVec(&acc);
        } else if (func_ov023_021f6f10(nodeY) == 1) {
            struct Vec3 acc = nodeY->GetVecA();
            struct Vec3 vecB = nodeY->GetVecB();
            Vector3fix_Add(&acc, (struct Vec3*)((char*)a + 0x2c), &acc);
            Vector3fix_Add(&acc, &vecB, &acc);
            nodeX->SetVec(&acc);
        }

        int count = nodeY->GetCount();
        if (count > 0) {
            func_ov011_02184a40(b, count);
        }
    }

    *(int*)((char*)a + 0x38) = 0;
}
