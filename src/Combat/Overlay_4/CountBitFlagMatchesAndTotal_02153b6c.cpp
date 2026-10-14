#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
extern "C" int func_ov023_021f6f10(void*);
extern "C" void* func_0205ec34(void);
extern "C" int func_020deb58(void*, int, int, int, int);
extern "C" void* func_020dec30(void*, int, int, int, int, int);
extern int TestBitInByteArray_0206dfb0(int unused, unsigned char* arr, int index);

class VObj02153b6c {
public:
	virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
	virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
	virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
	virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
	virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
	virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
	virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
	virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
	virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
	virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
	virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
	virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
	virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
	virtual void v56(); virtual void v57();
	virtual void* Method58();
};

struct Entry02153b6c {
    unsigned int pad0;
    unsigned int pad4;
    unsigned int pad8;
    unsigned int fieldC;
};

// USA: func_ov004_02153b6c  (semantic: CountBitFlagMatchesAndTotal_02153b6c)
extern "C" ARM void func_ov004_02153b6c(void* obj, int arg1, int arg2, int arg3, short* out1, short* out2) {
    void* node = func_ov023_021f6880(func_ov011_021849c8(obj), 0x2d);
    if (node) {
        if (func_ov023_021f6f10(node) == 0x11) {
            void* obj2 = ((VObj02153b6c*)node)->Method58();
            void* ptr = func_0205ec34();
            int count = func_020deb58(obj2, 1, arg1, arg2, arg3);

            short matchCount = 0;
            short i;
            for (i = 0; i < count; i++) {
                struct Entry02153b6c* entry = (struct Entry02153b6c*)func_020dec30(obj2, i, 1, arg1, arg2, arg3);
                if (entry) {
                    int extracted = (entry->fieldC << 9) >> 21;
                    extracted = (unsigned short)extracted;
                    if (extracted > 0) {
                        if (TestBitInByteArray_0206dfb0((int)ptr, (unsigned char*)ptr + 0x8c, extracted + 0x76 + 0xc00)) {
                            matchCount++;
                        }
                    }
                }
            }
            *out1 = matchCount;
            *out2 = (short)count;
        }
    }
}
