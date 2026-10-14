#include <globaldefs.h>

void PushInterruptDisableState_020d8654();
void TryIssueBattleCommandAndUpdateState_0202dd28();
extern "C" int func_0202b1f4(int* outPtr, int unused);
extern "C" void func_0202aec0(void* obj);
extern "C" void func_020d8694(void);
void SleepCurrentContext(unsigned int);
int GetGlobalField0x10_0202d6a8(void);
extern "C" void func_0202dd98(void);
int SetStateAndInvokeCallback_0202df10();

// USA: func_0202b0f4
extern "C" ARM unsigned char func_0202b0f4(int* obj) {
    int result = 0;
    PushInterruptDisableState_020d8654();
    if (*obj != 0) {
        int count = 0;
        while (GetGlobalField0x10_0202d6a8() == 3) {
            count++;
            if (count > 5000) {
                TryIssueBattleCommandAndUpdateState_0202dd28();
                result = func_0202b1f4(obj, 1);
                if (result == 3) {
                    func_0202aec0(obj);
                    func_020d8694();
                    return (unsigned char)result;
                }
                break;
            }
            SleepCurrentContext(1);
        }

        func_0202dd98();
        result = func_0202b1f4(obj, 1);
        if (result == 3) {
            func_0202aec0(obj);
            func_020d8694();
            return (unsigned char)result;
        }
        if (result != 0) {
            TryIssueBattleCommandAndUpdateState_0202dd28();
            result = func_0202b1f4(obj, 1);
            if (result == 3) {
                func_0202aec0(obj);
                func_020d8694();
                return (unsigned char)result;
            }
        }
        SetStateAndInvokeCallback_0202df10();
    }
    func_0202aec0(obj);
    func_020d8694();
    return (unsigned char)result;
}
