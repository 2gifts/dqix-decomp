#include <globaldefs.h>
#if defined(jpn)
enum{regionField=0x708,regionFlag=0x868};
#else
enum{regionField=0x838,regionFlag=0x998};
#endif

extern "C" int func_ov017_021d60f4(void*);
extern "C" void* func_ov017_021d612c(void*);
#if defined(jpn)
extern "C" void func_02045d88(void*, int, int);
#else
extern "C" void func_0204500c(void*, int, int, int);
#endif
int GetGlobalField0x1c020421a0();
struct Table_02153884;
void* FindTableEntry_02153884(struct Table_02153884* t, int key);

extern Table_02153884 data_ov001_021658d8;

struct Entry0215e2a4 { char pad0[4]; int val; };
struct Self0215e2a4 { int type; };

// USA: func_ov001_0215e2a4
extern "C" ARM int func_ov001_0215e2a4(Self0215e2a4* self, int mode) {
    char* g = (char*)GetGlobalField0x1c020421a0();
    int type = self->type;
    switch (type) {
    case 0: {
        int idx = func_ov017_021d60f4(self);
        Entry0215e2a4* entry = (Entry0215e2a4*)FindTableEntry_02153884(&data_ov001_021658d8, idx);
        if (entry == NULL) return 0;
        *(int*)(g + 0x1000 + regionField) = -1;
        int flag = 1;
        if (mode >= 2) {
            int r = func_ov017_021d60f4((char*)self + 0x8);
            if (r & 1) flag = 0;
        }
#if defined(jpn)
        func_02045d88(g, entry->val, flag);
#else
        func_0204500c(g, entry->val, flag, 0xe3);
#endif
        *(int*)(g + regionFlag) = 1;
        break;
    }
    case 2: {
        void* extra = func_ov017_021d612c(self);
        *(int*)(g + 0x1000 + regionField) = -1;
#if defined(jpn)
        func_02045d88(g, (int)extra, 1);
#else
        func_0204500c(g, (int)extra, 1, 0xe3);
#endif
        *(int*)(g + regionFlag) = 1;
        break;
    }
    }
    return 1;
}
