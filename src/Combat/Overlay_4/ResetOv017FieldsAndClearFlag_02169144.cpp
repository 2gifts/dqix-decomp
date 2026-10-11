#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { stateOffset = 0x964, bits0 = 0, bits4 = 4, bits8 = 8, fieldOffset = 0x8c, flagOffset = 0x790, fieldBase = 0 };
#else
enum { stateOffset = 0xb84, bits0 = 0x180, bits4 = 0x184, bits8 = 0x188, fieldOffset = 0x6c, flagOffset = 0x962, fieldBase = 0x100 };
#endif

void ClearBitsInWord(unsigned int* obj, unsigned int mask);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);
void ClearBitsInField8(unsigned int* obj, unsigned int mask);
void SetBitsInWord(unsigned int* obj, unsigned int mask);
void SetBitsInField4(unsigned int* obj, unsigned int mask);
void SetBitsInField8(unsigned int* obj, unsigned int mask);
extern "C" void* func_02012fe4(void);
struct S_e828;
extern "C" void _Z14SetFieldAt0x7eP6S_e828s(struct S_e828* p, unsigned short v);
extern "C" void func_ov017_021a967c(unsigned char* self, int id);
int GetGlobalField0x1c020421a0(void);
extern void* data_ov004_02171030;
struct FieldGroup02171030At100 {
#if defined(jpn)
 char pad[0xc];
#else
 char pad[0x8c];
#endif
 unsigned short field8c; };

// USA: func_ov004_02169144  (semantic: ResetOv017FieldsAndClearFlag_02169144)
extern "C" ARM int func_ov004_02169144(void) {
    GameState::GetInstance();
    void* obj = func_ov017_0218b5b0();
    unsigned char* self = *(unsigned char**)((char*)obj + 0x3000 + stateOffset);
    ClearBitsInWord((unsigned int*)obj, -1);
    ClearBitsInField4((unsigned int*)obj, -1);
    ClearBitsInField8((unsigned int*)obj, -1);
    SetBitsInWord((unsigned int*)obj, *(unsigned int*)((char*)data_ov004_02171030 + bits0));
    SetBitsInField4((unsigned int*)obj, *(unsigned int*)((char*)data_ov004_02171030 + bits4));
    SetBitsInField8((unsigned int*)obj, *(unsigned int*)((char*)data_ov004_02171030 + bits8));
    void* v = func_02012fe4();
    if (!v) return 0;
    struct S_e828* p = (struct S_e828*)((char*)v + fieldOffset);
    if (!p) return 0;
    struct FieldGroup02171030At100* s100 = (struct FieldGroup02171030At100*)((char*)data_ov004_02171030 + fieldBase);
    _Z14SetFieldAt0x7eP6S_e828s(p, s100->field8c);
    func_ov017_021a967c(self, -1);
    int g = GetGlobalField0x1c020421a0();
    g += 0x1000;
    *(unsigned char*)(g + flagOffset) = 0;
    return 0;
}
