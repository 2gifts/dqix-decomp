#include <globaldefs.h>

struct Key0215ec90 {
    char pad0[4];
    int code;
    int shiftedCode;
    char padC[3];
    unsigned char isCommand;
};

struct Entry0204254c {
    char pad0[4];
    signed char width;
};

struct NameInput0215ec90 {
    struct Key0215ec90* key;
    char pad4[4];
    char* text;
    int widthLimit;
    char pad10[4];
    int maxLen;
    char pad18[0x1e - 0x18];
    unsigned char state;
    unsigned char font;
    unsigned char shiftMode;
};

extern "C" void __clear(void* buf, int size);
extern "C" int _Z27FindEntryIndexByKey020424e4ii(int key, int tableIdx);
extern "C" int func_020426bc(void* src, void* dst, int flag);
extern "C" void func_02042764(void* src, void* dst, int flag);
extern "C" int func_020420e8(void* str, int flag);
extern "C" struct Entry0204254c* _Z22FindEntryByKey0204254cii(int key, int tableIdx);

extern unsigned char data_ov003_0217f3b0[];

// USA: func_ov003_0215ec90
extern "C" ARM int func_ov003_0215ec90(struct NameInput0215ec90* input) {
    unsigned char buf[0x100];
    unsigned char work[0x100];
    unsigned char* p;
    int code;
    int ch;
    struct Entry0204254c* entry;
    int width;
    int i;
    int len;
    char* text;
    int widthLimit;
    int font;
    int maxLen;
    struct Key0215ec90* key = input->key;
    if (key != 0) {
        if (key->isCommand != 0) {
            return 0xd;
        }

        font = input->font;
        text = input->text;
        code = key->code;
        if (data_ov003_0217f3b0[input->shiftMode] == input->state) {
            code = key->shiftedCode;
        }
        widthLimit = input->widthLimit;
        maxLen = input->maxLen;

        __clear(buf, 0x100);
        ch = _Z27FindEntryIndexByKey020424e4ii(code, font);
        len = func_020426bc(text, buf, font);
        p = buf;
        for (i = 0; i < maxLen; i++, p++) {
            if (i == maxLen - 1) {
                unsigned char prev = *p;
                *p = ch;
                if (widthLimit != 0) {
                    __clear(work, 0x100);
                    func_02042764(buf, work, font);
                    if (widthLimit < func_020420e8(work, 0)) {
                        *p = prev;
                        break;
                    }
                }
                func_02042764(buf, text, font);
                input->shiftMode = 0;
                return (maxLen <= len + 1) ? 3 : 2;
            }
            if (*p == 0) {
                if (widthLimit != 0) {
                    width = func_020420e8(text, 0);
                    entry = _Z22FindEntryByKey0204254cii(code, 0);
                    if (entry != 0) {
                        width += entry->width + 1;
                    }
                    if (widthLimit < width) {
                        break;
                    }
                }
                *p = ch;
                func_02042764(buf, text, font);
                input->shiftMode = 0;
                return (maxLen <= len + 1) ? 3 : 2;
            }
        }
    }
    return 0;
}
