#include <globaldefs.h>
#include "std_library_functions.h"
struct Obj02157d14;
void ResetEntry02157d14(Obj02157d14*);
void ResetStruct02157cdc(void*);
void InitStruct02160030(void*);
// USA: func_ov000_0215d090
// JPN: func_ov000_0215d090
extern "C" ARM void func_ov000_0215d090(unsigned char* self) {
    self[0x8e00]=0; self[0x8e01]=0; self[0x8e02]=0; self[0x8e03]=0;
    self[0x8e82]=0;
    *(unsigned short*)(self+0x8e52)=0; *(short*)(self+0x8e50)=-1;
    self[0x8e83]=0; *(int*)(self+0x8e58)=0;
    self[0x8e0c]=0; self[0x8e0d]=0; self[0x8e0e]=0; self[0x8e0b]=0;
    self[0x8e08]=0; self[0x8e09]=0; self[0x8e0a]=0; self[0x8e0f]=0;
    self[0x8e11]=0; self[0x8e12]=0; self[0x8e10]=0; self[0x8e13]=0;
    self[0x8e96]=0; *(int*)(self+0x8e24)=0; *(unsigned short*)(self+0x8e6e)=0;
    for(int i=0;i<0x48;i++) ResetEntry02157d14((Obj02157d14*)(self+0x20+i*0x34));
    for(int i=0;i<0x88;i++) ResetStruct02157cdc(self+0xec0+i*0x24);
    for(int i=0;i<0x168;i++) { memset(self+0x21e0+i*0x24,0,0x20); *(int*)(self+0x2200+i*0x24)=0; }
    for(int i=0;i<0xfc;i++) { *(short*)(self+0x5480+i*8)=0; *(int*)(self+0x5484+i*8)=0; }
    for(int i=0;i<0x48;i++) InitStruct02160030(self+0x821c+i*0x28);
    for(int i=0;i<0x14;i++) ResetEntry02157d14((Obj02157d14*)(self+0x6380+i*0x34));
    for(int i=0;i<0x14;i++) ResetStruct02157cdc(self+0x6790+i*0x24);
    for(int i=0;i<0x14;i++) { memset(self+0x6a60+i*0x24,0,0x20); *(int*)(self+0x6a80+i*0x24)=0; }
    for(int i=0;i<0x14;i++) InitStruct02160030(self+0x6060+i*0x28);
    for(int i=0;i<0x10;i++) ResetEntry02157d14((Obj02157d14*)(self+0x6fb0+i*0x34));
    for(int i=0;i<0x10;i++) ResetStruct02157cdc(self+0x72f0+i*0x24);
    for(int i=0;i<0x10;i++) { memset(self+0x7530+i*0x24,0,0x20); *(int*)(self+0x7550+i*0x24)=0; }
    for(int i=0;i<0x10;i++) InitStruct02160030(self+0x6d30+i*0x28);
    for(int i=0;i<0x10;i++) {
        InitStruct02160030(self+0x7770+i*0x28);
        ResetEntry02157d14((Obj02157d14*)(self+0x79f0+i*0x34));
        ResetStruct02157cdc(self+0x7d30+i*0x24);
        memset(self+0x7f70+i*0x24,0,0x20);
        *(int*)(self+0x7f90+i*0x24)=0;
    }
    *(int*)(self+0x8e70)=0; self[0x8e80]=0;
    *(int*)(self+0x8e74)=0; self[0x8e81]=0;
    *(int*)(self+0x8e78)=0; *(int*)(self+0x8e7c)=0;
}
