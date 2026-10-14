#include <globaldefs.h>

struct IntField0x68_020377bc {
	char unk[0x68];
	int field;
};
extern "C" int _ZNK8Object3D9GetHeightEv(struct IntField0x68_020377bc* obj);
extern "C" int _ZNK8Object3D9GetRadiusEv(unsigned char* obj);

int fix32abs(int x);

struct Vec3s32_020c3030 { int x; int y; int z; };
extern "C" int Vector3fix_Distance(struct Vec3s32_020c3030* a, struct Vec3s32_020c3030* b);

// USA: func_ov017_02194140  (semantic: CheckOverlap_02194140)
extern "C" ARM int func_ov017_02194140(unsigned char* self, unsigned char* other) {
	int extSelf = _ZNK8Object3D9GetHeightEv((struct IntField0x68_020377bc*)self);
	int extOther = _ZNK8Object3D9GetHeightEv((struct IntField0x68_020377bc*)other);

	if (!(*(int*)(self + 0x48) + extSelf >= *(int*)(other + 0x48) &&
	      *(int*)(other + 0x48) + extOther >= *(int*)(self + 0x48))) return 0;

	int half = (_ZNK8Object3D9GetRadiusEv(self) >> 1) + (_ZNK8Object3D9GetRadiusEv(other) >> 1);

	if (half < fix32abs(*(int*)(self + 0x44) - *(int*)(other + 0x44)) ||
	    half < fix32abs(*(int*)(self + 0x4c) - *(int*)(other + 0x4c))) return 0;

	int d = Vector3fix_Distance((struct Vec3s32_020c3030*)(self + 0x44), (struct Vec3s32_020c3030*)(other + 0x44));
	return half >= d;
}
