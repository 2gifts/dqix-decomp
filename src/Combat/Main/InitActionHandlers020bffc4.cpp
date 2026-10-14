#include <globaldefs.h>

int GetListEntryWord8020bd8ac(unsigned int index);

struct Obj020c0044;
int InitStreamFromEntry020c0044(struct Obj020c0044 *obj, unsigned int index);
void *CallFunc020cca80AtField0x5c_020c00b8(void *obj);
struct Obj020c00c8;
int AdjustDeltaThenSetupEffect020c00c8(struct Obj020c00c8 *obj, int b, int c, int d);
int TailForwardToField0x5c020c0100(void *obj);
int InitFieldFrom020bd8ac_020c0110(char *obj, void *arg);
void BlankFunction020c0138(void);
int CopyFromField0xa4_020c013c(char *obj, void *dst, int length, int offset);
void BlankFunction020c0158(void);

// USA: func_020bffc4
#pragma optimize_for_size off
ARM void InitActionHandlers020bffc4(void *obj, unsigned int id) {
    int val = GetListEntryWord8020bd8ac(id);
    if (val == 0) {
        *(void **)((char *)obj + 0x164) = (void *)InitStreamFromEntry020c0044;
        *(void **)((char *)obj + 0x168) = (void *)CallFunc020cca80AtField0x5c_020c00b8;
        *(void **)((char *)obj + 0x16c) = (void *)AdjustDeltaThenSetupEffect020c00c8;
        *(void **)((char *)obj + 0x170) = (void *)TailForwardToField0x5c020c0100;
    } else {
        *(void **)((char *)obj + 0x164) = (void *)InitFieldFrom020bd8ac_020c0110;
        *(void **)((char *)obj + 0x168) = (void *)BlankFunction020c0138;
        *(void **)((char *)obj + 0x16c) = (void *)CopyFromField0xa4_020c013c;
        *(void **)((char *)obj + 0x170) = (void *)BlankFunction020c0158;
    }
}
