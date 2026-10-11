#include <globaldefs.h>

struct Vector3fix {
    int x;
    int y;
    int z;
};

struct TerrainCtx02018fbc {
    char pad0[0x82c];
    int count82c;
    char pad1[0x23b8 - 0x830];
    unsigned char flag23b8;
};

struct Sample02018fbc {
    Vector3fix v0;
    Vector3fix v1;
    Vector3fix v2;
    Vector3fix v3;
};

struct Grid02018fbc {
    short cells[96][12];
    unsigned char rest[0x80];
};

struct Probe02018fbc {
    Vector3fix a;
    Vector3fix b;
};

extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);
extern "C" float _fflt(int v);
extern "C" float _fdiv(float a, float b);
extern "C" int _ffix(float v);
extern "C" int func_02017d90(TerrainCtx02018fbc* ctx, int i, Grid02018fbc* grid, Probe02018fbc probe, int mode);
extern "C" void func_02031188(Sample02018fbc* dst, short* src);
extern "C" void _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(Vector3fix* in, int scale, Vector3fix* out);
extern "C" void Vector3fix_Subtract(Vector3fix* a, Vector3fix* b, Vector3fix* out);
extern "C" int func_020312bc(Sample02018fbc* samples, int n, Vector3fix* a, Vector3fix* b, Vector3fix* out);

// USA: func_02018fbc
extern "C" ARM int func_02018fbc(TerrainCtx02018fbc* ctx, Vector3fix* p) {
    Vector3fix v = *p;
    Probe02018fbc probe;
    Vector3fix diff;
    Vector3fix up;
    Vector3fix down;
    Vector3fix out;

    _ZN8Vector3iaSERKS_((int*)&probe.a, (int*)&v);
    _ZN8Vector3iaSERKS_((int*)&probe.b, (int*)&v);
    probe.a.x += 0x800;
    probe.a.y += 0x1000;
    probe.a.z += 0x800;
    probe.b.x -= 0x800;
    probe.b.y -= 0xa000;
    probe.b.z -= 0x800;

    int cell;
    if (ctx->flag23b8 != 0) {
        cell = (int)(((float)(v.x + 0x4000) / 4096.0f) / 8.0f)
             + ((int)(((float)(v.z + 0x4000) / 4096.0f) / 8.0f) << 4);
    }

    for (int i = 0; i < ctx->count82c; i++) {
        if (ctx->flag23b8 == 0 || cell == i) {
            Grid02018fbc grid;
            Sample02018fbc samples[96];
            int n = func_02017d90(ctx, i, &grid, probe, 0);
            if (n > 0) {
                Sample02018fbc* sample = samples;
                int scale;
                for (int j = 0; j < n; j++, sample++) {
                    scale = (*(int*)&grid.rest[4]) << 12;
                    func_02031188(sample, &grid.cells[j][0]);
                    _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&sample->v0, scale, &sample->v0);
                    _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&sample->v1, scale, &sample->v1);
                    _Z24Vector3fixMultiplyScalarPK8Vector3iiPS_(&sample->v2, scale, &sample->v2);
                }
                Vector3fix_Subtract(&v, (Vector3fix*)&grid.rest[8], &diff);
                _ZN8Vector3iaSERKS_((int*)&up, (int*)&diff);
                up.y += 0x1000;
                _ZN8Vector3iaSERKS_((int*)&down, (int*)&diff);
                down.y -= 0xa000;
                if (func_020312bc(samples, n, &up, &down, &out) != -1) {
                    out.y += 0x199;
                    v.y = out.y;
                    diff.y = out.y;
                }
            }
        }
    }
    return v.y;
}
