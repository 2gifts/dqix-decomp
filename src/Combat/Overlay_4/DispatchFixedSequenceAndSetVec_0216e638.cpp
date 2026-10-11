#include <globaldefs.h>
#if defined(jpn)
enum { stateByteOffset = 0x7fb, clearPointerOffset = 0xc, readyFlagIndex = 0 };
#else
enum { stateByteOffset = 0x9ca, clearPointerOffset = 0x10, readyFlagIndex = 2 };
#endif
#include "GameState/GameState.h"

int GetGlobalField0x1c020421a0(void);
void SetByte0x7f70(void* obj, unsigned char value);

struct Struct020a9ea4;
void ClearStruct020a9ea4(struct Struct020a9ea4* p);
extern unsigned char data_ov004_02171034;

extern "C" void* func_ov011_021849c8(void*);
extern "C" void func_ov004_0216afb0(void* a1, int p2, int p3, int p4,
    int p5, int p6, int p7, int p8, unsigned char p9);
extern "C" int func_ov004_0216b2c8(void* obj, int id, int a, int b);

extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
extern "C" int func_ov023_021f6f10(void* self);
#else
int ScaleStatsIfType12_021f6f10(void* self);
#endif
void* GetFieldPtrAt_021f79e4_021f79e4(void* obj);
struct Obj0204b5e8;
int DispatchViaTable0204b5e8(struct Obj0204b5e8* obj, int a, int b);

struct Vec3_0216e638 { int x, y, z; };
class VObj0216e638 {
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
    virtual void v48(); virtual void v49();
    virtual void SetVec(Vec3_0216e638*);
    virtual Vec3_0216e638 GetVec();
};

extern "C" int func_ov004_0216b7bc(void* obj, int a, int b, int c);
struct Obj0205eaa0;
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
extern unsigned char data_02108760;

// USA: func_ov004_0216e638  (semantic: DispatchFixedSequenceAndSetVec_0216e638)
extern "C" ARM int func_ov004_0216e638(void* a) {
    void* self = a;
    *(unsigned char*)((char*)GetGlobalField0x1c020421a0() + 0x1000 + stateByteOffset) = 0;
    SetByte0x7f70(GameState::GetInstance(), 0);

    ClearStruct020a9ea4(*(struct Struct020a9ea4**)((char*)&data_ov004_02171034 + clearPointerOffset));
    (&data_ov004_02171034)[readyFlagIndex] = 1;

    func_ov004_0216afb0(self, 0x4b0, 2, 0x3e8, 0x23, 0xc, 5, 0xa, 1);
    func_ov004_0216afb0(self, 0x4b1, 2, 0x3e8, 0x35, 0xc, 0x11, 0xa, 1);

    for (int i = 0; i < 2; i = i + 1) {
        func_ov004_0216b2c8(self, 0x44c, i + 0x4b0, i);
    }

    void* node = func_ov011_021849c8(self);
    for (int j = 0; j < 2; j = j + 1) {
        void* n1 = func_ov023_021f6880(node, j + 0x65);
        if (!n1) continue;
#if defined(jpn)
        if (func_ov023_021f6f10(n1) != 2) continue;
#else
        if (ScaleStatsIfType12_021f6f10(n1) != 2) continue;
#endif
        DispatchViaTable0204b5e8((struct Obj0204b5e8*)GetFieldPtrAt_021f79e4_021f79e4(n1), 2, 4);

        void* n2 = func_ov023_021f6880(node, j + 0x4b0);
        if (!n2) continue;
#if defined(jpn)
        if (func_ov023_021f6f10(n2) != 8) continue;
#else
        if (ScaleStatsIfType12_021f6f10(n2) != 8) continue;
#endif

        Vec3_0216e638 v = ((VObj0216e638*)n2)->GetVec();
        v.x = v.x - 0x2000;
        v.y = v.y - 0x4000;
        ((VObj0216e638*)n2)->SetVec(&v);

        *(short*)((char*)n2 + 0x30) = -2;
        *(short*)((char*)n2 + 0x32) = -4;
    }

    func_ov004_0216b7bc(self, 0x3e8, 0x60, 0);
    DispatchWithShortB4_0205eaa0((struct Obj0205eaa0*)&data_02108760, 5, 0);
    return 0;
}
