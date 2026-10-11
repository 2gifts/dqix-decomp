#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { flagOffset = 0xc9d };
#else
enum { flagOffset = 0xf71 };
#endif

extern "C" void func_020aaf84(void*, int, int, int);
unsigned char GetField0xcc0209ca98(char* obj);
unsigned char GetByteFieldAt0xcc(unsigned char* obj);
void SetModeClamped0209ca70(void* obj, int val);
struct Obj0205e9f4;
void SetStateAndDispatch0205e9f4(struct Obj0205e9f4* obj, int state);
void SetByte0x7f70(void* obj, unsigned char value);
void SetByte0x4(char* obj, unsigned char value);
void SetWord0x7f6c(void* obj, int value);
extern "C" void func_ov011_021848a0(void* obj, int val);

#if defined(jpn)
struct FieldGroup02171034_0216d504 { unsigned char pad0[6]; unsigned char field1; unsigned char field4; unsigned char pad8[4]; unsigned char* ptr10; };
#else
struct FieldGroup02171034_0216d504 {
    unsigned char pad0[1];
    unsigned char field1;
    unsigned char pad2[2];
    unsigned char field4;
    unsigned char pad5[0xb];
    unsigned char* ptr10;
};
#endif
extern FieldGroup02171034_0216d504 data_ov004_02171034;
extern char data_02109bf4;
extern unsigned char data_02108760;

// USA: func_ov004_0216d504  (semantic: SetupFieldsAndDispatch_0216d504)
extern "C" ARM int func_ov004_0216d504(void* self) {
    func_020aaf84(data_ov004_02171034.ptr10, 0, 0, 0);
    data_ov004_02171034.field4 = GetField0xcc0209ca98(&data_02109bf4);
    data_ov004_02171034.field1 = GetByteFieldAt0xcc(&data_02108760);
    SetModeClamped0209ca70(&data_02109bf4, 3);
    SetStateAndDispatch0205e9f4((struct Obj0205e9f4*)&data_02108760, 3);

    GameState* battle = GameState::GetInstance();
    SetByte0x7f70(battle, 0);
    ((unsigned char*)battle + 0x7000)[flagOffset] = 0;
    SetByte0x4((char*)battle, 0);
    SetWord0x7f6c(battle, 5);

    func_ov011_021848a0(self, 0x3e7);
    return 0;
}
