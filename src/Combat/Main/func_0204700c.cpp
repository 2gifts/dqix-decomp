#include <globaldefs.h>

extern "C" float _fsub(float a, float b);
extern "C" int _fleq(float a, float b);
extern "C" float _fdiv(float a, float b);
extern "C" float _fmul(float a, float b);
extern "C" int _ffix(float v);
int fix32ReduceAngle0To2Pi(int angle);

struct GameState {
    static GameState* GetInstance();
    int GetTickCount() const;
};

void* GetField0x3b0Value_020100bc(GameState* gs);
extern "C" void _Z42SetField0x7cClearFields0x1ec0x1ee_0202e874Pht(unsigned char* obj, short val);

struct AngleTrig0202e9a4;
void SetAngleAndTrigTable0202e9a4(struct AngleTrig0202e9a4* obj, int angle);

struct Object3D {
    void AdvanceEffects();
};

struct GameResources;

extern "C" void* func_ov017_0218b5b0(void);
void SetMainBrightness(struct GameResources* resources, int brightness, int duration);
void SetSubBrightness(struct GameResources* resources, int brightness, int duration);

// USA: func_0204700c
extern "C" ARM int func_0204700c(char* self) {
    if (*(unsigned int*)self > 0x23) {
        return 1;
    }

    GameState* gs = GameState::GetInstance();
    int tick = gs->GetTickCount();

    float f8 = _fsub(*(float*)(self + 8), 8.0f);
    *(float*)(self + 8) = f8;
    if (_fleq(f8, -180.0f)) {
        *(float*)(self + 8) = 180.0f;
    }
    float ang = _fmul(3.14f, _fdiv(*(float*)(self + 8), 180.0f));

    *(float*)(self + 0xc) = _fsub(*(float*)(self + 0xc), 0.4333f);

    void* obj = GetField0x3b0Value_020100bc(gs);
    short ang16 = fix32ReduceAngle0To2Pi(_ffix(_fmul(4096.0f, ang)));
    _Z42SetField0x7cClearFields0x1ec0x1ee_0202e874Pht((unsigned char*)obj, ang16);
    SetAngleAndTrigTable0202e9a4((struct AngleTrig0202e9a4*)obj,
                                 _ffix(_fmul(4096.0f, *(float*)(self + 0xc))));

    Object3D* eff = *(Object3D**)(self + 0xe8);
    if (eff != 0) {
        eff->AdvanceEffects();
    } else {
        ((Object3D*)(self + 0x3c))->AdvanceEffects();
    }

    *(unsigned int*)self = *(unsigned int*)self + tick;
    if (*(unsigned int*)self > 0xf && *(unsigned char*)(self + 0x1c) != 0) {
        struct GameResources* res = (struct GameResources*)func_ov017_0218b5b0();
        SetMainBrightness(res, -16, 20);
        SetSubBrightness(res, -16, 20);
        *(unsigned char*)(self + 0x1c) = 0;
    }

    return *(unsigned int*)self > 0x23;
}
