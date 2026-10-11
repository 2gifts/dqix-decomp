#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"

extern "C" void* func_0202ae18(void);
extern "C" void __clear(void* buf, int size);
extern "C" void _Z20Clear12Bytes020a8e88Pv(void* p);
extern "C" void func_020a8fd0(void* obj, void* arg, void* file, unsigned int size, short* ids, int count);
extern "C" void func_ov017_021b5648(void* obj);

struct RowEntryA_021b5458 {
    unsigned int id : 12;
    int unk4;
};

struct RowEntryB_021b5458 {
    unsigned int id : 12;
};

struct GetRowByIndexRow {
    unsigned char unk0[2];
    unsigned char countA;
    unsigned char countB;
    struct RowEntryA_021b5458 entriesA[6];
    struct RowEntryB_021b5458 entriesB[6];
};

struct GetRowByIndexRow* GetRowByIndex(struct GetRowByIndexRow* base, int i);

struct Sub021b5458 {
    char pad0[0x10];
    void* field10;
#if defined(jpn)
    char pad14[0x120 - 0x14];
#else
    char pad14[0x124 - 0x14];
#endif

    struct GetRowByIndexRow rows[6];
    char pad2ec[0x30c - 0x2ec];
    unsigned char field30c[0xc];
};

struct Obj021b5458 {
    char pad0[8];
    struct Sub021b5458* sub;
    int key;
};

// JPN: func_ov017_021b5a0c
// USA: func_ov017_021b5458
extern "C" ARM void func_ov017_021b5458(struct Obj021b5458* obj) {
    struct Sub021b5458* sub;
    GameState::GetInstance();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    func_0202ae18();
    if (!loader->GetTaskStatus(obj->key)) {
        return;
    }

    if (loader->GetDetailedTaskStatus(obj->key) == 2) {
        unsigned int size;
        void* file;
        loader->GetLoadedFileByID(obj->key, &file, &size);
        if (file != 0) {
            short ids[64];
            __clear(ids, 0x80);
            short count = 0;
            sub = obj->sub;
            for (int i = 0; i < 6; i++) {
                struct GetRowByIndexRow* row = GetRowByIndex(sub->rows, i);
                if (row == 0) {
                    continue;
                }
                for (int j = 0; j < row->countA; j++) {
                    unsigned int id = row->entriesA[j].id;
                    int unique = 1;
                    for (int k = 0; k < count; k++) {
                        if (id == ids[k]) {
                            unique = 0;
                            break;
                        }
                    }
                    if (unique) {
                        ids[count++] = id;
                    }
                }
                for (int j = 0; j < row->countB; j++) {
                    unsigned int id = row->entriesB[j].id;
                    int unique = 1;
                    for (int k = 0; k < count; k++) {
                        if (id == ids[k]) {
                            unique = 0;
                            break;
                        }
                    }
                    if (unique) {
                        ids[count++] = id;
                    }
                }
            }
            sub = obj->sub;
            _Z20Clear12Bytes020a8e88Pv(sub->field30c);
            func_020a8fd0(sub->field30c, obj->sub->field10, file, size, ids, count);
        }
    }

    loader->RemoveTask(obj->key);
    obj->key = -1;
    func_ov017_021b5648(obj);
}
