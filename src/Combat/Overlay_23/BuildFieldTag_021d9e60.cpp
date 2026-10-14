#if defined(jpn)
#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/CharacterCreationUI.h"
#include "Combat/TryApplyElemFields.h"

struct Struct_0205d81c;
struct Elem_0205d81c {
    unsigned char unknown000[0xb8];
    unsigned short fieldB8;
    unsigned short fieldBA;
    unsigned char unknown0bc[8];
    unsigned char fieldC4;
    unsigned char unknown0c5[0xe0 - 0xc5];
};
Elem_0205d81c* FindElementByC40205d81c(Struct_0205d81c*, int);
int GetFieldByKey020e0434(Container020e0310*, int);
int AppendString02042058(char*, const char*);
extern "C" int func_02042428(char*, int);

// USA: 021d9e60; JPN: 021da6f0.
ARM void BuildFieldTag_021d9e60(char* obj) {
    CharacterCreationUI* self = (CharacterCreationUI*)obj;
    if (!(self->flags & 0x8000)) return;
    memset(self->textBuffer, 0, 0x800);
    if (self->state == 8) {
        Elem_0205d81c* elem = FindElementByC40205d81c((Struct_0205d81c*)&self->windows[1], 3);
        elem->fieldB8 = 0x11;
        elem->fieldBA = 0x10;
        func_02042428(self->textBuffer, 12);
        AppendString02042058(self->textBuffer, self->names[self->sex]);
    } else {
        int field = GetFieldByKey020e0434(&self->texts, 0x4274);
        AppendString02042058(self->textBuffer, (const char*)field);
    }
    TryApplyElemFields0205d5d0((StructA0205d5d0*)&self->windows[1], 3, (int)self->textBuffer, 0);
    self->flags &= ~0x8000;
}
#else
#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_0205d81c;
struct Elem_0205d81c;
Elem_0205d81c* FindElementByC40205d81c(Struct_0205d81c*, int);

struct StructA0205d5d0;
int TryApplyElemFields0205d5d0(StructA0205d5d0*, int, int, int, unsigned char);

struct Container020e0310;
int GetFieldByKey020e0434(Container020e0310*, int);

int AppendString02042058(char*, const char*);
int AppendXTag_02041a28(char*, int);

extern "C" void __clear(void*, int);
extern "C" int func_020426bc(void*, void*, int);
extern "C" void func_02042764(void*, void*, int);
extern "C" int func_020420e8(void*, int);

// USA: func_ov023_021d9e60
ARM void BuildFieldTag_021d9e60(char* obj) {
	if (!(*(int*)(obj + 0xd9c) & 0x8000)) return;
	char* buf = *(char**)(obj + 0xf8);
	memset(buf, 0, 0x960);
	if (*(signed char*)(obj + 0xc58) == 8) {
		Elem_0205d81c* elem = FindElementByC40205d81c((Struct_0205d81c*)(obj + 0x2b4), 3);
		*(unsigned short*)((char*)elem + 0xb8) = 0x11;
		*(unsigned short*)((char*)elem + 0xba) = 0x10;
		char nameBuf[0x80];
		char outBuf[0x80];
		__clear(nameBuf, 0x80);
		__clear(outBuf, 0x80);
		int idx = *(unsigned char*)(obj + 0xda3);
		int* arr = *(int**)(obj + 0xdb0);
		int i = func_020426bc((void*)arr[idx], nameBuf, 0);
		for (; i < 8; i++) nameBuf[i] = *(unsigned char*)(obj + 0xdb4);
		func_02042764(nameBuf, outBuf, 0);
		int len = func_020420e8(outBuf, 0);
		AppendXTag_02041a28(buf, (0x50 - len) >> 1);
		AppendString02042058(buf, outBuf);
	} else {
		int val = GetFieldByKey020e0434((Container020e0310*)(obj + 0xe0), 0x4274);
		AppendString02042058(buf, (const char*)val);
	}
	TryApplyElemFields0205d5d0((StructA0205d5d0*)(obj + 0x2b4), 3, (int)buf, 0, 0);
	*(int*)(obj + 0xd9c) &= ~0x8000;
}

#endif
