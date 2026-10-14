#include <globaldefs.h>

void SetField54IfTagNot9Or10_ov031_022393e4(int v);
extern "C" void func_ov031_02239368(int);
extern "C" int func_ov031_02239550(void);

struct TagInfo02239518 { short pad0; unsigned short tag; };

// USA: func_ov031_02239518
extern "C" ARM void func_ov031_02239518(TagInfo02239518* info) {
    unsigned short tag = info->tag;
    if (tag != 0) {
        SetField54IfTagNot9Or10_ov031_022393e4(tag);
        func_ov031_02239368(9);
        return;
    }
    if (func_ov031_02239550() != 0) return;
    func_ov031_02239368(9);
}
