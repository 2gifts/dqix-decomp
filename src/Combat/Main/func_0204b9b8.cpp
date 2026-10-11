// JPN: main:0204c7d8
struct PaletteWindow { char pad[0x14]; volatile unsigned short (*rows)[32]; };
extern "C" void func_0204b9b8(PaletteWindow* obj,int x,int y,int width,int height,unsigned palette) {
 volatile unsigned short (*rows)[32]=obj->rows;
 if(!rows)return;
 if(x+width<0 || y+height<0)return;
 if(x>=32 || y>=25)return;
 if(palette>15)return;
 if(x<0){width=(short)(x+width);x=0;}else if(x+width>=32)width=(short)(32-x);
 if(y<0){height=height+y;height=(short)height;y=0;}else if(y+height>=25)height=(short)(25-y);
 volatile unsigned short* row=rows[y]+x;
 palette=(unsigned short)(palette<<12);
 int j=0;
 unsigned short i;
 while(j<height) {
  i=0;
  while(i<width) {
   row[i]&=0xfff;
   row[i]|=palette;
   i=i+1;
  }
  row+=32;
  j=(unsigned short)(j+1);
 }
}
