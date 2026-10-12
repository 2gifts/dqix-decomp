#include <globaldefs.h>
#include "System/Memory.h"

struct InputState784 {
    unsigned char padding[4];
    unsigned int* flags;
    unsigned char digits[12];
    unsigned char cursor;
    unsigned char status;
};
extern InputState784* data_ov031_02290c98;
unsigned char GetField60_02225c24(void);
void SetField66_02225c38(int);
void SetField67_02225c4c(unsigned char);
void SetField68_02225c60(unsigned char);
void SetField_022274c0_022274c0(int);
void SetupHandlerB_0222de08(void);
extern "C" void func_ov031_02236878(int);
extern "C" int func_ov031_0222dd70(int);
extern "C" void func_ov031_0222df84(void);
extern "C" void func_ov031_0222e048(void);
extern "C" void func_ov031_0222e1ac(void);
extern "C" int func_ov031_0222e224(void);

// USA: func_ov031_0222da60
extern "C" ARM void func_ov031_0222da60(void) {
    int key = GetField60_02225c24();
    switch (key) {
    case 0:
        return;
    case 16:
        if (data_ov031_02290c98->cursor == 0 && data_ov031_02290c98->digits[2] == 0) break;
        func_ov031_02236878(3);
        if (data_ov031_02290c98->digits[data_ov031_02290c98->cursor * 3 + 2] == 0)
            --data_ov031_02290c98->cursor;
        VectorizedMemset(data_ov031_02290c98->digits + data_ov031_02290c98->cursor * 3, 0, 3);
        if (data_ov031_02290c98->cursor == 0 && data_ov031_02290c98->digits[2] == 0)
            SetField66_02225c38(0);
        SetField67_02225c4c(1);
        SetField68_02225c60(0);
        break;
    case 17:
        if (data_ov031_02290c98->cursor >= 3) break;
        if (data_ov031_02290c98->digits[data_ov031_02290c98->cursor * 3 + 2] == 0) break;
        func_ov031_02236878(1);
        ++data_ov031_02290c98->cursor;
        SetField68_02225c60(0);
        break;
    case 18:
        data_ov031_02290c98->status = 0;
        func_ov031_02236878(7);
        SetField_022274c0_022274c0((int)SetupHandlerB_0222de08);
        return;
    case 19:
        if (func_ov031_0222e224()) {
            func_ov031_02236878(6);
            data_ov031_02290c98->status = 1;
        } else {
            data_ov031_02290c98->status = 2;
            func_ov031_02236878(9);
        }
        data_ov031_02290c98->cursor = 3;
        *data_ov031_02290c98->flags = (*data_ov031_02290c98->flags & 0xc1fffcff) | 0x200;
        func_ov031_0222e048();
        func_ov031_0222e1ac();
        SetField_022274c0_022274c0((int)SetupHandlerB_0222de08);
        return;
    default:
        if (data_ov031_02290c98->cursor == 3 && func_ov031_0222dd70(26)) break;
        func_ov031_02236878(1);
        unsigned char* digits = data_ov031_02290c98->digits;
        int offset = data_ov031_02290c98->cursor * 3;
        if (digits[offset + 2] == 0) {
            digits[offset + 2] = key;
        } else if (digits[offset + 1] == 0) {
            digits[offset + 1] = digits[offset + 2];
            digits[offset + 2] = key;
            if (func_ov031_0222dd70(26)) {
                if (data_ov031_02290c98->cursor < 3) ++data_ov031_02290c98->cursor;
            }
        } else {
            digits[offset] = digits[offset + 1];
            digits[offset + 1] = digits[offset + 2];
            digits[offset + 2] = key;
            if (data_ov031_02290c98->cursor < 3) ++data_ov031_02290c98->cursor;
        }
        SetField66_02225c38(1);
        if (data_ov031_02290c98->cursor < 3) SetField68_02225c60(1);
        else SetField68_02225c60(0);
        if (data_ov031_02290c98->cursor == 3 && func_ov031_0222dd70(26))
            SetField67_02225c4c(0);
        break;
    }
    func_ov031_0222df84();
    func_ov031_0222e048();
}
