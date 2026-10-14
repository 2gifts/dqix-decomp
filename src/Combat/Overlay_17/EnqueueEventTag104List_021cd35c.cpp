#include <globaldefs.h>

void* GetData02100044_0202ae24(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct ListElem021cd35c {
    unsigned short b;
    unsigned short c : 15;
    unsigned short unused_021cd35c : 1;
    unsigned char e;
    signed char f;
};

struct Msg021cd35c {
    unsigned short id;
    unsigned short b;
    unsigned short c;
    signed char d;
    unsigned char e;
    signed char f;
};

// USA: func_ov017_021cd35c  (semantic: EnqueueEventTag104List_021cd35c)
extern "C" ARM void func_ov017_021cd35c(unsigned short id, ListElem021cd35c* list, int count, signed char last) {
    void* p = GetData02100044_0202ae24();
    unsigned char buf[0x14];
    buf[0] = 0x68;
    struct Msg021cd35c* m = (struct Msg021cd35c*)(buf + 4);
    m->id = id;
    if (count != 0) {
        int i;
        int sentinel = -1;
        for (i = 0; i < count; i++, list++) {
            m->b = list->b;
            m->c = list->c;
            m->e = list->e;
            m->f = list->f;
            if (i == count - 1) m->d = last;
            else m->d = sentinel;
            func_0205e330(p, buf, 0);
        }
    } else {
        m->b = 0;
        m->c = 0;
        m->d = 0;
        m->f = -1;
        func_0205e330(p, buf, 0);
    }
}
