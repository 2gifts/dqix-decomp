#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/Vector.h"

struct CharacterModel_021fc7c8
{
    char unk_0[0xc12];
    unsigned char loading_;
    char unk_c13[0xc20 - 0xc13];
};

class MenuCharacter_021fc7c8
{
public:
    unsigned short type_;
    unsigned short id_;
    unsigned short heap_;
    unsigned short vramState_;
    unsigned char flags_;
    char unk_d[3];
    const char* file_;
    void* prev_;
    void* next_;
    int state_;
    CharacterModel_021fc7c8 models_[2];
    int perspective_;
    unsigned char current_ : 1;
    unsigned char turnBack_ : 1;
    unsigned char unk_1864_2 : 1;
    unsigned char swap_ : 1;
    void (**leftCallback_)(void* script);
    void (**rightCallback_)(void* script);

    virtual void Update(void* script);
};

struct Words021e60c4;

void SetFogState_020c54a4(int, unsigned int, unsigned int, unsigned short);
extern "C" void func_ov023_021e5020(CharacterModel_021fc7c8* model);
extern "C" Vector3i func_ov023_021e613c(CharacterModel_021fc7c8* model);
bool TestFlagMask_02012430(unsigned short* pad, int buttons);
char* GetFieldIfFlag4_020100f8(char* gameState);
void SetFlagsAt0x244_020a28a0(unsigned char* camera, unsigned char flags);
void ClearFlagBits_020a28b0(unsigned char* camera, int flags);
void CallFunc020a0db8AtField0x16c_0202ee38(char*, int, int);
void CallFunc020a0db8AtField0x194AndClearFlag2_0202ee58(char*, int, int);
void SetFourWordBlocks_021e6088(void* model, Words021e60c4* rotation);

extern unsigned short data_02114e30[];
extern const Vector3i data_ov023_021fda08;
extern const Vector3i data_ov023_021fd9fc;
extern const Vector3i data_ov023_021fd9f0;
extern const Vector3i data_ov023_021fd9e4;

// USA: func_ov023_021fc7c8
extern "C" ARM void func_ov023_021fc7c8(MenuCharacter_021fc7c8* self, void* script)
{
    SetFogState_020c54a4(0, 0, 0, 0);
    GameState* gameState = GameState::GetInstance();
    unsigned int ticks = gameState->GetTickCount();
    if (ticks == 0)
        ticks = 1;
    func_ov023_021e5020(&self->models_[0]);
    func_ov023_021e5020(&self->models_[1]);
    if (self->swap_)
    {
        int next = (self->current_ + 1) % 2;
        if (!self->models_[next].loading_)
        {
            self->current_ = next;
            self->swap_ = 0;
        }
    }
    CharacterModel_021fc7c8* model = &self->models_[self->current_];
    Vector3i rotation = func_ov023_021e613c(model);
    int difference = fix32ReduceAngle0To2Pi(0x1eb - rotation.y);
    int angle = 0;
    if (TestFlagMask_02012430(data_02114e30, 0x200) && TestFlagMask_02012430(data_02114e30, 0x100))
    {
        if (!self->turnBack_)
            self->turnBack_ = 1;
    }
    if (TestFlagMask_02012430(data_02114e30, 0x40))
    {
        const Vector3i position = data_ov023_021fda08;
        const Vector3i target = data_ov023_021fd9fc;
        char* camera = GetFieldIfFlag4_020100f8((char*)gameState);
        SetFlagsAt0x244_020a28a0((unsigned char*)camera, 2);
        CallFunc020a0db8AtField0x16c_0202ee38(camera, (int)&position, 0xa000);
        CallFunc020a0db8AtField0x194AndClearFlag2_0202ee58(camera, (int)&target, 0xa000);
    }
    else if (TestFlagMask_02012430(data_02114e30, 0x80))
    {
        const Vector3i position = data_ov023_021fd9f0;
        const Vector3i target = data_ov023_021fd9e4;
        char* camera = GetFieldIfFlag4_020100f8((char*)gameState);
        ClearFlagBits_020a28b0((unsigned char*)camera, 2);
        CallFunc020a0db8AtField0x16c_0202ee38(camera, (int)&position, 0xa000);
        CallFunc020a0db8AtField0x194AndClearFlag2_0202ee58(camera, (int)&target, 0xa000);
    }
    if (self->turnBack_)
    {
        if (difference >= 0 && difference < 0x3244)
        {
            angle = rotation.y + difference / 12;
            for (unsigned int i = 0; i < ticks - 1; i++)
                angle += fix32ReduceAngle0To2Pi(0x1eb - angle) / 12;
        }
        else if (difference >= 0x3244 && difference < 0x6488)
        {
            angle = rotation.y - (0x6488 - difference) / 12;
            for (unsigned int i = 0; i < ticks - 1; i++)
                angle -= (0x6488 - fix32ReduceAngle0To2Pi(0x1eb - angle)) / 12;
        }
        rotation.y = fix32ReduceAngle0To2Pi(angle);
        int left = fix32ReduceAngle0To2Pi(0x1eb - angle);
        int distance = left < 0 ? -left : left;
        if (distance < 0x28)
        {
            self->turnBack_ = 0;
        }
        else
        {
            distance = 0x6488 - left;
            if (distance < 0)
                distance = -distance;
            if (distance < 0x28)
                self->turnBack_ = 0;
        }
        if (!self->turnBack_)
            rotation.y = 0x1eb;
    }
    else if (TestFlagMask_02012430(data_02114e30, 0x200))
    {
        if (self->leftCallback_ != NULL)
        {
            (*self->leftCallback_)(script);
            rotation = func_ov023_021e613c(model);
        }
        else
        {
            rotation.y += (int)(4096.0f * (0.08f * ticks));
            rotation.y = fix32ReduceAngle0To2Pi(rotation.y);
        }
    }
    else if (TestFlagMask_02012430(data_02114e30, 0x100))
    {
        if (self->rightCallback_ != NULL)
        {
            (*self->rightCallback_)(script);
            rotation = func_ov023_021e613c(model);
        }
        else
        {
            rotation.y += (int)(4096.0f * (-0.08f * ticks));
            rotation.y = fix32ReduceAngle0To2Pi(rotation.y);
        }
    }
    SetFourWordBlocks_021e6088(model, (Words021e60c4*)&rotation);
}
