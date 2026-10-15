#include <globaldefs.h>
#include "Resource/MessageSystem.h"

struct TaggedNumber02184c30 {
    int type;
    union { int integer; float real; } value;
};
int GetTaggedValueAsInt_02184c30(TaggedNumber02184c30* value);
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021849c8(void* context);
extern "C" void* func_ov023_021f6880(void* list, int key);
#if defined(jpn)
extern "C" int func_ov023_021f6f10(void* node);
#else
int ScaleStatsIfType12_021f6f10(void* node);
#endif
extern "C" void* func_ov023_021fa598(void* node);
int GetGlobalField0x1c020421a0();
struct TableA68;
void* FindEntryByKey_02072a68(TableA68* table, int key);

// USA: func_ov011_021873c4
extern "C" ARM int func_ov011_021873c4(TaggedNumber02184c30* arguments) {
    int nodeKey = GetTaggedValueAsInt_02184c30(&arguments[0]);
    int textKey = GetTaggedValueAsInt_02184c30(&arguments[1]);
    void* context = func_ov017_021b2164();
    void* list = func_ov011_021849c8(context);
    void* node = func_ov023_021f6880(list, nodeKey);
    if (!node) return 1;
#if defined(jpn)
    if (func_ov023_021f6f10(node) != 4) return 1;
#else
    if (ScaleStatsIfType12_021f6f10(node) != 4) return 1;
#endif
    TableA68* texts = (TableA68*)func_ov023_021fa598(node);
    if (!texts) return 1;
    MessageSystem* messages = (MessageSystem*)GetGlobalField0x1c020421a0();
    const char* text = (const char*)FindEntryByKey_02072a68(texts, (short)textKey);
#if defined(jpn)
    func_0204500c(messages, text, 0);
    *(int*)((char*)messages + 0x868) = 1;
    messages->flags17ff.flag4 = 1;
#else
    func_0204500c(messages, text, 0, 0xe3);
    *(int*)((char*)messages + 0x998) = 1;
    messages->b19d2 = 1;
#endif
    return 1;
}
