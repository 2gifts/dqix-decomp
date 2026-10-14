#include <globaldefs.h>

extern "C" int _ZNK8Object3D9GetRadiusEv(unsigned char* obj);

struct Vec3i_02196fc8 { int x; int y; int z; };
extern "C" Vec3i_02196fc8 _ZNK8Object3D8GetScaleEv(unsigned char* src);

struct Outer02077a20;
int GetField0x8OrDefault02077a20(struct Outer02077a20* p);

int fix32abs(int x);

struct Vec3s32_020c3030;
extern "C" int Vector3fix_Distance(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);

// USA: func_ov017_02196fc8
ARM int CheckProximity_02196fc8(unsigned char* self, unsigned char* other, int extra) {
	int a = _ZNK8Object3D9GetRadiusEv(self);
	int half;

	if (*(unsigned short*)other & 0x20) {
		int vx15 = _ZNK8Object3D8GetScaleEv(other).x * 15;
		int halfScale = GetField0x8OrDefault02077a20((struct Outer02077a20*)other) >> 1;
		half = (int)(((long long)halfScale * vx15 + 0x800) >> 12);
	} else {
		half = _ZNK8Object3D9GetRadiusEv(other) >> 1;
	}

	int dist = extra + (half + (a >> 1));

	if (dist < fix32abs(*(int*)(self + 0x44) - *(int*)(other + 0x44))) return 0;
	if (dist < fix32abs(*(int*)(self + 0x4c) - *(int*)(other + 0x4c))) return 0;

	int d = Vector3fix_Distance((struct Vec3s32_020c3030*)(self + 0x44), (struct Vec3s32_020c3030*)(other + 0x44));
	if (dist < d) return 0;

	return d != 0;
}
