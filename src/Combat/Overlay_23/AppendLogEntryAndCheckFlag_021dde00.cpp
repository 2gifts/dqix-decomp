#include <globaldefs.h>

extern "C" void func_0204c684(void* buf);
int InitBufferFromDataField4_021ddc34(void* obj, short a, short b, short c, short d);
extern "C" int func_ov023_021ddc98(void* buf, int val, unsigned short len, int flag);
extern int data_ov023_021ff9e0[];
extern "C" void __clear(void* buf, int len);
int GetGlobalField0x1c020421a0(void);
void CopyTextAndUppercaseIfFlagged0206819c(const char* src, char* dst, int flag);
extern "C" int func_02046608(int a, int b, void* c, void* d, int e, int f, int g);
extern "C" int func_020420e8(void* p, int flag);
extern "C" int func_0204f41c(void* target, int a, int b, void* c, int d, int e, void* f, void* g, int h);
extern "C" void func_ov023_021dd344(void* obj);

#if defined(jpn)
extern "C" void func_02041f50(const char*, char*);
int StringLength(const char*);
extern "C" int func_02050678(void*, int, int, const char*, int, int, void*, void*);
#define LOG_OFFSET 0x6d8
#define FLAGS_OFFSET 0x6f0
#define DATA_FLAG 5
#else
#define LOG_OFFSET 0x75c
#define FLAGS_OFFSET 0x774
#define DATA_FLAG 1
#endif

// JPN: func_ov023_021de5c4
// USA: func_ov023_021dde00  (semantic: AppendLogEntryAndCheckFlag_021dde00)
extern "C" ARM void func_ov023_021dde00(void* objRaw) {
    char* obj = (char*)objRaw;
    void* info = *(void**)(obj + 0x50);
    if (info) {
        char buf[0xe0];
        func_0204c684(buf);
        #if defined(jpn)
        if (InitBufferFromDataField4_021ddc34(buf, 5, 1, 0xe, 2)) {
#else
        if (InitBufferFromDataField4_021ddc34(buf, 4, 1, 0xf, 2)) {
#endif
            info = *(void**)(obj + 0x50);
            if (data_ov023_021ff9e0[DATA_FLAG] && info) {
#if defined(jpn)
                char converted[0x40];
                __clear(converted, 0x40);
                func_02041f50(*(const char**)((char*)info + 4), converted);
                short len = StringLength(converted);
                short half = len >> 1;
                short measured = half * 10;
                int arg1 = ((0x70 - measured) << 15) >> 16;
                short outHi, outLo;
                func_02050678(buf, arg1, 3, *(const char**)((char*)info + 4), 0xa, 0xf, &outLo, &outHi);
#else
                int g = GetGlobalField0x1c020421a0();
                char textBuf[0x80];
                char nameBuf[0x80];
                __clear(nameBuf, 0x80);
                __clear(textBuf, 0x80);
                CopyTextAndUppercaseIfFlagged0206819c(*(const char**)((char*)info + 4), nameBuf, 0);
                func_02046608(g, 0xa, nameBuf, textBuf, 0x100, 0, 0);
                int measured = func_020420e8(textBuf, 0);
                int arg1 = ((0x70 - (short)measured) << 15) >> 16;
                short outHi, outLo;
                func_0204f41c(buf, arg1, 3, textBuf, 0xa, 0xf, &outLo, &outHi, 0);
#endif
            }
            *(int*)(obj + LOG_OFFSET) = *(int*)(obj + LOG_OFFSET) + func_ov023_021ddc98(buf, *(int*)(obj + LOG_OFFSET), (unsigned short)data_ov023_021ff9e0[3], 0);
        }
    }
    if (*(unsigned short*)(obj + FLAGS_OFFSET) & 0x800) {
        func_ov023_021dd344(obj);
    }
}
