#include <globaldefs.h>

#if defined(jpn)
#define func_ov004_02159bcc func_ov004_0215ac28
#endif
#include "Memory/SafeAllocator.h"

struct Struct021707d8_02159bcc { char pad[8]; char* ptr; };
extern Struct021707d8_02159bcc data_ov004_021707d8;

struct Container020dedd0;
struct Element020de650;
extern "C" struct Container020dedd0* func_ov004_02156fd4(void* obj, int key);
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
int CallFunc020e52a0(void* p, int key);
int GetGlobalField0x1c020421a0(void);
void* ZeroInitReturn020de824(void* obj);
void InitStruct0207cbe8(char* obj);
void InitStruct0207cc0c(char* obj);
extern "C" void func_0207d134(void* buf, int a, int b);
extern "C" void func_ov011_021848a0(void* obj, int val);

// USA: func_ov004_02159bcc  (semantic: SetupCombatMessageAndDispatch_02159bcc)
extern "C" ARM int func_ov004_02159bcc(void* obj) {
    struct Container020dedd0* node = func_ov004_02156fd4(obj, 5);
    if (node == NULL) return 0;
    struct Element020de650* elem = FindElementByKey020dedd0(node, *(short*)(data_ov004_021707d8.ptr + 0xe));
    if (elem == NULL) return 0;
    int val = CallFunc020e52a0(data_ov004_021707d8.ptr + 0x8c, *(short*)((char*)elem + 0x18));
    *(int*)((char*)(int)GetGlobalField0x1c020421a0() + 0x18) = val;
    data_ov004_021707d8.ptr[0x12] = (char)0xff;
    if (*(unsigned char*)(data_ov004_021707d8.ptr + 0x47) == 0) {
        void* node2 = func_ov004_02156fd4(obj, 5);
        if (node2 != NULL) {
            char buf[0x38];
            ((SafeAllocator*)buf)->ResetAllocatorPointer();
            ZeroInitReturn020de824(buf + 0x14);
            InitStruct0207cbe8(buf);
            InitStruct0207cbe8(buf);
            *(void**)(buf + 0x2c) = node2;
            func_0207d134(buf, *(short*)(data_ov004_021707d8.ptr + 0xe), *(signed char*)(data_ov004_021707d8.ptr + 0x11));
            InitStruct0207cc0c(buf);
        }
        func_ov011_021848a0(obj, 0x38c);
        data_ov004_021707d8.ptr[0x9d] = 0;
        return 0;
    }
    func_ov011_021848a0(obj, 0x2379);
    return 0;
}
