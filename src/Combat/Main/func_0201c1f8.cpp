#include <globaldefs.h>
#include "Resource/Script.h"

struct Queue_0201c4d4;
struct ScriptRecord {
    unsigned short id_, value_;
    unsigned char history_;
    char name_[8], text_[28];
    unsigned char category_ : 3;
    unsigned char flag3_ : 1;
    unsigned char flag4_ : 1;
    unsigned char flag5_ : 1;
    unsigned char flag6_ : 1;
    unsigned char flag7_ : 1;
    unsigned char mode_;
    void SetId(unsigned short v) { id_ = v; }
    void SetValue(unsigned short v) { value_ = v; }
    void SetCategory(unsigned char v) { category_ = v; }
    void SetMode(unsigned char v) { mode_ = v; }
    void SetFlag3(unsigned char v) { flag3_ = v; }
    void SetFlag4(unsigned char v) { flag4_ = v; }
    void SetFlag5(unsigned char v) { flag5_ = v; }
    void SetFlag6(unsigned char v) { flag6_ = v; }
    void SetFlag7(unsigned char v) { flag7_ = v; }
};
struct ScriptQueues { void* fields_[2]; Queue_0201c4d4* queue_; };
extern ScriptQueues data_020fdc14 __attribute__((aligned(4)));
extern "C" void func_0201c4d4(Queue_0201c4d4*, ScriptRecord*);

// USA: func_0201c1f8
extern "C" ARM int func_0201c1f8(Script::Parameter* params) {
    ScriptRecord record;
    int result = 0;
    record.id_ = 0;
    record.value_ = 0;
    record.name_[0] = 0;
    record.history_ = 0;
    record.category_ = 0;
    record.flag4_ = 1;
    record.flag3_ = 0;
    record.flag5_ = 0;
    record.flag6_ = 0;
    record.flag7_ = 0;
    record.SetId(params[0].ToInt());
    record.SetValue(params[1].ToInt());
    const char* label = params[2].ToString();
    record.SetCategory(params[3].ToInt());
    const char* name = params[4].ToString();
    const char* text = params[5].ToString();
    record.SetMode(params[6].ToInt());
    record.SetFlag4(params[7].ToInt());
    record.SetFlag3(params[8].ToInt());
    record.SetFlag5(params[9].ToInt());
    record.SetFlag6(params[10].ToInt());
    record.SetFlag7(params[11].ToInt());
    if (text == NULL) {
        result = 0;
    } else {
        memcpy(record.name_, name, sizeof(record.name_));
        record.name_[7] = 0;
        memcpy(record.text_, text, sizeof(record.text_));
        ScriptQueues* queues = &data_020fdc14;
        Queue_0201c4d4* queue = queues->queue_;
        record.text_[27] = 0;
        func_0201c4d4(queue, &record);
        result = 1;
    }
    return result;
}
