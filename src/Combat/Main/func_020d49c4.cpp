// JPN: main:020d6420
void* GetBattleContext();
int GetBattleStateCode();
void InvalidateDataCacheRange(const void*, unsigned);
static inline unsigned GetStride(unsigned char* p) { unsigned value=*(unsigned short*)(p+6); return value; }
#pragma optimize_for_size off
extern "C" void* func_020d49c4(unsigned char* records, unsigned channel) {
 unsigned char* context=(unsigned char*)GetBattleContext();
 if(GetBattleStateCode()) return 0;
 if(channel<1 || channel>15) return 0;
 InvalidateDataCacheRange(*(unsigned char**)(context+4)+0x182,2);
 if(!(*(unsigned short*)(*(unsigned char**)(context+4)+0x182)&(1<<channel))) return 0;
 if(!*(unsigned short*)(records+4)) return 0;
 unsigned char* pointers[15];
 pointers[0]=records+10;
 int i=0;
 do {
  if(channel==*(unsigned short*)(pointers[i]+4)) return pointers[i];
  unsigned stride;
  unsigned char** slot;
  ++i;
  slot=&pointers[i];
  stride=GetStride(records);
  pointers[i]=(unsigned char*)(stride+*(unsigned*)((char*)slot-4));
 } while(i<*(unsigned short*)(records+4));
 return 0;
}

#pragma optimize_for_size reset
