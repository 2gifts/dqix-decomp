#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

#if defined(jpn)
enum {commandOffset=0x1f98, allocatorOffset=0x1bf8, unitStateOffset=0x144};
#else
enum {commandOffset=0x1d60, allocatorOffset=0x1af8, unitStateOffset=0x150};
#endif
struct Root {
    char pad0[0x68];int mask;
    char pad1[0x79-0x6c];unsigned char limit;
    char pad2[2];SafeAllocator firstAllocator;char pad3[0xb3-0x90];unsigned char flagB3;
    char pad4[0x17c-0xb4];int member;
    char pad5[8];char updateState[0x956-0x188];unsigned char flag956;
    char pad6[allocatorOffset-0x957];SafeAllocator allocator;
    char pad7[commandOffset-allocatorOffset-0x14];signed char commands[8];signed char index;
    char pad8;signed char mode;unsigned char count;
    char pad9[2];unsigned char special;char pad10[3];unsigned short flags;
    char pad11[4];bool force;
};
struct Party {char p[0xf78];signed char members[4];unsigned char count;};
struct UnitState {char p[0x56b];unsigned char low:4,high:4;};
struct UnitView {char p[unitStateOffset];UnitState* state;};
struct Struct_0205c570;struct Obj0205eaa0;struct Struct0217f8c0;struct TableEntry0217f8c0;
struct Struct_0205d81c;struct Entry_0205d6a0;struct Obj02092aa4;
int GetActiveScaledSum0205d794(Struct_0205c570*);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*,int,int);
void* GetPtrField0x2a04(GameState*);
GameObject* GetCombatantWithFlag0x100(GameState*,int);
TableEntry0217f8c0* FindMatchingTableEntry0217f8c0(Struct0217f8c0*);
int GetField0x3acValue(GameState*);
int CountSetBitsLow12_0x68(void*);
void SetElementStateIfLess0217a9d0(int,int,int,Struct_0205d81c*);
extern "C" void _Z15InitObj02092aa4P11Obj02092aa4h(Obj02092aa4*,int);
void CreateTypeAFromAllocator(SafeAllocator*,SafeAllocator*);
int CheckFlagsOrField_0217c5f4_0217c5f4(void*);
void ResetEntryList0205d6a0(Entry_0205d6a0*,int);
extern Obj0205eaa0 data_02108760;
extern "C" {
void func_02012fe4();int func_ov000_0217c594(void*,int);
void* func_ov000_02161318(void*,int);int func_ov000_0217f5dc(void*);
void func_ov000_02177038(void*,int,int,int,int);
void func_ov000_02176634(void*,void*,int,int,int);
int func_020dd3cc(int);int func_ov000_0217c514(int,int);
void func_ov000_02176e3c(void*,int,int,int,int,int);
void func_ov000_0217c638(void*,int,int);
}

// USA: func_ov000_0217ce24
// JPN: func_ov000_0217ce24
extern "C" ARM void func_ov000_0217ce24(Root* self,int a,int b)
{
    func_02012fe4();
    self->flags|=0x100;
    int mode=GetActiveScaledSum0205d794((Struct_0205c570*)self->updateState);
    if(mode<0)mode=0;
    self->mode=mode;
    if(func_ov000_0217c594(self,5)){
        self->flag956=0;
        DispatchWithShortB4_0205eaa0(&data_02108760,1,0);
        GameState* game=GameState::GetInstance();
        Party* party=(Party*)GetPtrField0x2a04(game);
        signed char count=0;bool active=false;
        unsigned char i=0;unsigned char total=party->count;
        for(;i<total;i++){
            int member=party->members[i];
            UnitView* unit=(UnitView*)GetCombatantWithFlag0x100(game,member);
            if(unit){
                bool stateActive=unit->state?unit->state->low!=0:false;
                if(stateActive)active=true;
                void* entry=func_ov000_02161318(self,member);
                if(entry&&func_ov000_0217f5dc(entry))count++;
            }
        }
        if(self->limit<count)count=self->limit;
        switch(self->mode){
        case 0:
            func_ov000_02177038(self,0,self->commands[self->index],a,b);
            if(party->count==1||active||self->force||count==1){
                self->count=0;self->index++;self->commands[self->index]=12;
                func_ov000_02176634(self,FindMatchingTableEntry0217f8c0((Struct0217f8c0*)self),12,a,b);
            }else{
                self->count=0;self->index++;self->commands[self->index]=3;
                func_ov000_02176634(self,FindMatchingTableEntry0217f8c0((Struct0217f8c0*)self),3,a,b);
            }
            break;
        case 1:
            func_ov000_02177038(self,0,self->commands[self->index],a,b);
            self->special=0;self->count=0;self->index++;self->commands[self->index]=5;
            if(party->count==1||active||count==1){
                int member=(signed char)GetField0x3acValue(game);
                self->mask=func_020dd3cc(member);
                self->mask=func_ov000_0217c514(member,self->mask);
                self->commands[self->index]=6;
                if(self->mask==0){
                    self->commands[self->index]=43;
                    func_ov000_02176634(self,func_ov000_02161318(self,member),43,a,b);
                    break;
                }
            }
            {TableEntry0217f8c0* entry=FindMatchingTableEntry0217f8c0((Struct0217f8c0*)self);
            func_ov000_02176634(self,entry,self->commands[self->index],a,b);}
            SetElementStateIfLess0217a9d0(6,CountSetBitsLow12_0x68(self),4,(Struct_0205d81c*)self->updateState);
            break;
        case 2:
            self->limit=count;
            func_ov000_02177038(self,0,self->commands[self->index],a,b);
            self->count=0;self->index++;self->commands[self->index]=8;
            func_ov000_02176634(self,FindMatchingTableEntry0217f8c0((Struct0217f8c0*)self),8,a,b);
            break;
        case 3:
            func_ov000_02176e3c(self,0,self->commands[self->index],a,b,1);
            self->index++;self->commands[self->index]=9;
            self->allocator.Reset();
            _Z15InitObj02092aa4P11Obj02092aa4h((Obj02092aa4*)&self->firstAllocator,(signed char)self->member);
            CreateTypeAFromAllocator(&self->firstAllocator,&self->allocator);
            self->flagB3|=8;
            break;
        }
    }else if(CheckFlagsOrField_0217c5f4_0217c5f4(self)){
        self->flag956=0;
        ResetEntryList0205d6a0((Entry_0205d6a0*)self->updateState,0);
        self->commands[self->index]=0;self->index--;
        func_ov000_0217c638(self,a,b);
    }
}
