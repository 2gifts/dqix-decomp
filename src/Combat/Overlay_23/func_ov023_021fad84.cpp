#include <globaldefs.h>

extern "C" void func_ov023_021f6ed8(void* obj);
extern "C" void* func_ov011_021849c8(void* ctx);
extern "C" void* func_ov023_021f6880(void* list, int value);
extern "C" void* func_ov023_021fad18(void* obj);
extern "C" int func_ov023_021f6c90(void* list, int elemIndex, int flag);
void* GetEntryPtr_021fa854(char* obj, unsigned int idx);
ARM void SetBitsInArray021f6bec(void* obj, int elemIndex, unsigned int startBit, unsigned int count);

struct Obj021fad84 {
    char pad0[4];
    unsigned short f4;
    unsigned short f6;
    unsigned short f8;
    unsigned short fa;
    char pad_c[4];
    unsigned int f10;
    char pad_14[8];
    unsigned int f1c;
    unsigned short f20;
    unsigned short f22;
    unsigned short f24;
    unsigned short f26;
    unsigned int f28;
    unsigned int f2c;
    unsigned short f30;
    unsigned short f32;
    unsigned short f34;
    unsigned short f36;
    char f38;
    char f39;
#if defined(jpn)
    unsigned short f3a;
#else
    unsigned char f3a;
    char pad_3b[1];
#endif

    unsigned short f3c;
    unsigned short f3e;
    unsigned short f40;
    unsigned short f42;
#if defined(jpn)
    int f44;
    int f46;
#else
    unsigned short f44;
    unsigned short f46;
#endif

    unsigned short f48;
    unsigned char f4a;
#if defined(jpn)

#else
    unsigned char f4b;
#endif

};

// JPN: func_ov023_021fa168
// USA: func_ov023_021fad84  (semantic: InitObjAndRegisterListEntryB_021fad84)
extern "C" ARM int func_ov023_021fad84(struct Obj021fad84* obj, void* ctx, int arg3, int arg4, int arg5, int arg6) {
    func_ov023_021f6ed8(obj);
    obj->f4 = 1;
    obj->f6 = arg3;
    obj->f8 = arg4;
    obj->fa = 0;
    obj->f10 = 0;
    obj->f1c = 2;
    obj->f20 = arg5;
#if defined(jpn)
    obj->f44 = -1;
    obj->f46 = -1;
#else
    obj->f3a = 1;
    obj->f44 = 0;
    obj->f46 = 0;
#endif


    void* list = func_ov011_021849c8(ctx);
    void* node = func_ov023_021f6880(list, obj->f20);
    if (node == NULL) {
        return 0;
    }

    void* p = func_ov023_021fad18(node);
    unsigned char b = *(unsigned char*)((char*)p + 0x50);
    *(unsigned short*)((char*)obj + 0x22) = arg6;
    void* entry = GetEntryPtr_021fa854((char*)p, *(unsigned short*)((char*)obj + 0x22));
    unsigned short entryVal = *(unsigned short*)entry;

    int r = func_ov023_021f6c90(list, b, entryVal);
    *(unsigned short*)((char*)obj + 0x24) = r;
    SetBitsInArray021f6bec(list, b, *(unsigned short*)((char*)obj + 0x24), entryVal);

    obj->f26 = 0;
    obj->f28 = 0;
    obj->f2c = 0;
    obj->f30 = obj->f32 = obj->f34 = obj->f36 = 0;
    obj->f38 = -1;
    obj->f39 = -1;
#if defined(jpn)
    obj->f3a = 0;
    obj->f3c = 0;
#else
    obj->f3c = 0;
#endif

    obj->f3e = 0;
    obj->f40 = 0;
#if defined(jpn)

#else
    obj->f42 = 0;
#endif

    obj->f48 = 0;
    obj->f4a = 0;
#if defined(jpn)

#else
    obj->f4b = 0;
#endif

    return 1;
}
