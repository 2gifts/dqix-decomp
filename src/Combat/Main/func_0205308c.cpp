#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

#if defined(jpn)
#define data_020e7bf8 data_020e85d0
extern char data_020f04d0;
#endif

struct Field150Holder02052e2c;

struct Obj0205308c {
#if defined(jpn)
    char pad[0x174];
#else
    char pad[0x180];
#endif
    int f180;
    char pad184[0x194 - 0x184];
    int f194;
};

extern "C" short* _Z28GetField150Ptr0x488_02052e2cP22Field150Holder02052e2c(struct Field150Holder02052e2c*);
extern "C" void* func_02012fe4(void);
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void* obj);
extern "C" void VectorizedMemset(void* dst, int value, unsigned int size);

extern signed char data_020e7bf8[];
extern char data_020f0434;
extern char data_020f044c;
extern char data_020f045c;
extern char data_020f0467;

struct EntryBits0205308c {
    unsigned char maleBit : 1;
    unsigned char rest : 7;
};

// USA: func_0205308c
extern "C" ARM void func_0205308c(void* obj, int val) {
    struct Obj0205308c* self = (struct Obj0205308c*)obj;
    char buf[0x50];
    short* entries = _Z28GetField150Ptr0x488_02052e2cP22Field150Holder02052e2c((struct Field150Holder02052e2c*)obj);
    BackgroundLoader* loader;
    int flag;

    sprintf(buf, &data_020f0434, val, data_020e7bf8[((struct EntryBits0205308c*)((char*)entries + 0x14))->maleBit]);

    loader = BackgroundLoader::GetInstance();
    if (self->f180 > BackgroundLoader::TaskStatus_Invalid) {
        loader->RemoveTask(self->f180);
        self->f180 = -1;
    }
    self->f180 = loader->QueueLoadFile(buf, 0);

    {
        unsigned short gid = *(unsigned short*)func_02012fe4();
        if (gid != _ZNK8Object3D10GetField06Ev(obj)) {
            return;
        }
    }

#if defined(jpn)
    if (val != 0xc && val != 0xd && val != 0xe &&
        val != 0xf && val != 0x10 && val != 0x1e) {
        return;
    }
    VectorizedMemset(buf, 0, 0x50);
    sprintf(buf, &data_020f04d0, val);
#else
    flag = 0;
    switch (val) {
        case 0xc:
        case 0xd:
        case 0xe:
            VectorizedMemset(buf, 0, 0x50);
            sprintf(buf, &data_020f044c, val);
            flag = 1;
            break;
        case 0xf:
        case 0x10:
        case 0x1e:
            VectorizedMemset(buf, 0, 0x50);
            sprintf(buf, &data_020f045c, val);
            flag = 1;
            break;
    }

    if (flag == 0) {
        return;
    }
#endif
    if (self->f194 > BackgroundLoader::TaskStatus_Invalid) {
        loader->RemoveTask(self->f194);
        self->f194 = -1;
    }
#if defined(jpn)
    self->f194 = loader->QueueLoadFile(buf, 0);
#else
    self->f194 = loader->QueueLoadFileInGP2(&data_020f0467, buf, 0);
#endif
}
