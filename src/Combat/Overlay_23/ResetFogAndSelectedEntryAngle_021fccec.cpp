#include <globaldefs.h>

struct WordsInner021fccec { unsigned int v[3]; };
struct Words021e60c4 { struct WordsInner021fccec mid; };
struct FlagByte021fccec { unsigned char pad[0x864]; unsigned char flag : 1; };
extern "C" void func_ov023_021e613c(struct Words021e60c4* dst, void* src);
int fix32ReduceAngle0To2Pi(int angle);
void SetFogState(int enable, unsigned int fogMode, unsigned int fogShift, unsigned short fogOffset);
void SetFourWordBlocks_021e6088(void* obj, struct Words021e60c4* src);

// USA: func_ov023_021fccec  (semantic: ResetFogAndSelectedEntryAngle_021fccec)
extern "C" ARM void func_ov023_021fccec(void* obj) {
    SetFogState(0, 0, 0, 0);
    unsigned int flag = ((struct FlagByte021fccec*)((char*)obj + 0x1000))->flag;
    void* entry = (char*)obj + 0x20 + flag * 0xc20;
    struct Words021e60c4 copy;
    struct Words021e60c4 tmp;
    func_ov023_021e613c(&tmp, entry);
    copy.mid = tmp.mid;
    copy.mid.v[1] = copy.mid.v[1] + 0xFFFFFE67u;
    copy.mid.v[1] = fix32ReduceAngle0To2Pi(copy.mid.v[1]);
    SetFourWordBlocks_021e6088(entry, &copy);
}
