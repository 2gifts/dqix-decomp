#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "System/Graphics.h"
#include "System/Interrupts.h"
#include "System/VRAM.h"

#define IRQ_MASTER_ENABLE (*(volatile unsigned short*)0x04000208)
#define SUB_BG0_SCROLL (*(volatile unsigned int*)0x04001010)

struct ScriptNode0218caa8 {
    unsigned short id;
    unsigned char padding2[2];
    int value;
    const char* mainName;
    const char* subName;
    unsigned char flags;
    unsigned char fade;
    short scene;
};

struct DisplayContext0218caa8 {
    int mode;
    unsigned char padding4[4];
    void* owner;
    unsigned char paddingc[4];
    int negativeScene;
    unsigned char padding14[0x20];
    ScriptNode0218caa8* node;
    unsigned char padding38[8];
    int displayState[2];
};

struct BackgroundGraphics {
    unsigned char padding0[0x1c];
    unsigned char screen : 4;
    unsigned char layer : 4;
    unsigned char padding1d;
    unsigned char padding1e[2];
};

struct List0204af64;
struct AllocTarget0204b12c;
struct Foo0204af38;
struct Rec020467f0;
struct ActiveEntry02046900;
struct Obj0204b8d0;
struct List0204b0e8;
struct Struct0200fb08;

void EncodeSignFlaggedHalfword(short*, int);
void ClearField0x0_020bc078(int*);
void CallField0xa00203aa44(void*);
int TryAllocateOrAppend0203aaf8(void*, void*, int*);
void EnsureInitAndSetFlag_0218be1c();
void InitOverlay17ObjAndBumpBattleCounter02012bd8();
int SetVBlankIrqEnable(int);
int GetWord0x7f6c(void*);
void SetSubBgMode(unsigned int);
void* AllocateAligned4(AllocatorUnion*, unsigned int);
void TailForward02012da4(AllocatorUnion*, void*);
void ResetList0204af64(List0204af64*);
void SetWord0x18ClearByte0x1f(unsigned char*, int);
void AllocateAndClearBuffer0204b12c(AllocTarget0204b12c*, SafeAllocator*);
void AllocateArray0204af38(Foo0204af38*, int, SafeAllocator*);
int CountActiveEntries(ActiveEntry02046900*);
void* FindRecordByIndex(Rec020467f0*, int, void**, int*);
int NormalizeField5_0200fb08(Struct0200fb08*);
void DispatchEntry0204b8d0(Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);
void FlushAndDispatchList0204b0e8(List0204b0e8*, void*);
void DelayThenSyncBit0();
extern "C" void func_020ca458(unsigned int, void*, unsigned int);
extern "C" void func_0204b5b4(BackgroundGraphics*, int);
extern "C" void func_0204b174(BackgroundGraphics*, void*, SafeAllocator*, unsigned int);
extern "C" void func_ov016_0218c04c(char*, void*);

extern DisplayContext0218caa8 data_ov016_0219d0c0;
extern int data_ov016_0219d0cc;
extern int data_02109bf4;
extern AllocatorUnion data_02114e20;
extern const char data_ov016_0219d030[];

// USA: func_ov016_0218caa8
extern "C" ARM void func_ov016_0218caa8(char* name, void* owner, ScriptNode0218caa8* node, int mode, void* script)
{
    EncodeSignFlaggedHalfword((short*)0x0400006c, -16);
    EncodeSignFlaggedHalfword((short*)0x0400106c, -16);
    data_ov016_0219d0c0.node = node;
    data_ov016_0219d0c0.displayState[0] = 0;
    data_ov016_0219d0c0.displayState[1] = 0;
    data_ov016_0219d0c0.negativeScene = node->scene < 0;
    data_ov016_0219d0c0.mode = mode;
    ClearField0x0_020bc078(&data_ov016_0219d0cc);
    if (data_ov016_0219d0c0.node->flags == 0)
    {
        CallField0xa00203aa44(&data_02109bf4);
        TryAllocateOrAppend0203aaf8(&data_02109bf4, (void*)(int)data_ov016_0219d0c0.node->scene, NULL);
    }
    SetInterruptHandler(1, (const void*)EnsureInitAndSetFlag_0218be1c);
    EnableSpecificInterrupts(0x60078);
    unsigned short previousMasterEnable = IRQ_MASTER_ENABLE;
    IRQ_MASTER_ENABLE = 1;
    SetVBlankIrqEnable(1);
    GameState* gameState = GameState::GetInstance();
    if (GetWord0x7f6c(gameState) == 5)
    {
        MapVRAMBanksToLCDC(0x1ff);
        func_020ca458(0, (void*)0x06800000, 0xa4000);
        func_020ca458(0xc0, (void*)0x07000000, 0x400);
        func_020ca458(0, (void*)0x05000000, 0x400);
        func_020ca458(0xc0, (void*)0x07000400, 0x400);
        func_020ca458(0, (void*)0x05000400, 0x400);
        MapVRAMBanksToLCDC(3);
        MapVRAMBanksToSubBG(0x80);
        SetSubBgMode(0);
        DISPCNTSUB = (DISPCNTSUB & ~0x1f00) | 0x100;
        BG0CNTSUB &= ~3;
        unsigned short backgroundControl = BG0CNTSUB;
        backgroundControl &= 0x43;
        backgroundControl |= 0xf00;
        BG0CNTSUB = backgroundControl;
        SUB_BG0_SCROLL = 0;

        void* buffer = AllocateAligned4(&data_02114e20, 0x2000);
        SafeAllocator allocator;
        allocator.ResetAllocatorPointer();
        allocator.ResetAllocatorPointer();
        allocator.CreateTypeA(buffer, 0x2000);
        BackgroundGraphics background;
        ResetList0204af64((List0204af64*)&background);
        background.screen = 1;
        background.layer = 0;
        func_0204b5b4(&background, 0);
        SetWord0x18ClearByte0x1f((unsigned char*)&background, 0);
        AllocateAndClearBuffer0204b12c((AllocTarget0204b12c*)&background, &allocator);
        AllocateArray0204af38((Foo0204af38*)&background, 5, &allocator);
        int task;
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        loader->MaybeReset();
        task = loader->QueueLoadFile(data_ov016_0219d030, NULL);
        void* recordName;
        void* archive;
        unsigned int archiveLength;
        for (;;)
        {
            if (loader->GetTaskStatus(task) != 0)
            {
                loader->GetLoadedFileByID(task, &archive, &archiveLength);
                int count = CountActiveEntries((ActiveEntry02046900*)archive);
                for (int index = 0; index < count; index++)
                {
                    int recordLength;
                    void* record = FindRecordByIndex((Rec020467f0*)archive, index, &recordName, &recordLength);
                    if (record != NULL)
                    {
                        func_0204b174(&background, record, &allocator, recordLength);
                    }
                }
                loader->RemoveTask(task);
                int selection = 0;
                switch (NormalizeField5_0200fb08((Struct0200fb08*)gameState))
                {
                case 2:
                    selection = 1;
                    break;
                case 3:
                    selection = 3;
                    break;
                case 4:
                    selection = 2;
                    break;
                case 5:
                    selection = 4;
                    break;
                }
                DispatchEntry0204b8d0((Obj0204b8d0*)&background, 0, 0, 0, 0, 0, 32, 25, 0xffff);
                if (selection > 0)
                {
                    DispatchEntry0204b8d0((Obj0204b8d0*)&background, (unsigned char)selection, 0, 0, 0, 17, 32, 25, 0xffff);
                }
                FlushAndDispatchList0204b0e8((List0204b0e8*)&background, NULL);
                break;
            }
            loader->RemoveAllLocks();
        }
        if (allocator.GetSignedAllocator() != NULL)
        {
            allocator.Destroy();
        }
        if (buffer != NULL)
        {
            TailForward02012da4(&data_02114e20, buffer);
        }
    }
    else
    {
        MapVRAMBanksToLCDC(0x1ff);
        func_020ca458(0, (void*)0x06800000, 0xa4000);
        DisableLCDCMappedVRAMBanks();
        func_020ca458(0xc0, (void*)0x07000000, 0x400);
        func_020ca458(0, (void*)0x05000000, 0x400);
        func_020ca458(0xc0, (void*)0x07000400, 0x400);
        func_020ca458(0, (void*)0x05000400, 0x400);
        MapVRAMBanksToLCDC(0x1ff);
    }
    DelayThenSyncBit0();
    data_ov016_0219d0c0.owner = owner;
    EncodeSignFlaggedHalfword((short*)0x0400006c, 0);
    EncodeSignFlaggedHalfword((short*)0x0400106c, 0);
    func_ov016_0218c04c(name, script);
    SetInterruptHandler(1, (const void*)InitOverlay17ObjAndBumpBattleCounter02012bd8);
}

