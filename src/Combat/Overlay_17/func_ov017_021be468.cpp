#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "Filesystem/BackgroundLoader.h"
#include "Memory/AllocatorUnion.h"
#include "std_library_functions.h"
struct Obj020397cc; struct ListHead02046b60; struct Foo0207df50; struct Base02010834; struct TailList020469b4; struct TailNode020469b4;
struct StateE468 {
    unsigned char tag,done; char pad2[6]; int state,timer; Vector3i position; int field1c,task;
    SafeAllocator allocator; unsigned char actors,pending; unsigned short zone; unsigned char field3c; unsigned char flag:1,otherFlags:7; unsigned char field3e,field3f; unsigned short field40;
    short x,y,z; unsigned char field48; unsigned char low:4,high:4;
};
struct Foo0207df50 { unsigned int first[10],second[10],field50,field54,firstPair[2],secondPair[2]; };
struct SourceE468 { char pad0[0x568]; Foo0207df50 saved; };
struct ActorE468 { char pad0[0x154]; SourceE468* data; };
struct PackedFlagsE468 { unsigned char bit0:1,bit1:1,bit2:1,bit3:1,bit4:1,bit5:1,bit6:1,bit7:1; };
struct ParamsE468 {
    unsigned char active; char pad1[15]; unsigned char mode; PackedFlagsE468 flags; unsigned short field12;
    short field14,field16,field18,field1a,field1c; char pad1e[2]; int field20,field24,field28; Vector3i position,rotation,scale;
};
struct WorldE468 { unsigned short id; char pad2[2]; unsigned char field4; char pad5[2]; unsigned char field7,field8,field9,pada; signed char fieldb; unsigned char fieldc; char padd[3]; Vector3i position; unsigned short field1c; short field1e; int field20,field24,field28,field2c; char pad30[0x6c-0x30]; short field6c; char pad6e[2]; };
struct GrottoViewE468 { unsigned char active,pending; char pad2[3]; unsigned char environment,rank,pad7,field8; char pad9[3]; int zone; Vector3i entrance; char pad1c[0x6c-0x1c]; unsigned char field6c; char pad6d[0x83-0x6d]; unsigned char field83,field84,pad85; unsigned short field86; };
extern AllocatorUnion data_02114e20; extern char data_ov017_021d7e80[]; extern char data_02108760[];
extern "C" void func_0202ae18(); extern "C" void* func_02057924(); extern "C" unsigned char* func_02012fe4();
void CancelPendingAction020397cc(Obj020397cc*,int); void SetOrClearBit(unsigned char*,int,int);
int ListContainsId(ListHead02046b60*,int); extern "C" void func_02046b8c(void*,int); extern "C" void func_02046a8c(void*,void*);
void EnqueueEventTag33_021d2738(unsigned char,unsigned char); int IsField0Null(void**); void SetBitsInWord(unsigned int*,unsigned int);
void* GetGlobal02109400(); extern "C" void func_02094ab0(void*); extern "C" void func_020a0cc4(unsigned int);
void* AllocateAligned4(AllocatorUnion*,unsigned int); void CopyInternalFields0207df50(Foo0207df50*);
extern "C" void func_02057e6c(void*,int,SafeAllocator*,void*,unsigned int,Foo0207df50*);
int IsMainBrightnessTransitionActive(GameResources*); void CopyCountedBytesToIntArray02010834(Base02010834*,int,int*,int*);
void FindNodeAndProcess02057fb4(void*,int,int); void SetForwardAndStore0205ebc0(void*,int,int); void DispatchIfField0xc4NonNeg_0205ebfc(void*,int,int);
void SetBrightness(GameResources*,int,int); void ClearBitsInWord(unsigned int*,unsigned int); void CallListIfFlagsSet_02197528();
WorldE468* GetField0x3f8Address(GameState*); extern "C" void VectorizedMemset(void*,int,int);
void InitAndResetHeader_0219e310(unsigned char*,int); void AppendNodeToTail(TailList020469b4*,TailNode020469b4*);
void SetByteField0x253(void*); extern "C" void func_ov017_021beb48(StateE468*); void ForwardField0xc0_0205ebec(void*);

// USA: func_ov017_021be468
extern "C" ARM void func_ov017_021be468(StateE468* self,ListHead02046b60* list) {
    GameState* game=GameState::GetInstance(); func_0202ae18();
    GameResources* resources=func_ov017_0218b5b0();
    GameObject* actor=game->GetUnknownGameObject();
    void* battle=func_02057924(); BackgroundLoader* loader=BackgroundLoader::GetInstance(); unsigned char* zone=func_02012fe4();
    if(self->state==0) {
        CancelPendingAction020397cc((Obj020397cc*)actor,1); SetOrClearBit(zone,1,0);
        if(ListContainsId(list,3)) func_02046b8c(list,3);
        else {
            if(ListContainsId(list,0x34)) func_02046a8c(list,resources->unknown_ptr_array_3afc[28]);
            if(ListContainsId(list,0x2e)) { func_02046a8c(list,resources->unknown_ptr_array_3afc[21]); EnqueueEventTag33_021d2738((unsigned char)actor->obj3D_.unknown_4_,0); }
            if(IsField0Null((void**)resources->unknown_ptr_array_36fc[1])) {
                SetBitsInWord((unsigned int*)resources,0x10); func_02094ab0(GetGlobal02109400()); func_020a0cc4(0x2800);
                self->task=loader->QueueLoadFile(data_ov017_021d7e80,0); self->state++;
            }
        }
    } else if(self->state==1) {
        if(loader->GetTaskStatus(self->task)!=0) {
            if(loader->GetDetailedTaskStatus(self->task)!=2) { loader->RemoveTask(self->task); self->done=1; }
            {
                unsigned int length; void* file; loader->GetLoadedFileByID(self->task,&file,&length);
                self->allocator.CreateTypeA(AllocateAligned4(&data_02114e20,0x2800),0x2800); self->allocator.Reset();
                Foo0207df50* source=&((ActorE468*)game->GetUnknownGameObject())->data->saved;
                CopyInternalFields0207df50(source);
                void* copy=self->allocator.Allocate(length); memcpy(copy,file,length);
                func_02057e6c(battle,5,&self->allocator,copy,length,source); loader->RemoveTask(self->task); self->state++;
            }
        }
    } else if(self->state==2) {
        if(!IsMainBrightnessTransitionActive(resources)) {
            int ids[5],count=0; CopyCountedBytesToIntArray02010834((Base02010834*)game,actor->obj3D_.unknown_4_,ids,&count);
            for(int i=0;i<count;i++) self->actors|=1<<ids[i];
            ParamsE468 params[5];
            for(int i=0;i<count;i++) {
                GameObject* member=game->GetGameObjectByIndex(ids[i]); if(member==NULL) continue;
                params[i].active=0; params[i].mode=1; params[i].field12=0;
                params[i].field14=-1; params[i].field16=-1; params[i].field18=-1; params[i].field1a=-1; params[i].field1c=-0x1000;
                params[i].field20=0; params[i].field24=0; params[i].field28=0;
                params[i].position.x=0; params[i].position.y=0; params[i].position.z=0;
                params[i].rotation.x=0; params[i].rotation.y=0; params[i].rotation.z=0;
                params[i].scale.x=0x1000; params[i].scale.y=0x1000; params[i].scale.z=0x1000;
                ParamsE468* p=&params[i]; p->flags.bit0=0; p->flags.bit1=0; p->flags.bit2=1; p->flags.bit3=0; p->flags.bit4=0; p->flags.bit5=0; p->flags.bit6=0; p->flags.bit7=0;
                p->position=member->obj3D_.position_; p->scale=member->obj3D_.GetScale();
                ((void (*)(void*,int,ParamsE468*))FindNodeAndProcess02057fb4)(battle,5,p);
            }
            self->state++;
        }
    } else if(self->state==3) {
        self->timer++;
        if(self->timer==5) { SetForwardAndStore0205ebc0(data_02108760,0xb1,0xb1); DispatchIfField0xc4NonNeg_0205ebfc(data_02108760,0,0); }
        if(self->timer>25) {
            for(int i=0;i<5;i++) if(self->actors&(1<<i)) { GameObject* member=game->GetGameObjectByIndex(i); if(member!=NULL) member->obj3D_.EnableFlag(1); }
            self->state++;
        }
    } else if(self->state==4) {
        self->timer++; if(self->timer>55) { SetBrightness(resources,-16,30); self->state++; }
    } else if(self->state==5) {
        self->timer++;
        if(self->timer>85) {
            for(int i=0;i<5;i++) if(self->actors&(1<<i)) { GameObject* member=game->GetGameObjectByIndex(i); if(member!=NULL) member->obj3D_.DisableFlag(1); }
            ClearBitsInWord((unsigned int*)resources,0x10); CallListIfFlagsSet_02197528();
            WorldE468* world=GetField0x3f8Address(game); VectorizedMemset(world,0,0x70);
            world->field4=1; world->field8=1; world->field9=1; world->fieldb=-1;
            world->field20=-1; world->field24=-1; world->field28=-1; world->field2c=-1; world->field1e=-1; world->fieldc=0; world->field6c=-1;
            world->id=self->field1c; world->field7=1; world->field1c=0x3244; world->position=self->position;
            TailList020469b4* nodes=(TailList020469b4*)resources->unknown_ptr_array_36fc[0]; unsigned char* node=(unsigned char*)resources->unknown_ptr_array_36fc[4];
            InitAndResetHeader_0219e310(node,0); AppendNodeToTail(nodes,(TailNode020469b4*)node);
            if(self->pending) {
                GrottoViewE468* grotto=(GrottoViewE468*)game->GetGrottoStruct();
                grotto->zone=self->zone; grotto->field6c=self->field3c;
                int active; if(self->flag) active=1; else active=0; grotto->active=active;
                grotto->entrance.x=self->x<<7; grotto->entrance.y=self->y<<7; grotto->entrance.z=self->z<<7;
                grotto->field83=self->field3e; grotto->field84=self->field3f; grotto->field86=self->field40;
                grotto->rank=self->low; grotto->environment=self->high; grotto->field8=self->field48; grotto->pending=0; self->pending=0;
            }
            self->done=1; SetByteField0x253(actor); func_ov017_021beb48(self);
            ForwardField0xc0_0205ebec(data_02108760);
        }
    }
}
