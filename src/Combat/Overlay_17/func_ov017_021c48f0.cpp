#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
struct Fields020407b4; struct Obj02033874; struct Bytes02033b88; struct SearchStruct0202c1a4;
struct Entry_02028bd0 { unsigned short id; unsigned short group:2,rest:14; };
struct Vec48f0 { int x,y,z; };
union Position48f0 { Vec48f0 plain; Vector3i vector; };
struct Event48f0 { unsigned char tag,pad[3]; unsigned short zone; unsigned char byte6,byte7; unsigned short field8; short x,y,z,angle; };
struct Actor48f0 { Object3D object; char padac[2]; short height; char padb0[0xd4-0xb0]; Vector3i previous; unsigned char flags; char pade1[0x130-0xe1]; unsigned int state; char pad134[0x158-0x134]; Vector3i target; unsigned short field164,slot; };
struct ActorHead48f0 { char pad0[0x130]; unsigned int* stats; };
struct Work48f0 { char pad0[3]; unsigned char active; char pad4[0x101-4]; unsigned char ready; };
struct Party48f0 { char pad0[0xf7d]; unsigned char flag; };
struct Resource48f0 { char pad0[0x36d0]; unsigned char* bits; char pad36d4[0x3734-0x36d4]; Work48f0* work; };
int GetSignedByte0x1ca_02039888(void*); void ClearFlag0x1ceBit0x4_02039d58(unsigned char*);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState*,int); int GetSignedByte0x2d0_020546a8(void*);
extern "C" unsigned short* func_02012fe4(); void ClearBytesAndZeroBlock02039d24(unsigned char*);
void SetFields0x44(Fields020407b4*,int,int,int); void SetVecYFromValue02033874(Obj02033874*,int); void SetByte0xbeShiftPrev(Bytes02033b88*,int);
void DispatchWithZeroExtras_02193428(void*,void*); void SetBit02026bc8(unsigned char*,int);
int GetSearchStructCurrentArrEntry(SearchStruct0202c1a4*);
extern "C" void func_ov017_0219dc90(GameResources*,int,int,int,int);
Entry_02028bd0* GetEntryTableBase_02027ca4(); Entry_02028bd0* FindInlineEntryById(Entry_02028bd0*,int);
extern "C" void func_ov017_021c8f3c(int,int); extern "C" void __clear(void*,int);
extern "C" void func_ov017_021c95ec(int,int,int,int,int,Vec48f0,int,int,int);
extern "C" void func_ov017_021c9168(int,int,int,int,Vec48f0,Vec48f0,int);
extern "C" void func_ov017_021c927c(int,int,int,Vec48f0,int,int,int);
extern "C" int func_0202c508(void*); extern "C" void func_ov017_021ce400(int,int);
int GetByteFieldMasked0x1ce_02039790(void*,int); extern "C" void func_ov017_021bd4d0(void*,int,int,int); extern "C" void func_ov017_021c3e18(unsigned char);

// USA: func_ov017_021c48f0
extern "C" ARM void func_ov017_021c48f0(int memberId,Event48f0* event,GameState* game,GameResources* resources,SearchStruct0202c1a4* search) {
    int leader;
    Entry_02028bd0* entry;
    Work48f0* work;
    work=((Resource48f0*)resources)->work;
    int zone=event->zone;
    Vector3i position;
    position.x=event->x<<5; position.y=event->y<<5; position.z=event->z<<5;
    if(zone==10000) zone=0x170c; else if(zone==10100) zone=0x1901;
    int count=0; leader=0;
    GameObject* actors[4]; actors[count++]=game->GetPartyMemberByIndex(memberId);
    if(actors[0]!=NULL) {
        GameObject* first=actors[0];
        if(*((ActorHead48f0*)first)->stats&1) { leader=GetSignedByte0x1ca_02039888(first); GameObject* actor=game->GetPartyMemberByIndex(leader); if(actor!=NULL) ClearFlag0x1ceBit0x4_02039d58((unsigned char*)actor); }
        else { ClearFlag0x1ceBit0x4_02039d58((unsigned char*)first); leader=memberId; }
        for(int i=0;i<4;i++) { GameObject* actor=GetCombatantWithFlag0x1000_0200ff58(game,i); if(actor!=NULL && memberId==GetSignedByte0x2d0_020546a8(actor)) actors[count++]=actor; }
        int reveal=(work->active==0 || work->ready==0)?1:0;
        for(int i=0;i<count;i++) {
            GameObject* actor=actors[i];
            if(actor==NULL) continue;
            if(!actor->obj3D_.IsVisible() && reveal) {
                if(event->byte7==0 || zone!=*func_02012fe4()) actor->obj3D_.MakeVisible();
                ClearBytesAndZeroBlock02039d24((unsigned char*)actor);
                if(event->zone==10000 && GetSignedByte0x1ca_02039888(actor)!=-1) SetFields0x44((Fields020407b4*)actor,0xff000,0,0xff000);
                else actor->obj3D_.position_=position;
                SetVecYFromValue02033874((Obj02033874*)actor,event->angle);
                if(i!=0) SetByte0xbeShiftPrev((Bytes02033b88*)actor,0);
                ((Actor48f0*)actors[i])->previous=position;
                ((Actor48f0*)actors[i])->flags|=0x20;
            }
            if(event->zone==10000 && leader==actor->obj3D_.unknown_4_ && reveal) {
                SetFields0x44((Fields020407b4*)actors[i],0x5f0a,0x3614,0x570);
                SetVecYFromValue02033874((Obj02033874*)actors[i],0x4b66);
            }
            actor->obj3D_.EnableFlag(0x4000000);
            if(work->active==0) DispatchWithZeroExtras_02193428(actor,0);
            SetBit02026bc8(((Resource48f0*)resources)->bits,actor->obj3D_.unknown_4_);
        }
    }
    if(GetSearchStructCurrentArrEntry(search)==0) {
        func_ov017_0219dc90(resources,memberId,event->zone,event->byte6,event->field8);
        entry=FindInlineEntryById(GetEntryTableBase_02027ca4(),zone);
        if(entry!=NULL) {
            int height;
            Position48f0 actorPosition,rotation,target;
            Vec48f0 zero1,zero4,zero9;
            for(int i=0;i<12;i++) {
                int base=entry->group*12+0x70;
                GameObject* monster=game->GetMaybeFieldMonsterByIndex(i+base);
                if(monster==NULL || monster->obj3D_.unknown_2_<0) continue;
                int slot;
                int kind=monster->obj3D_.unknown_2_;
                actorPosition=*(Position48f0*)&monster->obj3D_.position_;
                rotation=*(Position48f0*)&monster->obj3D_.rotation_;
                slot=((Actor48f0*)monster)->slot;
                func_ov017_021c8f3c(i+base,memberId);
                switch(((Actor48f0*)monster)->state) {
                case 1: __clear(&zero1,12); func_ov017_021c95ec(zone,i,kind,1,-1,zero1,0,0,0); break;
                case 2: func_ov017_021c9168(zone,i,kind,((Actor48f0*)monster)->field164,actorPosition.plain,rotation.plain,memberId); break;
                case 3: target.vector=((Actor48f0*)monster)->target; func_ov017_021c927c(zone,i,kind,target.plain,height,3,-1); break;
                case 4: __clear(&zero4,12); func_ov017_021c95ec(zone,i,kind,4,slot,zero4,0,0,0); break;
                case 5: height=((Actor48f0*)monster)->height; target.vector=((Actor48f0*)monster)->target; func_ov017_021c927c(zone,i,kind,target.plain,height,5,slot); break;
                case 6: height=((Actor48f0*)monster)->height; target.vector=((Actor48f0*)monster)->target; func_ov017_021c927c(zone,i,kind,target.plain,height,6,slot); break;
                case 7: height=((Actor48f0*)monster)->height; target.vector=((Actor48f0*)monster)->target; func_ov017_021c927c(zone,i,kind,target.plain,height,7,slot); break;
                case 9: __clear(&zero9,12); func_ov017_021c95ec(zone,i,kind,9,memberId,zero9,0,0,0); break;
                }
            }
        }
    }
    Party48f0* party=(Party48f0*)GetPtrField0x2a04_02010828(game);
    if(func_0202c508(search) && party->flag!=0) func_ov017_021ce400(party->flag,*func_02012fe4());
    if(game->GetPartyMemberByIndex(leader)!=NULL && GetByteFieldMasked0x1ce_02039790(game->GetPartyMemberByIndex(leader),0x20)) func_ov017_021bd4d0(work,(unsigned char)leader,0,1);
    if(zone==*func_02012fe4()) func_ov017_021c3e18(0);
}
