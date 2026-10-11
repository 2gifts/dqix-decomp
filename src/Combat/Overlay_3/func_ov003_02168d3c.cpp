#include <globaldefs.h>
extern "C" void* memset(void*, int, unsigned int);
#include "GameState/GameState.h"

struct Struct_0205d81c;
struct Container020e0310;
struct StoreStruct;
extern "C" void* _Z26GetGlobalField0x1c020421a0v();
extern "C" void _Z17SetElementFieldC2P15Struct_0205d81cii(Struct_0205d81c*, int, int);
extern "C" int _Z21GetFieldByKey020e0434P17Container020e0310i(Container020e0310*, int);
extern "C" int _Z20AppendString02042058PcPKc(char*, const char*);
extern "C" void func_ov003_0216abd8(void*, char*);
extern "C" void func_ov003_02169c3c(void*);
extern "C" int func_ov003_02169eec(void*, void*);
extern "C" void func_02046380(void*);
void StoreInArray0x8b0(StoreStruct*, int, int);
void SetByteInRange(unsigned char*, int, unsigned char);
extern "C" void func_0205d6e4(Struct_0205d81c*, int);
extern "C" void* _Z23FindElementByC40205d81cP15Struct_0205d81ci(Struct_0205d81c*, int);
int AddCappedFieldF6c_02169938(int, int);
#if defined(jpn)
extern "C" void func_02045d88(void*, int, int);
extern "C" void func_020474a8(void*, int, int, char*);
enum { kMenu68d3c=0xe0, kStage68d3c=0x870, kFlag68d3c=0x17de, kTextSize68d3c=0x800 };
#else
extern "C" void func_0204500c(void*, int, int, int);
extern "C" void func_02046608(void*, int, int, char*, int, int, int);
enum { kMenu68d3c=0xe4, kStage68d3c=0x9a0, kFlag68d3c=0x19ae, kTextSize68d3c=0x960 };
#endif
struct Obj68d3c {
    char pad0[0x64];
    char messages[0x18];
    char* text;
    char pad80[kMenu68d3c-0x80];
    char menu[0x404];
    unsigned char state;
    char pad1[2];
    unsigned char changed;
    unsigned char next;
    char pad2[2];
    unsigned char digits[4];
    unsigned char limits[4];
    char pad3;
    unsigned int maximum;
    char pad4[0xa4];
    unsigned int selected;
};
struct Global68d3c {
    char pad0[kStage68d3c-8];
    int busy;
    int pad1;
    int stage;
    char pad2[kFlag68d3c-kStage68d3c-4];
    unsigned char flag;
};
struct Party68d3c { char pad0[0xf68]; unsigned int bank; unsigned int money; };
static inline void Show68d3c(Global68d3c* g, int text) {
#if defined(jpn)
    func_02045d88(g,text,0);
#else
    func_0204500c(g,text,0,0xe3);
#endif
}
static inline void Format68d3c(Global68d3c* g,int fmt,char* out) {
#if defined(jpn)
    func_020474a8(g,0xc,fmt,out);
#else
    func_02046608(g,0xc,fmt,out,0xe3,0,1);
#endif
}
// USA: func_ov003_02168d3c
// JPN: func_ov003_02168bbc
extern "C" ARM void func_ov003_02168d3c(Obj68d3c* self, void* arg, int key) {
    GameState* gs=GameState::GetInstance();
    Global68d3c* global=(Global68d3c*)_Z26GetGlobalField0x1c020421a0v();
    Party68d3c* party=(Party68d3c*)GetPtrField0x2a04(gs);
    if(global->stage==3) global->flag=0;
    if(self->state==0) {
        _Z17SetElementFieldC2P15Struct_0205d81cii((Struct_0205d81c*)self->menu,1,1);
        if(key==0x3f2) {
            int error=-1;
            if(party->bank>=0x3b9ac618) error=(short)(key+5);
            else if(party->money<1000) error=(short)(key+3);
            if(error>=0) {
                memset(self->text,0,kTextSize68d3c);
                int text=_Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)self->messages,error);
                _Z20AppendString02042058PcPKc(self->text,(const char*)text);
                func_ov003_0216abd8(self,self->text);
                Show68d3c(global,(int)self->text);
                self->state=3;
                return;
            }
            unsigned int value=party->money/1000;
            int multiplier=1;
            for(int i=3;i>=0;--i) {
                unsigned int a=value/multiplier;
                unsigned int b=value/(multiplier*10);
                self->limits[i]=a-b*10;
                multiplier*=10;
            }
            self->maximum=value*1000;
        } else if(key==0x3fc) {
            int error=-1;
            if(party->bank==0) error=(short)(key+3);
            else if(party->money>=0x989298) error=(short)(key+4);
            if(error>=0) {
                memset(self->text,0,kTextSize68d3c);
                int text=_Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)self->messages,error);
                _Z20AppendString02042058PcPKc(self->text,(const char*)text);
                func_ov003_0216abd8(self,self->text);
                Show68d3c(global,(int)self->text);
                self->state=3;
                return;
            }
            func_02046380(global);
            StoreInArray0x8b0((StoreStruct*)global,0,party->bank);
            SetByteInRange((unsigned char*)global,0,0);
            unsigned int value=party->bank/1000;
            unsigned int money=party->money/1000;
            int multiplier=1;
            if(0x270f-money<value) value=0x270f-money;
            for(int i=3;i>=0;--i) {
                unsigned int a=value/multiplier;
                unsigned int b=value/(multiplier*10);
                self->limits[i]=a-b*10;
                multiplier*=10;
            }
            self->maximum=value*1000;
        }
        int text=_Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)self->messages,(short)key);
        Show68d3c(global,text);
        self->state++;
    } else if(self->state==1) {
        if(global->stage==3) {
            func_ov003_02169c3c(self);
            _Z17SetElementFieldC2P15Struct_0205d81cii((Struct_0205d81c*)self->menu,0,0);
            _Z17SetElementFieldC2P15Struct_0205d81cii((Struct_0205d81c*)self->menu,2,0);
            self->state++;
        }
    } else if(self->state==2) {
        int result=func_ov003_02169eec(self,arg);
        if(result==-1) return;
        if(result==-2) {
            func_0205d6e4((Struct_0205d81c*)self->menu,1);
            _Z17SetElementFieldC2P15Struct_0205d81cii((Struct_0205d81c*)self->menu,1,1);
            memset(self->text,0,kTextSize68d3c);
            int text=_Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)self->messages,0x406);
            _Z20AppendString02042058PcPKc(self->text,(const char*)text);
            func_ov003_0216abd8(self,self->text);
            Show68d3c(global,(int)self->text);
            self->state++;
            return;
        }
        if(result!=0) return;
        func_0205d6e4((Struct_0205d81c*)self->menu,1);
        void* element=_Z23FindElementByC40205d81cP15Struct_0205d81ci((Struct_0205d81c*)self->menu,1);
        *(unsigned short*)((char*)element+0xc2)=1;
        bool success=false;
        bool error=false;
        int message=(short)key;
        if(message==0x3f2) {
            if(party->bank+self->selected>0x3b9ac618) {
                error=true;
                message=(short)(message+4);
            } else if(AddCappedFieldF6c_02169938((int)self,-self->selected)) {
                success=true;
                party->bank+=self->selected;
            }
        } else if(message==0x3fc) {
            if(self->selected<=party->bank) {
                if(party->money+self->selected>0x98967f) {
                    error=true;
                    message=(short)(message+4);
                } else {
                    party->bank-=self->selected;
                    AddCappedFieldF6c_02169938((int)self,self->selected);
                    success=true;
                }
            }
        }
        if(success) {
            self->changed=1;
            memset(self->text,0,kTextSize68d3c);
            func_02046380(global);
            StoreInArray0x8b0((StoreStruct*)global,0,self->selected);
            SetByteInRange((unsigned char*)global,0,0);
            int text=_Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)self->messages,(short)(message+1));
            Format68d3c(global,text,self->text);
            func_ov003_0216abd8(self,self->text);
            Show68d3c(global,(int)self->text);
            self->state++;
        } else if(error) {
            func_02046380(global);
            StoreInArray0x8b0((StoreStruct*)global,0,0x3b9ac618-party->bank);
            SetByteInRange((unsigned char*)global,0,0);
            int text=_Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)self->messages,message);
            Format68d3c(global,text,self->text);
            func_ov003_0216abd8(self,self->text);
            Show68d3c(global,(int)self->text);
            self->state++;
        } else {
            memset(self->text,0,kTextSize68d3c);
            int text=_Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)self->messages,(short)(message+2));
            _Z20AppendString02042058PcPKc(self->text,(const char*)text);
            text=_Z21GetFieldByKey020e0434P17Container020e0310i((Container020e0310*)self->messages,message);
            _Z20AppendString02042058PcPKc(self->text,(const char*)text);
            Show68d3c(global,(int)self->text);
            for(int i=0;i<4;++i) self->digits[i]=0;
            self->selected=0;
            self->state=1;
        }
    } else if(self->state==3) {
        if(global->busy==0) { self->next=6; self->state=0; }
    }
}
