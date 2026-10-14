#include <globaldefs.h>

struct Entry0207d9bc { unsigned short id; unsigned short pad; unsigned int a; unsigned int b; };
void* GetData02108ea8_0207d78c(void);
int CheckEntryBytes0207d978(Entry0207d9bc* arr, unsigned short key);
Entry0207d9bc* FindEntryByHalfword(Entry0207d9bc* arr, unsigned short key);

// USA: func_ov017_021c5bf8
ARM int CheckByteAtIndex_021c5bf8(int index, int keyIn) {
	if (index >= 4)
		goto zero;
	{
	Entry0207d9bc* arr = (Entry0207d9bc*)GetData02108ea8_0207d78c();
	if (!CheckEntryBytes0207d978(arr, (unsigned short)keyIn))
		goto zero;
	{
	Entry0207d9bc* e = FindEntryByHalfword(arr, (unsigned short)keyIn);
	if (e != NULL) {
		signed char v = *((signed char*)e + index + 8);
		if (v != -1)
			return 1;
	}
	}
	}
zero:
	return 0;
}
