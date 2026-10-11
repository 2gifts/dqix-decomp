// JPN: main:020d70e0
void* GetBattleContext();
extern "C" int func_020d424c(int, ...);
void InvalidateDataCacheRange(const void*,unsigned);
int GetAlignedField0x3eSize020d4900();
int GetAlignedField0x3cSize020d4894();
void SetBattleContextArrayEntry(int,int);
extern "C" void func_020ca3ec(unsigned,void*,unsigned);
extern "C" void func_020ca408(const void*,void*,unsigned);
int CommitBattleContextBuffer020d4168(void*,unsigned);
struct BufferRequest { unsigned short command,pad; unsigned data,halfSize,other,count; unsigned char reserved[28]; unsigned char tail[16]; };
#pragma optimize_for_size off
extern "C" int func_020d5684(int entry,unsigned data,int size,unsigned other,unsigned short count,const void* tail) {
 unsigned char* buffer=*(unsigned char**)((char*)GetBattleContext()+4);
 int result=func_020d424c(2,7,8);
 if(result) return result;
 InvalidateDataCacheRange(buffer+0x188,2);
 InvalidateDataCacheRange(buffer+0xc6,2);
 if(*(unsigned short*)(buffer+0x188)!=0 && *(unsigned short*)(buffer+0xc6)!=1) return 3;
 InvalidateDataCacheRange(buffer+0xc,4);
 if(*(unsigned*)(buffer+0xc)==1) return 3;
 if(size&63) return 6;
 if(count&31) return 6;
 InvalidateDataCacheRange(buffer+0x9c,2);
 if(!*(unsigned short*)(buffer+0x9c)) {
  if(size<GetAlignedField0x3eSize020d4900()) return 6;
  if(count<GetAlignedField0x3cSize020d4894()) return 6;
 }
 SetBattleContextArrayEntry(14,entry);
 BufferRequest request;
 func_020ca3ec(0,&request,64);
 request.command=14;
 request.data=data;request.halfSize=(unsigned)size>>1;request.other=other;request.count=count;
 func_020ca3ec(0,request.reserved,28);
 func_020ca408(tail,request.tail,16);
 result=CommitBattleContextBuffer020d4168(&request,64);
 if(!result) return 2;
 return result;
}

#pragma optimize_for_size reset
