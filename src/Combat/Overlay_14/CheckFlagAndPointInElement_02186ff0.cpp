#include <globaldefs.h>

extern int data_02114e30;
int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);

extern unsigned char data_02114e54;
void SelectCoordsByFlag0x24_02012a84(unsigned char* obj, int* out1, int* out2);

struct Obj2081;
int IsPointInsideElement02080d54(struct Obj2081* obj, int key, int px, int py);

// USA: func_ov014_02186ff0
ARM int CheckFlagAndPointInElement_02186ff0(char* obj) {
	int result = 0;

	if (TestFlag0SetAndFlag1Clear_02012444((unsigned short*)&data_02114e30, 2)) {
		result = 1;
	}

	if (*(&data_02114e54 + 0x55) != 0) {
		int a, b;
		SelectCoordsByFlag0x24_02012a84(&data_02114e54, &a, &b);
		short key = *(short*)(obj + 0x170);
		struct Obj2081* elemObj = *(struct Obj2081**)(obj + 0xc0);
		if (!IsPointInsideElement02080d54(elemObj, key, (short)a, (short)b)) {
			result = 1;
		}
	}

	return result;
}
