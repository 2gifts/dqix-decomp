#include <globaldefs.h>
#include "System/Memory.h"

struct HandshakeState { unsigned char secret[0x30]; unsigned char resumed; char pad31[3]; unsigned char random[0x20]; char pad54[0x20]; unsigned char session[0x20]; char pad94[0x3c1]; unsigned char error; };
struct HandshakeConnection { char pad0[0xc]; HandshakeState* state; char pad10[8]; unsigned short field18; char pad1a[2]; void* field1c; };
struct ClientHello { unsigned char recordType, major, minor, recordLength[2], handshakeType, handshakeLength[3], helloMajor, helloMinor, random[32], sessionLength, session[32]; };
extern void* (*data_ov031_0224c994)(unsigned int);
extern void (*data_ov031_0224c9c0)(void*);
extern unsigned short data_ov031_022496fc[] __attribute__((aligned(4)));
extern "C" unsigned int func_ov031_02207c98();
extern "C" void func_ov031_02209cf8(void*,int);
extern "C" void func_ov031_02207aa4(HandshakeState*,void*,unsigned short);
extern "C" void func_ov031_022037a8(void*,int,int,int,HandshakeConnection*);
extern "C" void _Z24InitTwoSections_022098acPvii(void*,int,int);

// USA: func_ov031_02209ff0
extern "C" ARM void func_ov031_02209ff0(HandshakeConnection* connection) {
    HandshakeState* state=connection->state;
    ClientHello* hello=(ClientHello*)data_ov031_0224c994(0x98);
    if(!hello) { state->error=9; return; }
    hello->helloMajor=3; hello->helloMinor=0;
    unsigned int timestamp=func_ov031_02207c98();
    state->random[0]=timestamp>>24; state->random[1]=timestamp>>16;
    state->random[2]=timestamp>>8; state->random[3]=timestamp;
    func_ov031_02209cf8(state->random+4,28);
    VectorizedInvertedMemcpy(state->random,hello->random,32);
    func_ov031_02207aa4(state,connection->field1c,connection->field18);
    int length;
    char* cursor;
    if(!state->resumed) { hello->sessionLength=0; cursor=(char*)hello->session; }
    else { hello->sessionLength=32; VectorizedInvertedMemcpy(state->session,hello->session,32); cursor=(char*)hello->session+32; }
    length=0;
    cursor[0]=0; cursor[1]=4; cursor+=2;
    do {
        cursor[0]=data_ov031_022496fc[length]>>8;
        cursor[1]=data_ov031_022496fc[length];
        cursor+=2;
    } while((unsigned int)++length<2);
    cursor[0]=1; cursor[1]=0;
    cursor+=2;
    length=cursor-(char*)hello;
    length-=5;
    int payloadLength=length-4;
    hello->recordType=0x16; hello->major=3; hello->minor=0;
    hello->recordLength[0]=length>>8; hello->recordLength[1]=length;
    hello->handshakeType=1;
    hello->handshakeLength[0]=payloadLength>>16;
    hello->handshakeLength[1]=payloadLength>>8;
    hello->handshakeLength[2]=payloadLength;
    func_ov031_022037a8(hello,length+5,0,0,connection);
    _Z24InitTwoSections_022098acPvii(state,(int)&hello->handshakeType,length);
    data_ov031_0224c9c0(hello);
}
