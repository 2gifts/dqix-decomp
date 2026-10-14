#include <globaldefs.h>

void ForwardField0xc0_0205ebec(void* obj);
void SetForwardAndStore0205ebc0(void* obj, int arg1, int arg2);
void DispatchIfField0xc4NonNeg_0205ebfc(void* obj, int a, int b);
unsigned long long GetCurrentTimestamp(void);
void* GetData02108f0c_0208a9b4(void);

struct Obj0208b494;
void CaptureValueOnce0208b494(struct Obj0208b494* obj);

extern int data_02108760;

// USA: func_ov017_021c2e50
ARM void ForwardResetAndCaptureTimestamp_021c2e50(char* self) {
    ForwardField0xc0_0205ebec((void*)&data_02108760);
    SetForwardAndStore0205ebc0((void*)&data_02108760, 0xb3, 0xb3);
    DispatchIfField0xc4NonNeg_0205ebfc((void*)&data_02108760, 0, 0);
    *(unsigned long long*)(self + 0x98) = GetCurrentTimestamp();
    CaptureValueOnce0208b494((struct Obj0208b494*)GetData02108f0c_0208a9b4());
    self[0x8c] = 3;
}
