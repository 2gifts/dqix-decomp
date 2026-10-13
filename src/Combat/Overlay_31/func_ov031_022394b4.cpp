#include <globaldefs.h>

void SetField54IfTagNot9Or10(int v);
extern "C" ARM void func_ov031_02239368(int val);
extern "C" ARM void func_ov031_02239518(void* info);
extern "C" int _Z26SubmitBattleAction020d68dcijPv(int cb, unsigned int v, void* ctx);

struct Ctx_022394b4 {
    unsigned char pad[0x13ac];
    int (*hook)(void*, void*);
    unsigned char pad2[0x10];
    void* arg;
};
struct Outer_022394b4 { void* unk0; Ctx_022394b4* field4; };
extern struct Outer_022394b4 data_ov031_02290d18;

// USA: func_ov031_022394b4
extern "C" ARM int func_ov031_022394b4(void) {
    func_ov031_02239368(3);
    Ctx_022394b4* c = data_ov031_02290d18.field4;
    unsigned int r = c->hook((void*)((char*)c + 0x13c0), c);
    int res = _Z26SubmitBattleAction020d68dcijPv((int)func_ov031_02239518, r,
                                          (void*)((char*)data_ov031_02290d18.field4 + 0x13c0));
    if (res == 2) {
        return 1;
    }
    SetField54IfTagNot9Or10(res);
    func_ov031_02239368(9);
    return 0;
}
