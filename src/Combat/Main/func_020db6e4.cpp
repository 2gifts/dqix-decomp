#include <globaldefs.h>
int GetObjectValue020db2dc(int,int);
struct TileObject {
 unsigned int position;
 union { unsigned short value; struct { unsigned short tile:10; unsigned short mode:2; unsigned short palette:4; } fields; } attribute;
 unsigned short pad;
};
// USA: 020db6e4; JPN: 020dd0ec
extern "C" ARM void func_020db6e4(unsigned char* object, unsigned short value) {
 TileObject* entries=(TileObject*)GetObjectValue020db2dc((int)object,object[0x3c]);
 value|=0xf800;
 for(int row=0;row<3;++row) {
  for(int col=0;col<4;++col) {
   int index=col+row*4+0x10;
   entries[index].position=0xc0000000|((row<<6)&0xff)|((unsigned)(col<<29)>>7);
   entries[index].attribute.value=value;
   entries[index].attribute.fields.mode=2;
  }
 }
}
