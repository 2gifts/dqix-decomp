#include <globaldefs.h>

extern "C" void func_ov000_0216d370(char* obj, int flagA, int flagB, int flagC);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void* gs, int id);
void SetFlagOrState0216d530(void*, int);
extern "C" int _ZNK8Object3D9GetRadiusEv(unsigned char* obj);
extern "C" int _ZNK8Object3D9GetHeightEv(void* obj);
extern "C" ARM int Vector3fix_Length(int* v);
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
void ApplyVec3Tail(void* obj, int* vec);

struct Vec3_0216dbf0 { int x, y, z; };
extern Vec3_0216dbf0 data_ov000_02183280;

// USA: func_ov000_0216dbf0
extern "C" ARM void func_ov000_0216dbf0(char* self, int* ids, int count, short flag) {
    func_ov000_0216d370(self, 1, 1, 1);
    *(unsigned char*)(self + 0x220) = 3;

    Vec3_0216dbf0 c = data_ov000_02183280;
    Vec3_0216dbf0 v;
    v.x = 0x5e38;

    void* gs = _ZN9GameState11GetInstanceEv();

    int dist = 0;
    int rad = 0;
    int hgt = 0x2000;

    if (count == 1) {
        void* o = _ZN9GameState20GetGameObjectByIndexEi(gs, *ids);
        if (o != 0) {
            SetFlagOrState0216d530(self, *ids);
            rad = _ZNK8Object3D9GetRadiusEv((unsigned char*)o) >> 1;
            hgt = _ZNK8Object3D9GetHeightEv(o);
        }
    } else {
        for (int i = 0; i < count; i++, ids++) {
            void* o = _ZN9GameState20GetGameObjectByIndexEi(gs, *ids);
            if (o != 0) {
                Vec3_0216dbf0 pos = *(Vec3_0216dbf0*)((char*)o + 0x44);
                int len = Vector3fix_Length((int*)&pos);
                if (dist < len) {
                    dist = len;
                    rad = _ZNK8Object3D9GetRadiusEv((unsigned char*)o) >> 1;
                }
                if (hgt < _ZNK8Object3D9GetHeightEv(o)) {
                    hgt = _ZNK8Object3D9GetHeightEv(o);
                }
            }
        }
    }

    c.y = hgt >> 1;
    v.y = 0x1000;
    int a = (int)((((unsigned long long)((long long)(dist + rad) * 0x3000)) + 0x800ULL) >> 12);
    int b = (int)((((unsigned long long)((long long)hgt * 0x3000)) + 0x800ULL) >> 12);

    if (b < a) {
        v.z = a;
    } else {
        v.z = b;
    }

    if (!(flag != 0)) {
        v.y = 0x1000;
        if (v.z < 0x7000) {
            v.z = 0x7000;
        } else if (v.z > 0x10000) {
            v.y = v.y + (v.z - 0x10000) / 2;
        }
    } else {
        c.y = 0xb85;
        v.y = 0x3999;
        if (v.z < 0xe000) {
            v.z = 0xe000;
        }
    }

    _ZN8Vector3iaSERKS_((int*)(self + 0x10), (int*)&c);
    ApplyVec3Tail(self, (int*)&v);
    *(int*)(self + 0x238) = 0x1c;
    *(int*)(self + 0x23c) = 0x14;
}
