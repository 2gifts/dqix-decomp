#include <globaldefs.h>
#include "System/Matrix.h"

extern Vector3i data_0210a250;
extern Vector3i data_0210a25c;
extern Vector3i data_0210a268;
extern Matrix4x3 data_0210a05c;
struct Field0xfc_02196048 { char pad[0xfc]; int fld; };
extern struct Field0xfc_02196048 data_0210a010;

// USA: func_ov017_02196048
ARM void CopyVec3sAndDispatch_02196048(int* a, int* b, int* c) {
	data_0210a250 = *(Vector3i*)a;
	data_0210a25c = *(Vector3i*)b;
	data_0210a268 = *(Vector3i*)c;
	Mat4x3_WriteViewMatrix((Vector3i*)a, (Vector3i*)b, (Vector3i*)c, &data_0210a05c);
	data_0210a010.fld &= ~0xe8;
}
