#include <globaldefs.h>
#include "std_library_functions.h"
#include "Graphics/Vector.h"

extern char data_ov001_02164d10[];

struct InitStruct02158828 {
    int f0;
    unsigned char arr1[0xc];
    unsigned char arr2[0xc];
    int f1c;
    int f20;
    int f24;
    char str28[0x20];
    void* f48;
};

extern "C" ARM void _Z17InitEntry02158828P18InitStruct02158828(struct InitStruct02158828* obj);

struct BattleCamera_021588e4 {
    InitStruct02158828* entries;
    int entryCount;
    int field_0x8;
    int field_0xc;
    int field_0x10;
    int field_0x14;
    int field_0x18;
    int field_0x1c;
    int field_0x20;
    int field_0x24;
    int field_0x28;
    int field_0x2c;
    int field_0x30;
    int field_0x34;
    int timer;
    int field_0x3c;
    int field_0x40;
    int shakeFrame;
    int field_0x48;
    Vector3fix eye;
    Vector3fix target;
    int field_0x64;
    int field_0x68;
    int field_0x6c;
    int field_0x70;
    int field_0x74;
    int field_0x78;
    Vector3fix field_0x7c;
    int field_0x88;
    int field_0x8c;
    int field_0x90;
    char name[0x20];
    Vector3fix eyeVelocity;
    Vector3fix targetVelocity;
    int field_0xcc;
    int field_0xd0;
    int field_0xd4;
    int field_0xd8;
    Vector3fix field_0xdc;
    Vector3fix field_0xe8;
    Vector3fix field_0xf4;
    Vector3fix field_0x100;
    int field_0x10c;
    Vector3fix eyeVelocityCopy;
    Vector3fix targetVelocityCopy;
    Vector3fix field_0x128;
    int shakeActive;
    Vector3fix shakeAmplitude;
    Vector3fix savedEye;
    Vector3fix savedTarget;
    char pad_0x15c[0x8c4];
    void* field_0xa20;
    int field_0xa24;
};

// USA: func_ov001_021588e4
extern "C" ARM void func_ov001_021588e4(BattleCamera_021588e4* cam) {
    cam->field_0x34 = cam->field_0x30 = 0;
    cam->timer = 0;
    cam->field_0x3c = 0;
    cam->field_0x40 = 0;
    cam->shakeFrame = 0;
    cam->field_0x48 = 0;
    memset(&cam->eye, 0, sizeof(Vector3fix));
    memset(&cam->target, 0, sizeof(Vector3fix));
    cam->field_0x6c = 0;
    cam->field_0x68 = 0;
    cam->field_0x64 = 0;
    cam->field_0x70 = 0;
    cam->field_0x74 = -1;
    cam->field_0x78 = 0;
    memset(&cam->field_0x7c, 0, sizeof(Vector3fix));
    strcpy(cam->name, data_ov001_02164d10);
    cam->field_0x90 = 0;
    cam->field_0x8c = 0;
    cam->field_0x88 = 0;
    memset(&cam->eyeVelocity, 0, sizeof(Vector3fix));
    memset(&cam->targetVelocity, 0, sizeof(Vector3fix));
    cam->field_0xd8 = 0;
    cam->field_0xd4 = 0;
    cam->field_0xcc = 0;
    memset(&cam->field_0xdc, 0, sizeof(Vector3fix));
    memset(&cam->field_0xe8, 0, sizeof(Vector3fix));
    memset(&cam->field_0xf4, 0, sizeof(Vector3fix));
    memset(&cam->field_0x100, 0, sizeof(Vector3fix));
    cam->field_0x10c = 0;
    memset(&cam->eyeVelocityCopy, 0, sizeof(Vector3fix));
    memset(&cam->targetVelocityCopy, 0, sizeof(Vector3fix));
    memset(&cam->field_0x128, 0, sizeof(Vector3fix));
    cam->shakeActive = 0;
    cam->field_0xa24 = 0;
    memset(&cam->shakeAmplitude, 0, sizeof(Vector3fix));
    memset(&cam->savedEye, 0, sizeof(Vector3fix));
    memset(&cam->savedTarget, 0, sizeof(Vector3fix));
    cam->field_0x8 = 0;
    cam->field_0xc = 0;
    cam->field_0x10 = 0;
    cam->field_0x14 = 0;
    cam->field_0x18 = 0;
    cam->field_0x1c = 0;
    cam->field_0x20 = 0;
    cam->field_0x24 = 0;
    cam->field_0x28 = 0;
    cam->field_0x2c = 0;
    cam->field_0xa20 = NULL;
    if (cam->entries == NULL || cam->entryCount <= 0) {
        return;
    }
    for (int i = 0; i < cam->entryCount; i++) {
        _Z17InitEntry02158828P18InitStruct02158828(&cam->entries[i]);
    }
}
