#include <globaldefs.h>
#include "World/Object3D.h"

struct Outer02077a20;
int GetField0x8OrDefault02077a20(struct Outer02077a20* p);

int fix32abs(int x);

// USA: func_ov017_02196fc8
ARM int CheckProximity_02196fc8(unsigned char* self, unsigned char* other, int extra) {
	int a = ((Object3D*)self)->GetRadius();
	int half;

	if (*(unsigned short*)other & 0x20) {
		int vx15 = ((Object3D*)other)->GetScale().x * 15;
		int halfScale = GetField0x8OrDefault02077a20((struct Outer02077a20*)other) >> 1;
		half = (int)(((long long)halfScale * vx15 + 0x800) >> 12);
	} else {
		half = ((Object3D*)other)->GetRadius() >> 1;
	}

	int dist = extra + (half + (a >> 1));

	if (dist < fix32abs(*(int*)(self + 0x44) - *(int*)(other + 0x44))) return 0;
	if (dist < fix32abs(*(int*)(self + 0x4c) - *(int*)(other + 0x4c))) return 0;

	int d = Vector3fix_Distance((const Vector3fix*)(self + 0x44), (const Vector3fix*)(other + 0x44));
	if (dist < d) return 0;

	return d != 0;
}
