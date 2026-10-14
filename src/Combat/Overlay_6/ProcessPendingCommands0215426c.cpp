#include <globaldefs.h>

extern "C" void Mat4x3_Multiply(void* a, void* b, void* c);
struct Matrix3x3;
struct Matrix4x3;
void GetCurrentPositionAndDirectionMatrices(Matrix4x3*, Matrix3x3*);
extern "C" void* _ZN12RenderConfig20GetInverseViewMatrixEv(void);
extern int data_ov006_02160380[3];
extern int data_ov006_0216038c[3];

struct Obj0215426c {
	char pad0[0x8];
	unsigned int flags8;
	char pad1[0xae - 0xc];
	unsigned char byteAe;
};

// USA: func_ov006_0215426c
ARM void ProcessPendingCommands0215426c(Obj0215426c* o) {
	if (!(o->flags8 & 0x10)) {
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (data_ov006_02160380[i] == ((o->flags8 & 0x10) ? o->byteAe : -1) && data_ov006_0216038c[i] != 0) {
			GetCurrentPositionAndDirectionMatrices((Matrix4x3*)data_ov006_0216038c[i], (Matrix3x3*)NULL);
			void* obj2 = _ZN12RenderConfig20GetInverseViewMatrixEv();
			Mat4x3_Multiply((void*)data_ov006_0216038c[i], obj2, (void*)data_ov006_0216038c[i]);
		}
	}
}
