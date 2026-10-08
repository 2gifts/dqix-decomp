#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct Obj020941f8 {
    char pad0[0x340];
    int handle340;
    char pad1[0x3c8 - 0x344];
    unsigned char rest3c8 : 7;
    unsigned char flag3c8 : 1;
    char pad2[0x3cb - 0x3c9];
    char field3cb;
    char pad3;
    unsigned char field3cd;
};

struct Ctx020941f8 {
    char pad0[0x44];
    int field44;
    char pad1[0x50 - 0x48];
    unsigned char field50;
};

struct ActiveEntry02046900;
struct Rec020467f0;

int CountActiveEntries(struct ActiveEntry02046900* entry);
extern void* FindRecordByIndex(struct Rec020467f0* rec, int index, void** out, int* out44);
extern "C" unsigned char _Z27IsPowCnt1Bit15Clear020938ccv();
extern "C" ARM void _Z18InitStruct0205a444Pc(char* obj);
extern "C" ARM void _Z23EmptyDestructor0205a494Pv(void* obj);
extern "C" ARM int func_0205a528(void* obj, void* data, int arg2, int arg3);
extern "C" int func_020937f0(int a);
extern const char data_020f1394[];

// USA: func_020941f8
extern "C" ARM int func_020941f8(struct Obj020941f8* p) {
    if ((p->field3cd & 8) == 0 && (p->field3cd & 2) == 0) {
        return 0;
    }
    BackgroundLoader* bgl = BackgroundLoader::GetInstance();
    unsigned int n = p->rest3c8;
    if (n == 0) {
        if (p->handle340 >= 0) {
            bgl->RemoveTask(p->handle340);
            p->handle340 = -1;
        }
        p->handle340 = bgl->QueueLoadFile(data_020f1394, 0);
        p->field3cd &= ~8;
        p->field3cd |= 2;
        p->rest3c8 = p->rest3c8 + 1;
    } else {
        void* out1;
        void* file;
        unsigned int length;
        int size;
        if (n == 1 && bgl->GetTaskStatus(p->handle340) != 0) {
            bgl->GetLoadedFileByID(p->handle340, &file, &length);
            int count = CountActiveEntries((struct ActiveEntry02046900*)file);
            p->flag3c8 = _Z27IsPowCnt1Bit15Clear020938ccv();
            int value = func_020937f0(p->flag3c8);
            if (value != 0) {
                struct Ctx020941f8 ctx;
                int i;
                _Z18InitStruct0205a444Pc((char*)&ctx);
                _Z18InitStruct0205a444Pc((char*)&ctx);
                ctx.field50 = (unsigned char)p->flag3c8;
                ctx.field44 = value - 0xa00;
                for (i = 0; i < count; i++) {
                    void* rec;
                    size = 0;
                    rec = FindRecordByIndex((struct Rec020467f0*)file, i, &out1, &size);
                    func_0205a528(&ctx, rec, size, 0);
                }
                _Z23EmptyDestructor0205a494Pv(&ctx);
            }
            bgl->RemoveTask(p->handle340);
            p->handle340 = -1;
            p->field3cd &= ~2;
            p->rest3c8 = 0;
            if (p->field3cb > 0) {
                p->field3cd |= 1;
            }
        }
    }
    return 1;
}