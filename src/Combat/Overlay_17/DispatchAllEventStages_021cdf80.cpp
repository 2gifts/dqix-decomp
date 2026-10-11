#include <globaldefs.h>

extern "C" void func_ov017_021c83a0(void);
extern "C" void func_ov017_021c6378(void* self);
extern "C" void func_ov017_021c66e8(char* self);
extern "C" void func_ov017_021ca2f8(unsigned char b);
extern "C" void func_ov017_021ca3c4(void* obj);
extern "C" void func_ov017_021ca534(void* obj);
extern "C" void func_ov017_021ca81c(void* obj);
extern "C" void func_ov017_021ca9bc(void* obj);
extern "C" void func_ov017_021caea8(void* obj);
extern "C" void func_ov017_021cb5f8(void* obj);
extern "C" void func_ov017_021c6bc8(void);
extern "C" void func_ov017_021c6d50(void);
extern "C" void func_ov017_021c6ff0(void);
extern "C" void func_ov017_021c71a4(void);
extern "C" void func_ov017_021c7484(void);
extern "C" void func_ov017_021c7b8c(void);
void EnqueueEventTag99_021cbbd0(unsigned char* obj);

// USA: func_ov017_021cdf80
ARM void DispatchAllEventStages_021cdf80(char* self, unsigned char b) {
    func_ov017_021c83a0();
    func_ov017_021c6378(self);
    func_ov017_021c66e8(self);
    func_ov017_021ca2f8(b);
    func_ov017_021ca3c4(self + 0x1b0 + 0x8000);
    func_ov017_021ca534(self + 0x1b0 + 0x8000);
    func_ov017_021ca81c(self + 0x1b0 + 0x8000);
    func_ov017_021ca9bc(self + 0x1b0 + 0x8000);
    func_ov017_021caea8(self + 0x1b0 + 0x8000);
    func_ov017_021cb5f8(self + 0x1b0 + 0x8000);
    func_ov017_021c6bc8();
    func_ov017_021c6d50();
    func_ov017_021c6ff0();
    func_ov017_021c71a4();
    func_ov017_021c7484();
    func_ov017_021c7b8c();
    EnqueueEventTag99_021cbbd0((unsigned char*)self);
}
