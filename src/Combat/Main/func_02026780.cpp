#include <globaldefs.h>
#include "World/LootableContainer.h"
#include "Memory/SafeAllocator.h"
#include "System/Memory.h"
#include "System/Matrix.h"

extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* p);
extern "C" void* func_02012fe4(void);

extern "C" void _Z20ClearRecords02026644Pc(char* obj);
extern "C" void _Z20AppendRecord020269e4PcPKv(char* obj, const void* src);

struct Cont02026780 {
    unsigned short uniqueID;
    unsigned short itemIDOrRank;
    unsigned short unk_4_0 : 2;
    unsigned short lootType : 2;
    unsigned short containerType : 3;
    short unk_6;
    Vector3fix position;
    struct Cont02026780* pNext;
};

struct Node02026780 {
    unsigned char type;
    unsigned char pad1;
    unsigned char numNames;
    unsigned char pad3;
    char* names;
    fix32_t x;
    fix32_t z;
    struct Node02026780* next;
};

struct Obj02026780 {
#if defined(jpn)
    unsigned char pad0[0x6a8];
#else
    unsigned char pad0[0x754];
#endif
    struct Node02026780* nodes;
    unsigned char pad2[0x22];
    unsigned char count;
    unsigned char pad3[1];
    char* names;
    unsigned char recCount;
    unsigned char pad5[0x9b8 - 0x781];
    unsigned char flag;
};

struct Rec02026780 {
    unsigned short id;
    unsigned short f2;
    unsigned short f4;
    unsigned short f6;
    unsigned short f8;
    unsigned short fA;
    unsigned int pad;
    Vector3fix pos;
};

struct Mgr02026780 {
    char unk_0[4];
    Cont02026780* pContainerList_;
    unsigned short numEntries_;
};

// USA: func_02026780
// JPN: func_02026780
extern "C" ARM int func_02026780(Obj02026780* self, void* fileBuf, unsigned int fileSize) {
    char buffer[0x800];
    SafeAllocator alloc;
    Mgr02026780 mgr;
    Rec02026780 rec;
    int i;
    int notFound;
    fix32_t ax;
    fix32_t az;
    struct Node02026780* node;

    if (self->count == 0 || self->names == 0) {
        return 0;
    }

    if (func_0202c540(func_0202ae18()) != 0) {
        _Z20ClearRecords02026644Pc((char*)self);
        return 0;
    }

    func_02012fe4();
    alloc.ResetAllocatorPointer();
    alloc.ResetAllocatorPointer();
    alloc.CreateTypeA(buffer, sizeof(buffer));

    self->recCount = 0;

    for (i = 0; i < self->count; i++) {
        ax = 0;
        az = ax;
        node = self->nodes;
        notFound = 1;

        while (node != 0 && notFound) {
            if (node->type == 1) {
                int j = 0;
                while (j < node->numNames && notFound) {
                    if (*(unsigned short*)(node->names + j * 2)
                        == *(unsigned short*)(self->names + i * 0x1a)) {
                        ax = node->x;
                        az = node->z;
                        notFound = 0;
                    }
                    j++;
                }
            }
            node = node->next;
        }

        alloc.Reset();
        ((LootableContainerManager*)&mgr)->Reset();
        ((LootableContainerManager*)&mgr)->Reset();

        ((LootableContainerManager*)&mgr)->LoadZoneContainers(
            fileBuf, fileSize, self->names + i * 0x1a + 2, &alloc);

        for (Cont02026780* c = mgr.pContainerList_; c != 0; c = c->pNext) {
            VectorizedMemset(&rec, 0, sizeof(rec));
            rec.id = c->uniqueID;
            rec.f2 = c->unk_4_0;
            rec.f4 = c->lootType;
            rec.f6 = c->containerType;
            rec.pos = c->position;

            if (rec.f6 == 0) {
                if (c->itemIDOrRank == 0) {
                    rec.f8 = 0;
                } else {
                    rec.f8 = 1;
                }
                rec.fA = rec.f8;
                if (!notFound) {
                    rec.pos.x = ax + fix32_Divide(c->position.x, 9830);
                    rec.pos.z = az + fix32_Divide(c->position.z, 9830);
                }
                _Z20AppendRecord020269e4PcPKv((char*)self, &rec);
            }
        }

        ((LootableContainerManager*)&mgr)->ResetAllocator(&alloc);
        ((LootableContainerManager*)&mgr)->Reset();
    }

    alloc.Destroy();
    self->flag = 0;
    return 1;
}
