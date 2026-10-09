#include <globaldefs.h>

extern "C" void func_ov004_02153978(void* self, short* a, short* b, short* c);
extern "C" void func_ov023_021f645c(void* a, int b, unsigned short c, int d);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" void _Z22ClearElements_021e1518Pv(void* obj);
extern "C" void _Z24BuildLinkedList_021e1564Pviii(void* a, int b, int c, int d);
extern "C" void _Z19BuildChain_021e15b4Pviii(void* a, int b, int c, int d);

struct BattleState_0215482c {
    unsigned char pad[0x7c];
    unsigned char side;
};
struct MessagePair_0215482c {
    unsigned short ids[2];
};
extern BattleState_0215482c* data_ov004_021707c0;
extern const MessagePair_0215482c data_ov004_0216fa7c;

class VObj0215482c {
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
    virtual void* MethodEc();
};

// USA: func_ov004_0215482c
extern "C" ARM int func_ov004_0215482c(void* self) {
    short b, c, d;
    func_ov004_02153978(self, &b, &c, &d);

    unsigned short mode = 0x2c;
    if (b != 0) {
        if (d >= 0) {
            mode = d + 6;
        } else if (c >= 0) {
            mode = c + 0x11;
            if (c == 7) mode = 0x18;
        }
    }

    func_ov023_021f645c(self, 0x34, mode, 0xf);

    MessagePair_0215482c pair = data_ov004_0216fa7c;
    func_ov023_021f645c(self, 0x35, pair.ids[data_ov004_021707c0->side], 0xf);

    int flag = (data_ov004_021707c0->side == 0) ? 1 : 0;

    VObj0215482c* node = (VObj0215482c*)func_ov023_021f6880(func_ov011_021849c8(self), 0x39);
    if (node) {
        short d3, d2, d1;
        func_ov004_02153978(self, &d1, &d2, &d3);

        void* result = node->MethodEc();
        if (result) {
            _Z22ClearElements_021e1518Pv(result);
            if (flag) {
                _Z24BuildLinkedList_021e1564Pviii(result, d1, d2, d3);
            } else {
                _Z19BuildChain_021e15b4Pviii(result, d1, d2, d3);
            }
        }
    }
    return 0;
}
