#include <globaldefs.h>

struct PackedFields;
int MatchesPackedFields_020de3ac(struct PackedFields* obj, int a, int unused, int b);

struct MatchPackedFields;
int MatchesFieldAAndLow_020de38c(struct MatchPackedFields* obj, int a, int b);

struct BitTriple020de3cc;
int MatchThreeBitfieldsAt0x10(struct BitTriple020de3cc* obj, int a, int b, int c);

// USA: func_020de524
ARM void SelectMatchFnByWildcard020de524(int a, int b, void** out) {
    if (a == 999) {
        if (b == 999) {
            *out = 0;
        } else {
            *out = (void*)MatchesPackedFields_020de3ac;
        }
    } else {
        if (b == 999) {
            *out = (void*)MatchesFieldAAndLow_020de38c;
        } else {
            *out = (void*)MatchThreeBitfieldsAt0x10;
        }
    }
}
