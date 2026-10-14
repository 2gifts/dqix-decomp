#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { stateOffset = 0x8c, firstFlag = 0xc9e, secondFlag = 0xc9f };
#else
enum { stateOffset = 0x6c, firstFlag = 0xf72, secondFlag = 0xf73 };
#endif

void ClearBitsInWord_0203b4b0(unsigned int* obj, unsigned int mask);
void ClearBitsInField4_0203b4e8(unsigned int* obj, unsigned int mask);
void ClearBitsInField8_0203b520(unsigned int* obj, unsigned int mask);
void SetBitsInWord_0203b4a0(unsigned int* obj, unsigned int mask);
void SetBitsInField4_0203b4d8(unsigned int* obj, unsigned int mask);
void SetBitsInField8_0203b510(unsigned int* obj, unsigned int mask);
extern "C" void* func_02012fe4(void);
struct S_e828;
void SetFieldAt0x7e_0201e828(S_e828*, unsigned short);
void SetWord0x7f6c_02012010(void* obj, int value);
void SetFieldFlag17188_0218d258(void* obj);

struct Struct02171048_0216ecd0 { char pad[0x4]; char* ptr; };
extern Struct02171048_0216ecd0 data_ov004_02171048;

// USA: func_ov004_0216ecd0  (semantic: ClearAndSetOv017FieldsThenSync_0216ecd0)
extern "C" ARM int func_ov004_0216ecd0(void) {
    GameState* bs = GameState::GetInstance();
    void* obj = func_ov017_0218b5b0();
    ClearBitsInWord_0203b4b0((unsigned int*)obj, -1);
    ClearBitsInField4_0203b4e8((unsigned int*)obj, -1);
    ClearBitsInField8_0203b520((unsigned int*)obj, -1);
    SetBitsInWord_0203b4a0((unsigned int*)obj, *(unsigned int*)(data_ov004_02171048.ptr + 0x0));
    SetBitsInField4_0203b4d8((unsigned int*)obj, *(unsigned int*)(data_ov004_02171048.ptr + 0x4));
    SetBitsInField8_0203b510((unsigned int*)obj, *(unsigned int*)(data_ov004_02171048.ptr + 0x8));
    void* v = func_02012fe4();
    if (!v) return 0;
    struct S_e828* p = (struct S_e828*)((char*)v + stateOffset);
    if (!p) return 0;
    SetFieldAt0x7e_0201e828(p, *(unsigned short*)(data_ov004_02171048.ptr + 0xc));
    SetWord0x7f6c_02012010(bs, 5);
    *(char*)((char*)bs + 0x7000 + firstFlag) = 1;
    *(char*)((char*)bs + 0x7000 + secondFlag) = 1;
    SetFieldFlag17188_0218d258(obj);
    return 0;
}
