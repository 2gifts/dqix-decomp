#include <globaldefs.h>
#include "Resource/Script.h"

struct Variant02030b0c;
struct Element0209ccc8;
struct ElementList0209ccc8;
void AppendElementCapped0209ccc8(struct ElementList0209ccc8*, struct Element0209ccc8*);
extern int data_02109be0;

// USA: func_0209cb94
ARM int AppendVariantIntToGlobalList_0209cb94(struct Variant02030b0c* p) {
    int value = ((Script::Parameter*)p)->ToInt();
    AppendElementCapped0209ccc8((struct ElementList0209ccc8*)&data_02109be0, (struct Element0209ccc8*)&value);
    return 1;
}
