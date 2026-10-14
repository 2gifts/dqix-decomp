#include <globaldefs.h>
int SubmitBattleAction020d68dc(int, unsigned int, void*);

extern char data_021015a0;
extern char data_02101600;
extern char data_021016e0;
void SetField0x48UnlessState9Or10_0202c848(int arg);
void CheckField2ThenSetState9_0202d1e4(unsigned short* a);

typedef int (*FieldFn0202d180)(void*, void*);

// USA: func_0202d180
ARM int SetState3AndInvokeHandler0202d180(void) {
    *(int*)(&data_021015a0 + 0x10) = 3;
    FieldFn0202d180 fn = *(FieldFn0202d180*)(&data_021015a0 + 0x30);
    int r = fn(&data_02101600, &data_021016e0);
    int result = SubmitBattleAction020d68dc((int)((void*)CheckField2ThenSetState9_0202d1e4), (unsigned int)(r), (void*)(&data_02101600));
    if (result == 2) {
        return 1;
    }
    SetField0x48UnlessState9Or10_0202c848(result);
    *(int*)(&data_021015a0 + 0x10) = 9;
    return 0;
}
