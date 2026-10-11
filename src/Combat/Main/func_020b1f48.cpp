// JPN: main:020b3a14
extern "C" {
void func_020b1ff8(unsigned short*,int,int,int,unsigned,unsigned);
#define FillRows func_020b1ff8
#pragma optimize_for_size off
void func_020b1f48(unsigned short* output,int width,int height,int x,int y,int stride,unsigned tile,unsigned palette) {
 if(stride<=32) { FillRows(output+(stride*y+x),width,height,stride,tile,palette); return; }
 int right=x+width;
 int bottom=y+height;
 unsigned short shifted=palette<<12;
 if(y<bottom) do {
  int row=y<32?y:y+32;
  int col=x;
  unsigned short* line=output+row*32;
  if(col<right) do {
   int offset=col<32?col:col+992;
   line[offset]=tile|shifted;
   ++tile;
  } while(++col<right);
 } while(++y<bottom);
}
#pragma optimize_for_size reset
}
