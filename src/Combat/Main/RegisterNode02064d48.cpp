#include <globaldefs.h>
#include "Resource/Script.h"

#if defined(jpn)
enum { kResourceOffset = 0x860, kRegNodeSize = 0x20 };
#else
enum { kResourceOffset = 0x840, kRegNodeSize = 0x14 };
#endif


#include "Combat/NodeLookup.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"


int IsIdInRange020981e4(int a, int id);
int IsInRange1To63(int a, int x);



extern "C" void* func_02012fe4(void);

extern int data_02108ce0;

struct RegNode02064d48 {
    short id;
    unsigned char field2;
    unsigned char field3;
#if defined(jpn)
    char firstName[12];
#endif
    char name[12];
    struct RegNode02064d48* next;
};

// USA: func_02064d48
ARM int RegisterNode02064d48(char* obj) {
    const Script::Parameter* parameters = reinterpret_cast<const Script::Parameter*>(obj);
    int b = parameters[0].ToInt();
    char* g = (char*)func_02012fe4();

    if (IsIdInRange020981e4((int)(g + kResourceOffset), *(unsigned short*)g)) {
        if (IsInRange1To63((int)(g + kResourceOffset), b)) {
            return 1;
        }
    }

    if (FindNodeByByteId(*(void**)((char*)&data_02108ce0 + 4), b) == NULL) {
        return 1;
    }

    RegNode02064d48* node = (RegNode02064d48*)(*(SafeAllocator**)((char*)&data_02108ce0 + 0))->Allocate(kRegNodeSize);
    if (node == NULL) {
        return 0;
    }

    node->id = (short)b;
    node->field2 = (unsigned char)parameters[1].ToInt();

#if defined(jpn)
    const char* firstName = parameters[2].ToString();
    if (firstName != NULL) {
        strcpy(node->firstName, firstName);
    }
#else
    parameters[2].ToString();
#endif
    const char* name = parameters[3].ToString();
    if (name != NULL) {
        strcpy(node->name, name);
    }

    node->field3 = (unsigned char)parameters[4].ToInt();

    RegNode02064d48** headSlot = *(RegNode02064d48***)((char*)&data_02108ce0 + 8);
    node->next = *headSlot;
    *headSlot = node;
    return 1;
}
