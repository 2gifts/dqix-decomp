#include <globaldefs.h>

extern "C" ARM int func_ov031_0223e38c(unsigned char* dst, const signed char* src, int max);
extern const int data_ov031_022493c4[];

// USA: func_ov031_0223e454
extern "C" ARM int func_ov031_0223e454(unsigned char* dst, const signed char* src, int n) {
	unsigned char s[3];
	int total = 0;
	int got = func_ov031_0223e38c(s, src, n > 3 ? 3 : n);
	if (got > 0) {
		do {
			if (n < 3) s[2] = 0;
			if (n < 2) s[1] = 0;
			unsigned char b = s[1];
			const unsigned char a = s[0];
			unsigned char c = s[2];
			int v0 = (a >> 2) & 0xff;
			int v1 = ((a << 4) | (b >> 4)) & 0x3f;
			int v2 = (b << 2) | (c >> 6);
			int v2m = v2 & 0x3f;
			int v3 = c & 0x3f;
			dst[0] = ((const signed char*)data_ov031_022493c4)[v0];
			dst[1] = ((const signed char*)data_ov031_022493c4)[v1];
			dst[2] = got > 1 ? ((const signed char*)data_ov031_022493c4)[v2m] : '*';
			src += got;
			total += 4;
			dst[3] = got > 2 ? ((const signed char*)data_ov031_022493c4)[v3] : '*';
			dst += 4;
			n -= got;
		} while (n != 0 && (got = func_ov031_0223e38c(s, src, n > 3 ? 3 : n)) > 0);
	}
	*dst = 0;
	return total;
}
