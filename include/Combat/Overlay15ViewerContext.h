#pragma once

class SafeAllocator;
class Object3D;
struct ViewerSlot;
struct Struct205563c;

struct Obj0218c274
{
    char* viewer_;
    ViewerSlot* slot_;
    SafeAllocator* allocators_;
    const char* name_;
    void* monster_;
    void* buffer_;
    unsigned int bufferSize_;
    unsigned char kind_;
    char unknown1d_[3];
    int* parts_;
    Object3D* objects_;
    Struct205563c* effect_;
    char unknown2c_[0xc];
    short motion_;
    unsigned char unknown3a_;
    unsigned char flag3b_;
    char unknown3c_[0xc];
    int field48_;
    char unknown4c_[0x10];
};

extern "C" int func_ov015_0218bcb0(void*);
extern "C" void func_ov015_0218f0c4(void*);
extern "C" void func_ov015_0218c274(Obj0218c274*, char*, int);
extern "C" void func_ov015_0218c920(void*, int);
