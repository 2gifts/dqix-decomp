#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, int);
#if defined(jpn)
extern "C" int func_ov023_021f6f10(void* self);
#else
int ScaleStatsIfType12_021f6f10(void* self);
#endif
extern char* data_ov004_021707c0; // pointer to struct with fields at 0x78 (short), 0x7a (short)
extern "C" short func_ov004_021537e0(void);
extern "C" short func_ov004_02153860(void);
extern "C" short func_ov004_021538f0(void);

// Real virtual calls: index 0x3c/4=15 (MethodNotify), index 0xec/4=59 (CallEc).
class VObj02154c78 {
public:
	virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
	virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
	virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
	virtual void v12(); virtual void v13(); virtual void v14();
	virtual void MethodNotify0x3c(int a);
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
	virtual void v56(); virtual void v57(); virtual void v58();
	virtual void CallEc();
};

// USA: func_ov004_02154c78
ARM int NotifyChainIfConditions_02154c78(void* self) {
	VObj02154c78* node = (VObj02154c78*)func_ov023_021f6880(func_ov011_021849c8(self), 0x39);
	if (!node) return 0;
#if defined(jpn)
	if (func_ov023_021f6f10(node) != 0x12) return 0;
#else
	if (ScaleStatsIfType12_021f6f10(node) != 0x12) return 0;
#endif

	node->CallEc();
	if (!node) return 0;

	if (*(short*)(data_ov004_021707c0 + 0x7a) == 0) {
		VObj02154c78* n2 = (VObj02154c78*)func_ov023_021f6880(func_ov011_021849c8(self), 0x1a);
		if (n2) n2->MethodNotify0x3c(0);
	}

	if (func_ov004_021537e0() == 0) {
		VObj02154c78* n2 = (VObj02154c78*)func_ov023_021f6880(func_ov011_021849c8(self), 0x1b);
		if (n2) n2->MethodNotify0x3c(0);
	}

	if (func_ov004_02153860() == 0) {
		VObj02154c78* n2 = (VObj02154c78*)func_ov023_021f6880(func_ov011_021849c8(self), 0x1c);
		if (n2) n2->MethodNotify0x3c(0);
	}

	if (func_ov004_021538f0() == 0) {
		VObj02154c78* n2 = (VObj02154c78*)func_ov023_021f6880(func_ov011_021849c8(self), 0x1d);
		if (n2) n2->MethodNotify0x3c(0);
	}

	return 0;
}
