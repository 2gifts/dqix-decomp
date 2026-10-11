#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "World/Object3D.h"
#include "std_library_functions.h"

extern "C" char* func_02012fe4(void);
void* GetPtrField0x468(void* obj);
extern "C" int _Z17IsInRange0201b5b0i(int id);
void ClearHalfword0x18(void* obj);
extern "C" void _Z19ClearBuffer0209bc84Pv(void* obj);
struct ResetObject0209af34Struct;
extern "C" void _Z19ResetObject0209af34P25ResetObject0209af34Struct(struct ResetObject0209af34Struct* obj);
extern "C" void _Z20Clear12Bytes0206efc4Pv(void* obj);
struct ZeroWordAndByte0206ee60Struct;
extern "C" void _Z23ZeroWordAndByte0206ee60P29ZeroWordAndByte0206ee60Struct(struct ZeroWordAndByte0206ee60Struct* obj);
extern "C" void _Z20Clear12Bytes020a8e88Pv(void* obj);
extern "C" void func_0201a300(char* zone, int floor, void* monster, int a, int b);

extern const char data_ov017_021d7afc[];
extern const char data_ov017_021d7b06[];
extern const char data_ov017_021d7b0d[];
extern const char data_ov017_021d7b24[];
extern const char data_ov017_021d7b3a[];

struct MonsterEntry021b478c {
    unsigned short key;
    unsigned char pad2[3];
    char name[1];
};

struct SearchTable;
MonsterEntry021b478c* FindEntryByHalfwordKey(struct SearchTable* table, int key);

struct Monster021b478c {
    unsigned short id;
    unsigned char pad2[0xc - 2];
    unsigned char loaded;
    unsigned char padd[0x10 - 0xd];
    SafeAllocator* allocator;
};

struct Request021b478c {
    unsigned char pad0;
    unsigned char done;
    unsigned char pad2[8 - 2];
    Monster021b478c* monster;
    int taskId;
    unsigned char state;
};

// JPN: func_ov017_021b4e7c
// USA: func_ov017_021b478c
extern "C" ARM void func_ov017_021b478c(Request021b478c* request) {
#if defined(jpn)
 enum {regionalOffset0=0x240c, regionalOffset1=0x40, regionalOffset2=0x5c, regionalOffset3=0x120, regionalOffset4=0x2f4, regionalOffset5=0x300, regionalOffset6=0x308, regionalOffset7=0x444};
#else
 enum {regionalOffset0=0x23ec, regionalOffset1=0x44, regionalOffset2=0x60, regionalOffset3=0x124, regionalOffset4=0x2f8, regionalOffset5=0x304, regionalOffset6=0x30c, regionalOffset7=0x424};
#endif
    GameState* battle;
    BackgroundLoader* loader;
    struct SearchTable* table;
    char* zone;
    int id;
    MonsterEntry021b478c* entry;
    char* monster;
    ActiveGrottoClass* grotto;

    battle = GameState::GetInstance();
    loader = BackgroundLoader::GetInstance();
    table = (struct SearchTable*)GetPtrField0x468(battle);
    zone = func_02012fe4();
    grotto = (ActiveGrottoClass*)(zone + regionalOffset0);
    id = request->monster->id;
    entry = FindEntryByHalfwordKey(table, id);

    monster = (char*)request->monster;
    ClearHalfword0x18(monster + regionalOffset1);
    _Z19ClearBuffer0209bc84Pv(monster + regionalOffset2);
    _Z19ResetObject0209af34P25ResetObject0209af34Struct((struct ResetObject0209af34Struct*)(monster + regionalOffset3));
    _Z20Clear12Bytes0206efc4Pv(monster + regionalOffset4);
    _Z23ZeroWordAndByte0206ee60P29ZeroWordAndByte0206ee60Struct((struct ZeroWordAndByte0206ee60Struct*)(monster + regionalOffset5));
    _Z20Clear12Bytes020a8e88Pv(monster + regionalOffset6);

    if (request->monster->id == 3 || request->monster->allocator->GetSignedAllocator() == NULL) {
        request->done = 1;
        return;
    }

    if (!_Z17IsInRange0201b5b0i(id)) {
        char name[0x14];
        char path[0x50];
        if (strlen(entry->name) < 6) {
            sprintf(name, data_ov017_021d7afc, entry->name);
        } else {
            sprintf(name, data_ov017_021d7b06, entry->name);
        }
        name[3] = 'P';
        strcpy(path, name);
        request->taskId = loader->QueueLoadFileInGP2(data_ov017_021d7b0d, path, NULL);
        request->state = 1;
        return;
    }

    if (id != battle->GetProtagonist()->obj3D_.GetField06()) {
        char ambl[0x50];
        sprintf(ambl, data_ov017_021d7b24, grotto->GetActiveGrottoEnviron());
        request->taskId = loader->QueueLoadFile(ambl, NULL);
        request->state = 2;
        return;
    }

    if (_Z17IsInRange0201b5b0i(id)) {
        int floor = id % 20;
        if (grotto->floorMap_.pMapData == NULL || *(int*)(zone + regionalOffset7) != 0) {
            return;
        }
        func_0201a300(zone, floor, request->monster, 0, 0);
    }
    request->monster->loaded = 1;
    request->taskId = loader->QueueLoadFile(data_ov017_021d7b3a, NULL);
    request->state = 3;
}
