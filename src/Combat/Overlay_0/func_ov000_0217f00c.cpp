#include <globaldefs.h>
struct Slot {char p[0x10];signed char states[8],index;char q[0x17];signed char* ids;signed char count;char r[3];void* menu;char s[0x10];int id;
#if defined(jpn)
char t[0x431];
#else
char t[0x3f1];
#endif
unsigned char flag;char u[6];};
struct Root {char p[0x6c];signed char order[4];char q[4];signed char ids[4],count;char r[0x9f];int flag;char s[0x60];int activeId;char t[0x7d8];Slot slots[4];};
int TestFlag0SetAndFlag1Clear(unsigned short*,int);extern unsigned short data_02114e30;extern unsigned char data_02114e54[];
struct Struct_0205d81c;unsigned char* FindElementByC40205d81c(Struct_0205d81c*,int);struct S02171698;int CountNonZero02171698(S02171698*);struct S021719c0;int CountNonZero021719c0(S021719c0*);int GetField0_0205bafc(void*);void SetField0xd8State(unsigned char*,int);void ProcessCombatantEntry0217f78c(void*);
extern "C" {void func_ov000_0217fa60(void*);void func_ov000_02174c14(void*);void func_ov000_0217f304(void*,int,int,void*);int func_ov000_021700dc(void*);void func_ov000_0217edd4(void*,signed char*,signed char*);void func_ov000_0217ee7c(signed char*,signed char*,signed char,int);void func_ov000_02176634(void*,void*,int,int,int);int func_ov000_0217c158(void*);void func_ov000_02177038(void*,void*,int,int,int);}
// USA: func_ov000_0217f00c
// JPN: func_ov000_0217f00c
extern "C" ARM void func_ov000_0217f00c(Root* self,int mode,int count){
 if(self->activeId<0){if(TestFlag0SetAndFlag1Clear(&data_02114e30,0x802)||data_02114e54[0x55]){func_ov000_0217fa60(self);func_ov000_02174c14(self);}return;}
 for(int i=0;i<4;i++){
  Slot* slot=&self->slots[self->order[i]];if(self->activeId!=slot->id)continue;
  unsigned char* entry;func_ov000_0217f304(self,mode,count,slot);int result=func_ov000_021700dc(slot);
  switch(result){
  case -3:func_ov000_0217fa60(self);func_ov000_02174c14(self);break;
  case -2:ProcessCombatantEntry0217f78c(self);break;
  case 15:case 16:case 17:case 18:{
   int active=0;func_ov000_0217edd4(self,self->ids,&self->count);signed char num=self->count;slot->ids=self->ids;slot->count=num;slot->flag=mode;func_ov000_02176634(self,slot,result,mode,count);
   entry=FindElementByC40205d81c((Struct_0205d81c*)slot->menu,(unsigned char)result);
   if(result==15){if(CountNonZero02171698((S02171698*)slot)>4)active=1;}
   else if(result==16){if(CountNonZero021719c0((S021719c0*)slot)>4)active=1;}
   else if(result==17){if(GetField0_0205bafc((char*)slot->menu+0x54)>4)active=1;}
   if(entry)SetField0xd8State(entry,active);break;
  }
  case 19:{
   func_ov000_0217edd4(self,self->ids,&self->count);func_ov000_0217ee7c(self->ids,&self->count,-1,1);signed char num=self->count;slot->ids=self->ids;slot->count=num;slot->flag=mode;func_ov000_02176634(self,slot,result,mode,count);break;}
  case 20:{
   func_ov000_0217edd4(self,self->ids,&self->count);func_ov000_0217ee7c(self->ids,&self->count,(signed char)slot->id,2);signed char num=self->count;slot->ids=self->ids;slot->count=num;slot->flag=mode;func_ov000_02176634(self,slot,result,mode,count);break;}
  default:func_ov000_02176634(self,slot,result,mode,count);break;
  }
  if(func_ov000_0217c158(slot))self->flag=1;
  func_ov000_02177038(self,slot,slot->states[slot->index],mode,count);break;
 }
}
