#include <globaldefs.h>

int CompareBytes_020d3044(const unsigned char* a, const unsigned char* b, int n);

// USA: func_ov031_0223fb54
ARM int CompareBytesThunk_0223fb54(const unsigned char* a, const unsigned char* b, int n) {
	return CompareBytes_020d3044(a, b, n);
}
