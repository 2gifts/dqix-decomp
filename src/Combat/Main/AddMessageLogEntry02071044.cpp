#include <globaldefs.h>
#include "std_library_functions.h"
#include "Resource/Script.h"

struct Variant02030b0c {
    int tag;
    union { int i; float f; } u;
};

struct Struct02030b7c {
    int field0;
    void* field4;
};

int StringLength_020d2ff0(const char* s);

struct MsgArgs02071044 {
    struct Variant02030b0c v0;
    struct Variant02030b0c v1;
    struct Variant02030b0c v2;
    struct Variant02030b0c v3;
    struct Variant02030b0c v4;
    struct Variant02030b0c v5;
    struct Variant02030b0c v6;
    struct Struct02030b7c v7;
};

struct MsgEntry02071044 {
    int id;
    char text[0x1e];
    char flag1;
    char flag2;
};

struct MsgQueueState02071044 {
    unsigned char forceFlag;
    char pad1[7];
    struct MsgEntry02071044* entries;
    char pad2[4];
    int limit;
    char pad3[8];
    int targetValue;
    char pad4[4];
    int count;
};
extern struct MsgQueueState02071044 data_02108d70;

// USA: func_02071044  (semantic: AddMessageLogEntry02071044)
extern "C" ARM int func_02071044(struct MsgArgs02071044* args) {
    int v0;
    int key;
    int i;
    void* text;
    int len;

    if (data_02108d70.limit <= data_02108d70.count) {
        return 0;
    }

    v0 = ((Script::Parameter*)&args->v0)->ToInt();
    ((Script::Parameter*)&args->v1)->ToInt();

    if (v0 == data_02108d70.targetValue || data_02108d70.forceFlag != 0) {
        ((Script::Parameter*)&args->v2)->ToInt();
        ((Script::Parameter*)&args->v3)->ToInt();
        ((Script::Parameter*)&args->v4)->ToInt();
        key = ((Script::Parameter*)&args->v5)->ToInt();

        for (i = 0; i < data_02108d70.count; i++) {
            if (data_02108d70.entries[i].id == key) {
                if (key < 0x5208 || key >= 0x9c40) {
                    return 0;
                }
            }
        }

        data_02108d70.entries[data_02108d70.count].id = key;

        ((Script::Parameter*)&args->v6)->ToInt();
        text = (void*)((Script::Parameter*)&args->v7)->ToString();
        if (!text) {
            return 0;
        }

        memset(data_02108d70.entries[data_02108d70.count].text, 0, 0x20);

        len = StringLength_020d2ff0((const char*)text);
        if (len < 0x1f) {
            memcpy(data_02108d70.entries[data_02108d70.count].text, text, len);
        } else {
            memcpy(data_02108d70.entries[data_02108d70.count].text, text, 0x1e);
            data_02108d70.entries[data_02108d70.count].flag1 = 0;
        }

        data_02108d70.entries[data_02108d70.count].flag2 = 0;
        data_02108d70.count++;
    }

    return 1;
}
