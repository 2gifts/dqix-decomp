#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;
struct WordList0209ccec;
void AllocateWordList0209ccec(struct WordList0209ccec*, int);
extern int data_02109be0;

// USA: func_0209cb74
ARM int AllocateGlobalWordListFromVariant_0209cb74(struct Variant02030b0c* p) {
    AllocateWordList0209ccec((struct WordList0209ccec*)&data_02109be0, ((Script::Parameter*)p)->ToInt());
    return 1;
}
