#include <globaldefs.h>

void* GetGlobalManager0209dccc();
int RunUpdateSequence0209fdf8();
extern "C" int func_ov017_021d6134(void*, int);

// USA: func_0209daf8
ARM int NotifyOv017WithUpdateResult_0209daf8(void* arg) {
    void* mgr = GetGlobalManager0209dccc();
    if (mgr == NULL) return 0;
    int v = RunUpdateSequence0209fdf8();
    func_ov017_021d6134(arg, v);
    return 1;
}
