#include <globaldefs.h>

extern "C" void* func_ov011_021849c8(void* obj);

struct Node021f68b8 { void* first; };
void* GetNthNode_021f68b8(struct Node021f68b8* head, int n);

extern "C" unsigned int func_ov023_021f6f10(void* obj);

struct Obj021f6f08 { char pad[6]; unsigned short field6; };
unsigned int GetShort6_021f6f08(struct Obj021f6f08* obj);

struct NodeFlag45_021f88b8 { char pad[0x45]; unsigned char bit0 : 1; };

int GetField18_021f6f18(void* obj);

extern "C" void func_ov023_021f809c(void* obj, void* param2);

// USA: func_ov023_021f88b8  (semantic: SyncNodeFlagsByShort6_021f88b8)
extern "C" ARM void func_ov023_021f88b8(void* obj, void* param1, int id) {
    void* sub = func_ov011_021849c8(param1);
    void* node = GetNthNode_021f68b8((struct Node021f68b8*)sub, 0);
    while (node != NULL) {
        unsigned int state = func_ov023_021f6f10(node);
        if (state == 8 && *(unsigned short*)((char*)node + 0x34) == *(unsigned short*)((char*)obj + 0x6)) {
            unsigned int short6 = GetShort6_021f6f08((struct Obj021f6f08*)node);
            if ((unsigned int)id == short6) {
                ((struct NodeFlag45_021f88b8*)node)->bit0 = 1;
            } else {
                ((struct NodeFlag45_021f88b8*)node)->bit0 = 0;
            }
        }
        node = (void*)GetField18_021f6f18(node);
    }
    func_ov023_021f809c(obj, param1);
}
