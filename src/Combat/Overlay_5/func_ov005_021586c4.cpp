#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Graphics/Vector.h>

struct Obj021e4e20 { char pad[0x4fc]; int member; };
struct Body { char pad[0x50]; Vector3fix rotation; };
struct Vec3copy0202ec84;
struct SlotDepth { int depth; int padding[2]; };
extern "C" Obj021e4e20* _Z19GetField1c_021a193cPi(int*);
extern "C" Body* _Z17RunIfPtr_021e4e20P11Obj021e4e20(Obj021e4e20*);
int GetField0x3b0Value(GameState*);
extern "C" int _Z27ComputeTwoFromVec3_0202ec84PvP16Vec3copy0202ec84PiS2_(void*, Vec3copy0202ec84*, int*, int*);
extern "C" double func_0200b454(double);
extern const Vector3fix data_ov005_0215cc24[8];
extern const SlotDepth data_ov005_0215cc2c[8];
extern const unsigned char data_ov005_0215cbf4[8];

// USA: func_ov005_021586c4
extern "C" ARM int func_ov005_021586c4(void*, int x, int y) {
    GameState* game = GameState::GetInstance();
    void* camera;
    int i;
    Obj021e4e20* screen = _Z19GetField1c_021a193cPi((int*)func_ov017_0218b5b0()->unknown_ptr_array_36fc[3]);
    int member = screen->member;
    if (x > 0 && x < 128) {
        int screenX[8];
        int screenY[8];
        camera = (void*)GetField0x3b0Value(game);
        Matrix4x3 matrix;
        Vector3fix positions[8];
        matrix = RotationMatrixY(_Z17RunIfPtr_021e4e20P11Obj021e4e20(screen)->rotation.y);
        for (i = 0; i < 8; i++) {
            Mat4x3_ApplyToVector(&data_ov005_0215cc24[i], &matrix, &positions[i]);
            _Z27ComputeTwoFromVec3_0202ec84PvP16Vec3copy0202ec84PiS2_(camera, (Vec3copy0202ec84*)&positions[i], &screenX[i], &screenY[i]);
        }
        GetCombatantWithFlag0x100(game, member);
        int count = 0;
        float radii[8];
        int touched[8];
        for (int i = 0; i < 8; i++) {
            radii[i] = 20.0f;
            int dy = y - screenY[i];
            int dx = x - screenX[i];
            if ((float)func_0200b454(dx * dx + dy * dy) < radii[i]) touched[count++] = i;
        }
        if (count > 0) {
            int best = touched[0];
            int bestDepth = data_ov005_0215cc2c[best].depth;
            for (int i = 1; i < count; i++) {
                int part = touched[i];
                if (bestDepth < data_ov005_0215cc2c[part].depth) {
                    best = part;
                    bestDepth = data_ov005_0215cc2c[part].depth;
                }
            }
            return data_ov005_0215cbf4[best];
        }
    }
    return 255;
}
