#include <globaldefs.h>

void InitFourWordsAndCallbacksOnce_020d21c0(void);
void ResetQueueAndNotify_020bbdd8(void);
void CallFunc020bd08c_020bbe10(void);
void ResetFlagPool_020bbf18(void);
void Reset0210fd74State_020bce9c(void);
void InitAllocatorPools020bc23c(void);

struct NodeCEE54 { char _pad[8]; struct NodeCEE54* next; };
void PrependToGlobalList02111804_020cef34(struct NodeCEE54* node);

struct NodeCEE68 { char _pad[8]; struct NodeCEE68* next; };
void AppendToGlobalList02111800_020cef4c(struct NodeCEE68* node);

extern struct NodeCEE54 data_0210cfd0;
extern struct NodeCEE68 data_0210cfdc;

struct Struct0210cfc0 {
    char byte0;
    char pad1[3];
    int field4;
    char pad2[0xc - 8];
    int guard;
    void (*field10)(void);
    int field14;
    char pad3[0x1c - 0x18];
    void (*field1c)(void);
    int field20;
};
extern struct Struct0210cfc0 data_0210cfc0;

// USA: func_020bbd14  (semantic: InitGlobalSystemsOnce020bbd14)
extern "C" ARM void func_020bbd14(void) {
    if (data_0210cfc0.guard != 0) return;
    data_0210cfc0.guard = 1;
    InitFourWordsAndCallbacksOnce_020d21c0();
    data_0210cfc0.field10 = ResetQueueAndNotify_020bbdd8;
    data_0210cfc0.field14 = 0;
    data_0210cfc0.field1c = CallFunc020bd08c_020bbe10;
    data_0210cfc0.field20 = 0;
    PrependToGlobalList02111804_020cef34(&data_0210cfd0);
    AppendToGlobalList02111800_020cef4c(&data_0210cfdc);
    ResetFlagPool_020bbf18();
    Reset0210fd74State_020bce9c();
    InitAllocatorPools020bc23c();
    data_0210cfc0.byte0 = -1;
    data_0210cfc0.field4 = 1;
}
