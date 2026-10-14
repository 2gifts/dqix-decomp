#include <globaldefs.h>
void RunBufferedScript_02028048(int, int, struct StreamHeader*, int);

struct Struct0202811c;
void CheckAllPairsEqual0202811c(struct Struct0202811c* s);

// USA: func_02028104
ARM void ProcessAndCheckPairs02028104(struct Struct0202811c* s, int b, int c, int d) {
    RunBufferedScript_02028048((int)(s), (int)(b), (struct StreamHeader*)(c), (int)(d));
    CheckAllPairsEqual0202811c(s);
}
