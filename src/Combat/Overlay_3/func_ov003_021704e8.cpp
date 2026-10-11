#include <globaldefs.h>

#if defined(jpn)
#define func_ov003_021704e8 func_ov003_0216fd3c
#endif

struct Container0205a3d0;
struct Elem0205a3d0;
struct Obj0216dee4;

extern "C" void func_ov003_021705d4(void* obj, short* out1, short* out2);
void SetElemFields0216dee4(struct Obj0216dee4* obj, int idx, int v14, int v18, int v22, int v25, int v26);
Elem0205a3d0* FindEntryByHalfword0205a3d0(Container0205a3d0* c, int key);
void ComputeValues_0217063c(unsigned char* obj, unsigned short* out1, unsigned short* out2);

// USA: func_ov003_021704e8  (semantic: RefreshElementIcons_021704e8)
extern "C" ARM void func_ov003_021704e8(char* obj) {
    Container0205a3d0* cont = *(Container0205a3d0**)(obj + 0xa4);
    if (cont == NULL) return;

    short a, b;
    func_ov003_021705d4(obj, &a, &b);
    if (a != 0 && b != 0) {
        SetElemFields0216dee4((struct Obj0216dee4*)(obj + 0x68), 8, a, b, -1, 1, 3);
    } else {
        Elem0205a3d0* e = FindEntryByHalfword0205a3d0(cont, 2);
        if (e != NULL) {
            *(unsigned char*)((char*)e + 0x15) &= ~8;
        }
    }

    short c, d;
    ComputeValues_0217063c((unsigned char*)obj, (unsigned short*)&c, (unsigned short*)&d);
    if (c != 0 && d != 0) {
        SetElemFields0216dee4((struct Obj0216dee4*)(obj + 0x68), 8, c, d, -1, 1, 3);
    } else {
        Elem0205a3d0* e = FindEntryByHalfword0205a3d0(cont, 3);
        if (e != NULL) {
            *(unsigned char*)((char*)e + 0x15) &= ~8;
        }
    }
}
