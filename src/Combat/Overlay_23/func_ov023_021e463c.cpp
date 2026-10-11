#include <globaldefs.h>

extern "C" void func_ov023_021e6194(void* p);
struct Words021e60c4 { unsigned int v[3]; };
extern "C" void func_ov023_021e613c(Words021e60c4* dst, char* src);
extern "C" int _Z22fix32ReduceAngle0To2Pii(int angle);
void InitWordsQuad_021e60e0(void* obj, unsigned int val);
void SetFourWordBlocks_021e6088(void* obj, Words021e60c4* src);
extern "C" int func_ov023_021e29d0(char* obj);
int TestFlagMask(unsigned short* obj, int mask);

extern unsigned char data_02114e54;
extern unsigned short data_02114e30;

// JPN: func_ov023_021e4860
// USA: func_ov023_021e463c  (semantic: UpdateOrientationOrCombatFlags_021e463c)
extern "C" ARM void func_ov023_021e463c(void* objRaw, unsigned int count) {
#if defined(jpn)
 enum {regionalOffset0=0x124, regionalOffset1=0x56c};
#else
 enum {regionalOffset0=0x128, regionalOffset1=0x634};
#endif
    char* obj = (char*)objRaw;
    Words021e60c4 s24;
    Words021e60c4 s18;
    Words021e60c4 s0c;
    Words021e60c4 s00;
    func_ov023_021e6194(*(void**)(obj + regionalOffset0));
    unsigned short flags = *(unsigned short*)(obj + regionalOffset1);
    if (flags & 2) {
        int within = 0;
        func_ov023_021e613c(&s0c, *(char**)(obj + regionalOffset0));
        s24 = s0c;
        int origPos = s24.v[1];
        int base = 0x1eb;
        int divisor = 12;
        int d = _Z22fix32ReduceAngle0To2Pii(base - origPos);
        int pos;
        if (d >= 0 && d < 0x3244) {
            pos = origPos + d / divisor;
            unsigned int i;
            for (i = 0; i < count - 1; i++) {
                int dd = _Z22fix32ReduceAngle0To2Pii(base - pos);
                pos += dd / divisor;
            }
        } else if (d >= 0x3244 && d < 0x6488) {
            int span = 0x6488;
            pos = origPos - (span - d) / divisor;
            unsigned int i;
            for (i = 0; i < count - 1; i++) {
                int dd = _Z22fix32ReduceAngle0To2Pii(base - pos);
                pos -= (span - dd) / divisor;
            }
        }
        int normalized = _Z22fix32ReduceAngle0To2Pii(pos);
        InitWordsQuad_021e60e0(*(void**)(obj + regionalOffset0), normalized);
        int diff = _Z22fix32ReduceAngle0To2Pii(0x1eb - pos);
        int absDiff = diff < 0 ? -diff : diff;
        if (absDiff < 0x28) {
            within = 1;
        } else {
            int d2 = 0x6488 - diff;
            int absD2 = d2 < 0 ? -d2 : d2;
            if (absD2 < 0x28) within = 1;
        }
        if (within) {
            int n2 = _Z22fix32ReduceAngle0To2Pii(0x1eb);
            InitWordsQuad_021e60e0(*(void**)(obj + regionalOffset0), n2);
            *(unsigned short*)(obj + regionalOffset1) &= ~2;
        }
    } else if (flags & 1) {
        int flag5 = 0, flag6 = 0, got = 0;
        if (*(&data_02114e54 + 0x55)) {
            int v = func_ov023_021e29d0(obj + 0xd4);
            if (v == 0x22) flag5 = 1;
            if (v == 0x23) flag6 = 1;
            got = 1;
        } else if (*(&data_02114e54 + 0x5f) && *(unsigned short*)(&data_02114e54 + 0x24)) {
            if (flags & 0x100) flag5 = 1;
            if (flags & 0x200) flag6 = 1;
            got = 1;
        } else if (*(&data_02114e54 + 0x54)) {
            got = 1;
        }
        if (!got) {
            if (TestFlagMask(&data_02114e30, 0x200)) flag5 = 1;
            if (TestFlagMask(&data_02114e30, 0x100)) flag6 = 1;
        }
        if (flag5 && flag6) {
            *(unsigned short*)(obj + regionalOffset1) |= 2;
        } else if (flag5 || flag6) {
            func_ov023_021e613c(&s00, *(char**)(obj + regionalOffset0));
            s18 = s00;
            if (flag5) {
                s18.v[1] += (int)((float)count * 0.08f * 4096.0f);
            }
            if (flag6) {
                s18.v[1] -= (int)((float)count * 0.08f * 4096.0f);
            }
            s18.v[1] = _Z22fix32ReduceAngle0To2Pii(s18.v[1]);
            SetFourWordBlocks_021e6088(*(void**)(obj + regionalOffset0), &s18);
        }
        if (flag5) {
            *(unsigned short*)(obj + regionalOffset1) |= 0x100;
        } else {
            *(unsigned short*)(obj + regionalOffset1) &= ~0x100;
        }
        if (flag6) {
            *(unsigned short*)(obj + regionalOffset1) |= 0x200;
        } else {
            *(unsigned short*)(obj + regionalOffset1) &= ~0x200;
        }
    }
}
