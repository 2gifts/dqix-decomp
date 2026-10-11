#include <globaldefs.h>
#include <std_library_functions.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>

struct BinarySearchByComparatorStruct;
struct TableA68;
struct Words021edf38;
struct Reset_021eefac;
struct S_a0110;
struct S_a0330;
struct S_a0388;

struct MessageName_021eefd0;
void SetWords_021edf38_021edf38(void* dst, Words021edf38* src);

struct MessageName_021eefd0 {
    const char* text_;
    const char* unk_4;
    unsigned int unk_8;

    MessageName_021eefd0& operator=(const MessageName_021eefd0& other)
    {
        SetWords_021edf38_021edf38(this, (Words021edf38*)&other);
        return *this;
    }
};

struct MessageSystem_021eefd0 {
    char unk_0[0x10];
    MessageName_021eefd0* unk_10;
    char unk_14[0x20 - 0x14];
    MessageName_021eefd0* unk_20;
#if defined(jpn)
    char unk_24[0x868 - 0x24];
    int busy_;
    char unk_86c[0x17e2 - 0x86c];
    unsigned char unk_19b2;

#else
    char unk_24[0x998 - 0x24];
    int busy_;
    char unk_99c[0x19b2 - 0x99c];
    unsigned char unk_19b2;
    char unk_19b3[0x19d7 - 0x19b3];
    unsigned char unk_19d7;

#endif
};

struct PlayRecords_021eefd0 {
    char unk_0[0xc];
    unsigned int unk_c_0 : 7;
    unsigned int unk_c_7 : 7;
    unsigned int unk_c_14 : 14;
    unsigned int unk_c_28 : 4;
    char unk_10[0x68 - 0x10];
    char unk_68[0xb0 - 0x68];
};

struct DetailedTreasureMapData_021eefd0 {
    unsigned char discoveryState_;
    unsigned char mapType_;
    char unk_2[0xe - 2];
    char clearedBy_[0xc];
    char unk_1a[0x56 - 0x1a];
    unsigned char legacyLevel_;
    char unk_57[0x65 - 0x57];
    unsigned char regularLevel_;
};

class ActiveGrottoClass {
public:
    DetailedTreasureMapData_021eefd0* GetDetailedData();
};

struct ZoneData_021eefd0 {
    unsigned short id_;
#if defined(jpn)
    char unk_2[0x240c - 2];
#else
    char unk_2[0x23ec - 2];
#endif

    ActiveGrottoClass grotto_;
};

struct GrottoStruct_021eefd0 {
    unsigned char unknown_0[4];
};

struct GameObject_021eefd0 {
    char unk_0[0x134];
    void* baseStats_;
};

struct GameState {
    static GameState* GetInstance();
    GameObject_021eefd0* GetProtagonist();
    GrottoStruct_021eefd0* GetGrottoStruct();
};

struct GameResources_021eefd0 {
#if defined(jpn)
    char unk_0[0x3508];
#else
    char unk_0[0x3718];
#endif

    void* unknown_ptr_3718;
};

struct Unknown_021b8478_021eefd0 {
    char unk_0[0xc];
    int unk_c;
};

struct BattleData_021eefd0 {
    char unk_0[0x8e30];
    int monsterCount_;
};

struct BattleInfo_021eefd0 {
    char unk_0[0x24];
    unsigned char grotto_;
    unsigned char legacyBoss_;
    char unk_26[0x678 - 0x26];
    char monsters_[0xc];
};

struct BattleEnd_021eefd0 {
    int step_;
    int task_;
    int task2_;
    int task3_;
    unsigned char nothing_;
    char unk_11[0x10c - 0x11];
    char monsters_[0xc];
};

struct BattleScene_021eefd0 {
    char unk_0[0x30];
    SafeAllocator allocator_;
#if defined(jpn)
    char unk_44[0x218 - 0x44];
    BattleData_021eefd0* data_;
    BattleInfo_021eefd0* info_;
    char unk_220[0xe28 - 0x220];
    int endState_;
    char unk_e2c[0x5ab9 - 0xe2c];
    unsigned char victory_;
    unsigned short victoryMonster_;
    char unk_5abc[0x5af4 - 0x5abc];
    char texts_[0x7028 - 0x5af4];
    int unk_6e38;
    char unk_702c[0x703a - 0x702c];
    unsigned char timer_;

#else
    char unk_44[0x29c - 0x44];
    BattleData_021eefd0* data_;
    BattleInfo_021eefd0* info_;
    char unk_2a4[0xeac - 0x2a4];
    int endState_;
    char unk_eb0[0x58c9 - 0xeb0];
    unsigned char victory_;
    unsigned short victoryMonster_;
    char unk_58cc[0x5904 - 0x58cc];
    char texts_[0x6e38 - 0x5904];
    int unk_6e38;
    char unk_6e3c[0x6e4a - 0x6e3c];
    unsigned char timer_;

#endif
};

extern "C" BattleEnd_021eefd0* _ZZ17GetGlobal021ffefcvE1s;
extern const char data_ov023_021fe230[];
extern const char data_ov023_021fe246[];
extern char data_02109bf4[];
#if defined(jpn)
extern const char data_ov023_021fd4ec[];
extern const char data_ov023_021fd504[];
extern "C" void func_02045d88(MessageSystem_021eefd0*, const char*, int);
#endif

MessageSystem_021eefd0* GetGlobalField0x1c020421a0();
void Clear12Bytes0206efc4(void* monsters);
void WrapCall0206f230With1000(int monsters, int allocator, int file, int size, int monster);
void* SearchWithComparator0206f4f0(BinarySearchByComparatorStruct* monsters, int id);
void Clear12Bytes020e46c4(void* name);
const char* FindEntryByKey(TableA68* texts, int id);
void LoadBattleBlock020ac4c0(void* records);
void AddClamped24BitFieldAt0x8(S_a0330* records, unsigned int value);
void AddClamped16BitFieldHighAt0x10(S_a0110* time, unsigned int value);
void AddClamped14BitFieldMidAt0xc(S_a0388* records, unsigned int value);
void CopyInBattleField0x7540(void* records);
void ResetAndDispatchActorContext0209c6d8(void* obj, short value);
void EnqueueEventTag162_021cfc74(unsigned char value);
void ResetFields_021eefac(Reset_021eefac* end);
int IsInRange0201b588(int zone);
void DispatchAndSetTreasureMapUnknownBit(char* gameState, int map);

extern "C" {
void __clear(void* buffer, unsigned long size);
GameResources_021eefd0* func_ov017_0218b5b0();
Unknown_021b8478_021eefd0* func_ov017_021b8478(void* unk);
MessageName_021eefd0 func_ov023_021ed804(MessageName_021eefd0 name, void* monster);
void func_0204500c(MessageSystem_021eefd0* messages, const char* text, int a, int b);
void* func_0202ae18();
int func_0202c508(void* unk);
int func_0202c540(void* unk);
int func_ov023_021f4fc8();
ZoneData_021eefd0* func_02012fe4();
void func_020426bc(void* name, char* buffer, int a);
void VectorizedMemset(void* dst, int value, unsigned int size);
void VectorizedInvertedMemcpy(const void* src, void* dst, unsigned int size);
void func_02011744(GameState* gameState);
}

// JPN: func_ov023_021eed20
// USA: func_ov023_021eefd0
extern "C" ARM int func_ov023_021eefd0(BattleScene_021eefd0* self)
{
    BattleEnd_021eefd0* end = _ZZ17GetGlobal021ffefcvE1s;
    if (end->step_ == 0)
    {
        void* monsters = self->info_->monsters_;
        MessageSystem_021eefd0* messages = GetGlobalField0x1c020421a0();
        BackgroundLoader* loader = BackgroundLoader::GetInstance();
        int load = 1;
        if (_ZZ17GetGlobal021ffefcvE1s->task3_ > -1)
        {
            if (loader->GetTaskStatus(_ZZ17GetGlobal021ffefcvE1s->task3_))
            {
                void* file;
                unsigned int size;
                loader->GetLoadedFileByID(_ZZ17GetGlobal021ffefcvE1s->task3_, &file, &size);
                if (file != NULL)
                {
                    self->allocator_.Reset();
                    monsters = _ZZ17GetGlobal021ffefcvE1s->monsters_;
                    Clear12Bytes0206efc4(monsters);
                    WrapCall0206f230With1000((int)monsters, (int)&self->allocator_, (int)file, size, (short)self->victoryMonster_);
                }
                loader->RemoveTask(_ZZ17GetGlobal021ffefcvE1s->task3_);
                _ZZ17GetGlobal021ffefcvE1s->task3_ = -1;
                load = 0;
            }
            else
            {
                return self->endState_;
            }
        }
        if (load && self->victoryMonster_ != 0 && SearchWithComparator0206f4f0((BinarySearchByComparatorStruct*)monsters, (short)self->victoryMonster_) == NULL)
        {
            monsters = _ZZ17GetGlobal021ffefcvE1s->monsters_;
            if (SearchWithComparator0206f4f0((BinarySearchByComparatorStruct*)monsters, (short)self->victoryMonster_) == NULL)
            {
#if defined(jpn)
                _ZZ17GetGlobal021ffefcvE1s->task3_ = loader->QueueLoadFile(data_ov023_021fd4ec, NULL);
#else
                _ZZ17GetGlobal021ffefcvE1s->task3_ = loader->QueueLoadFileInGP2(data_ov023_021fe230, data_ov023_021fe246, NULL);
#endif

                return self->endState_;
            }
        }
        GameResources_021eefd0* resources = func_ov017_0218b5b0();
        void* unk = NULL;
        Unknown_021b8478_021eefd0* unk2 = NULL;
        int kind = -1;
        if (resources != NULL)
            unk = resources->unknown_ptr_3718;
        if (unk != NULL)
            unk2 = func_ov017_021b8478(unk);
#if defined(jpn)
        char name[40];
        if (unk2 != NULL)
            kind = unk2->unk_c;
        __clear(name, sizeof(name));
        char text[80];
        switch (self->victory_)
        {
        case 0:
        {
            void* monster = SearchWithComparator0206f4f0((BinarySearchByComparatorStruct*)monsters, (short)self->victoryMonster_);
            if (monster != NULL)
                strcpy(name, *(const char**)monster);
            sprintf(text, FindEntryByKey((TableA68*)self->texts_, 1), name);
            break;
        }
        case 1:
        {
            void* monster = SearchWithComparator0206f4f0((BinarySearchByComparatorStruct*)monsters, (short)self->victoryMonster_);
            if (monster != NULL)
                sprintf(name, FindEntryByKey((TableA68*)self->texts_, 5), *(const char**)monster);
            sprintf(text, FindEntryByKey((TableA68*)self->texts_, 1), name);
            break;
        }
        case 2:
        {
            if (kind == 0x36 || kind == 0x43 || kind == 0x50)
                strcpy(name, data_ov023_021fd504);
            else
                strcpy(name, FindEntryByKey((TableA68*)self->texts_, 4));
            sprintf(text, FindEntryByKey((TableA68*)self->texts_, 1), name);
            break;
        }
        case 3:
        {
            void* monster = SearchWithComparator0206f4f0((BinarySearchByComparatorStruct*)monsters, (short)self->victoryMonster_);
            if (monster != NULL)
                strcpy(name, *(const char**)monster);
            sprintf(text, FindEntryByKey((TableA68*)self->texts_, 3), name);
            break;
        }
        case 4:
        {
            void* monster = SearchWithComparator0206f4f0((BinarySearchByComparatorStruct*)monsters, (short)self->victoryMonster_);
            if (monster != NULL)
                sprintf(name, FindEntryByKey((TableA68*)self->texts_, 5), *(const char**)monster);
            sprintf(text, FindEntryByKey((TableA68*)self->texts_, 3), name);
            break;
        }
        case 5:
        {
            strcpy(name, FindEntryByKey((TableA68*)self->texts_, 4));
            sprintf(text, FindEntryByKey((TableA68*)self->texts_, 3), name);
            break;
        }
        case 6:
        {
            void* monster = SearchWithComparator0206f4f0((BinarySearchByComparatorStruct*)monsters, (short)self->victoryMonster_);
            if (monster != NULL)
                strcpy(name, *(const char**)monster);
            sprintf(text, FindEntryByKey((TableA68*)self->texts_, 2), name);
            break;
        }
        case 7:
        {
            void* monster = SearchWithComparator0206f4f0((BinarySearchByComparatorStruct*)monsters, (short)self->victoryMonster_);
            if (monster != NULL)
                sprintf(name, FindEntryByKey((TableA68*)self->texts_, 5), *(const char**)monster);
            sprintf(text, FindEntryByKey((TableA68*)self->texts_, 2), name);
            break;
        }
        case 8:
        {
            strcpy(name, FindEntryByKey((TableA68*)self->texts_, 4));
            sprintf(text, FindEntryByKey((TableA68*)self->texts_, 2), name);
            break;
        }
        }

#else
        MessageName_021eefd0 name;
        if (unk2 != NULL)
            kind = unk2->unk_c;
        Clear12Bytes020e46c4(&name);
        void* monster = SearchWithComparator0206f4f0((BinarySearchByComparatorStruct*)monsters, (short)self->victoryMonster_);
        if (kind == 0x36 || kind == 0x43 || kind == 0x50)
            monster = SearchWithComparator0206f4f0((BinarySearchByComparatorStruct*)monsters, 0x1fc);
        if (monster != NULL)
        {
            name = func_ov023_021ed804(name, monster);
            messages->unk_20 = &name;
            messages->unk_10 = &name;
        }
        char text[0x12c];
        switch (self->victory_)
        {
        case 0:
            sprintf(text, FindEntryByKey((TableA68*)self->texts_, 1));
            break;
        case 1:
            messages->unk_19d7 = 1;
            sprintf(text, FindEntryByKey((TableA68*)self->texts_, 1));
            break;
        case 2:
            if (kind == 0x36 || kind == 0x43 || kind == 0x50)
                sprintf(text, FindEntryByKey((TableA68*)self->texts_, 1));
            else
                sprintf(text, FindEntryByKey((TableA68*)self->texts_, 0x32));
            break;
        case 3:
            sprintf(text, FindEntryByKey((TableA68*)self->texts_, 3));
            break;
        case 4:
            messages->unk_19d7 = 1;
            sprintf(text, FindEntryByKey((TableA68*)self->texts_, 3));
            break;
        case 5:
            sprintf(text, FindEntryByKey((TableA68*)self->texts_, 0x34));
            break;
        case 6:
            sprintf(text, FindEntryByKey((TableA68*)self->texts_, 2));
            break;
        case 7:
            messages->unk_19d7 = 1;
            sprintf(text, FindEntryByKey((TableA68*)self->texts_, 2));
            break;
        case 8:
            sprintf(text, FindEntryByKey((TableA68*)self->texts_, 0x33));
            break;
        }

#endif
        if (self->info_->legacyBoss_ != 0)
            strcat(text, FindEntryByKey((TableA68*)self->texts_, 0x22));
        else if (end->nothing_ == 0)
            strcat(text, FindEntryByKey((TableA68*)self->texts_, 0x22));
#if defined(jpn)
        func_02045d88(messages, text, 1);
#else
        func_0204500c(messages, text, 1, 0xe3);
#endif

        messages->unk_19b2 = 0;
        messages->busy_ = 1;
        if (self->data_->monsterCount_ > 0)
        {
            PlayRecords_021eefd0 records;
            LoadBattleBlock020ac4c0(&records);
            AddClamped24BitFieldAt0x8((S_a0330*)&records, 1);
            AddClamped16BitFieldHighAt0x10((S_a0110*)records.unk_68, 1);
            CopyInBattleField0x7540(&records);
        }
        if (!func_0202c540(func_0202ae18()) || self->info_->legacyBoss_ == 0)
            ResetAndDispatchActorContext0209c6d8(data_02109bf4, 0x36);
        end->step_++;
        if (self->info_->grotto_ != 0 || self->info_->legacyBoss_ != 0)
        {
            GrottoStruct_021eefd0* grotto = GameState::GetInstance()->GetGrottoStruct();
            self->unk_6e38 = 1;
            grotto->unknown_0[3] = 1;
            EnqueueEventTag162_021cfc74(1);
        }
        Clear12Bytes0206efc4(_ZZ17GetGlobal021ffefcvE1s->monsters_);
    }
    else if (end->step_ == 100)
    {
        self->timer_++;
        if (func_ov023_021f4fc8() || self->timer_ > 30)
        {
            ResetFields_021eefac((Reset_021eefac*)end);
            return 0x10;
        }
    }
    else if (end->step_ == 1)
    {
        if (func_ov023_021f4fc8())
            end->step_ = 2;
    }
    else if (end->step_ == 2)
    {
        ResetFields_021eefac((Reset_021eefac*)end);
        void* unk = func_0202ae18();
        ZoneData_021eefd0* zone = func_02012fe4();
        DetailedTreasureMapData_021eefd0* map = zone->grotto_.GetDetailedData();
        if (self->info_->legacyBoss_ != 0)
        {
            if (IsInRange0201b588(zone->id_))
            {
                PlayRecords_021eefd0 records;
                LoadBattleBlock020ac4c0(&records);
                AddClamped14BitFieldMidAt0xc((S_a0388*)&records, 1);
                if (map != NULL && map->mapType_ == 2 && map->legacyLevel_ > records.unk_c_7)
                    records.unk_c_7 = map->legacyLevel_;
                CopyInBattleField0x7540(&records);
            }
            return 4;
        }
        if (self->info_->grotto_ != 0)
        {
            DetailedTreasureMapData_021eefd0* map2 = func_02012fe4()->grotto_.GetDetailedData();
            GameState* gameState = GameState::GetInstance();
            if (func_0202c508(unk))
            {
                void* name = gameState->GetProtagonist()->baseStats_;
#if defined(jpn)

#else
                char buffer[0xa];
                __clear(buffer, sizeof(buffer));
                func_020426bc(name, buffer, 1);
#endif

                map2->discoveryState_ = 3;
                VectorizedMemset(map2->clearedBy_, 0, sizeof(map2->clearedBy_));
#if defined(jpn)
                VectorizedInvertedMemcpy(name, map2->clearedBy_, 10);
#else
                VectorizedInvertedMemcpy(buffer, map2->clearedBy_, sizeof(buffer));
#endif

                DispatchAndSetTreasureMapUnknownBit((char*)gameState, (int)map2);
                func_02011744(gameState);
            }
            if (IsInRange0201b588(zone->id_))
            {
                PlayRecords_021eefd0 records;
                LoadBattleBlock020ac4c0(&records);
                AddClamped14BitFieldMidAt0xc((S_a0388*)&records, 1);
                if (map != NULL && map->mapType_ == 1 && map->regularLevel_ > records.unk_c_0)
                    records.unk_c_0 = map->regularLevel_;
                CopyInBattleField0x7540(&records);
            }
        }
        return end->nothing_ ? 0xe : 6;
    }
    return self->endState_;
}
