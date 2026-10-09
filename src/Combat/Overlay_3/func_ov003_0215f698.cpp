#include <globaldefs.h>

struct Element0202bad4 {
    char unk_0[4];
    unsigned char id[6];
    char unk_a[0x43 - 0xa];
    unsigned char removed;
    char unk_44[0x50 - 0x44];
    unsigned char name[0x63 - 0x50];
    signed char level;
    char unk_64;
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
    unsigned char hidden : 1;
    unsigned char present : 1;
    unsigned char visible : 1;
    unsigned char flag6 : 1;
    unsigned char flag7 : 1;
    char unk_66[0xc0 - 0x66];
};
struct ElementArray0202bad4;

struct Record0215f698 {
    unsigned char active : 1;
    unsigned char level : 6;
    unsigned char valid : 1;
    char name[0x30];
    unsigned char id[6];
};

extern "C" void* func_0202ae18(void);
int GetField0xc(void* obj);
struct Element0202bad4* GetElementAt0x10Stride0xc0(struct ElementArray0202bad4* base, int index);
extern "C" int func_02001aec(void* a, void* b, int n);
extern "C" void __clear(void* buf, int size);
extern "C" void func_02042764(void* src, char* dst, int flag);
extern "C" int sprintf(char* dst, const char* fmt, ...);
extern "C" void* memcpy(void* dst, const void* src, int size);

// USA: func_ov003_0215f698
extern "C" ARM void func_ov003_0215f698(struct Record0215f698* records, short* count) {
    void* ctx = func_0202ae18();
    int n = GetField0xc(ctx);

    struct Record0215f698* rec = records;
    for (short i = 0; i < 10; i++) {
        rec->active = 0;
        rec++;
    }

    for (int k = 0; k < n; k++) {
        struct Element0202bad4* elem = GetElementAt0x10Stride0xc0((struct ElementArray0202bad4*)ctx, k);
        int found = 0;
        for (short j = 0; j < *count; j++) {
            rec = &records[j];
            if (elem->removed == 0 && func_02001aec(rec->id, elem->id, 6) == 0 && !elem->hidden && elem->present &&
                elem->visible) {
                char buf[0x30];
                rec->valid = 1;
                rec->active = 1;
                __clear(buf, 0x30);
                func_02042764(elem->name, buf, 1);
                sprintf(rec->name, buf);
                memcpy(rec->id, elem->id, 6);
                rec->level = elem->level;
                found = 1;
                break;
            }
        }
        if (!found && *count < 10 && elem->removed == 0 && !elem->hidden && elem->present && elem->visible &&
            elem->level > 0) {
            char buf[0x30];
            struct Record0215f698* added = &records[*count];
            added->valid = 1;
            added->active = 1;
            __clear(buf, 0x30);
            func_02042764(elem->name, buf, 1);
            sprintf(added->name, buf);
            memcpy(added->id, elem->id, 6);
            added->level = elem->level;
            (*count)++;
        }
    }
}
