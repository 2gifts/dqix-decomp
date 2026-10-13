#include <globaldefs.h>

struct BattleCommandArgument {
    int type;
    union {
        int integer;
        float real;
        BattleCommandArgument* reference;
    } value;
};

#if defined(jpn)
#define func_0209ebe4 func_020a095c
#endif


void* GetGlobalManager0209dccc();
extern "C" int func_ov017_021d60f4(void*);
extern "C" void func_0209ebe4(void*, int, int);

#if defined(jpn)
#define TryProcessObjectPair0209ebe4 func_0209ed88
extern "C" ARM int func_0209ed88(void* obj);
#endif

// USA: func_0209d010
ARM int TryProcessObjectPair0209ebe4(void* argumentData) {
    void* manager = GetGlobalManager0209dccc();
    if (manager == NULL) return 0;
    BattleCommandArgument* arguments = (BattleCommandArgument*)argumentData;
    int refineExisting = func_ov017_021d60f4(&arguments[0]);
    int filterParameter = func_ov017_021d60f4(&arguments[1]);
    func_0209ebe4(manager, refineExisting, filterParameter);
    return 1;
}
