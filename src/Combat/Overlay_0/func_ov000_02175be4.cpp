#include <globaldefs.h>
#include "std_library_functions.h"

class GameState { public: static GameState* GetInstance(); };
void* GetCombatantWithFlag0x1000(GameState*,int);
int GetField0x3acValue(GameState*);
int GetClampedArrayField0xd1c(char*,int);
int GetClampedArrayField0xd3c(char*,int);
extern "C" void _Z26EnqueueEventTag67_021c6a9cththha(unsigned short,int,int,unsigned char,unsigned char,signed char);
struct Node02175be4 {
    char p0[0x1d]; signed char selection; char p1[8]; unsigned short key;
    char p2[6]; signed char state;
};
struct Root02175be4 {
    unsigned short keys[4]; signed char selections[4],states[4];
    char p0[0xb]; signed char phase; char p1[8]; unsigned short event;
};
struct Group02175be4 { unsigned short key; unsigned char indices[4],count,pad; };
struct FourShort02175be4 { short v[4]; };
extern "C" {
Node02175be4* func_ov000_02161318(void*,int);
void func_ov000_02170db0(Node02175be4*);
int rand();
extern const FourShort02175be4 data_ov000_021833a8;
}

static inline short GetKey02175be4(Node02175be4* node) { return (short)node->key; }

// USA: func_ov000_02175be4
// JPN: func_ov000_02175be4
extern "C" ARM void func_ov000_02175be4(Root02175be4* obj) {
    GameState* gs = GameState::GetInstance();
    for (signed char i=0;i<4;i++) {
        if (!GetCombatantWithFlag0x1000(gs,i)) func_ov000_02161318(obj,i);
    }
    if (obj->phase != GetField0x3acValue(gs)) return;
    unsigned char count = 0;
    short keys[4] = {0};
    FourShort02175be4 selections(data_ov000_021833a8);
    for (signed char i=0;i<4;i++) {
        if (!GetCombatantWithFlag0x1000(gs,i)) {
            Node02175be4* node = func_ov000_02161318(obj,i);
            if (node) {
                keys[count] = node->key;
                selections.v[count] = node->selection;
                count++;
            }
        }
    }
    Group02175be4 groups[4];
    int choices[4];
    memset(groups,0,sizeof(groups));
    int groupCount=0;
    short* keyIt=keys;
    for (int i=0;i<count;keyIt++,i++) {
        Group02175be4* group;
        int fresh,j;
        int key=*keyIt;
        if (key>=0) {
            group=groups;
            fresh=1;
            for (j=0;j<groupCount;group++,j++) {
                if (group->key==key) {fresh=0;break;}
            }
            group->key=key;
            if (fresh) groupCount++;
            group->indices[group->count]=i;
            group->count++;
        }
    }
    Group02175be4* current;
    int key=-1;
    Group02175be4* winner=0;
    int maximum=0;
    current=groups;
    for (int i=0;i<groupCount;current++,i++) {
        if (maximum<current->count) {
            maximum=current->count;
            winner=current;
            key=(short)current->key;
        } else if (maximum==current->count) key=-1;
    }
    if (key==-1) key=0;
    short selected=0;
    if (key && winner) {
        int n=0;
        for (int i=0;i<winner->count;i++) {
            unsigned int index=((unsigned char*)winner+i)[2];
            if (index<4) { choices[n]=selections.v[index]; n++; }
        }
        if (n>0) selected=choices[rand()%n];
    }
    if (selected==-1) selected=selections.v[0];
    if (!key) {
        for (unsigned char i=0;i<4;i++) {
            Node02175be4* node=func_ov000_02161318(obj,i);
            if (node) {
                node->key=obj->keys[i];
                node->selection=obj->selections[i];
                node->state=obj->states[i];
                func_ov000_02170db0(node);
            }
        }
    } else {
        for (unsigned char i=0;i<4;i++) {
            Node02175be4* node=func_ov000_02161318(obj,i);
            if (node) {
                node->key=(unsigned short)key;
                node->selection=(signed char)selected;
                node->state=-1;
                func_ov000_02170db0(node);
            }
        }
    }
    for (signed char i=0;i<4;i++) {
        Node02175be4* node=func_ov000_02161318(obj,i);
        if (node) {
            unsigned char a=GetClampedArrayField0xd1c((char*)obj,node->selection);
            unsigned char b=GetClampedArrayField0xd3c((char*)obj,node->selection);
            _Z26EnqueueEventTag67_021c6a9cththha(obj->event,i,(unsigned short)GetKey02175be4(node),a,b,node->state);
        }
    }
}
