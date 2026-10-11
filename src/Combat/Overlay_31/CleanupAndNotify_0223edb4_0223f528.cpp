#include <globaldefs.h>

typedef void* (*AllocFn02290dac)(int, int);
extern AllocFn02290dac data_ov031_02290dac;
extern void (*data_ov031_02290dc0)(void*);
extern int data_ov031_02290dbc;
extern int data_ov031_02249430;
extern int data_ov031_0224c754;

extern "C" {
	int func_ov031_0223fb48(const char* s);
	int func_ov031_0223e454(void* dst, const void* src, int n);
	int func_ov031_02240074(void* obj, void* entry, void* val);
	int func_ov031_0223ede0(void** p0, void** p1, void* p2, void* p3, int p4, const char* p5);
}
struct Container0223f188 { int field0; };
extern "C" int func_ov031_0223f188(Container0223f188* p0, void* p1);
struct Obj02240df4;
ARM void CleanupAndNotify_0223edb4(void* p0, struct Obj02240df4* p1);
ARM int DivBy3Times4_0223e438(int x);

struct NodeStruct0223f528 {
	unsigned char pad0[4];
	int field4;
	unsigned char pad1[8];
	void* field10;
	int field14;
};

struct NameObj0223f528 {
	unsigned char pad0[0xac];
	unsigned int fieldAc;
};

// USA: func_ov031_0223f528  (semantic: RegisterNamedEntryAtIndex_0223f528)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_0223f528(const char* name, void* val1, unsigned int idx, const char* val3) {
	if (idx < ((NameObj0223f528*)name)->fieldAc) {
		data_ov031_02290dbc = 7;
		return 0;
	}

	int len = func_ov031_0223fb48(name);
	if (len > 0x20) {
		data_ov031_02290dbc = 7;
		return 0;
	}

	int n;
	if (len <= 0) {
		n = 0;
	} else {
		n = DivBy3Times4_0223e438(len);
	}

	void* buf = data_ov031_02290dac(n + 1, 4);
	if (!buf) {
		data_ov031_02290dbc = 1;
		return 0;
	}

	NodeStruct0223f528* node;
	void* obj;
	if (!func_ov031_0223ede0((void**)&node, &obj, &data_ov031_02249430, val1, ((NameObj0223f528*)name)->fieldAc, val3)) {
		data_ov031_02290dc0(buf);
		return 0;
	}

	if (n > 0) {
		int n2 = func_ov031_0223e454(buf, name, len);
		((unsigned char*)buf)[n2] = 0;
		if (!func_ov031_02240074(obj, &data_ov031_0224c754, buf)) {
			goto cleanup;
		}
	}

	node->field4 = 3;
	node->field10 = buf;
	node->field14 = ((NameObj0223f528*)name)->fieldAc;
	if (func_ov031_0223f188((Container0223f188*)node, obj)) {
		return 1;
	}
	data_ov031_02290dc0(buf);
	return 0;

cleanup:
	CleanupAndNotify_0223edb4(node, (struct Obj02240df4*)obj);
	data_ov031_02290dc0(buf);
	data_ov031_02290dbc = 1;
	return 0;
}
