#include <globaldefs.h>
struct Vector3i { int x,y,z; Vector3i& operator=(const Vector3i&); };
struct Object3D { char pad[0x44]; Vector3i position; int GetHeight() const; };
class GameState { public: static GameState* GetInstance(); Object3D* GetCombatantByIndex(int); };
int ClampScaledStat_0216352c(int,float,float);
void ReadFields0x70To0x78(unsigned char*,int*,int*,int*);
int fix32abs(int);
int Vector3fixSquaredDistance(const Vector3i*,const Vector3i*);
void SetFlagOrState0216d530(void*,int);
void SetFields0x10To0x18(unsigned char*,int,int,int);
void* GetActiveCombatWork();
extern "C" { void func_ov000_0216d370(void*,int,int,int); void func_0202e5d8(void*,int,int,int); void func_ov000_02167f10(void*); }
struct Camera { char p0[0x10]; Vector3i position; char p1[0x5c-0x1c]; int divisor,scale; char p2[0x220-0x64]; unsigned char mode; char p3[3]; int index; char p4[0x23c-0x228]; int angle; };
inline int IsParty(int n) { return n>=0 && n<=3; }
inline int IsEnemy(int n) { return n>=0xc0 && n<=0xc7; }
inline int HeightOffset(int h,float f) { return h-(int)(4096.0f*f); }
inline int Mul(int a,int b) { return (int)(((long long)a*b+0x800)>>12); }
// USA: func_ov000_0216df00
// JPN: func_ov000_0216df00
extern "C" ARM void func_ov000_0216df00(Camera* self,int id,int force,float offset,float factor) {
    Object3D* unit=GameState::GetInstance()->GetCombatantByIndex(id);
    if(!unit) return;
    int reuse=0;
    if(self->index==id && self->mode==1 && force==0) reuse=1;
    int party=0;
    if(IsParty(id)) party=1;
    int height=unit->GetHeight();
    int half=height/2;
    if(half<0x1000) half=0x1000;
    int minimum=(half+0x800)*self->scale/self->divisor;
    int distance=Mul(height,0x1ccc)+0x4000;
    if(party) distance=Mul(height,(int)(4096.0f*factor))+0x4000;
    if(IsEnemy(id)) distance+=Mul(ClampScaledStat_0216352c(id,1.5f,0.5f),0x1000);
    if(distance<minimum) distance=minimum;
    if(reuse) {
        int x=0,y=0,z=0;
        ReadFields0x70To0x78((unsigned char*)self,&x,&y,&z);
        if(x==0) {
            int tolerance=Mul(distance,0x400);
            if(fix32abs(z-distance)<tolerance) {
                Vector3i old(self->position), target;
                target.z=0; target.x=0; target.y=half;
                if(Vector3fixSquaredDistance(&old,&target)<0x1000) return;
            }
        }
    }
    func_ov000_0216d370(self,1,1,1);
    self->mode=1;
    SetFlagOrState0216d530(self,id);
    if(party) { int y=HeightOffset(half,offset); SetFields0x10To0x18((unsigned char*)self,0,y,0); }
    else SetFields0x10To0x18((unsigned char*)self,0,half,0);
    int low=half-0x1800;
    if(low<0) low=0;
    func_0202e5d8(self,0,low,distance);
    self->angle=-20;
    Vector3i pos(unit->position);
    int coordinates[2]={pos.x,pos.z};
    int changed=0;
    int* coordinate=coordinates;
    for(int i=0;i<2;i++,coordinate++) {
        if(*coordinate>0x6000) { *coordinate=0x6000; changed=1; }
        else if(*coordinate<-0x6000) { *coordinate=-0x6000; changed=1; }
    }
    pos.x=coordinates[0]; pos.z=coordinates[1];
    if(changed) {
        pos.y=0xcc;
        func_ov000_02167f10(GetActiveCombatWork());
        unit->position=pos;
    }
}
