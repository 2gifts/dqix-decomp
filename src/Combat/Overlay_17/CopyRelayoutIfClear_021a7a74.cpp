#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);
struct HeadNode02046b24;
int GetHeadNodeIdOrMinusOne(HeadNode02046b24** obj);
struct TailList020469b4;
struct TailNode020469b4;
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
void InitObj_021a7adc(char* obj);
void CopyRelayoutFields_021a7c28(unsigned char* dst, unsigned char* src);

// JPN: func_ov017_021a8404
// USA: func_ov017_021a7a74  (semantic: CopyRelayoutIfClear_021a7a74)
extern "C" ARM void func_ov017_021a7a74(void* unused0, unsigned char* src) {
#if defined(jpn)
 enum {regionalOffset0=0x4ec, regionalOffset1=0x8ec, regionalOffset2=0x978};
#else
 enum {regionalOffset0=0x6fc, regionalOffset1=0xb0c, regionalOffset2=0xb98};
#endif
    int base0 = func_ov017_0218b5b0();
    HeadNode02046b24** list = *(HeadNode02046b24***)(base0 + 0x3000 + regionalOffset0);
    int id = GetHeadNodeIdOrMinusOne(list);
    if (id == 0x1a) {
        int* p = *(int**)(base0 + 0x3000 + regionalOffset1);
        if (*(int*)((char*)p + 0x64) != 0) {
            return;
        }
    }
    unsigned char* node = *(unsigned char**)(base0 + 0x3000 + regionalOffset2);
    InitObj_021a7adc((char*)node);
    CopyRelayoutFields_021a7c28(node, src);
    AppendNodeToTail((TailList020469b4*)list, (TailNode020469b4*)node);
}
