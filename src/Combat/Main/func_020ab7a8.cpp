#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

struct StateBits5ccc_1155c;
void ClearFlag0x5cccBit0(struct StateBits5ccc_1155c* state);
int IsFunc020d0840NonZero();
void NotifyU16AndSetFlag02075cb8();

extern "C" int func_02075910(int a, void* p, unsigned int size, int c);
extern "C" int func_02075acc(int a, void* p, unsigned int size, int c);
extern "C" int func_01ff85b8(void* buf, int size);
extern "C" int strcmp(const char* a, const char* b);

struct Buf020a94f8 {
    int hdr;
    char data[0x10];
};
int VerifyBuffer020a94f8(struct Buf020a94f8* buf, int flag);

struct SaveHead020ab7a8 {
    int hdr;
    unsigned char pad[4];
    char str[12];
};

struct SaveMid020ab7a8 {
    int hdr;
    char data[0x5c];
};

struct SaveTail020ab7a8 {
    int hdr;
    char data[0x6f5c];
};

struct SaveBuf020ab7a8 {
    struct SaveHead020ab7a8 head;
    struct SaveMid020ab7a8 mid;
    struct SaveTail020ab7a8 tail;
};

struct Task020ab7a8 {
    unsigned char pad0;
    unsigned char state;
    unsigned char pad2[2];
    struct SaveBuf020ab7a8* buf;
};

extern "C" char data_0211e33c[];
extern "C" char data_020f1be8;

// USA: func_020ab7a8
extern "C" ARM int func_020ab7a8(void* obj, int flag) {
    struct Task020ab7a8* task = (struct Task020ab7a8*)obj;
    char local0;
    char local1;
    struct Buf020a94f8 buf;

    if (task->state == 0) {
        ClearFlag0x5cccBit0((struct StateBits5ccc_1155c*)GameState::GetInstance());
        if (func_02075910(0, &local0, 1, 0) == 0) {
            return 1;
        }
        BackgroundLoader::FreeAllocationsGlobal();
        task->buf = (struct SaveBuf020ab7a8*)((unsigned char*)&data_0211e33c[0] + 0x2901c);
        if (func_02075910(flag ? 0x8010 : 0x10, task->buf, 0x6fe4, 1) == 0) {
            return 1;
        }
        task->state = 1;
    } else if (task->state == 1) {
        if (IsFunc020d0840NonZero() == 0) {
            return 0;
        }
        NotifyU16AndSetFlag02075cb8();
        if (func_02075910(0, &local1, 1, 0) == 0) {
            return 2;
        }
        if (func_01ff85b8(&task->buf->head.pad[0], 0x10) != task->buf->head.hdr) {
            return 3;
        }
        if (task->buf->head.pad[1] == 0) {
            return 3;
        }
        if (strcmp(task->buf->head.str, &data_020f1be8) == 0) {
            return 3;
        }
        struct SaveBuf020ab7a8* mid = task->buf;
        if (func_01ff85b8(&mid->mid.data[0], 0x5c) != mid->mid.hdr) {
            return 3;
        }
        struct SaveBuf020ab7a8* tail = task->buf;
        if (func_01ff85b8(&tail->tail.data[0], 0x6f5c) != tail->tail.hdr) {
            return 3;
        }
        func_02075acc(flag ? 0x10 : 0x8010, task->buf, 0x6fe4, 1);
        task->state = 2;
        return 4;
    } else if (task->state == 2) {
        if (IsFunc020d0840NonZero() == 0) {
            return 4;
        }
        NotifyU16AndSetFlag02075cb8();
        if (flag) {
            if (VerifyBuffer020a94f8(&buf, 1) != 0) {
                buf.data[0] = 0;
                buf.hdr = func_01ff85b8((char*)&buf + 4, 0x10);
                func_02075acc(0x10, &buf, 0x14, 0);
            }
        }
        task->state = 3;
        return 5;
    } else {
        return 5;
    }
    return 0;
}
