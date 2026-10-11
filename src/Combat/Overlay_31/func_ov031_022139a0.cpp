void Configure_02213a68(int, void*, int, unsigned char*);
void Configure_02213ab4(int, void*, int, unsigned char*);
// USA: func_ov031_022139a0
extern "C" int func_ov031_022139a0(int id, void* record, int flags, unsigned char* state) {
 unsigned char* input=(unsigned char*)record;
 int i;
 unsigned char* p;
 unsigned char first;
 int result;
 int count;
 count=state[0xd12];
 result=-1;
 i=0;
 if(count>0) {
 first=input[4];
 p=state+0x474;
 do {
  if(first==p[0] && input[5]==p[1] && input[6]==p[2] && input[7]==p[3] && input[8]==p[4] && input[9]==p[5]) { result=i; break; }
  i++; p+=0xc0;
 } while(i<count);
 }
 if(result==-1) {
  Configure_02213a68((unsigned char)id,record,flags,state);
  if(state[0xd12]<10) state[0xd12]++;
  result=10;
 } else Configure_02213ab4(result,record,flags,state);
 return result;
}
