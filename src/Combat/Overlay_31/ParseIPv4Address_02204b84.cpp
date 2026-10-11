#include <globaldefs.h>

int ParseDigits_02204b50(char* str, char** endptr);

// USA: func_ov031_02204b84  (semantic: ParseIPv4Address_02204b84)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_02204b84(char* str, unsigned int* out) {
    unsigned int accum = 0;
    char* p = str;
    int octetIndex = 0;
    do {
        char* next;
        int val = ParseDigits_02204b50(p, &next);
        if (p == next)
            return 0;
        p = next;
        if ((unsigned int)val > 0xff)
            goto fail;
        if (octetIndex != 3) {
            unsigned char c = *p;
            p = p + 1;
            if (c != '.')
                goto fail;
        }
        if (octetIndex == 3) {
            if (*(unsigned char*)p != 0)
                goto fail;
        }
        goto accumulate;
fail:
        return 0;
accumulate:
        octetIndex++;
        accum = val | (accum << 8);
    } while (octetIndex < 4);
    *out = accum;
    return 1;
}
