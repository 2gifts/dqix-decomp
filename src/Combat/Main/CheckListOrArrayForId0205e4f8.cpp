#include <globaldefs.h>

void PushInterruptDisableState_020d8654(void);
extern "C" void* func_0202ae18(void);
void* GetSubstructAt0x7c0_0202c19c(void* base);
extern "C" void func_020d8694(void);

struct ListNode0205e4f8 {
    unsigned char id;
    unsigned char pad[0x18 - 1];
    struct ListNode0205e4f8* next;
};

struct Elem0205e4f8 {
    unsigned char pad[0x10];
    unsigned char id;
    unsigned char pad2[0x14 - 0x11];
};

// USA: func_0205e4f8  (semantic: CheckListOrArrayForId0205e4f8)
extern "C" ARM int func_0205e4f8(void* obj, int id) {
    int result = 0;
    PushInterruptDisableState_020d8654();
    struct ListNode0205e4f8* node = *(struct ListNode0205e4f8**)((char*)obj + 0x150c);
    while (node != NULL) {
        if (node->id == id) {
            result = 1;
            break;
        }
        node = node->next;
    }
    if (!result) {
        struct Elem0205e4f8* arr = (struct Elem0205e4f8*)GetSubstructAt0x7c0_0202c19c(func_0202ae18());
        for (int i = 0; i < 5; i++) {
            if (arr[i].id == id) {
                result = 1;
                break;
            }
        }
    }
    func_020d8694();
    return result;
}
