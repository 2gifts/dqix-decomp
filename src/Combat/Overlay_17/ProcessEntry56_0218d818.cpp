#if defined(jpn)
enum {regionalOffset0=0x13b, regionalOffset1=0x4136, regionalOffset2=0x4137, regionalOffset3=0x4138, regionalOffset4=0x413a};
#else
enum {regionalOffset0=0x35b, regionalOffset1=0x4356, regionalOffset2=0x4357, regionalOffset3=0x4358, regionalOffset4=0x435a};
#endif
#include <globaldefs.h>

void* GetData02153637(void);
struct Container020e34bc;
int GetEntryStatusForKey020e34bc(struct Container020e34bc* obj, int key);
void Dispatch020e3428(void* a, int b);
void ClearFields0to5_0218d7fc(unsigned char* obj);
struct Entry020e3054;
void ClearEntryIfCurrentArrMatches020e3468(struct Entry020e3054* list, int key);
void SetName56AndFlag_0218d7b0(unsigned char* obj, char* name);

extern "C" void func_ov017_0218d2f0(int a, int b, int c, int d);

// JPN: func_ov017_0218e3f8
// USA: func_ov017_0218d818
ARM void ProcessEntry56_0218d818(unsigned char* obj) {
	if (obj[0x4000 + regionalOffset0] != 1) return;
	void* ctx = GetData02153637();
	int status = GetEntryStatusForKey020e34bc((struct Container020e34bc*)ctx, 1);
	if (status == 1) {
		func_ov017_0218d2f0(obj[regionalOffset1], obj[regionalOffset2], *(unsigned short*)(obj + regionalOffset3), obj[regionalOffset4]);
		Dispatch020e3428(ctx, 1);
		ClearFields0to5_0218d7fc(obj + regionalOffset1);
	} else if ((unsigned int)(status - 3) <= 2) {
		ClearEntryIfCurrentArrMatches020e3468((struct Entry020e3054*)ctx, 1);
		unsigned short buf[3];
		buf[0] = *(unsigned short*)(obj + regionalOffset1);
		buf[1] = *(unsigned short*)(obj + regionalOffset3);
		buf[2] = *(unsigned short*)(obj + regionalOffset4);
		SetName56AndFlag_0218d7b0(obj, (char*)buf);
	}
}
