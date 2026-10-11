struct ResourceGroup { unsigned int key; unsigned short entries[4]; };
struct ResourceEntry { unsigned int value:24; unsigned int flags:8; };
extern "C" ResourceGroup* _Z18GetOffsetEntry0x10i(int);
extern "C" void* _Z21PostEvent0x1FForIndexjii(unsigned,int,int);
extern "C" void* _Z25GetListEntryWord8020bd8acj(unsigned);
extern "C" ResourceEntry* _Z18GetOffsetEntry0x14i(int);
extern "C" int _Z26DispatchEventEntryForIndexijiiPi(int,unsigned,int,int,void**);
extern "C" int _Z22ProcessEntries020be604PvS_iii(void*,void*,int,int,int);
extern "C" void func_020d2b34(void*,int,void*);
#pragma optimize_for_size off
// JPN: main:020bf99c
extern "C" int func_020bded0(int index,unsigned flags,int b,int c,void** out) {
 ResourceGroup* group=_Z18GetOffsetEntry0x10i(index);
 if(!group) return 4;
 void* list;
 if(flags&2) {
  list=_Z21PostEvent0x1FForIndexjii(group->key,b,c);
  if(!list) return 8;
 } else list=_Z25GetListEntryWord8020bd8acj(group->key);
 int i;
 unsigned flag4;
 flag4=flags&4;
 i=0;
 do {
  if(group->entries[i]!=0xffff) {
  ResourceEntry* entry=_Z18GetOffsetEntry0x14i(group->entries[i]);
  if(!entry) return 5;
  void* object;
  int result=_Z26DispatchEventEntryForIndexijiiPi(group->entries[i],flags,b,c,&object);
  if(result) return result;
  if((entry->flags&1)&&flag4) {
   if(!_Z22ProcessEntries020be604PvS_iii(object,list,i,entry->value,b)) return 9;
  }
  if(list&&object) func_020d2b34(list,i,object);
  }
  ++i;
 } while(i<4);
 if(out) *out=list;
 return 0;
}

#pragma optimize_for_size reset
