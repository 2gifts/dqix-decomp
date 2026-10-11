#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
struct ActorData {char p[0x49c];unsigned char special:1,rest:7;};
struct Allocators {char p[0x52c];SafeAllocator first,second;};
struct Extension {char p[0x13c];int* scriptState;
#if defined(jpn)
char q[4];
#else
char q[16];
#endif
ActorData* actor;Allocators* allocators;};
inline int SetScriptState(Extension* unit,int value){return unit->scriptState?(*unit->scriptState=value):0;}
struct Item {signed char id;unsigned char phase;short first,second;};
struct Root {
#if defined(jpn)
char p[0x79c6];
#else
char p[0x77d6];
#endif
Item items[4];unsigned char count;inline int GetCount(){return count;}};
GameObject* GetCombatantWithFlag0x100(GameState*,int);int IsField0Null(void**);void FormatEffectStats02072c9c(int,char*);
struct Struct_203dafc;void ClearEightWords(Struct_203dafc*);struct StreamHeader;void RunOverlayScript0216d1c4(int,StreamHeader*,int,int*);struct Bytes02033b88;void SetByte0xbeShiftPrev(Bytes02033b88*,int);
extern "C" {int sprintf(char*,const char*,...);GameResources* func_ov017_0218b5b0();void func_ov000_0216867c(Root*,int);extern const char data_ov000_02183ad8[],data_ov000_02183ae0[],data_ov000_02183afb[],data_ov000_02183b03[];}
// USA: func_ov000_021682ec
// JPN: func_ov000_021682ec
extern "C" ARM void func_ov000_021682ec(Root* self){
 int count=self->count;BackgroundLoader* loader;GameState* gs;SafeAllocator* allocator;int i;Item* item;GameObject* unit; if(count==0)return;gs=GameState::GetInstance();loader=BackgroundLoader::GetInstance();void** resource=(void**)func_ov017_0218b5b0()->unknown_ptr_array_36fc[1];
 char filename[64];ObjectArchiveLoadInfo firstInfo,secondInfo;char code[8];void* file;unsigned int size;const void* script;unsigned int scriptSize;int scriptState;
 for(i=0;i<self->GetCount();i++){
  item=&self->items[i];
  if(item->phase==0){
   if(!IsField0Null(resource))return;unit=GetCombatantWithFlag0x100(gs,item->id);if(unit)unit->obj3D_.RemoveAllAnimationPackages();loader->AddFence();FormatEffectStats02072c9c(item->id,code);sprintf(filename,data_ov000_02183ad8,code);
   if(unit&&((Extension*)unit)->actor->special==1)filename[0]='w';
   item->first=loader->QueueLoadFileInGP2(data_ov000_02183ae0,filename,0);sprintf(filename,data_ov000_02183afb,code);item->second=loader->QueueLoadFileInGP2(data_ov000_02183ae0,filename,0);item->phase++;
  }else if(item->phase==1){
   if(!loader->GetTaskStatus(item->first))continue;unit=GetCombatantWithFlag0x100(gs,item->id);
   if(unit&&loader->GetDetailedTaskStatus(item->first)==2){
    loader->GetLoadedFileByID(item->first,&file,&size);Allocators* allocators=((Extension*)unit)->allocators;
    if(allocators&&file){allocator=&allocators->first;allocator->Reset();ClearEightWords((Struct_203dafc*)&firstInfo);firstInfo.unk_10=1;firstInfo.packageID=0;firstInfo.fileData=file;firstInfo.unk_8=size;firstInfo.allocator=allocator;unit->obj3D_.LoadFromCCHROrCMOTArchive(&firstInfo,0);}
   }
   loader->RemoveTask(item->first);item->first=0xffff;item->phase++;
  }else if(item->phase==2){
   if(!loader->GetTaskStatus(item->second))continue;unit=GetCombatantWithFlag0x100(gs,item->id);
   if(unit&&loader->GetDetailedTaskStatus(item->second)==2){
    loader->GetLoadedFileByID(item->second,&file,&size);Allocators* allocators=((Extension*)unit)->allocators;
    if(allocators&&file){allocator=&allocators->second;allocator->Reset();ClearEightWords((Struct_203dafc*)&secondInfo);secondInfo.unk_10=1;secondInfo.packageID=1;secondInfo.fileData=file;secondInfo.unk_8=size;secondInfo.allocator=allocator;unit->obj3D_.LoadFromCCHROrCMOTArchive(&secondInfo,0);
     if(FindFilesInNarcBySubstring(file,data_ov000_02183b03,&script,&scriptSize,1)){RunOverlayScript0216d1c4((int)allocator,(StreamHeader*)script,scriptSize,&scriptState);SetScriptState((Extension*)unit,scriptState);}
     SetByte0xbeShiftPrev((Bytes02033b88*)unit,0);
    }
   }
   loader->RemoveTask(item->second);item->second=0xffff;func_ov000_0216867c(self,item->id);
  }
 }
}
