// JPN: main:020c02f4
extern "C" {
void* _Z33AcquireOrEvictSlotAndLink020bc454P15SlotObj020bc454ii(void*,int,int);
void* _Z27PopSlotFirstAndLink020bc5bciP12Node020bc5bc(int,void*);
void _Z25CallFunc020bc79c_020bc4ecPv(void*);
void _Z31HandleCommandType2Event020bc4f8P11Obj020bc4f8iii(void*,void*,int,void*);
void _Z16SetInnerByte0x40P13Outer020bc16ch(void*,unsigned char);
void _Z29CallFunc020d1e88OnNodeField3cP11Obj020bc1aci(void*,int);
void _Z23SetSubFields0x34And0x38P6Holderi(void*,int);
int func_020bded0(int,int,void*,int,void**);
int func_020bddec(int,int,void*,int,void**);
struct Record020be828 { unsigned char padding[0x18]; int offset; };
#pragma optimize_for_size off
int func_020be828(void* self,int pool,int first,int slotIndex,const unsigned char* settings,int second) {
 void* slot=_Z33AcquireOrEvictSlotAndLink020bc454P15SlotObj020bc454ii(self,pool,slotIndex);
 if(!slot)return 0;
 void* data=_Z27PopSlotFirstAndLink020bc5bciP12Node020bc5bc(pool,slot);
 Record020be828* secondRecord;
 void* firstRecord;
 if(func_020bded0(first,6,data,0,&firstRecord)) {
  _Z25CallFunc020bc79c_020bc4ecPv(slot);return 0;
 }
 if(func_020bddec(second,1,data,0,(void**)&secondRecord)) {
  _Z25CallFunc020bc79c_020bc4ecPv(slot);return 0;
 }
 _Z31HandleCommandType2Event020bc4f8P11Obj020bc4f8iii(slot,(char*)secondRecord+secondRecord->offset,0,firstRecord);
 _Z16SetInnerByte0x40P13Outer020bc16ch(self,settings[6]);
 _Z29CallFunc020d1e88OnNodeField3cP11Obj020bc1aci(self,settings[7]);
 _Z23SetSubFields0x34And0x38P6Holderi(self,second);
 return 1;
}
#pragma optimize_for_size reset
}
