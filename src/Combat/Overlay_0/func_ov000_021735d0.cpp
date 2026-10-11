#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

#if defined(jpn)
enum {commandOffset=0x1f98, gameFlagsOffset=0x5a6c};
#else
enum {commandOffset=0x1d60, gameFlagsOffset=0x5ccc};
#endif
struct Root {
    char p0[0x118]; int result;
    char p1[0x188-0x11c]; char updateState[0x94];
    bool flagA,flagB;
    char p2[0x8a4-0x21e]; char dispatchA[0x20],dispatchB[0x20],dispatchC[0x20];
    char p3[8]; int task;
    char p4[0x940-0x910]; int x,y; int unknown948,delta;
    char p5[commandOffset-0x950]; signed char commands[8]; signed char commandIndex;
    char p6[7]; bool active; char p7; unsigned short flags;
    char p8[13]; unsigned char phase;
};
struct GameFlags {char pad[gameFlagsOffset]; signed int bit0:1,bit1:1,rest:30;};
struct TableEntry0217f8c0 {char p[0x10];signed char commands[8];signed char index;char q[0x24-0x19];unsigned char flags;};
struct Struct0217f8c0;struct Obj0204b5e8;struct Struct021754fc;struct S02180b50;
int DispatchViaTable0204b5e8(Obj0204b5e8*,int,int);
TableEntry0217f8c0* FindMatchingTableEntry0217f8c0(Struct0217f8c0*);
void UpdateLastEntryField02175440(void*);
void UpdateFieldromTable_02174fc0_02174fc0(void*);
void NotifyEachViaLookup021754fc(Struct021754fc*,int);
void TickCounter02180b50(S02180b50*);
int GetField0x3acValue(GameState*);
int CheckField0NonZero(int*);
extern "C" {
int* func_0202ae18(); void func_020dc7e8(int,int); int func_0205d0e0(void*,int);
void func_ov000_02175fc8(void*);void func_ov000_02174d08(void*);void func_ov000_02175024(void*,int);
void* func_ov000_02161318(void*,int);
void func_ov000_0217f304(void*,int,int,void*);void func_ov000_0217c908(void*,int,int);
void func_ov000_02176e3c(void*,void*,int,int,int,int);
int func_ov000_0217fd60(void*,int);void func_ov000_021751ac(void*);
void func_ov000_0217f00c(void*,int,int);void func_ov000_02175258(void*);
void func_ov000_0218099c(void*,int);void func_ov000_02180a64(void*);
}
extern int data_ov000_02183ff0;extern int data_ov000_02184288[];

// USA: func_ov000_021735d0
// JPN: func_ov000_021735d0
extern "C" ARM void func_ov000_021735d0(Root* self,int delta)
{
    self->delta=delta;
    DispatchViaTable0204b5e8((Obj0204b5e8*)self->dispatchA,-self->x,-self->y);
    DispatchViaTable0204b5e8((Obj0204b5e8*)self->dispatchB,0,0);
    DispatchViaTable0204b5e8((Obj0204b5e8*)self->dispatchC,0,0);
    GameState* gs=GameState::GetInstance();func_0202ae18();
    if(((GameFlags*)gs)->bit1)func_020dc7e8(0,-1);
    if(!delta)delta=1;
    int update=1;
    TableEntry0217f8c0* entry=FindMatchingTableEntry0217f8c0((Struct0217f8c0*)self);
    if(entry&&entry->commands[entry->index]==100)update=0;
    if(update){
        UpdateLastEntryField02175440(self);
        entry=FindMatchingTableEntry0217f8c0((Struct0217f8c0*)self);
        int clear;bool a=self->flagA,b=self->flagB;clear=0;
        if(entry&&!(self->flags&0x200)&&self->commands[self->commandIndex]!=6&&self->commands[self->commandIndex]!=7&&!(entry->flags&1))clear=1;
        if(clear){self->flagA=false;self->flagB=false;}
        self->result=func_0205d0e0(self->updateState,delta);
        if(clear){if(a)self->flagA=true;if(b)self->flagB=true;}
    }
    func_ov000_02175fc8(self);func_ov000_02174d08(self);UpdateFieldromTable_02174fc0_02174fc0(self);
    func_ov000_02175024(self,delta);NotifyEachViaLookup021754fc((Struct021754fc*)self,delta);
    if(self->flags&0x200){
        void* unit=func_ov000_02161318(self,(signed char)GetField0x3acValue(GameState::GetInstance()));
        func_ov000_0217f304(self,data_ov000_02183ff0,data_ov000_02184288[1],unit);
        func_ov000_0217c908(self,data_ov000_02183ff0,data_ov000_02184288[1]);
        TickCounter02180b50((S02180b50*)self);
        int special=self->commands[self->commandIndex]==100;
        if(special & CheckField0NonZero(func_0202ae18())){
            if(self->phase==1){
                for(int i=0;i<2;i++)func_ov000_02176e3c(self,unit,23,data_ov000_02183ff0,data_ov000_02184288[1],0);
                self->phase=2;
            }else if(self->phase==0)self->phase=1;
        }
    }
    if(self->flags&0x400)TickCounter02180b50((S02180b50*)self);
    if(!func_ov000_0217fd60(self,-1)){
        if(self->active&&self->task>=0){BackgroundLoader* loader=BackgroundLoader::GetInstance();loader->RemoveTask(self->task);self->task=-1;}
    }else{
        func_ov000_021751ac(self);
        if(!(self->flags&0x200)){
            if(self->commands[self->commandIndex]==13){if(!(self->flags&4))func_ov000_0217f00c(self,data_ov000_02183ff0,data_ov000_02184288[1]);}
            else func_ov000_0217c908(self,data_ov000_02183ff0,data_ov000_02184288[1]);
            func_ov000_02175258(self);func_ov000_0218099c(self,delta);func_ov000_02180a64(self);
        }
    }
}
