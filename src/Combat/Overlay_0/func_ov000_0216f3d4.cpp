#include <globaldefs.h>
struct Vector3i { int x,y,z; };
struct Object3D { char pad[0x44]; Vector3i position; int GetRadius() const; int GetHeight() const; int IsVisible() const; int GetInheritedAlpha() const; int GetOwnAlpha() const; };
class GameState { public: static GameState* GetInstance(); Object3D* GetCombatantByIndex(int); };
void* GetActiveCombatWork();
float GetScaledField0x6002049fec(char*);
struct Obj02049f50;
void SetField41AndScaleSub02049f50(Obj02049f50*,int,int);
extern "C" { int func_ov000_02153e40(void*,short*,int,int); void Vector3fix_Subtract(const Vector3i*,const Vector3i*,Vector3i*); int Vector3fix_InnerProduct(const Vector3i*,const Vector3i*); int func_02049fc0(void*); }
struct Node { char p0[0x20]; unsigned short id; char p1[0xe]; Node* next; };
struct Group { char p0[0xe]; short ids[4]; unsigned char spare,count; char p1[8]; Group* next; };
struct Work { char p0[0x10]; Node* nodes; Group* groups; };
struct Camera { char p0[4]; Vector3i position; char p1[0x21c-0x10]; void* list; unsigned char mode,instant; char p2[2]; int index; char p3[0x260-0x228]; unsigned char active,state,first,second; char p4[0x278-0x264]; unsigned char enabled; char p5[3]; Work* work; };
inline int Square(int a) { return (int)(((long long)a*a+0x800)>>12); }
// USA: func_ov000_0216f3d4
// JPN: func_ov000_0216f3d4
extern "C" ARM void func_ov000_0216f3d4(Camera* self) {
    if(!self->list || !self->enabled) return;
    short ids[12];
    int count=func_ov000_02153e40(self->list,ids,12,0);
    GameState* gs=GameState::GetInstance();
    int duration=180;
    if(self->instant) { duration=0; self->instant=0; }
    short* id=ids;
    for(int i=0;i<count;i++,id++) {
        Object3D* unit=gs->GetCombatantByIndex(*id);
        if(!unit || !unit->IsVisible() || unit->GetInheritedAlpha()<=0) continue;
        Vector3i camera(self->position);
        int radius=unit->GetRadius()/2;
        int near=radius+0x2000;
        int far=radius+0x2b33;
        near=Square(near); far=Square(far);
        Vector3i origin(camera),position(unit->position),delta;
        position.y+=unit->GetHeight()/2;
        Vector3fix_Subtract(&position,&origin,&delta);
        int distance=Vector3fix_InnerProduct(&delta,&delta);
        int selected=self->index==*id;
        if(GetActiveCombatWork() && (self->active || self->work) && !selected) {
            Work* work=self->work;
            if(work) {
                Node* n=work->nodes;
                while(n) { if(n->id==*id) { selected=1; break; } n=n->next; }
                if(!selected) {
                    Group* g=work->groups;
                    while(g) {
                        short* entry=g->ids;
                        for(int j=0;j<g->count;entry++,j++) { if(*entry==*id) { selected=1; break; } }
                        if(selected) break;
                        g=g->next;
                    }
                }
            } else if(self->active) {
                if(self->first==*id || self->second==*id) selected=1;
            }
        }
        if(distance<=near && !selected) {
            if((!func_02049fc0(unit) && unit->GetOwnAlpha()>0) || (func_02049fc0(unit) && GetScaledField0x6002049fec((char*)unit)>0.0f))
                SetField41AndScaleSub02049f50((Obj02049f50*)unit,0,duration);
        } else {
            if(distance>=far || duration==0 || selected) {
                if(duration==0 || (!func_02049fc0(unit) && unit->GetOwnAlpha()<31) || (func_02049fc0(unit) && GetScaledField0x6002049fec((char*)unit)<31.0f))
                    SetField41AndScaleSub02049f50((Obj02049f50*)unit,31,duration);
            }
        }
    }
}
