#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum {selectionOffset=0xc2,savedOffset=0x47d,globalFlagsOffset=0x1faa};
#else
enum {selectionOffset=0x82,savedOffset=0x43d,globalFlagsOffset=0x1d72};
#endif
struct CommandState {
    char p0[8];signed char commands[8];signed char index;char p1[3];
    signed char mode;unsigned char count;short value16;
    signed char value18,value19,value1a,value1b;char p2[2];short kind;
    char p3[6];signed char value26;char p4[9];
};
struct Container020e0310;struct Struct_0205c570;struct Obj_0205da38;struct Entry_0205d6a0;
struct Obj0203c108;struct Obj0205eaa0;
struct Root {
    int p0;Container020e0310* container;CommandState command;
    Struct_0205c570* active;char p1[0x4c-0x3c];int member;
    char entry[selectionOffset-0x50];short selectionA,selectionB;signed char selectionC;
    char p2[savedOffset-selectionOffset-5];signed char saved;
    char p3[6];unsigned char flag;
};
struct GlobalRoot {char p[globalFlagsOffset];unsigned short flags;};
#if defined(jpn)
struct GlobalData {GlobalRoot* root;void* work;int other;};
#else
struct GlobalData {void* work;int other;GlobalRoot* root;};
#endif
struct Ability {char p[0x3b];unsigned char low:3,flag:1,high:4;};
struct Unit {char p[0x138];Ability* ability;};
extern GlobalData data_ov000_02184294;
extern unsigned short data_02114e30[];
extern Obj0205eaa0 data_02108760;
GameObject* GetCombatantWithFlag0x100(GameState*,int);
int GetFieldAt0x150(unsigned char*);
int GetActiveScaledSum0205d794(Struct_0205c570*);
bool TestFlag0SetAndFlag1Clear(unsigned short*,int);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*,int,int);
int GetFieldByKey020e0434(Container020e0310*,int);
void SwapGlobalEntry0203c108(Obj0203c108*,char*);
int CheckFlagsOrField_0217ab48_0217ab48(void*);
void ResetEntryList0205d6a0(Entry_0205d6a0*,int);
extern "C" {
void func_02012fe4();
bool _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38(Obj_0205da38*,int);
void* _Z16GetStoredWorkPtrv(GlobalRoot*);
int func_ov000_0217c2a0(void*);int func_ov000_0217aa78(void*,int,int);
void func_ov000_0217c32c(void*);void func_ov000_02171c04(void*);
}

// USA: func_ov000_0217ae90
// JPN: func_ov000_0217ae90
extern "C" ARM int func_ov000_0217ae90(Root* self)
{
    Unit* unit=(Unit*)GetCombatantWithFlag0x100(GameState::GetInstance(),self->member);
    int state=0;
    if(unit)state=GetFieldAt0x150((unsigned char*)unit);
    func_02012fe4();
    CommandState* command=&self->command;
    command->mode=GetActiveScaledSum0205d794(self->active);
    command->kind=0;
    data_ov000_02184294.root->flags|=0x100;
    bool flag=TestFlag0SetAndFlag1Clear(data_02114e30,0x601);
    bool active=flag | _Z31IsActiveElementFlag2Set0205da38P12Obj_0205da38((Obj_0205da38*)self->active,20);
    if(active){
        self->flag=0;
        data_ov000_02184294.work=_Z16GetStoredWorkPtrv(data_ov000_02184294.root);
        switch(command->mode){
        case 0:
            self->saved=self->command.commands[self->command.index];
            DispatchWithShortB4_0205eaa0(&data_02108760,1,0);
            command->index++;command->commands[command->index]=14;
            command->count=0;command->value19=-1;command->value26=-1;command->kind=1;
            if(func_ov000_0217c2a0(self)){
                command->commands[command->index]=100;
                SwapGlobalEntry0203c108((Obj0203c108*)self->entry,(char*)GetFieldByKey020e0434(self->container,0x7534));
            }
            return command->commands[command->index];
        case 1:
            self->saved=self->command.commands[self->command.index];
            DispatchWithShortB4_0205eaa0(&data_02108760,1,0);
            if(self->selectionA){
                command->index++;command->commands[command->index]=15;command->value18=0;
                if(state)command->value18=func_ov000_0217aa78(self,self->selectionA,0);
                return command->commands[command->index];
            }else{
                data_ov000_02184294.root->flags&=~0x100;
                command->index++;command->commands[command->index]=27;command->value18=-1;
                return command->commands[command->index];
            }
        case 2:
            self->saved=self->command.commands[self->command.index];command->kind=3;
            DispatchWithShortB4_0205eaa0(&data_02108760,1,0);
            SwapGlobalEntry0203c108((Obj0203c108*)self->entry,(char*)GetFieldByKey020e0434(self->container,0x7536));
            command->index++;command->commands[command->index]=100;
            return command->commands[command->index];
        case 3:
            self->saved=self->command.commands[self->command.index];
            DispatchWithShortB4_0205eaa0(&data_02108760,1,0);
            if(self->selectionB){
                command->index++;command->commands[command->index]=16;command->value16=0;
                if(state)command->value16=func_ov000_0217aa78(self,self->selectionB,1);
                func_ov000_0217c32c(self);
                return command->commands[command->index];
            }else{
                data_ov000_02184294.root->flags&=~0x100;
                command->index++;command->commands[command->index]=28;command->value16=-1;
                return command->commands[command->index];
            }
        case 4:
            self->saved=self->command.commands[self->command.index];
            DispatchWithShortB4_0205eaa0(&data_02108760,1,0);
            func_ov000_02171c04(self);
            if(self->selectionC){
                command->index++;command->commands[command->index]=17;command->value1a=0;
                return command->commands[command->index];
            }else{
                data_ov000_02184294.root->flags&=~0x100;
                command->index++;command->commands[command->index]=29;command->value1a=-1;
                return command->commands[command->index];
            }
        case 5:
            if(unit->ability->flag){
                self->saved=self->command.commands[self->command.index];
                DispatchWithShortB4_0205eaa0(&data_02108760,1,0);
                command->index++;command->commands[command->index]=21;command->value1b=0;
                return command->commands[command->index];
            }
            break;
        }
    }else if(CheckFlagsOrField_0217ab48_0217ab48(self)){
        command->kind=0;data_ov000_02184294.root->flags&=~0x100;
        ResetEntryList0205d6a0((Entry_0205d6a0*)self->active,1);
        return -2;
    }
    return -1;
}
